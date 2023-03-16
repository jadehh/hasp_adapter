/*******************************************************************************
* @File     : hasp_adapter
* @Author   : jade
* @Date     : 2023/3/16 9:35
* @Email    : jadehh@1ive.com
* @Software : Samples
* @Desc     :
*******************************************************************************/
#include "include/hasp_adapter.h"
#include "include/hasp_vcode.h"       /* contains HASP DEMOMA vendor code */
#include "stdio.h"
int login(){
    hasp_handle_t   handle;
    int status = hasp_login(0,
                            (hasp_vendor_code_t) vendor_code,
                            &handle);
    if (status == 0){
        hasp_logout(handle);
    }
    return status;
}

HaspStruct getSessionInfo(int feature_id) {
    hasp_handle_t   handle;
    char *info = 0;
    int status = hasp_login(feature_id,
               (hasp_vendor_code_t) vendor_code,
               &handle);
    hasp_get_sessioninfo(handle,
                         HASP_SESSIONINFO,
                         &info);

    HaspStruct haspStruct{};
    haspStruct.status = status;
    haspStruct.info = info;
    return haspStruct;
}
HaspStruct  getInfo(){
    hasp_status_t   status;
    hasp_handle_t   handle;
    const char     *scope;
    char *info = 0;
    scope =
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
            "<haspscope/>";
    const char* format =
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
            "<haspformat root=\"hasp_info\">"
            "    <hasp>"
            "        <attribute name=\"id\" />"
            "        <attribute name=\"type\" />"
            "        <feature>"
            "            <attribute name=\"id\" />"
            "        </feature>"
            "    </hasp>"
            "</haspformat>";
    hasp_get_info(scope, format, (hasp_vendor_code_t)vendor_code, &info);
    HaspStruct haspStruct{};
    haspStruct.status = 0;
    haspStruct.info = info;
    return haspStruct;

}

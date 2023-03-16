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
#include <iostream>
using namespace std;
int hasp_adapter::login(int feature_id) {
    printf("登录模块");
    status = hasp_login(feature_id,
                        (hasp_vendor_code_t)vendor_code,
                        &handle);

    return status;
}
char * hasp_adapter::getInfo() {
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

    status = hasp_get_info(scope, format, (hasp_vendor_code_t)vendor_code, &info);

    return info;
}
char * hasp_adapter::getSessionInfo() {

    status = hasp_get_sessioninfo(handle,
                                  HASP_SESSIONINFO,
                                  &info);

    return info;
}

int hasp_adapter::logout() {
    status = hasp_logout(handle);
    return status;
}

int hasp_adapter::login_scope(int feature_id) {
    status = hasp_login_scope(feature_id,
                              scope,
                              (hasp_vendor_code_t)vendor_code,
                              &handle);
    printf("loing scope:%s",scope);
}
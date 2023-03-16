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
char * getSessionInfo(int feature_id) {
    hasp_handle_t   handle;
    char *info = 0;
    int status = hasp_login(feature_id,
               (hasp_vendor_code_t) vendor_code,
               &handle);
    printf("status = %d\n",status);
    hasp_get_sessioninfo(handle,
                         HASP_SESSIONINFO,
                         &info);

    return info;
}

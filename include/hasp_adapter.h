/*******************************************************************************
* @File     : hasp_adapter
* @Author   : jade
* @Date     : 2023/3/16 9:35
* @Email    : jadehh@1ive.com
* @Software : Samples
* @Desc     :
*******************************************************************************/
#ifndef HASP_DEMO_HASP_ADAPTER_H
#define HASP_DEMO_HASP_ADAPTER_H
#include "stdio.h"
#include "hasp_api.h"

class hasp_adapter{
private:
    hasp_status_t   status;
    hasp_handle_t   handle;
    const char     *scope;
    char *info = 0;
public:
    int login(int feature_id);
    char * getInfo();
    char * getSessionInfo();
    int logout();
    int login_scope(int feature_id);

};


#endif //HASP_DEMO_HASP_ADAPTER_H

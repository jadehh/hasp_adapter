/*******************************************************************************
* @File     : hasp_adapter
* @Author   : jade
* @Date     : 2023/3/16 9:35
* @Email    : jadehh@1ive.com
* @Software : Samples
* @Desc     :
*******************************************************************************/
#include "hasp_api.h"
struct HaspStruct
{
    int status;
    char *info;
};
extern "C"{
    int login();
    HaspStruct  getSessionInfo(int feature_id);
    HaspStruct getInfo();
};

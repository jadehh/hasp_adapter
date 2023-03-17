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
    int handle;
    char *info;
};
extern "C"{
    __declspec(dllexport) HaspStruct login(int feature_id);
    __declspec(dllexport) void logout(int handle);
    __declspec(dllexport) HaspStruct  getSessionInfo(int feature_id);
    __declspec(dllexport) HaspStruct getInfo();
};

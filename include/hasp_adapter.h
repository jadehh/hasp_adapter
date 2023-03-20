/*******************************************************************************
* @File     : hasp_adapter
* @Author   : jade
* @Date     : 2023/3/16 9:35
* @Email    : jadehh@1ive.com
* @Software : Samples
* @Desc     :
*******************************************************************************/
#include "hasp_api.h"
# include "stdio.h"

struct HaspStruct
{
    int status;
    hasp_u32_t handle;
    char *info;
};
extern "C"{
    HaspStruct login(int feature_id);
    void logout(hasp_u32_t handle);
    HaspStruct  getSessionInfo(int feature_id);
    __declspec(dllexport) HaspStruct getInfo();
};

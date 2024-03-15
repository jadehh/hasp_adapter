/*******************************************************************************
* @File     : hasp_adapter
* @Author   : jade
* @Date     : 2023/3/16 9:35
* @Email    : jadehh@1ive.com
* @Software : Samples
* @Desc     :
*******************************************************************************/
#ifndef __HASP_ADAPTER_H__
#define __HASP_ADAPTER_H__
#pragma once

#include "hasp_api.h"
#include <stdio.h>
#include <string>
#include <string.h>

#pragma comment(lib, "libhasp_windows_34033.lib")

using namespace std;
#pragma warning(disable:4996)

struct HaspStruct {
    int status;                    // 状态信息
    hasp_u32_t handle;            // 句柄信息
    char *info;                    // 详细信息
};


extern "C" {

//用产品ID：feature_id 登录
//返回值：0=成功，建立会话成功，并登录句柄，
//        非0=失败，建立会话失败，句柄为0；
HaspStruct login_featureID(int feature_id);

//用产品ID：feature_id 和硬件ID hasp id 登录
//返回值：0=成功，建立会话成功，并登录句柄，
//        非0=失败，建立会话失败，句柄为0；
HaspStruct login_featureID_haspID(int feature_id, std::string strHaspID);

//使用登录句柄，注销会话进行退出
hasp_status_t logout(hasp_u32_t handle);

//获取网络内所有的设备信息
//返回值为XML值，需进行解析
HaspStruct getInfo_all();

//获取本地的设备信息
//返回值为XML
HaspStruct getInfo_local();

//使用产品ID，获取会话信息
HaspStruct getSessionInfo(int feature_id);
};
#endif


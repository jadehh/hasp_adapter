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

//用产品ID：feature_id 登录
//返回值：0=成功，建立会话成功，并登录句柄，
//        非0=失败，建立会话失败，句柄为0；
//返回信息如下：
/*< ? xml version = "1.0" encoding = "UTF-8" ? >
<hasp_info>
<hasp id = "669664520" type = "HASP-HL">
<feature id = "0" license_type = "perpetual" / >
<feature id = "1001" license_type = "perpetual" / >
<license_manager ip = "127.0.0.1" hostname = "samples" / >
< / hasp>
<hasp id = "1158261828" type = "HASP-HL">
<feature id = "0" license_type = "perpetual" / >
<feature id = "1001" license_type = "perpetual" / >
<license_manager ip = "127.0.0.1" hostname = "samples" / >
< / hasp>
<hasp id = "774467902" type = "HASP-HL">
<feature id = "0" license_type = "perpetual" / >
<feature id = "101" license_type = "perpetual" / >
<feature id = "401" license_type = "perpetual" / >
<license_manager ip = "192.168.40.215" hostname = "win-efidhrn5usj" / >
< / hasp>
< / hasp_info>*/

HaspStruct login_featureID(int feature_id)
{
    //hasp_handle_t   handle;
    //int status = hasp_login(feature_id,
    //    (hasp_vendor_code_t)vendor_code,
    //    &handle);
    HaspStruct haspStruct{};
    hasp_handle_t handle = HASP_INVALID_HANDLE_VALUE;
    const char* scope =
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
            "<haspscope>"
            "    <license_manager hostname=\"localhost\" />"
            "</haspscope>";

    hasp_status_t status = hasp_login_scope(0, scope, (hasp_vendor_code_t)vendor_code, &handle);

    haspStruct.status = status;
    haspStruct.handle = handle;

    if (status != HASP_STATUS_OK)
    {
        return haspStruct;
    }

    status = hasp_login_scope(feature_id, scope, (hasp_vendor_code_t)vendor_code, &handle);
    haspStruct.status = status;
    haspStruct.handle = handle;
    return haspStruct;
}

//用产品ID：feature_id 和硬件ID hasp id 登录
//返回值：0=成功，建立会话成功，并登录句柄，
//        非0=失败，建立会话失败，句柄为0；
//返回信息如下：
/*<?xml version="1.0" encoding="UTF-8" ?>
<hasp_info>
  <hasp id="669664520" type="HASP-HL">
    <feature id="0" license_type="perpetual" />
    <feature id="1001" license_type="perpetual" />
    <license_manager ip="127.0.0.1" hostname="samples" />
  </hasp>
  <hasp id="1158261828" type="HASP-HL">
    <feature id="0" license_type="perpetual" />
    <feature id="1001" license_type="perpetual" />
    <license_manager ip="127.0.0.1" hostname="samples" />
  </hasp>
</hasp_info>*/
HaspStruct login_featureID_haspID(int feature_id, std::string strHaspID)
{
    hasp_handle_t handle = HASP_INVALID_HANDLE_VALUE;
    hasp_status_t status;

    const char* scope = NULL;
    std::string strScope =
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
            "<haspscope>"
            "    <license_manager hostname=\"localhost\" />"
            "    <hasp id=\"" + strHaspID + "\" />"
                                            "</haspscope>";

    status = hasp_login_scope(feature_id, strScope.c_str(), (hasp_vendor_code_t)vendor_code, &handle);

    /* check if operation was successful */
    if (status != HASP_STATUS_OK)
    {
        switch (status)
        {
            case HASP_FEATURE_NOT_FOUND:
                break;
            case HASP_HASP_NOT_FOUND:
                break;
            case HASP_OLD_DRIVER:
                break;
            case HASP_NO_DRIVER:
                break;
            case HASP_INV_VCODE:
                break;
            case HASP_FEATURE_TYPE_NOT_IMPL:
                break;
            case HASP_TMOF:
                break;
            case HASP_TS_DETECTED:
                break;
            default:
                break;
        }
    }

    HaspStruct haspStruct{};
    haspStruct.status = status;
    haspStruct.handle = handle;
    return haspStruct;
}

//使用登录句柄，注销会话进行退出
hasp_status_t logout(hasp_u32_t handle)
{
    return hasp_logout(handle);
}

//获取网络内所有的设备信息
//返回值为XML值，需进行解析
HaspStruct  getInfo_all()
{
    const char* scope;
    char* info = 0;
    scope =
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
            "<haspscope/>";

    const char* format =
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
            "<haspformat root=\"hasp_info\">"
            "    <hasp>"
            "        <attribute name=\"id\" />"
            "        <attribute name=\"type\" />"
            "       <feature>"
            "           <attribute name=\"id\" />"
            "           <attribute name=\"license\" />"
            "       </feature>"
            "       <license_manager>"
            "           <attribute name=\"ip\" />"
            "           <attribute name=\"hostname\" />"
            "       </license_manager> "
            "    </hasp>"

            //"  <license_manager>"
            //"        <attribute name=\"id\" />"
            //"        <attribute name=\"time\" />"
            //"        <attribute name=\"hostname\" />"
            //"        <element name=\"hostname\" />"
            //"        <element name=\"ip\" />"
            //"        <element name=\"osname\" />"
            //"        <element name=\"version\" />"
            //"        <element name=\"host_fingerprint\" />"
            //"  </license_manager> "
            //"<product>"
            //"    <element name=\"id\"/>"
            //"    <element name=\"name\"/>"
            //"</product>"

            //"       <feature>"
            //"           <attribute name=\"id\" />"
            //"           <attribute name=\"license\" />"
            //        "           <attribute name=\"locked\" />"
            //        "           <attribute name=\"expired\" />"
            //        "           <attribute name=\"disabled\" />"
            //        "           <attribute name=\"usable\" />"
            //"       </feature>"
            "</haspformat>";


    hasp_get_info(scope, format, (hasp_vendor_code_t)vendor_code, &info);
    HaspStruct haspStruct{};
    haspStruct.status = 0;
    haspStruct.info = info;
    return haspStruct;
}

//获取本地的设备信息
//返回值为XML
HaspStruct  getInfo_local()
{
    char* info = 0;
    const char* scope =
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
            "<haspscope>"
            "    <license_manager hostname=\"localhost\" />"
            "</haspscope>";

    //const char* format =
    //    "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
    //    "<haspformat root=\"hasp_info\">"
    //    "    <hasp>"
    //    "        <attribute name=\"id\" />"
    //    "        <attribute name=\"type\" />"
    //    "        <feature>"
    //    "            <attribute name=\"id\" />"
    //    "        </feature>"
    //    "    </hasp>"
    //    "</haspformat>";

    const char* format =
            "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
            "<haspformat root=\"hasp_info\">"
            "    <hasp>"
            "        <attribute name=\"id\" />"
            "        <attribute name=\"type\" />"
            "       <feature>"
            "           <attribute name=\"id\" />"
            "           <attribute name=\"license\" />"
            "       </feature>"
            "       <license_manager>"
            "           <attribute name=\"ip\" />"
            "           <attribute name=\"hostname\" />"
            "       </license_manager> "
            "    </hasp>"
            "</haspformat>";

    hasp_get_info(scope, format, (hasp_vendor_code_t)vendor_code, &info);
    HaspStruct haspStruct{};
    haspStruct.status = 0;
    haspStruct.info = info;
    return haspStruct;
}

//使用产品ID，获取会话信息
//返回值为XML：如下
/*< ? xml version = "1.0" encoding = "UTF-8" ? >
<hasp_info>
<feature>
< featureid>1001 < / featureid >
< maxlogins>1 < / maxlogins >
<concurrency>
<export>network, display, local< / export>
<count>station< / count>
< / concurrency>
<vmenabled>true< / vmenabled>
< currentlogins>1 < / currentlogins >
<session>
< idle_timeout>43200 < / idle_timeout >
< idle_remaining>43200 < / idle_remaining >
< / session>
<license>
<license>perpetual< / license>
< / license>
< / feature>
< / hasp_info>*/

HaspStruct getSessionInfo(int feature_id)
{
    hasp_handle_t   handle;
    char* info = 0;
    int status = hasp_login(feature_id,
                            (hasp_vendor_code_t)vendor_code,
                            &handle);
    hasp_get_sessioninfo(handle,
                         HASP_SESSIONINFO,
                         &info);

    HaspStruct haspStruct{};
    haspStruct.handle = handle;
    haspStruct.status = status;
    haspStruct.info = info;
    return haspStruct;
}


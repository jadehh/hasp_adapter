/*******************************************************************************
* @File     : main
* @Author   : jade
* @Date     : 2023/3/16 9:44
* @Email    : jadehh@1ive.com
* @Software : Samples
* @Desc     :
*******************************************************************************/
# include "include/hasp_adapter.h"
void wait4key(char *hint)
{
    fflush(stdout);
    fflush(stdin);
    printf("\npress ENTER %s\n", hint);
    while (getchar() == EOF)
        ;
}
int main() {
    hasp_adapter *adapter = new hasp_adapter();
    int status;
    char *info;
    status = adapter->login(101);
    printf("登录状态为:%d\n", status);
    info = adapter->getInfo();
    printf("获取info状态:%s\n", info);
    info = adapter->getSessionInfo();
    printf("获取Session info状态:%s\n", info);
//    status = adapter->logout();
//    printf("log out 状态:%d\n",status);
    return 0;
};
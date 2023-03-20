/*******************************************************************************
* @File     : main
* @Author   : jade
* @Date     : 2023/3/16 9:44
* @Email    : jadehh@1ive.com
* @Software : Samples
* @Desc     :
*******************************************************************************/
# include "include/hasp_adapter.h"
# include "stdio.h"
void wait4key(char *hint)
{
    fflush(stdout);
    fflush(stdin);
    printf("\npress ENTER %s\n", hint);
    while (getchar() == EOF)
        ;
}
int main() {
    HaspStruct haspStruct;
    HaspStruct haspStruct1 = login(0);
    printf("login status = %d\n",haspStruct.status);
    haspStruct = getInfo();
    printf("status:%d,获取info状态:%s\n", haspStruct.status,haspStruct.info);
    haspStruct = getSessionInfo(301);
    printf("status:%d,获取Session info状态:%s\n",haspStruct.status, haspStruct.info);
    logout(haspStruct1.handle);
    HaspStruct haspStruct2 = login(301);
//    wait4key("contine");
    logout(haspStruct2.handle);
    printf("logout:%d",haspStruct2.handle);
    return 0;
};
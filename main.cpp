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
    HaspStruct haspStruct = getInfo();
    printf("status:%d,获取info状态:%s\n", haspStruct.status,haspStruct.info);

    return 0;
};
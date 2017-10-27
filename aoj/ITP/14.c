#include <stdio.h>

int main(void)
{
    int time;
    scanf("%d",&time);

    printf("%d:",time/(60*60));  //時間
    time = time % (60*60);       //あまり算の%

    printf("%d:",time/60);       //分
    time = time % 60;

    printf("%d\n",time);         //秒

    return 0;
}
    

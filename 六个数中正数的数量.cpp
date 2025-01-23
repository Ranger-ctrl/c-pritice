#include<stdio.h>
int main()
{
    int a,x=0;
    for(int i=1;i<=6;i++){
        scanf("%d",&a);
        if(a>0){
            x++;
        }
    }
    printf("%d positive numbers",x);
    return 0;
}
#include<stdio.h>
int main()
{
    int cm;
    scanf("%d",&cm);
    double m=cm/100.0;
    double total=m/0.3048;
    int foot=(int)total;
    int inch=(total-foot)*12;
    printf("%d %d",foot,inch);
    return 0;
} 


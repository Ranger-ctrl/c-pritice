#include<stdio.h>
int Count_Number(int N);
int main()
{
    int N,D=0;
    scanf("%d",&N);
    D=Count_Number(N);
    printf("%d",D);
    return 0;
}
int Count_Number( int N)
{
    int x,count=0;
    if(N>=-9&&N<=9){
        count =1;
    }
    else{
        x=N/10;
        count=1;
        while(x!=0){
            x=x/10;
            count++;
        }
    }
    return count;
}
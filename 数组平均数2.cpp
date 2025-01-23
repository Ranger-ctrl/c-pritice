#include<stdio.h>
int main()
{
	int cnt,sum=0,x;
	double average;
	printf("请输入你将要输入的数字数量：\n");
	scanf("%d",&cnt);
	int number[cnt];
	for(int i=0;i<cnt;i++){
		scanf("%d",&x);
		number[i]=x;
		sum+=x;
	}
	if(cnt>0){
		average=sum*1.0/cnt;
		printf("平均数为%.2lf\n",average);
		for(int j=0;j<cnt;j++){
			if(number[j]>average){
				printf("%d\t",number[j]);
			}
		}
	}
	return 0;

}
#include<stdio.h>
int main()
{
	printf("现在有1角，2角，5角的硬币，输入一个金额，可以不同的方案凑出该金额\n");
	int count,one,two,five;
	scanf("%d",&count);
	for(one=0;one<=count*10;one++){
		for(two=0;two<=count*10/2;two++){
			for(five=0;five<=count*10/5;five++){
				if(one*1+two*2+five*5==count*10){
					printf("可以用%d个1角%d个两角%d个五角凑出%d元钱\n",one,two,five,count);
				//	goto out;
				}
			}
		}
	}
//out:
	return 0;
}
#include<stdio.h>
int main()
{
    double X1;
    scanf("%lf",&X1);
    int X=(int)X1;
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n",X/100);X=X%100;
    printf("%d nota(s) de R$ 50.00\n",X/50);X=X%50;
    printf("%d nota(s) de R$ 20.00\n",X/20);X=X%20;
    printf("%d nota(s) de R$ 10.00\n",X/10);X=X%10;
    printf("%d nota(s) de R$ 5.00\n",X/5);X=X%5;
    printf("%d nota(s) de R$ 2.00\n",X/2);X=X%2;
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n",X);
    int X3=(int)X1;
	printf("X3=%d\n",X3);	
    double X2=X1-X3;
    double X4=X2*100;
    printf("X4=%lf\n",X4);
    int X5=(int)X4;
    printf("X5=%d\n",X5);
    printf("%d moeda(s) de R$ 0.50\n",X5/50);X5=X5%50;
    printf("%d moeda(s) de R$ 0.25\n",X5/25);X5=X5%25;
    printf("%d moeda(s) de R$ 0.10\n",X5/10);X5=X5%10;
    printf("%d moeda(s) de R$ 0.05\n",X5/5);X5=X5%5;
    printf("%d moeda(s) de R$ 0.01",X5);
    return 0;
}
#include<stdio.h>
#include<conio.h>

// gan gia tri
int a[5][5]={10,5,6,4,7,
2,8,9,6,3,
8,10,5,7,8,
11,7,9,12,6,
12,9,10,11,10};
int inxoan(int a[5][5],int dong,int cot)
{
	if(dong == cot)	 printf("%4d", a[dong][dong]);
	else
	{
		for(int i=dong;i<cot;i++)	printf("%4d", a[dong][i]);
		for(int i=dong+1;i<cot;i++)	printf("%4d",a[i][cot]);
		for(int i=cot-1;i>=dong;i--) printf("%4d", a[cot][i]);
		for(int i=cot-1;i>=dong+1;i--)	printf("%4d",a[i][dong]);
		inxoan(a,dong+1,cot-1);
		
	}
}



int main()
{
	inxoan(a,0,4);
}

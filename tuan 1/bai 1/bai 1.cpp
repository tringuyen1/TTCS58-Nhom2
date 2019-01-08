#include<stdio.h>




void nhapmang(int a[5][5],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("nhap phan tu:",i,j);
			scanf("%4d",&a[i][j]);
		}
	}
}

void xuatmang(int a[5][5],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n;
	int a[5][5]={ 11,7,15,20,10,32,14,9,81,21,10};
	// nhap phan tu tu ban phim
	printf("nhap so phan tu cua mang:");
	scanf("%d",&n);
	
	
	nhapmang(a,n);
	xuatmang(a,n);
	
	

}

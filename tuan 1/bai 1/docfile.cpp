#include<stdio.h>
#include<conio.h>


int main()
{
	// mo file
	FILE* fi= fopen("input.txt","rt");
	if(fi==NULL)
	{
		printf("file ko ton tai!");
	}
	int n,m;
	fscanf(fi,"%4d",&n);
	fscanf(fi,"%4d",&m);
	// cap phat vung nho
	int **a = new int*[n];
	for(int j=0;j<n;j++)
		a[j]= new int[m];
	
	// doc file
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			fscanf(fi,"%4d",&a[i][j]);
	}
	fclose(fi);
	//in ra man hinh
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<m;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
	// xuat file
	FILE *fo= fopen("output.txt","wt");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			fprintf(fo,"%4d",a[i][j]);
		fprintf(fo,"\n");
	}
	fclose(fo);
	
}




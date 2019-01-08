#include<iostream>
#include<fstream>
using namespace std;
FILE *f;
int a[10][10];
	int n;
char pathout[100]="D:\\bt BM ky thuat phan mem\\bai 1\\output.txt";
//void nhapm(int a[10][10],int n)
//{
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<"\n nhap phan tu: ";
//			cin>>a[i][j];
//		}
//	}
//}
void nhap(int a[10][10],int &n)
{
	do
	{
		cout<<"\nnhap so phan tu: ";
		cin>>n;
		if(n<3||n>3)
		{
			cout<<"\nnhap lai!!";
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<"\n nhap phan tu: ";
					cin>>a[i][j];
				}
			}	
		}
	}while(n<3||n>10);
}
void xuatm(int a[10][10],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<" "<<a[i][j];
		}
		cout<<"\n";
	}
}
//--------------------------------------
void xoadongcot(int a[10][10],int n)
{
	int dong;
	cout<<"\nnhap so dong can xoa: ";cin>>dong;
	int cot;
	cout<<"\nnhap so cot can xoa: ";cin>>cot;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>=dong)
			{
				if(j>=cot)	a[i][j]=a[i+1][j+1];
				else a[i][j]= a[i+1][j];
			}
			else if(j>=cot)	a[i][j]=a[i][j+1];
		}
	}
	xuatm(a,n-1);
}
//-----------------------------------------------
int  doixung(int a[10][10],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]!=a[j][i])
				return 0;
		}
	}
	return 1;
}
//---------------------------------------------
bool phantulonnhattrendongvacot(int a[10][10],int i,int j,int n)
{
	int k;
	for(k=0;k<n;k++)
	{
		if(a[i][j]<a[k][j])
			return false;
		if(a[i][j]<a[i][k])
			return false;
	}
	return true;
}
bool kiemtrasohoanghau(int a[10][10],int i,int j,int n)
{
	int k,h;//dong va cot;
	for(k=i+1,h=j+1;k<n&&h<n;k++,h++)
	{
		if(a[i][j]<a[h][k])
			return false;
	}
	for(k=i-1,h=j-1;k>=0&&h>=0;k--,h--)
	{
		if(a[i][j]<a[h][k])
			return false;
	}
	for(k=i+1,h=j-1;k<n&&h>=0;k++,h--)
	{
		if(a[i][j]<a[h][k])
			return false;
	}
	for(k=i-1,h=j+1;k>=0&&h<n;k--,h++)
	{
		if(a[i][j]<a[h][k])
			return false;
	}
	return true;
}
int kiemtra(int a[10][10],int n)
{
	bool check=false;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(phantulonnhattrendongvacot(a,i,j,n)==true &&kiemtrasohoanghau(a,i,j,n)==true)
			{
				cout<<" "<<a[i][j];
				check =true;
			}
		}
	}
	if(check == false)
	{
		cout<"\nkhong co so hoang hau nao!!";
	}
}
int ghifile(char pathout[100])
{
	f=fopen(pathout,"w");
	bool check=false;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(phantulonnhattrendongvacot(a,i,j,n)==true &&kiemtrasohoanghau(a,i,j,n)==true)
			{
				fprintf(f,"%4d",a[i][j]);
				check =true;
			}
		}
	}
	if(check == false)
	{
		fprintf(f,"\nkhong co so hoang hau nao");
	}
}
int main()
{
	nhap(a,n);
	xuatm(a,n);
	cout<<"\n-------------\n";
	xoadongcot(a,n);
	cout<<"\n---------------\n";
	if(doixung(a,n)==0)
	{
		cout<<"\nday la ma tran khong doi xung!";
	}
	else cout<"\nday la ma tran doi xung";
	cout<<"\n----------------\n";
	kiemtra(a,n);
	ghifile(pathout);
}

	
	

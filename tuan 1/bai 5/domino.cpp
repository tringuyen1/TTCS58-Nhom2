#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>
#include<fstream>
using namespace std;
FILE *f;
char pathin[50]="D:\\SQL\\INPUT.txt";

struct co
{
	int tren,duoi;	
};
co a[29];// du lieu luu tru cac con co
// mang trang thai cac con co
int trangthai[29];
int chenhlech= 168;		// do chenh lech (lon nhat va nho nhat)
int ttluu[28]; // luu trang thai cac con co 
int n;//khao sat n la so con co can xu ly
//--------------------------

void docfile(char pathin[50])
{
	f=fopen(pathin,"r");
	if(f==NULL)	cout<<"\nkhong doc duoc file";
	else 
	{
		fscanf(f,"%d",&n);
		for(int i=1;i<=n;i++){
			fscanf(f,"%d",&a[i].tren);
			fscanf(f,"%d",&a[i].duoi);
		}
		fclose(f);
	}
}
char pathout[100]="D:\\SQL\\output.txt";
//void ghifile(char pathout[100])
//{
//	f=fopen(pathout,"w");
//	int k,dem;
//	fprintf(f,"\n do chenh lech nho nhat la: %d",chenhlech);
//	// so luong quan co(bao nhiu trang thai 1
//	for(k=1;k<n;k++)
//	{
//		if(ttluu[k]==1) dem=dem+1;
//	}
//	fprintf(f,"\nso luong co phai quay: %d ",dem);
//	for(k=1;k<n;k++)
//		fprintf(f,"\ntrang thai luu: %d ",ttluu[k]);
//	
//	
//}
//void nhapco(int &n)// voi n la so luong con co
//{
//	cout<<"\n nhap so luong quan co: \n";
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		cout<<"\n quan co thu %d: \n"<<i;
//		cout<<"\n mat tren: ";
//		cin>>a[i].tren;
//		cout<<"\n mat duoi: ";
//		cin>>a[i].duoi;	
//	}
//}
//----------------
void kiemtra()//tong gia tri tren,duoi ,do chenh lech lon va nho,va luu lai
{
	int sumt=0,sumd=0;
	int k;
	int dochenh;
	for(k=0;k<=n;k++)
	{
		if(trangthai[k]==0)
		{
			sumt=sumt+ a[k].tren;
			sumd=sumd+ a[k].duoi;
		}
		else 
		{
			sumt =sumt + a[k].duoi;
			sumd =sumd + a[k].tren;
		}
		dochenh = abs(sumt -sumd);
	}
	if(dochenh <chenhlech)
	{
		chenhlech=dochenh;
		for(k=1;k<=n;k++)
			ttluu[k]=trangthai[k];
	}
}
//--------------
void thu(int i)
{
	int k;
	for(k=0;k<n;k++)
	{
		trangthai[i]=k;
		if(i<n)
			thu(i+1);
		else kiemtra();
		trangthai[i]=0;
	}
}
///---------------------------------------------
void ketqua()
{
	int k,dem=0;
	cout<<"\n do lech lon nhat "<<chenhlech;
	// so luong quan co(bao nhiu trang thai 1
	for(k=1;k<=n;k++)
	{
		if(ttluu[k]==1) dem=dem+1;
		
	}
	cout<<"\nso luong co phai quay: "<<dem;
	for(k=1;k<=n;k++)
		cout<<"\ntrang thai luu : "<<ttluu[k];
}
int main()
{
	int i;
//	nhapco(n);
	docfile(pathin);
	thu(1);
	ketqua();
//	ghifile(pathout);
}

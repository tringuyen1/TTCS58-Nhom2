#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;



void nhapngaunhien(int n,int m)
{
	do
	{
		cout<<"\n nhap n: ";cin>>n;
		cout<<"\nnhap m: ";cin>>m;
	}while(n>=m);
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		cout<<rand()%m<<"  ";
	}
}

void xuat(int n,int m)
{
	for(int i=0;i<n;i++)
		cout<<m;
}
int main()
{
	int n,m;
	nhapngaunhien(n,m);
	xuat(n,m);
}

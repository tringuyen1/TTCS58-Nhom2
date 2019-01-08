
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;



void taomangngaunhien(int a[50],int &n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%51;
		cout<<endl;
	}
}

//nhap mang 

void nhapmang(int a[50],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nnhap phan tu: "<<i<<" ";
		cin>>a[i];
	}
}


void xuatmang(int a[50],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
//hoan vi
void swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
// a[i] la cay goc
// cay co root la i(lar)
// n la kich thuoc cua dong
void heapify(int a[50],int n,int i)
{
	// khoi tao
	int lar=i;
	int left= 2*i+1;
	int right= 2*i+2;
	//neu con trai lon hon lar
	if(left<n && a[left]> a[lar])
		lar=left;
	//neu con phai lon hon lar
	if(right<n&& a[right]>a[lar])
		lar=right;
	//neu i khong phai la root lon nhat
	if(lar != i)
	{
		swap(a[i],a[lar]);
		//de quy lai ham
		heapify(a,n,i);
	}
}
// sap xep 
void heapsort(int a[50],int n)
{
	//tao mot dong
	for(int i=(n/2)-1;i>=0;i--)
		heapify(a,n,i);
	//qua trinh dung lai khi con 1 phan tu(trich xuat tung phan tu)
	for(int i=n-1;i>=0;i--)
	{
		// di chuyen ve nut cuoi cung
		swap(a[0],a[i]);
		//goi ham heapify
		heapify(a,i,0);
	}
}


int main()
{
	int a[50],n;
	cout<<"\nnhap so phan tu cua mang: ";
	cin>>n;
//	nhapmang(a,n);
	taomangngaunhien(a,n);
	xuatmang(a,n);
	heapsort(a,n);
	cout<<"\n sau khi vun dong: \n";
	xuatmang(a,n);
}








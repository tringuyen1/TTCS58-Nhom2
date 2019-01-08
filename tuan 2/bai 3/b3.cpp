#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream f("D:\\bt BM ky thuat phan mem\\bai 3\\input.txt");


struct nhanvien{
	int manv;
	string hoten;
	string chucvu;
	int hsl; 
	int hscv; 
	int thang; 
	int nam;
	int luong;
	int luongcb;
};

nhanvien a[20];
int n;

void nhap()
{
	if(f.fail()){
		cout<<"ko tim thay file."<<"\n";
	}
	else{
		cout<<"doc file thanh cong."<<"\n";
		cout<<"\n";
		f>>n;
		for(int i=0;i<n;i++)
		{
			f>>a[i].manv;
			f>>a[i].hoten;
			f>>a[i].hsl;
			f>>a[i].chucvu;
			f>>a[i].hscv;
			f>>a[i].thang;
			f>>a[i].nam;
		}
	}
}

void xuat()
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n ma nhan vien: "<<a[i].manv;
		cout<<"\n ho ten: "<< a[i].hoten;
		cout<<"\n he so luong : "<<a[i].hsl;
		cout<<"\n he so chuc vu: "<<a[i].hscv;
		cout<<"\nluong : "<<a[i].luong;
		cout<<"\n luong co ban: "<<a[i].luongcb;
		cout<<"\n thang: "<<a[i].thang;
		cout<<"\nnam : "<<a[i].nam;
	}
}
// ham sap xep
void luong()
{
	for(int i=0;i<n;i++)
	{
		a[i].luongcb=1250000;
		a[i].luong=a[i].luongcb*(a[i].hscv+a[i].hsl);
		cout<<"luong cua "<<a[i].chucvu<<" : \t"<<a[i].luong<<"\n";
		cout<<"\n";
	}
	cout<<"sap xep thu tu tang dan. \n";
	cout<<endl;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].luong>a[j].luong)
			{
				swap(a[i],a[j]);		
			}		
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i].luong<<"\t";
	}
	//------------------
}
// ham tim kiem nhan vien
void timkiem()
{
	luong();
	int i;
	int maso;
	cout<<"nhap ma so nhan vien ban muon tim kiem: \t";
	cin>>maso;
	cout<<endl;
	for(int i=0;i<n;i++){	
		if(a[i].manv==maso)
		{
			cout<<"\n ma nhan vien: "<<a[i].manv;
		cout<<"\n ho ten: "<< a[i].hoten;
		cout<<"\n he so luong : "<<a[i].hsl;
		cout<<"\n he so chuc vu: "<<a[i].hscv;
		cout<<"\nluong : "<<a[i].luong;
		cout<<"\n luong co ban: "<<a[i].luongcb;
		cout<<"\n thang: "<<a[i].thang;
		cout<<"\nnam : "<<a[i].nam;
		}	
		cout<<"\n";
	}	
}
// ham xoa nhan vien
void xoa()
{
	xuat();
	luong();
	timkiem();
	int manv;
	cout<<"nhap ma so nhan vien ban muon xoa: \t";
	cin>>manv;
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i].manv==manv)
		{
			a[i].manv = a[i+1].manv;
			a[i].hoten = a[i+1].hoten;
			a[i].hscv = a[i+1].hscv;
			a[i].hsl = a[i+1].hsl;
			a[i].chucvu = a[i+1].chucvu;
			a[i].thang = a[i+1].thang;
			a[i].nam = a[i+1].nam;
			a[i].luong = a[i+1].luong;
			n--;	
		}
	}
	cout<<"xoa thanh cong.\n";
	cout<<"\n";	
	cout<<"\n danh sach nhan vien sau khi xoa \n";
	xuat();
}


int main(){
	nhap();
	xoa();
}

#include<iostream>
#include<string.h>
#include<vector>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class khachhang{
	public:
		char  makh[5],tenkh[20];
		int sodutien;
};
class gid{
	public:
		char makh[10];
		char loaigd[5];
		int tiengd;
};
class thongtin{
	public:
		vector <khachhang>	dskh;
		vector <gid> dsgd;
		bool themkh(khachhang kh);
		int thuchiengd(char makh[10],char loaigd[5],int tiengd);
		void indskh();
		void insaoke(char makh[10]);
		void dockh();
		void docgd();
		void ghikh(khachhang kh);
		void ghigd(gid gd);
		void capnhap();
};
//---------------
void thongtin::dockh(){
	FILE *f=fopen("d:\\customer.dat","rb");
	int i=0;
	khachhang temp;
	while(!feof(f))
	{
		fread(&temp,sizeof(khachhang),1,f);
		dskh.insert(dskh.begin()+i,temp);
		i++;
	}
	dskh.pop_back();
	rewind(f);
	fclose(f);
}

void thongtin::docgd(){
	FILE *fi=fopen("D:\\trans.dat","rb");
	int i=0;
	gid temp;
	while(!feof(fi))
	{
		fread(&temp,sizeof(gid),1,fi);
		dsgd.insert(dsgd.begin()+i,temp);
		i++;
	}
	dsgd.pop_back();
	rewind(fi);
	fclose(fi);
}
void thongtin::ghikh(khachhang kh){
	FILE *f = fopen("D:\\customer.dat","ab");
	fwrite(&kh,sizeof(khachhang),1,f);
	fclose(f);
}
void thongtin::ghigd(gid gd){
	FILE *f = fopen("D:\\trans.dat","ab");
	fwrite(&gd,sizeof(gid),1,f);
	fclose(f);
}
void thongtin::capnhap(){
	FILE *f = fopen("D:\\customer.dat","wb");
	for(int i=0;i<dskh.size();i++)
		fwrite(&dskh[i],sizeof(khachhang),1,f);
	fclose(f);
}
bool thongtin::themkh(khachhang kh){
	for(int i=0;i<dskh.size();i++)
	{
		if(strcmp(dskh[i].makh,kh.makh)==0)
			return false;
	}
	dskh.insert(dskh.begin()+dskh.size(),kh);
	ghikh(kh);
	return true;
}
int thongtin::thuchiengd(char makh[10],char loaigd[5],int tiengd){
	gid gd;
	khachhang kh;
	strcpy(gd.makh,makh);
	strcpy(gd.loaigd,loaigd);
	gd.tiengd = tiengd;
	int i;
	for(i=0;i<dskh.size();i++)
	{
		if(strcmp(makh,dskh[i].makh)==0)
		{
			strcmp(kh.makh,dskh[i].makh);
			strcmp(kh.tenkh,dskh[i].tenkh);
			kh.sodutien = dskh[i].sodutien;
			break;
		}
	}
	if(i== dskh.size())
	{
		return 0;
	}
	if(strcmp(loaigd,"r")==0)
	{
		if(kh.sodutien< tiengd)
			return 1; //khong duoc rut tien
		else
		{
			kh.sodutien=kh.sodutien-tiengd;
			dskh[i].sodutien = kh.sodutien;
			dsgd.insert(dsgd.begin()+ dsgd.size(),gd);
			ghigd(gd);
			capnhap();
		}
	}
	return 2; // rut thanh cong
}
void thongtin::indskh(){
	for(int i=0;i<dskh.size();i++){
		cout<<"\n ma khach hang "<<dskh[i].makh<<endl;
		cout<<"\n ten khach hang "<<dskh[i].tenkh<<endl;
		cout<<"\n so du tien "<<dskh[i].sodutien<<endl; 
		cout<<"\n=====================\n";
	}
}
void thongtin::insaoke(char makh[10]){
	for(int i=0;i<dsgd.size();i++)
	{
		if(strcmp(dsgd[i].makh,makh)==0)
		{
			if(strcmp(dsgd[i].loaigd,"g")==0){

				cout<<"\n gui tien \n";
				cout<<"\n ma khach hang "<<dsgd[i].makh<<endl;
				cout<<"\n tien giao dich "<<dsgd[i].tiengd<<endl;
			}
			else{
				cout<<"\n rut tien \n";
				cout<<"\n ma khach hang "<<dsgd[i].makh<<endl;
				cout<<"\n tien giao dich "<<dsgd[i].tiengd<<endl;	
			}
		}
	}
}
khachhang nhapkh(){
	khachhang kh;
	cin.sync();
	cout<<"\n nhap ma khach hang: ";
	cin.get(kh.makh,10);
	cin.sync();
	cout<<"\n nhap ten khach hang: ";
	cin.get(kh.tenkh,10);
	cin.sync();
	cout<<"\n nhap so du tien: ";
	cin>>kh.sodutien;
	cin.sync();
	return kh;
}
gid nhapgd(){
	gid gd;
	cin.sync();
	cout<<"\nnhap ma khach hang: ";
	cin.get(gd.makh,10);
	cin.sync();
	cout<<"\n nhap tien giao dich: ";
	cin>>gd.tiengd;
	cin.sync();
	return gd;
}
int main(){
	thongtin tt;
	int chon;
	khachhang kh;
	gid gd;
	tt.dockh();
	tt.docgd();
	cout<<"\n=============chon==========\n"<<endl;
	cout<<"\n 1. them khach hang "<<endl;
	cout<<"\n 2. cho phep khach hang gui tien "<<endl;
	cout<<"\n 3. cho phep khach hang rut tien "<<endl;
	cout<<"\n 4. in danh sach khach hang "<<endl;
	cout<<"\n 5. in sao ke mot khach hang "<<endl;
	cout<<"\n 6. thoat"<<endl;
	do{
		cout<<"\n chon: ";
		cin>>chon;
		switch(chon){
			case 1:{
				kh = nhapkh();
				tt.themkh(kh);
				break;
			}
			case 2 :{
				gd = nhapgd();
				strcpy(gd.loaigd,"g");
				tt.thuchiengd(gd.makh,gd.loaigd,gd.tiengd);
				tt.dockh();
				break;
			}
			case 3: {
				gd = nhapgd();
				strcpy(gd.loaigd,"r");
				tt.thuchiengd(gd.makh,gd.loaigd,gd.tiengd);
				tt.dockh();
				break;
			}
			case 4: {
				tt.indskh();
				break;
			}
			case 5: {
				cout<<"\n nhap khach hang can liet ke: ";
				cin.get(gd.makh,10);
				tt.insaoke(gd.makh);
				break;
			}
		}
	}while(chon!=6);
}



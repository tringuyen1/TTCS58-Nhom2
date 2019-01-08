#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<fstream>
using namespace std;
FILE *f;
char pathin[50]="D:\\tuan 3\\bai2\\ghichu.txt";
int a[50];

struct thoigian{
	short d,m;
	int y;
};
//------------------------------------------------------------
thoigian dd;
char key;//bien tuong tac voi ban phim
int i;//bien chay;
string thunamthuong[7]={"thu bay","chu nhat","thu hai","thu ba","thu tu","thu nam","thu sau"};// thu nam thuong
string thunamnhuan[7]={"thu sau","thu bay","chu nhat","thu hai","thu ba","thu tu","thu nam"};// thu nam nhuan
int ngaycuoithang[12]={31,28,31,30,31,30,31,31,30,31,30,31};//cac ngay cuoi thang tu thang 1 den thang 12
int khoangtrangnamthuong[7]={5,6,0,1,2,3,4};//trang tri
int khoangtrangnamnhuan[7]={4,5,6,0,1,2,3};//trang tri
short KT;// kiem tra

//------------------------------------------------------------------
void textcolor(int x)// xac dinh mau cua chu
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , x);
}
void Goto(int x,int y)//thu tuc tuong duong voi thu tuc trong pascal
{
	COORD co = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , co);
}
//----------------------------------------------
void nhap()
{
	cout<<endl<<"nhap vao ngay thang nam: ";
	cin>>dd.d>>dd.m>>dd.y;
}
void kiemtrangay()
{
	if((dd.m<1)||(dd.y)<1||(dd.m>12)||(dd.d<1)||(dd.d>ngaycuoithang[dd.m-1]))
	{
		cout<<"nhap sai!!";
		Sleep(1000);
		ExitProcess(0);
	}
}
short namnhuan(int y)
{
	if((y%4==0)||(y%400==0)&&(y%100!=0))
		return 1;// la nam nhuan
	return 0;//khong la nam nhuan
}
long tongngay(short d,short m,short y)//tinh tong ngay
{
	int i, ngaynhuan;
	long tn;
	if(namnhuan(y)==1)	ngaycuoithang[1]=29;
	else 	ngaycuoithang[1]=28;
	tn = d + ngaynhuan + (y-1)*365;
	for(i=0;i<=(m-2);i++)	tn=tn+ngaycuoithang[i];
	return tn;
}
string thu(short d,short m,short y)
{
	if(namnhuan(y)==0)
		return thunamthuong[tongngay(d,m,y)%7];
	else
		return	thunamthuong[tongngay(d,m,y)%7];
}
short khoangtrang(short d,short m,short y)//dua ra thu cua ngay nhap vao
{
	if(namnhuan(y)==0)	return khoangtrangnamthuong[tongngay(d,m,y)%7];
	else 	return khoangtrangnamnhuan[tongngay(d,m,y)%7];
}
short thangtruoc(short m){
	if(m==1)	return 12;
	else return m-1;
}
short thangsau(short m){
	if(m==12)	return 1;
	else return m+1;
}
void chuchay(string ch,short n)//trang tri
{
	textcolor(9);
	Sleep(n);
	short i,l=ch.length();
	for(i=1;i<=l;i++)
	{
		Goto(1,1);
		cout<<ch<<endl;
		ch.erase(0,1);
		Sleep(100);
		system("cls");
	}
}
void trangtridaulich(thoigian dd){
	cout<<endl<<"ngay "<<dd.d<<"-"<<dd.m<<"-"<<dd.y<<"la: "<<thu(dd.d,dd.m,dd.y)<<endl<<endl;
	textcolor(11);
	cout<<" LICH THANG"<<dd.m<<" NAM "<<dd.y<<endl<<endl;//trang tri
	textcolor(13);
	cout<<"2 3 4 5 6 7 CN"<<endl<<endl;//trang tri
}
void trangtrithanlich(thoigian dd){
	textcolor(7);
	KT = khoangtrang(1,dd.m,dd.y);
	textcolor(8);
	for(i = KT-1;i>=0;i--)
		cout<<ngaycuoithang[thangtruoc(dd.m)-1]-i<<" ";// viet ra nhung ngay cua thang truoc
	textcolor(7);
	for(i=1; i<= ngaycuoithang[dd.m-1];i++)
	{
		if(i==dd.d)
		{
			textcolor(26);
			if(i<=9) cout<<i<<" ";
			else cout<<i<<" ";
		}
		else
		if(thu(i,dd.m,dd.y)=="chu nhat")
		{
			textcolor(12);
			if(i <=9)	cout<<i<<" ";
			else cout<<i<<" ";
		}
		else
		if(i<=9)
		{
			textcolor(7);
			cout<<i<<" ";
		}else{
			textcolor(7);
			cout<<i<<" ";
		}
		if(thu(i,dd.m,dd.y)=="chu nhat")	
			cout<<endl;
	
		
		
		
		
	}
}	
void trangtricuoilich(thoigian dd)
{
	textcolor(8);
	if(thu(ngaycuoithang[dd.m-1],dd.m,dd.y)!="chu nhat")
	{
		KT= 6-khoangtrang(ngaycuoithang[dd.m-1],dd.m,dd.y);
		for(i =1 ; i<=KT;i++)
			cout<<i<<" ";//viet ra nhung ngay cua thang sau
	}
	textcolor(7);
}
void lich(thoigian dd)// xuat ra man hinh
{
	trangtridaulich(dd);
	trangtrithanlich(dd);
	trangtricuoilich(dd);
}
void tuychon()
{
	textcolor(8);
	cout<<endl<<endl<<"*************";
	cout<<endl<<"-----tuy chon-----"<<endl;
	cout<<"1: nhap ngay khac: "<<endl;
	cout<<"2: thoat";
}
thoigian ansangtrai(thoigian dd)
{
	dd.d=dd.d-1;
	if(dd.d<1)
	{
		dd.d=ngaycuoithang[thangtruoc(dd.m)-1];
		dd.m=dd.m-1;
		if(dd.m<1)
		{
			dd.m=12;
			dd.y=dd.y-1;
			if(dd.y<1)
			{
				dd.d=1;
				dd.m=1;
				dd.y=1;
			}
		}
	}
	return dd;
}
thoigian ansangphai(thoigian dd)
{
	dd.d=dd.d+1;
	if(dd.d>ngaycuoithang[dd.m-1])
	{
		dd.d=1;
		dd.m=dd.m+1;
		if(dd.m>12)
		{
			dd.m=1;
			dd.y=dd.y+1;
		}
	}
	return dd;
}
thoigian anlentren(thoigian dd)
{
	dd.d=dd.d-7;
	if(dd.d<1)
	{
		dd.d=ngaycuoithang[thangtruoc(dd.m)-1]-(7-dd.d)+7;
		dd.m=dd.m-1;
		if(dd.m<1)
		{
			dd.y=dd.y-1;
			if(dd.y<1)
			{
				dd.d=1;
				dd.m=1;
				dd.y=1;
			}
		}
	}
	return dd;
}
thoigian anxuongduoi(thoigian dd)
{
	dd.d=dd.d+7;
	if(dd.d>ngaycuoithang[dd.m-1])
	{
		dd.d=7-((ngaycuoithang[dd.m-1]-dd.d))-7;
		dd.m=dd.m+1;
		if(dd.m>12)
		{
			dd.m=1;
			dd.y=dd.y+1;
		}		
	}
	return dd;
}
//---------------tang thang-giamthang
thoigian tangthang(thoigian dd)
{
	dd.m=dd.m+1;
	if(dd.m>12)
	{
		dd.y=dd.y+1;
		dd.m=1;
		
	}
	return dd;
}
thoigian giamthang(thoigian dd)
{
	dd.m=dd.m-1;
	if(dd.m<1)
	{
		dd.m=12;
		dd.y=dd.y-1;
		if(dd.y<1)
		{
			dd.d=1;
			dd.m=1;
			dd.y=1;
		}
	}
	return dd;
}
void tuongtacphim()
{
	key=getch();
	if(key=='d' ||  key== 'D')	dd= ansangphai(dd);
	if(key== 'a'||  key== 'A')	dd= ansangtrai(dd);
	if(key== 'w'||  key== 'W') 	dd= anlentren(dd);
	if(key== 's'||  key== 'S')	dd= anxuongduoi(dd);
	if(key== 'n'||  key== 'N')	dd= tangthang(dd);
	if(key== 'p'||  key== 'P')	dd= giamthang(dd);
	if(key== '1')	 nhap();
}

int main()
{
	dd.d=1;dd.m=8;dd.y=2019;
	cout<<endl;
	do
	{
		kiemtrangay();
		system("cls");
		lich(dd);
		tuychon();
		tuongtacphim();
	}while(key != '2');
	chuchay("<-----------------------hen gap lai------------------------------->",40);
}





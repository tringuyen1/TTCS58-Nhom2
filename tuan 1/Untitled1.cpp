#include<iostream>
#include<string>
using namespace std;


struct CON{
	string manhankhau;
	string hoten;
	string gioitinh;
	CON *cnext;
};

struct XE{
	string soxe;
	string hieuxe;
	string loaixe;
	XE *xnext;

};
struct HOKHAU{
	string sohokhau;
	string manhankhau;
	string tenchuho;
	string diachi;
	HOKHAU *hknext;

	CON *con;
	XE *xe;
	
};

void NHAPXE(XE *&dau)
{
	
	XE *p, *q;
	string soxe1;
	do{
		
		cout<<"nhap so xe";
		getline(cin,soxe1);
		if(soxe1.compare("\0")!=0)
		{
			p = new XE;
			p->soxe=soxe1;
			cout<<endl<<"nhap loai xe";
			getline(cin,p->loaixe);
			cout<<endl<<"nhap hieu xe: ";
			getline(cin,p->hieuxe);
			p->xnext = NULL;
			if(dau == NULL) 
			{
				dau = p;
			}
			else
			{
				q->xnext = p;
			}
			q = p;
		}
	}while(soxe1.length() !=0) ;
}

void NHAPCON(CON *&dau){
	CON *p, *q;
	string manhankhau1;
	do{
		p = new CON;
		cout<<endl<< "nhap ma nhan khau: ";
		getline(cin,manhankhau1);
		if(manhankhau1.compare("\0") !=0)
		{
			p->manhankhau = manhankhau1;
			cout<<endl<<"nhap ho ten: ";
			getline(cin,p->hoten);
			cout<<endl<<"nhap gioi tinh: ";
			getline(cin,p->gioitinh);
			p->cnext = NULL;
			
			if(dau == NULL)
			{
				dau = p;
			}
			else
			{
				q->cnext = p;
			}
			q= p;
		}
	}while(manhankhau1.length()!=0);
}

void NHAPHK(HOKHAU *&dau)
{
	HOKHAU *p, *q;
	string tam;
	do{
		cout<<"nhap so ho khau: ";
		getline(cin,tam);
		if(tam.length() != 0)
		{
			p->sohokhau = tam;
			cout<<endl<<"nhap ma nhan khau:";
			getline(cin,p->manhankhau);
			cout<<endl<<"nhap ten chu ho: ";
			getline(cin,p->tenchuho);
			cout<<endl<<"nhap dia chi:";
			getline(cin,p->diachi);
			p->hknext = NULL;
			p->xe = NULL;
			p->con = NULL;
			
		}
	}
}
int main()
{
	XE *xe1;
	NHAPXE(xe1);
	
}

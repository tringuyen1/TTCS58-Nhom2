#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;




struct node3
{
	char MSNK[20],HOTEN[20],GT[20];
	node3 *ke;
};

struct node2
{
	char SX[20],LX[20],HX[20];
	node2 *sau;	
};
struct node1 
{
	char SHK[20],MNK[20],TENCH[20],DIACHI[20];
	node1 *tiep;
	node2 *xe;
	node3 *con;
};
node1 *dau;
void khoitao(node1 *&dau)
{
	dau==NULL;
}


void nhapcon(node3 *&dau)	
{
	char tam[20];
	node3 *p,*q;
	do{
		cout<<"\nnhap ma nhan khau: ";
		fflush(stdin);
		gets(tam);
		if(strcmp(tam,"\0")!=0)
		{
			p= new node3;
			strcpy(p->MSNK,tam);
			cout<<"\n nhap ho ten: ";
			gets(p->HOTEN);
			cout<<"\n nhap gioi tinh: ";
			gets(p->GT);
			if(dau == NULL)
			{
				dau=p;
			}
			else
			{
				q->ke=p;
			}
			q=p;
		}
		
	}while(strcmp(tam,"\0")!=0);
}
void nhapxe(node2 *&dau)
{
	char tam[20];
	node2 *p,*q;
	do{
		cout<<"\nnhap so xe: ";
		fflush(stdin);
		gets(tam);
		if(strcmp(tam,"\0")!=0)
		{
			p= new node2;
			strcpy(p->SX,tam);
			cout<<"\n nhap hieu xe: ";
			gets(p->HX);
			cout<<"\n nhap loai xe : ";
			gets(p->LX);
			if(dau == NULL)
			{
				dau=p;
			}
			else
			{
				q->sau=p;
			}
			q=p;
		}
		
	}while(strcmp(tam,"\0")!=0);
}

void nhaphk(node1 *&dau)
{
	char tam[20];
	node1 *p,*q;
	do{
		cout<<"\nnhap so ho khau: ";
		fflush(stdin);
		gets(tam);
		if(strcmp(tam,"\0")!=0)
		{
			p= new node1;
			strcpy(p->SHK,tam);
			cout<<"\n nhap ma nhan khau: ";
			gets(p->MNK);
			cout<<"\n nhap ten chu ho : ";
			gets(p->TENCH);
			cout<<"\n nhap dia chi : ";
			gets(p->DIACHI);
			p->xe=NULL;
			nhapxe(p->xe);
			p->con=NULL;
			nhapcon(p->con);
			if(dau == NULL)
			{
				dau=p;
			}
			else
			{
				q->tiep=p;
			}
			q=p;
		}
		
	}while(strcmp(tam,"\0")!=0);
}
void incon(node3 *dau)
{
	node3 *p;
	p=dau;
	if(p!=NULL)
	{
		cout<<"\n ma so nhan khau: "<<setw(30)<<p->MSNK;
		cout<<"\n ho ten: "<<setw(30)<<p->HOTEN;
		cout<<"\ngioi tinh: "<<setw(30)<<p->GT;
	}
}
void indsthanhvienho(node1 *dau)
{
	node1 *p;
	p=dau;
	if(p!=NULL)
	{
		cout<<"\nso ho khau: "<<setw(30)<<p->SHK;
		cout<<"\nten chu ho: "<<setw(30)<< p->TENCH;
		cout<< "\ndia chi: "<<setw(30)<<p->DIACHI;
		cout<<"\nma nhan khau: "<<setw(30)<<p->MNK;
		incon(p->con);
	}
}

int timxe(node2 *&dau, string hieuxe)
{
	node2 *tam;
	tam=dau;
	while(tam!=NULL)
	{
		if(tam->HX==hieuxe)
		{
			return 1;
			break;
		}
		tam =tam->sau;
	}
}
void inhkxe(node1 *dau,string hieuxe)
{
	node1 *tam;
	tam =dau;
	if(tam== NULL)
		cout<<"\n khong co trong ho khau!!";
	while(tam!=NULL)
	{
		if(timxe(tam->xe,hieuxe)==1)
		{
			cout<<"\nso ho khau "<<tam->SHK;
			cout<<"\nten chu ho: "<<tam->TENCH;
		}
		tam= tam->tiep;
	}
}
void xoaxe(node2 *&dau)
{
	node2 *p;
	p=dau;
	if(dau!=NULL)
	{
		p= p->sau;
		delete p;
	}
}
void xoaxehk(node1 *&dau)
{
	if(dau!=NULL)
		xoaxe(dau->xe);
}
int main()
{
	string hieuxe;
	khoitao(dau);
	nhaphk(dau);
	indsthanhvienho(dau);
	cout<<"\n nhap xe can tim: ";
	getline(cin,hieuxe);
	inhkxe(dau,hieuxe);
	xoaxehk(dau);
	
}

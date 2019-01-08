#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;




//tao cay:
struct nut
{
	int info;
	nut *left,*right;
};
typedef nut node;
node *root,*root1;
void khoitao(node *&root)
{
	root=NULL;
}
void mocnut(node *&root,int x)
{
	if(root == NULL)
	{
		root = new node;
		root->info=x;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		if(root->info>=x)
			mocnut(root->left,x);
		else
			mocnut(root->right,x);
	}
}
void taocayngaunhien(node *&root)
{
	int tam;
	do
	{
		tam = rand()%51;
		if(tam !=0 ) mocnut(root,tam);
	}while(tam!=0);
}


void taocay(node *&root)
{
	int tmp;
	do
	{
		cout<<"nhap so nguyen va 0 de dung: ";
		cin>>tmp;
		if(tmp!=0)
			mocnut(root,tmp);
	}while(tmp!=0);
}
 void duyetLNR(node *root)
 {
 	if(root!=NULL)
 	{
 		duyetLNR(root->left);
 		cout<<root->info<<" ";
 		duyetLNR(root->right);
	 }
 }
 //chieu cao cua cay
 int max(int a,int b)
 {
 	if(a>=b)
 		return a;
 	else return b;
 }
 int chieucao(node *root)
 {
 	if(root==NULL)
 		return 0;
 	return 1 + max(chieucao(root->left),chieucao(root->right));
 }
//in muc i
void inmuci(node *root,int i ,int muc=1)
{
	if(root != NULL)
	{
		if(muc ==i)
		{
			cout<<root->info<<" ";
		}
		else 
			inmuci(root->left,i,muc+1);
			inmuci(root->right,i,muc+ 1);
	}
}
// sao chep cay
void saochep(node *root,node *&root1)
{
	if(root == NULL)
	{
		root1 = NULL;
	}
	else
	{
		root1 =new node;
		root1->info=root->info;
		saochep(root->left,root1->left);
		saochep(root->right,root1->right);
	}
}
// tim nut trong cay
node *tim(node *root,int x)
{
	if(root->info==x)	return root;
	if(root->info>x)	return tim(root->left,x);
	if(root->info<x)	return tim(root->right,x);
}

int xoa(node *root,int x)
{
	if (root == NULL)	return 0;
	else if(root->info > x) return xoa(root->left,x);
	else if(root->info < x)	return xoa(root->right,x);
	else
	{
		node *p;
		p=root;
		if(root->left== NULL) root=root->right;// node chi co cay con phai
		else if(root->right== NULL) root=root->left;// node chi co cay con trai
		else
		{
			// S la cha cua Q va Q la node phai cua cay
			node *S =root, *Q = S->left;
			while (Q->right!=NULL)
			{
				S=Q;
				Q=Q->right;
			}
			p->info=Q->info;
			S->right= Q->left;
			delete Q;
		}
	}
}

int main()
{
	int n;
	khoitao(root);
	taocay(root);
//	cout<<"\n nhap so phan tu cua cay: \n";
//	cin>>n;
//	taocayngaunhien(root);
	khoitao(root1);
	saochep(root,root1);

	duyetLNR(root);
	cout<<"\n sao chep cay: \n";
	duyetLNR(root1);
	cout<<"\nchieu cao cay: "<<chieucao(root);
	inmuci(root,1,1);
	node *p;
	int x;
	cout<<"\n nhap vi tri can xoa: ";
	cin>>x;
	p= tim(root,x);
	if(p!= NULL) cout<<"\nket can xoa: "<<p->info;
	else cout<<"\nko co trong cay"<<x;
	if(xoa(root,x))	cout<<"\nxoa thanh cong";
	else cout<<"\nxoa ko thanh"<<x;
	duyetLNR(root);
}

#include<iostream>
#include<fstream>
using namespace std;
#define MAX 1000
#define TRUE 1
#define FALSE 0

int a[100][100];
int n; // so dinh
int m;//so canh
int sc; //so canh cay khung nho nhat
int w; // do dai cua cay
int chuaxet[100]; //mang danh dau dinh
int dsc[100][3]; // danh sach canh cua cay khung
void nhap()
{
	int i,j,k;
	freopen("D:\\tuan 3\\bai4\\dl.txt","r",stdin);
	cout<<"\n so dinh: ";cin>>n;
	cout<<"\n so canh: ";cin>>m;
	//khoi tao
	for(i=1;i<=n;i++){
		chuaxet[i]= TRUE; // gan nhan cho dinh
		for(j=1;j<=n;j++)
			a[i][j]=MAX;
	}
	// nhap
	for(int p =1 ;p <= m;p++){
		cin>>i>>j>>k;
		a[i][j] = k;
		a[i][j]= k;
	}
}
void caykhung(){
	int k,top,min,l,t,u;
	int s[100]; // mang chua cac dinh
	sc = 0;
	w=0;u=1;
	top=1;
	s[top] =u; //them dinh vao u
	chuaxet[u]= FALSE;
	while(sc< n-1){
		min = MAX;
		///tim canh do dai nho nhat
		for(int i=1;i<=top;i++)
		{
			t=s[i];
			for(int j=1;j<=n;j++){
				if(chuaxet[j]&& min >a[t][j]){
					min = a[t][j];
					k= t ;
					l=t;
				}
			}
		}
		sc++;
		w = w+ min;
		//them vao danh sach
		dsc[sc][1]=k;
		dsc[sc][2]=l;
		chuaxet[l]= FALSE;
		top++;
		s[top]=l;
	}
}
void xuat(){
	cout<<"\n do dai ngan nhat "<<w<<endl;
	cout<<"\n cac canh cua cay khung nho nhat"<<endl;
	for(int i=1;i<=sc;i++)
		cout<<dsc[i][1]<<" "<<dsc[i][2]<<endl;
}
void xuatfile(){
	freopen("D:\\tuan 3\\bai4\\out.txt","w",stdout);
	cout<<"\n do dai ngan nhat "<<w<<endl;
	cout<<"\n cac canh cua cay khung nho nhat"<<endl;
	for(int i=1;i<=sc;i++)
		cout<<dsc[i][1]<<" "<<dsc[i][2]<<endl;
}
int main(){
	nhap();
	caykhung();
	xuat();
	xuatfile();
}

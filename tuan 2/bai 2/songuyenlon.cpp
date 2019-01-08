#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int kituthanhso(char c) // chuyen ki tu sang so
{
		return c - '0';
}
int sothanhkitu(int n)	// chuyen so sang ki tu
{
	return (char)(n+48);
}
char chuanhoa(string &a,string &b) // lam hai xau co do dai bang nhau
{
	int l1 = a.length(), l2= b.length();
	if(l1 >= l2)
	{
		b.insert(0,l1-l2,'0'); // chen vao dau cua b cac ky tu '0';
	}
	else 
	{
		a.insert(0,l2-l1,'0'); // chen vao dau cua a cac ky tu '0'
	}
}
string cong(string a,string b)
{
	string s ="";
	chuanhoa(a,b);
	int tam = 0;
	for(int i= a.length()-1;i>=0;i--)
	{
		tam = kituthanhso(a[i])+kituthanhso(b[i])+tam;
		s.insert(0,1,sothanhkitu(tam%10));
		tam = tam/10;
	}
	if(tam > 0) // neu nhu hang chuc lon hon 0 thi in ket qua
	{
		s.insert(0,1,sothanhkitu(tam));
	}
	return s;
}
string tru(string a,string b)
{
	string s ="";
	chuanhoa(a,b);
	int tam = 0;
	for(int i= a.length()-1;i>=0;i--)
	{
		tam = kituthanhso(a[i])-kituthanhso(b[i])-tam;
		s.insert(0,1,sothanhkitu(tam%10));
		tam = tam/10;
	}
	if(tam > 0) // neu nhu hang chuc lon hon 0 thi in ket qua
	{
		s.insert(0,1,sothanhkitu(tam));
	}
	return s;
}
string nhannho(char a,string b)
{
	string s ="";
	int tam = 0;
	for(int i= b.length()-1;i>=0;i--)
	{
		tam = kituthanhso(a)*kituthanhso(b[i])+tam;
		s.insert(0,1,sothanhkitu(tam%10));
		tam = tam/10;
	}
	if(tam > 0) // neu nhu hang chuc lon hon 0 thi in ket qua
	{
		s.insert(0,1,sothanhkitu(tam));
	}
	return s;
}
string nhan(string a,string b)
{
	string s ="";
	int l= a.length();
	string s1[l];
	for(int i=l-1;i>=0;i--)
	{
		s1[i]=nhannho(a[i],b);
		s1[i].insert(s1[i].length(),l-i-1,'0');
		s = cong(s,s1[i]); //con don theo cach con so lon
	}
	return s;
}
int main()
{
	int chon;
	string a,b,kqc,kqn,kqt;
//	cout << "\n nhap a va b: ";
//	getline(cin,a);
//	getline(cin,b);
//	kqc =cong(a,b);
//	cout<< a ;cout << "+"; cout<<b; cout<<"="; cout<<kqc;
//	cout<<"\n-------------\n";
//	kqt =tru(a,b);
//	cout<< a ;cout << "-"; cout<<b; cout<<"="; cout<<kqt;
//	cout<<"\n----------\n";
//	kqn =nhan(a,b);
//	cout<< a ;cout << "*"; cout<<b; cout<<"="; cout<<kqn;
//	int chon=0;
//	menu---------------------------------------------------------------
	do
    {
    	cout << "\n nhap a va b: ";
		getline(cin,a);
		getline(cin,b);
		kqt =tru(a,b);
        system("cls");
        cout<<"\t\t\t===========menu======================\n";
        cout<<"\t\t\t 1.tinh cong                 	   |\n";
        cout<<"\t\t\t 2.tinh nhan               	   |\n";
        cout<<"\t\t\t 3.tinh tru              		   |\n";
        cout<<"\t\t\t 4.thoat             	    	   |\n";
        cout<<"ban chon: ";
       	cin>>chon;
        switch(chon)
        {
        	case 1:{
        		kqc =cong(a,b);
				cout<< a ;cout <<" + "; cout<<b; cout<<" = "; cout<<kqc;
				break;
			}
			case 2:{
				kqn =nhan(a,b);
				cout<< a ;cout <<" * "; cout<<b; cout<<" = "; cout<<kqn;
				break;
			}
			case 3:{
				cout<< a ;cout <<" - "; cout<<b; cout<<"="; cout<<kqt;
				break;
			}
			case 4:{
				break;
			}
			default:
				cout<<"\n vui long nhap lai!!!";
				break;
				
		}
    }while(chon!=4);
}

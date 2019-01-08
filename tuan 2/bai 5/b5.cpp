
#include <math.h>
#include <winbgim.h>
#include <iostream>
#include <string.h>
using namespace std;
int Ax, Ay;
class toado{
	protected:
		int x,y;
		friend class duongthang;
		friend class hinhchunhat;
		friend class hinhvuong;
		friend class hinhtron;
		friend class tamgiac;
	public:
		void nhap(){
			cout<<endl<<"\nnhap Toa do x: ";cin>>x;
			cout<<"\nnhap toa do y: ";cin>>y;
		}
};
//----------------------------------------------------
class duongthang{
	private:
	toado d1,d2;//diem mot diem 1 va 2
	public:
		void nhapduong(){
			cout<<"\ntoa do diem thu nhat: ";d1.nhap();
			cout<<"\ntoa do diem thu hai: ";d2.nhap();
		}
		void vehinh(){			
			line(d1.x+Ax/2,-d1.y+Ay/2,d2.x+Ax/2,-d2.y+Ay/2);
		}
};
//---------------------------------------
class hinhchunhat{
	private:
		toado trent, duoip;// tren trai va tren phai
	public:
		void nhapchunhat(){
			cout<<"\ntoa do diem tren trai: ";trent.nhap();
			cout<<"\ntoa do diem duoi phai: ";duoip.nhap();
		}
		void vehinh(){			
			rectangle(trent.x+Ax/2, -trent.y+Ay/2, duoip.x+Ax/2, -duoip.y+Ay/2);
		}
};
//----------------------------------------------
class hinhvuong{
	private:
		toado trent, duoip;
	public:
		void nhapvuong(){
			do
			{
				cout<<"\ntoa do diem tren trai: ";trent.nhap();
				cout<<"\ntoa do diem duoi phai: ";duoip.nhap();
				if (abs(trent.x-duoip.x) != abs(trent.y-duoip.y))
					cout<<"\nkhong chinh xac!!!!"<<endl;
			}
			while (abs(trent.x-duoip.x) != abs(trent.y-duoip.y));
		}
		void vehinh(){			
			rectangle(trent.x+Ax/2, -trent.y+Ay/2, duoip.x+Ax/2, -duoip.y+Ay/2);
		}
};
//--------------------------------------------------
class hinhtron{
	private:
		toado temp;
		int bankinh;
	public:
		void nhaptron(){
			cout<<"\nnhap toa do tam: ";temp.nhap();
			cout<<"\nNhap ban kinh: ";cin>>bankinh;
		}
		void vehinh(){			
			circle(temp.x+Ax/2,-temp.y+Ay/2,bankinh);
		}
};
//------------------------------------------------------------------
class tamgiac{
	private:
		toado t1,t2,t3;
	public:
		void nhaptamgiac(){
			cout<<"\nToa do diem thu nhat: ";	t1.nhap();
			cout<<"\nToa do diem thu hai: ";t2.nhap();
			cout<<"\nToa do diem thu ba: ";t3.nhap();
	}
		void vehinh(){			
			line(t1.x+Ax/2, -t1.y+Ay/2, t2.x+Ax/2, -t2.y+Ay/2);
			line(t1.x+Ax/2, -t1.y+Ay/2, t3.x+Ax/2, -t3.y+Ay/2);
			line(t2.x+Ax/2, -t2.y+Ay/2, t3.x+Ax/2, -t3.y+Ay/2);
		}	
};
int main(){
	int chon;
	duongthang dt;
	tamgiac tg;
	hinhchunhat cn;
	hinhvuong v;
	hinhtron t;
	initwindow(1400,700);
    cleardevice();
    Ax = getmaxx(), Ay = getmaxy();
    cout<<"Nhap lua chon: "<<endl;
    cout<<"1. Ve duong thang"<<endl;
    cout<<"2. Ve tam giac"<<endl;
    cout<<"3. Ve hinh chu nhat"<<endl;
    cout<<"4. Ve hinh vuong"<<endl;
    cout<<"5. Ve hinh tron"<<endl;
    cout<<"6. Ket thuc ve"<<endl;
    do
    {
	    cout<<endl<<"Nhap lua chon: ";
	    cin>>chon;
		switch(chon)
		{
			case 1:
				dt.nhapduong();
				dt.vehinh();
				break;
			case 2:
				tg.nhaptamgiac();
				tg.vehinh();
				break;
			case 3:
				
				cn.nhapchunhat();
				cn.vehinh();
				break;
			case 4:
				
				v.nhapvuong();
				v.vehinh();
				break;
			case 5:
				t.nhaptron();
				t.vehinh();
				break;
			case 0:
				break;
		}
		delay(200);
	}
    while (chon != 6);	
    while(!kbhit()) delay(1);
}

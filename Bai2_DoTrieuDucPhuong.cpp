#include <iostream>
using namespace std;
int swit(int k)
{
    cout<<"Nhap diem: ";
    cin>>k;
    switch (k)
    {
       case 0: {cout<<"Yeu "; break; }
       case 1:  {cout<<"Yeu "; break; }
       case 2:  {cout<<"Yeu "; break; }
       case 3:  {cout<<"Yeu "; break; }
       case 4: {cout<<"Kem"; break; }
       case 5: {cout<<"Trung binh"; break; }
       case 6: {cout<<"Trung binh"; break; }
       case 7: {cout<<"Kha"; break; }
       case 8: {cout<<"Kha"; break; }
       default :{ cout<<"Gioi";  }

    }    
}
int neu(int d)
{
    cout<<endl<<"Nhap diem: ";
    cin>>d;
    while (d<0 || d>10)
    {
        cout<<"Nhap lai diem ";
        cin>>d;
    }
    if(d>=0 && d<=3) cout<<"Yeu";
    else if(d==4) cout<<"Kem";
    else if(d>=5 && d<=6) cout<<"Trung binh";
    else if(d>=7 && d<=8) cout<<"Kha";
    else cout<<"Gioi";

}
int main()
{ int k,d;
    swit(k);
    neu(d);
}
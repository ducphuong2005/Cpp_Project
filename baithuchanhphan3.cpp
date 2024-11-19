#include <iostream>
#include <cmath>
 using namespace std;
  int main()
  { int k;
  int n,d;
    cout<<" chon bai muon lam ";
    cin>>k;
    switch(k)
    {
    case 1:
          int x,y;
         cout<<"Nhap 2 so thuc x va y"; cin>>x>>y;
         cout<<log(x*x+pow(y,4))+ abs(y-x)+(pow(x,6)+pow(x,7)/exp(x+y));
         break;
    case 2:
     
         cout<<"Nhap so ngay lam viec "; cin>>n;
         cout<<"nhap doanh so "; cin>>d;
         if (n<10 || d <10000000) cout<<"luong la "<<n*50000;
         else if((n>=10 && n<=20) && (d>=10000000 &&  d<=30000000)) cout<<"luong la "<<n*75000 + 2%d;
         else if ((n>20)&& (d>= 10000000 && d>=30000000)) cout<<n* 100000 +2%d;
         else cout<<n* 100000 + 4%d;
      break;

    case 4:
          int a1,b1,x1;
         cout<<"Nhap a va b"; cin>>a1>>b1;
         cout<<"Nhap x "; cin>>x1;
         if (a1+b1 !=0 ) cout<<"gia tri ham so la "<<exp(x1)/(a1+b1);
         else if (a1==0 && b1==0 && a1==b1) cout<<"gia tri ham so la 0";
         else cout<<sqrt(a1*a1+b1*b1+100)+pow(sin(x1),3);
    break;
    
    case 0:

         return 0;
    }


    }
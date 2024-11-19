#include <iostream>
#include <cmath>
 using namespace std;
  int main()
  {
    int k,a,b,n,x,sotien,s;
    cout<<" chon bai muon lam";
    cin>>k;
    switch(k)
    {
    case 1:
        cout<<"Nhap a,b"; cin>>a>>b;
        cout<<"tong la "<<a+b;
        cout<<"hieu la "<<a-b;
        cout<<"tich la "<<a*b;
        cout<<"thuong la "<<a/b;
        cout<<"phan du cua a cho b la "<<a%b;
        break;
    case 2:
         cout<<"nhap so nguyen n"; cin>>n;
         if(n%2==0) cout<<n<<"la so chan";
         else cout<<n<<"la so le";
         break;

     case 3:
          cout<<"nhap x"; cin>>x;
          cout<<(x*x+ exp(x)+ sin(x)*sin(x))/sqrt(x*x+1);
         break;
     
     case 4:
           cout<<"nhap so tien cua khach hang"; 
           cin>>sotien;
           if (sotien <200000) cout<<"ko khuyen mai";
           if (sotien>=200000 && sotien<=300000) cout<<"so tien duoc khuyen mai la "<<sotien*0.2;
           if (sotien >300000) cout<<"so tien duoc khuyen mai la "<<sotien*0.3;
           break;

     case 5:
            cout<<"nhap quang duong nguoi di bo phai di"; cin>>s;
            if(s<=3000) cout<<s<<"s";
            if(s>3000 && s<=5000) cout<<3000+ (s-3000)*2<<"s";
            if(s>5000 && s<=6000) cout<<3000+ 2000*2 + (s-5000)*3<<"s";
            if(s>6000) cout<<3000+2000*2+ 30000 + (s-6000)*5<<"s";
            break;

    case 0:

        return 0; 
    }


  }

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
//lay n so sau dau thap phan: cout<<fixed<<setprecision(n)<<a;
float tonga(int n)
{ cout<<"Phan a: "<<endl;
    cout<<"Nhap n: "; cin>>n;
while (n<=0)
{
    cout<<"Nhap lai n: "; cin>>n;
}
    int k;
    float s=0;
    cout<<"Ban muon giai bang cach 1 hay 2 (cach 1 dung for, cach 2 dung while)? ";
    cin>>k;
    switch (k)
    {
        case 1:
           for(int i=1; i<=n; i++)
           s+=1.0/i;
           cout<<"Tong cua S o phan a la: "<<fixed<<setprecision(3)<<s<<endl;
           break;
        case 2:
           int i=1;
           while (i<=n)
           {
            s+=1.0/i;
            i++;
           }
         cout<<"Tong cua S o phan a la: "<<fixed<<setprecision(3)<<s<<endl;
         break;
   }

    }
    float tongb(float n, float x)

    {   cout<<"Phan b: "<<endl;
        cout<<"Nhap x: "; cin>>x;
        cout<<"Nhap n: "; cin>>n;
        while (n<=0)
        {
            cout<<"Nhap lai n: "; cin>>n;
        }
    int k;
    float s=1;
    cout<<"Ban muon giai bang cach 1 hay 2 (cach 1 dung for, cach 2 dung while)? ";
    cin>>k;
    switch (k)
    {
        case 1:
        for (int i=1; i<=n; i++)
        s+=(pow(-1,i)*pow(x,n))/i;
        cout<<"Tong cua S o phan b la: "<<s;
        break;
        case 2:
        int i=1;
        while (i<=n)
        {
             s+=(pow(-1,i)*pow(x,n))/i;
             i++;
        }
          cout<<"Tong cua S o phan b la: "<<s;
          break;
    }
    }
int main()
{
    int n;
    float m,x;
    tonga(n);
    tongb(m,x);
}

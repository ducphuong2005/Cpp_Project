#include <iostream>

using namespace std;
void trian(float &a, float &b, float &c, float n)
{
    cout<<"nhap a,b,c: "; cin>>a>>b>>c;
    cout<<"Nhap n: "; cin>>n;
    while (a+b<=c|| a+c<=b || b+c<=a)
    {
        cout<<"Nhap lai a,b,c: ";
        cin>>a>>b>>c;
    }
}

float chuvi(float &a, float &b, float &c)
{ 
   return a+b+c;
}
float gt(float a, float n, float k)
{
    float l=2020*pow(a,n);
    for (int i=1; i<=n; i++)
    {
        l=l+(pow(k,i))/2*n;
    }
    return l;
}
int main()
{
    float d,e,f,o,n;
    trian(d,e,f,n);
    o=chuvi(d,e,f);
    cout<<"chu vi tam giac la: "<<o<<endl ;
    cout<<"gia tri bieu thuc F la: "<<gt(d,n,2*o);
}


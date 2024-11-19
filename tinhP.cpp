#include <iostream>
#include <math.h>
using namespace std;

void nhap(float &x)
{
    cout << "Nhap so thuc: "; cin >> x;
}

void nhap(int &n)
{
    cout << "Nhap so nguyen: "; cin >> n;
}

int tang(int n)
{
    n=n+1;
    return n;
}

int giam(int n)
{
    n=n-1;
    return n;
}

float P(float x, int n)
{
    float total = 2018*pow(x,n);
    for (int i=2; i<=n; i++)
    {
        total=total+ (pow(x,i))/pow(3,i-1);
  
    }
        return total;
}
/*for(int i=1; n<=n; i++)
    {
        float T=T*pow(x,i);
        int M= pow(3,i-1);
        total=total+T/M;
        return total;
    }
}
*/
int tong(int n)
{
    int total = 0;
    if (n>5 && n%2==0)
    {
        float total=n;
        return total;
    }
}
int tongChan(int n, int m)
{
    int total=0;
    if(n<=m)
    {
        for(int i=6; i<=m; i+=2)
            total += i;
        return total;
    }
    else
    {
        for(int i=6; i<=n; i+=2)
            total += i;
        return total;
    }
}
int main()
{
    float x;
    int n,m,t=0,d ;
    nhap(x);
    nhap(n);
    nhap(m);
    cout << "tang(n)= " << tang(n) << endl;
    cout << "tang(m)= " << tang(m) << endl;
    d=tang(n);
    cout << "P(x,n)= " << P(x,d) << endl;
cout<<"tong chan la: "<<tongChan(n,m);
}
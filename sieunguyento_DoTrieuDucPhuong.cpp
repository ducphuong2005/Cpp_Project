#include <iostream>
#include <math.h>
using namespace std;
//so siu nguyen to la so ma khi bo 1 chu so ben phai so do ta van thu duoc so nguyen to

int nt(int n)
{  
   
    if(n<2) return false;
    else
    {
    for (int i=2; i<=sqrt(n); i++)
    {
       if(n%i==0) return false;
    }

    }
    return true;
}
int snt(int n)
{
     while (n!=0)
     {
          if(nt(n)==false) return false;
          n/=10;
     }
     return true;
}
int main()
{
     int n;
     cout<<"Nhap n: ";
     cin>>n;
     if(snt(n)==true) cout<<n<<" la so sieu nguyen to ";
     else cout<<n<<" khong la so sieu nguyen to";
}
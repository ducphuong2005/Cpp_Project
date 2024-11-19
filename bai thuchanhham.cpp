#include <iostream>
#include <math.h>

using namespace std;

int NT(int &k)
{ 
    cout<<"Nhap k: ";
    cin>>k;
    for (int i=2; i<=sqrt(k); i++)
    {
        if(i%k==0) cout<<"No";
        else cout<<"Yes";

    }
    if(k==1) cout<<"No";
}
int main()
{   int m,l;
    l=NT(m);
    cout<<l;
    int n,d=0;
    cout<<endl<<"Nhap n ";
    cin>>n;
    if (n==1) cout<<"Tong la 0";
   else  
   {
    for (int i=2; i<= n; i++)
    {
        if(n%i!=0) d=d+i;
    }
    cout<<d;

   } 

}

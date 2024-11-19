#include<iostream>
#include<cmath>
using namespace std;
 int main()
{
   int a[100];
   int n;
   cout<<"Nhap so phan tu cua mang: ";
   cin>>n;
   for (int i=0;i<=n;i++)
   cin>>a[i];
   for(int i=0; i<=n-1;i++)
   for (int j=i+1;j<=n; j++)
   {if(a[i]>a[j]) swap(a[i],a[j]);}

   for(int i=0; i<=n;i++)
   cout<<a[i]<<" ";
    
}
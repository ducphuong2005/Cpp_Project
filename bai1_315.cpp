//phan c,d:
#include <iostream>

using namespace std;

int nhap(int a[],int n)
{
    cout<<"Nhap so phan tu mang a: "; cin>>n;
    for(int i=0; i<n; i++)
    cin>>a[i];
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}

int main()
{
    int n;
    int *a=new int [n];
    int b[100];
    int c[100];
    nhap(a,n);
    for(int i=0; i<n;i++)
    {
        if(a[i]%2!=0) b[i]=a[i];
    }
   for(int i=0; i<n; i++)
   {
     if(b[i]>b[i+1]) 
     swap(b[i],b[i+1]);
   }
   for(int i=0; i<n; i++) cout<<b[i]<<" ";
   for(int i=0; i<n;i++)
    {
        if(a[i]%2==0) c[i]=a[i];
    }
   for(int i=0; i<n; i++)
   {
     if(c[i]<c[i+1]) 
     swap(c[i],c[i+1]);
   }
   for(int i=0; i<n; i++) cout<<c[i]<<" ";
}

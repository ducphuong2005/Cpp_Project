#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int k;
    int n;
    int m=1;
   float s=0;
    cout<<"nhap bai muon lam "; cin>>k;

    switch (k)
    {
        case 1:
          cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
            for (int i=2; i<=n+2; i=i+2)
            s=s+i;
          }
          cout<<s;
          break;
        case 2:
            cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
            for (int i=1; i<=n+1; i=i+2)
            s=s+i;
          }
          cout<<s;
          break;
        case 3:
            cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
            for (int i=1; i<=n; i++)
            s=s+i*i;
          }
          cout<<s;
          break;
        case 4:
           cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
            for (int i=1; i<=n; i++)
           if(i%2==0) s=s-i*i;
           else s=s+i*i;
          }
          cout<<s;
          break;
        case 5:
         cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
            for (int i=1; i<=n; i++)
            s=s+1/i;
          }
          cout<<s;
          break;
        case 6:
          cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
            for (float i=2; i<=n; i=i*2)
            s=s+1/(i*i);
          }
          cout<<s;
          break;
        case 7:
             cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
            for (float i=1; i<=2*n+1; i+=2)
            s=s+1+1/(2*i+1);
          }
          cout<<s;
          break;
        case 8:
              cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
            for (float i=1; i<=n; i++)
            s=s+1/(i*(i+1));

          }
          cout<<s;
          break;
        case 9:
           cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
            for (float i=1; i<=n; i++)
            s=s+i/(i+1);
          }
          cout<<s;
          break;
        case 10:
         cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
            for (float i=0; i<=n; i++)
            s=s+(2*n+1)/(2*n+2);
          }
          cout<<s;
          break;
        case 11:
             cout<<"nhap n "; cin>>n;
             for(int i=1; i<=n; i++)
             m=m*i;
             cout<<m;
             break;
        case 12:
        int s1=1;
         cout<<"nhap n "; cin>>n;
          if(n>=0 ) 
          {
             for(int i=1; i<=n; i++)
             m=m*i;
             s1=s1+m;
          }
          cout<<s1;
          break;
        case 13:
          int x;
          cout<<"Nhap x,n "; cin>>x>>n;
          cout<<pow(x,n);
          break;
          
           

    }
}

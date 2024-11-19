#include<iostream>
using namespace std;
int const MOD = 1e5+5;
int n,m,k,d;
int a[MOD][MOD];
void Nhap()
  {cin>>n>>m>>k>>d;
    for(int i =0;i<n;++i)
    for(int j=0;j<m;++j)
     cin>>a[i][j];
  }

int Cau(int i,int m,int n,int d)
{
    
   int s = MOD;
   int  t = 0;
    for(int i = 1;i<=m-1;++i)
    {
        for(int j =i;j<=i+d && i+d <= m-2;++j)
        {
            t+= (a[i][j]+1);
            s = min(s,t);
            t = t - a[i][j]-1;
            
        }
        t = s;
    }
    return s+2;
}
int Solve()
{
    Nhap();
    int l = 0;
    int r = n-k-1;
    int kq =0;
    for(int i =0;i<=n-1-k;++i)
    {
       kq+= Cau(i,m,n,d);
    }

    while(r<n-1)
    { r++;
        int p = kq;
        p-= Cau(l,m,n,d);
        p+= Cau(r,m,n,d);
        l++;
        kq = min(kq,p);
    }
    return kq;
}
int main()
{
    cout << Solve();
    
}
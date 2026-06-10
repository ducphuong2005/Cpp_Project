#include <iostream>

using namespace std;

int timVT(int a[], int l, int r, int k)
{
    if(l>r)
        return -1;
    if(l==r)
    {
        if(a[l]==k)
            return l;
        return -1;
    }
    int m=(l+r)/2;
    int left=timVT(a, l, m, k);
    if(left!=-1)
        return left;
    return timVT(a, m+1, r, k);
}

struct xeKhach{
    string tenXe;
    int soHK;
    int tienThu;
};

// int ThamLam(xeKhach ds[], int n, int m, xeKhach kq[], int &p)
// {
//     int sl=0;
//     p=0;
//     for(int i=0; i<n; i++)
//     {
//         kq[sl++]=ds[i];
//         p+=ds[i].tienThu;
//         if(p>m)
//         {
//             return sl;
//         }
//     }
//     return 0;
// }

int ThamLam(xeKhach ds[], int n, int m, xeKhach kq[], int &p)
{
    int sl = 0;
    p = 0;

    for(int i = 0; i < n; i++)
    {
        if(p + ds[i].tienThu <= m)
        {
            kq[sl++] = ds[i];
            p += ds[i].tienThu;
        }
    }

    return sl;
}


int QuyHD (xeKhach ds[], int n, int k, xeKhach kq[], int &t)
{
   int **dp= new int *[n+1];
   for(int i=0; i<=n; i++)
   {
        dp[i]=new int [k+1]();
   }
   for(int i=1; i<=n; i++)
   {
        for(int j=0; j<=k; j++)
        {
            dp[i][j]=dp[i-1][j];
            int w= ds[i-1].soHK;
            int v= ds[i-1].tienThu;
            if(w<=j){
            int tam =v+dp[i-1][j-w];
            if(dp[i][j]<tam)
                dp[i][j]=tam;
            }
        }
   }

   int sl=0;
   int i=n, j=k;
   t=0;
   while(i>0 && j>0)
   {
    if(dp[i][j]!=dp[i-1][j])
    {
        kq[sl++]=ds[i-1];
        t+=ds[i-1].tienThu;
        j-=ds[i-1].soHK;
    }
    i--;
   }
   for(int l=0; l<sl/2; l++)
   {
        swap (kq[sl-1-l], kq[l]);
   }
   for(int i=0; i<=n; i++)
    delete[] dp[i];

    delete[] dp;
    return sl;
}

void HienThi(int sl, int tong)
{
    cout<<"Tong so xe: "<<sl<<endl;
    cout<<"Tong so tien thu duoc: "<<tong<<endl;
}

int main(){
    cout<<"========Cau 1======="<<endl;
    int n=13, k=8;
    int a[]= {1,3,2,4,5,6,8,11,23,14,20,36,40};
    int vT=timVT(a,0,n-1,k);
    cout<<"vi tri k la: "<<vT<<endl;
    cout<<"=======Cau 2======"<<endl;
    int soXe=8;
    xeKhach d[] ={
        {"Hoang Long", 45, 9000000}, {"Hai Au", 40, 8500000},
        {"Thanh Cong", 38, 8000000}, {"Ha Son", 35, 7500000},
        {"Anh Huy", 30, 7000000},    {"Phuong Trang", 28, 6500000},
        {"Mai Linh", 25, 6000000},   {"Duc Phuc", 20, 5000000}
    };
    xeKhach kq[soXe];
    int m=25000000;
    int v=100;
    cout<<"======Tham lam===="<<endl;
    int p=0;
    int u=ThamLam(d,soXe, m, kq, p);
    HienThi(u,p);
    cout<<"======QHD===="<<endl;
    int t=0;
    int q= QuyHD(d, soXe, v,kq, t);
    HienThi(q,t);
    

}
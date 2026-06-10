#include <iomanip>
#include <iostream>

using namespace std;

int A(int k, int l, int r, int a[])
{
    if(l==r)
    {
        if(a[l]%k==0)
            return 1;
        return 0;
    }
    int m=(l+r)/2;
    return A(k,l, m, a) + A(k,m+1,r,a);
}

struct giaoVien{
    string hoTen;
    int soLop;
    int luongThang;
};

int G(giaoVien ds[], int n, int m, giaoVien kq[], int &v)
{
    int sl=0;
    v=0;
    for(int i=n-1; i>=0; i--)
    {
        if(v+ds[i].luongThang<=m)
        {
            kq[sl++]=ds[i];
            v+=ds[i].luongThang;
        }
    }
    return sl;
}

int D(giaoVien ds[], int n, int m, giaoVien kq[], int &t)
{
    int **dp=new int *[n+1];
    for(int i=0; i<=n; i++)
    {
        dp[i]=new int [m+1]();
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            dp[i][j]=dp[i-1][j];
            int w=ds[i-1].luongThang;
            int v=ds[i-1].soLop;

            if(w<=j)
            {
                int tam= v+ dp[i-1][j-w];
                if(dp[i][j]<tam)
                    dp[i][j]=tam;
            }
        }
    }
    int sl=0;
    t=0;
    int i=n, j=m;
    while (i>0&&j>0)
    {
        if(dp[i][j]!=dp[i-1][j])
        {
            kq[sl++]=ds[i-1];
            t+=ds[i-1].soLop;
            j-=ds[i-1].luongThang;
        }
        i--;
    }
    for(int l=0; l<sl/2; l++)
    {
        swap(kq[sl-1-l], kq[l]);
    }
    for(int i=0; i<=n; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return sl;
}

void hienThiG(int u, int v)
{
    if(u==0)
    {
        cout<<"Khong co phuong an"<<endl;
        return;
    }
    cout<<"So giao vien nhieu nhat: "<<u<<endl;;
    cout<<"So luong "<<v<<endl;
}

void hienThiD(giaoVien kq[], int sl, int t)
{
    if(sl==0){
        cout<<"Khong co phuong an "<<endl;
        return;
    }
    int tong=0;
    cout<<"Danh sach giao vien duoc chon: "<<endl;
    cout<<left<<setw(20)<<"Ho ten"<<setw(20)<<"So lop"<<setw(20)<<"Luong thang"<<endl;
    for(int i=0; i<sl; i++)
    {
            cout<<left<<setw(20)<<kq[i].hoTen<<setw(20)<<kq[i].soLop<<setw(20)<<kq[i].luongThang<<endl;
            tong+=kq[i].luongThang;
    }
    cout<<"Tong so lop t: "<<t<<endl;
    cout<<"Tong luong: "<<tong<<endl;
}

int main()
{
    cout<<"=====Cau 1======"<<endl;
    int a[]={5,7,32,76,2,4,87,35,23,67,45,86};
    int n=12;
    int k1=2, k2=4;
    cout<<A(k1, 0, n-1, a)<<endl;
    cout<<n-A(k2,0,n-1,a)<<endl;
    cout<<"=====Cau 2======"<<endl;
     giaoVien ds[] =
    {
        {"Nguyen Van A", 8, 1500},
        {"Tran Thi B", 7, 1400},
        {"Le Van C", 6, 1300},
        {"Pham Thi D", 5, 1200},
        {"Hoang Van E", 4, 1000},
        {"Do Thi F", 3, 900},
        {"Vu Van G", 2, 700},
        {"Nguyen Thi H", 1, 500}
    };
    
    int soGV=8;
    int luong=5000;
    int v;
    giaoVien kq[soGV];
    cout<<"====tham lam===="<<endl;
    int u=G(ds,soGV,luong,kq,v);
    hienThiG(u,v);
    cout<<"=====QHD====="<<endl;
    int t;
    int q=D(ds,soGV,luong,kq,t);
    hienThiD(kq,q,t);
}
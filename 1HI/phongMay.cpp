#include <iomanip>
#include <iostream>

using namespace std;


void A(double a[], int n, double k, double &tong, int &dem)
{
    if(n==0)
    {
        tong=0;
        dem=0;
        return;
    }
    A(a,n-1, k, tong, dem);
    if(a[n-1]<k){
        cout<<a[n-1]<<endl;
        tong+=a[n-1];
        dem++;
    }
}

struct phongMay{
    string soHieu;
    int soLuong;
    string nguoiQL;
    int giaTL;
};

int G(phongMay ds[], int n, int m, phongMay kq[], int tien)
{
    int sl=0;
    tien=0;
    for(int i=0; i<n; i++)
    {
        int tiens= ds[i].giaTL*ds[i].soLuong;
        if(tien+tiens<=m)
        {
            kq[sl++]=ds[i];
            tien+=tiens;
        }
    }
    return sl;
}

int D(phongMay ds[], int n, int m, phongMay kq[], int &t)
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

            int w= ds[i-1].soLuong*ds[i-1].giaTL;
            int v=ds[i-1].soLuong;
            if(w<=j){
                int tam=v+dp[i-1][j-w];
                if(dp[i][j]<tam)
                    dp[i][j]=tam;
            }
        }
    }

    int sl=0;
    t=0;
    int i=n, j=m;
    while (i>0 && j>0)
    {
        if(dp[i][j]!=dp[i-1][j])
        {
            kq[sl++]=ds[i-1];
            t+=ds[i-1].soLuong;
            j-=ds[i-1].giaTL*ds[i-1].soLuong;
        }
        i--;
    }
    for(int l=0; l<sl/2; l++)
    {
        swap(kq[sl-1-l], sl[l]);
    }
    for(int i=0; i<=n; i++)
        delete[] dp[i];
    delete[] dp;

    return sl;
}

void hienThiG(phongMay kq[], int sl)
{
    if(sl==0)
    {
        cout<<"Khong co phuong an "<<endl;
    }
    cout<<"So luong phong may: "<<sl<<end;
    cout<<"Danh sach phong may: "<<endl;

    bool check=false;
    cout << left << setw(10) << "So hieu" << setw(10) << "So luong" << setw(20)
       << "Nguoi quan ly" << setw(15) << "Gia thanh ly" << endl;

    for(int i=0; i<sl; i++)
    {
        if(kq[i].nguoiQL=="Nguyen Van Hoang")
        {
            check=true;
            cout << left << setw(10) << kq[i].soHieu << setw(10) << kq[i].soLuong
           << setw(20) << kq[i].nguoiQL << setw(15) << kq[i].giaThanhLy << endl;
        }
    }
    if(check==false)
    {
        cout<<"Khong co phong do NVH quan ly "<<endl;
    }
}

void hienThiD(int sl, int t)
{
    cout << "So luong phong may: " << sl << endl;
  cout << "Tong so luong may: " << t << endl;
}

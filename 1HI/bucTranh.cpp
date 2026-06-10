#include <iomanip>
#include <iostream>

using namespace std;

int A(int a[],int l, int r, int &tong)
{
    if(l==r)
    {
        if(a[l]%2==0)
        {
            tong=a[l];
            return 1; 
        }
        tong=0;
        return 0;
    }
    int m=(l+r)/2;
    int tong1, tong2;
    int dem1=A(a,l,m,tong1);
    int dem2=A(a,m+1,r, tong2);
    tong=tong1+tong2;

    return dem1+dem2;

}

struct bucTranh{
    string tieuDe;
    string tenTG;
    int kichThuoc;
    int giaBan;
};

int G(bucTranh ds[], int n, int s, bucTranh kq[], int &tong)
{
    int sl=0;
    tong=0;
    for(int i=n-1; i>=0; i--)
    {
        if(tong+ ds[i].kichThuoc <=s)
        {
        kq[sl++]=ds[i];
        tong+=ds[i].kichThuoc;
        }
    }
    return sl;
}

void hienthiG(bucTranh kq[], int sl, int tongDT)
{
    if(sl==0)
    {
        cout<<"Khong co phuong an"<<endl;
        return;
    }
    cout<<"Tong so luong tranh: "<<sl<<endl;
    cout << left
         << setw(20) << "Tieu de"
         << setw(20) << "Tac gia"
         << setw(15) << "Kich thuoc"
         << setw(15) << "Gia ban"
         << endl;
    for(int i=0; i<=sl; i++)
    {
        if(kq[i].kichThuoc>20)
        {
        cout << left
         << setw(20) << kq[i].tieuDe
         << setw(20) << kq[i].tenTG
         << setw(15) << kq[i].kichThuoc
         << setw(15) << kq[i].giaBan
         << endl;
        }
    }
    cout<<"Tong dien tich: "<<tongDT<<endl;
    
}

int D(bucTranh ds[], int n, int m, bucTranh kq[], int &t)
{
    int **dp=new int *[n+1];
    for(int i=0; i<=n; i++)
        dp[i]=new int [m+1]();
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            dp[i][j]=dp[i-1][j];
            int w= ds[i-1].giaBan;
            int v=ds[i-1].kichThuoc;
            if(w<=j)
            {
                int tam = v + dp[i-1][j-w];
                if(dp[i][j]<tam)
                    dp[i][j]=tam;
            }
        }
    }
    int sl=0;
    t=0;
    int i=n, j=m;
    while(i>0&&j>0)
    {
        if(dp[i][j]!=dp[i-1][j])
        {
            kq[sl++]=ds[i-1];
            t+=ds[i-1].kichThuoc;
            j-=ds[i-1].giaBan;
        }
        i--;
    }
    for(int l=0; l<sl/2; l++)
    {
        swap(kq[sl-1-l],kq[l]);
    }
    for(int i=0; i<=n; i++)
        delete[] dp[i];
    delete[] dp;

    return sl;
}

void hienThiD(int q, int t)
{
    if(q==0)
    {
        cout<<"Khong tim thay phuong an "<<endl;
        return;
    }
    cout<<"So luong buc tranh: "<<q<<endl;
    cout<<"Tong kich thuoc: "<<t<<endl;
}

int main()
{
     cout << "===== CAU 1 =====" << endl;

    int a[] =
    {
        -12,15,-18,20,25,-30,
        35,40,45,50,60,72
    };
    int n=12;
    int tongChan=0;
    int hi=A(a,0,n-1,tongChan);
    if(tongChan == 0)
    {
        cout << "Khong co so chan\n";
    }
    else
    {
        cout << "So luong so chan: "
             << hi << endl;
    }
    cout<<"=====Cau 2====="<<endl;
    bucTranh ds[]={
         {"Tranh A","Tac gia A",35,1500},
        {"Tranh B","Tac gia B",30,1400},
        {"Tranh C","Tac gia C",28,1300},
        {"Tranh D","Tac gia D",25,1200},
        {"Tranh E","Tac gia E",22,1000},
        {"Tranh F","Tac gia F",18,900},
        {"Tranh G","Tac gia G",15,700},
        {"Tranh H","Tac gia H",10,500}
    };
    int soBT=8;
    bucTranh kq[soBT];
    int s=100;
    int tien=5000;
    cout<<"====Tham lam====="<<endl;
    int tong;
    int sl=G(ds,soBT,s,kq,tong);
    hienthiG(kq,sl,tong);
   cout<<"=====QHD====="<<endl;
   int t;
   int kt=D(ds,soBT,tien, kq,t);
   hienThiD(kt,t);
}
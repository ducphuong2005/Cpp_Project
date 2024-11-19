#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    // nhập vao bàn phím 1 số n ktra số đấy phải số nguyên tố không
    // for(khởi tạo;điều kiện;end)
int n;
cout<<"Nhap n";
     cin>>n;
     int t;
     t=0;
   if(n==1)
      cout<< "Khong phai so nguyen to";
if(n>1)
{
    for(int i=2; i<= sqrt (n); i++ )
    {
        if( n%i==0 )
        t++;
    }
    if(t ==0) cout << "la so nguyen to";
    else cout << "khong phai la so nguyen to";
}
    return 0;
}
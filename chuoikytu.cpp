#include<iostream>
#include<string.h>
using namespace std;

void xoa_k(char s[], int k)
{
int n=strlen(s);
if (k<0 || k>=n )
cout<<" vi tri xoa khong hop le";
else {
    for(int i=k+1; i<=n; ++i)
    s[i-1]=s[i];
    --n;

}
}
 int main()
 {
    char s[100];
    cout<<"nhap ho va ten: ";
    fflush (stdin);
    gets(s);
    cout<<"ho ten da nhap la: "<<s;
    int n=strlen(s);
    if (s[0]!=' ')
    if(s[0]>=97)
    s[0]-=32;

    for(int i=1; i<n; ++i)
    if(s[i]!= ' ' && s[i-1]==' ')
    if (s[i]>=97)
    s[i]-=32;
    cout<<endl<< "ho ten da chuan hoa la: "<<s;
//1. dem xem trong chuoi co bao nhieu ky tu hoa
//2. cho biet chuoi co bao nhieu tu
//3. nhap vao ky tu c tu ban phim, xoa tat ca cac ky tu c xuat hien trong chuoi
int c;
cout<<endl<<"ky tu can xoa= ";
cin>>c;
for(int i=0; i<n; ++i)
if(s[i]==c)
xoa_k(s,i);
cout<<endl<<"mang sau khi xoa: "<<s;
 int d=0;
 
 }
#include<iostream>

using namespace std;

int count(int x){
    if(x<10) return 1;
    else 
    return count(x/10)+1;
}
int main()
{
    int x;
    cout<<"Nhap x: ";
    cin>>x;
    cout<<"So chu so cua x la: "<<count(x);
    return 0;
}


#include<iostream>

using namespace std;

int Daonguocxaukytu(char a[], int n)
{
    if(n==1) cout<<a[0];
    else 
    {
    	cout <<a[n-1];
    	Daonguocxaukytu(a, n-1);
	}
}
int main()
{
    char a[100];
    cin>>a;
    Daonguocxaukytu(a, strlen(a));
    return 0;

}
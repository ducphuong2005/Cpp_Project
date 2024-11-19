#include <iostream>
#include <math.h>
using namespace std;

long gt (int n)
{
    long gt=1;
    for (int i; i<=n; i++)
    gt=gt*i;
    return gt;
}
int main()
{

    int n;
    float s;
    cout << "n= "; cin >> n;
    s= gt(n)/gt(n+1);
    cout << "s= " <<s<< endl;
    return 0;
}
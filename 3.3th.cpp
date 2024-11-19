#include <iostream>

using namespace std;

void nhap (float &a, float &b, float &c)
{
    cout << "a= "; cin >> a;
    cout << "b= "; cin >> b;
    cout << "c= "; cin >> c;

}
float MAX (float a, float b, float c)
{
    float m=a;
    if (b>m) m=b;
    if (c>m) m=c;
    return m;
}
float MIN (float a, float b, float c)
{
    float n=a;
    if (b<n) n=b;
    if (c<n) n=c;
    return n;
}
int main()
{
    float a,b,c;
    nhap (a,b,c);
    MAX (a,b,c);
    MIN (a,b,c);
    cout << "MAX= "<< MAX(a,b,c) << endl;
    cout << "MIN= "<< MIN(a,b,c);
    return 0;
}
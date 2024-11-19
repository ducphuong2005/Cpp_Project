#include <iostream>
#include <fstream>

using namespace std;


void CreateFile(char *k, int **a)
{
    int n,m;
    ofstream f(k, ios::out);
    cout<<"n=";
    cin>>n;
    f<<"n="<<n<<endl;
    cout<<"m=";
    cin>>m;
    f<<"m="<<m<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j];
            cin>>a[i][j];
            f<<"a["<<i<<"]["<<j<<"]="<<a[i][j];
        }
        f<<endl;
    }
    f.close();
}

void ReadFile(char *k, int **&a, int &n, int &m)
{
    ifstream f(k, ios::in);
    char s[255];
    n=atoi(s);
    m=atoi(s);
    f>>s;
    a=new int*[n];
    for(int i=0; i<n; i++)
        a[i]=new int[m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            f>>a[i][j];
            a[i][j]=atoi(s);
        }
    }
    f.close();
}

void Print(int **a, int &n, int &m)
{
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,m;
    int **a=new int*[n];
    for(int i=0; i<n; i++)
    {
        a[i]=new int [m];
    }
    CreateFile("D:/bai53.txt", a);
    ReadFile("D:/bai53.txt",a, n, m);
    Print(a, n, m);
}


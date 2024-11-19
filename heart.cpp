#include <iostream>
using namespace std;

string s = "Happy Valentine";

void prnt(char c, int cnt){
    for(int j=1;j<=cnt;j++) cout << c;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(s.size() % 2 == 0) s += ' ';
    while(s.size() <= 6) s = ' ' + s + ' ';
    int width = s.size()+4;
    for(int i=3;i>0;i--){
        int sp = 1 + (i-1)*2;
        prnt(' ',i);
        if(i == 3) prnt('*',(width - 2*i - sp)/2);
        else{
            cout << '*';    
            prnt(' ',(width - 2*i - sp)/2-2);
            cout << '*';
        }
        prnt(' ',sp);
        if(i == 3) prnt('*',(width - 2*i - sp)/2);
        else{
            cout << '*';
            prnt(' ',(width - 2*i - sp)/2-2);
            cout << '*';
        }
        cout << '\n';
    }
    for(int i=1;i<=2;i++){
        cout << '*';
        prnt(' ',(width - 3)/2);
    }
    cout << "*\n";
    for(int i=1;i<=2;i++){
        cout << '*';
        if(i == 1){
            cout << ' ' << s << ' ';
        }
        else prnt(' ',width-2);
        cout << "*\n";
    }
    for(int i=1;i<=(width-1)/2;i++){
        prnt(' ',i);
        cout << '*';
        prnt(' ',width - 2 - 2*i);
        if(i < (width-1)/2) cout << "*\n";
    }
    return 0;
}
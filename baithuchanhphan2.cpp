#include <iostream>
#include <cmath>
 using namespace std;
  int main()
  {
    int k,a,b,X,Y,Z;
    float x,y,diem;

    cout<<" chon bai muon lam ";
    cin>>k;
    switch(k)
    {
    case 1:
      cout<<"nhap so nguyen a,b"; cin>>a>>b;
      cout<<"Nhap so thuc x,y"; cin>>x>>y;
      cout<<5*cos(3*x+2)-log(x*x+2)+sqrt(a*a+b*b)-(abs(x-y)/(pow(a,6)+1));
      break;
    case 2:
       cout<<"Nhap X,Y,Z"; cin>>X>>Y>>Z;
       cout<<"gia tri lon nhat trong 3 so la "<<max(max(X,Y),Z);
       cout<<"gia tri nho nhat trong 3 so la "<<min(min(X,Y),Z);
       break;
    
    case 3:
        cout<<"Nhap diem tong ket "; cin>>diem;
           if(diem >=8) cout<<"Gioi";
           else if(diem >=7 && diem <8 ) cout<<"Kha";
           else if(diem >=5 && diem <7 ) cout<<"Trung binh";
           else if(diem >=3 && diem< 5) cout<<"Yeu";
           else cout<<"Kem";

        break;
    case 4:
         float a,b,x;
	cout<<"a=";
	cin>>a;
	cout<<"b=";
	cin>>b;
	if(a==0){
		if(b==0)
			cout<<"pt vo so nghiem";
		else
			cout<<"pt vo nghiem";
	}
	else{
		x=-b/a;
		cout<<"pt co nghiem duy nhat x="<<x;
        break;
    
    case 5:
        int t,n;
        cout<<"Nhap thang, nhap nam hien tai "; cin>>t>>n;
        if(t%2==1 || t==8) cout<<"thang "<<t<<" co 31 ngay";
        if(t==4||t==6||t==9||t==11) cout<<"thang "<<t<<" co 30 ngay";
        if(t==2 && ((n%4==0 && n%100 !=0)||n%400==0)) cout<<"thang 2 nam nay co 29 ngay";
        
        else if (t==2 && ((n%4!=0 && n%100 ==0)||n%400!=0)) cout<<"Thang 2 nay co 28 ngay";
        
        break;

    case 0:
        return 0;
    }
    }

  }

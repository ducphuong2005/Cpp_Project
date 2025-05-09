#include <iostream>
#include <iomanip>
using namespace std;

struct SinhVien{
    int id;
    char hoTen[30];
    float diemTK;
};
 struct Node{
    SinhVien infor;
    Node *next;
 };
 typedef Node* TRO;
 TRO L;

//khoi tao danh sach rong
void create (TRO &L){
    L = NULL;
}
//kiem tra danh sach rong
 int empty (TRO &L){
    return L == NULL;
}
//nhap thong tin sinh vien
void inputTT(SinhVien &sv){
    cout << "Nhap ID: ";
    cin >> sv.id;
    fflush(stdin); // Xóa bộ đệm đầu vào
    cout << "Nhap ho ten: ";
    cin.getline(sv.hoTen, 30);
    cout << "Nhap diem TK: ";
    cin >> sv.diemTK;
}
//nhap danh sach sinh vien
void inputDS(TRO &L){
    SinhVien sv;
    TRO P,Q;
    int i=0;
    L= NULL;
    do{
        cout<<"Nhap sinh vien thu " << i+1 << endl;
        inputTT(sv);
        P=new Node;
        P -> infor = sv;
        P->next = NULL;
        if(L==NULL){
            L=P;
        }
        else {
            Q->next=P;
        }
        Q=P;
        i++;
    }
    while (i<3);
    }
    //xuat thong tin sinh vien
void outputTT(TRO &L){
    if(L==NULL){
        cout << "Danh sach rong" << endl;
        return;
    }
    TRO Q=L;
    cout<<left<<setw(8)<<"STT";
    cout<<left<<setw(10)<<"ID";
    cout<<left<<setw(20)<<"Ho ten";
    cout<<left<<setw(10)<<"Diem TK"<<endl;
    int d=0;
    while(Q!=NULL){
        SinhVien sv=Q->infor;
        cout<<left<<setw(8)<<d+1;
        cout<<left<<setw(10)<<sv.id;
        cout<<left<<setw(20)<<sv.hoTen;
        cout<<left<<setw(10)<<sv.diemTK<<endl;
        Q=Q->next;
        d++;
    }
}
//tim sinh vien co diem trung binh max
TRO tromax(TRO L){
    TRO max=L;
    TRO Q=L-> next;
    while(Q!=NULL){
        if(Q->infor.diemTK > max->infor.diemTK){
            max=Q;
        }
        Q=Q->next;
    }
    return max;
}
//xoa sinh vien co diem trung binh max dau tien
void deleteMax(TRO &L){
   TRO max, Q;
   max = tromax(L);
    if(max==L){
        L=L->next;
        delete max;
    }
    else{
        TRO Q=L;
        while(Q->next!=max){
            Q=Q->next;
        }
        Q->next=max->next;
        delete max;
    }
}
//chen 1 sinh vien truoc sinh vien co diem trung binh max
void insertBeforeMax(TRO &L, SinhVien sv){
    TRO max = tromax(L);
    TRO P = new Node;
    P->infor = sv;
    if(max == L){
        P->next = L;
        L = P;
    }
    else{
        TRO Q = L;
        while(Q->next != max){
            Q = Q->next;
        }
        Q->next = P;
        P->next = max;
    }
}
//dem bao nhieu sinh vien ten la "An"
void Count(TRO &L){
    int d=0;
    TRO Q=L;
    while(Q!=NULL){
        if(strcmp(Q->infor.hoTen, "an")==0){
            d++;
        }
        Q=Q->next;
    }
    cout << "So sinh vien co ten An la: " << d << endl;
}

void delName(TRO &L, TRO Q){
	TRO P = L;
	while (P->next!=Q)
		P=P->next;
	P->next=Q->next;
	delete Q;
}

void delN(TRO&L){
	TRO P=L;
	while(P!=NULL)
		if(strcmp(P->infor.hoTen, "an")==0){
			TRO Q = P;
			P=P->next;
			delName(L,Q);
		}
		else P=P->next;
}


    
int main()
{
    TRO L;
    TRO max;
    create(L);
    inputDS(L);
    cout << "Danh sach sinh vien: " << endl;
    outputTT(L);
    max=tromax(L);
    cout <<"Diem tong ket cua sinh vien co diem trung binh max la: "<<max->infor.diemTK << endl;
    deleteMax(L);
    cout << "Danh sach sinh vien sau khi xoa: " << endl;
    outputTT(L);
    SinhVien sv;
    cout << "Nhap sinh vien can chen: " << endl;
    inputTT(sv);
    insertBeforeMax(L, sv);
    cout << "Danh sach sinh vien sau khi chen: " << endl;
    outputTT(L);
    Count(L);
    delN(L);
    cout << "Danh sach sinh vien: " << endl;    
    outputTT(L);    
    return 0;
}
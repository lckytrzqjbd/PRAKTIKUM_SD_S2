#include <iostream>
using namespace std;

struct Stack {
int maks = 3, top = 0;
int lempeng[3];
string tiang;

void push(int data){
    if(top < maks){
        lempeng[top] = data;
        top++;
    }
}

void display(){
    cout << "Data Stack Hanoi" << endl;
    cout << "================" << endl;
    for(int i = maks-1 ; i >= 0; i--){
        if(lempeng[i] != 0){
            cout << "Stack ke-" << i << " = " << lempeng[i] << endl;
        }
    }
}

bool isFull(){
    if(top==maks) {
        cout << "Stack sudah penuh ";
        return true;
    }else{
        cout << "Stack Masih kosong " <<(maks-top) << "Data";
        return false;
    }
}

bool isEmpty() {
    return top == 0;
}

int pop(){
    if(!isEmpty()) {
        top--;
        int data = lempeng[top];
        lempeng[top] = 0;
        return data;
    }
    return -1;
    }
};

Stack A, B, C;

void pindah(int n, Stack &asal, Stack &tujuan, Stack &bantu) {
    if (n > 0) {
        pindah(n-1, asal, bantu, tujuan);
        int lempeng = asal.pop();
        tujuan.push(lempeng);
        cout << "Pindahkan lempeng " << lempeng << " dari " << asal.tiang << " ke " << tujuan.tiang << endl;
        pindah(n-1, bantu, tujuan, asal);
    }
}

int main()
{
    A.tiang = "A";
    B.tiang = "B";
    C.tiang = "C";
    
    A.push(30);
    A.push(20);
    A.push(10);
    
    cout << "=====================================" << endl;
    cout << "Urutan Perpindahan 3 lempengan Hanoi" << endl;
    cout << "Dari tiang A ke C melalui perantara B" << endl;
    cout << "=====================================" << endl;
    
    pindah(3, A, B, C);
    cout << "=====================================" << endl;
    return 0;
}
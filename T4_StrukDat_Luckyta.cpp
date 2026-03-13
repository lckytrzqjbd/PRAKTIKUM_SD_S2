#include <iostream>
using namespace std;

// Konsep Dasar Node (Seperti di Page 4)
struct Node {
    int data;
    Node* next; // Pointer yang merujuk ke node selanjutnya
};

//Fungsi untuk menyisipkan node di akhir
void insertBelakang(Node** head, int newData) {
  Node* newNode = new Node();
  newNode->data = newData;
  newNode->next = nullptr;
  
  //Jika list masih kosong, jadikan node baru sebagai head
  if (*head == nullptr) {
      *head = newNode;
      return;
  }
  
  //Jika tidak kosong, jalan sampai tail lalu sambung node baru
  Node* last = *head;
  while (last->next != nullptr) {
      last = last -> next;
  }
  last -> next = newNode;
}

//Fungsi utama untuk membalikkan linked list
void reverseLinkedList(Node** head) {
    Node* prev = nullptr;
    Node* current = *head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        //Simpang sambungan pointer node selanjutnya
        next = current -> next;
        
        //Putus sambungan dan balikkan panah pointer ke node sebelumnya (prev)
        current -> next = prev;
        
        //Geser posisi pointer maju satu langkah kedepan
        prev = current;
        current = next;
    }
    //Pindahkan head ke node yang tadinya berada di paling akhir (sekarang di depan)
    *head = prev;
}

//Fungsi untuk mencetak linked list
void cetakList (Node* node) {
    while (node != nullptr) {
        cout << node -> data;
        if (node -> next != nullptr) {
            cout << " -> ";
        }
        node = node -> next;
    }
    cout << endl;
}
int main()
{
    Node* head = nullptr;
    
    //Memasukkan data awal sesuai soal
    insertBelakang(&head, 5);
    insertBelakang(&head, 4);
    insertBelakang(&head, 3);
    insertBelakang(&head, 2);
    insertBelakang(&head, 1);
    
    cout << "Input: ";
    cetakList(head);
    
    //Memanggil fungsi untuk membalikkan urutan
    reverseLinkedList(&head);
    
    cout << "Output: ";
    cetakList(head);
    return 0;
}
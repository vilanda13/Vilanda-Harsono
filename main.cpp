#include <iostream>

using namespace std;

//deklarasi single linked list
struct Buku{

    // komponen / member
    string judul, pengarang;
    int tahunTerbit;

    Buku *next;

};

Buku *head, *tail, *cur , *newNode, *del;

//create single linked list
void createSingleLinkedList(string judul, string pengarang, int tB){
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
    head->next = NULL;
    tail = head;
}

// tambahAwal single linked list
void addFirst(string judul, string pengarang, int tB){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = head;
    head = newNode;

}

// tambahAkhir single linked list
void addLast(string judul, string pengarang, int tB){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;

}

// remove first
void removeFirst(){
    del = head;
    head = head->next;
    delete del;
}
// remove Last
void removeLast(){
   del = tail;
   cur = head;
   while( cur->next !=tail ){
    cur = cur->next;
   } 
   tail = cur;
   tail->next = NULL;
   delete del;
}

// ubahAwal single linked list
void changeFirst(string judul, string pengarang, int tB){
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;

}

// ubahAwal single linked list
void changeLast(string judul, string pengarang, int tB){
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tB;

}

// print single linked list
void printSingleLinkedList(){
   cur = head;
    while( cur != NULL){
        cout << "Judul Buku : " << cur->judul << endl;
        cout << "Pengarang Buku : " << cur->pengarang << endl;
        cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

        cur = cur->next;
    } 
}
int main (){

    createSingleLinkedList("Kata", "Geez & Aan", 2018);

    printSingleLinkedList();

    cout << "\n\n" << endl;

    addFirst("Dia adalah Kakakku","Tere Liye", 2009);

    printSingleLinkedList();

    cout << "\n\n" << endl;

    addLast("Aroma Karsa","Dee Lestari", 2018);

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    removeFirst();

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    addLast("11.11","Fiersa Besari", 2018);

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    removeLast();

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    changeFirst("Berhenti di Kamu","Gia Pratama", 2018);

    printSingleLinkedList();
    
    cout << "\n\n" << endl;


    }
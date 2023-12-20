#include <iostream>
using namespace std;

// Deklarasi single linked list
class Buku {
public:
    // Komponen / member
    string judul, pengarang;
    int tahunTerbit;
    Buku* next;

    // Constructor
    Buku(string newJudul, string newPengarang, int newTahunTerbit) : judul(newJudul), pengarang(newPengarang), tahunTerbit(newTahunTerbit), next(NULL) {}

    // Setter functions
    void setJudul(string newJudul) { judul = newJudul; }
    void setPengarang(string newPengarang) { pengarang = newPengarang; }
    void setTahunTerbit(int newTahunTerbit) { tahunTerbit = newTahunTerbit; }

    // Getter functions
    string getJudul() const { return judul; }
    string getPengarang() const { return pengarang; }
    int getTahunTerbit() const { return tahunTerbit; }
};

class SingleLinkedList {
public:
    Buku* head;
    Buku* tail;
    Buku* cur;
    Buku* newNode;
    Buku* del;

public:
    // Constructor
    SingleLinkedList() : head(NULL), tail(NULL), cur(NULL), newNode(NULL), del(NULL) {}

    // create single linked list
    void createSingleLinkedList(string judul, string pengarang, int tB) {
        head = new Buku(judul, pengarang, tB);
        tail = head;
    }

    // tambahAwal single linked list
    void addFirst(string judul, string pengarang, int tB) {
        newNode = new Buku(judul, pengarang, tB);
        newNode->next = head;
        head = newNode;
    }

    // tambahAkhir single linked list
    void addLast(string judul, string pengarang, int tB) {
        newNode = new Buku(judul, pengarang, tB);
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

    // remove first
    void removeFirst() {
        del = head;
        head = head->next;
        delete del;
    }

    // remove Last
    void removeLast() {
        del = tail;
        cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = NULL;
        delete del;
    }

    // ubahAwal single linked list
    void changeFirst(string judul, string pengarang, int tB) {
        head->setJudul(judul);
        head->setPengarang(pengarang);
        head->setTahunTerbit(tB);
    }

    // ubahAwal single linked list
    void changeLast(string judul, string pengarang, int tB) {
        tail->setJudul(judul);
        tail->setPengarang(pengarang);
        tail->setTahunTerbit(tB);
    }

    // print single linked list
    void printSingleLinkedList() {
        cur = head;
        while (cur != NULL) {
            cout << "Judul Buku : " << cur->getJudul() << endl;
            cout << "Pengarang Buku : " << cur->getPengarang() << endl;
            cout << "Tahun Terbit Buku : " << cur->getTahunTerbit() << endl;

            cur = cur->next;
        }
    }
};

int main() {
    // Create an object of SingleLinkedList class
    SingleLinkedList linkedList;

    // Use the object to perform linked list operations
    linkedList.createSingleLinkedList("Kata", "Geez & Aan", 2018);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.addFirst("Dia adalah Kakakku", "Tere Liye", 2009);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.addLast("Aroma Karsa", "Dee Lestari", 2018);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.removeFirst();
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.addLast("11.11", "Fiersa Besari", 2018);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.removeLast();
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.changeFirst("Berhenti di Kamu", "Gia Pratama", 2018);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    linkedList.addFirst("Terserah", "Vilanda", 2003);
    linkedList.printSingleLinkedList();
    cout << "\n\n" << endl;

    return 0;
}

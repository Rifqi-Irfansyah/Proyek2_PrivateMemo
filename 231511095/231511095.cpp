#include "231511095.h"
// #include "../231511089/231511089.h"
#include "../231511073/231511073.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void saveRecords(const char* filename, address_memo awal) {
    ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        cerr << "Gagal membuka file!" << endl;
        return;
    }

    address_memo current = awal;
    while (current != nullptr) {
        outFile.write(reinterpret_cast<char*>(&current->id_memo), sizeof(int));
        outFile.write(reinterpret_cast<char*>(&current->namaMemo), sizeof(char[30]));
        outFile.write(reinterpret_cast<char*>(&current->isiMemo), sizeof(char[300]));
        outFile.write(reinterpret_cast<char*>(&current->password), sizeof(char[50]));
        outFile.write(reinterpret_cast<char*>(&current->tanggal), sizeof(time_t));
        current = current->next;
    }
    outFile.close();
}

// modul inputMemo
void inputMemo() {
    int id_memo;
    address_memo awal, akhir, newNode;
    
    id_memo = readRecords("memo_coba.dat", awal, akhir);
    
    newNode = (address_memo) malloc(sizeof (ElmtList));
    if (newNode == NULL){
        printf("Memori Full");
    }
    else{
        newNode -> id_memo = id_memo + 1;
        char password[50]; // deklarasi variabel password bertipe array of char dengan length 50
        cout << "Nama Memo: ";
        cin.ignore();
        cin.getline(newNode -> namaMemo, 30); // dilakukan input untuk Nama Memo
        cout << "Isi Memo: ";
        cin.getline(newNode -> isiMemo, 300); // dilakukan input untuk Isian Memo
        cout << "Masukkan Password: ";
        cin.getline(password, 50); // menginputkan password
        
        int key = 17;
        string pw_encrpyt = encrypt(password, key); // dilakukan enkripsi password dengan memanggil function encrypt di 231511073.h
        strcpy(newNode -> password, pw_encrpyt.c_str());

        newNode -> tanggal = time(nullptr);
        newNode -> next = NULL;
        newNode -> prev = NULL;
    }
    
    if ((awal == NULL) && (akhir == NULL)){
        awal = newNode;
    }
    else{
        newNode->prev = akhir;
        akhir -> next = newNode;
    }
    akhir = newNode;

    saveRecords("memo_coba.dat", awal);
}
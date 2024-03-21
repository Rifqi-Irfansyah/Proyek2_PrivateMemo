#include "231511095.h"
#include "../231511073/231511073.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// modul tambahMemo
void tambahMemo(const Memo &memo) {
    ofstream file("Memos.dat", ios::out | ios::binary | ios::app);
    if (!file) {
        cerr << "Gagal membuka file!" << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(&memo), sizeof(Memo));
    // ditulis ke dalam file dalam bentuk biner dengan melakukan alokasi file terlebih dulu
    file.close();
    // file ditutup
}

// modul inputMemo
void inputMemo() {
    Memo newMemo;
    char password[50]; // deklarasi variabel password bertipe array of char dengan length 50
    cout << "Nama Memo: ";
    cin.ignore();
    cin.getline(newMemo.namaMemo, 30); // dilakukan input untuk Nama Memo
    cout << "Isi Memo: ";
    cin.getline(newMemo.isiMemo, 300); // dilakukan input untuk Isian Memo
    cout << "Masukkan Password: ";
    cin.getline(password, 50); // menginputkan password
    
    int key = 17;
    string pw_encrpyt = encrypt(password, key); // dilakukan enkripsi password dengan memanggil function encrypt di 231511073.h
    strcpy(newMemo.password, pw_encrpyt.c_str());

    newMemo.tanggal = time(nullptr);

    tambahMemo(newMemo);
}
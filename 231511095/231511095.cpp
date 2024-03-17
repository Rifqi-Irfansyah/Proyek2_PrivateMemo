#include "231511095.h"
#include "../231511073/231511073.h"
#include <iostream>
#include <fstream>
using namespace std;

// modul tambahMemo
void tambahMemo(const Memo &memo) {
    ofstream file("Memos.dat", ios::out | ios::binary | ios::app);
    if (!file) {
        cerr << "Gagal membuka file!" << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(&memo), sizeof(Memo));
    file.close();
}

// modul inputMemo
void inputMemo() {
    Memo newMemo;
    cout << "Nama Memo: ";
    cin.ignore();
    cin.getline(newMemo.namaMemo, 30);
    cout << "Isi Memo: ";
    cin.getline(newMemo.isiMemo, 300);
    newMemo.tanggal = time(nullptr);
    cout << "Masukkan Password: ";
    cin.getline(newMemo.password, 50); // menginputkan password
    
    string password_encrypt = encrypt(newMemo.password); // Memanggil fungsi encrypt dari 231511073.h

    tambahMemo(newMemo);
}
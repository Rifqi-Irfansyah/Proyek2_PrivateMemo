#include "231511095.h"
#include <iostream>
#include <fstream>
using namespace std;

void tambahMemo(const Memo &memo) {
    ofstream file("Memos.dat", ios::out | ios::binary | ios::app);
    if (!file) {
        cerr << "Gagal membuka file!" << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(&memo), sizeof(Memo));
    file.close();
}

void inputMemo() {
    Memo newMemo;
    cout << "Nama Memo: ";
    cin.ignore();
    cin.getline(newMemo.namaMemo, 30);
    cout << "Isi Memo: ";
    cin.getline(newMemo.isiMemo, 300);
    newMemo.tanggal = time(nullptr);

    tambahMemo(newMemo);
}
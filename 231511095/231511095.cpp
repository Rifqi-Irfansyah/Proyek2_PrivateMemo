#include "231511095.h"
#include <iostream>
#include <fstream>
using namespace std;

void tambahMemo(const Memo &memo) {
    ofstream file("memos.bin", ios::binary | ios::app);
    if (!file) {
        cerr << "Gagal membuka file!" << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(&memo), sizeof(Memo));
    file.close();
}

int main() {
    Memo newMemo;
    cout << "Nama Memo: ";
    getline(cin, newMemo.namaMemo);
    cout << "Isi Memo: ";
    getline(cin, newMemo.isiMemo);
    newMemo.tanggal = time(nullptr);

    tambahMemo(newMemo);

    return 0;
}
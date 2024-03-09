//#include "231511072.h"
// #include <fstream>
// #include <iostream>
// using namespace std;

// void readMemoFile(const char* filename, Memo& memo) {
    // ifstream file(filename, binary);
    // if (!file.is_open()) {
        // cerr << "Gagal Membuka Memo: " << filename << endl;
        // return;
    //}
    // Read memo name
    // getline(file, memo.namaMemo);

    // Read date (assumed to be the next line)
    // getline(file, memo.tanggal);

    // getline(file, memo.isiMemo); 

    // file.close();
//} 
// memo_reader.cpp
#include <iostream>
#include <fstream>
#include "231511072.h"

void readMemoFile(const char* filename, Memo& memo) {
    ifstream file(filename, ios::binary);

    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&memo), sizeof(Memo));
        file.close();

        cout << "Nama Memo: " << memo.namaMemo << endl;
        cout << "Tanggal: " << memo.tanggal << endl;
        cout << "Isi Memo: " << memo.isiMemo << endl;
    } else {
        cerr << "Gagal membuka file " << filename << endl;
    }
}

int main() {
    Memo memo;
    readMemoFile("memo.dat", memo);
    return 0;
}

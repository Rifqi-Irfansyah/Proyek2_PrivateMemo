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

int countDataMemo(){
    int numMemo = 0; // Jumlah data Memo yang terbaca
    ifstream readFile("Memos.dat", ios::in | ios::binary);
    if (readFile.is_open()) {
        // Hitung jumlah data dengan membaca per satu item
        Memo2 temp;
        while (readFile.read(reinterpret_cast<char*>(&temp), sizeof(Memo2))) {
            numMemo++;
        }
        readFile.close();
    }
    return numMemo;
}

Memo2* readMemoFile(){
    Memo2 *readMemo = nullptr; // Pointer ke array Memo
    int numMemo = 0; // Jumlah data Memo yang terbaca

    numMemo = countDataMemo();
    // Alokasikan memori untuk array readMemo
    readMemo = new Memo2[numMemo];

    // Baca data sebenarnya ke dalam array readMemo
    ifstream readFileAgain("Memos.dat", ios::in | ios::binary);
    if (readFileAgain.is_open()) {
        readFileAgain.read(reinterpret_cast<char*>(readMemo), numMemo * sizeof(Memo2));
        readFileAgain.close();
    } 
    else {
        cerr << "Gagal membuka file" << endl;
    }

    return readMemo;
}

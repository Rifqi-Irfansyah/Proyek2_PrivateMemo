#include <iostream>
#include <fstream>
#include <string>
#include "231511072.h"

int countDataMemo(){
    int numMemo = 0; // Jumlah data Memo yang terbaca
    ifstream readFile("Memos.dat", ios::in | ios::binary); //membuka file Memos.dat dalam mode baca dan mode biner
    if (readFile.is_open()) //memeriksa apakah file berhasil dibuka atau tidak
    {
        // Hitung jumlah data dengan membaca per satu item
        Memo2 temp; //membaca data dari file sementara
        while (readFile.read(reinterpret_cast<char*>(&temp), sizeof(Memo2))) //perulangan while yang akan membaca data dari file Memos.dat ke dalam objek temp
        {
            numMemo++; //menambahkan nilai numMemo dengan 1 setiap kali objek temp berhasil dibaca dari file //menghitung jumlah data Memo2 yang terbaca
        }
        readFile.close(); //menutup file Memos.dat setelah semua data selesai dibaca
    }
    return numMemo; //mengembalikan nilai numMemo 
}

Memo2* readMemoFile(){
    Memo2 *readMemo = nullptr ; // Pointer ke array Memo
    int numMemo = 0; // Jumlah data Memo yang terbaca

    numMemo = countDataMemo(); 
    // Alokasikan memori untuk array readMemo
    readMemo = new Memo2[numMemo];

    // Baca data sebenarnya ke dalam array readMemo
    ifstream readFileAgain("Memos.dat", ios::in | ios::binary);
    if (readFileAgain.is_open()) 
    {
        // Baca data dalam array readMemo yg telah dialokasi
        readFileAgain.read(reinterpret_cast<char*>(readMemo), numMemo * sizeof(Memo2));
        readFileAgain.close();
    } 
    else 
    {
        cerr << "Gagal membuka file" << endl;
    }

    return readMemo;
}
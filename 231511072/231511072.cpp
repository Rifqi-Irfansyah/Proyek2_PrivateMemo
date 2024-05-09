#include <iostream>
#include <fstream>
#include <string>
#include "231511072.h"

// int countDataMemo(){  
//     int numMemo = 0; // Jumlah data Memo yang terbaca
//     ifstream readFile("Memos.dat", ios::in | ios::binary); //membuka file Memos.dat dalam mode baca dan mode biner
//     if (readFile.is_open()) /
//     {
//         // Hitung jumlah data dengan membaca per satu item
//         Memo2 temp; //membaca data dari file sementara
//         while (readFile.read(reinterpret_cast<char*>(&temp), sizeof(Memo2))) //perulangan while yang akan membaca data dari file Memos.dat ke dalam objek temp
//         {
//             numMemo++; //menambahkan nilai numMemo dengan 1 setiap kali objek temp berhasil dibaca dari file //menghitung jumlah data Memo2 yang terbaca
//         }
//         readFile.close();
//     }
//     return numMemo;  
// }

// Memo2* readMemoFile(){
//     Memo2 *readMemo = nullptr ; // Pointer ke array Memo
//     int numMemo = 0; 

//     numMemo = countDataMemo(); 
//     // Alokasikan memori untuk array readMemo
//     readMemo = new Memo2[numMemo];

//     // Baca data sebenarnya ke dalam array readMemo
//     ifstream readFileAgain("Memos.dat", ios::in | ios::binary);
//     if (readFileAgain.is_open()) 
//     {
//         // Baca data dalam array readMemo yg telah dialokasi
//         readFileAgain.read(reinterpret_cast<char*>(readMemo), numMemo * sizeof(Memo2));
//         readFileAgain.close();
//     } 
//     else 
//     {
//         cerr << "Gagal membuka file" << endl;
//     }

//     return readMemo;
// }
int readRecords(const char* filename, address_memo& awal, address_memo& akhir) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        awal = nullptr;
        akhir = nullptr;
        // ofstream outFile(filename, std::ios::binary);
        return 0;
    }

    // Initialize head pointer
    awal = nullptr;
    akhir = nullptr;
    address_memo current = nullptr;
    while (inFile.peek() != EOF) {

        // Create a new Memo object
        address_memo newNode = new ElmtList;

        // Read data from file into the new Memo object
        inFile.read(reinterpret_cast<char*>(&newNode->id_memo), sizeof(int));
        inFile.read(reinterpret_cast<char*>(&newNode->namaMemo), sizeof(char[30]));
        inFile.read(reinterpret_cast<char*>(&newNode->isiMemo), sizeof(char[300]));
        inFile.read(reinterpret_cast<char*>(&newNode->password), sizeof(char[50]));
        inFile.read(reinterpret_cast<char*>(&newNode->tanggal), sizeof(time_t));

        // Link the new node to the linked list
        if (!awal) {
            awal = newNode;
        } else {
            current->next = newNode;
            newNode->prev = current;
        }
        current = newNode;
        akhir = current;
        current->next = NULL;
    }

    inFile.close();
    return akhir->id_memo;
}
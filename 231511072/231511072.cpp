#include <iostream>
#include <fstream>
#include <string>
#include "231511072.h"

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
            // newNode->prev = current;
        }
        current = newNode;
        akhir = current;
        current->next = NULL;
    }

    inFile.close();
    return akhir->id_memo;
} 
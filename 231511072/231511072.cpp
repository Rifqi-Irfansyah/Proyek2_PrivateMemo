#include "231511072.h"
#include <fstream>
#include <iostream>
using namespace std;

void readMemoFile(const char* filename, Memo& memo) {
    ifstream file(filename, binary);
    if (!file.is_open()) {
        cerr << "Gagal Membuka Memo: " << filename << endl;
        return;
    }

    // Read memo name
    getline(file, memo.namaMemo);

    // Read date (assumed to be the next line)
    getline(file, memo.tanggal);

    getline(file, memo.isiMemo); 

    file.close();
}

#ifndef MEMO_READER_H
#define MEMO_READER_H

#include <string>
#include <ctime>
// #include "../231511095/231511095.h"
using namespace std;

typedef struct Memo *address_memo;
typedef struct Memo {
    int id_memo; //var untuk menyimpan id memo
    char namaMemo[30]; // subvar namaMemo bertipe char dengan length 30
    char isiMemo[300]; // subvar isiMemo bertipe char dengan length 300
    char password[50]; // subvar password bertipe char dengan length 50
    time_t tanggal; // subvar tanggal
    address_memo next; //pointer ke memo berikutnya
    address_memo prev; //pointer ke memo sebelumnya

    Memo() : id_memo(0), namaMemo(""), isiMemo(""), password(""), tanggal(0) {}
    // inisiasi Memo yang memiliki nilai default dengan string kosong

} ElmtList;

int countDataMemo(); //menghitung jumlah data memo yang terdapat dalam file
int readRecords(const char* filename, address_memo& awal, address_memo& akhir);

#include "231511072.cpp"

#endif // MEMO_READER_H

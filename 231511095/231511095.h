#ifndef MEMO_H
#define MEMO_H

#include <string>
#include <ctime>
// #include "../231511089/231511089.h"
#include "../231511072/231511072.h"

using namespace std;

// deklarasi Struct Memo yang berisi subvar namaMemo, isiMemo, password
// typedef struct Memo *address_memo;
// typedef struct Memo {
//     int id_memo;
//     char namaMemo[30]; // subvar namaMemo bertipe char dengan length 30
//     char isiMemo[300]; // subvar isiMemo bertipe char dengan length 300
//     char password[50]; // subvar password bertipe char dengan length 50
//     time_t tanggal; // subvar tanggal
//     address_memo next;
//     address_memo prev;

//     Memo() : namaMemo(""), isiMemo(""), password(""), tanggal(0) {}
//     // inisiasi Memo yang memiliki nilai default dengan string kosong

// } ElmtList;

void tambahMemo(const Memo& memo); // deklarasi modul tambahMemo
void inputMemo(); // deklarasi modul inputMemo
void saveRecords(const char* filename, address_memo awal);

#include "231511095.cpp"

#endif // MEMO_H
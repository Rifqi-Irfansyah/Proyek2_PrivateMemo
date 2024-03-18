#ifndef MEMO_H
#define MEMO_H

#include <string>
#include <ctime>
using namespace std;

// deklarasi Struct Memo yang berisi subvar namaMemo, isiMemo, password
struct Memo {
    char namaMemo[30]; // subvar namaMemo bertipe char dengan length 30
    char isiMemo[300]; // subvar isiMemo bertipe char dengan length 300
    char password[50]; // subvar password bertipe char dengan length 50
    time_t tanggal; // subvar tanggal

    Memo() : namaMemo(""), isiMemo(""), password(""), tanggal(0) {}
    // inisiasi Memo yang memiliki nilai default dengan string kosong

};

void tambahMemo(const Memo& memo); // deklarasi modul tambahMemo
void inputMemo(); // deklarasi modul inputMemo

#endif // MEMO_H
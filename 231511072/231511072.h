#ifndef MEMO_READER_H
#define MEMO_READER_H

#include <string>
#include <ctime>
using namespace std;

struct Memo2 
{
    char namaMemo[30]; //array karakter dengan panjang 30 yang digunakan untuk menyimpan nama memo
    char isiMemo[300]; //array karakter dengan panjang 300 yang digunakan untuk menyimpan isi memo
    char password[50]; //array karakter dengan panjang 50 yang digunakan untuk menyimpan password
    time_t tanggal; //variabel bertipe time_t untuk menyimpan tanggal dibuatnya memo

    Memo2() : namaMemo(""), isiMemo(""), password(""), tanggal(0) {} 
};

Memo2* readMemoFile(); //membaca data memo dari sebuah file dan mengembalikan pointer ke array Memo2
int countDataMemo(); //menghitung jumlah data memo yang terdapat dalam file

#endif // MEMO_READER_H

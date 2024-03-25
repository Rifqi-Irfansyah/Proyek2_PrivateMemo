#ifndef MEMO_READER_H
#define MEMO_READER_H

#include <string>
#include <ctime>
using namespace std;

struct Memo2 
{
    char namaMemo[30]; 
    char isiMemo[300]; 
    char password[50]; 
    time_t tanggal; 

    Memo2() : namaMemo(""), isiMemo(""), password(""), tanggal(0) {} 
};

Memo2* readMemoFile(); //membaca data memo dari sebuah file dan mengembalikan pointer ke array Memo2
int countDataMemo(); //menghitung jumlah data memo yang terdapat dalam file

#endif // MEMO_READER_H

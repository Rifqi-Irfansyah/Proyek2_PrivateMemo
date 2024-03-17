#ifndef MEMO_READER_H
#define MEMO_READER_H

#include <string>
using namespace std;

struct Memo2 {
    char namaMemo[30];
    char isiMemo[300];
    char password[50];
    time_t tanggal;

    Memo2() : namaMemo(""), isiMemo(""), password(""), tanggal(0) {}
};

Memo2* readMemoFile();
int countDataMemo();

#endif // MEMO_READER_H

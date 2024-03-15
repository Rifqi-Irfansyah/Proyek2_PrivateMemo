#ifndef MEMO_READER_H
#define MEMO_READER_H

#include <string>
using namespace std;

struct Memo {
    char namaMemo[30];
    char isiMemo[300];
    time_t tanggal;

    Memo() : namaMemo(""), isiMemo(""), tanggal(0) {}
};

Memo* readMemoFile();
int countDataMemo();

#endif // MEMO_READER_H

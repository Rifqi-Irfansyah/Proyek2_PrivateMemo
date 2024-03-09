#ifndef MEMO_READER_H
#define MEMO_READER_H

#include <string>
using namespace std;

struct Memo {
    string namaMemo;
    string tanggal;
    string isiMemo;
};

void readMemoFile(const char* filename, Memo& memo);

#endif // MEMO_READER_H

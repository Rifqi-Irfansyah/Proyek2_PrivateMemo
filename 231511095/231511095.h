#ifndef MEMO_H
#define MEMO_H

#include <string>
using namespace std;

struct Memo {
    string namaMemo;
    string tanggal;
    string password;
    string isiMemo;
};

void tambahMemo(const Memo& memo, const string& namaFile);

#endif // MEMO_H

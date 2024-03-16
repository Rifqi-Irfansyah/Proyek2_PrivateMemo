#ifndef MEMO_H
#define MEMO_H

#include <string>
#include <ctime>
using namespace std;

struct Memo {
    char namaMemo[30];
    char isiMemo[300];
    time_t tanggal;

    // Memo() : namaMemo(""), isiMemo(""), tanggal(0) {}
    // Memo(const string& t, const string& c, time_t d) : namaMemo(t), isiMemo(c), tanggal(d) {}
};
void tambahMemo(const Memo& memo);
void inputMemo();
// Memo readMemoFile();
// bool authenticate(const string& password);

#endif // MEMO_H
#ifndef MEMO_H
#define MEMO_H

#include <string>
#include <ctime>
// #include "../231511089/231511089.h"
#include "../231511072/231511072.h"

using namespace std;

void tambahMemo(const Memo& memo); // deklarasi modul tambahMemo
void inputMemo(); // deklarasi modul inputMemo
bool saveRecords(const char* filename, address_memo awal);

#include "231511095.cpp"

#endif // MEMO_H
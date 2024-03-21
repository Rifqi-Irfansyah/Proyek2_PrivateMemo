#ifndef FILE_231511089_H
#define FILE_231511089_H

#include <ctime>
#include "../231511072/231511072.h"

extern int numMemo ;
extern Memo2* readMemo;

void listMemo();
bool cekPassword(string pw);
void hapusFile();
void bukaMemo(int pilih_memo, const Memo2* memo);


#endif

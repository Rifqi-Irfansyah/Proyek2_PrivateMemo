#ifndef FILE_231511089_H
#define FILE_231511089_H

#include "../231511072/231511072.h"
#include "../231511068/231511068.h"
#include "../231511095/231511095.h"
#include <ctime>
#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;
struct Memo;

void listMemo();
bool cekPassword(address_memo node);
void hapusFile();
void showNode(address_memo awal);

address_memo searchingNode(address_memo awal, int nilai);
bool removeNodeFirst(address_memo &awal);
bool removeNodeLast(address_memo &akhir);
bool removeNodeAnywhere(address_memo &awal, address_memo &akhir, address_memo &node);
bool removeNode(address_memo node);

#include "231511089.cpp"


#endif

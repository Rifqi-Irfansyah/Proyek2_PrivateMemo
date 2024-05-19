#ifndef HEADER_231511073_H
#define HEADER_231511073_H

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
int prima(long int);
void ce();
char* encrypt(const char plainText[], int &key);

#define MAX_SIZE 50

#include "../231511068/231511068.h" // buat manggil key random
#include "231511073.cpp"


#endif

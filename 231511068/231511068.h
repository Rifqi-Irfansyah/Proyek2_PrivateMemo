#ifndef HEADER_231511068_H
#define HEADER_231511068_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 50
using namespace std;
// Function prototypes
int proses_random(int random);
int key_dinamis(int key, int random);
long int cd(long int x);
char* encrypt(const char plainText[], int key);
char* decrypt(const char cipherText[], int key);
#include "231511068.cpp"
#endif

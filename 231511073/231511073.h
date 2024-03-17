#ifndef HEADER_231511073_H
#define HEADER_231511073_H

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
int prima(long int);
void ce();
string encrypt(char msg[50]);

#define MAX_SIZE 50

long int p; 
long int q;
long int n;
long int t;
long int flag;
long int key[MAX_SIZE][20];
long int temp[MAX_SIZE];
long int m[MAX_SIZE];
long int enkripsi[MAX_SIZE];
char msg[MAX_SIZE];


#endif

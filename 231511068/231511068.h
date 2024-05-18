#ifndef HEADER_231511068_H
#define HEADER_231511068_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "231511068.cpp"
// #include "test.cpp"
// #include "Random_key.cpp"

#define MAX_SIZE 50
using namespace std;
typedef struct node *adden;
typedef struct node
{
    char text;
    adden next;
}ode;

struct Node {
    char data;
    Node* next;
};
// Function prototypes
int proses_random(int random);
/*Pada Modul ini nilai random yang dibuat akan diolah dengan nomber yang tidak diketahui*/
int key_dinamis(int key, int random);
/*Pada modul ini proses key yang sudah diinput akan diolah dengan variabel random*/
int RSA_n(long int key,long int random);;
// char* encrypt(const char plainText[], int key);
char* decrypt(const char cipherText[], int key);
#endif

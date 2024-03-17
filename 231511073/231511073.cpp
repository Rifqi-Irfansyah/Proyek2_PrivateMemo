#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

#define MAX_SIZE 20

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

int prima(long int);
void ce();
void encrypt();

int prima(long int pr) {
    int i;
    long int j = sqrt(pr);
    for (i = 2; i <= j; i = i + 1) {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

int main() {

    p = 89;
    flag = prima(p);

    q = 97;
    flag = prima(q);

    cout << "\n\nMasukan Password : ";
    fflush(stdin);
    cin.getline(msg, MAX_SIZE);

    for (int i = 0; msg[i] != '\0'; i = i +1)
        m[i] = msg[i];
    
    n = p * q;
    t = (p - 1) * (q - 1);
    ce();
    encrypt();

    cout << "\n\n";
    return 0;
}

void ce() {
    int k = 0, j = 0;
    for (int i = 2; i < t; i++) {
        if (t % i == 0)
            continue;
        flag = prima(i);
        if (flag == 1 && i != p && i != q) {
            key[k][0] = i;
            if (flag > 0) {
                key[k][1] = flag;
                k++;
            }
            if (k == MAX_SIZE)
                break;
        }
    }
}

void encrypt() {
    long int pt, ct, len;
    len = strlen(msg);
    for (int i = 0; i < len; i++) {
        pt = m[i];
        pt = pt - 96;
        long int k = 1;
        for (int j = 0; j < key[0][0]; j++) {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        enkripsi[i] = ct;
    }
    enkripsi[len] = -1;
    cout << "\nPassword Enkripsi\n";
    for (int i = 0; enkripsi[i] != -1; i++)
        printf("%c", enkripsi[i]);
    cout << "\n";
}

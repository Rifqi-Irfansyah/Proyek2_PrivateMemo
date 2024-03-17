#include "231511068.h"

long int n, t, key[MAX_SIZE][1000], temp[MAX_SIZE], m[MAX_SIZE], enkripsi[MAX_SIZE];
long int cd(long int);
void dekripsi(long int enkripsi[MAX_SIZE]);

long int OPD(long int x) {
    long int k = 1;
    while (1) {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

void dekripsi(long int enkripsi[MAX_SIZE]) {
    long int pt, kalt;
    int i = 0;
    while (enkripsi[i] != -1) {
        kalt = temp[i];
        long int k = 1;
        for (int j = 0; j < key[0][1]; j++) {
            k = k * kalt;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    std :: cout << "\nPassword Dekripsi\n";
    for (int i = 0; m[i] != -1; i++)
        printf("%c", m[i]);
    std :: cout << "\n\n";
}

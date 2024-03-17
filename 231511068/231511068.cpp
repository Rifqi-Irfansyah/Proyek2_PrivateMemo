#include "231511068.h"

#define MAX_SIZE 1000

long int p, q, n, t, flag, key[MAX_SIZE][1000], temp[MAX_SIZE], m[MAX_SIZE], enkripsi[MAX_SIZE];
char msg[MAX_SIZE];

int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();

int prime(long int pr) {
    int i;
    long int j = sqrt(pr);
    for (i = 2; i <= j; i++) {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    // std :: cout << "\n\nMasukan Bilangan Prima Pertama (Di Atas 1) : ";
    // std :: cin >> p;
    p = 89; //bilangan prima ke 1
    flag = prime(p);
    // if (flag == 0) {
    //     std :: cout << "\nPenginputan Salah, Coba Lagi\n";
    //     exit(1);
    // }

    // std :: cout << "\nMasukan Bilangan Prima Kedua (Di Atas 1) : ";
    // std :: cin >> q;
    q = 97; //bilangan prima ke 2
    flag = prime(q);
    // if (flag == 0 || p == q) {
    //     std :: cout << "\n\nPenginputan Salah, Coba Lagi\n\n";
    //     exit(1);
    // }

    std :: cout << "\n\nMasukan Password\n";
    fflush(stdin);
    std :: cin.getline(msg, MAX_SIZE);
    // std :: cin >> msg;

    for (int i = 0; msg[i] != '\0'; i++)
        m[i] = msg[i];
    
    n = p * q;
    t = (p - 1) * (q - 1);
    ce();
    encrypt();
    decrypt();

   std :: cout << "\n\n";
    return 0;
}

void ce() {
    int k = 0, j = 0; // Mendeklarasikan variabel j di sini
    for (int i = 2; i < t; i++) {
        if (t % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q) {
            key[k][0] = i;
            flag = cd(key[k][0]);
            if (flag > 0) {
                key[k][1] = flag;
                k++;
            }
            if (k == MAX_SIZE)
                break;
        }
    }
}

long int cd(long int x) {
    long int k = 1;
    while (1) {
        k = k + t;
        if (k % x == 0)
            return (k / x);
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
    std :: cout << "\nPassword Enkripsi\n";
    for (int i = 0; enkripsi[i] != -1; i++)
        printf("%c", enkripsi[i]);
    std :: cout << "\n";
}

void decrypt() {
    long int pt, ct;
    int i = 0;
    while (enkripsi[i] != -1) {
        ct = temp[i];
        long int k = 1;
        for (int j = 0; j < key[0][1]; j++) {
            k = k * ct;
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
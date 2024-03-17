#include "231511068.h"

long int n, t, key[MAX_SIZE][1000], temp[MAX_SIZE], m[MAX_SIZE], enkripsi[MAX_SIZE];
long int cd(long int);

long int OPD(long int x) {
    long int k = 1;
    while (1) {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

string dekripsi(char enkripsi[MAX_SIZE]) {
    long int pt, kalt;
    char hasil_dekripsi[MAX_SIZE];
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
    for (int i = 0; m[i] != -1; i++){
        hasil_dekripsi[i] = m[i];
    }
    return hasil_dekripsi;
}

int main(){
    char password[MAX_SIZE];
    string password_encrypt;
    cout << "\n\nMasukan Password : ";
    fflush(stdin);
    cin.getline(password, MAX_SIZE);

    password_encrypt = dekripsi(password);

    cout << "Hasil = " <<password_encrypt;
}
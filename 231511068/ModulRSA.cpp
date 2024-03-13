#include"231511068.h"

/*
P = Banyak  Bilangan [Harus prima saat diimput]
Q = Banyak Bilangan [Harus prima saat diimput]
N = P x Q
R = (P - 1)(Q -1)
E = 3,5,17,65537
D = E^-1 mod(r)
*/
void encrypt(long int pass[][100], int n, long int e, long int temp[][100], long int enkripsi[][100]) {
    long int pastukar, ct, kunci = e, k;
    int i = 0, j = 0;
    int panstring = strlen(password[0]); // Panjang string pada posisi pada array password[] merupakan posisi baris array
    while (i != panstring) {
        pastukar = password[i][j];
        pastukar = pastukar - 96;
        k = 1;
        for (j = 0; j < kunci; j++) {
            k = k * pastukar;
            k = k % n;
        }
        temp[i][j] = k;
        ct = k + 96;
        enkripsi[i][j] = ct;
        i++;
    }
    enkripsi[1][0]= -1;
    printf ("\n Password sudah dienkripsi");
//     for (i = 0; enkripsi[i][0] != -1; i++) // Menggunakan en[i][0] != -1 sebagai kondisi loop
//         printf("%c", enkripsi[i][0]);
}
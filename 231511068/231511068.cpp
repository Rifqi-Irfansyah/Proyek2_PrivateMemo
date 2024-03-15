#include "231511068.h"

typedef long int satuan;
typedef int loop;
typedef int array;
/*
P = Banyak  Bilangan [Harus prima saat diimput]
Q = Banyak Bilangan [Harus prima saat diimput]
N = P x Q
R = (P - 1)(Q -1)
E = 3,5,17,65537
D = E^-1 mod(r)

k = merupakan variabel temp atau variabel kosong yang tidak termasuk dalam global var 
digunakan untuk dapat meminimalisir terjadinya multipel pernytaan variabel

Peraturan Definisi
Array input itu Array [1][j]
*/

  satuan p, q, n, t, cek,x;
  loop i,j;
  array e[100], d[100], temp[100][100],pass[100][100], enkripsi[100][100];
  char password[100][100];

int cekprim( int prima) {
    int i;
    int j = sqrt(prima);
    for (i = 2; i <= j; i++) {
        if (prima % i == 0) {
            return 0;
        }
    }
    return 1;
}

int mengolahtdann(int p, int q) {
    n = p * q;
    t = (p - 1) * (q - 1);
    printf("Nilai t: %d\n", t);
    printf("Nilai n: %d\n", n);
    return 0; // Menambahkan nilai kembalian karena fungsi ini memiliki tipe int
}

void bagE (int t,int *e,int *d) 
{
    int k;
    k = 0;
    for (i = 2; i < t;i++)
    {
        if (t % i == 0) /*Task ini digunakan untuk melanjutkan loop dari yang diinginkan agar 0 tidak dimasukkan pada saat nanti operasi array*/ 
            continue;
        cek = cekprim(i);
        if (cek == 1 && i != p && i != q)
        {
            e[k]= i;
            cek = bagianD(e[k]);
            if (cek > 0)
            {
                d[k] = cek;
                k++;
            }
                if (k == 99)
                break;
        }
        
        cout << "____"<<k;
        cout << "----"<<cek;
    }
}

int bagianD(int t) // Membuat  modular D
{
    int k = 1;   
    while (1)
    {
        k = k + t;
        if (k % x == 0)
        {
            return (k/x);
        }
    }
}


void encrypt()
{
    int Op, ct, kunci = e[0], k,panjang;
    int i = 0, j = 0;
    panjang = strlen(password[0]); // Panjang string pada posisi pada array password[] merupakan posisi baris array
    while (i != panjang) 
    {
        Op = password[i][j];
        Op = Op - 96;
        k = 1;
        for (j = 0; j < kunci; j++) {
            k = k * Op;
            k = k % n;
        }
        temp[i][j] = k;
        ct = k + 96;
        enkripsi[i][j] = ct;
        i++;
    }
    enkripsi[1][0]= -1;
    printf ("\n Password sudah dienkripsi");
    for (i = 0; enkripsi[i][0] != -1; i++) // Menggunakan en[i][0] != -1 sebagai kondisi loop
        printf("%c", enkripsi[i][0]);
}
 
// void decrypt(int enkripsi[][100],int pass[][100])
// {
//     int pt, ct, key = d[0][0], k;
//     i = 0;
//     while (enkripsi[i][j] != -1)
//     {   
//         ct = temp[i][j];
//         k = 1;
//         for (j = 0; j < key; j++)
//         {
//             k = k * ct;
//             k = k % n;
//         }
//         pt = k + 96;
//         pass[i][j] = pt;
//         j++;
//         i++;
//     }
//     pass[i][j] = - 1;
//         for (i = 0; pass[i][0] != -1; i++) // Menggunakan en[i][0] != -1 sebagai kondisi loop
//         printf("%c", pass[i][0]);
// }

 int main ()
 {
    printf ("Angka dengan minimal diatas dari 2\n");
    printf ("Masukkan Angka Prima Pertama: ");
    scanf ("%ld",&p);
    cek = cekprim(p);
    if (cek == 0)
    {
        printf ("Input mengalami error// tidak prima");
        exit(1);
    }
    printf ("Angka dengan minimal diatas dari 1\n");
    printf ("Masukkan angka Prima kedua: ");
    scanf ("%ld",&q);
    cek = cekprim(q);
    if (cek == 0 || p == q)
    {
        printf ("Input mengalami error/ TIdak prima");
        exit (1);
    }
    printf ("Masukkan Password yang akan digunakan : \n");
    scanf("%s",password);
      for (i = 0; password[i][j] != '\0'; i++)
      {
        for (j = 0;  j <= i; j++)
        {
         pass[i][j] = password[i][j];
        }
      }
      mengolahtdann(p, q);
      bagE ( t, e, d);
      bagianD(t);
      encrypt();
}



#include "231511068.h"
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

  long int p, q, n, t, cekinputprima, e[100][100], d[100][100], temp[100][100], j, pass[100][100], enkripsi[100][100], i;
  char password[100][100];

  int cekprim (long int prima)
{
    int i;
    long int j = sqrt(prima);
    for (i = 2; i <= j; i++)
    {
        if (prima % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void bagE (long int cekinputprima)
{
    int k,l;
    k = 0;
    l = 0;
    for (i = 2; i < t;i++)
    {
        // if (t % i == 0) /*Task ini digunakan untuk melanjutkan loop dari yang diinginkan agar 0 tidak dimasukkan pada saat nanti operasi array*/ 
        // {
        //     continue;
        // }
        cekinputprima = cekprim(i);
        if (cekinputprima == 1 && i != p && i != q)
        {
            e[k][l] = i;
            cekinputprima = bagianD(enkripsi[k][l]);
            if (cekinputprima > 0)
            {
                d[k][l] = cekinputprima;
                k++;
            }
        }
        

    }
}

long int bagianD(long int x) // Membuat  modular D
{
    long int k = 1;   
    while (1)
    {
        k = k + t;
        if (k % x ==0)
        {
            return (k/x);
        }
    }
}


void encrypt(long int pass[][100])
{
    long int pastukar, ct, kunci = e[0][0], k,len;
    int i = 0, j = 0;
    int panstring = strlen(password[0]); // Panjang string pada posisi pada array password[] merupakan posisi baris array
    while (i != panstring) 
    {
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
 



//  int main ()
//  {
//     printf ("Angka dengan minimal diatas dari 2\n");
//     printf ("Masukkan Angka Prima Pertama: ");
//     scanf ("%ld",&p);
//     cekinputprima = cekprim(p);
//     if (cekinputprima == 0)
//     {
//         printf ("Input mengalami error// tidak prima");
//         exit(1);
//     }
//     printf ("Angka dengan minimal diatas dari 1\n");
//     printf ("Masukkan angka Prima kedua: ");
//     scanf ("%ld",&q);
//     cekinputprima = cekprim(q);
//     if (cekinputprima == 0 || p == q)
//     {
//         printf ("Input mengalami error/ TIdak prima");
//         exit (1);
//     }
//     printf ("Masukkan Password yang akan digunakan");
//     fflush(stdin);
//     scanf("%s",password);




// }



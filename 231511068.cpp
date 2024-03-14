#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
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
 int main ()
 {
    printf ("Angka dengan minimal diatas dari 2\n");
    printf ("Masukkan Angka Prima Pertama: ");
    scanf ("%ld",&p);
    cekinputprima = cekprim(p);
    if (cekinputprima == 0)
    {
        printf ("Input mengalami error// tidak prima");
        exit(1);
    }
    printf ("Angka dengan minimal diatas dari 1\n");
    printf ("Masukkan angka Prima kedua: ");
    scanf ("%ld",&q);
    cekinputprima = cekprim(q);
    if (cekinputprima == 0 || p == q)
    {
        printf ("Input mengalami error/ TIdak prima");
        exit (1);
    }
    printf ("Masukkan Password yang akan digunakan");
    fflush(stdin);
    scanf("%s",password);
    



}



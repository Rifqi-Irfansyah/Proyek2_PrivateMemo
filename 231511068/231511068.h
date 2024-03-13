#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



long int p, q, n, t, flag, e[100][100], d[100][100], temp[100][100], j, pass[100][100], enkripsi[100][100], i;
 char password[100][100];
 int prime(long int);
 long int cd(long int);
 int prime(long int pr)
 {
     int i;
     j = sqrt(pr);
     for (i = 2; i <= j; i++)
     {
         if (pr % i == 0)
             return 0;
     }
 }
 
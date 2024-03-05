#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

using l = long long int;
#define S 100

l p, q,     
  n,       
  t,       
  flag,  
  e[S], 
  d[S], 
  temp[S], m[S], en[S];

char msg[S];

bool cekPrima(l); 
void eksponen_publik();         
l eksponen_privat(l);          
void enkripsi();  
void dekripsi(); 

bool cekPrima(l var) 
{
	int i, j = sqrt(var);
	for (i = 2; i <= j; ++i)
	if (var % i == 0)
			return false;
	return true;
}

void eksponen_publik()
{
     int k = 0;
     for (int i = 2; i < t; i++)
     {
	 if (t % i == 0) continue;
	 flag = cekPrima(i);
	 if (flag == 1 && i != p && i != q)
	 {
	     e[k] = i;
	     flag = eksponen_privat(e[k]);
	     if (flag > 0)
	     {
		d[k] = flag;
		k++;
	     }
	     if (k == 99) // (S-1)
	     break;
	 }
     }
}

l eksponen_privat(l x) 
{
     long int k = 1;
     while (true)
     {
	 k += t;
	 if (k % x == 0) return (k / x);
     }
}

void enkripsi()
{
	l pt, ct, key = e[0], k, len;
	int i = 0;
	len = std::strlen(msg);
	while (i != len)
	{
		pt = m[i];
		pt = pt - 96;
		k = 1;
		for (int j = 0; j < key; j++)
		{
			k *= pt;
			k %= n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}
	en[i] = -1;
	std::cout << "\nPesan Terenkripsi:\n";
	for (i = 0; en[i] != -1; i++)
		printf("%c", en[i]);
}

void dekripsi() 
{
	l pt, ct, key = d[0], k;
	int i = 0;
	while (en[i] != -1)
	{
		ct = temp[i];
		k = 1;
		for (int j = 0; j < key; j++)
		{
			k *= ct;
			k %= n;
		}
		pt = k + 96;
		m[i] = pt;
		i++;
	}
	m[i] = -1;
	std::cout << "\nPesan Terdekripsi:\n";
	for (int i = 0; m[i] != -1; i++)
		printf("%c", m[i]);
	
}

int main()
{   
    do 
    {
	   std::cout << "Masukkan dua bilangan prima (p,q untuk Euler's totient diambil sebagai (p-1)(q-1)):\n";
	   std::cin >> p >> q;
	   if(cekPrima(p) && cekPrima(q)) break;
	   else std::cout << "Input salah; Silakan masukkan bilangan prima.\n";
    } while(1);    

	std::cout << "Masukkan pesan untuk dienkripsi:\n";
	std::cin >> msg;
	for (int i = 0; msg[i] != '\0'; i++)
		m[i] = msg[i];
		
	n = p * q;
	t = (p - 1) * (q - 1);
	eksponen_publik();
	enkripsi();
	dekripsi();
	return 0;
}

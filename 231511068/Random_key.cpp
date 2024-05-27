#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;


int key_dinamis(int key) {
    cout << "Enter key: ";
    cin >> key;
    if (key >= 999999999)
    {
        cout << "Input gagal";
        exit(1);
    }
    time_t now = time(0);
    tm* wks = localtime(&now);
    time_t current_time;
    srand((unsigned)time(NULL));
    for (int i = 1; i <= 10; i++) {
        int random = 1 + (rand() % 27);
        return random;
        key = random - (key + wks->tm_mday);
        if (key < 0) 
        {
            key = abs(key);
            cout << "Kondisi key setelah tidak negatif = " << key << endl;
        }
        cout << key << endl;
    }

    if (key >= 26)
        {   
            cout << "N" << endl;
            int tampan = 1 + (rand() % 100);
            while (key > 26 || key < -26)
            {
                key = key - tampan;
            }
            cout << "Kondisi key = "  << key <<endl; 
            if (key < 0) 
            {
                key = abs(key);
                cout << "Kondisi key setelah tidak negatif = " << key << endl;
            }
        }
        
     if (key < 0) {
        key = abs(key);
        cout << "Kondisi key setelah tidak negatif = " << key << endl;
    }
    return key;
}


//  const int MAX_ROWS = 10;
//  const int MAX_COLS = 100;

// char* encrypt(const char plainText[], int key) {
//     char* encryptedText = new char[MAX_ROWS * MAX_COLS];
//     int len = strlen(plainText);

//     for (int i = 0; i < len; i++) {
//         if (isalpha(plainText[i])) {
//             char base = islower(plainText[i]) ? 'a' : 'A';
//             encryptedText[i] = (plainText[i] - base + key) % 26 + base;
//         } else {
//             encryptedText[i] = plainText[i];
//         }
//     }
//     encryptedText[len] = '\0';

//     return encryptedText;
// }


const int MAX_ROWS = 10;
const int MAX_COLS = 100;

char* decrypt(const char cipherText[], int key) {
    char* decryptedText = new char[MAX_ROWS * MAX_COLS];
    int len = strlen(cipherText);

    for (int i = 0; i < len; i++) {
        if (isalpha(cipherText[i])) {
            char base = islower(cipherText[i]) ? 'a' : 'A'; // ini merupakan operasi tenary dimana operasi ini seperti boolean namun lebih singkat dengan 
            /* ketentuan (condition) ? value_if_true : value_if_false sehingga dalam baris ini menjelaskan bahwa ketika operasi true maka  nilai kecil akan
            dimasukkan pada base */ 
            decryptedText[i] = (cipherText[i] - base - key + 26) % 26 + base;
        } else {
            decryptedText[i] = cipherText[i];
        }
    }
    decryptedText[len] = '\0'; // Add null terminator

    return decryptedText;
}

long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
n = p * q;
t = (p - 1) * (q - 1);
int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}
void ce()
{
    int k;
    k = 0;
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q)
        {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}
long int cd(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
}
}

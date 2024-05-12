#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

long int cd();

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

long int cd(long int x)
{
    int t;
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
}
}

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

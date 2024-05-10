#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX_ROWS = 10;
const int MAX_COLS = 100;
// Deklarasi fungsi
int key_dinamis(int key);
long int cd(long int x);
char* encrypt(const char plainText[], int key);
char* decrypt(const char cipherText[], int key);

int main() {
    int choice;
    int key = 10; // Key default
    int UI;
    do {
        cout << "\n=== Main Menu ===" << endl;
        cout << "1. Set Key" << endl;
        cout << "2. Encrypt Text" << endl;
        cout << "3. Decrypt Text" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                //  system("cls");
                key = key_dinamis(key);
                break;
            }
            case 2: {
                // system("cls");
                char plainText[100];
                cout << "Enter text to encrypt: ";
                cin.ignore(); // Clear input buffer
                cin.getline(plainText, 100);
                cout << "Encrypted Text: " << encrypt(plainText, key) << endl;
                break;
            }
            case 3: {
                //  system("cls");
                char cipherText[100];
                cout << "Enter text to decrypt: ";
                cin.ignore(); // Clear input buffer
                // alqan = kvakx
                // test 2 (alqan = qbgqd)  
                // test 3 (alqan = ufkuh)
                // test 4 (alqan = pafpc)
                // test 5 (alqan = mxcmz)
                // test 6 ( = hsxhu)
                cin.getline(cipherText, 100);
                cout << "Decrypted Text: " << decrypt(cipherText, key) << endl;
                break;
            }
            case 4: {
                cout << "Exiting program..." << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);

    return 0;
}

// int main() {
//     int choice;
//     int key = 10; // Key default
//     int UI;
//     do {
//         cout << "\n=== Main Menu ===" << endl;
//         cout << "1. Set Key" << endl;
//         cout << "2. Encrypt Text" << endl;
//         cout << "3. Decrypt Text" << endl;
//         cout << "4. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1: {
//                  system("cls");
//                 key = key_dinamis(key);
//                 UI = key;
//                 break;
//             }
//             case 2: {
//                 system("cls");
//                 char plainText[100];
//                 cout << "Enter text to encrypt: ";
//                 cin.ignore(); // Clear input buffer
//                 cin.getline(plainText, 100);
//                 cout << "Encrypted Text: " << encrypt(plainText, UI) << endl;
//                 break;
//             }
//             case 3: {
//                  system("cls");
//                 char cipherText[100];
//                 cout << "Enter text to decrypt: ";
//                 cin.ignore(); // Clear input buffer
//                 // alqan = kvakx
//                 // test 2 (alqan = cnscp)  
//                 cin.getline(cipherText, 100);
//                 cout << "Decrypted Text: " << decrypt(cipherText, UI) << endl;
//                 break;
//             }
//             case 4: {
//                 cout << "Exiting program..." << endl;
//                 break;
//             }
//             default:
//                 cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
//         }

//     } while (choice != 4);

//     return 0;
// }


// Implementasi fungsi-fungsi yang diperlukan

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

long int cd(long int x) {
    int t;
    long int k = 1;
    while (1) {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

char* encrypt(const char plainText[], int key) {
    char* encryptedText = new char[MAX_ROWS * MAX_COLS];
    int len = strlen(plainText);
    cout << key << endl;
    for (int i = 0; i < len; i++) {
        if (isalpha(plainText[i])) {
            char base = islower(plainText[i]) ? 'a' : 'A';
            encryptedText[i] = (plainText[i] - base + key) % 26 + base;
        } else {
            encryptedText[i] = plainText[i];
        }
    }
    encryptedText[len] = '\0';

    return encryptedText;
}

char* decrypt(const char cipherText[], int key) {
    char* decryptedText = new char[MAX_ROWS * MAX_COLS];
    int len = strlen(cipherText);

    for (int i = 0; i < len; i++) {
        if (isalpha(cipherText[i])) {
            char base = islower(cipherText[i]) ? 'a' : 'A';
            decryptedText[i] = (cipherText[i] - base - key + 26) % 26 + base;
        } else {
            decryptedText[i] = cipherText[i];
        }
    }
    decryptedText[len] = '\0'; // Add null terminator

    return decryptedText;
}

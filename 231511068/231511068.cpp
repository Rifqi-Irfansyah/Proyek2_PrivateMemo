#include <iostream>
#include <cstring>

const int MAX_ROWS = 10;
const int MAX_COLS = 100;

char* decrypt(const char cipherText[], int key) {
    char* decryptedText = new char[MAX_ROWS * MAX_COLS];
    int len = strlen(cipherText);
    
    for (int i = 0; i < len; i++) {
        char base; // Deklarasi base di dalam loop
        if (isupper(cipherText[i])) {
            base = 'A';
        } else if (islower(cipherText[i])) {
            base = 'a';
        } else {
            base = cipherText[i]; // Menyimpan karakter non-alfabet
        }
        decryptedText[i] = (cipherText[i] - base - key + 26) % 26 + base;
    }

    decryptedText[len] = '\0'; // Add null terminator

    return decryptedText;
}

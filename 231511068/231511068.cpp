#include <iostream>
#include <cstring>

const int MAX_ROWS = 10;
const int MAX_COLS = 100;

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
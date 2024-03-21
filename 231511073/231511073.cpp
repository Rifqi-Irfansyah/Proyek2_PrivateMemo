#include <iostream>
#include <cstring>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 100;

char* encrypt(const char plainText[], int key) {
    char* encryptedText = new char[MAX_ROWS * MAX_COLS];
    int len = strlen(plainText);

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

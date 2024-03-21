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

int main() {
    const int MAX_INPUT = 1000;
    char input[MAX_INPUT];
    int key = 7;

    cout << "Masukan Pesan Yang Akan Di Enkripsi : ";
    cin.getline(input, MAX_INPUT);

    char* encryptedText = encrypt(input, key);
    cout << "Pesan Yang Terenkripsi : " << encryptedText << endl;

    delete[] encryptedText;

    return 0;
}

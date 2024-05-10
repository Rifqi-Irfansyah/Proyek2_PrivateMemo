#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int key = 10;

long int cd();

int main()
{
    
    time_t now = time(0);
    tm* wks = localtime(&now);
    int hasil;
    int key = 10;
    time_t current_time;
	srand((unsigned)time(NULL));
    for (int i = 1; i<=7;i++)
    {
    int random = 1 + (rand() % 101);
    key = random - (key + wks->tm_mday);
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

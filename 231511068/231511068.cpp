#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cmath>
using namespace std;

const int MAX_COLS = 100;

int proses_random(int random)
{
    time_t now = time(0);
    tm* wks = localtime(&now);
    time_t current_time;
    srand((unsigned)time(NULL));
        for (int i = 1; i <= wks->tm_mday; i++) 
    {
        random = 1 + (rand() % 1001);
        // Menambahkan Operasi tambahan dalam loop ini

        // cout <<"Jumlah Loop- "<< i <<"dengan hasil random = " <<random << endl;     
    }
    cout << random << endl;
    return random;
}


int key_dinamis(int key,int random) {
    // cout << "Enter key: ";
    // cin >> key;
    if (key >= 999999999)
    {
        cout << "Input gagal";
        exit(1);
    }
    time_t now = time(0);
    tm* wks = localtime(&now);
    time_t current_time;
    srand((unsigned)time(NULL));
    for (int i = 0; i <= wks->tm_mon; i++) {
        key = wks->tm_yday - (key + random);
        // cout << "Kondisi random " << random << endl;
        if (key < 0) 
        {
            key = abs(key);
            // cout << "Kondisi key setelah tidak negatif = " << key << endl;
        }
        cout << key << endl;
    }
    if (key >= 26)
        {   
            // cout << "N" << endl;
            int tampan = 1 + (rand() % 100);
            while (key > 26 || key < -26)
            {
                key = key - tampan;
            }
            cout << "Kondisi key = "  << key <<endl; 
            if (key < 0) 
            {
                key = abs(key);
                // cout << "Kondisi key setelah tidak negatif = " << key << endl;
            }
        }
        
     if (key < 0) {
        key = abs(key);
        cout << "Kondisi key setelah tidak negatif = " << key << endl;
    }

    // if (key == nilai ganjil)
    // {
    //     operasi konversi key menjadi angka baru
    // }
    // else
    // {

    // }
    return key;
}

int RSA_n(int key, int random) {
    cout << "l" << endl;
    long int p, q, n, t, flag, j, i;
    int k = 0;
    n = key * random;
    t = (key - 1) * (random - 1);
    if (random >= 26) {
        cout << "1" << endl;
        int tampan = 1 + (rand() % 100);
        while (random > 26 || random < -26) {
            random = random - tampan;
        }
        if (random < 0) {
            random = abs(random);
        }
    }
    for (i = 2; i < t; i++) {
        cout << "2" << endl;
        if (t % i == 0) continue;
        flag = prime(i);
        cout << "i =" << i <<  endl;
        cout << "flag sebelum (if flag == 1) =" << flag <<  endl;
        if (flag == 1 && i != p && i != q) {
            key = i;
            cout << "3" << endl;
            cout << "flag saat (if flag == 1) =" << flag <<  endl;
            cout << "Key dalam proses =" << key <<  endl;
            while (key <= 26) {
                cout << "4" << endl;
                k = k + t;
                if (k % key == 0)
                    key = k / flag;
            cout << "proses Key =" << key <<  endl;
            }
            if (key == 26)
                cout << "5" << endl;
                break;
        }
    }
        if (key >= 26)
        {   
            // cout << "N" << endl;
            int tampan = 1 + (rand() % 100);
            while (key > 26 || key < -26)
            {
                key = key - tampan;
            }
            cout << "Kondisi key = "  << key <<endl; 
            if (key < 0) 
            {
                key = abs(key);
                // cout << "Kondisi key setelah tidak negatif = " << key << endl;
            }
        }
    return key;
}

int prime(long int pr) {
    int i, j;
    j = sqrt(pr);
    for (i = 2; i <= j; i++) {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}



struct Node {
    char data;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan elemen ke antrian
void enqueue(Node*& front, Node*& rear, char value) {
    Node* newNode = createNode(value);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Fungsi untuk menghapus elemen dari antrian
char dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {
        cerr << "Queue is empty" << endl;
        return '\0';
    }
    Node* temp = front;
    char value = front->data;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return value;
}

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty(Node* front) {
    return front == nullptr;
}

// Fungsi enkripsi menggunakan antrian
char* encrypt(const char plainText[], int key) {
    Node* front = nullptr;
    Node* rear = nullptr;

    int len = strlen(plainText);
    char* encryptedText = new char[len + 1]; // +1 untuk null terminator

    for (int i = 0; i < len; i++) {
        if (isalpha(plainText[i])) {
            char base = islower(plainText[i]) ? 'a' : 'A';
            char encryptedChar = (plainText[i] - base + key) % 26 + base;
            enqueue(front, rear, encryptedChar);
        } else {
            enqueue(front, rear, plainText[i]);
        }
    }

    int index = 0;
    while (!isEmpty(front)) {
        encryptedText[index++] = dequeue(front, rear);
    }
    encryptedText[index] = '\0';

    return encryptedText;
}

// Fungsi dekripsi menggunakan antrian
char* decrypt(const char cipherText[], int key) {
    Node* front = nullptr;
    Node* rear = nullptr;

    int len = strlen(cipherText);
    char* decryptedText = new char[len + 1]; // +1 untuk null terminator

    for (int i = 0; i < len; i++) {
        if (isalpha(cipherText[i])) {
            char base = islower(cipherText[i]) ? 'a' : 'A';
            char decryptedChar = (cipherText[i] - base - key + 26) % 26 + base;
            enqueue(front, rear, decryptedChar);
        } else {
            enqueue(front, rear, cipherText[i]);
        }
    }

    int index = 0;
    while (!isEmpty(front)) {
        decryptedText[index++] = dequeue(front, rear);
    }
    decryptedText[index] = '\0';

    return decryptedText;
}

int main() {
    char plainText[MAX_COLS];
    int key;
    int random = 1;
    int pil;

    do
    {
        cout << "\n=== Main menu===" << endl;
        cout << "key = " << key << endl;
        cout << "1. Menentukan KEY" << endl;
        cout << "2. Encrypt text dan decrpt" << endl;
        cout << "3. Exit" << endl;
        cout <<"Masukkan pilihan = ";
        cin >> pil;
    
    switch (pil)
    {
        case 1:
        {
            cout << "Masukkan Key = ";
            cin >> key;
            random = proses_random(random);
            key = key_dinamis(key,random);
        };
        case 2:
        {
             char plainText[100];
             
                cout << "Enter text to encrypt: ";
                cin.ignore(); // Clear input buffer
                cin.getline(plainText, 100);
                char* encryptedText = encrypt(plainText, key);
                cout << "Encrypted Text: " << encrypt(plainText, key) << endl;
                char* decryptedText = decrypt(encryptedText, key);
                cout << "Teks Yang Sudah Di Dekrip: " << decryptedText << endl;
                break; 
        }
        case 3:
        {
            cout << "Keluar dari program";
            break;
        }
    }
    } while (pil != 3);






    // proses_random(random);
    // cout << "Masukkan teks yang ingin dienkripsi: ";
    // cin.getline(plainText, MAX_COLS);

    // cout << "Masukkan kunci enkripsi: ";
    // cin >> key;
    // key_dinamis(key,random);
    // cout << "P = " << key << endl;
    // char* encryptedText = encrypt(plainText, key);
    // cout << "Teks Yang Sudah Di Enkrip: " << encryptedText << endl;

    
    // char* decryptedText = decrypt(encryptedText, key);
    // cout << "Teks Yang Sudah Di Dekrip: " << decryptedText << endl;

    // delete[] encryptedText;
    // delete[] decryptedText;

    return 0;
}

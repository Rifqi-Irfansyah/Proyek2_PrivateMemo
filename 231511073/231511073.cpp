#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_COLS = 100;


struct Node {
    char data;
    Node* next;
};


class Queue {
    private:
        Node* front;
        Node* rear;
    public:
        Queue() : front(nullptr), rear(nullptr) {}
        ~Queue() {
            while (!isEmpty()) {
                dequeue();
            }
        }

        bool isEmpty() {
            return front == nullptr;
        }

        void enqueue(char value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = nullptr;

            if (isEmpty()) {
                front = newNode;
            } else {
                rear->next = newNode;
            }
            rear = newNode;
        }

        char dequeue() {
            if (isEmpty()) {
                cerr << "Queue Kosong" << endl;
                return '\0';
            }

            Node* temp = front;
            char value = front->data;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
            return value;
        }
};


char* encrypt(const char plainText[], int key) {
    Queue queue;

    int len = strlen(plainText);
    char* encryptedText = new char[len + 1]; // +1 untuk null terminator

    for (int i = 0; i < len; i++) {
        if (isalpha(plainText[i])) {
            char base = islower(plainText[i]) ? 'a' : 'A';
            char encryptedChar = (plainText[i] - base + key) % 26 + base;
            queue.enqueue(encryptedChar);
        } else {
            queue.enqueue(plainText[i]);
        }
    }

    int index = 0;
    while (!queue.isEmpty()) {
        encryptedText[index++] = queue.dequeue();
    }
    encryptedText[index] = '\0';

    return encryptedText;
}

int main() {
    char plainText[MAX_COLS];
    int key;

    cout << "Masukan Nama : ";
    cin.getline(plainText, MAX_COLS);

    cout << "Masukan Usia : ";
    cin >> key;

    char* encryptedText = encrypt(plainText, key);
    cout << "\nTeks Ter-enkrip: " << encryptedText << endl;

    delete[] encryptedText;

    return 0;
}

// #include <iostream>
// #include <cstring>

// using namespace std;

// const int MAX_ROWS = 10;
// const int MAX_COLS = 100;

// char* encrypt(const char plainText[], int key) {
    // char* encryptedText = new char[MAX_ROWS * MAX_COLS];
    // int len = strlen(plainText);

    // for (int i = 0; i < len; i++) {
        // if (isalpha(plainText[i])) {
            // char base = islower(plainText[i]) ? 'a' : 'A';
            // encryptedText[i] = (plainText[i] - base + key) % 26 + base;
        // } else {
            // encryptedText[i] = plainText[i];
        // }
    // }
    // encryptedText[len] = '\0';

    // return encryptedText;
// }

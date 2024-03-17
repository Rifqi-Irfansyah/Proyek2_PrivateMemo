#include"231511073.h"

long int p; 
long int q;
long int n;
long int t;
long int flag;
long int key[MAX_SIZE][20];
long int temp[MAX_SIZE];
long int m[MAX_SIZE];
long int enkripsi[MAX_SIZE];
char msg[MAX_SIZE];

int prima(long int pr) {
    int i;
    long int j = sqrt(pr);
    for (i = 2; i <= j; i = i + 1) {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

// int main() {
//     char password[MAX_SIZE];
//     string password_encrypt;
//     cout << "\n\nMasukan Password : ";
//     fflush(stdin);
//     cin.getline(password, MAX_SIZE);

//     password_encrypt = encrypt(password);

//     cout << password_encrypt;
    
// }

void ce() {
    int k = 0, j = 0;
    for (int i = 2; i < t; i++) {
        if (t % i == 0)
            continue;
        flag = prima(i);
        if (flag == 1 && i != p && i != q) {
            key[k][0] = i;
            if (flag > 0) {
                key[k][1] = flag;
                k++;
            }
            if (k == MAX_SIZE)
                break;
        }
    }
}

string encrypt(const string& msg) {
    char password_encrypt[50] = "";
    p = 89;
    flag = prima(p);

    q = 97;
    flag = prima(q);

    for (int i = 0; msg[i] != '\0'; i = i +1)
        m[i] = msg[i];
    
    n = p * q;
    t = (p - 1) * (q - 1);
    
    ce();

    long int pt, ct, len;
    len = msg.size(); 
    for (int i = 0; i < len; i++) {
        pt = m[i];
        pt = pt - 96;
        long int k = 1;
        for (int j = 0; j < key[0][0]; j++) {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        enkripsi[i] = ct;
    }
    enkripsi[len] = -1;
    for (int i = 0; enkripsi[i] != -1; i++){
        password_encrypt[i] = enkripsi[i];
    }
    string pass_string(password_encrypt);
    return pass_string;
}

#include"231511073.h"


int prima(long int pr) {
    int i;
    long int j = sqrt(pr);
    for (i = 2; i <= j; i = i + 1) {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

// int main-nya dipindahin ke bawah

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

// char- nya di tambahin 50

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
    return password_encrypt;
}

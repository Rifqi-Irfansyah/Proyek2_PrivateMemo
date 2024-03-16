#include <iostream>
#include "231511072/231511072.h"
#include "231511095/231511095.h"
#include "231511089/231511089.h"
using namespace std;

void menuBeranda();

int main(){
    int pilih;
    do {
        menuBeranda();
        system("cls");
        cout << "1. = Ya,\n0. = Keluar \nKembali ke Menu Utama?: ";
        cin >> pilih;
        system("cls"); // Hapus layar console setelah kembali ke menu utama
    } while (pilih == 1);

    return 0;
}

void menuBeranda(){
    int pilih;
    cout << "===========================================\n";
    cout << "\tAplikasi Private Memo\n";
    cout << "===========================================\n";
    cout << "1. Buat Memo Baru\n";
    cout << "2. Lihat List Memo\n";
    cout << "0. Keluar\n";
    cout << "-------------------------------------------\n";
    cout << "Silahkan Pilih = ";
    cin >> pilih;
    switch(pilih){
        case 1:
            system("cls");
            inputMemo();
            break;
        case 2:
            system("cls");
            listMemo();
            break;
        default:
            break;
    }
}
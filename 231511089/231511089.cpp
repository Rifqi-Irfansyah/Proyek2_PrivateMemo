#include "../231511072/231511072.h"
#include "231511089.h"
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;


// int main() {
//     listMemo();
// }
int numMemo;
Memo2* readMemo;

void hapusFile() {
    std::remove("file_memo.txt");
}

void listMemo(){
    // Panggil fungsi readMemoFile untuk mendapatkan data Memo
    int pilih_memo;
    numMemo = countDataMemo() ;
    Memo2* readMemo = readMemoFile();

    if (readMemo != nullptr) {
        cout << "==========================================================\n";
        cout << "\t\tDaftar Nama Memo Saat Ini\n";
        cout << "==========================================================\n";

        for (int i=0; i < numMemo; i++) {
            cout << i+1 << ". Nama   : " << readMemo[i].namaMemo << endl;
            cout << "   Dibuat : " << ctime(&readMemo[i].tanggal) << endl;
        }
        cout << "----------------------------------------------------------\n";
        cout << "Silahkan Pilih Memo Yang akan dibaca \033[3matau kembali : '0'\033[0m  = ";
        cin >> pilih_memo;
        if (pilih_memo == 0){
            system("cls");
        }
        else{
            bukaMemo(pilih_memo, readMemo);
        }
    } else {
        cerr << "Gagal membaca data Memo" << endl;
    }

    delete[] readMemo;
}

void bukaMemo(int pilih_memo, const Memo2* readMemo){
    char kembali;

    if ((pilih_memo > 0) && (pilih_memo <= numMemo)){
        ofstream myfile;
        myfile.open("file_memo.txt");
        myfile<<"-------------------------------------------"<<endl;
        myfile<<"Nama Memo\t: "<<readMemo[pilih_memo - 1].namaMemo <<endl;
        myfile<<"Tanggal Dibuat\t: "<<ctime(&readMemo[pilih_memo - 1].tanggal) <<endl;
        // myfile<<"Password\t: "<<readMemo[pilih_memo - 1].password <<endl;
        myfile<<"-------------------------------------------"<<endl;
        myfile<<readMemo[pilih_memo - 1].isiMemo<<endl;
        system("start notepad file_memo.txt");
        atexit(hapusFile);
    }
    else{
        cout << "Maaf tidak ada data memo " << pilih_memo <<endl;

    }

    cout << "Kembali (y)? ";
    cin >> kembali;
    if (kembali == 'y'){
        system("cls");
        listMemo();
    }
    else{
        system("exit");
    }
}





// string dekripsi(string cipher_text){
//     string plain_text;

//     return plain_text;
// }

// void cekPassword(int pilih_memo, string pw){
//     string password;
//     char ulangi_pw;
//     char kembali;

//     do(){
//         system("cls");  //clear console
//         ulangi_pw = 'n';

//         cout << "Masukkan password Memo = ";
//         cin >> password;

//         if (password == pw){
//             cout << "Password Sesuai" <<endl;
//             validasi = true;
//         }
//         else{
//             cout << "Password Salah, Ulangi(y/n)? ";
//             cin >> ulangi_pw;
//             validasi = false;
//         }
//     }while (ulangi_pw == "y");

//     system("cls");
//     return validasi;
// }
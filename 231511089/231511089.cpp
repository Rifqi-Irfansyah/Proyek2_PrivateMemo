#include <iostream>
#include <ctime>
#include <fstream>
#include "../231511072/231511072.h"
using namespace std;

string dekripsi(string cipher_text);
void listMemo();
void cekPassword(int pilih_memo, string pw);
void hapusFile();
void bukaMemo(int pilih_memo);


Memo* readMemo = readMemoFile();
int numMemo = countDataMemo();

int main() {
    listMemo();


    // pw_plainText = dekripsi(memo[pilih_memo].pw); //dekripsi file (function yg nilai kembaliannya pw plain text)
    // validasi = cekPassword(pilih_memo, pw_plainText);

    // if (validasi == true){
    //     bukaMemo(pilih_memo);
    // }
    // else{
    //     cout << "Kembali (y)? ";
    //     cin >> kembali;
    //     if (kembali == 'y'){
    //         void listMemo(struct memo);
    //     }
    // }
}


void listMemo(){
    // Panggil fungsi readMemoFile untuk mendapatkan data Memo
    int pilih_memo;
    int i = 0;

    if (readMemo != nullptr) {
        cout << "==========================================================\n";
        cout << "\t\tDaftar Nama Memo Saat Ini\n";
        cout << "==========================================================\n";

        for (i; i < numMemo; i++) {
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
            bukaMemo(pilih_memo);
        }
    } else {
        cerr << "Gagal membaca data Memo" << endl;
    }

    delete[] readMemo;
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

void hapusFile() {
    // Kode untuk menghapus file di sini
    std::remove("file_memo.txt");
}

void bukaMemo(int pilih_memo){
    char kembali;

    if ((pilih_memo < 1) || (pilih_memo > numMemo)){
            cout << "Maaf tidak ada data memo " << pilih_memo <<endl;
    }
    else{
        ofstream myfile;
        myfile.open("file_memo.txt");
        myfile<<"-------------------------------------------"<<endl;
        myfile<<"Nama Memo\t: "<<readMemo[pilih_memo - 1].namaMemo <<endl;
        myfile<<"Tanggal Dibuat\t: "<<ctime(&readMemo[pilih_memo - 1].tanggal) <<endl;
        myfile<<"-------------------------------------------"<<endl;
        myfile<<readMemo[pilih_memo - 1].isiMemo<<endl;
        system("start notepad file_memo.txt");

        atexit(hapusFile);

    }

    cout << "Kembali (y)? ";
    cin >> kembali;
    if (kembali == 'y'){
        system("cls");
        listMemo();
    }
}
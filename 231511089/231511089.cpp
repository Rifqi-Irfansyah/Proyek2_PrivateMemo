#include <iostream>
using namespace std;

void listMemo(struct memo)
string dekripsi(string cipher_text)
void cekPassword(int pilih_memo, string pw);

void listMemo(struct memo) {
    int pilih_memo;
    bool validasi = false;


    cout << "List Memo yang Tersimpan:"<<endl;
    for (int i=1; i<=){
        cout << "Memo ke-" << i <<endl;
        cout << "Judul Memo  = ";
        cin >> memo[i].nama <<endl<<endl;
    }
    cout << "Pilih memo yg ingin dibuka = ";
    cin >> pilih_memo;

    pw_plainText = dekripsi(memo[pilih_memo].pw); //dekripsi file (function yg nilai kembaliannya pw plain text)
    validasi = cekPassword(pilih_memo, pw_plainText);

    if (validasi == true){
        bukaMemo(pilih_memo);
    }
    else{
        cout << "Kembali (y)? ";
        if (kembali == 'y'){
            void listMemo(struct memo);
        }
    }
}

string dekripsi(string cipher_text){
    string plain_text;

    return plain_text;
}

void cekPassword(int pilih_memo, string pw){
    string password;
    char ulangi_pw;
    char kembali;

    do(){
        system("cls");  //clear console
        ulangi_pw = 'n';

        cout << "Masukkan password Memo = ";
        cin >> password;

        if (password == pw){
            cout << "Password Sesuai" <<endl;
            validasi = true;
        }
        else{
            cout << "Password Salah, Ulangi(y/n)? ";
            cin >> ulangi_pw;
            validasi = false;
        }
    }while (ulangi_pw == "y");

    system("cls");
    return validasi;
}

void bukaMemo(int pilih_memo){
    ofstream myfile;
    myfile.open("file_memo.txt");
    myfile<<"-------------------------------------------"<<endl;
    myfile<<"Nama Memo\t: "<<nama<<endl;
    myfile<<"-------------------------------------------"<<endl;
    system("start notepad file_memo.txt");

	cout << "Kembali (y)? ";
    if (kembali == 'y'){
        void listMemo(struct memo);
    }
	atexit(hapusFile);
}
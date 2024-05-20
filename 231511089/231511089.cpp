#include "231511089.h"
#include "../231511095/231511095.h"
#include "../231511072/231511072.h"

void hapusFile() {
    remove("file_memo.txt");
}

void listMemo(){
    address_memo awal, akhir, hasil_search;
    int pilih_memo, pilih_aksi, readData;
    bool cekpw, cekSave;

    do{
        system("cls");
        readData = readRecords("memo_coba.dat", awal, akhir);

        cout << "==========================================================\n";
        cout << "\t\tDaftar Nama Memo Saat Ini\n";
        cout << "==========================================================\n";

        if (readData == 0){
            cout << "\n\t !! Saat ini tidak ada data Memo !! ";
            cout << "\n\n\t Tekan Enter Untuk Kembali Ke Beranda";
            cin.ignore();
            cin.get();
            pilih_memo = 0;
        }
        else{
            showNode(awal);
            cout << "----------------------------------------------------------\n";
            cout << "Silahkan Pilih Memo \033[3m atau kembali : '0'\033[0m  = ";
            cin >> pilih_memo;

            if (pilih_memo != 0){
                hasil_search = searchingNode(awal, pilih_memo);
                if(hasil_search == NULL){
                    cout << "\n Maaf ID Memo tidak ada\n";
                    system("pause");
                }
                else{
                    cout << "\n 1. Buka Memo\n";
                    cout << " 2. Edit Memo\n";
                    cout << " 3. Hapus Memo\n";
                    cout << " Pilih Aksi Pada Memo ' " << hasil_search->namaMemo <<" ' = ";
                    cin >> pilih_aksi;

                    switch(pilih_aksi){
                        case 1:
                            cekpw = cekPassword(hasil_search);
                            if (cekpw == 1){
                                ofstream myfile;
                                myfile.open("file_memo.txt");
                                myfile<<"-------------------------------------------"<<endl;
                                myfile<<" Nama Memo\t: "<< hasil_search->namaMemo <<endl;
                                myfile<<" Tanggal Dibuat\t: "<<ctime(& hasil_search->tanggal);
                                myfile<<"-------------------------------------------"<<endl;
                                myfile<< hasil_search->isiMemo<<endl;

                                system("start notepad file_memo.txt");
                                atexit(hapusFile);
                            }
                            else{
                                cout << "\n !! Password Salah, Gagal Membuka Memo !! \n";
                                system("pause");
                            }
                            break;
                        
                        case 2:
                            cout << "";
                            break;

                        case 3:
                            cekpw = cekPassword(hasil_search);
                            if (cekpw){
                                removeNodeAnywhere(awal, akhir, hasil_search);
                                cekSave = saveRecords("memo_coba.dat", awal);
                                if(cekSave){
                                    cout << "\n Penghapusan Berhasil\n";
                                }
                                else{
                                    cout << "\n !! Error Sistem, Gagal Menghapus Memo !!\n";
                                }
                            }
                            else{
                                cout << "\n !! Password Salah, Gagal Menghapus Memo !!\n";
                            }
                            system("pause");
                            break;

                        default:
                            break;
                    }
                }
            }
        }

    }while(pilih_memo != 0);
}

bool cekPassword(address_memo node){
    char pw_encrypt[50];
    string password;
    char ulangi_pw;
    bool password_true;
    
    strcpy(pw_encrypt, node->password);
    string pw_decrypt = decrypt(pw_encrypt, node->key);

    do{
        system("cls");
        ulangi_pw = 'n';

        cout << "Masukkan password Memo '" << node->namaMemo << "' = ";
        cin >> password;

        if (password == pw_decrypt){
            password_true = true;
        }
        else{
            cout << "Password Salah, Ulangi(y/n)? ";
            cin >> ulangi_pw;
            password_true = false;
        }
    }while (ulangi_pw == 'y');

    system("cls");
    return password_true;
}

void showNode(address_memo awal){
    if (awal == NULL){
        printf ("\n\t\t !! List node kosong !!");
    }
    else{
        address_memo node = awal;
        while (node != NULL) {
            cout << "Id Memo   = " << node -> id_memo <<endl;
            cout << "Nama Memo = " << node -> namaMemo <<endl;
            cout << "Tgl Memo  = " << ctime( &node -> tanggal) <<endl<<endl;
            node = node->next;
        }
    }
    
}

bool removeNodeFirst(address_memo &awal){
    if (awal == NULL){
        return false;
    }
    else{
        address_memo temp = awal;
        awal = awal -> next;
        removeNode(temp);
        return true;
    }
}

bool removeNodeLast(address_memo &akhir){
    if (akhir == NULL){
        return false;
    }
    else{
        address_memo temp = akhir;
        akhir = akhir -> prev;
        akhir -> next = nullptr;
        removeNode(temp);
        return true;
    }
}

void removeNodeAnywhere(address_memo &awal, address_memo &akhir, address_memo &node){
    if (node == awal){
        removeNodeFirst(awal);
    }
    else if (node == akhir){
        removeNodeLast(akhir);
    }
    else{
        address_memo temp;
        temp = node->prev;
        temp -> next = node->next;
        removeNode(node);
    }
}

void removeNode(address_memo node){
    if(node != NULL){
        node = NULL;
    }
    free(node);
}

address_memo searchingNode(address_memo awal, int nilai){
    address_memo result = NULL;
    if (awal != NULL){
        address_memo node = awal;

        while (node != NULL){
            if (node -> id_memo == nilai){
                result = node;
                break;
            }
            node = node -> next;
        }
    }
    return result;
}
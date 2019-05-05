#include <iostream>
#include "meonk.h"
#include "welcome.h"
#include "menu.h"

using namespace std;

// Membuat Address & List Pada Program

listHooman L_H;
listKuchink L_K;

addressHooman adrHooman;
addressKuchink adrKuchink;

int state = 0;

void init () {
    CreateListHooman(L_H);
    CreateListKuchink(L_K);
}

// Membuat Sebuah Relasi Saling Terhubung

void Relasi(string Hooman, string Kuchink) {
    addressHooman H = getHooman(L_H, Hooman);
    addressKuchink K = getKuchink(L_K, Kuchink);

    //Kalo Ada
    if (H != NULL && K != NULL) {
        if (getKuchink(info(H).Kuchinks, Kuchink) == NULL) {
            InsertLastKuchink(info(H).Kuchinks, AlokasiKuchink(Kuchink));
            info(H).numberOfKuchinks++;
            sortHooman(L_H);
        } else // Kalo Udah Ada
            cout << "Kuchink sudah ada";

        //Kalo Belom ada
        if (getHooman(info(K).Kuchink, Hooman) == NULL) {
            InsertLastHooman(info(K).Kuchink, AlokasiHooman(Hooman));
            info(K).numberofKuchink++;
            sortKuchink(L_K);
        } else // Kalo Udah Ada
            cout << "Hooman Sudah Ada";
    } else {
        cout << "data Hooman atau Kuchink tidak ada";
    }

}

// Membuat Sebuah Relasi Tidak Terhubung

void TidakRelasi(string Hooman, string Kuchink) {
    addressHooman H = getHooman(L_H, Hooman);
    addressKuchink K = getKuchink(L_K, Kuchink);

    //Kalo Ada
    if (H != NULL && K != NULL) {
        if (getKuchink(info(H).Kuchinks, Kuchink) != NULL) {
            DeleteKuchink(info(H).Kuchinks, getKuchink(info(H).Kuchinks, Kuchink));
            info(H).numberOfKuchinks--;
        } else //Kalo Udah Ada
            cout << "data tidak ada";

        //Kalo Belom Ada
        if (getHooman(info(K).Kuchink, Hooman) != NULL) {
            DeleteHooman(info(K).Kuchink, getHooman(info(K).Kuchink, Hooman));
            info(K).numberofKuchink--;
        } else
            cout << "data tidak ada";
    } else {
        cout << "data Hooman atau Kuchink tidak ada";
    }

}

// Main Program

int main () {
    cout<<""<<endl;
    welcomeIndo(); // Manggil si WelcomeIndo yang ada di welcome.cpp sebelumnya via welcome.h dulu
    init(); //manggil list hooman dan kuchink

    //Membuat sebuah String untuk menu yang berisikan 7 String
    string menu[7] = {
            "Menu Hooman",
            "Menu Kuchink",
            "Tampilkan semua Data Kuchink dan Hooman",
            "Pencarian Data Hooman tertentu dan Kuchink-nya",
            "Menampilkan Semua Kuchink dan Yang Berelasi",
            "Tunjukkan Kuchink tertentu dan Berelasi",
            "Keluar dari Aplikasi"
    };
    cout << "Pilih Menu yang ingin anda Panggil :\n\n";
    state = pilihanMenu(menu, 7); // ini yang 4 harus sesuai kalo menunya ada 7 berati di state harus / sampe 7

    //Perulangan pada menu
    while (state != -1) {
        cout<<""<<endl;
        if (state == 0){
            cout << "Pilih Menu yang ingin anda pilih :\n\n";
            state = pilihanMenu(menu, 7); // ini yang 7 harus sesuai kalo menunya ada 7 berati di state harus / sampe 7
        }else
        if (state == 1) { // State 1 yaitu Menu ke 1 (Menu Hooman)
            cout<<""<<endl;
            string submenu[3] = {
                    "Tambah Data",
                    "Hapus Data",
                    "Kembali"
            };
            int substate = pilihanMenu(submenu, 3); // ini yang 3 harus sesuai kalo menunya ada 3 berati di state harus / sampe 3
            cout<<""<<endl;

            //Isi Dari Menu Ke 1
            while(substate != -1) {
                if (substate == 0) {
                    substate = pilihanMenu(submenu, 3); // ini yang 3 harus sesuai kalo menunya ada 3 berati di state harus / sampe 3
                }
                if (substate == 1) {
                    InsertLastHooman(L_H, AlokasiHooman(getString("Masukan Data Hooman Baru : ")));
                    substate = 0;
                } else
                if (substate == 2) {
                    string data = getString("Masukan Data Hooman yang akan dihapus : ");
                    DeleteHooman(L_H, getHooman(L_H, data)); // Hapus Data Hooman (Delete Last)
                    addressKuchink P = first (L_K);
                    while (P != NULL) {
                        DeleteHooman(info(P).Kuchink, getHooman(info(P).Kuchink, data)); // Hapus Data Hooman (Delete Last)
                        P = next(P);
                    }
                    substate = 0;
                } else if (substate == 3) {
                    substate = -1;
                } else substate = 0;
            }

            state = 0;
        } else
        if (state == 2) { // State 2 yaitu Menu ke 2 (Menu Kuchink)
            cout<<""<<endl;
            string submenu[5] = { //Membuat sebuah String untuk menu yang berisikan 5 String
                    "Tambah Data",
                    "Relasi Kuchink",
                    "Tidak Relasi Kuchink",
                    "Hapus Data",
                    "Kembali"
            };
            int substate = pilihanMenu(submenu, 5); // ini yang 5 harus sesuai kalo menunya ada 5 berati di state harus / sampe 5
            cout<<""<<endl;

            // Isi Dari Menu Kuchink
            while(substate != -1) {
                cout<<""<<endl;
                if (substate == 0) {
                    substate = pilihanMenu(submenu, 5); // ini yang 5 harus sesuai kalo menunya ada 5 berati di state harus / sampe 5
                }
                if (substate == 1) {
                    InsertFirstKuchink(L_K, AlokasiKuchink(getString("Masukan data kuchink baru : ")));
                    substate = 0;
                } else
                if (substate == 2) {
                    Relasi(getString("masukan data hooman : "), getString("Masukan data kuchink baru : "));
                    Continue(); // Memasukan fungsi untuk melanjutkan
                    substate = 0;
                } else
                if (substate == 3) {
                    TidakRelasi(getString("masukan data hooman : "), getString("Masukan data kuchink baru : "));
                    Continue(); // Memasukan fungsi untuk melanjutkan
                    substate = 0;
                } else
                if (substate == 4) {
                    string data = getString("masukan data kuchink yang akan dihapus : ");
                    DeleteKuchink(L_K, getKuchink(L_K, data)); // Menghapus Data Kuchink (Delete Last)
                    addressHooman P = first (L_H);
                    while (P != NULL) {
                        DeleteKuchink(info(P).Kuchinks, getKuchink(info(P).Kuchinks, data)); // Menghapus Data Kuchink (Delete Last)
                        P = next(P);
                    }
                    substate = 0;
                } else if (substate == 5) { // ini yang 5 harus sesuai kalo menunya ada 5 berati di state harus / sampe 5
                    substate = -1;
                } else substate = 0;
            }

            state = 0;
        } else
        if (state == 3){ // View Hoooman
            addressHooman H = first (L_H);

            while (H != NULL){
                cout << "================================\n";
                cout << "Berikut adalah Data dari Hooman\n";
                cout << "================================\n";
                viewHooman (L_H, info(H).data); // Menampilkan Data Hooman
                cout << "========================";
                cout << '\n';
                H = next (H);
            }

            Continue(); // Memasukan fungsi untuk melanjutkan
            state = pilihanMenu(menu, 7);
        } else
        if (state == 4){
            viewHooman(L_H, getString("Masukan Data Hooman : ")); // input data hooman
            Continue(); // Memasukan fungsi untuk melanjutkan
            state = pilihanMenu(menu, 7);
        } else
        if (state == 5){
            addressKuchink K = first (L_K);

            while (K != nullptr){
                cout << "================================\n";
                cout << "Berikut adalah Data dari Kuchink\n";
                cout << "================================\n";
                viewKuchink (L_K, info(K).data); // Menampilkan Data Kuchink
                cout << "========================";
                cout << '\n';
                K = next (K);
            }
            Continue(); // Memasukan fungsi untuk melanjutkan
            state = pilihanMenu(menu, 7);
        } else
        if (state == 6){
            viewKuchink(L_K, getString("Masukan Data Kuchink: ")); // Input Data Kuchink
            Continue(); // Memasukan fungsi untuk melanjutkan
            state = pilihanMenu(menu, 7);

        } else
        if (state == 7){ // State 4 yaitu (Menu Keluar Aplikasi)
            state = -1;
            goodByeFromOtherSide();

            //Fixing Infinite Loop when Invalid Choice Menu by Hilman Abdan (github : @mystald)
        } else
        if (state > -1){
            state = -1;
            menuSalah();
        }
        cout<<""<<endl;

    }

    return 0;
}
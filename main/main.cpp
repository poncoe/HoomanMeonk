#include <iostream>
#include "meonk.h"

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

int main() {
    std::cout << "" << std::endl;
    init();

    return 0;
}
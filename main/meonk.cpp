#include "meonk.h"

// ========= HOOMAN ===========

// Mengalokasi Hooman

addressHooman AlokasiHooman(std::string data) {

    addressHooman P;
    P = new Hooman;

    listKuchink Kuchinks;
    CreateListKuchink(info (P).Kuchinks);

    info (P).data = data;
    info (P).numberOfKuchinks = 0;
    next (P) = NULL;
    prev (P) = NULL;

    return P;
}

// Membuat List Hooman

void CreateListHooman(listHooman &L) {
    first (L) = NULL;
    last (L) = NULL;
}

// Dealokasi Hooman

void DealokasiHooman(addressHooman P) {
    delete P;
    P = NULL;
}

// Membuat Address Nampilin Hooman

addressHooman TampilHooman(listHooman L, std::string nama) {

    addressHooman P = first (L);

    while (P != NULL ) {
        if (info(P).data == nama)
            return P;
        P = next (P);
    }
    return nullptr;
}

// Membuat Address Tambah Data Hooman (Insert First)

void InsertFirstHooman(listHooman &L, addressHooman H) {
    if (first (L) == NULL) {
        first (L) = H;
        last (L) = H;
    } else {
        next (H) = first (L);
        prev (first (L)) = H;
        first (L) = H;
    }
}

// ========= KUCHINK =========


// Membuat Alokasi pada Kuchink

addressKuchink AllocateKuchink(std::string data) {

    addressKuchink P;
    P = new Kuchink;

    listHooman Kuchink;
    CreateListHooman(info (P).Kuchink);

    info (P).data = data;
    info (P).numberofKuchink = 0;
    next (P) = NULL;
    prev (P) = NULL;
    return P;
}

// Dealokasi Kucink

void DealokasiKuchink(addressKuchink P) {
    delete P;
    P = NULL;
}

// Membuat List Kucink

void CreateListKuchink(listKuchink &L) {
    first (L) = NULL;
    last (L) = NULL;
}

// Nampilin Data Kucink

addressKuchink TampilKuchink(listKuchink L, std::string nama) {


    addressKuchink P = first (L);

    while (P != NULL ) {
        if (info(P).data == nama)
            return P;
        P = next (P);
    }
    return NULL;
}

// Membuat Address Input Data Kucink (Insert First)

void InsertFirstKuchink(listKuchink &L, addressKuchink K) {
    if (first (L) == NULL) {
        first (L) = K;
        last (L) = K;
    } else {
        next (K) = first (L);
        prev (first (L)) = K;
        first (L) = K;
    }
}
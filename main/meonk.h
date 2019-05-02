#ifndef HOOMANMEONK_MEONK_H
#define HOOMANMEONK_MEONK_H

#include <iostream>
#include <string>

// List Makro

#define first(L) (L).first
#define last(L)  (L).last
#define next(P)  (P)->next
#define prev(P)  (P)->prev
#define info(P)  (P)->info

// List Deklarasi

typedef struct Kuchink *addressKuchink;
typedef struct Hooman *addressHooman;

struct listKuchink {
    addressKuchink first;
    addressKuchink last;
};


struct listHooman {
    addressHooman first;
    addressHooman last;
};

// Struktur Data Hooman

struct infotypeHooman {
    std::string data;
    int numberOfKuchinks;

    // relasi kuchink didalam adt hooman
    listKuchink Kuchinks;
};

struct Hooman {
    infotypeHooman info;
    addressHooman next;
    addressHooman prev;
};

// Struktur Data Kuchink

struct infotypeKuchink {
    std::string data;
    int numberofKuchink;

    // relasi hooman didalam adt kuchink
    struct listHooman Kuchink;
};

struct Kuchink {
    infotypeKuchink info;
    addressKuchink next;
    addressKuchink prev;
};

// Hooman

addressHooman AlokasiHooman(std::string data);
addressHooman TampilHooman(listHooman L, std::string nama);
void CreateListHooman(listHooman &L);
void DealokasiHooman(addressHooman P);
void InserFirstHooman(listHooman &L, addressHooman H);
void InsertLastHooman(listHooman &L, addressHooman C);
void InsertAfterHooman(listHooman &L, addressHooman Prec, addressHooman C);

// Kuchink

addressKuchink AlokasiKuchink(std::string data);
addressKuchink TampilKuchink(listKuchink L, std::string nama);
void CreateListKuchink(listKuchink &L);
void DealokasiKuchink(addressKuchink P);
void InserFirstKuchink(listKuchink &L, addressKuchink K);
void InsertLastKuchink(listKuchink &L, addressKuchink F);
void InsertAfterKuchink(listKuchink &L, addressKuchink Prec, addressKuchink F);

#endif //HOOMANMEONK_MEONK_H

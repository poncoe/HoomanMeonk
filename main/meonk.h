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
    struct listHooman Kuchink;
};

struct Kuchink {
    infotypeKuchink info;
    addressKuchink next;
    addressKuchink prev;
};

// Hooman

addressHooman AlokasiHooman(std::string data);
addressHooman getHooman(listHooman L, std::string nama);
void CreateListHooman(listHooman &L);
void DealokasiHooman(addressHooman P);
void InserFirstHooman(listHooman &L, addressHooman H);
void InsertLastHooman(listHooman &L, addressHooman H);
void InsertAfterHooman(listHooman &L, addressHooman Prec, addressHooman H);
addressHooman DeleteFirstHooman(listHooman &L);
addressHooman DeleteLastHooman(listHooman &L);
addressHooman DeleteHooman(listHooman &L, addressHooman H);
void sortHooman(listHooman &L1);
void viewHooman(listHooman L, std::string nama);
void viewAllHooman(listHooman L);

// Kuchink

addressKuchink AlokasiKuchink(std::string data);
addressKuchink getKuchink(listKuchink L, std::string nama);
void CreateListKuchink(listKuchink &L);
void DealokasiKuchink(addressKuchink P);
void InserFirstKuchink(listKuchink &L, addressKuchink K);
void InsertLastKuchink(listKuchink &L, addressKuchink K);
void InsertAfterKuchink(listKuchink &L, addressKuchink Prec, addressKuchink K);
addressKuchink DeleteFirstKuchink(listKuchink &L);
addressKuchink DeleteLastKuchink(listKuchink &L);
addressKuchink DeleteKuchink(listKuchink &L, addressKuchink K);
void sortKuchink(listKuchink &L1);
void viewAllKuchink(listKuchink L);
void viewKuchink(listKuchink L, std::string nama);

#endif //HOOMANMEONK_MEONK_H

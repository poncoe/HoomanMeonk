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

#endif //HOOMANMEONK_MEONK_H
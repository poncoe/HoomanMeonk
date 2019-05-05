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

addressHooman getHooman(listHooman L, std::string nama) {

    addressHooman P = first (L);

    while (P != NULL ) {
        if (info(P).data == nama)
            return P;
        P = next (P);
    }
    return NULL;
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

// Membuat Address Tambah Data Hooman (Insert Last)

void InsertLastHooman(listHooman &L, addressHooman H) {
    if(getHooman(L, info(H).data) == NULL) {
        if(last(L) == NULL) {
            first(L) = H;
            last(L) = H;
        } else {
            prev(H) = last(L);
            next(last(L)) = H;
            last(L) = H;
        }
    }
    else {
        DealokasiHooman(H);
    }
}

// Membuat Address Tambah Data Hooman (Insert After)

void InsertAfterHooman(listHooman &L, addressHooman Prec, addressHooman H) {
    if (Prec != NULL)
        InsertLastHooman(L, H);
    else {
        next (H) = next (Prec);
        prev (H) = Prec;
        prev (next (Prec)) = H;
        next (Prec) = H;
    }
}

// Membuat Address Hapus Hooman (Delete First)

addressHooman DeleteFirstHooman(listHooman &L) {

    addressHooman P = first (L);

    if (P != NULL) {
        if (P == last (L)) {
            first (L) = NULL;
            last (L)  = NULL;
        } else {
            first (L) = next (first (L));
            next (P) = NULL;
            prev (first (L)) = NULL;
        }
    }

    return P;
}

// Membuat Address Hapus Hooman (Delete Last)

addressHooman DeleteLastHooman(listHooman &L) {

    addressHooman P = last (L);

    if (P != NULL) {
        if (P == first (L)) {
            first (L) = NULL;
            last (L)  = NULL;
        }
        else {
            last (L) = prev(P);
            prev (P) = NULL;
            next (last (L)) = NULL;
        }
    }

    return P;
}

// Membuat Address Hapus Hooman (Delete First & Delete Last)

addressHooman DeleteHooman(listHooman &L, addressHooman H) {

    addressHooman P = getHooman(L, info (H).data);

    if (P != NULL) {
        if (P == first (L)) {
            P = DeleteFirstHooman(L);
        } else if (P == last (L)) {
            P = DeleteLastHooman(L);
        } else {
            prev (next (P)) = prev (P);
            next (prev (P)) = next (P);
            next (P) = NULL;
            prev (P) = NULL;
        }
    }

    listKuchink Kuchink = info (H).Kuchinks;

    while (first (Kuchink) != NULL) {
        DeleteLastKuchink (Kuchink);
    }

    return P;

}

// Membuat Address Sort Data Hooman

void sortHooman(listHooman &L1) {

    listHooman L2;
    CreateListHooman(L2);

    while (first (L1) != nullptr) {

        addressHooman P = DeleteLastHooman(L1);

        if (first (L2) == nullptr)
            InsertFirstHooman(L2, P);
        else if (info (P).numberOfKuchinks <= info (first (L2)).numberOfKuchinks)
            InsertFirstHooman(L2, P);
        else if (info (P).numberOfKuchinks >= info (first (L2)).numberOfKuchinks)
            InsertLastHooman(L2, P);
        else {
            addressHooman Q = first (L2);
            while (info (next (Q)).numberOfKuchinks < info (P).numberOfKuchinks)
                Q = next (Q);
            InsertAfterHooman(L2, Q, P);
        }

    }

    L1 = L2;
}

// Membuat Address Menampilkan Semua Data Hooman

void viewAllHooman(listHooman L) {
    if (first (L) != NULL && last (L) != NULL) {
        addressHooman P = first(L);
        while (P != NULL) {
            std::cout << "  " << info(P).data << '\n';
            P = next (P);
        }
    } else {
        std::cout << "DATA KOSONG\n";
    }

}

// Membuat Address Lihat Data Hooman

void viewHooman(listHooman L, std::string nama) {
    if (first (L) != NULL && last (L) != NULL) {
        addressHooman P = getHooman(L, nama);
        if (P == NULL)
            std::cout << "Data Tidak Ada!";
        else {
            std::cout << "data Hooman       : " << info (P).data;
            std::cout << "\nJumlah Kuchink : " << info (P).numberOfKuchinks;
            std::cout << "\nNama Kuchink   : \n\n";
            viewAllKuchink(info (P).Kuchinks);
        }
    }
}

// ========= KUCHINK =========


// Membuat Alokasi pada Kuchink

addressKuchink AlokasiKuchink(std::string data) {

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

addressKuchink getKuchink(listKuchink L, std::string nama) {


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

// Membuat Address Input Data Kuchink (Insert Last)

void InsertLastKuchink(listKuchink &L, addressKuchink K) {
    if (getKuchink (L, info (K).data) == NULL) {
        if (last (L) == NULL) {
            first (L) = K;
            last (L) = K;
        } else {
            prev (K) = last (L);
            next (last (L)) = K;
            last (L) = K;
        }
    }
    else {
        DealokasiKuchink(K);
    }
}

// Membuat Address Input Data Kuchink (Insert After)

void InsertAfterKuchink(listKuchink &L, addressKuchink Prec, addressKuchink K) {
    if (Prec != NULL)
        InsertLastKuchink(L, K);
    else {
        next (K) = next (Prec);
        prev (K) = Prec;
        prev (next (Prec)) = K;
        next (Prec) = K;
    }
}

// Membuat Address Hapus Kuchink (Delete First)

addressKuchink DeleteFirstKuchink(listKuchink &L) {

    addressKuchink P = first (L);

    if (P != NULL) {
        if (P == last (L)) {
            last (L)  = NULL;
            first (L) = NULL;
        } else {
            first (L) = next (first (L));
            next (P) = NULL;
            prev (first (L)) = NULL;
        }
    }

    return P;
}

// Membuat Address Hapus Kuchink (Delete Last)

addressKuchink DeleteLastKuchink(listKuchink &L) {

    addressKuchink P = last (L);

    if (P != NULL) {
        if (P == first (L)) {
            last (L)  = NULL;
            first (L) = NULL;
        }
        else {
            last (L) = prev (P);
            prev (P) = NULL;
            next (last (L)) = NULL;
        }
    }

    return P;

}

// Membuat Address Hapus Kuchink (Delete First & Delete Last)

addressKuchink DeleteKuchink(listKuchink &L, addressKuchink K) {

    addressKuchink P = getKuchink(L, info (K).data);

    if (P != NULL) {
        if (P == first (L))
            P = DeleteFirstKuchink(L);
        else if (P == last (L))
            P = DeleteLastKuchink(L);
        else {
            prev (next (P)) = prev (P);
            next (prev (P)) = next (P);
            next (P) = NULL;
            prev (P) = NULL;
        }
    }

    listHooman Kuchink = info (K).Kuchink;

    while (first (Kuchink) != NULL) {
        DeleteLastHooman(Kuchink);
    }

    return P;
}

// Membuat Address Sort Data Kuchink

void sortKuchink(listKuchink &L1) {
    listKuchink L2;
    CreateListKuchink(L2);

    while (first (L1) != NULL) {

        addressKuchink P = DeleteLastKuchink(L1);

        if (first (L2) == NULL)
            InsertFirstKuchink(L2, P);
        else if (info (P).numberofKuchink <= info (first (L2)).numberofKuchink)
            InsertFirstKuchink(L2, P);
        else if (info (P).numberofKuchink >= info (first (L2)).numberofKuchink)
            InsertLastKuchink(L2, P);
        else {
            addressKuchink Q = first (L2);
            while (info (next (Q)).numberofKuchink < info (P).numberofKuchink)
                Q = next (Q);
            InsertAfterKuchink(L2, Q, P);
        }
    }

    L1 = L2;
}

// Menampilkan Semua Data Kuchink

void viewAllKuchink(listKuchink L) {
    if (first (L) != NULL && last (L) != NULL) {
        addressKuchink P = first(L);
        while (P != NULL) {
            std::cout << info(P).data << '\n';
            P = next (P);
        }
    } else {
        std::cout << "DATA KOSONG\n";
    }
}

// Menampilkan Data Kuchink

void viewKuchink(listKuchink L, std::string nama) {
    if (first (L) != NULL && last (L) != NULL) {
        addressKuchink P = getKuchink(L, nama);
        if (P == NULL)
            std::cout << "Data Tidak Ada"; // Kalo Datanya kaga ada

            // Kalo Datanya ada dia bakalan nampilin Kuchink
        else {
            std::cout << "Data    : " << info(P).data << '\n';
            std::cout << "Jumlah Hooman : " << info(P).numberofKuchink;
            std::cout << "\nHooman : \n\n";
            viewAllHooman(info (P).Kuchink);
        }
    }
}

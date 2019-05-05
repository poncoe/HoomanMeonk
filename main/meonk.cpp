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

void InsertLastHooman(listHooman &L, addressHooman C) {
    if(getHooman(L, info(C).data) == NULL) {
        if(last(L) == NULL) {
            first(L) = C;
            last(L) = C;
        } else {
            prev(C) = last(L);
            next(last(L)) = C;
            last(L) = C;
        }
    }
    else {
        DealokasiHooman(C);
    }
}

// Membuat Address Tambah Data Hooman (Insert After)

void InsertAfterHooman(listHooman &L, addressHooman Prec, addressHooman C) {
    if (Prec != NULL)
        InsertLastHooman(L, C);
    else {
        next (C) = next (Prec);
        prev (C) = Prec;
        prev (next (Prec)) = C;
        next (Prec) = C;
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

addressHooman DeleteHooman(listHooman &L, addressHooman C) {

    addressHooman P = getHooman(L, info (C).data);

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

    listKuchink Kuchink = info (C).Kuchinks;

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

void InsertLastKuchink(listKuchink &L, addressKuchink F) {
    if (getKuchink (L, info (F).data) == NULL) {
        if (last (L) == NULL) {
            first (L) = F;
            last (L) = F;
        } else {
            prev (F) = last (L);
            next (last (L)) = F;
            last (L) = F;
        }
    }
    else {
        DealokasiKuchink(F);
    }
}

// Membuat Address Input Data Kuchink (Insert After)

void InsertAfterKuchink(listKuchink &L, addressKuchink Prec, addressKuchink F) {
    if (Prec != NULL)
        InsertLastKuchink(L, F);
    else {
        next (F) = next (Prec);
        prev (F) = Prec;
        prev (next (Prec)) = F;
        next (Prec) = F;
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

addressKuchink DeleteNetizen(listKuchink &L, addressKuchink F) {

    addressKuchink P = getKuchink(L, info (F).data);

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

    listHooman Kuchink = info (F).Kuchink;

    while (first (Kuchink) != NULL) {
        DeleteLastHooman(Kuchink);
    }

    return P;
}

// Membuat Address Sort Data Kuchink

void sortKuchink(listKuchink &L1) {
    listKuchink L2;
    CreateListKuchink(L2);

    while (first (L1) != nullptr) {

        addressKuchink P = DeleteLastKuchink(L1);

        if (first (L2) == nullptr)
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

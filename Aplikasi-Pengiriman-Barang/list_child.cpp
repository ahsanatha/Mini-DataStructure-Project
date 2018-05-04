#include "list_child.h"
#include <stdio.h>
///bagian daniel peter smith
/// CSLL w/o Last.
/// ======================== inisialisasi |||
void createList(List_child &L) {
    first(L) = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    next(P) = P;
    info(P) = x;
    return P;
}

void dealokasi(address_child &P){
    delete P;
    P = NULL;
}

/// ===================== inserting  |||

void insertFirst(List_child &L, address_child P) {
    address_child Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q); }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}
void insertLast(List_child &L, address_child P){
    address_child Q;
    if(first(L)==NULL){
        first(L) = P;
        next(P) = P;
    } else
        Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
}


void insertAfter(List_child L, address_child Prec, address_child P) {
    if ((first(L) != NULL) && (Prec != NULL)) {
        if (next(Prec) == first(L)) {
            insertLast(L, P);
        }else {
            next(P) = next(Prec);
            next(Prec) = P;
    }
}
}

/// =============== some function.

int hitung(List_child L){
    address_child C; int cnt = 0;
    if (first(L) != NULL){
        C = first(L);
        while (next(C) != first(L)){
            cnt++;
            C = next(C);
        }
        cnt++;
    }
    return cnt;
}

void printInfo(List_child L) {
    if (first(L) != NULL){
    address_child P = first(L);
    while(next(P) != first(L)) {
        cout << " > ID : "<< info(P).ID << " | Nama Ekspedisi : "<< info(P).namaKr <<endl;
        cout <<" >> Kuota : "<<info(P).kuota << " | Harga per Kg :"<<info(P).hargaKg;
        cout << " | Harga per Km : "<<info(P).hargaKm << endl;
        cout << " >> Pendapatan : "<<info(P).pendapatan << " | rating : "<< info(P).bintang;
        cout << endl<< endl;
        P = next(P);
    }
        cout <<">>ID : "<< info(P).ID << " | Nama Ekspedisi : "<< info(P).namaKr <<endl;
        cout <<">>> Kuota : "<<info(P).kuota << " | Harga per Kg :"<<info(P).hargaKg;
        cout << " | Harga per Km : "<<info(P).hargaKm << endl;
        cout << ">>> Pendapatan : "<<info(P).pendapatan << " | rating : ";printf("%0.1f",info(P).bintang);cout<<endl;
        cout << endl<< endl;
    } else {
        cout << "    Tidak ada Kurir Terdaftar"<<endl;

    }

    cout << endl;
}


address_child findElm(List_child L, int x) {
    address_child P = first(L);
    while( next(P)!= first(L) ) {
        if(info(P).ID==x) {
            return P;
        }
        P = next(P);
    }
    if(info(P).ID==x) return P;
    else return NULL;
}



/// ==================== Deleting

void autoDelete(List_child &L, address_child P){
    address_child Prec, last;
    if (first(L) != NULL){
        last = first(L);
        while (next(last) != first(L)) last = next(last);
        if (P == first(L)) deleteFirst(L);
        else if (P == last) deleteLast(L);
        else {
            Prec = first(L);
            while (next(Prec) != P)
                Prec = next(Prec);
            if (Prec != NULL)
                deleteAfter(L,Prec);
        }
     cout <<info(Prec).namaKr<<endl;
    }else cout << "List Kosong";
}
void deleteFirst(List_child &L){
    address_child Q,P;
    if (first(L) != NULL) {
        P = first(L);
        if ((next(P) == first(L))) {
            next(P) = NULL;
            first(L) = NULL;
        } else {
            Q = first(L);
            while(next(Q) != first(L)) {
                Q = next(Q);
            } //{END WHILE}
            first(L) = next(P);
            next(Q) = next(P);
            next(P) = NULL;
            dealokasi(P);
        }
        //{END IF}
    }
    //{END IF
}
void deleteLast(List_child &L){
    address_child Q,P;
    if (first(L) != NULL){
        P = first(L);
        if (next(P) == first(L)) {
            next(P) = NULL;
            first(L) = NULL;
        } else
            Q = first(L);
            while (next(next(Q)) != first(L)) {
                Q = next(Q);
            }//{END WHILE}
            P = next(Q);
            next(Q) = next(P);
            next(P) = NULL;
    }
}
void deleteAfter(List_child &L, address_child Prec) {
    address_child P;
    if ((first(L) != NULL) && (Prec != NULL)) {
        if(next(Prec) != first(L)){
            P = next(Prec);
            next(Prec) =  next(P);
            next(P) = NULL;

    } else {
            deleteFirst(L);
    }
}
}

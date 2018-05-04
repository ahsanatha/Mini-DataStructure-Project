#include "list_relasi.h"
#include <iomanip>
#include <stdio.h>
///bagian Muhammad Ahsan Athallah
///DLL w/o Last.

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_parent P, address_child C, infotype_relasi data) {
    address_relasi Q = new elmlist_relasi;
    info(Q) = data;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}

void insertFirst(List_relasi &L, address_relasi P) {
    if (first(L) == NULL){
        first(L) = P;
    }else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}

void printInfo(List_relasi L) {
    if (first(L) == NULL){
        cout << endl<< "  Tidak ada pengiriman barang terdaftar. "<<endl;
    } else {
        address_relasi P = first(L);
        while(P !=NULL) {
            cout <<" --------------------------------------------------------------------- "<<endl;
            cout <<"ID : "<<info(P).ID<<" || Toko online ";
                if(parent(P) != NULL) cout << info(parent(P)).olshop;
                else cout << "????";
            cout << " menggunakan jasa ekpedisi ";
                if  (child(P) != NULL) cout << info(child(P)).namaKr<<endl;
                else cout << "????"<<endl;
            cout << " keterangan : "<<endl;
            cout << "   Nama Pengirim          : "<<info(P).namaCS<<endl;
            cout << "   Berat Barang           : "<<info(P).berat<<" Kg"<<endl;
            cout << "   Jarak Pengiriman       : "; printf("%0.2f Km ",info(P).jarak);cout <<endl;
            cout << "   Total Biaya Pengiriman : "<<"Rp. "<<info(P).total<<",-"<<endl;
            cout << "   Rating Ekspedisi       : "; printf("[%0.1f/10] Star",info(P).bintang);cout <<endl;
            cout <<" --------------------------------------------------------------------- "<<endl<<endl;
            P = next(P);
        }
    }
}

void dealokasi(address_relasi &P){
    delete P;
    P = NULL;
}

address_relasi findElm(List_relasi L,int id) {
    if (first(L) != NULL){
        address_relasi Q = first(L);
        while(Q != NULL) {
            if(info(Q).ID == id) {
                return Q;
            }
            Q = next(Q);
        }
        return NULL;
    }else{
        return NULL;
    }
}

int hitungRLS(List_relasi Hub, address_child pKR){
    if (first(Hub)== NULL){
        return 0;
    }else {
        int cnt = 1;
        address_relasi P = first(Hub);
        while(next(P) != NULL){
            cnt++;
            P = next(P);
        }
        return cnt;
    }

}

void autoDelete(List_relasi &L, address_relasi P){
    address_relasi Prec;
    if(first(L) != NULL && P != NULL){
        if (P == first(L) ){
            deleteFirst(L);
        }else if (P != NULL){
                Prec = prev(P);
                deleteAfter(L,Prec);
            }
        }
}

void deleteFirst(List_relasi &L){
    if (first(L) != NULL){
        address_relasi P;
        P = first(L);
        first(L) = next(P);
        dealokasi(P);
    }else {
        cout << "LIST SUDAH KOSONG"<<endl;
    }
}


void deleteAfter(List_relasi &L, address_relasi Prec){
    if (first(L) != NULL){
        address_relasi P = next(Prec);
        prev(P) = NULL;
        next(Prec) = NULL;
        dealokasi(P);
    }else {
        cout << "List sudah kosong."<< endl;
    }
}


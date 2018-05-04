#include "list_parent.h"
///Bagian Daniel Pitters Smith//
///SSL w/ Last.
///inisialisasi
void createList(List_parent &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_parent alokasiP(infotype_parent data){
    address_parent P = new elmlist_parent;
    info(P) = data;
    next(P) = NULL;
    return P;
}

void dealokasi(address_parent &P){
    delete P;
    P = NULL;
}
///end inisialisasi.


///Inserting.
void insertFirst(List_parent  &L, address_parent P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfter(List_parent &L, address_parent P, address_parent Prec){
    if(first(L) == NULL){
        insertFirst(L,P);
    }else{
        if(first(L) == Prec){
            insertFirst(L,P);
        }else if(next(Prec) == last(L)){
            insertLast(L,P);
        }else{
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }
}
void insertLast(List_parent &L, address_parent data){
    if (first(L) != NULL){
        address_parent P;
        P = first(L);
        while (next(P) != NULL){
            P = next(P);
        }
        next(P) = data;
        data = NULL;
        last(L) = next(P);
    }else{
        insertFirst(L,data);
    }
}
///end Inserting.

/// Delete-ing wkwk.

void autoDelete(List_parent &L, address_parent P){ ///masih error
    address_parent Prec;
    if (first(L) != NULL){
        if (P == first(L)) deleteFirst(L);
        else if (P == last(L)) deleteLast(L);
        else {
            Prec = first(L);
            while (next(Prec) != P && P != NULL) Prec = next(Prec);
            if (Prec != NULL) deleteAfter(L,Prec,P);
        }
    } else cout << "List Kosong";
}
void deleteFirst(List_parent &L){
    if (first(L) != NULL){
        address_parent P;
        P = first(L);
        first(L) = next(P);
        dealokasi(P);
    }else {
        cout << "LIST SUDAH KOSONG"<<endl;
    }
}
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){
    if(first(L) == NULL){
        cout<<"Kosong";
    }else{
        if(first(L) == P){
            deleteFirst(L);
        }else if(next(P) == NULL){
            deleteLast(L);
        }else{
            P = next(Prec);
            next(Prec) = next(P);
            next(P) = NULL;
        }
    }
}
void deleteLast(List_parent &L){
    if (first(L) != NULL){
        address_parent P;
        P = first(L);
        if (next(P) == NULL){
            deleteFirst(L);
        }else {
            address_parent Q;
            Q = P;
            P = next(Q);
            while (next(P) != NULL){
                Q = P;
                P = next(Q);
            }
            next(Q) = NULL;
            dealokasi(P);
        }
    }
}

///end Delete-ing huehue.

///fungsi-fungsi yang akan sangat berguna bagi masa depan.

int hitung(List_parent L){
    address_parent P; int cnt = 0;
    P = first(L);
    while (P != NULL){
        cnt++;
        P = next(P);
    }
    return cnt;
}

void printInfo(List_parent L){
    if(first(L) != NULL){
        address_parent P;
        P = first(L);
        while (P  != NULL){
            cout<<"ID : "<<info(P).ID<<" | Nama Toko Online : "<<info(P).olshop;
           // cout <<endl;
            cout << " | Budget : "<<info(P).budget;
            //cout << endl;
            cout << " | Pengeluaran : "<<info(P).pengeluaran;
            P = next(P);
            cout <<endl;
        }
        cout <<endl;
    } else cout <<"    Tidak ada toko online " <<endl;
    cout<<endl;
}

address_parent findByID(List_parent L, int x) {
        address_parent P = first(L);
    do {
        if(info(P).ID == x) {
            return P;
        }
        P = next(P);
    } while(P != NULL);
    return NULL;
}



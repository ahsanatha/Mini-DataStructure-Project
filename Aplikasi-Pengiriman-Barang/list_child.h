#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED


#include <iostream>
#include <cstdlib>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

struct infotype_child{
    int ID;
    string namaKr;
    int kuota;
    int hargaKg;
    int hargaKm;
    float pendapatan;
    float bintang;
};
typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
};

struct List_child{
    address_child first;
};

void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(List_child &L, address_child &Prec, address_child P);
void deleteFirst(List_child &L);
void deleteLast(List_child &L);
void deleteAfter(List_child &L, address_child Prec);


address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findElm(List_child L, int x);
void printInfo(List_child L);
void autoDelete(List_child &L, address_child P);
int hitung(List_child L);
#endif // LIST_CHILD_H_INCLUDED

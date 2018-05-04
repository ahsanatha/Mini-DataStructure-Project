#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
using namespace std;

#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent


struct infotype_relasi{
    int ID;
    string namaCS;
    float berat;
    float jarak;
    float total;
    float bintang;
};

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    infotype_relasi info;
    address_relasi next;
    address_relasi prev;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first;
};

void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L);
void deleteLast(List_relasi &L);
void deleteAfter(List_relasi &L, address_relasi Prec);
void autoDelete(List_relasi &L, address_relasi P);
void deleteAfterr(List_relasi &L, address_relasi Prec, address_relasi&P);


address_relasi alokasi( address_parent P, address_child C,infotype_relasi data);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, int id);
void printInfo(List_relasi L);
int hitungRLS(List_relasi Hub, address_child pKR);

#endif // LIST_RELASI_H_INCLUDED

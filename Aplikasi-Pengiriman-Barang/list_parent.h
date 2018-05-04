#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next


struct infotype_parent{
    int ID;
    string olshop;
    int pengeluaran;
    int budget;
};
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    address_parent next;
};

struct List_parent {
    address_parent first;
    address_parent last;
};


void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L);
void deleteLast(List_parent &L);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);
void autoDelete(List_parent &L, address_parent P);


address_parent alokasiP(infotype_parent data);
void dealokasi(address_parent &P);
address_parent findByID(List_parent L, int x);
void printInfo(List_parent L);
int hitung(List_parent L);

#endif // LIST_PARENT_H_INCLUDED

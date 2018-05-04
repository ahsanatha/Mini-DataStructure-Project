/// Daniel Peter Smith and Muhammad Ahsan Athallah.
/// IF - 41 - 10
/// Informatics Enginering Telkom University
/// copyright 2018.

#include <iostream>
#include "stdio.h"
#include <string>
#include <cstdlib>
using namespace std;

#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"
#include "mainFunction.h"


int main()
{
    List_parent Olshop;
    createList(Olshop);

    List_child Kurir;
    createList(Kurir);

    List_relasi Hub;
    createList(Hub);

    int idP = 0, idC = 0, idR = 0;

    int command = 1;


    while (command != 0) {
            system("CLS");
            cout <<endl<< " Aplikasi Pengiriman Barang v2.5 " << endl;
            cout <<       " ======== by DPS && MAA ======== "<< endl;
            cout <<" ===============================  " << endl;
            cout <<"   1. Kirim Barang                " << endl;
            cout <<"   2. Menu Toko Online            " << endl;
            cout <<"   3. Menu Ekspedisi              " << endl;
            cout <<"   4. Lihat Kiriman               " << endl;
            cout <<"   0. Keluar dari program :(      " << endl;
            cout <<" ===============================  " << endl;
            cout << endl;
            cout << "[main] >> "; cin >> command;
            cout <<endl;
            switch (command) {
                case 1 : {  tambahRLS(Hub,Olshop,Kurir,idP,idC,idR);
                            break;}
                case 2 : {  menuTO(Olshop,Hub,idP);
                            break;}
                case 3 : {  menuKR(Kurir,Hub,idC);
                            break;}
                case 4 : {  menuRLS(Hub,Olshop,Kurir,idP,idC,idR);
                            break;}
                /// 404 for TEST SPESIFIKASI DARI BU STHEVANIE
                case 404 : { devMode(Olshop,Kurir,Hub);
                            break;}
            }
    }
    system("cls");
    return 0;
}

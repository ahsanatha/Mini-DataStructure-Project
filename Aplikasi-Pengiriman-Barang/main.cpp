#include <iostream>
#include <cstdlib>
#include "FungsiMenu.h"
using namespace std;

int main()
{
    int in;
    do {
    system("cls");
    cout << "Hello world!" << endl;
    cout << "1. Kirim Barang" << endl;
    cout << "2. Cari Nama Penerima" << endl;
    cout << "3. Keluar" << endl;
    cout << endl << " Pilihan : " ; cin >> in;
    switch(in) {
        case 1 : kirimBarang(); break;
        case 2 : cariNamaPenerima(); break;
        case 3 : break;
    }
    }while (in != 3);

    return 0;
}

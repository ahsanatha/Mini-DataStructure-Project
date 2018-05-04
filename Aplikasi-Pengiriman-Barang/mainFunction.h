#ifndef MAINFUNCTION_H_INCLUDED
#define MAINFUNCTION_H_INCLUDED
#include <cstdlib>
///Bagian Muhammad Ahsan Athallah

/// ========== Kurir =========================

void editKR(List_child &kurir){
    int id,dit; address_child Q;
    system("CLS");
    cout << endl<< "#### Update Toko Online ####"<<endl<<endl;
    if (first(kurir) != NULL){
        printInfo(kurir);
        cout << "pilih id kurir yang ingin di edit : "; cin >> id;
        Q = findElm(kurir, id);
        if (Q != NULL){
            cout<<endl;
            cout<< " daftar data di kurir : " << endl;
            cout<< " 1. nama kurir " << endl;
            cout<< " 2. kuota kurir " << endl;
        }
        cout << " pilih data yang ingin di update : "; cin >> dit;
        switch (dit){
            case 1 : {  cin.ignore();
                        cout << " nama kurir : "; getline(cin,info(Q).namaKr);
                        break;}
            case 2 : {cout << " kuota kurir : "; cin >> info(Q).kuota;
                        break;}
        }
        cout << " [!] Data berhasil di update."<< endl;
    }else cout << " [!] Tidak ada kurir terdaftar "<<endl<<endl;
}

void hapusKR(List_child &kurir, List_relasi &Hub){
    system("CLS");
    cout << endl<< "---- Hapus Ekspedisi ----"<<endl<<endl;
    int id; address_child Q;address_relasi pHub; char pil;
    if (first(kurir)!= NULL){
        cout << "[delete]>>" << " Daftar Nama Kurir :"<<endl<<endl;
        printInfo(kurir);
        cout << "pilih id toko yang ingin di hapus : "; cin >>id;
        Q = findElm(kurir,id);
        if (Q != NULL){
            pHub = first(Hub);
            if (pHub != NULL){
                do{
                    cin.ignore();
                    cout <<endl<< " Apakah anda juga ingin menghapus pengiriman terdaftar dengan ekspedisi ini? [y/n] : "; pil = getchar();
                }while(pil != 'y' && pil != 'n');
                while (pHub != NULL){
                    if (child(pHub) == Q){
                        if (pil == 'y'){
                            cout <<endl<< "pengiriman dengan ID "<<info(pHub).ID<<" telah di hapus"<<endl<<endl;
                            autoDelete(Hub,pHub);
                        }else{
                            child(pHub) = NULL;
                            cout <<endl<< "pengiriman dengan ID "<<info(pHub).ID<<" telah di hapus 'pointer to childnya'"<<endl<<endl;
                        }
                    }
                    pHub = next(pHub);
                }
            }
            cout <<endl<<" [!] Ekspedisi "<<info(Q).namaKr<<" telah di hapus."<<endl;
            autoDelete(kurir,Q);
           /// cout <<"test"<<endl;
        } else  cout <<endl<< " [!] ID tidak ada."<<endl;
    }else {
    cout << "  [!] Tidak Ada Kurir"<<endl;
    }
    cout <<endl;
    system("pause");
}


void tambahKR(List_child &kurir,int &id){
    id++;
    system("CLS");
    cout << endl<< "++++ Tambah Ekspedisi ++++"<<endl<<endl;
    infotype_child data;
    address_child PKR;
    cin.ignore();
    cout << "[insert]>>" <<" Nama Kurir    : ";    getline(cin, data.namaKr);
    cout << "[insert]>>" <<" Kuota         : ";         cin >> data.kuota;
    cout << "[insert]>>" <<" Harga per Kg  : "; cin >> data.hargaKg;
    cout << "[insert]>>" <<" Harga per Km  : " ; cin >> data.hargaKm;
    data.pendapatan = 0;
    data.bintang = 0;
    data.ID = id;
    PKR = alokasi(data);
    insertFirst(kurir,PKR);
    cout << endl << " [!] Kurir berhasil di tambahkan." <<endl<<endl;
    system("pause");
}

/// ==================  Bagian Parent . ==============================================///

void editTO(List_parent &TO){
    int id,dit; address_parent Q;
    system("CLS");
    cout << endl<< "#### Update Toko Online ####"<<endl<<endl;
    if (first(TO) != NULL){
        printInfo(TO);
        cout << "pilih id olshop yang ingin di update : "; cin >> id;
        Q = findByID(TO, id);
        if (Q != NULL){
            cout<< endl;
            cout<< " daftar data di kurir : " << endl <<endl;
            cout<< "    1. nama toko online " << endl;
            cout<< "    2. budget toko online " << endl;
        }
        cout <<endl<< " pilih data yang ingin di update : "; cin >> dit;
        switch (dit){
            case 1 : {  cin.ignore();
                        cout << " nama toko online : "; getline(cin,info(Q).olshop);
                        break;}
            case 2 : {cout << " budget toko online : "; cin >> info(Q).budget;
                        break;}
        }
        cout << " [!] Data berhasil di edit."<< endl;
    }else cout << " [!] Tidak ada toko online terdaftar"<<endl<<endl;
}

void hapusTO(List_parent &TO, List_relasi &Hub){
    char pil;
    int id;
    address_parent Q; address_relasi pHub;
    system("CLS");
    cout << endl<< "---- Hapus Toko Online ----"<<endl<<endl;
    if (first(TO)!= NULL){
        cout << "[delete]>>" << " Daftar Nama Toko Online :"<<endl<<endl;
        printInfo(TO);
        cout << "pilih id toko yang ingin di hapus : "; cin >>id;
        Q = findByID(TO,id);
        if (Q != NULL){
            pHub = first(Hub);
            if (pHub != NULL){
                do{
                    cin.ignore();
                    cout <<endl<< " Apakah anda juga ingin menghapus pengiriman terdaftar dengan toko ini? [y/n] : "; pil = getchar();
                }while(pil != 'y' && pil != 'n');
                while (pHub != NULL){
                    if (parent(pHub) == Q){
                        if (pil == 'y'){
                            cout <<endl<< "pengiriman dengan ID "<<info(pHub).ID<<" telah di hapus"<<endl<<endl;
                            autoDelete(Hub,pHub);
                        }else{
                            parent(pHub) = NULL;
                            cout <<endl<< "pengiriman dengan ID "<<info(pHub).ID<<" telah di hapus 'pointer to parentnya'"<<endl<<endl;
                        }
                    }
                    pHub = next(pHub);
                }
            }
            cout <<endl<<" [!] Toko "<<info(Q).olshop<<" telah di hapus."<<endl;
            autoDelete(TO,Q);
        } else  cout <<endl<< " [!] ID tidak ada."<<endl;
    }else {
    cout << "  [!] Tidak Ada Toko Online"<<endl;
    }
    cout <<endl;
    system("pause");
}

void tambahTO(List_parent &TO, int &id){
    id++;
    infotype_parent data;
    address_parent PTO;
    system("CLS");
    cout << endl<< "++++ Tambah Toko Online ++++"<<endl<<endl;
    cin.ignore();
    cout <<"[insert] >>"<< " Nama Toko   : "; getline(cin,data.olshop);
    cout <<"[insert] >>"<< " Budget      : "; cin >> data.budget;
    data.pengeluaran = 0;
    data.ID = id;
    PTO = alokasiP(data);
    insertFirst(TO,PTO);
    cout << endl << " [!] Toko berhasil di tambahkan." <<endl<<endl;
    //break;
    system("pause");
};

/// ===== Relasiiiiiiiiiii ===========


address_parent pilihToko(List_parent &TO, int &idP){
    system("cls");
    address_parent pTO;
    char pil;
    int id;
    if (first(TO) == NULL){
        do{
            cin.ignore();
            cout <<endl<< " [!] Tidak ada Toko terdaftar. ingin tambah toko ? [y/n] : "; pil = getchar();
        }while (pil != 'n' && pil != 'y');
        if (pil == 'y'){
            tambahTO(TO,idP);
            pilihToko(TO,idP);
        } else return NULL;
    } else {
        cout <<endl<< " [==] Toko Online [==]: "<<endl<<endl;
        printInfo(TO);
        cout <<"pilih ID toko online : "; cin >> id;
        pTO = findByID(TO,id);
        if (pTO == NULL){
            do{
                cin.ignore();
                cout <<endl<< " [!] data yang anda cari tidak ada, ingin menambahkan Toko Online? [y/n] :"; pil = getchar();
            }while (pil != 'n' && pil != 'y');
            if (pil == 'y'){
                tambahTO(TO,idP);
                pilihToko(TO,idP);
            } else return NULL;
        } else return pTO;
    }
}

address_child pilihKurir(List_child &KR, int &idC){
    system("cls");
    address_child pKR;
    int id;
    char pil;
    if (first(KR) == NULL){
        do{
            cin.ignore();
            cout <<endl<< " [!] Tidak ada ekspedisi terdaftar. ingin tambah ekspedisi ? [y/n] : "; pil = getchar();
        }while (pil != 'n' && pil != 'y');
        if (pil == 'y'){
            tambahKR(KR,idC);
            pilihKurir(KR,idC);
        } else return NULL;
    } else {
        cout << " [==] Ekspedisi [==] : "<<endl<<endl;
        printInfo(KR);
        cout <<endl << "pilih ID ekspedisi : "; cin >> id;
        pKR = findElm(KR,id);
        if (pKR == NULL){
            do{
                cin.ignore();
                cout <<endl<< " [!] data yang anda cari tidak ada, ingin menambahkan Toko Online? [y/n] : "; pil = getchar();
            }while (pil != 'n' && pil != 'y');
            if (pil == 'y'){
                tambahKR(KR,idC);
                pilihKurir(KR,idC);
            } else return NULL;
        } else return pKR;
    }
}


void tambahRLS(List_relasi &Hub ,List_parent &TO ,List_child &KR,int &idP, int &idC, int &idR){
    idR++;
    system("CLS");
    float tempTotal,berat, jarak,star;
    address_parent pTO; address_child pKR; address_relasi pHub;
    infotype_relasi data;
    pTO = pilihToko(TO,idP);
    if (pTO == NULL){
        cout <<endl<< " [!!] pengisian data pengiriman tidak dapat dilanjutkan karena toko online tidak ada."<<endl<<endl;
        system("pause");
    } else {
            pKR = pilihKurir(KR, idC);
            if (pKR == NULL){
                cout << endl << "[!!] pengisian data pengiriman tidak dapat dilanjutkan karena ekspedisi tidak ada."<<endl<<endl;
                system("pause");
            }else {
                system("cls");
                cout <<endl;
                cout << "  >> Toko Online : "<< info(pTO).olshop<<endl;
                cout << "  >> Ekspedisi   : "<< info(pKR).namaKr <<endl<<endl;
                cout << " silahkan isi data berikut : "<<endl;
                cout << "  [relasi] >> Berat barang     : "; cin >> berat;
                cout << "  [relasi] >> Jarak pengiriman : "; cin >> jarak;
                tempTotal = (berat * info(pKR).hargaKg) + (jarak * info(pKR).hargaKm);
                //cout << "tempTotal = "<<tempTotal<<endl;
                //system("pause");
                if ((tempTotal + info(pTO).pengeluaran) <= info(pTO).budget){
                    if (info(pKR).kuota > hitungRLS(Hub,pKR)){
                        cin.ignore();
                        cout << "  [relasi] >> Nama pengirim    : "; getline(cin,data.namaCS);
                        cout << "  [relasi] >> Rating [1-10]    : "; cin >>star;
                        ///kalkulasi segala macemnya.
                        data.berat = berat;
                        data.jarak = jarak;
                        data.ID = idR;
                        data.bintang = star;
                        info(pKR).bintang = (info(pKR).bintang + star)/2;
                        info(pTO).pengeluaran = info(pTO).pengeluaran + tempTotal;
                        info(pKR).pendapatan = info(pKR).pendapatan + tempTotal;
                        data.total = tempTotal;

                        pHub = alokasi(pTO,pKR,data);
                        insertFirst(Hub,pHub);
                        cout << endl <<endl << " [!] Data tersimpan, Pengiriman akan segera di proses." <<endl << endl;
                        system("pause");
                    }else {
                        cout <<endl<< " [!] maaf input tidak dapat di lanjutkan karena pengiriman akan melebihi batas [kuota Ekspedisi]." <<endl<<endl;
                        system("pause");
                    }
                } else {
                    cout <<endl<< " [!] maaf input tidak dapat di lanjutkan karena pengiriman akan melebihi batas [budget Toko Online]." <<endl<<endl;
                    system("pause");
                }
            }
        }
    }

void hapusRLS(List_relasi &Hub,List_parent &TO, List_child &KR,int &idP, int &idC, int &idR){
    system("CLS");
    int id;
    if (first(Hub) == NULL){
        cout << " tidak ada pengiriman terdaftar. " <<endl;
        system("pause");
    }else{
        address_relasi pHub = first(Hub);
        cout << " daftar pengiriman : "<<endl;
        printInfo(Hub);
        cout << " pilih id pengiriman yang ingin di hapus : "; cin >> id;
        pHub = findElm(Hub,id);
        if (pHub == NULL){
            cout <<endl<< " [!] pengiriman yang anda cari tidak ada. " <<endl<<endl;
            system("pause");
        } else {
            cout <<endl<< "pengiriman dengan ID "<<info(pHub).ID<<" telah di hapus"<<endl<<endl;
            autoDelete(Hub,pHub);
            system("pause");
        }
    }
}

void devMode(List_parent &Olshop, List_child &Kurir, List_relasi &Hub){
    int idP = 0, idC = 0, idR = 0;

    int command = 1;


    while (command != 0) {
            system("CLS");
            cout <<endl<< " Aplikasi Pengiriman Barang v1.0." << endl << endl;
            cout <<" =================================  " << endl;
            cout <<"     1   : insert online shop " <<endl;
            cout <<"     2   : delete online shop " <<endl;
            cout <<"     3   : show   online shop " <<endl;
            cout <<"     4   : update online shop " <<endl;
            cout <<"     5   : insert kurir       " <<endl;
            cout <<"     6   : delete kurir       " <<endl;
            cout <<"     7   : show   kurir "       <<endl;
            cout <<"     8   : update kurir "       <<endl;
            cout <<"     9   : insert Relasi "      <<endl;
            cout <<"     10  : show relasi "        <<endl;
            cout <<"     11  : delete relasi "      <<endl;
            cout <<"     0   : exit program :( "    <<endl;
            cout <<" =================================  " << endl;
            cout << endl;
            cout << "[main] >> "; cin >> command;
            cout <<endl;
            switch (command) {
                case 1 : {  tambahTO(Olshop,idP);
                            break;}

                case 2 : {  hapusTO(Olshop,Hub);
                            break;}

                case 3 : {  printInfo(Olshop);
                            cout << " Banyak elemen di list Toko online : "<< hitung(Olshop)<<endl;
                            system("pause");
                            break;}

                case 5 : {
                            tambahKR(Kurir,idC);
                            break;}

                case 7 : {  printInfo(Kurir);
                            cout << "banyak elemen di list kurir : "<< hitung(Kurir) << endl;
                            system("pause");
                            break;}

                case 6 : {  hapusKR(Kurir,Hub);
                            break;}

                case 8 : {  editKR(Kurir);
                            system("pause");
                            break;}

                case 4 : {  editTO(Olshop);
                            system("pause");
                            break;}
                case 9 : {
                            tambahRLS(Hub,Olshop,Kurir,idP,idC,idR);
                            break;}
                case 10 : { printInfo(Hub);
                            system("pause");
                            break;}
                case 11 : { hapusRLS(Hub,Olshop,Kurir,idP,idC,idR);
                            break;}
            }
    };
    //system("CLS");
}
void menuRLS(List_relasi &Hub, List_parent &TO, List_child &KR,int &idP,int &idC, int &idR){
    char pil;
    int choose;
    do{
        system("CLS");
        cout << endl;
        cout << " Daftar Relasi"<<endl;
        cout <<endl;
        printInfo(Hub);
        if (first(Hub)== NULL){
            do{
                cin.ignore();
                cout <<endl<< " [!] Tidak ada pengiriman terdaftar. Ingin melakukan pengiriman? [y/n] : "; pil = getchar();
            }while (pil != 'n' && pil != 'y');
            if (pil == 'y'){
                tambahRLS(Hub,TO,KR,idP,idC,idR);
                menuRLS(Hub,TO,KR,idP,idC,idR);
            }else { break;}
        }else {
            cout << " ========================= "<<endl;
            cout << "   1. Tambah Pengiriman    "<<endl;
            cout << "   2. Hapus  Pengiriman    "<<endl;
            cout << "   0. Kembali              "<<endl;
            cout << " ========================= "<<endl;
            cout <<endl;
            cin.ignore();
            cout << " [RLS] >> "; cin>>choose;
            switch (choose){
                case 1 : {  tambahRLS(Hub,TO,KR,idP,idC,idR);
                            break;}
                case 2 : {  hapusRLS(Hub,TO,KR,idP,idC,idR);
                            break;}
            }
            cout <<endl;
        }

    }while (choose != 0);
}

void menuKR(List_child &KR,List_relasi &Hub, int &idC){
    int pil;
    do{
        system("CLS");
        cout << endl;
        cout << " Daftar Ekspedisi : "<<endl;
        cout << endl;
        printInfo(KR);
        cout << endl<<"      banyak data : " <<hitung(KR)<<endl;
        cout << " ========================= "<<endl;
        cout << "   1. Tambah Ekspedisi     "<<endl;
        cout << "   2. Hapus  Ekspedisi     "<<endl;
        cout << "   3. Update Ekspedisi     "<<endl;
        cout << "   0. Kembali              "<<endl;
        cout << " ========================= "<<endl;
        cout <<endl;
        cin.ignore();
        cout << " [KR] >> "; cin>>pil;
        cout <<endl;
        switch (pil){
            case 1 : {  tambahKR(KR,idC);
                        break;}
            case 2 : {  hapusKR(KR,Hub);
                        break;}
            case 3 : {  editKR(KR);
                        break;}
        }
    }while(pil != 0);
}


void menuTO(List_parent &TO,List_relasi &Hub, int &idP){
    //address_parent pTO;
    int pil;
    do{
        system("CLS");
        cout << endl;
        cout << " Daftar Toko Online : "<<endl;
        cout << endl;
        printInfo(TO);
        cout << endl<<"      banyak data : " <<hitung(TO)<<endl;
        cout << " ========================= "<<endl;
        cout << "   1. Tambah Toko Online   "<<endl;
        cout << "   2. Hapus  Toko Online   "<<endl;
        cout << "   3. Update Toko Online   "<<endl;
        cout << "   0. Kembali              "<<endl;
        cout << " ========================= "<<endl;
        cout <<endl;
        cin.ignore();
        cout << " [TO] >> "; cin>>pil;
        cout <<endl;
        switch (pil){
            case 1 : {  tambahTO(TO,idP);
                        break;}
            case 2 : {  hapusTO(TO,Hub);
                        break;}
            case 3 : {  editTO(TO);
                        break;}
        }
    }while(pil != 0);
}
#endif // MAINFUNCTION_H_INCLUDED

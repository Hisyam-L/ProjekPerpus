
#include "buku.cpp";



void login_member(){
    int pilihan = 4;
    string databuku = "data_buku.txt";
    do {
        cout << "\n=== MENU MEMBER ===" << endl;
        cout << "[1] Pilihan Buku" << endl;
        cout << "[2] Pinjam Buku" << endl;
        cout << "[3] Cari Buku" << endl;
        cout << "[4] Kembalikan Buku" << endl;
        cout << "[5] Bayar Denda Buku"<<endl;
        cout << "[6] Logout"<<endl;

        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: 
<<<<<<< HEAD
                system("cls");
                bacaDataBuku(databuku);
            break;
                
=======
            int jumlah;
            system("cls");
                cout << "Buku yang tersedia : ";

>>>>>>> b70cda7bfaa66dbbc25c5e804a1f7d48f2e1c8e6
            case 2:

            break;

            case 3: cout << "Logout berhasil!" << endl; 
                caribuku();
            break;

            case 4: cout << "Logout berhasil!" << endl; 
            break;

            case 5: cout << "Logout berhasil!" << endl; 
            break;

            case 6: cout << "Logout berhasil!" << endl; 
            break;



            default: cout << "Pilihan tidak valid!" << endl;
            break;
        }
    } while (pilihan != 4);

}

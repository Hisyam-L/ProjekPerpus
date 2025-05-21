#include "function_member.cpp";



void login_member(string inputuser){
    int pilihan;
    string databuku = "data_buku.txt";
    do {
        cout << "\n=== MENU MEMBER ===" << endl;
        cout << "[1] Pilihan Buku" << endl;
        cout << "[2] Pinjam Buku" << endl;
        cout << "[3] Cari Buku" << endl;
        cout << "[4] Kembalikan Buku" << endl;
        cout << "[5] Riwayat Pinjam"<<endl;
        cout << "[6] Logout"<<endl;

        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: 
                system("cls");
                bacaDataBuku(databuku);
            break;
                
            case 2:
            system("cls");
                pinjam_buku(inputuser);
            break;

            case 3: 
            system("cls");
                caribuku();
            break;

            case 4: 
            system("cls");
                kembalikan_buku(inputuser);
            break;

            case 5: 
            system("cls");
                riwayat_pinjam_buku(inputuser);
            break;

            case 6: 
            system("cls");
                cout << "Anda telah keluar";   
            break;

            default: cout << "Pilihan tidak valid!" << endl;
            break;
        }
    } while (pilihan != 6);

}

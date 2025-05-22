#include "project_alpro_2.cpp";

const string namaFile = "data_buku.txt";


vector<Buku> bacaBukuDariFile() {
    vector<Buku> daftar;
    ifstream file(namaFile);
    if (!file.is_open()) {
        cout << "File tidak ditemukan, mulai dengan data kosong." << endl;
        return daftar;
    }
    string line;
    while (getline(file, line)) {
        Buku buku;
        stringstream ss(line);
        string temp;

        
        getline(ss, temp, '|'); buku.IDBuku = stoi(temp);
        getline(ss, buku.judulBuku, '|');
        getline(ss, buku.penulisBuku, '|');
        getline(ss, buku.penerbitBuku, '|');
        getline(ss, temp, '|'); buku.tahunTerbit = stoi(temp);
        getline(ss, buku.sinopsisBuku, '|');
        getline(ss, buku.ISBNBuku, '|');
        getline(ss, buku.genreBuku, '|');
        getline(ss, temp, '|'); buku.jumlahHalamanBuku = stoi(temp);
        getline(ss, temp, '|'); buku.jumlahsalinan = stoi(temp);

        daftar.push_back(buku);
    }
    file.close();
    return daftar;
}



string bersihkanInput(const string& input) {
    string output = input;
    output.erase(remove(output.begin(), output.end(), '|'), output.end());
    return output;
}

void tambahBuku() {
    Buku bukuBaru;
    cout << "Masukkan ID Buku: "; cin >> bukuBaru.IDBuku;
    cin.ignore();
    cout << "Masukkan Judul Buku: "; getline(cin, bukuBaru.judulBuku);
    cout << "Masukkan Penulis Buku: "; getline(cin, bukuBaru.penulisBuku);
    cout << "Masukkan Penerbit Buku: "; getline(cin, bukuBaru.penerbitBuku);
    cout << "Masukkan Tahun Terbit: "; cin >> bukuBaru.tahunTerbit;
    cin.ignore();
    cout << "Masukkan Sinopsis Buku: "; getline(cin, bukuBaru.sinopsisBuku);
    cout << "Masukkan ISBN Buku: "; getline(cin, bukuBaru.ISBNBuku);
    cout << "Masukkan Genre Buku: "; getline(cin, bukuBaru.genreBuku);
    cout << "Masukkan Jumlah Halaman: "; cin >> bukuBaru.jumlahHalamanBuku;
    cout << "Masukkan Jumlah Salinan: "; cin >> bukuBaru.jumlahsalinan;
    cin.ignore();

    ifstream file("data_buku.txt");
    ofstream temp("dummy.txt");
    bool duplikat = false;

    if (!file.is_open() || !temp.is_open()) {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        Buku b = bukutostring(line);

        if (b.IDBuku == bukuBaru.IDBuku) {
            cout << "ID Buku sudah ada. Tambah dibatalkan.\n";
            duplikat = true;
        }

        temp << b.IDBuku << "|"
             << b.judulBuku << "|"
             << b.penulisBuku << "|"
             << b.penerbitBuku << "|"
             << b.tahunTerbit << "|"
             << b.sinopsisBuku << "|"
             << b.ISBNBuku << "|"
             << b.genreBuku << "|"
             << b.jumlahHalamanBuku << "|"
             << b.jumlahsalinan << "\n";
    }

    if (!duplikat) {
        temp << bukuBaru.IDBuku << "|"
             << bukuBaru.judulBuku << "|"
             << bukuBaru.penulisBuku << "|"
             << bukuBaru.penerbitBuku << "|"
             << bukuBaru.tahunTerbit << "|"
             << bukuBaru.sinopsisBuku << "|"
             << bukuBaru.ISBNBuku << "|"
             << bukuBaru.genreBuku << "|"
             << bukuBaru.jumlahHalamanBuku << "|"
             << bukuBaru.jumlahsalinan << "\n";

        cout << "Buku berhasil ditambahkan!" << endl;
    }

    file.close();
    temp.close();

    // Ganti file lama
    remove("data_buku.txt");
    rename("dummy.txt", "data_buku.txt");
}




void cekSemuaBuku() {
    vector<Buku> daftar = bacaBukuDariFile();
    if (daftar.empty()) {
        cout << "Tidak ada buku dalam daftar." << endl;
        return;
    }
    cout << "=== DAFTAR BUKU ===" << endl;
    for (auto& buku : daftar) {
        cout << "ID Buku         : " << buku.IDBuku << endl;
        cout << "Judul Buku      : " << buku.judulBuku << endl;
        cout << "Penulis Buku    : " << buku.penulisBuku << endl;
        cout << "Penerbit Buku   : " << buku.penerbitBuku << endl;
        cout << "Tahun Terbit    : " << buku.tahunTerbit << endl;
        cout << "Sinopsis Buku   : " << buku.sinopsisBuku << endl;
        cout << "ISBN Buku       : " << buku.ISBNBuku << endl;
        cout << "Genre Buku      : " << buku.genreBuku << endl;
        cout << "Jumlah Halaman  : " << buku.jumlahHalamanBuku << endl;
        cout << "Jumlah Salinan  : " << buku.jumlahsalinan << endl;
        cout << "---------------------------" << endl;
    }
}


void cariBukuByID(int id) {
    vector<Buku> daftar = bacaBukuDariFile();
    bool found = false;
    for (auto& buku : daftar) {
        if (buku.IDBuku == id) {
            cout << "Buku ditemukan:" << endl;
            cout << "Judul Buku: " << buku.judulBuku << endl;
            cout << "Penulis Buku: " << buku.penulisBuku << endl;
            cout << "Penerbit Buku: " << buku.penerbitBuku << endl;
            cout << "Tahun Terbit: " << buku.tahunTerbit << endl;
            cout << "Sinopsis Buku: " << buku.sinopsisBuku << endl;
            cout << "ISBN Buku: " << buku.ISBNBuku << endl;
            cout << "Genre Buku: " << buku.genreBuku << endl;
            cout << "Jumlah Halaman: " << buku.jumlahHalamanBuku << endl;
            cout << "Jumlah Salinan: " << buku.jumlahsalinan << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Buku dengan ID " << id << " tidak ditemukan." << endl;
    }
}

void admin() {
    int pilihan;
    do {
        cout << "=== MENU ADMIN===" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Cek Semua Buku" << endl;
        cout << "3. Cari Buku Berdasarkan ID" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: "; cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                system("cls");
                tambahBuku();
                break;
            case 2:
                system("cls");
                bacaDataBuku(namaFile);
                break;
            case 3: {
                system("cls");
                int id;
                cout << "Masukkan ID buku yang dicari: ";
                cin >> id;
                cin.ignore();
                cariBukuByID(id);
                break;
            }
            case 0:
            system("cls");
                cout << "Terima kasih." << endl;
                break;
            default:
            system("cls");
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);


}


int bacaAkunDariFile(string namafile, akun** &arr, int &jumlah) {
    ifstream file(namafile);
    if (!file.is_open()) {
        jumlah = 0;
        arr = nullptr;
        return 0;
    }

    jumlah = 0;
    string baris;
    while (getline(file, baris)) {
        jumlah++;
    }

    file.clear();
    file.seekg(0);

    arr = new akun*[jumlah];
    int i = 0;
    while (getline(file, baris)) {
        int koma = baris.find(',');
        if (koma != -1) {
            arr[i] = new akun;
            arr[i]->username = baris.substr(0, koma);
            arr[i]->password = baris.substr(koma + 1);
            i++;
        }
    }

    file.close();
    return jumlah;
}

void simpanKeFile(string namafile, akun** arr, int jumlah) {
    ofstream file(namafile);
    for (int i = 0; i < jumlah; i++) {
        file << arr[i]->username << "," << arr[i]->password << "\n";
    }
    file.close();
}

void hapusAkun(akun** &arr, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        delete arr[i];
    }
    delete[] arr;
    arr = nullptr;
}

void registrasi(string namafile, int maksimal) {
    akun** arr = nullptr;
    int jumlah = 0;

    bacaAkunDariFile(namafile, arr, jumlah);

    if (jumlah >= maksimal) {
        cout << "GAGAL: Kapasitas penuh\n";
        hapusAkun(arr, jumlah);
        return;
    }

    string user, pass;
    cout << "\n=== Registrasi ===\n";
    cout << "Masukkan username: ";
    cin >> user;
    cout << "Masukkan password: ";
    cin >> pass;

    bool sudahAda = false;
    for (int i = 0; i < jumlah; i++) {
        if (arr[i]->username == user) {
            sudahAda = true;
            break;
        }
    }

    if (sudahAda) {
        cout << "Username sudah terdaftar\n";
        hapusAkun(arr, jumlah);
        return;
    }

    akun** baru = new akun*[jumlah + 1];
    for (int i = 0; i < jumlah; i++) {
        baru[i] = arr[i];
    }

    baru[jumlah] = new akun;
    baru[jumlah]->username = user;
    baru[jumlah]->password = pass;

    delete[] arr;
    arr = baru;
    jumlah++;

    simpanKeFile(namafile, arr, jumlah);
    cout << "Registrasi berhasil!\n";

    hapusAkun(arr, jumlah);
}

void login1(const string& namafile) {
    akun** arr = nullptr;
    int size = 0;

    bacaAkunDariFile(namafile, arr, size);

    cout << "\n=== Login ===\n";
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    bool loginBerhasil = false;
    for (int i = 0; i < size; i++) {
        if (arr[i]->username == username && arr[i]->password == password) {
            loginBerhasil = true;
            break;
        }
        else if (username == "admin" && password == "admin123")
        {
            admin();
        }
        
    }

    if (loginBerhasil) {
        cout << "Login berhasil! Selamat datang, " << username << ".\n";
        login_member(username);
    } else {
        cout << "Login gagal! Username atau password salah.\n";
    }

    hapusAkun(arr, size);
}

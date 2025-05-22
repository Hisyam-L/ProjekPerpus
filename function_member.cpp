#include "buku.cpp"


riwayat_pinjam riwayattostring(const string& line){
    stringstream ss(line);
    riwayat_pinjam riwayat;
    string item;

    getline(ss, riwayat.judulBuku, ',');
    getline(ss, riwayat.username, ',');
    getline(ss, riwayat.waktupinjam, ',');
    getline(ss, item, ',');
    riwayat.idbuku = stoi(item);

    return riwayat;
}

string stringtoriwayat(const riwayat_pinjam& riwayat) {
    return riwayat.judulBuku + "," + riwayat.username + "," + riwayat.waktupinjam + "," + to_string(riwayat.idbuku);
}

Buku bukutostring(const string& line){
        stringstream ss(line);
        string item;
        Buku buku;

        getline(ss, item, ',');
        buku.IDBuku = stoi(item);

        getline(ss, buku.judulBuku, ',');
        getline(ss, buku.penulisBuku, ',');
        getline(ss, buku.penerbitBuku, ',');

        getline(ss, item, ',');
        buku.tahunTerbit = stoi(item);

        getline(ss, buku.sinopsisBuku, ',');
        getline(ss, buku.ISBNBuku, ',');
        getline(ss, buku.genreBuku, ',');

        getline(ss, item, ',');
        buku.jumlahHalamanBuku = stoi(item);

        getline(ss, item, ',');
        buku.jumlahsalinan = stoi(item);
        return buku;
}

string stringtobuku(const Buku &buku){
    return to_string(buku.IDBuku) + "," + buku.judulBuku + "," + buku.penulisBuku + "," +
           buku.penerbitBuku + "," + to_string(buku.tahunTerbit) + "," + buku.sinopsisBuku + "," +
           buku.ISBNBuku + "," + buku.genreBuku + "," + to_string(buku.jumlahHalamanBuku) + "," +
           to_string(buku.jumlahsalinan);
}

void bacaDataBuku(string data_buku) {
    ifstream file(data_buku);

    if (!file.is_open()) {
        cerr << "Tidak dapat membuka file: " << data_buku << endl;
        return;
    }

    string line;
    int nomor = 1;
    while (getline(file, line)) {
        stringstream ss(line);
        string item;
        Buku buku;

        getline(ss, item, ',');
        buku.IDBuku = stoi(item);

        getline(ss, buku.judulBuku, ',');
        getline(ss, buku.penulisBuku, ',');
        getline(ss, buku.penerbitBuku, ',');

        getline(ss, item, ',');
        buku.tahunTerbit = stoi(item);

        getline(ss, buku.sinopsisBuku, ',');
        getline(ss, buku.ISBNBuku, ',');
        getline(ss, buku.genreBuku, ',');

        getline(ss, item, ',');
        buku.jumlahHalamanBuku = stoi(item);

        getline(ss, item, ',');
        buku.jumlahsalinan = stoi(item);

        cout << "==========================================" << endl;
        cout << "           Data Buku Ke-" << nomor++ << endl;
        cout << "==========================================" << endl;
        cout << left << setw(20) << "ID Buku"            << ": " << buku.IDBuku << endl;
        cout << left << setw(20) << "Judul"              << ":" << buku.judulBuku << endl;
        cout << left << setw(20) << "Penulis"            << ":" << buku.penulisBuku << endl;
        cout << left << setw(20) << "Penerbit"           << ":" << buku.penerbitBuku << endl;
        cout << left << setw(20) << "Tahun Terbit"       << ": " << buku.tahunTerbit << endl;
        cout << left << setw(20) << "Sinopsis"           << ":" << buku.sinopsisBuku << endl;
        cout << left << setw(20) << "ISBN"               << ":" << buku.ISBNBuku << endl;
        cout << left << setw(20) << "Genre"              << ":" << buku.genreBuku << endl;
        cout << left << setw(20) << "Jumlah Halaman"     << ": " << buku.jumlahHalamanBuku << endl;
        cout << left << setw(20) << "Jumlah Salinan"     << ": " << buku.jumlahsalinan << endl;
        cout << endl;
    }

    file.close();
    system("pause");
}



void pinjam_buku(string user) {
    ifstream file("data_buku.txt");
    ofstream temp("dummy.txt");

    if (!file.is_open() || !temp.is_open()) {
        cerr << "Gagal membuka file data_buku atau dummy.\n";
        return;
    }

    vector<riwayat_pinjam> riwayatList;
    ifstream riwayatFile("riwayat_pinjam.txt");
    if (riwayatFile.is_open()) {
        string line;
        while (getline(riwayatFile, line)) {
            if (!line.empty()) {
                riwayatList.push_back(riwayattostring(line));
            }
        }
        riwayatFile.close();
    }

    cout << "Masukkan nama buku yang ingin dipinjam: ";
    string namabuku;
    getline(cin, namabuku);

    string line;
    bool found = false;

    while (getline(file, line)) {
        Buku b = bukutostring(line);

        if (b.judulBuku == namabuku) {
            found = true;
            if (b.jumlahsalinan > 0) {
                b.jumlahsalinan--;
                cout << "Berhasil meminjam \"" << b.judulBuku
                     << "\". Sisa salinan: " << b.jumlahsalinan << "\n";

                time_t now = time(0);
                char* dt_raw = ctime(&now);
                string dt(dt_raw);

                if (!dt.empty() && dt.back() == '\n') {
                    dt.pop_back();
                }

                riwayat_pinjam baru;
                baru.judulBuku = b.judulBuku;
                baru.username = user;
                baru.waktupinjam = dt;
                baru.idbuku = b.IDBuku;
                riwayatList.push_back(baru);

            } else {
                cout << "Maaf, \"" << b.judulBuku << "\" sedang habis.\n";
            }
        }

        temp << to_string(b.IDBuku) << ","
             << b.judulBuku << ","
             << b.penulisBuku << ","
             << b.penerbitBuku << ","
             << to_string(b.tahunTerbit) << ","
             << b.sinopsisBuku << ","
             << b.ISBNBuku << ","
             << b.genreBuku << ","
             << to_string(b.jumlahHalamanBuku) << ","
             << to_string(b.jumlahsalinan)
             << "\n";
    }

    if (!found) {
        cout << "Buku dengan judul \"" << namabuku << "\" tidak ditemukan.\n";
    }

    file.close();
    temp.close();

    ofstream riwayatOut("riwayat_pinjam.txt");
    if (!riwayatOut.is_open()) {
        cerr << "Gagal membuka file riwayat_pinjam.txt untuk menulis.\n";
        return;
    }
    for (const auto& r : riwayatList) {
        riwayatOut << r.judulBuku << ","
                   << r.username << ","
                   << r.waktupinjam << ","
                   << r.idbuku << "\n";
    }
    riwayatOut.close();

    remove("data_buku.txt");
    rename("dummy.txt", "data_buku.txt");
}

void bubbleSortRekursif(vector<Buku>& data, int n) {

    if (n == 1) return;

    for (int i = 0; i < n - 1; i++) {
        if (data[i].judulBuku > data[i + 1].judulBuku) {
            swap(data[i], data[i + 1]);
        }
    }

    bubbleSortRekursif(data, n - 1);
}

vector<Buku> caribukuberdasarkan(int pilihanberdasarkan, string katakunci) {
    ifstream file("data_buku.txt");
    vector<Buku> hasil;

    if (!file.is_open()) {
        cerr << "Gagal membuka file data_buku.txt\n";
        return hasil;
    }

    string line;
    while (getline(file, line)) {
        Buku buku = bukutostring(line);

        
        if (pilihanberdasarkan == 1 && buku.judulBuku == katakunci) {
            hasil.push_back(buku);
        }
        
        else if (pilihanberdasarkan == 2 && buku.penulisBuku == katakunci) {
            hasil.push_back(buku);
        }
        
        else if (pilihanberdasarkan == 3 && buku.genreBuku == katakunci) {
            hasil.push_back(buku);
        }
        
        else if (pilihanberdasarkan == 4) {
            try {
                int tahun = stoi(katakunci); 
                if (buku.tahunTerbit == tahun) {
                    hasil.push_back(buku);
                }
            } catch (...) {
                cout << "Input tahun tidak valid. Harus berupa angka.\n";
                break; 
            }
        }
    }

    if (pilihanberdasarkan == 4 && !hasil.empty()) {
        bubbleSortRekursif(hasil, hasil.size());
    }

    file.close();
    return hasil;
}





void caribuku() {
    bool keluarcari = false;
    while (!keluarcari) {
        int pilihancari;
        string katakunci;

        cout << "Mencari berdasarkan apa ?\n";
        cout << "1. Judul\n2. Penulis\n3. Genre\n4. Tahun Rilis\n5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihancari;
        cin.ignore();

        if (pilihancari == 4) {
            keluarcari = true;
            continue;
        }

        cout << "Masukkan kata kunci: ";
        getline(cin, katakunci);

        vector<Buku> hasil = caribukuberdasarkan(pilihancari, katakunci);

        if (hasil.empty()) {
            cout << "Tidak ditemukan buku dengan kriteria tersebut.\n\n";
        } else {
            int nomor = 1;
            for (const auto& buku : hasil) {
                cout << "==========================================\n";
                cout << "           Data Buku Ke-" << nomor++ << endl;
                cout << "==========================================\n";
                cout << left << setw(20) << "ID Buku"        << ": " << buku.IDBuku << endl;
                cout << left << setw(20) << "Judul"          << ": " << buku.judulBuku << endl;
                cout << left << setw(20) << "Penulis"        << ": " << buku.penulisBuku << endl;
                cout << left << setw(20) << "Penerbit"       << ": " << buku.penerbitBuku << endl;
                cout << left << setw(20) << "Tahun Terbit"   << ": " << buku.tahunTerbit << endl;
                cout << left << setw(20) << "Sinopsis"       << ": " << buku.sinopsisBuku << endl;
                cout << left << setw(20) << "ISBN"           << ": " << buku.ISBNBuku << endl;
                cout << left << setw(20) << "Genre"          << ": " << buku.genreBuku << endl;
                cout << left << setw(20) << "Jumlah Halaman" << ": " << buku.jumlahHalamanBuku << endl;
                cout << left << setw(20) << "Jumlah Salinan" << ": " << buku.jumlahsalinan << endl;
                cout << endl;
            }
        }
    }
}



void riwayat_pinjam_buku(string username) {
    ifstream file("riwayat_pinjam.txt");
    if (!file.is_open()) {
        cerr << "Gagal membuka file riwayat.\n";
        return;
    }

    cout << "Berikut adalah riwayat pinjam buku Anda:\n";
    string line;
    int nomor = 1;

    while (getline(file, line)) {
        riwayat_pinjam r = riwayattostring(line);
        if (r.username == username) {
            cout << "----------------------------------\n";
            cout << "Riwayat Ke-" << nomor++ << endl;
            cout << "Judul Buku : " << r.judulBuku << endl;
            cout << "Waktu Pinjam : " << r.waktupinjam << endl;
            cout << "ID Buku : " << r.idbuku << endl;
        }
    }

    if (nomor == 1) {
        cout << "Tidak ada riwayat peminjaman ditemukan.\n";
    }

    file.close();
}

void kembalikan_buku(string username) {
    ifstream file("riwayat_pinjam.txt");
    if (!file.is_open()) {
        cerr << "Gagal membuka file riwayat.\n";
        return;
    }

    vector<riwayat_pinjam> riwayat_user;
    string line;
    while (getline(file, line)) {
        riwayat_pinjam r = riwayattostring(line);
        if (r.username == username) {
            riwayat_user.push_back(r);
        }
    }
    file.close();

    if (riwayat_user.empty()) {
        cout << "Anda tidak memiliki buku yang sedang dipinjam.\n";
        return;
    }

    cout << "Buku yang sedang Anda pinjam:\n";
    for (size_t i = 0; i < riwayat_user.size(); ++i) {
        cout << i + 1 << ". " << riwayat_user[i].judulBuku
             << " (ID: " << riwayat_user[i].idbuku
             << ", Waktu Pinjam: " << riwayat_user[i].waktupinjam << ")\n";
    }

    cout << "Masukkan nomor buku yang ingin dikembalikan: ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    if (pilihan < 1 || pilihan > (int)riwayat_user.size()) {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    riwayat_pinjam dipilih = riwayat_user[pilihan - 1];

    ifstream buku_in("data_buku.txt");
    ofstream buku_out("dummy_buku.txt");
    string baris;
    while (getline(buku_in, baris)) {
        Buku b = bukutostring(baris);
        if (b.IDBuku == dipilih.idbuku) {
            b.jumlahsalinan++; 
        }
        buku_out << stringtobuku(b) << "\n";
    }
    buku_in.close();
    buku_out.close();
    remove("data_buku.txt");
    rename("dummy_buku.txt", "data_buku.txt");

    ifstream riwayat_in("riwayat_pinjam.txt");
    ofstream riwayat_out("dummy_riwayat.txt");

    while (getline(riwayat_in, line)) {
        riwayat_pinjam r = riwayattostring(line);
        if (!(r.username == dipilih.username && r.idbuku == dipilih.idbuku && r.waktupinjam == dipilih.waktupinjam)) {
            riwayat_out << stringtoriwayat(r) << "\n";
        }
    }
    riwayat_in.close();
    riwayat_out.close();
    remove("riwayat_pinjam.txt");
    rename("dummy_riwayat.txt", "riwayat_pinjam.txt");

    cout << "Buku \"" << dipilih.judulBuku << "\" berhasil dikembalikan.\n";
}

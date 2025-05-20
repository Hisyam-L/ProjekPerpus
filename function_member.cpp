#include "buku.cpp"

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

void bacaDataBuku() {
    string data_buku = "data_buku.txt";
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

        // Tampilkan data dalam format rapi
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



void pinjam_buku() {
    ifstream file("data_buku.txt");
    ofstream temp("dummy.txt");
    if (!file.is_open() || !temp.is_open()) {
        cerr << "Gagal membuka file.\n";
        return;
    }

    cin.ignore();

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
            } else {
                cout << "Maaf, \"" << b.judulBuku << "\" sedang habis.\n";
            }
        }
        temp << to_string(b.IDBuku) << ","
             << b.judulBuku    << ","
             << b.penulisBuku  << ","
             << b.penerbitBuku << ","
             << to_string(b.tahunTerbit) << ","
             << b.sinopsisBuku << ","
             << b.ISBNBuku     << ","
             << b.genreBuku    << ","
             << to_string(b.jumlahHalamanBuku) << ","
             << to_string(b.jumlahsalinan)
             << "\n";
    }

    if (!found) {
        cout << "Buku dengan judul \"" << namabuku << "\" tidak ditemukan.\n";
    }

    file.close();
    temp.close();

    remove("data_buku.txt");
    rename("dummy.txt", "data_buku.txt");
}

int carinamabuku(string nama_buku, int indeks){
    if (indeks >= jumlah_buku)
    {
        return -1;
    }
    else{

    }
    
    
}

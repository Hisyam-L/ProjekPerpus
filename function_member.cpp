#include "buku.cpp";

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

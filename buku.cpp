#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Buku
{
    int IDBuku;
    string judulBuku;
    string penulisBuku;
    string penerbitBuku;
    int tahunTerbit;
    string sinopsisBuku;
    string ISBNBuku;
    string genreBuku;
    int jumlahHalamanBuku;
    int jumlahsalinan;
};
const int jumlah_max_buku = 3000;


int jumlah_buku = 100; 

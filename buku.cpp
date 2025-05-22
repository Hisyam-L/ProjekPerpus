#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <algorithm>
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


int jumlah_buku = 100; 
int jumlah_buku_dipinjam = 0; 


struct riwayat_pinjam{
    string judulBuku;
    string username;
    string waktupinjam;
    int idbuku;
};

int a;

struct akun 
{
    string username;
    string password;
};

struct buku
{
    string judul;
    string penulis;
};

const int max_buku = 3000;
int bukucount = 0;
buku daftarBuku[max_buku];


const int max_user = 1000;
int usercount = 0;
akun acc[max_user];

bool found = 0;
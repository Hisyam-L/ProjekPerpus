#include "project_alpro_2.cpp";


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

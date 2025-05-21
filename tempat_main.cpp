#include "login_daftar.cpp";

int main(){
    akun acc[max_user];
    bool ulang = 0;
    string fileakun = "akun.txt";
    int batasUser = 1000;
    int choice;
        do{
            system("cls");
        cout<<"[1]daftar\n";
        cout<<"[2]login\n";
        cout<<"[3]keluar\n";
        cout<<"masukkan angka : ";
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1 : 
                registrasi(fileakun, batasUser);
            break;
            
            case 2 : 
                login1(fileakun);
            break;

            
            case 3:
            cout<<"Terimakasih";
            system("pause");
            bool ulang = 1;
            break; 
        }
    }while(!ulang);
}
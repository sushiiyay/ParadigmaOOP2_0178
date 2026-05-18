#include <iostream>
#include <iomanip>
using namespace std;

class RekeningBank {
  public:
    virtual void potongAdmin() = 0;
    virtual ~RekeningBank() {}
}


class RekeningSyariah : public RekeningBank {
  private:
    string nama;
    double saldo;

  public:
    void setRekening(string n, double s){
      nama = n;
      saldo = s;
    }
    void potongAdmin() override {
      cout << "Nama     : " << nama << endl;
      cout << "Tipe     : Syariah" << endl;
      cout << "Admin    : Bebas biaya admin" << endl;
      cout << "Saldo    : Rp " << saldo << endl;
      cout << "----------------------------" << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
  private:
    string nama;
    double saldo;

  public:
    void setRekening(string n, double s){
      nama = n;
      saldo = s;
    }
    void potongAdmin() override {
      saldo -= 15000;
      cout << "Nama     : " << nama << endl;
      cout << "Tipe     : Konvensional" << endl;
      cout << "Admin    : Rp 15.000 dipotong" << endl;
      cout << "Saldo    : Rp " << saldo << endl;
      cout << "----------------------------" << endl;
    }
};

class RekeningPremium : public RekeningBank {
  private:
    string nama;
    double saldo;

  public:
    void setRekening(string n, double s){
      nama = n;
      saldo = s;
    }
    void potongAdmin() override {
      cout << "Nama     : " << nama << endl;
      cout << "Tipe     : Premium" << endl;
      if(saldo > 10000000){
        cout << "Admin    : Bebas biaya admin" << endl;
      } else {
        saldo -= 50000;
        cout << "Admin    : Rp 50.000 dipotong" << endl;
      }
      cout << "Saldo    : Rp " << saldo << endl;
      cout << "----------------------------" << endl;
    }
};

int main(){
  RekeningSyariah rs;
  cout << fixed << setprecision(0);
  rs.setRekening("Sono", 5000000);

  RekeningKonvensional rk;
  rk.setRekening("Nur", 2000000);

  RekeningPremium rp1;
  rp1.setRekening("Yono", 15000000);

  RekeningPremium rp2;
  rp2.setRekening("Helmi", 8000000);

  cout << "=== Proses Akhir Bulan - Bank Gibran Jaya ===" << endl;
  cout << "----------------------------" << endl;

  rs.potongAdmin();
  rk.potongAdmin();
  rp1.potongAdmin();
  rp2.potongAdmin();

  return 0;
}
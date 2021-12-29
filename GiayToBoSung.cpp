#include"QLGTBS.h"

GiayToBoSung::GiayToBoSung()
{
    this->MaYeuCau = "";
    this->TenGiayToCanBoSung = "";
    this->ThoiDiemYeuCau = "";
    this->ThoiDiemBoSung = "";
    this->TinhTrang = "";
    QLGTBS::Instance()->Add(this);
}

GiayToBoSung::GiayToBoSung(string _MaYeuCau, string _TenGiayToCanBoSung, string _ThoiDiemYeuCau, string _ThoiDiemBoSung, string _TinhTrang)
{
    this->MaYeuCau = _MaYeuCau;
    this->TenGiayToCanBoSung = _TenGiayToCanBoSung;
    this->ThoiDiemYeuCau = _ThoiDiemYeuCau;
    this->ThoiDiemBoSung = _ThoiDiemBoSung;
    this->TinhTrang = _TinhTrang;
    QLGTBS::Instance()->Add(this);
}
GiayToBoSung::~GiayToBoSung()
{
    QLGTBS::Instance()->Remove(this);
}
//================== NHAP THONG TIN GIAY TO CAN BO SUNG ========================
void GiayToBoSung::Scan()
{
    cout << "-> Nhap thong tin Giay to bo sung: " << endl;
    cout << "\tMa Yeu cau: ";
    fflush(stdin);
    cin.ignore();
    getline(cin, this->MaYeuCau);
    cout << "\tTen Giay to can bo sung: ";
    fflush(stdin);
    getline(cin, this->TenGiayToCanBoSung);
    cout << "\tThoi diem yeu cau bo sung: ";
    fflush(stdin);
    getline(cin, this->ThoiDiemYeuCau);
    cout << "\tThoi diem bo sung: ";
    fflush(stdin);
    getline(cin, this->ThoiDiemBoSung);
    cout << "\tTinh trang: ";
    fflush(stdin);
    getline(cin, this->TinhTrang);
}
void GiayToBoSung::Print()//Them
{
    cout << "| " << this->MaYeuCau;
    gotoxy(14, QLGTBS::yVal);
    cout << "| " << this->TenGiayToCanBoSung;
    gotoxy(37, QLGTBS::yVal);
    cout << "| " << this->ThoiDiemYeuCau;
    gotoxy(60, QLGTBS::yVal);
    cout << "| " << this->ThoiDiemBoSung;
    gotoxy(77, QLGTBS::yVal);
    cout << "| " << this->TinhTrang;
    gotoxy(90, QLGTBS::yVal);
    cout << "|";
    QLGTBS::yVal++;
}
GiayToBoSung GiayToBoSung::operator=(const GiayToBoSung& G)
{
    this->MaYeuCau = G.MaYeuCau;
    this->TenGiayToCanBoSung = G.TenGiayToCanBoSung;
    this->ThoiDiemYeuCau = G.ThoiDiemYeuCau;
    this->ThoiDiemBoSung = G.ThoiDiemBoSung;
    this->TinhTrang = G.TinhTrang;
    return *this;
}
void GiayToBoSung::Update() {
    cout << "-> Cap nhat Giay To Bo Sung: " << this->MaYeuCau << " - " << this->TenGiayToCanBoSung << endl;
    cout << "\tThoi diem yeu cau bo sung: ";
    fflush(stdin);
    getline(cin, this->ThoiDiemYeuCau);
    cout << "\tThoi diem bo sung: ";
    fflush(stdin);
    getline(cin, this->ThoiDiemBoSung);
    cout << "\tTinh trang: ";
    fflush(stdin);
    getline(cin, this->TinhTrang);
}
string GiayToBoSung::GetMaYeuCau() {
    return this->MaYeuCau;
}
string GiayToBoSung::GetName() {
    return this->TenGiayToCanBoSung;
}
string GiayToBoSung::GetTDYC() {
    return this->ThoiDiemYeuCau;
}
string GiayToBoSung::GetTDBS() {
    return this->ThoiDiemBoSung;
}
string GiayToBoSung::GetTinhTrang() {
    return this->TinhTrang;
}
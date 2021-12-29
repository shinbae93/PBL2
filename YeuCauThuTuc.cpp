#include"QLTT.h"

YeuCauThuTuc::YeuCauThuTuc()
{
    this->size = 0;
    this->TenGiayToCanBoSung = new string;
    this->MaYeuCau = "";
    this->MaCD = "";
    this->NoiDungYeuCau = "";
    this->MaLoaiTT = "";
    this->TrangThai = "";
    this->ThoiDiemTaoYeuCau = "";
    this->ThoiDiemHenTraKQ = "";
    this->ThoiDiemTraKQ = "";
    QLTT::Instance()->Add(this);
}
YeuCauThuTuc::YeuCauThuTuc(string _MaYeuCau, string _MaCD, string _NoiDungYeuCau, string _MaLoaiTT, string _ThoiDiemTaoYeuCau, string _ThoiDiemHenTraKQ, string _ThoiDiemTraKQ, string _TrangThai)
{
    this->size = 0;
    this->TenGiayToCanBoSung = new string;
    this->MaYeuCau = _MaYeuCau;
    this->MaCD = _MaCD;
    this->NoiDungYeuCau = _NoiDungYeuCau;
    this->MaLoaiTT = _MaLoaiTT;
    this->TrangThai = _TrangThai;
    this->ThoiDiemTaoYeuCau = _ThoiDiemTaoYeuCau;
    this->ThoiDiemHenTraKQ = _ThoiDiemHenTraKQ;
    this->ThoiDiemTraKQ = _ThoiDiemTraKQ;
    QLTT::Instance()->Add(this);
}
YeuCauThuTuc::~YeuCauThuTuc()
{
    delete[] TenGiayToCanBoSung;
    for(int i=0;i<QLCD::Instance()->GetSize();++i) {
        if(this->MaCD == (*QLCD::Instance())[i]->GetMaCD()) {
            (*QLCD::Instance())[i]->RemoveTT(this->MaYeuCau);
            break;
        }
    }
    for(int i=0;i<QLLTT::Instance()->GetSize();++i) {
        if(this->MaLoaiTT == (*QLLTT::Instance())[i]->GetMaLoaiTT()) {
            (*QLLTT::Instance())[i]->RemoveTT(this->MaYeuCau);
            break;
        }
    }
    QLTT::Instance()->Remove(this);
}
//=================== NHAP THONG TIN YEU CAU THU TUC ========================
void YeuCauThuTuc::Scan()
{
    cout << "-> Nhap thong tin Yeu cau thu tuc: " << endl;
    cout << "\tMa Yeu cau: ";
    fflush(stdin);
    getline(cin, this->MaYeuCau);
    cout << "\tMa Cong dan: ";
    fflush(stdin);
    getline(cin, this->MaCD);
    cout << "\tNoi dung yeu cau: ";
    fflush(stdin);
    getline(cin, this->NoiDungYeuCau);
    cout << "\tMa Loai thu tuc: ";
    fflush(stdin);
    getline(cin, this->MaLoaiTT);
    cout << "\tThoi diem tao yeu cau: ";
    fflush(stdin);
    getline(cin, this->ThoiDiemTaoYeuCau);
    cout << "\tThoi diem hen tra KQ: ";
    fflush(stdin);
    getline(cin, this->ThoiDiemHenTraKQ);
    cout << "\tThoi diem tra KQ: ";
    fflush(stdin);
    getline(cin, this->ThoiDiemTraKQ);
    cout << "\tTrang thai: ";
    fflush(stdin);
    getline(cin, this->TrangThai);
}
void YeuCauThuTuc::Print()
{
    cout << "| " << this->MaYeuCau;
    gotoxy(14, QLTT::yVal);
    cout << "| " << this->MaCD;
    gotoxy(27, QLTT::yVal);
    cout << "| " << this->NoiDungYeuCau;
    gotoxy(50, QLTT::yVal);
    cout << "| " << this->MaLoaiTT;
    gotoxy(63, QLTT::yVal);
    cout << "| " << this->ThoiDiemTaoYeuCau;
    gotoxy(77, QLTT::yVal);
    cout << "| " << this->ThoiDiemHenTraKQ;
    gotoxy(90, QLTT::yVal);
    cout << "| " << this->ThoiDiemTraKQ;
    gotoxy(100, QLTT::yVal);
    cout << "| " << this->TrangThai;
    gotoxy(113, QLTT::yVal);
    cout << "| ";
    QLTT::yVal++;
}
YeuCauThuTuc YeuCauThuTuc::operator=(const YeuCauThuTuc& Y)
{
    this->MaYeuCau = Y.MaYeuCau;
    this->MaCD = Y.MaCD;
    this->NoiDungYeuCau = Y.NoiDungYeuCau;
    this->MaLoaiTT = Y.MaLoaiTT;
    this->TrangThai = Y.TrangThai;
    this->ThoiDiemTaoYeuCau = Y.ThoiDiemTaoYeuCau;
    this->ThoiDiemHenTraKQ = Y.ThoiDiemHenTraKQ;
    this->TenGiayToCanBoSung = Y.TenGiayToCanBoSung;
    return *this;
}
string YeuCauThuTuc::GetMaYeuCau() {
    return this->MaYeuCau;
}
void YeuCauThuTuc::Update() {
    cout << "-> Cap nhat thong tin Yeu cau thu tuc: " << this->MaYeuCau << endl;
    cout << "\tMa Cong dan: ";
    fflush(stdin);
    getline(cin, this->MaCD);
    cout << "\tNoi dung yeu cau: ";
    fflush(stdin);
    getline(cin, this->NoiDungYeuCau);
    cout << "\tMa Loai thu tuc: ";
    fflush(stdin);
    getline(cin, this->MaLoaiTT);
    cout << "\tThoi diem tao yeu cau: ";
    fflush(stdin);
    getline(cin, this->ThoiDiemTaoYeuCau);
    cout << "\tThoi diem hen tra KQ: ";
    fflush(stdin);
    getline(cin, this->ThoiDiemHenTraKQ);
    cout << "\tThoi diem tra KQ: ";
    fflush(stdin);
    getline(cin, this->ThoiDiemTraKQ);
    cout << "\tTrang thai: ";
    fflush(stdin);
    getline(cin, this->TrangThai);
}
string YeuCauThuTuc::GetMaCD() {
    return this->MaCD;
}
string YeuCauThuTuc::GetNoiDung() {
    return this->NoiDungYeuCau;
}
string YeuCauThuTuc::GetMaLoaiTT() {
    return this->MaLoaiTT;
}
string YeuCauThuTuc::GetThoiDiemTao() {
    return this->ThoiDiemTaoYeuCau;
}
string YeuCauThuTuc::GetThoiDiemHen() {
    return this->ThoiDiemHenTraKQ;
}
string YeuCauThuTuc::GetThoiDiemTra() {
    return this->ThoiDiemTraKQ;
}
string YeuCauThuTuc::GetTrangThai() {
    return this->TrangThai;
}
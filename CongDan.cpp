#include"QLCD.h"

CongDan::CongDan()
{
    this->MaCD = "";
    this->HoTenCD = "";
    this->GioiTinh = 0;
    this->NgaySinh = "";
    this->HoTenChuHo = "";
    this->QuanHeVoiChuHo = "";
    this->MaYeuCau = new string;
    this->size = 0;
    QLCD::Instance()->Add(this);
}
CongDan::CongDan(string _MaCD, string _HoTenCD, bool _GioiTinh, string _NgaySinh, string _HoTenChuHo, string _QuanHeVoiChuHo)
{
    this->MaCD = _MaCD;
    this->HoTenCD = _HoTenCD;
    this->GioiTinh = _GioiTinh;
    this->NgaySinh = _NgaySinh;
    this->HoTenChuHo = _HoTenChuHo;
    this->QuanHeVoiChuHo = _QuanHeVoiChuHo;
    this->MaYeuCau = new string;
    this->size = 0;
    QLCD::Instance()->Add(this);
}
CongDan::~CongDan()
{
    QLCD::Instance()->Remove(this);
    delete this->MaYeuCau;
    this->size = 0;
}

//=========================== NHAP THONG TIN CONG DAN ===========================
void CongDan::Scan()
{
    cout << "-> Nhap thong tin Cong dan: " << endl;
    cout << "\tMa Cong dan: ";
    fflush(stdin);
    cin.ignore();
    getline(cin, this->MaCD);
    cout << "\tHo ten Cong dan: ";
    fflush(stdin);
    getline(cin, this->HoTenCD);
    cout << "\tGioi tinh (Nu = 0 || Nam = 1) : ";
    cin >> this->GioiTinh;
    cout << "\tNgay sinh: ";
    fflush(stdin);
    cin.ignore();
    getline(cin, this->NgaySinh);
    cout << "\tHo ten Chu ho: ";
    fflush(stdin);
    getline(cin, this->HoTenChuHo);
    cout << "\tQuan he voi Chu ho: ";
    fflush(stdin);
    getline(cin, this->QuanHeVoiChuHo);
}

void CongDan::Print()
{
    cout << "| " << this->MaCD;
    gotoxy(14, QLCD::yVal);
    cout << "| " << this->HoTenCD;
    gotoxy(37, QLCD::yVal);
    cout << "| " << (this->GioiTinh ? "Nam" : "Nu");
    gotoxy(48, QLCD::yVal);
    cout << "| " << this->NgaySinh;
    gotoxy(61, QLCD::yVal);
    cout << "| " << this->HoTenChuHo;
    gotoxy(84, QLCD::yVal);
    cout << "| " << this->QuanHeVoiChuHo;
    gotoxy(104, QLCD::yVal);
    cout << "| ";
    QLCD::yVal++;
}

CongDan CongDan::operator=(const CongDan C)
{
    this->MaCD = C.MaCD;
    this->HoTenCD = C.HoTenCD;
    this->GioiTinh = C.GioiTinh;
    this->NgaySinh = C.NgaySinh;
    this->HoTenChuHo = C.HoTenChuHo;
    this->QuanHeVoiChuHo = C.QuanHeVoiChuHo;
    this->MaYeuCau = C.MaYeuCau;
    this->size = C.size;
    return *this;
}

void CongDan::AddYC(const string& _MaYeuCau) 
{
    string* temp = new string[this->size + 1];
    for(int i = 0; i < this->size; ++i) {
        *(temp + i) = *(this->MaYeuCau + i);
    }
    *(temp + this->size) = _MaYeuCau;
    delete this->MaYeuCau;
    this->MaYeuCau = temp;
    this->size++;
}

void CongDan::RemoveTT(const string& _MaYeuCau) {
    int index = -1;
    for(int i=0;i<this->size;++i) {
        if(*(this->MaYeuCau + i) == _MaYeuCau) {
            index = i;
            break;
        }
    }
    if (index == -1) return;
    string* temp = new string[this->size - 1];
    for(int i=0;i<this->size;++i) {
        if(i < index) *(temp + i) = *(this->MaYeuCau + i);
        if(i > index) *(temp + i-1) = *(this->MaYeuCau + i);
    }
    delete MaYeuCau;
    this->MaYeuCau = new string[this->size - 1];
    this->MaYeuCau = temp;
    delete[] temp;
    this->size--;
}

void CongDan::Update() {
    cout << "-> Cap nhat thong tin Cong dan: " << this->MaCD << endl;
    cout << "\tHo ten Cong dan: ";
    fflush(stdin);
    getline(cin, this->HoTenCD);
    cout << "\tGioi tinh (Nu = 0 || Nam = 1) : ";
    cin >> this->GioiTinh;
    cout << "\tNgay sinh: ";
    fflush(stdin);
    cin.ignore();
    getline(cin, this->NgaySinh);
    cout << "\tHo ten Chu ho: ";
    fflush(stdin);
    getline(cin, this->HoTenChuHo);
    cout << "\tQuan he voi Chu ho: ";
    fflush(stdin);
    getline(cin, this->QuanHeVoiChuHo);
}

string CongDan::GetMaCD() {
    return this->MaCD;
}
string CongDan::GetName() {
    return this->HoTenCD;
}
string CongDan::GetGioiTinh() {
    return to_string(this->GioiTinh);
}
string CongDan::GetNgaySinh() {
    return this->NgaySinh;
}
string CongDan::GetNameChu() {
    return this->HoTenChuHo;
}
string CongDan::GetRelate() {
    return this->QuanHeVoiChuHo;
}
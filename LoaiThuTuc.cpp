#include"QLLTT.h"

LoaiThuTuc::LoaiThuTuc()
{   
    this->MaYeuCau = new string;
    this->MaLoaiTT = "";
    this->TenLoaiTT = "";
    this->ThoiHanTraKetQuaToiDa = 0;
    this->MucPhi = 0.0;
    QLLTT::Instance()->Add(this);
}

LoaiThuTuc::LoaiThuTuc(string _MaLoaiTT, string _TenLoaiTT, int _ThoiHan, float _MucPhi)
{
    this->MaYeuCau = new string;
    this->MaLoaiTT = _MaLoaiTT;
    this->TenLoaiTT = _TenLoaiTT;
    this->ThoiHanTraKetQuaToiDa = _ThoiHan;
    this->MucPhi = _MucPhi;
    QLLTT::Instance()->Add(this);
}

LoaiThuTuc::~LoaiThuTuc()
{
    delete this->MaYeuCau;
    QLLTT::Instance()->Remove(this);
}

//===================== NHAP THONG TIN LOAI THU TUC =====================
void LoaiThuTuc::Scan()
{
    cout << "\t->Ma Loai thu tuc: ";
    fflush(stdin);
    cin.ignore();
    getline(cin, this->MaLoaiTT);
    cout << "\tTen Loai thu tuc: ";
    fflush(stdin);
    getline(cin, this->TenLoaiTT);
    cout << "\tThoi han tra ket qua toi da: ";
    cin >> this->ThoiHanTraKetQuaToiDa;
    cout << "\tMuc phi: ";
    cin >> this->MucPhi;
}
void LoaiThuTuc::Print()
{
    cout << "| " << this->MaLoaiTT;
    gotoxy(14, QLLTT::yVal);
    cout << "| " << this->TenLoaiTT;
    gotoxy(37, QLLTT::yVal);
    cout << "| " << this->ThoiHanTraKetQuaToiDa;
    gotoxy(61, QLLTT::yVal);
    cout << "| " << this->MucPhi;
    gotoxy(70, QLLTT::yVal);
    cout << "|";
    QLLTT::yVal++;
}
LoaiThuTuc LoaiThuTuc::operator=(const LoaiThuTuc& L)
{
    this->MaLoaiTT = L.MaLoaiTT;
    this->TenLoaiTT = L.TenLoaiTT;
    this->ThoiHanTraKetQuaToiDa = L.ThoiHanTraKetQuaToiDa;
    this->MucPhi = L.MucPhi;
    return *this;
}
void LoaiThuTuc::AddYC(string& _MaYeuCau) {
    string* temp = new string[this->size + 1];
    for (int i = 0; i < this->size; ++i) {
        *(temp + i) = *(this->MaYeuCau + i);
    }
    *(temp + this->size) = _MaYeuCau;
    delete[] this->MaYeuCau;
    this->MaYeuCau = new string[this->size + 1];
    this->MaYeuCau = temp;
    delete[] temp;
    this->size++;
}
void LoaiThuTuc::RemoveTT(string _MaYeuCau) {
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
    delete this->MaYeuCau;
    this->MaYeuCau = new string[this->size - 1];
    this->MaYeuCau = temp;
    delete[] temp;
    this->size--;
}
void LoaiThuTuc::Update() {
    cout << "-> Cap nhat thong tin Loai thu tuc: " << this->MaLoaiTT << endl;
    cout << "\tTen Loai thu tuc: ";
    fflush(stdin);
    cin.ignore();
    getline(cin, this->TenLoaiTT);
    cout << "\tThoi han tra ket qua toi da: ";
    cin >> this->ThoiHanTraKetQuaToiDa;
    cout << "\tMuc phi: ";
    cin >> this->MucPhi;
}
string LoaiThuTuc::GetMaLoaiTT() {
    return this->MaLoaiTT;
}
string LoaiThuTuc::GetName() {
    return this->TenLoaiTT;
}
string LoaiThuTuc::GetThoiHan() {
    return to_string(this->ThoiHanTraKetQuaToiDa);
}
string LoaiThuTuc::GetMucPhi() {
    return to_string(this->MucPhi);
}
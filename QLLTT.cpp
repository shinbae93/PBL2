#pragma once
#include "QLLTT.h"

QLLTT* QLLTT::_Instance = nullptr;
QLLTT* QLLTT::Instance() {
    if (QLLTT::_Instance == nullptr) {
        QLLTT::_Instance = new QLLTT();
    }
    return QLLTT::_Instance;
}
QLLTT::QLLTT() {
    this->size = 0;
    this->data = nullptr;
}
QLLTT::~QLLTT() {
    delete[] this->data;
}
LoaiThuTuc* QLLTT::operator[](const int& index) {
    if(index >= 0 && index < this->size) 
        return *(this->data + index);
    return nullptr;
}
void QLLTT::Add(LoaiThuTuc* Type) {
    if(this->size == 0)
    {
        this->data = new LoaiThuTuc*[this->size + 1];
        *(this->data + this->size) = Type;
    }
    else
    {
        LoaiThuTuc* *temp = new LoaiThuTuc*[this->size];
        for(int i = 0; i < this->size; ++i)
        {
            *(temp + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new LoaiThuTuc*[this->size + 1];
        for(int i = 0; i < this->size; ++i)
        {
            *(this->data + i) = *(temp + i);
        }
        *(this->data + this->size) = Type;
        delete[] temp;
    }
    this->size++;
}
void QLLTT::Remove(LoaiThuTuc* Type) {
    int index = this->Find(Type->GetMaLoaiTT());
    if (index == -1) return;
    LoaiThuTuc** temp = new LoaiThuTuc*[this->size];
    for(int i=0; i < this->size; ++i) {
        *(temp + i) = *(this->data + i);
    }
    delete[] this->data;
    this->data = new LoaiThuTuc*[this->size - 1];
    for(int i=0; i < this->size; ++i) {
        if(i < index)
        {
            *(this->data + i) = *(temp + i);
        }
        else if(i > index)
        {
            *(this->data + i - 1) = *(temp + i);
        }
    }
    delete[] temp;
    this->size--;
}
int QLLTT::Find(string _MaCD) {
    try {
        for(int i=0;i<this->size;++i) {
            if((*(this->data + i))->GetMaLoaiTT() == _MaCD) return i;
        }
        throw 0;
    }
    catch(int) {
        cout << "Khong ton tai !!";
        return -1;
    }
}
int QLLTT::yVal = 4;
void QLLTT::Print() {
    if(this->size == 0)
    {
        cout << "\tDanh sach trong!!" << endl;
        return;
    }
    //cout << "\tDanh sach Loai Thu Tuc: " << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "| MaLoaiTT";
    gotoxy(14, 2);
    cout << "| TenLoaiTT";
    gotoxy(37, 2);
    cout << "| ThoiHanTraKetQuaToiDa";
    gotoxy(61, 2);
    cout << "| MucPhi";
    gotoxy(70, 2);
    cout << "|" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    QLLTT::yVal = 4;
    for(int i=0;i<this->size;++i) {
        (*(this->data + i))->Print();
        cout << endl;
    }
    cout << "----------------------------------------------------------------------" << endl;
}
LoaiThuTuc* QLLTT::Update() {
    cout << "Nhap Ma Loai Thu Tuc can chinh sua: " << endl;
    string _MaCD;
    fflush(stdin);
    getline(cin, _MaCD);
    int index = this->Find(_MaCD);
    if (index == -1) return nullptr;
    (*(this->data + index))->Update();
    return *(this->data + index);
}
LoaiThuTuc* QLLTT::Insert() {
    LoaiThuTuc *t = new LoaiThuTuc;
    t->Scan();
    return t;
}
LoaiThuTuc* QLLTT::Delete() {
    cout << "Nhap Ma LTT cua LTT can xoa: " << endl;
    string _MaCD;
    cin >> _MaCD;
    if (this->Find(_MaCD) == -1) return nullptr;
    this->Remove(*(this->data + this->Find(_MaCD)));
    return *(this->data + this->Find(_MaCD));
}
void QLLTT::Sort( int l, int r) {
    if (l <= r)
    {
        string key = this->data[(l + r) / 2]->GetMaLoaiTT();
        int i = l;
        int j = r;
        while (i <= j)
        {
            while ((*(this->data + i))->GetMaLoaiTT() < key)   i++;
            while ((*(this->data + j))->GetMaLoaiTT() > key)   j--;
            if (i <= j)
            {
                LoaiThuTuc* temp = *(this->data + j);
                *(this->data + j) = *(this->data + i);
                *(this->data + i) = temp;
                i++;
                j--;
            }
        }
        if (l < j)  Sort(l, j);
        if (r > i)  Sort(i, r);
    }
}
int QLLTT::GetSize() {
    return this->size;
}
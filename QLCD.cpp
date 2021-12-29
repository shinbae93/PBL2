#pragma once
#include "QLCD.h"

QLCD* QLCD::_Instance = nullptr;
QLCD* QLCD::Instance() {
    if (QLCD::_Instance == nullptr) {
        QLCD::_Instance = new QLCD();
    }
    return QLCD::_Instance;
}
QLCD::QLCD() {
    this->size = 0;
    this->data = nullptr;
}
QLCD::~QLCD() {
    this->size = 0;
    delete[] this->data;
}

void QLCD::Add(CongDan* CD) {
    if(this->size == 0)
    {
        this->data = new CongDan*[this->size + 1];
        *(this->data + this->size) = CD;
    }
    else
    {
        CongDan* *temp = new CongDan*[this->size];
        for(int i = 0; i < this->size; ++i)
        {
            *(temp + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new CongDan*[this->size + 1];
        for(int i = 0; i < this->size; ++i)
        {
            *(this->data + i) = *(temp + i);
        }
        this->data[this->size] = CD;
        delete[] temp;
    }
    this->size++;
}
int QLCD::Find(string _MaCD) {
   for(int i=0;i<this->size;++i) 
      if((*(this->data + i))->GetMaCD() == _MaCD) 
          return i;
   return -1;
}
void QLCD::Remove(CongDan* CD) {
    int index = this->Find(CD->GetMaCD());
    if (index == -1) return;
    CongDan** temp = new CongDan*[this->size];
    for(int i=0; i < this->size; ++i) {
        *(temp + i) = *(this->data + i);
    }
    delete[] this->data;
    this->data = new CongDan*[this->size - 1];
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
CongDan* QLCD::operator[](const int& index) {
    try {
        if(index >= 0 && index < this->size) return *(this->data + index);
        else {
            return nullptr;
            throw 0;
        }
    }
    catch(int) {
        cout << "Wrong Index !!";
    }
}
int QLCD::yVal = 4;
void QLCD::Print() {
    if(this->size == 0)
    {
        cout << "\tDanh sach trong!!" << endl;
        return;
    }
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << "MaCongDan";
    gotoxy(14, 2);
    cout << "| " << "HoTenCongDan";
    gotoxy(37, 2);
    cout << "| " << "GioiTinh";
    gotoxy(48, 2);
    cout << "| " << "NgaySinh";
    gotoxy(61, 2);
    cout << "| " << "HoTenChuHo";
    gotoxy(84, 2);
    cout << "| " << "QuanHeVoiChuHo";
    gotoxy(104, 2);
    cout << "| " << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    QLCD::yVal = 4;
    for(int i = 0; i < this->size; ++i) {
        (*(this->data + i))->Print();
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
}
CongDan* QLCD::Update() {
    cout << "Nhap Ma Cong Dan can chinh sua: " << endl;
    string _MaCD;
    fflush(stdin);
    cin.ignore();
    getline(cin, _MaCD);
    int index = this->Find(_MaCD);
    if (index == -1) {
        cout << "Khong ton tai";
        return nullptr;
    }
    (*(this->data + index))->Update();
    return (*(this->data + index));
}
CongDan* QLCD::Insert() {
    CongDan *t = new CongDan;
    t->Scan();
    return t;
}
CongDan* QLCD::Delete() {
    cout << "Nhap Ma CD cua cong dan can xoa: ";
    fflush(stdin);
    cin.ignore();
    string _MaCD;
    cin >> _MaCD;
    if (this->Find(_MaCD) == -1) return nullptr;
    this->Remove(*(this->data + this->Find(_MaCD)));
    return *(this->data + this->Find(_MaCD));
}
void QLCD::Sort(int l, int r) {
    if (l <= r)
    {
        string key = (*(this->data + (l + r)/2))->GetMaCD();
        int i = l;
        int j = r;
        while (i <= j)
        {
            while ((*(this->data + i))->GetMaCD() < key)   i++;
            while ((*(this->data + i))->GetMaCD() > key)   j--;
            if (i <= j)
            {
                CongDan* temp = *(this->data + j);
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
int QLCD::GetSize() {
    return this->size;
}
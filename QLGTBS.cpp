#include "QLGTBS.h"

QLGTBS* QLGTBS::_Instance = nullptr;
QLGTBS* QLGTBS::Instance() {
    if (QLGTBS::_Instance == nullptr) {
        QLGTBS::_Instance = new QLGTBS();
    }
    return QLGTBS::_Instance;
}
QLGTBS::QLGTBS() {
    this->size = 0;
    this->data = nullptr;
}
QLGTBS::~QLGTBS() {
    delete[] this->data;
}
void QLGTBS::Add(GiayToBoSung* s) {
    if(this->size == 0)
    {
        this->data = new GiayToBoSung*[this->size + 1];
        *(this->data + this->size) = s;
    }
    else
    {
        GiayToBoSung* *temp = new GiayToBoSung*[this->size];
        for(int i = 0; i < this->size; ++i)
        {
            *(temp + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new GiayToBoSung*[this->size + 1];
        for(int i = 0; i < this->size; ++i)
        {
            *(this->data + i) = *(temp + i);
        }
        *(this->data + this->size) = s;
        delete[] temp;
    }
    this->size++;
}
void QLGTBS::Remove(GiayToBoSung* s) {
    int index = this->Find(s->GetMaYeuCau(), s->GetName());
    if (index == -1) return;
    GiayToBoSung** temp = new GiayToBoSung*[this->size];
    for(int i=0; i < this->size; ++i) {
        *(temp + i) = *(this->data + i);
    }
    delete[] this->data;
    this->data = new GiayToBoSung*[this->size - 1];
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
int QLGTBS::Find(string _MaCD, string _Name) {
    for(int i=0;i<this->size;++i) 
        if((*(this->data + i))->GetMaYeuCau() == _MaCD && (*(this->data + i))->GetName() == _Name)
                return i;
    return -1;
}
int QLGTBS::yVal = 4;
void QLGTBS::Print() {
    if(this->size == 0)
    {
        cout << "\tDanh sach trong!!" << endl;
        return;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "| MaYeuCau";
    gotoxy(14, 2);
    cout << "| TenGiayToBoSung";
    gotoxy(37, 2);
    cout << "| ThoiDiemYeuCauBoSung";
    gotoxy(60, 2);
    cout << "| ThoiDiemBoSung";
    gotoxy(77, 2);
    cout << "| TinhTrang";
    gotoxy(90, 2);
    cout << "|" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    QLGTBS::yVal = 4;
    for(int i=0;i<this->size;++i) {
        (*(this->data + i))->Print();
        cout << endl;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
}
GiayToBoSung* QLGTBS::Update() {
    cout << "Nhap Ma Yeu Cau can chinh sua: ";
    string _MaCD;
    fflush(stdin);
    cin.ignore();
    getline(cin, _MaCD);
    cout << "Nhap Ten Giay To Bo Sung can chinh sua: ";
    string _Name;
    fflush(stdin);
    getline(cin, _Name);
    int index = this->Find(_MaCD, _Name);
    if (index == -1) return nullptr;
    (*(this->data + index))->Update();
    return *(this->data + index);
}
GiayToBoSung* QLGTBS::Insert() {
    GiayToBoSung *t = new GiayToBoSung;
    t->Scan();
    return t;
}
GiayToBoSung* QLGTBS::Delete() {
    cout << "Nhap Ma Yeu Cau can xoa: ";
    string _MaCD;
    fflush(stdin);
    cin.ignore();
    getline(cin, _MaCD);
    cout << "Nhap Ten Giay To Bo Sung can xoa: ";
    string _Name;
    fflush(stdin);
    cin.ignore();
    getline(cin, _Name);
    if (this->Find(_MaCD, _Name) == -1) return nullptr;
    this->Remove(*(this->data + this->Find(_MaCD, _Name)));
    return *(this->data + this->Find(_MaCD, _Name));
}
void QLGTBS::Sort(int l, int r) {
    if (l <= r)
    {
        string key = (*(this->data + (l + r)/2))->GetMaYeuCau();
        int i = l;
        int j = r;
        while (i <= j)
        {
            while ((*(this->data + i))->GetMaYeuCau() < key)   i++;
            while ((*(this->data + i))->GetMaYeuCau() > key)   j--;
            if (i <= j)
            {
                GiayToBoSung* temp = *(this->data + j);
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
int QLGTBS::GetSize() {
    return this->size;
}
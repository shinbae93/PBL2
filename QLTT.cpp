#include "QLTT.h"

QLTT* QLTT::_Instance = nullptr;
QLTT* QLTT::Instance() {
    if (QLTT::_Instance == nullptr) {
        QLTT::_Instance = new QLTT();
    }
    return QLTT::_Instance;
}
QLTT::QLTT() {
    this->size = 0;
    this->data = new YeuCauThuTuc*;
}
QLTT::~QLTT() {
    this->size = 0;
    delete[] this->data;
}
int QLTT::yVal = 4;
void QLTT::Print() {
    if (this->size == 0)
    {
        cout << "\tDanh sach trong!!" << endl;
        return;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << "MaYeuCau";
    gotoxy(14, 2);
    cout << "| " << "MaCD";
    gotoxy(27, 2);
    cout << "| " << "NoiDungYeuCau";
    gotoxy(50, 2);
    cout << "| " << "MaLoaiTT";
    gotoxy(63, 2);
    cout << "| " << "TGTaoYeuCau";
    gotoxy(77, 2);
    cout << "| " << "TGHenTraKQ";
    gotoxy(90, 2);
    cout << "| " << "TGTraKQ";
    gotoxy(100, 2);
    cout << "| " << "TrangThai";
    gotoxy(113, 2);
    cout << "| " << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    QLTT::yVal = 4;
    for(int i = 0; i < this->size; ++i) {
        (*(this->data + i))->Print();
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}
void QLTT::Add(YeuCauThuTuc* TT) {
    if(this->size == 0)
    {
        this->data = new YeuCauThuTuc*[this->size + 1];
        *(this->data + this->size) = TT;
    }
    else
    {
        YeuCauThuTuc* *temp = new YeuCauThuTuc*[this->size];
        for(int i = 0; i < this->size; ++i)
        {
            *(temp + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new YeuCauThuTuc*[this->size + 1];
        for(int i = 0; i < this->size; ++i)
        {
            *(this->data + i) = *(temp + i);
        }
        this->data[this->size] = TT;
        delete[] temp;
    }
    this->size++;
}
void QLTT::Remove(YeuCauThuTuc* TT) {
    int index = this->Find(TT->GetMaYeuCau());
    if (index == -1) return;
    YeuCauThuTuc** temp = new YeuCauThuTuc*[this->size];
    for(int i=0; i < this->size; ++i) {
        *(temp + i) = *(this->data + i);
    }
    delete[] this->data;
    this->data = new YeuCauThuTuc*[this->size - 1];
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
int QLTT::Find(string _MaCD) {
    for(int i=0;i<this->size;++i) 
        if((*(this->data + i))->GetMaYeuCau() == _MaCD) return i;   
    return -1;
}
YeuCauThuTuc* QLTT::Update() {
    cout << "Nhap Ma Yeu Cau cua Thu Tuc can chinh sua: " << endl;
    string _MaCD;
    fflush(stdin);
    getline(cin, _MaCD);
    if (this->Find(_MaCD) == -1) return nullptr;
    (*(this->data + this->Find(_MaCD)))->Update();
    return *(this->data + this->Find(_MaCD));
}
YeuCauThuTuc* QLTT::Insert() {
    YeuCauThuTuc *t = new YeuCauThuTuc;
    t->Scan();
    return t;
}
YeuCauThuTuc* QLTT::Delete() {
    cout << "Nhap Ma Yeu Cau cua Thu Tuc can xoa: " << endl;
    string _MaCD;
    cin >> _MaCD;
    if (this->Find(_MaCD) == -1) return nullptr;
    this->Remove(*(this->data + this->Find(_MaCD)));
    return *(this->data + this->Find(_MaCD));
}
void QLTT::Sort(int l, int r) {
        if (l <= r)
        {
            string key = (*(this->data + (l + r)/2))->GetMaYeuCau();
            int i = l;
            int j = r;
            while (i <= j)
            {
                while ((*(this->data + i))->GetMaYeuCau() < key)   i++;
                while ((*(this->data + j))->GetMaYeuCau() > key)   j--;
                if (i <= j)
                {
                    YeuCauThuTuc* temp = *(this->data + j);
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
int QLTT::GetSize() {
    return this->size;
}
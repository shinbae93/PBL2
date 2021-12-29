#pragma once
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

class LoaiThuTuc
{
    string MaLoaiTT;
    string TenLoaiTT;
    int ThoiHanTraKetQuaToiDa; //So ngay
    float MucPhi;
    string* MaYeuCau;
    int size;

    public:
        LoaiThuTuc();
        LoaiThuTuc(string, string, int, float);
        ~LoaiThuTuc();
        void AddYC(string&S);
        void RemoveTT(string);
        void Update();
        void Scan();
        void Print();
        LoaiThuTuc operator=(const LoaiThuTuc&);
    public:
        string GetMaLoaiTT();
        string GetName();
        string GetThoiHan();
        string GetMucPhi();

};
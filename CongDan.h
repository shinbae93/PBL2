#pragma once
#include<iostream>
#include<string>
using namespace std;

class CongDan
{
    string MaCD;
    string HoTenCD;
    bool GioiTinh;
    string NgaySinh;
    string HoTenChuHo;
    string QuanHeVoiChuHo;
    string* MaYeuCau;
    int size;

    public:
        CongDan();
        CongDan(string , string, bool, string, string, string);
        ~CongDan();
        void AddYC(const string&);
        void RemoveTT(const string&);
        void Update();
        void Scan();
        void Print();
        CongDan operator=(const CongDan);
    public:
        string GetMaCD();
        string GetName();
        string GetGioiTinh();
        string GetNgaySinh();
        string GetNameChu();
        string GetRelate();
};
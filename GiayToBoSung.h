#pragma once
#include<string>
#include<iostream>
using namespace std;

class GiayToBoSung
{
    string MaYeuCau;
    string TenGiayToCanBoSung;
    string ThoiDiemYeuCau;
    string ThoiDiemBoSung;
    string TinhTrang; // true - Da bo sung, false - Chua bo sung

    public:
        GiayToBoSung();
        GiayToBoSung(string, string, string, string = "", string = "");
        ~GiayToBoSung();
        void Update();
        void Scan();
        void Print();
        GiayToBoSung operator=(const GiayToBoSung&);
    public:
        string GetMaYeuCau();
        string GetName();
        string GetTDYC();
        string GetTDBS();
        string GetTinhTrang();
};
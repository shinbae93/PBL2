#pragma once
#include "QLCD.h"
#include "QLLTT.h"

class YeuCauThuTuc
{   
    string MaYeuCau;
    string MaCD;
    string NoiDungYeuCau;
    string MaLoaiTT;
    string ThoiDiemTaoYeuCau;
    string ThoiDiemHenTraKQ;
    string ThoiDiemTraKQ;
    string TrangThai;
    string* TenGiayToCanBoSung;
    int size;

    public:
        YeuCauThuTuc();
        YeuCauThuTuc(string, string, string, string, string, string, string, string);
        ~YeuCauThuTuc();
        void Update();
        void Scan();
        void Print();
        YeuCauThuTuc operator=(const YeuCauThuTuc&);
    public:
        string GetMaYeuCau();
        string GetMaCD();
        string GetNoiDung();
        string GetMaLoaiTT();
        string GetThoiDiemTao();
        string GetThoiDiemHen();
        string GetThoiDiemTra();
        string GetTrangThai();
};
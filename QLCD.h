#pragma once
#include "CongDan.h"
#include "GiaoDien.h"
class QLCD {
    CongDan** data;
    int size;
    static QLCD* _Instance;
    QLCD();

    public:
        static int yVal;
		~QLCD();
		static QLCD* Instance();
        void Add(CongDan*);
        void Remove(CongDan*);
        int GetSize();
        int Find(string);
        void Print();
		CongDan* Update();
		CongDan* Insert();
		CongDan* Delete();
        void Sort(int, int);
        CongDan* operator[](const int&);
};

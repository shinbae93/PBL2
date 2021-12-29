#pragma once
#include "LoaiThuTuc.h"
#include "GiaoDien.h" 

class QLLTT {
    LoaiThuTuc** data;
    int size;
    static QLLTT* _Instance;
    QLLTT();
    
    public:
        static int yVal;
		~QLLTT();
		static QLLTT* Instance();
        int GetSize();
        void Add(LoaiThuTuc*);
        void Remove(LoaiThuTuc*);
        int Find(string);
        void Print();
		LoaiThuTuc* Update();
		LoaiThuTuc* Insert();
		LoaiThuTuc* Delete();
        void Sort(int, int);
        LoaiThuTuc* operator[](const int&);
};

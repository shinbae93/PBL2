#pragma once
#include "YeuCauThuTuc.h"
#include "GiaoDien.h"
class QLTT {
	YeuCauThuTuc** data;
	int size;
	static QLTT* _Instance;
	QLTT();

	public:
		static int yVal;
		~QLTT();
		static QLTT* Instance();
		int GetSize();
        void Add(YeuCauThuTuc*);
        void Remove(YeuCauThuTuc*);
		int Find(string);
		YeuCauThuTuc* Update();
		void Print();
		YeuCauThuTuc* Insert();
		void Sort(int, int);
		YeuCauThuTuc* Delete();
};
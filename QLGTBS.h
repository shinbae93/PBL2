#pragma once
#include "GiayToBoSung.h"
#include "GiaoDien.h"
class QLGTBS {
	GiayToBoSung** data;
	int size;
	static QLGTBS* _Instance;
	QLGTBS();

public:
	static int yVal;
	~QLGTBS();
	static QLGTBS* Instance();
	void Add(GiayToBoSung*);
	void Remove(GiayToBoSung*);
	int Find(string, string);
	int GetSize();
	void Print();
	GiayToBoSung* Update();
	GiayToBoSung* Insert();
	GiayToBoSung* Delete();
	void Sort(int, int);
};
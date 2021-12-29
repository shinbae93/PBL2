#pragma once

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <stdlib.h>
#include "QLTT.h"
#include "QLGTBS.h"
#include "CongDan.h"
#include "LoaiThuTuc.h"
#include "GiayToBoSung.h"
#include "YeuCauThuTuc.h"

class DBHelper
{
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1024
	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

public:
	void init();
	int ExecDirect(string);
	void Insert(CongDan*);
	void Insert(YeuCauThuTuc*);
	void Insert(LoaiThuTuc*);
	void Insert(GiayToBoSung*);
	void Select(CongDan*&, int&);
	void Select(YeuCauThuTuc*&, int&);
	void Select(LoaiThuTuc*&, int&);
	void Select(GiayToBoSung*&, int&);
	void Update(CongDan*);
	void Update(LoaiThuTuc*);
	void Update(YeuCauThuTuc*);
	void Update(GiayToBoSung*);
	void Delete(CongDan*);
	void Delete(YeuCauThuTuc*);
	void Delete(LoaiThuTuc*);
	void Delete(GiayToBoSung*);
	void close();

};

#include "DBHelper.h"
#include<iomanip>
#include<conio.h>

void DBHelper::init()
{

	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		close();

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		close();

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		close();

	cout << "Attempting connection to SQL Server...";
	cout << "\n";
	switch (SQLDriverConnect(sqlConnHandle, NULL,(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=DESKTOP-15ST2P9;DATABASE=demo2;Trusted = true;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_INVALID_HANDLE:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	case SQL_ERROR:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	default:
		break;
	}
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		close();
}

int DBHelper::ExecDirect(string s)
{
	SQLWCHAR* query = new SQLWCHAR[s.length() + 1];
	for (int i = 0; i < int(s.length()); i++)
		query[i] = s[i];
	query[s.length()] = 0;
	int a = SQLExecDirect(sqlStmtHandle, query, SQL_NTS);
	delete[] query;
	return a;
}
void DBHelper::Select(CongDan*& CDs, int& size) 
{	
	cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";
	string Query = "SELECT * FROM CongDan";

	if (SQL_SUCCESS != ExecDirect(Query)) {
		size = 0;
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		
		SQLINTEGER ptrSqlVersion;
		char _MaCD[10] = "";
		char _Name[30] = "";
		bool _GioiTinh = 0;	
		char _NgaySinh[10] = "";
		char _NameChu[30] = "";
		char _Relate[15] = "";
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, _MaCD,  10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, _Name, 30, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_BIT, &_GioiTinh, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, _NgaySinh,  10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, _NameChu, 30, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, _Relate, 15, &ptrSqlVersion);

			CongDan *CD = new CongDan(string(_MaCD), string(_Name), _GioiTinh, string(_NgaySinh), string(_NameChu), string(_Relate));
			*(CDs + i) = *CD;
			i++;
		}	
		size = i;
	}
	SQLCancel(sqlStmtHandle);
}

void DBHelper::Select(YeuCauThuTuc*& TTs, int& size) 
{
	cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";
	string Query = "SELECT * FROM YeuCauThuTuc";

	if (SQL_SUCCESS != ExecDirect(Query)) {
		size = 0;
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		
		SQLINTEGER ptrSqlVersion;
		char _MaYeuCau[10] = "";
		char _MaCD[10] = "";
		char _NoiDung[30] = "";
		char _MaLoaiTT[10] = "";
		char _ThoiDiemTao[10] = "";
		char _ThoiDiemHenTra[10] = "";
		char _ThoiDiemTra[10] = "";
		char _TrangThai[10] = "";
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, _MaYeuCau,  10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, _MaCD, 10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, _NoiDung, 30, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, _MaLoaiTT,  10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, _ThoiDiemTao, 10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, _ThoiDiemHenTra, 10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_CHAR, _ThoiDiemTra,  10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_CHAR, _TrangThai, 10, &ptrSqlVersion);
			YeuCauThuTuc *TT = new YeuCauThuTuc(string(_MaYeuCau), string(_MaCD), string(_NoiDung), string(_MaLoaiTT), string(_ThoiDiemTao), string(_ThoiDiemHenTra), string(_ThoiDiemTra), string(_TrangThai));
			*(TTs + i) = *TT;
			i++;
		}	
		size = i;
	}
	SQLCancel(sqlStmtHandle);
}

void DBHelper::Select(LoaiThuTuc*& LTTs, int& size) 
{
	cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";
	string Query = "SELECT * FROM LoaiThuTuc";

	if (SQL_SUCCESS != ExecDirect(Query)) {
		size = 0;
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
	
		SQLINTEGER ptrSqlVersion;
		char _MaLoaiTT[10] = "";
		char _Name[30] = "";
		int _ThoiHan = 0;
		float _MucPhi = 0.0;
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, _MaLoaiTT,  10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, _Name, 30, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_INTEGER, &_ThoiHan, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_C_FLOAT, &_MucPhi, SQL_RESULT_LEN, &ptrSqlVersion);
			
			LoaiThuTuc *LTT = new LoaiThuTuc(string(_MaLoaiTT), string(_Name), _ThoiHan, _MucPhi);
			*(LTTs + i) = *LTT;
			i++;
		}	
		size = i;
	}
	SQLCancel(sqlStmtHandle);
}

void DBHelper::Select(GiayToBoSung*& GTBSs, int& size) 
{
	cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";
	string Query = "SELECT * FROM GiayToBoSung";

	if (SQL_SUCCESS != ExecDirect(Query)) {
		size = 0;
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		SQLINTEGER ptrSqlVersion;
		char _MaYeuCau[10] = "";
		char _Name[30] = "";
		char _ThoiDiemYeuCau[10] = "";
		char _ThoiDiemBoSung[10] = "";
		char _TinhTrang[10] = "";
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, _MaYeuCau,  10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, _Name, 30, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, _ThoiDiemYeuCau, 10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, _ThoiDiemBoSung,  10, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, _TinhTrang, 10, &ptrSqlVersion);

			GiayToBoSung *GTBS = new GiayToBoSung(string(_MaYeuCau), string(_Name), string(_ThoiDiemYeuCau), string(_ThoiDiemBoSung), string(_TinhTrang));
			*(GTBSs + i) = *GTBS;
			i++;
		}	
		size = i;
	}
	SQLCancel(sqlStmtHandle);
}
void DBHelper::Insert(CongDan* CD)
{
	string s = "INSERT INTO CongDan VALUES(";
	string s1 = "'" + CD->GetMaCD() + "',";
	string s2 = "'" + CD->GetName() + "',";
	string s3 = "'" + CD->GetGioiTinh() + "',";
	string s4 = "'" + CD->GetNgaySinh() + "',";
	string s5 = "'" + CD->GetNameChu() + "',";
	string s6 = "'" + CD->GetRelate() + "')";

	s = s + s1 + s2 + s3 + s4 + s5 + s6;
	char* m = new char[s.length()+1];
	strcpy_s(m, s.length()+1, s.c_str());

	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle,(SQLCHAR*)m , SQL_NTS)) {

		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		delete[] m;
		close();
	}
	else {

		cout << "\nINSERT SUCCESS";
		delete[] m;
		return;
	}
}

void DBHelper::Insert(YeuCauThuTuc* TT)
{
	string s = "INSERT INTO YeuCauThuTuc VALUES(";
	string s1 = "'" + TT->GetMaYeuCau() + "',";
	string s2 = "'" + TT->GetMaCD() + "',";
	string s3 = "'" + TT->GetNoiDung() + "',";
	string s4 = "'" + TT->GetMaLoaiTT() + "',";
	string s5 = "'" + TT->GetThoiDiemTao() + "',";
	string s6 = "'" + TT->GetThoiDiemHen() + "',";
	string s7 = "'" + TT->GetThoiDiemTra() + "',";
	string s8 = "'" + TT->GetTrangThai() + "')";

	s = s + s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8;
	char* m = new char[s.length()+1];
	strcpy_s(m, s.length()+1, s.c_str());

	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle,(SQLCHAR*)m , SQL_NTS)) {

		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		delete[] m;
		close();
	}
	else {

		cout << "\nINSERT SUCCESS";
		delete[] m;
		return;
	}
}
void DBHelper::Insert(LoaiThuTuc* LTT)
{
	string s = "INSERT INTO LoaiThuTuc VALUES(";
	string s1 = "'" + LTT->GetMaLoaiTT() + "',";
	string s2 = "'" + LTT->GetName() + "',";
	string s3 = "" + LTT->GetThoiHan() + ",";
	string s4 = "" + LTT->GetMucPhi() + ")";

	s = s + s1 + s2 + s3 + s4;
	char* m = new char[s.length()+1];
	strcpy_s(m, s.length()+1, s.c_str());

	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle,(SQLCHAR*)m , SQL_NTS)) {

		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		delete[] m;
		close();
	}
	else {

		cout << "\nINSERT SUCCESS";
		delete[] m;
		return;
	}
}
void DBHelper::Insert(GiayToBoSung* GTBS)
{
	string s = "INSERT INTO GiayToBoSung VALUES(";
	string s1 = "'" + GTBS->GetMaYeuCau() + "',";
	string s2 = "'" + GTBS->GetName() + "',";
	string s3 = "'" + GTBS->GetTDYC() + "',";
	string s4 = "'" + GTBS->GetTDBS() + "',";
	string s5 = "'" + GTBS->GetTinhTrang() + "')";

	s = s + s1 + s2 + s3 + s4 + s5;
	char* m = new char[s.length()+1];
	strcpy_s(m, s.length()+1, s.c_str());

	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle,(SQLCHAR*)m , SQL_NTS)) {

		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		delete[] m;
		close();
	}
	else {

		cout << "\nINSERT SUCCESS";
		delete[] m;
		return;
	}
}

void DBHelper::Update(CongDan* CD)
{	
	string Query = "UPDATE CongDan SET HoTenCD = '" + CD->GetName() + 
	"', " + "GioiTinh = " + CD->GetGioiTinh() + 
	", " + "NgaySinh = '" + CD->GetNgaySinh() + 
	"', " + "HoTenChuHo = '" + CD->GetNameChu() + 
	"', " + "QuanHeVoiChuHo = '" + CD->GetRelate() + 
	"' WHERE MaCD = '" + CD->GetMaCD() + "'";

	if (SQL_SUCCESS != ExecDirect(Query))
	{
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else
	{
		cout << "\nUPDATE SUCCESS" << endl;
		return;
	}
	SQLCancel(sqlStmtHandle);
}
void DBHelper::Update(LoaiThuTuc* LTT)
{
	string Query = "UPDATE LoaiThuTuc SET TenLoaiTT = '" + LTT->GetName() + 
	"', " + "ThoiHanTraKetQuaToiDa = " + LTT->GetThoiHan() + 
	", " + "MucPhi = " + LTT->GetMucPhi() +  
	" WHERE MaCD = '" + LTT->GetMaLoaiTT() + "'";
	if (SQL_SUCCESS != ExecDirect(Query))
	{
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else
	{
		cout << "\nUPDATE SUCCESS" << endl;
		return;
	}
	SQLCancel(sqlStmtHandle);
}
void DBHelper::Update(YeuCauThuTuc* TT)
{
	string Query = "UPDATE YeuCauThuTuc SET MaCD = '" + TT->GetMaCD() + 
	"', " + "NoiDungYeuCau = " + TT->GetNoiDung() + 
	", " + "MaLoaiTT = '" + TT->GetMaLoaiTT() + 
	"', " + "ThoiDiemTaoYeuCau = '" + TT->GetThoiDiemTao() + 
	"', " + "ThoiDiemHenTraKQ = '" + TT->GetThoiDiemHen() + 
	"', " + "ThoiDiemTraKQ = '" + TT->GetThoiDiemTra() + 
	"', " + "TrangThai = '" + TT->GetTrangThai() + 
	"' WHERE MaYeuCau = '" + TT->GetMaYeuCau() + "'";
	if (SQL_SUCCESS != ExecDirect(Query))
	{
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else
	{
		cout << "\nUPDATE SUCCESS" << endl;
		return;
	}
	SQLCancel(sqlStmtHandle);
}
void DBHelper::Update(GiayToBoSung* GTBS)
{
	string Query = "UPDATE GiayToBoSung SET ThoiDiemYeuCauBoSung = '" + GTBS->GetTDYC() + 
	"', " + "ThoiDiemBoSung = " + GTBS->GetTDBS() + 
	", " + "TinhTrang = '" + GTBS->GetTinhTrang() + 
	"' WHERE MaYeuCau = '" + GTBS->GetMaYeuCau() + "'" +
	" AND TenGiayToCanBoSung = '" + GTBS->GetName() + "'";
	if (SQL_SUCCESS != ExecDirect(Query))
	{
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else
	{
		cout << "\nUPDATE SUCCESS" << endl;
		return;
	}
	SQLCancel(sqlStmtHandle);
}
void DBHelper::Delete(CongDan* CD)
{	
	string Query = "DELETE FROM CongDan WHERE MaCD = '" + CD->GetMaCD() + "'";

	if (SQL_SUCCESS != ExecDirect(Query)) {
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {

		cout << "\nDELETE SUCCESS";
		return;
	}
	SQLCancel(sqlStmtHandle);
}
void DBHelper::Delete(YeuCauThuTuc* TT)
{
	string Query = "DELETE FROM YeuCauThuTuc WHERE MaCD = '" + TT->GetMaYeuCau() + "'";

	if (SQL_SUCCESS != ExecDirect(Query)) {
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {

		cout << "\nDELETE SUCCESS";
		return;
	}
	SQLCancel(sqlStmtHandle);
}
void DBHelper::Delete(LoaiThuTuc* LTT)
{
	string Query = "DELETE FROM LoaiThuTuc WHERE MaLoaiTT = '" + LTT->GetMaLoaiTT() + "'";

	if (SQL_SUCCESS != ExecDirect(Query)) {
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {

		cout << "\nDELETE SUCCESS";
		return;
	}
	SQLCancel(sqlStmtHandle);
}
void DBHelper::Delete(GiayToBoSung* GTBS)
{
	string Query = "DELETE FROM GiayToBoSung WHERE MaCD = '" + GTBS->GetMaYeuCau() + "'" + " AND " + "'" + GTBS->GetName() + "'";

	if (SQL_SUCCESS != ExecDirect(Query)) {
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {

		cout << "\nDELETE SUCCESS";
		return;
	}
	SQLCancel(sqlStmtHandle);
}
void DBHelper::close()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	system("pause");
	exit(0);
}
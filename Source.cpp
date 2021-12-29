#include "QLTT.h"
#include "QLGTBS.h"
#include "DBHelper.h"
//#include "GiaoDien.h"

DBHelper db;

template<class T>
void ChonCongViec()
{
	cout << "\t 1. Hien thi"<< endl;
    cout << "\t 2. Sap xep" << endl;
    cout << "\t 3. Them"<< endl;
    cout << "\t 4. Sua"<< endl;
    cout << "\t 5. Xoa"<< endl;
    cout << "\t 0. Quay lai"<< endl;
    cout << "\t Chon cong viec [1/2/3/4/5/0] : ";
    int job;
    cin >> job;
    switch (job)
    {
        case 1:
            system("cls");
            T::Instance()->Print();
            system("pause");
            system("cls");
            break;
        case 2:
        {
            T::Instance()->Sort(0, T::Instance()->GetSize() - 1);
            cout << "Sort Success !";
        }
            break;
        case 3:
            db.Insert(T::Instance()->Insert());
            break;
        case 4:
            db.Update(T::Instance()->Update());
            break;
        case 5:
        {
            T::Instance()->Delete();
            cout << "\nDELETE SUCCESS";
        }
            break;
        case 0:
            break;
        default:
            cout << "Ban da nhap sai, moi ban nhap lai !!!" << endl;
            break;
    }
}
void Menu()
{
    cout << "\t**************************************" << endl;
    cout << "\t||   PROCEDURE MANAGERMENT SYSTEM   ||" << endl;
    cout << "\t**************************************" << endl;
    while(1) {
		cout << "\t------------------------------------" <<endl;
        cout << "\t 1. Cong Dan" << endl;
		cout << "\t 2. Yeu Cau Thu Tuc" << endl;
		cout << "\t 3. Loai Thu Tuc" << endl;
		cout << "\t 4. Giay To Bo Sung" << endl;
		cout << "\t 0. Exit" << endl;
		cout << "\t Chon bang [1/2/3/4/0] : ";
        int input;
        cin >> input;
		cout << "\t------------------------------------" <<endl;
        switch (input)
        {
            case 1:
            {
                cout << "\t-> Bang Cong Dan: " << endl;
                ChonCongViec<QLCD>();
            }
                break;
            case 2:
            {
                cout << "\t-> Bang Yeu Cau Thu Tuc: " << endl;
                ChonCongViec<QLTT>();
            }
                break;
            case 3:
            {
                cout << "\t-> Bang Loai Thu Tuc: " << endl;
                ChonCongViec<QLLTT>();
            }
                break;
            case 4:
            {
                cout << "\t-> Bang Giay To Bo Sung: " << endl;
                ChonCongViec<QLGTBS>();
            }
                break;
            case 0:
            {
                cout << "Thoat chuong trinh ... !!!";
                return;
            }
            default:
                cout << "Ban da nhap sai, moi ban nhap lai!!" << endl;
                break;
        }
    }
}
int main()
{   
    db.init();
    CongDan* CD1 = new CongDan("CD001", "Tri", 1, "2001-03-09", "Hieu", "Cha");
    CongDan* CD2 = new CongDan("CD002", "Tri", 1, "2001-03-09", "Hieu", "Cha");
    CongDan* CD3 = new CongDan("CD003", "Tri", 1, "2001-03-09", "Hieu", "Cha");
    CongDan* CD4 = new CongDan("CD004", "Tri", 1, "2001-03-09", "Hieu", "Cha");
    CongDan* CD5 = new CongDan("CD005", "Tri", 1, "2001-03-09", "Hieu", "Cha");
    CongDan* CD6 = new CongDan("CD007", "Tri", 1, "2001-03-09", "Hieu", "Cha");
    LoaiThuTuc* TT1 = new LoaiThuTuc("TT001", "Khai sinh", 21, 6);
    LoaiThuTuc* TT2 = new LoaiThuTuc("TT002", "Khai sinh", 21, 6);
    GiayToBoSung* BS1 = new GiayToBoSung("YC001", "CMND", "01/01/2001", "02/01/2001", "Tre");
    GiayToBoSung* BS2 = new GiayToBoSung("YC002", "CMND", "01/01/2000", "02/01/2001", "Dung han");
    YeuCauThuTuc* YC1 = new YeuCauThuTuc("YC001", "CD001", "Lam giay khai sinh", "TT001", "02/12/2001", "02/12/2002", "20/12/2001", "Tre");
    //YeuCauThuTuc* YC1 = new YeuCauThuTuc();
    //YeuCauThuTuc* YC2 = new YeuCauThuTuc();
    //YeuCauThuTuc* YC2 = new YeuCauThuTuc("YC002", "CD002", "Lam giay khai sinh", "TT001", "02/12/2001", "02/12/2002", "20/12/2001", "Dung han");
    //db.Delete(CD);
    //QLTT::Instance()->Print();
    Menu();
    /*QLGTBS::Instance()->Insert();
    system("cls");
    QLGTBS::Instance()->Print();
    system("pause");
    */
    db.close();
    return 0;
}
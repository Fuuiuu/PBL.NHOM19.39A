#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
using namespace std;

class KHACHHANG {
public:
    int ID;
    string TEN;
    int TUOI;
    bool GIOITINH;
    string TINHTRANG;
    string DICHVU[6];
};

void docFile(FILE *f, KHACHHANG *DS, int &id)
    {
    char buffer[256];
    int dv;
    while (fgets(buffer, sizeof(buffer), f) != NULL)
       {
        DS[id].ID = id+1;
        DS[id].TEN = string(buffer);
        DS[id].TEN.pop_back();

        fgets(buffer, sizeof(buffer), f);
        DS[id].TUOI = atoi(buffer);

        fgets(buffer, sizeof(buffer), f);
        DS[id].GIOITINH = (buffer[0] == '1');

        fgets(buffer, sizeof(buffer), f);
        DS[id].TINHTRANG = string(buffer);
        DS[id].TINHTRANG.pop_back();

        dv = 0;
        while (fgets(buffer, sizeof(buffer), f) != NULL && dv < 6) 
        {
            if (buffer[0] == '\n' || buffer[0] == '7') break;
            DS[id].DICHVU[dv] = string(buffer);
            DS[id].DICHVU[dv].pop_back();
            dv++;
        }
        id++;
    }
}

void themKhachHang(KHACHHANG *DS, int &id) {
    int n, dv;
    cout << "=== Nhập thông tin khách hàng ===" << endl;
    DS[id].ID = id+1;
    cout << "Tên: ";
    getline(cin >> ws, DS[id].TEN);

    while (true) {
        cout << "Tuổi: ";
        cin >> DS[id].TUOI;
        if (DS[id].TUOI > 0 && DS[id].TUOI < 100) break;
        else {
            cout << "SỐ TUỔI KHÔNG PHÙ HỢP!" << endl; 
            }
    }

    while (true) {
        cout << "-- Giới Tính --" << endl;
        cout << "1.Nam" << endl;
        cout << "2.Nữ" << endl << "-> ";
        cin >> n;
        if (n == 1) { DS[id].GIOITINH = true; break; }
        else if (n == 2) { DS[id].GIOITINH = false; break; }
        else { cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl; }
    }

    while (true) {
        cout << "-- Tình Trạng --" << endl;
        cout << "1.Tốt" << endl;
        cout << "2.Ổn" << endl;
        cout << "3.Yếu" << endl << "-> ";
        cin >> n;
        if (n == 1) { DS[id].TINHTRANG = "Tot"; break; }
        else if (n == 2) { DS[id].TINHTRANG = "On"; break; }
        else if (n == 3) { DS[id].TINHTRANG = "Yeu"; break; }
        else { cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl; }
    }

    dv = 0;
    while (true) {
        cout << "-- Gói Dịch Vụ --" << endl;
        cout << "1.Chăm sóc da mặt" << endl;
        cout << "2.Tẩy da hóa học" << endl;
        cout << "3.Tẩy da chết siêu vi" << endl;
        cout << "4.Liệu pháp Laser" << endl;
        cout << "5.Điều trị mụn" << endl;
        cout << "6.Làm săn chắc da" << endl;
        cout << "7.Thoát chọn gói dịch vụ" << endl << "-> ";
        cin >> n;
        if (n == 7 || dv == 6) break;
        if (n < 1 || n > 7) { cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl; }
        switch (n) {
        case 1:
            DS[id].DICHVU[dv] = "Cham soc da mat"; dv++; break;
        case 2:
            DS[id].DICHVU[dv] = "Tay da hoa hoc"; dv++; break;
        case 3:
            DS[id].DICHVU[dv] = "Tay da chet sieu vi"; dv++; break;
        case 4:
            DS[id].DICHVU[dv] = "Lieu phap Laser"; dv++; break;
        case 5:
            DS[id].DICHVU[dv] = "Dieu tri mun"; dv++; break;
        case 6:
            DS[id].DICHVU[dv] = "Lam san chac da"; dv++; break;
        }
    }
    id++;
}

void suaKhachHang(KHACHHANG *DS, int id) {
    int n;
    if (DS[0].TEN.empty()) {
        cout << "DANH SÁCH TRỐNG!" << endl;
        return;
    }

    while (true) {
        cout << "-- Tìm ID hoặc tên khách hàng muốn sửa --" << endl;
        cout << "1.ID" << endl;
        cout << "2.Tên" << endl << "-> ";
        cin >> n;
        if (n == 1) {
            cout << "ID: ";
            int id;
            bool kt = false;
            cin >> id;
            for (int i = 0; i < id + 1; i++) {
                if (id == DS[i].ID) {
                    kt = true;
                    while (true) {
                        cout << "-- Mời chọn thông tin để sửa --" << endl;
                        cout << "1.Tên" << endl;
                        cout << "2.Tuổi" << endl;
                        cout << "3.Giới tính" << endl;
                        cout << "4.Tình trạng" << endl;
                        cout << "5.Thoát" << endl << "-> ";
                        cin >> n;
                        if (n == 5) { break; }
                        if (n < 1 || n > 5) {
                            cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl;
                        }
                        switch (n) {
                        case 1:
                            cout << "Tên sửa: ";
                            getline(cin >> ws, DS[i].TEN);
                            break;
                        case 2:
                            while (true) {
                                cout << "Tuổi sửa: ";
                                cin >> DS[i].TUOI;
                                if (DS[i].TUOI > 0 && DS[i].TUOI < 100) break;
                                else {
                                    cout << "SỐ TUỔI KHÔNG PHÙ HỢP!" << endl; 
                                    }
                            }
                            break;
                        case 3:
                            while (true) {
                                cout << "-- Giới Tính Sửa --" << endl;
                                cout << "1.Nam" << endl;
                                cout << "2.Nữ" << endl << "-> ";
                                cin >> n;
                                if (n == 1) { DS[i].GIOITINH = true; break; }
                                else if (n == 2) { DS[i].GIOITINH = false; break; }
                                else { 
                                    cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl; 
                                }
                            }
                            break;
                        case 4:
                            while (true) {
                                cout << "-- Tình Trạng Sửa--" << endl;
                                cout << "1.Tốt" << endl;
                                cout << "2.Ổn" << endl;
                                cout << "3.Yếu" << endl << "-> ";
                                cin >> n;
                                if (n == 1) { DS[i].TINHTRANG = "Tot"; break; }
                                else if (n == 2) { DS[i].TINHTRANG = "On"; break; }
                                else if (n == 3) { DS[i].TINHTRANG = "Yeu"; break; }
                                else { cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl; }
                            }
                            break;
                        }
                        cout << "ĐÃ SỬA THÀNH CÔNG!" << endl;
                    }
                }
            }

            if (!kt) {
                cout << "KHÔNG TÌM THẤY ID!" << endl;
            }
            break;
        }
        else if (n == 2) 
           {
            cout << "Tên: ";
            string ten;
            bool kt = false;
            getline(cin >> ws, ten);

            for (int i = 0; i < id + 1; i++) {
                if (ten == DS[i].TEN) {
                    kt = true;
                    while (true) {
                        cout << "-- Mời chọn thông tin để sửa --" << endl;
                        cout << "1.Tên" << endl;
                        cout << "2.Tuổi" << endl;
                        cout << "3.Giới tính" << endl;
                        cout << "4.Tình trạng" << endl;
                        cout << "5.Thoát" << endl << "-> ";
                        cin >> n;
                        if (n == 5) { break; }
                        if (n < 1 || n > 5) {
                            cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl;
                        }
                        switch (n) {
                        case 1:
                            cout << "Tên sửa: ";
                            getline(cin >> ws, DS[i].TEN);
                            break;
                        case 2:
                            while (true) {
                                cout << "Tuổi sửa: ";
                                cin >> DS[i].TUOI;
                                if (DS[i].TUOI > 0 && DS[i].TUOI < 100) break;
                                else { 
                                    cout << "SỐ TUỔI KHÔNG PHÙ HỢP!" << endl; 
                                }
                            }
                            break;
                        case 3:
                            while (true) {
                                cout << "-- Giới Tính Sửa --" << endl;
                                cout << "1.Nam" << endl;
                                cout << "2.Nữ" << endl << "-> ";
                                cin >> n;
                                if (n == 1) { DS[i].GIOITINH = true; break; }
                                else if (n == 2) { DS[i].GIOITINH = false; break; }
                                else { cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl; }
                            }
                            break;
                        case 4:
                            while (true) {
                                cout << "-- Tình Trạng Sửa--" << endl;
                                cout << "1.Tốt" << endl;
                                cout << "2.Ổn" << endl;
                                cout << "3.Yếu" << endl << "-> ";
                                cin >> n;
                                if (n == 1) { DS[i].TINHTRANG = "Tot"; break; }
                                else if (n == 2) { DS[i].TINHTRANG = "On"; break; }
                                else if (n == 3) { DS[i].TINHTRANG = "Yeu"; break; }
                                else { cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl; }
                            }
                            break;
                        }
                        cout << "ĐÃ SỬA THÀNH CÔNG!" << endl;
                    }
                }
            }

            if (!kt) {
                cout << "KHÔNG TÌM THẤY TÊN!" << endl;
            }
            break;
        }
        else { cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl; }
    }
}

void xoaKhachHang(KHACHHANG *DS, int id) {
    int n;
    while (true) {
        cout << "-- Tìm ID hoặc tên khách hàng muốn xóa --" << endl;
        cout << "1.ID" << endl;
        cout << "2.Tên" << endl << "-> ";
        cin >> n;
        if (n == 1) {
            cout << "ID: ";
            int id;
            bool kt = false;
            cin >> id;
            for (int i = 0; i < id + 1; i++) {
                if (id == DS[i].ID) {
                    kt = true;
                    DS[i].ID = -1;
                }
            }
            if (!kt) {
                cout << "KHÔNG TÌM THẤY ID!" << endl; break;
            }
            cout << "ĐÃ XÓa KHÁCH HÀNG!" << endl;
            break;
        }
        else if (n == 2) {
            cout << "Tên: ";
            string ten;
            bool kt = false;
            getline(cin >> ws, ten);
            for (int i = 0; i < id + 1; i++) {
                if (ten == DS[i].TEN) {
                    kt = true;
                    DS[i].ID = -1;
                }
            }
            if (!kt) {
                cout << "KHÔNG TÌM THẤY TÊN!" << endl; break;
            }
            cout << "ĐÃ XÓA KHÁCH HÀNG!" << endl;
            break;
        }
        else { cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl; }
    }
}

void hienThiKhachHang(KHACHHANG *DS, int id) {
    string gt;
    if (DS[0].TEN.empty()) {
        cout << "DANH SÁCH TRỐNG!" << endl;
        return;
    }
    cout << setw(6) << left << "ID" << setw(35) << left << "Ten Khach Hang" << setw(10) << left << "Tuoi" << setw(11) << left << "Gioi Tinh" << setw(13) << left << "Tinh Trang" << setw(50) << left << "Goi Dich Vu" << endl;
    for (int i = 0; i < id; i++) 
    {
        if (DS[i].ID == -1) { continue;
        }
        else {
            if (DS[i].GIOITINH) {
                gt = "Nam";
            }
            else {
                gt = "Nu";
            }
            cout << "00" << setw(4) << DS[i].ID << setw(35) << DS[i].TEN << setw(10) << DS[i].TUOI << setw(11) << gt << setw(13) << DS[i].TINHTRANG;
            for (int j = 0; j < 6; j++) {
                if (DS[i].DICHVU[j].empty()) {
                    break;
                }
                else {
                    cout << DS[i].DICHVU[j] << " - ";
                }
            }
            cout << endl;
        }
    }
}

int main() {
    int n, id = 0;
    KHACHHANG *DS = new KHACHHANG[50];
    FILE *f;
    f = fopen("DsKhachHang.txt", "r");
    if (f != NULL) {
        docFile(f, DS, id);
        fclose(f);
    }
    while (true) {
        cout << endl << "============= MENU =============" << endl;
        cout << "1.Thêm khách hàng" << endl;
        cout << "2.Sửa thông tin khách hàng" << endl;
        cout << "3.Xóa khách hàng" << endl;
        cout << "4.Hiển thị danh sách khách hàng" << endl;
        cout << "5.Thoát" << endl;
        cout << "================================" << endl << "-> ";
        cin >> n;
        if (n == 5) { cout << "ĐÃ THOÁT!"; break; }
        switch (n) {
        case 1:
            themKhachHang(DS, id);
            break;
        case 2:
            suaKhachHang(DS, id);
            break;
        case 3:
            xoaKhachHang(DS, id);
            break;
        case 4:
            hienThiKhachHang(DS, id);
            break;
        default:
            cout << "NHẬP SAI CÚ PHÁP MỜI NHẬP LẠI!" << endl;
            break;
        }
    }
    delete[] DS;
    return 0;
}
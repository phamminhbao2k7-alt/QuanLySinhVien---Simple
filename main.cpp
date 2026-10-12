
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    float diem;
};

vector<SinhVien> ds;

void them() {
    SinhVien sv;

    cout << "Ma sinh vien: ";
    cin >> sv.maSV;

    cin.ignore();
    cout << "Ho ten: ";
    getline(cin, sv.hoTen);

    cout << "Diem: ";
    cin >> sv.diem;

    if (sv.diem < 0 || sv.diem > 10) {
        cout << "Diem khong hop le!\n";
        return;
    }

    ds.push_back(sv);
    cout << "Them thanh cong!\n";
}

void hienThi() {
    for (const SinhVien &sv : ds) {
        cout << sv.maSV << " | "
             << sv.hoTen << " | "
             << sv.diem << '\n';
    }

    if (ds.empty())
        cout << "Danh sach rong!\n";
}

void timKiem() {
    string ma;
    cout << "Nhap ma sinh vien: ";
    cin >> ma;

    for (const SinhVien &sv : ds) {
        if (sv.maSV == ma) {
            cout << sv.hoTen << " - "
                 << sv.diem << '\n';
            return;
        }
    }

    cout << "Khong tim thay!\n";
}

int main() {
    int chon;

    do {
        cout << "\n=== QUAN LY SINH VIEN ===\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Tim kiem sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        switch (chon) {
            case 1: them(); break;
            case 2: hienThi(); break;
            case 3: timKiem(); break;
            case 0: cout << "Tam biet!\n"; break;
            default: cout << "Lua chon sai!\n";
        }
    } while (chon != 0);

    return 0;
}

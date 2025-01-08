#include <iostream>

using namespace std;

 struct SINHVIEN {
    int MSSV;
    char TenSV[100];
    float DTB;
}; 

 struct NODE {
    SINHVIEN SV;
    NODE* Next;
};

NODE *Head = nullptr;  // Biến toàn cục quản lý danh sách liên kết
	void themSinhVienCuoi() {
    for (int i = 0; i < 2; ++i) {
        SINHVIEN sv;
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        cout << "MSSV: ";
        cin >> sv.MSSV;
        cin.ignore();  // Đọc bỏ ký tự '\n' còn sót lại
        cout << "Ten sinh vien: ";
        cin.getline(sv.TenSV, 100);
        cout << "DTB: ";
        cin >> sv.DTB;

        // Tạo node mới cho sinh viên vừa nhập
        NODE *New = new NODE();
        New->SV = sv;
        New->Next = nullptr;

        // Thêm vào cuối danh sách
        if (Head == nullptr) {
            Head = New;  // Nếu danh sách rỗng, gán pHead trỏ đến pNew
        } else {
            NODE *Temp = Head;
            while (Temp->Next != nullptr) {
                Temp = Temp->Next;  // Duyệt đến phần tử cuối cùng
            }
            Temp->Next = New;  // Gắn node mới vào cuối danh sách
        }
    }
}
void inDanhSachSVCoDTB() {
    NODE *Temp = Head;
    cout << "\nDanh sach sinh vien co DTB >= 5:\n";
    while (Temp != nullptr) {
        if (Temp->SV.DTB >= 5) {
            cout << "MSSV: " << Temp->SV.MSSV << endl;
            cout << "Ten sinh vien: " << Temp->SV.TenSV << endl;
            cout << "DTB: " << Temp->SV.DTB << endl;
            cout << "----------------------------\n";
        }
        Temp = Temp->Next;
    }
}
void giaiPhongDanhSach() {
    NODE *Temp;
    while (Head != nullptr) {
        Temp = Head;           // Lưu trữ node hiện tại
        Head = Head->Next;    // Chuyển sang node tiếp theo
        delete Temp;            // Giải phóng bộ nhớ của node hiện tại
    }
}
int main() {
    themSinhVienCuoi();  // Nhập thông tin của 10 sinh viên và thêm vào danh sách

    inDanhSachSVCoDTB();  // In ra danh sách sinh viên có ĐTB >= 5

    giaiPhongDanhSach();  // Giải phóng bộ nhớ của danh sách
    
    inDanhSachSVCoDTB();

    return 0;
}

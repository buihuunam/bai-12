#include <iostream>
#include <fstream>
#include <conio.h> // Sử dụng _getch() để đợi nhấn phím

using namespace std;

int main() {
    // Yêu cầu người dùng nhập tên tệp
    cout << "Nhập tên tệp: ";
    string fileName;
    getline(cin, fileName);

    // Mở tệp để đọc
    ifstream file(fileName);

    // Kiểm tra xem tệp có mở thành công không
    if (file.is_open()) {
        const int LINES_PER_PAGE = 24;
        string line;

        while (getline(file, line)) {
            cout << line << endl;

            // Nếu đã hiển thị đủ 24 dòng, đợi người dùng nhấn phím
            if (file.tellg() % (LINES_PER_PAGE * line.size()) == 0) {
                cout << "\nNhấn phím bất kỳ để tiếp tục...";
                _getch(); // Đợi người dùng nhấn phím
                system("cls"); // Xóa màn hình
            }
        }

        // Đóng tệp
        file.close();
    } else {
        cout << "Không thể mở tệp." << endl;
    }

    return 0;
}

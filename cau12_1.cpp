#include <iostream>
#include <fstream>
#include <string>

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
        // Hiển thị 10 dòng đầu tiên của tệp
        string line;
        for (int i = 0; i < 10 && getline(file, line); ++i) {
            cout << line << endl;
        }

        // Đóng tệp
        file.close();
    } else {
        cout << "Không thể mở tệp." << endl;
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h> // Sử dụng _getch() để đợi nhấn phím

using namespace std;

// Hàm để hiển thị nội dung của tệp với số dòng
void hienThiTep(const string& tenTep) {
    ifstream tep(tenTep);

    if (tep.is_open()) {
        const int LINES_PER_PAGE = 24;
        string line;
        int lineNumber = 1;

        while (getline(tep, line)) {
            cout << lineNumber << ":" << line << endl;
            lineNumber++;

            // Nếu đã hiển thị đủ 24 dòng, đợi người dùng nhấn phím
            if (lineNumber % LINES_PER_PAGE == 1) {
                cout << "\nNhấn phím bất kỳ để tiếp tục...";
                _getch(); // Đợi người dùng nhấn phím
                system("cls"); // Xóa màn hình
            }
        }

        tep.close();
    } else {
        cout << "Không thể mở tệp " << tenTep << endl;
    }
}

// Hàm để hiển thị 10 dòng cuối cùng của tệp
void hienThiTail(const string& tenTep) {
    ifstream tep(tenTep);
    
    if (tep.is_open()) {
        vector<string> lines;
        string line;

        // Lưu 10 dòng cuối cùng vào vector
        while (getline(tep, line)) {
            lines.push_back(line);
            if (lines.size() > 10) {
                lines.erase(lines.begin());
            }
        }

        // Hiển thị 10 dòng cuối cùng hoặc toàn bộ nếu tệp ít hơn 10 dòng
        for (const string& l : lines) {
            cout << l << endl;
        }

        tep.close();
    } else {
        cout << "Không thể mở tệp " << tenTep << endl;
    }
}

int main() {
    // Yêu cầu người dùng nhập tên của tệp
    cout << "Nhập tên tệp: ";
    string fileName;
    getline(cin, fileName);

    // Gọi hàm để hiển thị 10 dòng cuối cùng của tệp
    cout << "\n10 dòng cuối cùng của tệp:" << endl;
    hienThiTail(fileName);

    // Gọi hàm để hiển thị nội dung của tệp với số dòng
    cout << "\nNội dung của tệp với số dòng:" << endl;
    hienThiTep(fileName);

    return 0;
}

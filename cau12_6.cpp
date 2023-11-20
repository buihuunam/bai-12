#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Hàm để tìm kiếm và hiển thị dòng chứa chuỗi trong tệp
int timKiemVaHienThi(const string& tenTep, const string& chuoiTimKiem) {
    ifstream tep(tenTep);

    if (tep.is_open()) {
        string line;
        int lineNumber = 0;
        int occurrences = 0;

        while (getline(tep, line)) {
            lineNumber++;

            // Tìm kiếm chuỗi trong dòng
            size_t found = line.find(chuoiTimKiem);

            // Nếu chuỗi được tìm thấy, hiển thị dòng và tăng số lần xuất hiện
            if (found != string::npos) {
                cout << "Dòng " << lineNumber << ": " << line << endl;
                occurrences++;
            }
        }

        tep.close();

        return occurrences;
    } else {
        cout << "Không thể mở tệp " << tenTep << endl;
        return 0;
    }
}

int main() {
    // Yêu cầu người dùng nhập tên tệp và chuỗi cần tìm kiếm
    cout << "Nhập tên tệp: ";
    string fileName;
    getline(cin, fileName);

    cout << "Nhập chuỗi cần tìm kiếm: ";
    string searchStr;
    getline(cin, searchStr);

    // Gọi hàm để tìm kiếm và hiển thị dòng chứa chuỗi trong tệp
    int occurrences = timKiemVaHienThi(fileName, searchStr);

    // Hiển thị số lần xuất hiện của chuỗi
    cout << "Chuỗi '" << searchStr << "' xuất hiện " << occurrences << " lần trong tệp." << endl;

    return 0;
}

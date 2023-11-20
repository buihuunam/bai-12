#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Hàm để hiển thị 10 dòng cuối cùng của tệp
void hienThiTail(const string& tenTep) {
    ifstream tep(tenTep);
    
    if (tep.is_open()) {
        // Lưu 10 dòng cuối cùng vào một vector
        vector<string> lines;
        string line;
        
        while (getline(tep, line)) {
            lines.push_back(line);
            if (lines.size() > 10) {
                lines.erase(lines.begin());
            }
        }

        // Hiển thị 10 dòng cuối cùng
        for (const string& l : lines) {
            cout << l << endl;
        }

        tep.close();
    } else {
        cout << "Không thể mở tệp " << tenTep << endl;
    }
}

int main() {
    // Yêu cầu người dùng nhập tên tệp
    cout << "Nhập tên tệp: ";
    string fileName;
    getline(cin, fileName);

    // Gọi hàm để hiển thị 10 dòng cuối cùng của tệp
    hienThiTail(fileName);

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Hàm để đọc và hiển thị từng dòng trong tệp câu đùa
void docVaHienThiCauDua(const string& tenTep) {
    ifstream tep(tenTep);

    if (tep.is_open()) {
        string dong;
        while (getline(tep, dong)) {
            cout << dong << endl;
        }

        tep.close();
    } else {
        cout << "Không thể mở tệp " << tenTep << endl;
    }
}

// Hàm để hiển thị phần punch từ tệp
void hienThiPhanPunch(const string& tenTep) {
    ifstream tep(tenTep);

    if (tep.is_open()) {
        // Di chuyển đến cuối tệp
        tep.seekg(0, ios::end);

        // Lặp lại để tìm dòng cuối cùng bắt đầu từ cuối tệp
        int offset = 1;
        char ch;
        while (offset <= tep.tellg()) {
            tep.seekg(-offset, ios::end);
            tep.get(ch);

            // Nếu tìm thấy ký tự xuống dòng, dừng lại
            if (ch == '\n') {
                break;
            }

            offset++;
        }

        // Đọc và hiển thị dòng cuối cùng (phần punch)
        string punchLine;
        getline(tep, punchLine);
        cout << punchLine << endl;

        tep.close();
    } else {
        cout << "Không thể mở tệp " << tenTep << endl;
    }
}

int main() {
    // Gọi hàm để đọc và hiển thị câu đùa từ tệp joke.txt
    cout << "Cau dua:" << endl;
    docVaHienThiCauDua("joke.txt");

    // Gọi hàm để hiển thị phần punch từ tệp punchline.txt
    cout << "\nPhan punch:" << endl;
    hienThiPhanPunch("punchline.txt");

    return 0;
}

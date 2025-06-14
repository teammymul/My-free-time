#include <iostream>
#include <fstream>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;
const int SIZE = 216;
int main() {

    std::ifstream file("C:\\Users\\surfa\\Downloads\\Book1.csv");
    std::string line;
    int A[SIZE][SIZE];

    // อ่านข้อมูลใส่ A จาก CSV
    for (int i = 0; i < SIZE && std::getline(file, line); ++i) {
        std::stringstream ss(line);
        std::string value;
        for (int j = 0; j < SIZE && std::getline(ss, value, ','); ++j) {
            A[i][j] = std::stoi(value);
        }
    }

    // คำนวณ B - A โดยที่ B = A transpose
    int diff[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            diff[i][j] = A[j][i] - A[i][j]; // B = A^T
        }
    }

    // แสดงผลลัพธ์ (บางส่วนเพื่อไม่ให้แสดงเยอะเกินไป)
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << diff[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

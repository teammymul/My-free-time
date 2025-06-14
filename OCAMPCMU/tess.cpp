#include <iostream>
#include <map>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;

int main() {
    map<double, int> freq;

    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            for (int k = 1; k <= 6; ++k) {
                for (int l = 1; l <= 6; ++l) {
                    for (int m = 1; m <= 6; ++m) {
                        for (int n = 1; n <= 6; ++n) {
                            for (int o = 1; o <= 6; ++o) {
                                for (int p = 1; p <= 6; ++p) {
                                    for (int q = 1; q <= 6; ++q) {
                                        for (int r = 1; r <= 6; ++r) {
                double avg = (i + j + k + l + m + n + o + p + q + r) / 10.0;
                avg = round(avg * 100) / 100.0;
                freq[avg]++;
            }
        }
    }
}
                        }
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(2);
    cout << "ค่าเฉลี่ย\tความถี่" << endl;
    for (const auto& pair : freq) {
        cout << pair.first << "\t\t" << pair.second << endl;
    }

    return 0;
}

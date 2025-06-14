#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            for (int k = 1; k <= 6; ++k) {
                double avg = (2*(i + j + k)+1) / 3.0;
                cout << fixed << setprecision(2) << avg << endl;
            }
        }
    }
    return 0;
}

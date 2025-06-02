#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ฟังก์ชันสำหรับแปลง rank และ suit ให้เป็นค่าที่สามารถใช้เปรียบเทียบได้
int getRankValue(char rank) {
    string rankOrder = "3456789TJQKA2";
    return rankOrder.find(rank);
}

int getSuitValue(char suit) {
    string suitOrder = "CDHS";
    return suitOrder.find(suit);
}

// ฟังก์ชันเปรียบเทียบไพ่
bool compareCards(const pair<char, char>& a, const pair<char, char>& b) {
    if (getRankValue(a.first) != getRankValue(b.first)) {
        return getRankValue(a.first) < getRankValue(b.first);
    }
    return getSuitValue(a.second) < getSuitValue(b.second);
}

int main() {
    int n;
    cin >> n;
    vector<pair<char, char>> cards;

    for (int i = 0; i < n; i++) {
        char rank, suit;
        cin >> rank >> suit;
        cards.push_back({rank, suit});
    }

    // เรียงลำดับไพ่ตามกติกา
    sort(cards.begin(), cards.end(), compareCards);

    // แสดงผลลัพธ์
    for (const auto& o : cards) {
        cout << card.first << " " << card.second << "\n";
    }

    return 0;
}

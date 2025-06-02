#include <bits/stdc++.h>
using namespace std;
int rankcompare (char a){
    string order = "3456789TJQKA2";
    return order.find(a);
}
int suitcompare (char a){
    string order = "CDHS";
    return order.find(a);
}
bool compare(pair<char , char>& a , pair<char, char>& b){
    if(rankcompare(a.first) == rankcompare(b.first)){
        return suitcompare(a.second) < suitcompare(b.second);
    }
    return rankcompare(a.first) < rankcompare(b.first);
}
int main(){
    int n;cin>>n;
    vector<pair<char,char>> v;
    for(int i = 0 ; i < n ; i++){
        char a,b;
        cin>> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin() , v.end() , compare);
    for(auto i : v){
        cout << i.first <<" "<< i.second<<endl;
    }
}
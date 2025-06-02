#include <bits/stdc++.h>
using namespace std;
int monrank(string a){
    vector<string> order = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int l = 12;
    for(int i = 0 ; i< l ;i++){
        if(a == order[i]){
            return i;
        }
    }
    return 0;
}
bool compare(tuple<int,string,int,string>& a,tuple<int,string,int>& target){
      if(get<2>(a) == get<2>(target)){
        if(monrank(get<1>(a)) == monrank(get<1>(target))){
            return get<0>(a) < get<0>(target);
        }
        return monrank(get<1>(a)) < monrank(get<1>(target));
      }
    return get<2>(a) < get<2>(target);
}
void binary(vector<tuple<int,string,int,string>>& a ,tuple<int,string,int>& target, int p){
        int low = 0 ;
        int high = a.size()-1;
        while(low <= high){
             int mid = low + (high - low) / 2;
        if((get<0>(target) == get<0>(a[mid])) && (get<1>(target) == get<1>(a[mid])) && (get<2>(target) == get<2>(a[mid]))){
            if(p == 1)cout<<"["<<mid<<"]: "<<get<0>(a[mid])<<"/"<<get<1>(a[mid])<<"/"<<get<2>(a[mid])<<endl;
            cout<<"key: "<<get<0>(target)<<"/"<<get<1>(target)<<"/"<<get<2>(target)<<" found "<<get<3>(a[mid])<<endl;
            return;
        }
        if(!compare(a[mid] , target)){
            if(p == 1)cout<<"["<<mid<<"]: "<<get<0>(a[mid])<<"/"<<get<1>(a[mid])<<"/"<<get<2>(a[mid])<<endl;
            high = mid-1;
        }
        if(compare(a[mid],target)){ 
            if(p == 1)cout<<"["<<mid<<"]: "<<get<0>(a[mid])<<"/"<<get<1>(a[mid])<<"/"<<get<2>(a[mid])<<endl;
            low = mid+1;
        }
    }
    cout<<"key: "<<get<0>(target)<<"/"<<get<1>(target)<<"/"<<get<2>(target)<<" not found "<<endl;
    return;
}
int main(){
    int n;cin>>n;
    vector<tuple<int,string,int,string>> v;
    for(int i=0; i < n;i++){
        int date;
        string mon;
        int year;
        string event;
        cin>>date>>mon>>year>>event;
        v.push_back({date,mon,year,event});
    }
    int m;cin>>m;
    for(int i =0;i<m;i++){
        int p;cin>>p;
        // if(p==0){
        //     tuple<int,string,int> target;
        //     int date;
        //     string mon;
        //     int year;
        //     bool check = true;
        //     cin>>date>>mon>>year;
        //     target = {date,mon,year};
        //     for(int j = 0 ; j < n;j++){
        //         if((get<0>(target) == get<0>(v[j])) && (get<1>(target) == get<1>(v[j])) && (get<2>(target) == get<2>(v[j]))) {
        //             cout<<"key: "<<get<0>(target)<<"/"<<get<1>(target)<<"/"<<get<2>(target)<<" found "<<get<3>(v[j])<<endl;
        //             check = false;
        //         }
        //     }
        //         if(check){
        //         cout<<"key: "<<get<0>(target)<<"/"<<get<1>(target)<<"/"<<get<2>(target)<<" not found "<<endl;
        //     }
        // }
        // if(p==1){
            tuple<int,string,int> target;
            int date;
            string mon;
            int year;
            cin>>date>>mon>>year;
            target = {date,mon,year};
            binary(v,target,p);
        // }
    }
}
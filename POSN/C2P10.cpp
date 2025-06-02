#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node *next;
};
node* head = NULL;
void p(node* head){
    if(head == nullptr){
        cout<<endl;
    }
    else {
        cout<<head->data<<" ";
        p(head->next);
    }
}
void insert(int index , int target){
    node* newNode = new node;
    newNode->data = target;
    newNode->next = nullptr;
    if(index == 0){
        newNode->next = head;
        head = newNode;
        return;
    }
    node* currNode = head;
    node* prevNode = nullptr;
    int cnt = 0; 
    while(currNode != nullptr){
        if(cnt == index){
            prevNode->next = newNode;
            newNode->next = currNode;
            return;
        }
        cnt++;
        prevNode = currNode;
        currNode = currNode->next;
    }
    if(cnt == index){
        prevNode->next = newNode;
        newNode->next = nullptr;
        return;
    }
    cout<<"["<<index<<": "<<target<<" not inserted]"<<endl;
}
void d(int index){
    if (head == nullptr) {
    cout<<"["<<index<<": "<<"not deleted]"<<endl;
    return;
}
    if(index == 0){
        cout<<"["<<index<<": "<<head->data<<" "<<"deleted]"<<endl;
        head = head->next;
            return;
    }
    node* currNode = head;
    node* prevNode = nullptr;
    int cnt = 0;
    while(currNode->next != nullptr){
        if(cnt == index){
            cout<<"["<<index<<": "<<currNode->data<<" "<<"deleted]"<<endl;
            prevNode->next = currNode->next;
            currNode->next = nullptr;
            return;
        }
        cnt++;
        prevNode = currNode;
        currNode = currNode->next;
    }
    if(cnt == index){
        cout<<"["<<index<<": "<<currNode->data<<" "<<"deleted]"<<endl;
        prevNode->next = nullptr;
        return;
    }
    cout<<"["<<index<<": "<<"not deleted]"<<endl;
    return;
}
void v(int index){
    if(head == nullptr){
        cout<<"["<<index<<": "<<" invalid index]"<<endl;
    }
    if(index == 0){
        cout<<index<<": "<<head->data<<endl;
        return;
    }
    node* currNode = head;
    int cnt = 0;
    while(currNode != NULL){
        if(cnt == index){
            cout<<index<<": "<<currNode->data<<endl;
            return;
        }
        cnt++;
        currNode = currNode->next;
    }
    cout<<"["<<index<<": "<<"invalid index]"<<endl;
    return;
}
int main(){
    head = nullptr;
    int n ; cin>>n;
    for(int i = 0; i < n; i++){
        char temp;cin>>temp;
        if(temp == 'i'){
            int index,target;
            cin>>index>>target;
            insert(index,target);
        }
        if(temp == 'd'){
            int index;
            cin>>index;
            d(index);
        }
        if(temp == 'p'){
            p(head);
        }
        if(temp == 'v'){
            int index;cin>>index;
            v(index);
        }
    }
}
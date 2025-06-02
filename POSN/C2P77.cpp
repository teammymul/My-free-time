#include<bits/stdc++.h>
using namespace std;
struct BinTree {
 int value;
 BinTree* left;
 BinTree* right;
};
int cnt;
int cntleave;
BinTree* createNode(int target){
    BinTree* newNode = new BinTree;
    newNode->value = target;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
BinTree* build(BinTree* node,vector<int>& v){
    if(node == nullptr){
        node = createNode(v[cnt]);
        cnt++;
        return node;
    }
    node->left = build(node->left,v);
    node->right = build(node->right,v);
    return node;
}
void inorder(BinTree* node){
    if(node == NULL){
        return;
    }
    if(node->left == nullptr && node->right == nullptr){
        cout<<node->value<<" ";
        return;
    }
    if(node->value == -1){
        cout<<-1<<" ";
        return;
    }
    inorder(node->left);
    cout<<node->value<<" ";
    inorder(node->right);
}
void preorder(BinTree* node){
    if(node == NULL){
        return;
    }
    if(node->left == nullptr && node->right == nullptr){
        cout<<node->value<<" ";
        return;
    }
    if(node->value == -1){
        cout<<-1<<" ";
        return;
    }
    cout<<node->value<<" ";
    preorder(node->left);
    preorder(node->right);
}
void postorder(BinTree* node){
    if(node == NULL){
        return;
    }
    if(node->left == nullptr && node->right == nullptr){
        cout<<node->value<<" ";
        return;
    }
    if(node->value == -1){
        cout<<-1<<" ";
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->value<<" ";
}
void findleavenode(BinTree* node){
    if(node == NULL){
        return;
    }
    if(node->value == -1){
        return;
    }
    if(node->left == nullptr && node->right == nullptr){
        cntleave++;
        return;
    }
    findleavenode(node->left);
    findleavenode(node->right);
}
int maxvalue;
void findmax(BinTree* node){
    if(node == NULL){
        return;
    }
    if(node->value == -1){
        return;
    }
    if(node->value > maxvalue){
        maxvalue = node->value;
    }
    findmax(node->left);
    findmax(node->right);
}
void findsibling(vector<int>& v,int target){
    int l = v.size();
    for(int i = 0 ; i < l ; ++i){
        if(v[i] == target){
            if(i==0){
                cout<<-1;
                return;
            }
            else if(i%2 == 0){
                cout<<v[i-1];
                return;
            }
            else if(i%2 != 0){
                cout<<v[i+1];
                return;
            }
        }
    }
    cout<<-1;
}
bool check;
void findparent(BinTree* node,int target){
    if(node == NULL){
        cout<<-1;
        return;
    }
    if (node == NULL || node->left == NULL || node->right == NULL) return;
    if(node->value == -1) return;
    if(node->left == nullptr && node->right == nullptr) return;
    if(node->left->value == target || node->right->value == target){
        cout<<node->value;
        check = true;
    }
    findparent(node->left,target);
    findparent(node->right,target);
}
int main(){
    int h;cin>>h;
    int l = pow(2,h)-1;
    vector<int> v(l);
    BinTree* root = NULL;
    for(int i = 0 ; i < l ; ++i){
        int temp;cin>>temp;
        v[i] = temp;
    }
    for(int i = 0 ; i < h ; ++i){
        root = build(root,v);
    }
    int n;cin>>n;
    for(int i = 0 ;i < n;++i){
        char temp;
        cin>>temp;
        if(temp == 'm'){
            findmax(root);
            cout<<maxvalue;
            maxvalue = 0;
        }
        if(temp == 'i'){
            if(i==0){inorder(root);}
            else{
                cout<<endl;
                inorder(root);
            }
        }
        if(temp == 'a'){
            if(i==0){preorder(root);}
            else{
                cout<<endl;
                preorder(root);
            }
        }
        if(temp == 'b'){
            if(i==0){postorder(root);}
            else{
                cout<<endl;
                postorder(root);
            }
        }
        if(temp == 'l'){
            findleavenode(root);
            cout<<endl<<cntleave;
            cntleave = 0;
        }
        if(temp == 'p'){
            int target;cin>>target;
            if(i != 0)cout<<endl;
            findparent(root,target);
            if(!check) cout<<-1;
            check = false;
        }
        if(temp == 's'){
            int target;cin>>target;
            if(i != 0)cout<<endl;
            findsibling(v,target);
        }
    }
    // for(int i = 0 ; i < l ;++i){
    //     cout<<v[i]<<' ';
    // }
    // // cout<<endl;
    // // inorder(root);
    // // cout<<endl;
    // // preorder(root);
    // // cout<<endl;
    // // postorder(root);
    // // cout<<endl;
    // // findleavenode(root);
    // // cout<<cntleave;
    // // findmax(root);
    // // cout<<endl<<maxvalue;
    // // cout<<endl;
    // // findsibling(v,26);
    // // findparent(root,32);
    // // if(!check) cout<<-1;
}  
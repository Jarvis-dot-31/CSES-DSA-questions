#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode*child[2];
    bool isleaf;
    TrieNode(){
        isleaf=false;
        child[0]=nullptr;
        child[1]=nullptr;
    }
};
void insert(TrieNode*root,int num){
    TrieNode*temp=root;
    for (int i=30;i>=0;i--){
        if (num&(1<<i)){
            if (!temp->child[1]) temp->child[1]=new TrieNode();
            temp=temp->child[1];
        }else{
            if (!temp->child[0]) temp->child[0]=new TrieNode();
            temp=temp->child[0];
        }
    }
    temp->isleaf=true;
}
int helper(TrieNode*root,int num){
    TrieNode*temp=root;
    int ans=0;
    for (int i=30;i>=0;i--){
        if (num&(1<<i)){
            if (temp->child[0]){
                ans+=(1<<i);
                temp=temp->child[0];
            }else temp=temp->child[1];
        }else{
            if (temp->child[1]){
                ans+=(1<<i);
                temp=temp->child[1];
            }else temp=temp->child[0];
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    TrieNode*root=new TrieNode();
    insert(root,0);
    int curr=0;
    int ans=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        curr=(curr^a);
        ans=max(ans,helper(root,curr));
        insert(root,curr);
    }
    cout<<ans<<"\n";
}
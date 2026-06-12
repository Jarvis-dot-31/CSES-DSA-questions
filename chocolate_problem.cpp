#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<char>>&arr,vector<int>&arr1){
    for (int i=0;i<arr.size();i++){
        for (int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    for (int i:arr1) cout<<i<<" ";
    cout<<"\n";
}

int main(){
    string s;
    cin>>s;
    int q;
    char c;
    cin>>q>>c;
    int rootn=pow(s.size(),0.5);
    vector<vector<char>>groups(s.size()/rootn+1);
    vector<int>counts(s.size()/rootn+1,0);
    for (int i=0;i<s.size();i++){
        groups[i/rootn].push_back(s[i]);
        if (s[i]==c){
            counts[i/rootn]++;
        }
    }
    vector<int>ans;
    for (int i=0;i<q;i++){
        int type;
        cin>>type;
        if (type==1){
            int id;
            cin>>id;
            if (s[id]!=c) counts[id/rootn]++;
        }else{
            int z=0;
            int l,r;
            cin>>l>>r;
            int lower=l/rootn;
            int high=r/rootn;
            for (int j=l;j<groups[lower].size();j++){
                if (groups[lower][j]==c) z++;
            }
            cout<<"\n";
            for (int j=0;j<=r;j++){
                if (groups[high][j]==c) z++;
            }
            for (int j=lower+1;j<high;j++){
                z+=counts[j];
            }
            ans.push_back(z);
        }
    }
    for (int i:ans) cout<<i<<"\n";
}
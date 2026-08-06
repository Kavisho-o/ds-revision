#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int k; cin>>k;
    string s; cin>>s;

    unordered_map<char,int> mp;
    for (auto c: s) mp[c]++;

    string ans="";
    for (auto &it: mp){
        if (it.second%k!=0) {cout<<-1; return;}
        else ans+=string(it.second / k, it.first);;
    }
 
    int n = ans.size();
    string t=ans;
    for (int i=0; i<k-1; i++){
        ans+=t;
    }

    cout<<ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
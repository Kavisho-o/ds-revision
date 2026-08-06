#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    string s; cin>>s;
    vector<int> v;

    for (auto c: s){
        if (c!='+') v.push_back(c-'0');
    }

    sort(v.begin(),v.end());

    string ans="";
    for (int i=0; i<v.size(); i++){ 
        ans+=v[i]+'0';
        if (i!=v.size()-1) ans+='+';
    }

    cout<<ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
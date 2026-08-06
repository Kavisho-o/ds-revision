#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    string s; cin>>s;

    vector<string> v(5);
    bool found=0;
    for (int i=0; i<5; i++){
        cin>>v[i];
        if (v[i][0]==s[0] || v[i][1]==s[1]) found=1;
    }

    found ? cout<<"YES" : cout<<"NO";
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
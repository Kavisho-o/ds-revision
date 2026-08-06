#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    string s; cin>>s;

    for (int i=1; i<s.length(); i++){
        if (s[i]<='z' && s[i]>='a') {cout<<s; return;}
    }
    for (int i=1; i<s.length(); i++){
        s[i]=tolower(s[i]);
    }
    (s[0]<='z' && s[0]>='a') ? s[0]+='A'-'a' : s[0]-='A'-'a';
    cout<<s;

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
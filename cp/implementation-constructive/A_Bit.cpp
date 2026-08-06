#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;

    int ans=0;

    for (int i=0; i<n; i++) {
        string s; cin>>s;
        s.find('+')!=string::npos ? ans++ : ans--;
    }

    cout<<ans<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}   
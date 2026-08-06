#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int x; cin>>x;

    string s = to_string(x);
    int n=s.size();
    int ans = ((s[n-1]-'0')-1) * 10 + (n+1)*n/2;

    cout<<ans<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
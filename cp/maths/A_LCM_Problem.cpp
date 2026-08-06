#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    
    ll l, r;
    cin >> l >> r;

    if (2 * l <= r) cout << l << " " << 2 * l << "\n";
    else cout << -1 << " " << -1 << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
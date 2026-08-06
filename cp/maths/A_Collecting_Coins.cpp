#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int mx = max({a, b, c});
    int need = 2 * mx - (a + b + c - mx);

    n -= need;

    if (n < 0) {
        cout << "NO\n";
        return;
    }
    if (n % 3 == 0) cout << "YES\n";
    else cout << "NO\n";
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
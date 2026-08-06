#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n;
    cin >> n;

    for (int y = n / 7; y >= 0; y--) {

        int rem = n - 7 * y;

        if (rem % 4 == 0) {

            int x = rem / 4;

            for (int i = 0; i < x; i++) cout << 4;
            for (int i = 0; i < y; i++) cout << 7;

            return;

        }
    }

    cout << -1;

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
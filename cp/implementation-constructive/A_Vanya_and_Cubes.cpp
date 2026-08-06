#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;

    int height = 0;
    int cubes = 0;

    for (int i = 1;; i++) {
        cubes += i*(i+1)/2;
        if (cubes > n) break;
        height++;
    }

    cout<<height;

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
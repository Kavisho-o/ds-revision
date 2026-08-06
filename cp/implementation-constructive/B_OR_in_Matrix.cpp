#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int m, n;
    cin >> m >> n;

    vector<vector<int>> B(m, vector<int>(n));
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> B[i][j];

    vector<vector<int>> A(m, vector<int>(n, 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (B[i][j] == 0) {
                for (int k = 0; k < n; k++) A[i][k] = 0;
                for (int k = 0; k < m; k++) A[k][j] = 0;
            }
        }
    }

    vector<vector<int>> B2(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = 0;
            for (int k = 0; k < n; k++) val |= A[i][k];
            for (int k = 0; k < m; k++) val |= A[k][j];
            B2[i][j] = val;
        }
    }

    if (B2 != B) cout << "NO\n";
    else {
        cout << "YES\n";
        for (auto &row : A) {
            for (int x : row)
                cout << x << " ";
            cout << "\n";
        }
    }

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
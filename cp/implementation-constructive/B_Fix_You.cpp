#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,m; cin>>n>>m; 
    int cnt=0;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char x; cin>>x;
            if (i==n-1 && x=='D') cnt++;
            if (j==m-1 && x=='R') cnt++;
        }
    }

    cout<<cnt<<endl;


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
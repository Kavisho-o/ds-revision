#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,m; cin>>n>>m;

    if (m%n!=0){cout<<-1; return;}
    int mult = m/n;

    int ops=0;
    while (mult!=1){
        ops++;
        if (mult%3==0) mult/=3;
        else if (mult%2==0) mult/=2;
        else {cout<<-1; return;}
    }
    cout<<ops;

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
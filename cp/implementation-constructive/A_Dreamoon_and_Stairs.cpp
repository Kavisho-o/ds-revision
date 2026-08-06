#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,m; cin>>n>>m;

    int t=n/2; // max no. of two steps possible here
    int o=n%2; // remaining one steps here

    while (t>=0){
        if ((2*t+o)==n && (t+o)%m==0){ cout<<t+o; return; }
        t--; o+=2;
    }

    cout<<-1;
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
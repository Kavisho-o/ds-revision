#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    ll n; cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++) cin>>v[i];

    ll chocs=v[n-1];
    ll adj=v[n-1];

    for (ll i=n-2; i>=0; i--){

        if (v[i]>=adj) adj=min(adj-1,v[i]);
        else adj=v[i];

        if (adj<=0) break;
        chocs+=adj;
    }

    cout<<chocs;

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
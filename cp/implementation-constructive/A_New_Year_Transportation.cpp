#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,t; cin>>n>>t;
    vector<int> v(n);
    for (int i=1; i<=n-1; i++) cin>>v[i-1];

    unordered_map<int,int> mp;
    for (int i=1; i<n; i++) mp[i]=v[i-1]+i;

    vector<int> vis(n+1,-1);
    int i=1;
    while (vis[i]==-1){

        if (mp[i]==t){cout<<"YES"; return; }
        vis[i]=1;
        i=mp[i];

    }

    cout<<"NO";

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
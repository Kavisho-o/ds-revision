#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int k,n,w; cin>>k>>n>>w;

    int ans=(n-(w*(w+1)/2)*k<0) ? abs(n-(w*(w+1)/2)*k) : 0;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
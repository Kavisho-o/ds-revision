#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int x,y,z; cin>>x>>y>>z;

    int mx=max({x,y,z});
    if ((x==y && x==mx) || (y==z && y==mx) || (z==x && z==mx)) {
        cout<<"YES"<<endl;
        cout<<min({x,y,z})<<" "<<min({x,y,z})<<" "<<mx<<endl;
    }
    else cout<<"NO"<<endl;   
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
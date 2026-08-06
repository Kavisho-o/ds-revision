#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,m; cin>>n>>m;

    int ans=0;
    
    if (m%2==0) {

        ans = (m/2)*n;

    }

    else{

        int add = n%2==0 ? n/2 : n/2 + 1;
        ans = (m/2)*n + add;

    }

    cout<<ans<<endl;

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
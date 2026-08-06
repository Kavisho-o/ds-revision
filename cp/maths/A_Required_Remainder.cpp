#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int x,y,n; cin>>x>>y>>n;

    while (n){
        if (n%x==y) break;
        n--;
    }

    cout<<n<<endl;
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
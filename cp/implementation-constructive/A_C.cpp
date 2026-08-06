#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int a,b,n; cin>>a>>b>>n;

    int ops=0;
    while (max(a,b)<=n){
        if (a<b) a+=b;
        else b+=a;
        ops++;
    }

    cout<<ops<<endl;

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
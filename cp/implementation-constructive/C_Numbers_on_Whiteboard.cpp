#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;

    int ans = n==1?1:2;
    cout<<ans<<endl;

    int a=n;
    int b=n-1;

    while (n!=1){

        cout<<a<<" "<<b<<endl;
        n--;
        a=(a+b+1)/2;
        b--;

    }

    cout<<endl;
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
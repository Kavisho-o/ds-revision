#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {

    ll n; cin>>n;

    ll i=1;
    int cnt=0;

    while (i<=n){

        cnt++; n--; i++;

    }

    cout<<cnt<<endl;

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
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    double a,b; cin>>a>>b;

    int ans = 1+floor(log(b/a)/log(3.0/2.0));
    cout<<ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,k,l,c,d,p,nl,np; cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int daaru = k*l;
    int nimbu = c*d;

    int ans=min({daaru/nl,p/np,nimbu})/n;

    cout<<ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
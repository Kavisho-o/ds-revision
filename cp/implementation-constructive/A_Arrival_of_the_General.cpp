#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;

    int mxpos=-1;
    int mnpos=-1;

    int mx=0;
    int mn=101;

    for (int i=0; i<n; i++) {
        int x; cin>>x;
        if (x>mx){
            mxpos=i;
            mx=x;
        }
        if (x<=mn){
            mnpos=i;
            mn=x;
        }
    }

    int steps=mxpos+(n-mnpos-1);
    int ans = mxpos>mnpos ? steps-1 : steps;

    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
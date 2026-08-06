#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;

    int pplintram=0;
    int mxppl=-1;
    for (int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        pplintram+=(b-a);
        mxppl=max(mxppl,pplintram);
    }
    
    cout<<mxppl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
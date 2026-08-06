#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,k; cin>>n>>k;
    for (int i=0; i<k; i++){
        if (n%10!=0) n--;
        else n/=10;
    }

    cout<<n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
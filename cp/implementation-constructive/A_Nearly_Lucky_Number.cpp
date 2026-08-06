#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    ll n; cin>>n;
    int lucky = 0;

    while(n>0){
        if (((n%10)==4) || ((n%10)==7)) lucky++;
        n/=10;
    }

    (lucky==4 || lucky==7) ? cout<<"YES" : cout<<"NO";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
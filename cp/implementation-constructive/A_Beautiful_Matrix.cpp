#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    
    int iidx=-1;
    int jidx=-1;

    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            int n; cin>>n;
            if (n==1) {
                iidx=i; jidx=j;
            }
        }
    }

    int ans = abs(2-iidx) + abs(2-jidx);
    cout<<ans;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
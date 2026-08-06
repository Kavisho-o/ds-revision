#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin>>arr[i];

    int mx=1;
    int seq=1;

    for (int i=1; i<n; i++){
        if (arr[i]>arr[i-1]) seq++;
        else seq=1;
        mx=max(mx,seq);
    }

    cout<<mx;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
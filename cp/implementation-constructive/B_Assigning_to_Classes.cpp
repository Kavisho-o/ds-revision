#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n; 
    vector<int> v(2*n);

    for (int i=0; i<2*n; i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    int ans = v[n]-v[n-1];
    cout<<ans<<endl;

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
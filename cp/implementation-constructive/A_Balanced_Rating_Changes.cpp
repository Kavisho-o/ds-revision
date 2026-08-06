#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    vector<int> v(n),ans(n);

    for (int i=0; i<n; i++){
        cin>>v[i];
        ans[i] = v[i]/2;
    }

    for (int i=0; i<n; i++){
        if (v[i]<0 && v[i]%2!=0) ans[i]--;
    }

    int sum = accumulate(ans.begin(),ans.end(),0);

    for (int i=0; i<n && sum<0; i++){
        if (v[i]%2!=0){
            ans[i]++;
            sum++;
        }
    }

    for (int x: ans)cout<<x<<endl;
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
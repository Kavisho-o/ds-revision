#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,k; cin>>n>>k;
    vector<pair<int,int>> v(n);
    for (int i=0; i<n; i++){
        int x; cin>>x;
        v[i] = {i+1,x};
    }

    sort(v.begin(),v.end(),[](const auto& a, const auto& b){ return a.second<b.second; });

    
    int i=0;
    for (;i<n; i++){

        if (k>=v[i].second) k-=v[i].second;
        else break;
        
    }

    cout<<i<<endl;
    for (int j=0; j<i; j++) cout<<v[j].first<<" ";


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
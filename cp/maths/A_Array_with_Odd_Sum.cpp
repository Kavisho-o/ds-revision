#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    vector<int> v(n);
    int b=0;

    for (int i=0; i<n; i++){ cin>>v[i]; if (v[i]%2) b++; }
    if ((n%2==0 && b==n) || b==0) {cout<<"NO"<<endl; return;}
    cout<<"YES"<<endl;

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
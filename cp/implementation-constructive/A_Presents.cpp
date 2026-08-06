#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;

    vector<int> arr(n);
    for (int i=0; i<n; i++){
        int x; cin>>x;
        arr[x-1]=i+1;
    }

    for (auto x: arr) cout<<x<<" ";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
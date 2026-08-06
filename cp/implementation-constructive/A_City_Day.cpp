#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,x,y; cin>>n>>x>>y;

    vector<int> arr(n);
    for (int i=0; i<n; i++) cin>>arr[i];

    for (int i=0; i<n; i++){

        int prevd=0;
        int nextd=0;    
        int j=i-1;
        int k=i+1;
        bool ok=1;

        while (j>=0 && prevd<x){ if (arr[j]<arr[i]) ok=0; j--; prevd++; }
        while (k<n && nextd<y){ if (arr[k]<arr[i]) ok=0; k++; nextd++; } 
        if (ok) {cout<<i+1; return;}

    }

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
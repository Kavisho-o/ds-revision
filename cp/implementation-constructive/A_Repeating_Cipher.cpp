#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    string t; cin>>t;
    
    int i=0;
    string s="";
    int pos=1;
    while(i<n){
        s+=t[i];
        i+=pos;
        pos++;
    }

    cout<<s;

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
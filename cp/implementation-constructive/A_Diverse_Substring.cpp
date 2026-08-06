#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    string s; cin>>s;

    int i=0; 
    int j=i+1;

    while (j<n){
        if (s[i]!=s[j]) {string t=""; t+=s[i]; t+=s[j]; cout<<"YES"<<endl; cout<<t ; return;}
        i++; j++;
    }
    cout<<"NO";

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
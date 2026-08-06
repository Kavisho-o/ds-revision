#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    string s; cin>>s;

    int n=s.length();

    int fo=-1;
    int lo=-1;

    for (int i=0; i<n; i++){
        if (s[i]=='1'){
            if (fo==-1) fo=i;
            lo=i;
        } 
    }
    int ans=0;

    for (int i=fo; i<=lo; i++){

        if (s[i]=='0') ans++;
    }

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
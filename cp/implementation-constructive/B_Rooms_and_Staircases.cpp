#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    string s; cin>>s;

    int rooms=n;
    for (int i=0; i<n; i++){

        if (s[i]=='1') rooms = max(rooms,2*max(i+1,n-i));

    }

    cout<<rooms<<endl;

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
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    ll n; cin>>n;
    string s=to_string(n);

    for (int i=0; i<s.size(); i++){
        if (i==0 && s[i]=='9') continue;
        char c=(9-(s[i]-'0'))+'0';
        s[i]=min(s[i],c);
    }
    
    cout<<s;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
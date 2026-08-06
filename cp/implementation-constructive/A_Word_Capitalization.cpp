#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    string s; cin>>s;
    s[0]=(s[0]<='z' && s[0]>='a')?s[0]+('A'-'a'):s[0];
    cout<<s;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
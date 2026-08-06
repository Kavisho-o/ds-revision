#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    string s; cin>>s;
    string t="";

    for (int i=0; i<s.length(); i++){
        if ((tolower(s[i])<='z' && tolower(s[i])>='b') 
        && (tolower(s[i])!='e') 
        && (tolower(s[i])!='i')
        && (tolower(s[i])!='o')
        && (tolower(s[i])!='u')
        && (tolower(s[i])!='y')){
            t+='.';
            t+=tolower(s[i]);
        }
    }

    cout<<t;

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
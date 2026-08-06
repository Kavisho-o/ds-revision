#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    string s; cin>>s;
    unordered_set<char> st;

    for (auto c: s) st.insert(c);
    int sz = (int)st.size();

    if (sz%2) cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
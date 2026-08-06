#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;

    int sz=0;
    int ans=0;

    vector<int> v;

    while(n>0){
        if ((n%10)!=0){
            int pb=(pow(10,sz))*(n%10);
            v.push_back(pb);
        }
        sz++;
        n/=10;
    }

    cout<<v.size()<<endl;
    for (auto x: v) cout<<x<<" ";
    cout<<endl;
    
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
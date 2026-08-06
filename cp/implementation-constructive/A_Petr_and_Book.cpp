#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    unordered_map<int,int> mp;
    int weekly=0;
    for (int i=0; i<7; i++){
        int x; cin>>x;
        mp[i+1]=x;
        weekly+=x;
    }

    n%=weekly;
    if (n==0) n=weekly;
    
    int i=0;
    while (n>0){
        i++;
        n-=mp[i];
    }

    while (mp[i]==0) i++;

    cout<<i;



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
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dist(int a, int b, int c, int curr){

    return abs(a-curr)+abs(b-curr)+abs(c-curr);

}

void solve() {

    int a,b,c; cin>>a>>b>>c;

    int ans=INT_MAX;
    
    for (int i=min({a,b,c}); i<=max({a,b,c}); i++){
        ans=min(ans,dist(a,b,c,i));
    }

    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
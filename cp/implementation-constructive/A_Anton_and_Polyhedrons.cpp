#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    int ans=0;

    for (int k=0; k<n; k++){
        string s; cin>>s;
        if (s=="Tetrahedron") ans+=4;
        if (s=="Cube") ans+=6;
        if (s=="Octahedron") ans+=8;
        if (s=="Dodecahedron") ans+=12;
        if (s=="Icosahedron") ans+=20;
    }

    cout<<ans;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
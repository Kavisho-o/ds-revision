#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    string s; cin>>s;
    vector<vector<int>> v(n,vector<int> (2));

    for (int i=0; i<n; i++){

        char c = s[i];
        v[i][0] = c=='a' ? 'b' : (c-1);
        v[i][1] = c=='z' ? 'y' : (c+1);
        
    }

    int f=0;
    int l=n-1;

    while (f<l){

        bool done=0;

        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){

                if (v[f][i]==v[l][j]) { done=1; break; }

            }
            if (done) break;
        }

        if (!done){ cout<<"NO"<<endl; return; }
        f++; l--;
    
    }

    cout<<"YES"<<endl;

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
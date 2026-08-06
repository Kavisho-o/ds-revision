#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n,m; cin>>n>>m;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (i%2) cout<<'#';
            else{
                if ((i/2)%2){
                    if (j==m) cout<<'#';
                    else cout<<'.';
                }
                else{
                    if (j==1) cout<<'#';
                    else cout<<'.';
                }
            }
        }
        cout<<endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
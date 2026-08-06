#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;

    int gap=n;
    int dir=-1;

    for (int i=0; i<=2*n; i++){
        for (int k=0; k<gap; k++){
            cout<<"  ";
        }
        for (int j=0; j<n-gap+1; j++){
            if (i==0 || i==2*n) cout<<j;
            else cout<<j<<" ";
        }
        for (int l=n-gap; l>0; l--){
            if (l==1) cout<<l-1;
            else cout<<l-1<<" ";
        }
        cout<<endl;
        gap+=dir;
        if (gap==0 || gap==n) dir*=-1;
      
    }

    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
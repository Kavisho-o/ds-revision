#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n; cin>>n;
    for (int i=0; i<n; i++){
        int x; cin>>x;
        if (x==1){
            cout<<"HARD";
            return;
        }
    }
    cout<<"EASY";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();    

    return 0;
}
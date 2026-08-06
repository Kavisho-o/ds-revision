#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    long double n,x; cin>>n>>x;

    if (n<=2) { cout<<1<<endl; return;}
    n-=2;
    n=ceil((double)n/x);
    n++;

    cout<<n<<endl;

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
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    string s; cin>>s;
    string e; cin>>e;

    int sh = stoi(s.substr(0,2));
    int sm = stoi(s.substr(3,2));
    
    int eh = stoi(e.substr(0,2));
    int em = stoi(e.substr(3,2));

    int tms = sh*60 + sm;
    int tme = eh*60 + em;
    int tmm = (tms+tme)/2;

    int mh = tmm/60;
    int mm = tmm%60;

    string m=to_string(mm);
    if (m.size()==1) m="0"+m;

    string h=to_string(mh);
    if (h.size()==1) h="0"+h;

    cout<<h<<":"<<m;

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
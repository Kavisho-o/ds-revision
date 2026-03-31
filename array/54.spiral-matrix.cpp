# include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>> &arr){

        int n=arr.size();
        int m=arr[0].size();

        int fr=0;
        int lr=n-1;
        int fc=0;
        int lc=m-1;

        vector<int> res;

        while (fr<lr && fc<lc) {

            for (int i=fc; i<=lc; i++){

                res.pb(arr[fr][i]);

            }

            for (int i=fr; i<=lr; i++){

                res.pb(arr[i][lc]);

            }

            for (int i=lr; i>=fr; i--){

                res.pb(arr[lr][i]);

            }

            for (int i=lc; i>=fc; i--){

                res.pb(arr[i][fc]);

            }

            lr--;
            lc--;
            fr++;
            fc++;

        }

        return res;

    }

};
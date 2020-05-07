
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll res = 1;
    for(int i=0; i<n; i++){
        res = (2*res)%1000000007;
    }
    cout << res << endl;
}

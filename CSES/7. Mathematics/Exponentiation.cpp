
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll p(ll a, ll b){
    ll x=1, y=a;
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % MOD;
        }
        y = (y*y) % MOD;
        b /= 2;
    }
    return x % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T,a,b; cin >> T;
    while(T--){
        cin >> a >> b;
        cout << p(a,b) << "\n";
    }
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll p(ll a, ll b, ll m){
    ll x=1, y=a;
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % m;
        }
        y = (y*y) % m;
        b /= 2;
    }
    return x % m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T,a,b,c; cin >> T;
    while(T--){
        cin >> a >> b >> c;
        cout << p(a,p(b,c,MOD-1),MOD) << "\n";
    }
}

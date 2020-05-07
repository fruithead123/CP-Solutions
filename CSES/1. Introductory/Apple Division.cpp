
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int n;
    ll apples[20], best = 20LL*1000000000LL;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> apples[i];
    }
    for(int mask = 0; mask< (1 << n); mask++){
        ll cur = 0LL;
        int mc = mask;
        for(int i=0; i<n; i++){
            if(mc&1){
                cur += apples[i];
            }
            else{
                cur -= apples[i];
            }
            mc >>= 1;
        }
        best = min(best, abs(cur));
    }
    cout << best << endl;
}

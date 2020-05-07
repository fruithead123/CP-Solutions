
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, k[200009];
    cin >> n >> t;
    for(int i=0; i<n; i++){
        cin >> k[i];
    }

    ll lo = 0LL;
    ll hi = 1000000000000000000LL;
    ll best = hi;
    while(lo <= hi){
        unsigned long long val = 0LL;
        ll mid = (lo+hi)/2;
        for(int i=0; i<n; i++){
            val += (mid / k[i]);
        }
        if(val >= t){
            best = min(best, mid);
            hi = mid-1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << best << endl;


}

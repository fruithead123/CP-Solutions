
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n;
    int res = 0;
    for(int i=1; i<=n; i++){
        res ^= i;
    }
    for(int i=0; i<n-1; i++){
        cin >> q;
        res ^= q;
    }
    cout << res << endl;
}

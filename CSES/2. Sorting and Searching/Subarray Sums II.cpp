
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000009;

int n;
ll nums[200009], s=0, x, ans = 0;
map<ll, int> occ;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin>> nums[i];
    }
    occ[0]++;
    for(int i=0; i<n; i++){
        s += nums[i];
        ans += occ[s - x];
        occ[s]++;
    }
    cout << ans << endl;
}

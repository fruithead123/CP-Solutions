
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000009;

ll nums[200009], s=0, ans = 0,n;
map<ll, int> occ;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        while(nums[i] < 0) nums[i] += n;
        nums[i] %= n;
    }
    occ[0]++;
    for(int i=0; i<n; i++){
        s = (s + nums[i]) % n;
        ans += occ[s];
        occ[s]++;
    }
    cout << ans << endl;
}

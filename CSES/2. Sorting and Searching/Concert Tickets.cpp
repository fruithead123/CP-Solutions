
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tmp;
    multiset<int> prices;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> tmp;
        prices.insert(tmp);
    }
    for(int i=0; i<m; i++){
        cin >> tmp;
        auto pos = prices.upper_bound(tmp);
        if(pos == prices.begin()){
            cout << -1 << endl;
        }
        else{
            cout << *(--pos) << endl;
            prices.erase(pos);
        }
    }


}

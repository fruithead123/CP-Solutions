
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> coins(n);
    set<int> found;
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    for(int i=0; i<n; i++){
        vector<int> ne;
        for(int x : found){
            ne.push_back(x + coins[i]);
        }
        ne.push_back(coins[i]);
        for(int k : ne){
            found.insert(k);
        }
    }
    cout << found.size() << "\n";
    for(int x : found){
        cout << x << " ";
    }
}

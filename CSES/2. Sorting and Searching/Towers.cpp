
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cubes[200009];
    vector<int> towers;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> cubes[i];
    }
    for(int i = 0; i<n; i++){
        auto pos = upper_bound(towers.begin(), towers.end(), cubes[i]);
        if(pos == towers.end()){
            towers.push_back(cubes[i]);
        }
        else{
            *pos = cubes[i];
        }
    }
    cout << towers.size() << endl;
}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, nums[5010];
    pair<int, pair<int,int>> ans;
    map<int, vector<int>> table;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        table[nums[i]].push_back(i);
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            auto pos = table.find(x - nums[i] - nums[j]);
            if(pos != table.end()){
                for(int k : pos->second){
                    if(i != k && j != k){
                        ans = {i, {j,k}};
                        goto End;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
    End:
        cout << ans.first + 1 << " " << ans.second.first + 1 << " " << ans.second.second + 1 << endl;
        return 0;
}


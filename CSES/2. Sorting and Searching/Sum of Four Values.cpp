
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, nums[1010];
    map<int, vector<pair<int,int>>> table;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            table[nums[i]+nums[j]].push_back({i,j});
        }
    }
    for(auto check : table){
        int f = check.first;
        vector<pair<int, int>> s = check.second;
        auto match = table.find(x - f);
        if(match != table.end()){
            for(pair<int, int> p1 : s){
                for(pair<int,int> p2 : match->second){
                    if(p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second != p2.second){
                        printf("%d %d %d %d\n", p1.first+1, p1.second+1, p2.first+1, p2.second+1);
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;


}

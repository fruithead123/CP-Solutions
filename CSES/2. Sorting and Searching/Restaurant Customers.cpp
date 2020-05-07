
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, start, leave;
    vector<pair<int, int>> times;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> start;
        cin >> leave;
        times.push_back({start, 0});
        times.push_back({leave, 1});
    }
    sort(times.begin(), times.end());
    int best = 0;
    int curr = 0;
    for(pair<int,int> t : times){
        if(t.second == 0){
            curr++;
        }
        else{
            curr--;
        }
        best = max(best, curr);
    }
    cout << best << endl;


}

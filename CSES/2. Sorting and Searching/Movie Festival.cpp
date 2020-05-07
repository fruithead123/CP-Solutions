
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
        times.push_back({leave, start});
    }
    sort(times.begin(), times.end());
    int time = 0;
    int cnt = 0;
    for(pair<int, int> movie : times){
        if(movie.second >= time){
            cnt++;
            time = movie.first;
        }
    }
    cout << cnt << endl;
}

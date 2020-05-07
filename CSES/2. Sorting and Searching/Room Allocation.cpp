
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a,b, place[200009], mx=0;
    vector<pair<pair<int, int>, int>> times;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a >> b;
        times.push_back({{a, 1}, i});
        times.push_back({{b, 2}, i});
    }
    sort(times.begin(), times.end());

    for(pair<pair<int, int>, int> evt : times){
        if(evt.first.second == 1){
            if(pq.empty()){
                place[evt.second] = ++mx;
            }
            else{
                place[evt.second] = pq.top();
                pq.pop();
            }
        }
        else{
            pq.push(place[evt.second]);
        }
    }

    cout << mx << endl;
    for(int i=1; i<=n; i++){
        cout << place[i] << endl;
    }


}

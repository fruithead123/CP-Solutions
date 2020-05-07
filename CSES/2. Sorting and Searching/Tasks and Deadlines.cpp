
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, d;
    ll time = 0;
    ll cost = 0LL;
    vector<pair<ll, ll>> tasks;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> d;
        tasks.push_back({a, d});
    }
    sort(tasks.begin(), tasks.end());
    for(int i=0; i<n; i++){
        time += tasks.at(i).first;
        cost += (tasks.at(i).second - time);
    }
    cout << cost << endl;


}

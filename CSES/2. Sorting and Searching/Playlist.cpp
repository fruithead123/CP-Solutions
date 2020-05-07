
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, songs[200009];
    map<int, int> seen;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> songs[i];
        seen[songs[i]] = -1;
    }
    int best = 0;
    int start = 0;
    for(int i=0; i < n; i++){
        if(seen[songs[i]] < start){
            seen[songs[i]] = i;
        }
        else{
            //cout << start << " " << i << endl;
            best = max(best, i - start);
            start = seen[songs[i]] + 1;
            seen[songs[i]] = i;
        }
    }
    best = max(best, n - start);
    cout << best << endl;
}

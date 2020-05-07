
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k, ppl[200009], app[200009], ans=0;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> ppl[i];
    }
    for(int i=0; i<m; i++){
        cin >> app[i];
    }
    sort(ppl, ppl + n);
    sort(app, app + m);
    int pptr = 0;
    int aptr = 0;
    while(pptr < n && aptr < m){
        //cout << ppl[pptr] << " " << app[aptr] << endl;
        if((app[aptr] >= ppl[pptr] - k) && (app[aptr] <= ppl[pptr] + k)){
            ans++;
            pptr++;
            aptr++;
        }
        else if(app[aptr] <= ppl[pptr] - k){
            aptr++;
        }
        else{
            pptr++;
        }
    }
    cout << ans << endl;

}

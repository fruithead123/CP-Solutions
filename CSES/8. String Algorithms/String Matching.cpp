
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000009;

string str, pat;
ll A = 911382323;
ll B = 972663749;
ll h[1000009], p[1000009];

ll getHash(int a, int b){
    if(a == 0) return h[b];
    ll res = h[b] - (h[a-1]*p[b-a+1])%B;
    while(res < 0) res += B;
    return res;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> str >> pat;
    h[0] = (int)str[0];
    p[0] = 1;
    for(int i=1; i<str.size(); i++){
        h[i] = (A * h[i-1] + (int)str[i]) % B;
        p[i] = (A * p[i-1]) % B;
    }
    ll patHash = pat[0];
    for(int i=1; i<pat.size(); i++){
        patHash = (A * patHash + pat[i]) % B;
    }
    for(int i=pat.size()-1; i<str.size(); i++){
        if(patHash == getHash(i-pat.size()+1,i)) ans++;
    }
    cout << ans << endl;
}

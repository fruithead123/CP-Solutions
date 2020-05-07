
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000009;

string str, pat;
ll A = 911382327;
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

    cin >> str;
    int L = str.size();
    h[0] = (int)str[0];
    p[0] = 1;
    for(int i=1; i<L; i++){
        h[i] = (A * h[i-1] + (int)str[i]) % B;
        p[i] = (A * p[i-1]) % B;
    }

    for(int i=0; i<L-1; i++){
        if(getHash(0, i) == getHash(L-i-1,L-1)) cout << i+1 << " ";
    }
}

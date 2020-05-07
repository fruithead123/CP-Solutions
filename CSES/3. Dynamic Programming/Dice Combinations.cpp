
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll a1 = 1;
    ll a2 = 2;
    ll a3 = 4;
    ll a4 = 8;
    ll a5 = 16;
    ll a6 = 32;
    for(int i=1; i<n; i++){
        ll tmp = (a1+a2+a3+a4+a5+a6)%1000000007;
        a1=a2;
        a2=a3;
        a3=a4;
        a4=a5;
        a5=a6;
        a6=tmp;
    }
    cout << a1 << endl;
}

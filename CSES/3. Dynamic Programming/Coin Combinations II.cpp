
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> a(n), d(x+1);
    for(int i=0; i<n; i++){cin >> a[i];}
    d[0]=1;
    for(int c : a){
        for(int i=1; i<=x; i++){
            if(i-c>=0){
                d[i] = (d[i] + d[i-c])%1000000007;
            }
        }
    }
    cout << d[x] << endl;
}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int res = 0;
    for(int i=1; i<13; i++){
        res += n/pow(5,i);
    }
    cout << res << endl;
}

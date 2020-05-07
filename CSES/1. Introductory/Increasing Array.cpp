
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, cnt=0, prev, cur;
    cin >> n;
    for(long long i=0; i<n; i++){
        cin >> cur;
        if(i == 0){
            prev = cur;
        }
        else{
            if(cur - prev < 0){
                cnt += (prev - cur);
            }
            else{
                prev = cur;
            }
        }
    }
    cout << cnt << endl;
}

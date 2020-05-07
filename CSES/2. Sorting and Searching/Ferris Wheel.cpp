
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, w[200009];
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    sort(w, w + n);
    int left = 0;
    int right = n-1;
    int pairs = 0;
    while(left < right){
        if(w[left] + w[right] <= x){
            pairs++;
            left++;
            right--;
        }
        else{
            right--;
        }
    }
    cout << n-pairs << endl;

}

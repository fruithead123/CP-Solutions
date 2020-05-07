
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, nums[200009];
    int ans = 0;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int ptr1 = 0;
    int ptr2 = 0;
    int sum = nums[0];
    while(ptr2 < n){
        //printf("%d %d %d \n", ptr1, ptr2, sum);
        if(sum == x){
            ans++;
            if(ptr1 == ptr2){
                ptr2++;
                sum+=nums[ptr2];
            }
            else{
                sum -= nums[ptr1];
                ptr1++;
            }
        }
        else if(sum < x){
            ptr2++;
            sum += nums[ptr2];
        }
        else{
            sum -= nums[ptr1];
            ptr1++;
        }
    }
    cout << ans << endl;
}

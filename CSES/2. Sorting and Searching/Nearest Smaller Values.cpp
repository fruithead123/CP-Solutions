
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000009;

int n, nums[200009];
stack<pair<int,int>> stk;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin>> nums[i];
    }
    for(int i=0; i<n; i++){
        while(!stk.empty() && stk.top().first >= nums[i]) stk.pop();
        if(stk.empty()) cout << 0 << " ";
        else cout << stk.top().second << " ";
        stk.push({nums[i], i+1});
    }
}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, nums[200005];
set<int> st;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    for(int i=0; i<n; i++){
        st.insert(nums[i]);
        auto it = st.find(nums[i]);
        it++;
        if(it != st.end()){
            st.erase(it);
        }
    }
    cout << st.size() << endl;
}

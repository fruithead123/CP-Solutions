
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n, a;
    set <int> s;
    multiset <int> m;
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    for(int i = 1; i <= n; ++i) {
        cin >> a;
        auto l = s.lower_bound(a), r = --s.upper_bound(a);
        if(*l > a) --l;
        if(*r < a) ++r;
        auto f = m.find(*r - *l);
        if(f != m.end()) m.erase(f);
        m.insert(a - *l);
        m.insert(*r - a);
        s.insert(a);
        cout << *--m.end() << "\n";
    }
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int link[100009], sz[100009]; //link[x] -> next element towards representitive, sz[x] -> Size of component
int n,m,num,mx;


int fnd(int x){
    if(x == link[x]) return x;
    return link[x] = fnd(link[x]);
}

bool same(int a, int b){
    return fnd(a) == fnd(b);
}

void unite(int a, int b){
    a = fnd(a);
    b = fnd(b);
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
    num--;
    mx = max(mx, sz[a]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        link[i] = i;
        sz[i] = 1;
    }
    num = n;
    mx = 1;

    for(int i=0,a,b; i<m; i++){
        cin >> a >> b;
        if(!same(a,b)){
            unite(a,b);
        }
        cout << num << " " << mx << endl;
    }



}

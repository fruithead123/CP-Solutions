
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char grid[1000][1000];
char paths[1000][1000];
int n, m, x, y;
pair<int, int> a, b;
char last;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                a = {i,j};
            }
            if(grid[i][j] == 'B'){
                b = {i,j};
            }
        }
    }
    queue<pair<pair<int, int>, char>> q;
    q.push({{a.first, a.second}, 'S'});
    while(!q.empty()){
        pair<pair<int, int>, char> t = q.front(); q.pop();
        x = t.first.first;
        y = t.first.second;
        last = t.second;
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y] == '#'){continue;}
        if(grid[x][y] == 'B'){
            paths[x][y] = last;
            cout << "YES" << endl;
            string p = "";
            while(paths[x][y] != 'S'){
                if(paths[x][y] == 'L'){
                    p += "L";
                    y+=1;
                }
                else if(paths[x][y] == 'R'){
                    p += "R";
                    y-=1;
                }
                else if(paths[x][y] == 'U'){
                    p += "U";
                    x+=1;
                }
                else{
                    p += "D";
                    x-=1;
                }
            }
            reverse(p.begin(), p.end());
            cout << p.length() << endl;
            cout << p << endl;
            return 0;
        }

        paths[x][y] = last;
        grid[x][y] = '#';
        q.push({{x+1, y}, 'D'});
        q.push({{x-1, y}, 'U'});
        q.push({{x, y+1}, 'R'});
        q.push({{x, y-1}, 'L'});
    }
    cout << "NO" << endl;
}

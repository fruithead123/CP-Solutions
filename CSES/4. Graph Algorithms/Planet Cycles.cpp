
#include <bits/stdc++.h>
using namespace std;

//Find all cycles and compute their lengths

//For all nodes not in a cycle, push them into a queue and keep track of
//how long it takes to reach a cycle. Once we reach a cycle, we can update the ans for
//each node in the queue together and mark that we know their answer

//Visited[i] = 0 -> Node not visited
//Visited[i] = 1 -> We have been here, but dont know the answer to it
//Visited[i] = 2 -> We know the answer for this value

typedef long long ll;

int n, ans[200009], visited[200009], succ[200009],a,b;
queue<int> process;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> succ[i];
    }
    memset(visited, 0, sizeof visited);
    memset(ans, 0, sizeof ans);

    for(int i=1; i<=n; i++){
        //Floyd's cycle detection alg
        if(visited[i] == 0){
            visited[i] = 1;
            a = succ[i];
            b = succ[succ[i]];
            int done = 0;
            while(a != b){
                if(visited[a] == 2){ //A  previously found cycle should be disregarded
                    done = 1;
                    break;
                }
                visited[a] = 1;
                a = succ[a];
                b = succ[succ[b]];
            }
            if(done == 0){
                a = i;
                while(a != b){
                    a = succ[a];
                    b = succ[b];
                }
                int first = a;
                visited[a] = 2; //We will know the answer to all nodes in cycles
                int length = 1;
                a = succ[a];
                visited[a] = 2;
                while(a != first){
                    length++;   //Keep track of length of cycle
                    a = succ[a];
                    visited[a] = 2;
                }
                ans[a] = length;
                a = succ[a];
                while(a != first){
                    ans[a] = length; //update all the answers
                    a = succ[a];
                }
            }
        }
    }

    /*
    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    for(int i=1; i<=n; i++){
        cout << visited[i] << " ";
    }
    cout << endl;
    */
    for(int i=1; i<=n; i++){
        int tmp = i;
        if(visited[tmp] != 2){ //For all nodes that we still need to resolve:
            int dist = 0;
            while(visited[tmp] != 2){ //Get all nodes on the way until we find a node that we have already resolved
                process.push(tmp);
                tmp = succ[tmp];
                dist++;
            }
            while(!process.empty()){    //Update distances as required.
                ans[process.front()] = dist + ans[tmp];
                dist--;
                visited[process.front()] = 2;
                process.pop();
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
}

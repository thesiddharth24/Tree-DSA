#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100005];

int subtreeNode[100005];

void dfs(int node, int parent){

    
    if(graph[node].size() == 1 && graph[node][0] == parent){
        subtreeNode[node] = 1;
        return;
    }
    
    
    for(auto child:graph[node]){
        if(child != parent){
            dfs(child, node);
            subtreeNode[node] += subtreeNode[child];
        }
    }
    
    subtreeNode[node] += 1;

    
}
void solve(){


    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    dfs(1,0);

    for(int i = 1; i <= n; i++){
        cout<<i<<"-"<<subtreeNode[i]<<endl;
    }


}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    // Your code goes here
    return 0;
}




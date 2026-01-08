 //Q. For each node we need to find  max(abs(value[node]- value[y])) where y is the ancestor of the node


 #include <bits/stdc++.h>

using namespace std;

vector<int> graph[100005];


int val[100005];

int ans[100005];

void dfs(int node, int parent ,int mini , int maxi){
    
    //now ab ans cal karo
    ans[node] = max(abs(val[node] - mini),abs(val[node]-maxi));
    

    

    
    
    for(auto child:graph[node]){
        if(child != parent){
            dfs(child, node,min(val[child],mini),max(val[child],maxi));
            
        }
    }
    
  

    
}
void solve(){


    int n;
    cin>>n;
  
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    
    dfs(1,0,val[1],val[1]);

    for(int i = 1; i <= n; i++){
        cout<<i<<"-"<<ans[i]<<endl;
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




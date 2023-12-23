// ways to define graph
bool g[n][n];
vector<vector<int>>g;
vector<int>g[n];
multiset<int>g[n];
map<int,set<int >>g;

// dfs 
void dfs(int node ){
    vis[node]=1;
    for (auto &nbr :g[node]) {
        if(!vis[nbr]) dfs(nbr);
    }
}

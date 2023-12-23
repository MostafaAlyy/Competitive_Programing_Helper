// ways to define graph
bool g[n][n];
vector<vector<int>>g;
vector<int>g[n];
multiset<int>g[n];
map<int,set<int >>g;

/*
 * DFS
 * the time complexity of DFS is O(V + E)
 * The space complexity of DFS is O(V)
 */

void dfs(int node ){
    vis[node]=1;
    for (auto &nbr :g[node]) {
        if(!vis[nbr]) dfs(nbr);
    }
}

//if you want to know if the current node is leaf or not use this way
void dfs(int node){
    vis[node]=1;
    bool leaf=1;
    for (auto &nbr :g[node]) {
        if(!vis[nbr]) {
            dfs(nbr);
            leaf=0;
        }
    }
    if(leaf)
        ans++;
}


// ways to define graph
bool g[N][N];
vector<vector<int>>g;
vector<int>g[N];
multiset<int>g[N];
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

/*
 * Topological Sort
 * used when you have dependent things like tasks 
 * Topological sort is a linear ordering of the vertices of a directed graph such that for every directed edge u -> v, vertex u comes before vertex v in the ordering. 
 * Note: make DFS on every unvisited node to avoid leaving nodes 
 */
stack<int> stack1;
void dfs(int node ){
    vis[node]=1;
    for (auto &nbr :g[node]) {
        if(!vis[nbr])
            dfs(nbr);
    }
    stack1.push(node);
}
//print result
    while (!stack1.empty()){
        cout<<stack1.top()<<" ";
        stack1.pop();
    }



/*
 * Digkistra BFS  
 * the time complexity of DFS is O((V + E) log V)
 * The space complexity of DFS is O(V)
 *  finding the shortest path from the node to every other node and storing it in cost vector
 */
const int N=1e5+7;
vector<pair<ll,ll>>g[N];
vector<ll>cost(N,-1);

void dijkstra_shortest_path(ll start){
   fill(cost.begin(), cost.end(),-1);
    priority_queue<pair<ll,ll>,deque<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,start});
    while (!pq.empty()){
        pair<ll,ll> p = pq.top();
        ll node =p.second,node_cost=p.first;
        pq.pop();
        if(cost[node]!=-1) continue;

        cost[node]=node_cost;
        for(auto [nbr_cost,nbr]:g[node])
        {
            if(cost[nbr]==-1)
                pq.push({node_cost+nbr_cost,nbr});
        }
    }
}

// return the shortest path between start and the end
ll dijkstra_shortest_path(ll start ,ll end ){
    memset(vis,0,sizeof(vis));
    priority_queue<pair<ll,ll>,deque<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,start});
    while (!pq.empty()){
        pair<ll,ll> p = pq.top();
        ll node =p.second,node_cost=p.first;

        if(end==node) return node_cost;
        pq.pop();
        vis[node]=1;
        for(auto [nbr_cost,nbr]:g[node])
        {
            if(!vis[nbr])
                pq.push({node_cost+nbr_cost,nbr});
        }
    }
    return -1;
}
// return the shortest path between start and the end
// better at multi-test cases 
ll dijkstra_shortest_path(ll start ,ll end ,vector<bool> &vis,vector<pair<ll,ll>> g[]){
    priority_queue<pair<ll,ll>,deque<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,start});
    while (!pq.empty()){
        pair<ll,ll> p = pq.top();
        ll node =p.second,node_cost=p.first;

        if(end==node) return node_cost;
        pq.pop();
        vis[node]=1;
        for(auto [nbr_cost,nbr]:g[node])
        {
            if(!vis[nbr])
                pq.push({node_cost+nbr_cost,nbr});
        }
    }
    return -1;
}



const int N=507;
vector<pair<ll,ll>>g[N];
bool vis[N];
vector<vector<ll>>cost(N,vector<ll>(N,-1));
// finding the shortest path from every node to every other node and storing it in the cost matrix
void dijkstra_shortest_path_from_every_node_to_every_node(){
    for (int start = 0; start < N; ++start) {
        priority_queue<pair<ll,ll>,deque<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,start});
        while (!pq.empty()){
            pair<ll,ll> p = pq.top();   
            ll node =p.second,node_cost=p.first;
            pq.pop();
            if(cost[start][node]!=-1) continue;

            cost[start][node]=node_cost;
            for(auto [nbr_cost,nbr]:g[node])
            {
                if(cost[start][nbr]==-1)
                    pq.push({node_cost+nbr_cost,nbr});
            }
        }
    }

}


// get the the shortest path from start to end with each step in the vector path
const int N=1e5+7;
vector<pair<ll,ll>>g[N];
bool vis[N];
vector<ll>parent(N,-1);
ll dijkstra_shortest_path(int start, int end){
    vector<ll>distance(N,INT64_MAX);
    //{cost, node}
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>q;
    distance[start]=0;
    q.push({0, start});
    while(!q.empty()){
        int node=q.top().second;
        ll node_cost=q.top().first;
        q.pop();
        if(node==end) return distance[node];
        if(node_cost!= distance[node]) continue;
        for(auto [nbr_cost,nbr]:g[node]){

            if(distance[nbr]>distance[node]+nbr_cost){
                distance[nbr]=distance[node]+nbr_cost;
                q.push({distance[nbr], nbr});
                parent[nbr]=node;
            }
        }
    }
    return -1;
}

vector<ll> path;
void get_path(ll n){
    while(n!=-1){
        path.push_back(n);
        n=parent[n];
    }
}

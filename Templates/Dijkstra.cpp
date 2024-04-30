
/*
 * Digkistra BFS  
 * the time complexity of DFS is O((V + E) log V)
 * The space complexity of DFS is O(V)
 *  finding the shortest path from the node to every other node and storing it in cost vector
 */
const int N=5e5+7;
vector<pair<ll,ll>>g[N];
vector<ll>cost(N,INT64_MAX);
vector<bool> vis(N);
vector<int> par(N);



void dijkstra_shortest_path(int src) {
    fill(cost.begin(), cost.end(), INT64_MAX);
    fill(vis.begin(), vis.end(), false);
    fill(par.begin(), par.end(), -1);

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    cost[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        pair<ll,ll> p = pq.top();
        ll node =p.second,node_cost=p.first;
        pq.pop();

        if (vis[node]) continue;
        vis[node] = 1;

        cost[node] = min(cost[node], node_cost);
        for (auto [nbr_cost,nbr]:g[node]) {
            ll new_cost = cost[node] +nbr_cost;
            if (new_cost < cost[nbr]) {
                cost[nbr] = new_cost;
                par[nbr] = node;
                pq.push(make_pair(new_cost,nbr));
            }
        }
    }
}





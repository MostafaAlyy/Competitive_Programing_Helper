
class DSU{
public:
    int n;
    vector<int>parent, group_size;
    DSU(int _n) {        
        n=_n+1;
        parent.resize(n);
        group_size.resize(n, 1);
        // for(int i=0;i<n;i++) parent[i]=i;
        iota(parent.begin(), parent.end(), 0);
    }
    // Time Complexity: O(log n)
    inline int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u]= findParent(parent[u]);
    }
    // Time Complexity: O(log n)
    inline bool join(int u, int v){
        u= findParent(u);
        v= findParent(v);
        if(u==v) return false;
        if(group_size[u]>group_size[v]) 
            swap(u, v);             // I'm sure that group_size[v] is the greater
        parent[u]=v;
        group_size[v]+=group_size[u];
        return true;
    }
};

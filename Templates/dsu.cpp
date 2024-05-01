class DSU{
public:
    int n;
    vector<int>par, sz;
    DSU(int _n) : n(_n){        // used in main to initialize the size of my graph
//        n=_n+1;
        par.resize(n);
        sz.resize(n, 1);
//        for(int i=0;i<n;i++) par[i]=i;
        iota(par.begin(), par.end(), 0);
    }
    inline int findPar(int u){
        if(par[u]==u) return u;
        return par[u]= findPar(par[u]);
    }
    inline bool join(int u, int v){
        u= findPar(u);
        v= findPar(v);
        if(u==v) return false;
        if(sz[u]>sz[v]) swap(u, v);             // I'm sure that sz[v] is the greater
        par[u]=v;
        sz[v]+=sz[u];
        return true;
    }
};

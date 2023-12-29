#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
#define all(x) (x).begin(), (x).end()
#define FOR(i, n) for(int i=0;i<n;i++)
#define FOR1(i, n) for(int i=1;i<=n;i++)
#define MULTI_TEST_CASE 0

/*
 * replace int with the data type you want
 * if you want to make it from greater just replace less with greater
 */
typedef  tree<int, null_type,less_equal<>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;


//use this if you use ordered_multiset because normal erase do not work
void myerase(ordered_multiset &t, int v){
    int rank = t.order_of_key(v);
    auto it = t.find_by_order(rank); 
    t.erase(it);
}

void file();


void solve() {
    ordered_set st;
    int n;
    cin >> n;
    for (int i = 0 ; i < n;i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    // see what in st
    for (auto &it:st) {
        cout<<it<<" ";
    }
    cout << endl;

    // finding kth element
    cout << "0th element: " << *st.find_by_order(0) << endl;

    // finding number of elements smaller than X
    cout << "No. of elems smaller than 6: " << st.order_of_key(6) << endl; // 2

    // Remove elements
    st.erase(1);

}


int main() {
    IOS
    file();
    clock_t z = clock();
    int testCase = 1;
    if (MULTI_TEST_CASE)
        cin >> testCase;
    while (testCase--) {
        solve();
    }
    cerr << "Run Time : " << ((double) (clock() - z) / CLOCKS_PER_SEC);
}


void file() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

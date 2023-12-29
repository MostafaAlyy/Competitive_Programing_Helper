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

typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;



void myerase(ordered_set &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}

void file();


void solve() {
    ordered_multiset st;
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0 ; i < n;i++)
    {
        int x;
        cin >> x;
        st.insert(x);
        sum += st.order_of_key(x);
    }

    for (auto &it:st) {
        cout<<it<<" ";
    }
    cout<<endl;
    cout << sum << endl;


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

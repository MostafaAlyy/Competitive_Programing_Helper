#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...) 0
#define file(...)  0
#endif

#define endl "\n"
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define all(x) (x).begin(), (x).end()
#define FOR(i, n) for(int i=0;i<n;i++)
#define FOR1(i, n) for(int i=1;i<=n;i++)
#define MULTI_TEST_CASE 0



void solve() {

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




 /*
  the time complexity O(r)
  the space complexity  O(1).
  can't used with mod 
  */
ll nCr(ll n ,ll r){
    if(r>n)return 0;
    if(r==n)return 1;
    ll a=1,b=1;
    if(n-r<r)
        r=n-r;
    if(r!=0){
        while (r){
            a=a*n;
            b=b*r;
            ll g= __gcd(a,b);
            a=a/g;
            b=b/g;
            n--;
            r--;
        }
    }
    else
        a=1;
    return a;
}

 /*
  the time complexity O(n * r)
  the space complexity  O(n * r).
  Use this if you have a lot of queries less than n or  you want to use mod 
  */
//Bottom Up NCR % m 
vector<vector<int> > nCr(int n,int r){

    vector< vector<int> > table(n + 1, vector<int>(r+1,0));

    for(int i=0; i<=n; i++){
        for(int j=0; j<= min(i,r); j++){

            //base case 
            if(j==0 || j == i){
                table[i][j] = 1;
            }
            else{
                table[i][j] = (table[i-1][j-1] + table[i-1][j]);
                //If you want to add a mod add it here         ^
            
            }
        }
    }
    return table;

}



 /*
  the time complexity O(n )
  the space complexity  O(n ).
  factorial n = permutation n 
  */

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}


 /*
  the time complexity O(n )
  the space complexity  O(n ).
  factorial n = permutation n 
  use this if you want to use factorial many times
  */
const int N = 21;
ull f[N];
void initFactorial(){
    f[0]=1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i;
    }
}


// nCr with mod 
unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}


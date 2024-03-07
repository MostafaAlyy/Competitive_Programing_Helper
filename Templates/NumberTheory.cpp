/*
 * Fast power
 * the time complexity is O(log(b))
 * The space complexity is O(log(b))
 */
ll power(ll a,ll b)
{
    if(b==0)return 1;
    ll x=power(a,b/2);
    x*=x;
    if(b%2!=0)x*=a;
    return x;
}
//if you have a mod 
ll pow_mod(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}

/*
 * to know if the number is prime 
 * the time complexity is O(sqrt(n))
 * The space complexity is O(1)
 */
bool is_prime(ll n)
{
    if(n==1||n==0)return 0;
    else if(n==2)return 1;
    else if(n%2==0)return 0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

/*
 * to know all prims from 0 to N
 * the time complexity is O(N log(log(N)))
 * The space complexity is O(N)
 */
vector<bool> isPrime(N,true);
void sieve()
{
    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i=2;i*i<N;i++)
    {
        if(isPrime[i])
        {
            for(ll j=i*i;j<N;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}


/*
 * if you have equation ax+by=gcd(a,b) and you want to know the x and y 
 * this function return gcd
 * the time complexity is O(log(n))
 * The space complexity is O(log(n))
 */

ll  extended_euclid(ll a,ll b,ll &x,ll &y ){
    if(b==0){
        x=1,y=0;
        return a;
    }
    ll g= extended_euclid(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}


// to use mod use this functions 
ll add(ll a,ll b)
{
    return ((a%mod)+(b%mod))%mod;
}
ll mul(ll a,ll b)
{
    return ((a%mod)*(b%mod))%mod;
}
ll sub(ll a,ll b)
{
    return ((((a%mod)-(b%mod))%mod)+mod)%mod;
}
ll divide(ll a,ll b)
{
    return mul(a,powmod(b,mod-2));
}



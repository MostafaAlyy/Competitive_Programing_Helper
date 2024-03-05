/*
 * Fast power
 * the time complexity is O(log(b))
 * The space complexity is O(log(b))
 */
int fastPow(int a, int b, int m) 
{
    if (b == 0) return 1;
    int res = fastPow(a, b / 2,m);
    if (b % 2) return ((res * res)%m * a%m)%m;
    else return (res * res)%m;
}

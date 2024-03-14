bool get_bit(ll n,int i)
{
    return (n>>i)&1;
}
ll set_bit(ll n,int i)
{
    return n|(1<<i);
}
ll reset_bit(ll n,int i)
{
    return n&(~(1<<i));
}
ll flip_bit(ll n,int i)
{
    return n^(1<<i);
}

void clear_bits_in_range(int &n,int i,int j){
    int a=(~0)<<(j+1);
    int b=(1<<i) -1;
    int mask=a|b;
    n=n&mask;
}

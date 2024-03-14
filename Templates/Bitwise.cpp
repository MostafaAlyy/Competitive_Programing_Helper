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

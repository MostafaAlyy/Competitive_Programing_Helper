
 /*
  the time complexity O(r)
  the space complexity  O(1).
  */
ll nCr(ll n ,ll r){
    ll a=1,b=1;
    if(n-r<r)
        r=n-r;
    if(r!=0){
        while (r){
            a=a*n;
            b=b*r;
            ll g= gcd(a,b);
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
vector<vector<int> > binomialCoefficient(int n,int r){

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


#include <bits/stdc++.h>
#define llt long long int
#define MOD 1000000007
using namespace std;
 
vector<bool> genSieve(llt n)
{
    vector<bool> sieve(n+1);
    fill(sieve.begin(),sieve.end(),true);
    
    for(llt i=2;i<=sqrt(n);i++)
    {
        if(sieve[i])
        {
            for(llt j=i*i;j<=n;j+=i)
                sieve[j] = false;
        }
    }
    
    return sieve;
}
 
llt solve(llt k, vector<bool> prime)
{
    llt ans=1;
    for(llt j=2;j<=k;j++)
    {
        if(prime[j] == false)
            continue;
 
        llt p=0;
        for(llt z=j;k/z>0;z=z*j)
            p+=(k/z);
 
        ans=(ans*(p+1))%MOD;
    }
    
    return ans;
}
 
int main()
{
    llt t;
    cin >> t;
    
    vector<bool> prime = genSieve(50000);
    while(t--)
    {
        llt k;
        cin >> k;
        
        llt ans = solve(k,prime);
        cout << ans << endl;
    }
    return 0;
} 
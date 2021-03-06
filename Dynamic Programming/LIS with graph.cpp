/**
Bismillahir Rahmanir Rahim
MD. Iqbal Hossain Bappy
Dept. of CSE, CoU
**/

#include<bits/stdc++.h>
#include<queue>
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scln(x)                 sc("%lld",&(x))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))
#define pb(a)                   push_back(a)
#define mp                      make_pair
#define db                      double
#define EPS                     10E-10
#define ff                      first
#define ss                      second
#define sqr(x)                  (x)*(x)
#define vi                      vector<int>
#define vl                      vector<ll>
#define vii                     vector<vector<int> >
#define vll                     vector<vector<ll> >
#define DBG                     pf("HI\n")
#define MOD                     1000000007
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                2147483647;
#define longlimit               9223372036854775808
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

///------------------Graph Moves-------------------
/// const int fx[] = {+1,-1,+0,+0};
/// const int fy[] = {+0,+0,+1,-1};
/// const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
/// const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
/// const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
/// const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

int n=7;
int value[]={-1000000,5,0,9,2,7,3,4};
int dp[1000],dir[1000];

/**Printing Soln**/
void solution(int start)
{
    while(dir[start] != -1)
    {
        pf("Index %d ; value = %d\n",start,value[start]);
        start=dir[start];
    }
}

int longest(int u)
{
    if(dp[u] != -1)
        return dp[u];
    int maxi=0;
    for(int v=u+1;v<=n;v++)
    {
        if(value[v] > value[u])
        {
            if(longest(v) > maxi)
            {
                maxi=longest(v);
                dir[u]=v;
            }
        }
    }
    return dp[u]=1+maxi;
}
int main()
{
    ms(dp,-1);
    ms(dir,-1);
    int LIS=0,start,i;
    for(int i=1;i<=n;i++)
    {
        if(longest(i) > LIS)
        {
            LIS=longest(i);
            start=i;
        }
    }
    pf("LIS = %d , starting point %d\n\n\n",LIS,start);
    solution(start);
    return 0;
}


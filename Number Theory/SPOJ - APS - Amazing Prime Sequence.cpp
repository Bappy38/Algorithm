#include<bits/stdc++.h>

#define Input                   freopen("in.txt","r",stdin)
#define Output                  freopen("out.txt","w",stdout)
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)              sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)              sc("%lld %lld",&(x),&(y))
#define pf                      printf
#define all(a)                  (a.begin()),(a.end())
#define UNIQUE(X)               (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)          (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
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
#define intlimit                2147483690
#define longlimit               92233720368547758
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

bool mark[10000002];
ll SF[10000002];
void Sieve(int n)
{
    int i,j,sqrtN=(int)sqrt(n*1.0)+2;
    mark[0]=1;
    mark[1]=1;
    SF[0]=0;
    SF[1]=0;
    SF[2]=2;
    for(i=4 ; i<=n ; i+=2)
    {
        mark[i]=1;
        SF[i]=2;
    }
    for(i=3 ; i<=n ; i+=2)
    {
        if(!mark[i])
        {
            SF[i]=i;
            if(i <= sqrtN)
            {
                for(j=i*i ; j<=n ; j+=(2*i))
                {
                    mark[j]=1;
                    SF[j]=i;
                }
            }
        }
    }
}
void FuN(int n)
{
    for(int i=2 ; i<=n ; i++)
        SF[i] += SF[i-1];
}
int main()
{
    Sieve(10000000);
    FuN(10000000);
    int i,j,k,n,t,T;
    ll ans;
    scin(T);
    RUN_CASE(t,T)
    {
        scin(n);
        ans = SF[n];
        pf("%lld\n",ans);
    }
    return 0;
}


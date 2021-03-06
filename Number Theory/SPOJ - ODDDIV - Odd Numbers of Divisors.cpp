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
#define longlimit               9223372036854775800
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

#define sz 100005
bool mark[sz];
vl Prime;

void Sieve(ll n)
{
    mark[1] = 1;
    Prime.pb(2);
    for(ll i=4 ; i<=n ; i+=2)
        mark[i] = 1;
    for(ll i=3 ; i<=n ; i+=2){
        if(!mark[i]){
            Prime.pb(i);
            if(i*i <= n){
                for(ll j=i*i ; j<=n ; j+=(2*i))
                    mark[j] = 1;
            }
        }
    }
}

map<ll , ll>factor;
map<ll , ll>:: iterator it;
void primeFactorize(ll n)
{
    factor.clear();
    for(int i=0 ; i<(int)Prime.size() && Prime[i]*Prime[i]<=n ; i++){
        if(n%Prime[i] == 0){
            while(n%Prime[i] == 0){
                factor[Prime[i]]++;
                n /= Prime[i];
            }
        }
    }
    if(n > 1){
        factor[n]++;
    }
}

vector<pll>v;   ///First-NOD of n ; Second-n

void Solve(int t)
{
    ll i,j,k,lo,hi,ans;
    sc("%lld %lld %lld",&k,&lo,&hi);
    ll lb = lower_bound(v.begin() , v.end() , make_pair(k , lo))-v.begin();
    ll ub = upper_bound(v.begin() , v.end() , make_pair(k , hi))-v.begin();
    ans = ub-lb;
    pf("%lld\n",ans);
}

void Process()
{
    for(ll i=2 ; i*i<=1e10 ; i++){
        ll x = i*i;
        ll NOD = 1;
        primeFactorize(x);
        for(it=factor.begin() ; it!=factor.end() ; it++){
            NOD *= (it->second + 1);
        }
        v.pb(make_pair(NOD , x));
    }
    sort(v.begin() , v.end());
}

int main()
{
    Sieve(100000);
    Process();
    int t,T;
    T = 1;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}



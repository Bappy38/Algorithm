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


/** You're given a tree with n(<=1e5) nodes. There'll be q(<=1e5) query. In each query
you'll given two integers u & v.You've to tell is node u is an ancestor of node v or not? **/

#define sz 100005
int tim=0,start[sz],finish[sz],vis[sz];
vi graph[sz];

void DFS(int u)
{
    start[u] = ++tim;
    vis[u] = 1;
    for(auto v:graph[u]){
        if(!vis[v])
            DFS(v);
    }
    finish[u] = ++tim;
}

void Solve(int t)
{
    int i,j,k,n,u,v,q;
    scin2(n , q);
    for(i=1 ; i<=n-1 ; i++){
        scin2(u , v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    DFS(1);
    for(i=1 ; i<=q ; i++){
        scin2(u , v);
        if(start[v]>=start[u] && finish[v]<=finish[u])
            pf("YES\n");
        else
            pf("NO\n");
    }
}

int main()
{
    int t,T;
    T = 1;
//    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
/**
7 5
1 2
1 3
2 4
2 5
3 6
6 7
1 2
1 5
3 4
2 6
3 7
**/


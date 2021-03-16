///****In the name of ALLAH, most Gracious, most Compassionate****//
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
#define MOD                     1000000000
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
#define coutv(v)                for(auto it:v)cout<<it<<' ';cout<<'\n';
#define cinv(v)                 for(auto &it:v)cin>>it;
#define srt(v)                  sort(v.begin(),v.end());
#define rsrt(v)                 sort(v.rbegin(),v.rend());
#define rvs(v)                  reverse(v.begin(),v.end());

using namespace std;


#define sz 200009
struct edge
{
    int u,v,w;
    edge(){}
    edge(int _u,int _v,int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (const edge &p)const{
        return w > p.w;
    }
};
vector<edge>ed;

int n,m,par[sz],Size[sz];
ll ans = 0 , totpair = 0;

void makeSet(int n)
{
    for(int i=1 ; i<=n ; i++){
        par[i] = i;
        Size[i] = 1;
    }
}

int findSet(int u)
{
    if(par[u] == u)
        return u;
    return par[u] = findSet(par[u]);
}

void unionSet(int u,int v,int w)
{
    int paru = findSet(u);
    int parv = findSet(v);

    if(paru == parv){
        ll cnt = ((totpair%MOD) * w)%MOD;
        ans = (ans + cnt)%MOD;
        return;
    }

    ll temp = ((ll)Size[paru] * (Size[paru] - 1))/2;    ///Subtract number of pair of this component
    totpair -= temp;

    temp = ((ll)Size[parv] * (Size[parv] - 1))/2;       ///Subtract number of pair of this component
    totpair -= temp;

    ll newsz = Size[paru] + Size[parv];             ///Add number of pair of new component
    temp = (newsz * (newsz - 1))/2;
    totpair += temp;

    if(Size[paru] < Size[parv])
        swap(paru , parv);
    par[parv] = paru;
    Size[paru] += Size[parv];

    ll cnt = ((totpair%MOD) * w)%MOD;
    ans = (ans + cnt)%MOD;
}

void Solve(int t)
{
    int i,j,k,u,v,w;
    scin2(n , m);
    for(i=1 ; i<=m ; i++){
        sc("%d %d %d",&u,&v,&w);
        ed.pb(edge(u , v , w));
    }
    sort(ed.begin() , ed.end());

    makeSet(n);
    for(i=0 ; i<m ; i++){
        unionSet(ed[i].u , ed[i].v , ed[i].w);
    }
    pf("%lld\n",ans%MOD);
}

int main()
{
    int t,T;
    T = 1;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

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
/**     toint, tostring, BigMod, Power , sieve, Primefactorize ,frequency in n!     **/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1; i>=0; i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//string tostring(ll x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}
//vector<ll>Prime;
//bool mark[10000003];
//void sieve(ll n){ll i,j;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i*i<=n){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//map<ll,ll>Factor;
//void Primefactorize(ll n){for(ll i=0; i<Prime.size() && Prime[i]*Prime[i]<=n; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){Factor[Prime[i]]++;n/=Prime[i];}}}if(n>1){Factor[n]++;}}
//ll frequency(ll n,ll factor)/** Frequency of a factor in n! **/{ll cnt=0;while(n){cnt += (n/factor);n /= factor;}return cnt;}
/**     Order Set       **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(0)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

/** LCA problem **/
/** You're given a rooted tree .Find the length of the shortest and the length
of the longest road on the path between the two given nodes. **/

#define sz 100005
bool vis[sz];
int parent[sz],level[sz];
vi graph[sz];
map<pii , int>cost;
void BFS(int start)
{
    ms(parent,-1);
    ms(level,0);
    ms(vis,0);
    queue<int>q;
    vis[start] = 1;
    level[start] = 0;
    q.push(start);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0 ; i<graph[u].size() ; i++)
        {
            int v=graph[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                level[v] = 1+level[u];
                parent[v] = u;
                q.push(v);
            }
        }
    }
}
struct info
{
    int par,lowest,highest;
    info() {}
    info(int a,int b,int c)
    {
        par=a;
        lowest=b;
        highest=c;
    }
}sptable[sz][20];
void Init(int n)
{
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<20 ; j++)
            sptable[i][j] = info(-1,infinity,0);
    }
}
void LCA_Init(int n)
{
    Init(n);
    for(int i=1 ; i<=n ; i++){
        sptable[i][0].par = parent[i];
        if(parent[i] != -1){
            sptable[i][0].lowest = min(sptable[i][0].lowest, cost[make_pair(i,parent[i])]);
            sptable[i][0].highest = max(sptable[i][0].highest, cost[make_pair(i,parent[i])]);
        }
    }
    for(int j=1 ; (1<<j)<=n ; j++){
        for(int i=1 ; i<=n ; i++){
            if(sptable[i][j-1].par != -1){
                sptable[i][j].par = sptable[sptable[i][j-1].par][j-1].par;
                sptable[i][j].lowest = min(min(sptable[i][j].lowest,sptable[i][j-1].lowest) , sptable[sptable[i][j-1].par][j-1].lowest);
                sptable[i][j].highest = max(max(sptable[i][j].highest,sptable[i][j-1].highest) , sptable[sptable[i][j-1].par][j-1].highest);
            }
        }
    }
}
pii LCA_Query(int n,int p,int q)
{
    if(p == q)return make_pair(0,0);
    pii ret = make_pair(infinity,0);
    if(level[p] < level[q])
        swap(p,q);
    int Log=0;
    while(1)
    {
        int nxt = Log+1;
        if((1<<nxt) > level[p])
            break;
        Log++;
    }
    for(int i=Log ; i>=0 ; i--){
        if(level[p]-(1<<i) >= level[q]){
            ret.first = min(ret.first , sptable[p][i].lowest);
            ret.second = max(ret.second , sptable[p][i].highest);
            p = sptable[p][i].par;
        }
    }
    if(p == q)
        return ret;
    for(int i=Log ; i>=0 ; i--)
    {
        if(sptable[p][i].par!=-1 && sptable[p][i].par!=sptable[q][i].par)
        {
            ret.first = min(ret.first , min(sptable[p][i].lowest , sptable[q][i].lowest));
            ret.second = max(ret.second , max(sptable[p][i].highest , sptable[q][i].highest));
            p=sptable[p][i].par;
            q=sptable[q][i].par;
        }
    }
    ret.first = min(ret.first , cost[make_pair(p,parent[p])]);
    ret.first = min(ret.first , cost[make_pair(q,parent[q])]);
    ret.second = max(ret.second , cost[make_pair(p,parent[p])]);
    ret.second = max(ret.second , cost[make_pair(q,parent[q])]);
    return ret;
}
int main()
{
    int i,j,k,n,small,big,u,v,w,q;
    scin(n);
    rep(i,2,n)
    {
        scin2(u,v);
        scin(w);
        graph[u].pb(v);
        graph[v].pb(u);
        cost[make_pair(u,v)]=w;
        cost[make_pair(v,u)]=w;
    }
    BFS(1);
    LCA_Init(n);
    scin(q);
    rep(i,1,q)
    {
        scin2(u,v);
        pii ans = LCA_Query(n,u,v);
        pf("%d %d\n",ans.first,ans.second);
    }
    return 0;
}


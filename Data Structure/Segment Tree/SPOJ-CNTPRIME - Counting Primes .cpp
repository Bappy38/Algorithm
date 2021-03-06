/** Assignment on segment with lazy **/

#include<bits/stdc++.h>

#define Input                   freopen("in.txt","r",stdin)
#define Output                  freopen("out.txt","w",stdout)
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)                sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)                sc("%lld %lld",&(x),&(y))
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
#define MOD                     100000007
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                214748369
#define longlimit               922337203685477580
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;
/** toint, tostring, BigMod, sieve, Primefactorize **/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1;i>=0;i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//string tostring(ll n){string s="";ll x;while(n > 0){x=n%10;s +=(char)(x+'0');n/=10;}reverse(s.begin(),s.end());return s;}
//ll BigMod(ll a,ll b,ll m){if(b == 0)return 1%m;else if(b%2 == 0){ll temp=BigMod(a,b/2,m);return ((temp%m)*(temp%m))%m;}else{return ((a%m)*BigMod(a,b-1,m)%m)%m;}}
//ll power(ll a,ll n){ll ans=1;if(n == 0)return 1;else if(n == 1)return a;else return a*power(a,n-1);}
//vector<int>List;
//void Primefactorize(int n){for(int i=0; Prime[i]*Prime[i]<=n ; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){List.push_back(Prime[i]);n/=Prime[i];}}}if(n>1)List.push_back(n);}

/** Order Set **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5

bool mark[1000009];
void sieve(int n)
{
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}
#define sz 10005
struct info
{
    int prop,sum;
} tree[sz*4];
int ara[sz];

void reset()
{
    for(int i=0; i<=40004; i++)
    {
        tree[i].sum=0;
        tree[i].prop=-1;
    }
}
void init(int node,int b,int e)
{
    if(b == e)
    {
        if(mark[ara[b]] == 0)
            tree[node].sum=1;
        else
            tree[node].sum=0;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int b,int e,int i,int j,int val)
{
    if(tree[node].prop != -1)
    {
        tree[node].sum=(e-b+1)*tree[node].prop;
        if(b != e)
        {
            tree[node*2].prop=tree[node].prop;
            tree[node*2+1].prop=tree[node].prop;
        }
        tree[node].prop=-1;
    }
    if(b>e || i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum=(e-b+1)*val;
        if(b != e)
        {
            tree[node*2].prop=val;
            tree[node*2+1].prop=val;
        }
        return;
    }
    int mid=(b+e)/2;
    update(node*2,b,mid,i,j,val);
    update(node*2+1,mid+1,e,i,j,val);
    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
int query(int node,int b,int e,int i,int j)
{
    if(b>e || i>e || j<b)
        return 0;
    if(tree[node].prop != -1)
    {
        tree[node].sum=(e-b+1)*tree[node].prop;
        if(b != e)
        {
            tree[node*2].prop=tree[node].prop;
            tree[node*2+1].prop=tree[node].prop;
        }
        tree[node].prop=-1;
    }
    if(b>=i && e<=j)
        return tree[node].sum;
    int mid=(b+e)/2;
    int p1=query(node*2,b,mid,i,j);
    int p2=query(node*2+1,mid+1,e,i,j);
    return p1+p2;
}
int main()
{
    sieve(1000005);
    int i,j,t,T,cmd,x,y,val,n,q,ans;
    scin(T);
    RUN_CASE(t,T)
    {
        reset();
        ms(ara,0);
        scin2(n,q);
        for(i=1; i<=n; i++)
            scin(ara[i]);
        init(1,1,n);
        pf("Case %d:\n",t);
        for(i=1; i<=q; i++)
        {
            scin(cmd);
            scin2(x,y);
            if(cmd == 0)
            {
                scin(val);
                if(mark[val] == 0)
                    update(1,1,n,x,y,1);
                else
                    update(1,1,n,x,y,0);
            }
            else
            {
                ans=query(1,1,n,x,y);
                pf("%d\n",ans);
            }
        }
    }
    return 0;
}

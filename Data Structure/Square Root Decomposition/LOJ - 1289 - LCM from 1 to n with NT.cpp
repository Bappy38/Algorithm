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
#define MOD                     4294967296
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                2147483690
#define longlimit               92233720368547758
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (((a)/(gcd(a,b)))*b)
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

bool Check(unsigned int N,unsigned int pos)
{
    return (bool)(N & (1<<pos));
}
unsigned int Set(unsigned int N,unsigned int pos)
{
    return N=N | (1<<pos);
}
unsigned int Prime[5761459],nPrime;
unsigned int status[3125002];
void Sieve(unsigned int n)
{
    unsigned int i,j,sqrtN;
    sqrtN = ( sqrt(n*1.0)) +2;
    for(i=3 ; i<=sqrtN ; i+=2)
    {
        if(Check(status[i>>5], i&31) == 0)
        {
            for(j=i*i ; j<=n ; j+=(i<<1))
                status[j>>5] = Set(status[j>>5], j&31);
        }
    }
    Prime[nPrime++]=2;
    status[1>>5] = Set(status[1>>5] , 1&31);
    for(i=4 ; i<=n ; i+=2)
        status[i>>5] = Set(status[i>>5] , i&31);
    for(i=3 ; i<=n ; i+=2)
    {
        if(Check(status[i>>5], i&31) == 0)
            Prime[nPrime++]=i;
    }
}
unsigned int Power(unsigned int a,unsigned int n)
{
    unsigned int ret=1;
    for(unsigned int i=1 ; i<=n ; i++)
        ret *= a;
    return ret;
}
/** Square root decomposition **/
unsigned int block[2405];
unsigned int blockSize = 2401,sz;
void Build()
{
    for(unsigned int i=0 ; i<=blockSize ; i++)
        block[i] = 1;
    for(unsigned int i=0 ; i<sz ; i++)
        block[i/blockSize] *= Prime[i];
}
unsigned int Query(unsigned int lft,unsigned int rgt)
{
    unsigned int sourceBlock,destBlock,nxtBlock,prevBlock;
    unsigned int mul = 1;
    sourceBlock = lft/blockSize;
    destBlock = rgt/blockSize;
    if(sourceBlock == destBlock)    /** IF left and right r existing in same block **/
    {
        for(unsigned int i=lft ; i<=rgt ; i++)
            mul *= Prime[i];
    }
    else
    {
        nxtBlock = sourceBlock+1;
        prevBlock = destBlock-1;
        for(unsigned int i=lft ; i<=nxtBlock*blockSize-1 ; i++)
            mul *= Prime[i];      /** Multiply 1st partially relevant block **/
        for(unsigned int i=nxtBlock ; i<=prevBlock ; i++)
            mul *= block[i];    /** Multiply all fully relevant block **/
        for(unsigned int i=destBlock*blockSize ; i<=rgt ; i++)
            mul *= Prime[i];      /** Multiply last partially relevant block **/
    }
    return mul;
}
int main()
{
    unsigned int i,j,k,t,T,n,x,lftid,rgtid;
    unsigned int temp,ans,p,fre,mx,lo,hi,mid;
    Sieve(100000000);
    sz = nPrime;
    Build();
    sc("%u",&T);
    RUN_CASE(t,T)
    {
        ans=1;
        sc("%u",&n);
        for(i=0 ; i<nPrime && Prime[i]*Prime[i]<=n ; i++)
        {
            p = Prime[i];
            mx = floor((log10(1e9*1.0)/log10(p*1.0))); /** logp(n) = log10(n)/log10(p) ; maximum frequency of this factor for a number from 1 to n **/
            lo=0;hi=mx;fre=0;
            while(lo <= hi)
            {
                mid = (lo+hi)/2;
                if(Power(p,mid) == n)
                {
                    fre=mid;
                    break;
                }
                else if(Power(p,mid) < n)
                {
                    fre=mid;
                    lo=mid+1;
                }
                else
                    hi=mid-1;
            }
            temp = Power(p,fre);
            ans *= temp;
        }
        /** Now multiply the prime numbers greater than sqrt(n) and less or equal n ;
         bcoz their frequency will be one ; Try to solve this task with below sqrt(n)
         complexity **/
        /** Here, we'll apply square root decomposition to do this task **/
        if(Prime[i] <= n)
        {
            lftid = lower_bound(Prime , Prime+nPrime , Prime[i])-Prime;
            rgtid = lower_bound(Prime , Prime+nPrime , n)-Prime;
            if(Check(status[n>>5] , n&31) == 1)
                rgtid -= 1;
            temp = Query(lftid , rgtid);
            ans *= temp;
        }
        pf("Case %u: %u\n",t,ans);
    }
    return 0;
}

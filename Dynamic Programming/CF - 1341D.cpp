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
#define infinity                (1<<18)
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
//ll BigMod(ll a,ll b){if(b == 0)return 1%MOD;else if(b%2 == 0){ll temp=BigMod(a,b/2);return ((temp%MOD)*(temp%MOD))%MOD;}else{return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;}}
//ll Power(ll a,ll n){ll ret=1;for(ll i=1 ; i<=n ; i++)ret = ((ret%MOD)*(a%MOD))%MOD;return ret;}
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

inline int add(int a, int b) {a += b; return a >= MOD ? a - MOD : a;}
inline int sub(int a, int b) {a -= b; return a < 0 ? a + MOD : a;}
inline int mul(int a, int b) {return (ll) a * b % MOD;}
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

//string small = "abcdefghijklmnopqrstuvwxyz";
//string capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move


int d[15][10];
void ajaira()
{
    d[0][0]=1; d[0][1]=1; d[0][2]=1; d[0][3]=0; d[0][4]=1; d[0][5]=1; d[0][6]=1;
    d[1][0]=0; d[1][1]=0; d[1][2]=1; d[1][3]=0; d[1][4]=0; d[1][5]=1; d[1][6]=0;
    d[2][0]=1; d[2][1]=0; d[2][2]=1; d[2][3]=1; d[2][4]=1; d[2][5]=0; d[2][6]=1;
    d[3][0]=1; d[3][1]=0; d[3][2]=1; d[3][3]=1; d[3][4]=0; d[3][5]=1; d[3][6]=1;
    d[4][0]=0; d[4][1]=1; d[4][2]=1; d[4][3]=1; d[4][4]=0; d[4][5]=1; d[4][6]=0;
    d[5][0]=1; d[5][1]=1; d[5][2]=0; d[5][3]=1; d[5][4]=0; d[5][5]=1; d[5][6]=1;
    d[6][0]=1; d[6][1]=1; d[6][2]=0; d[6][3]=1; d[6][4]=1; d[6][5]=1; d[6][6]=1;
    d[7][0]=1; d[7][1]=0; d[7][2]=1; d[7][3]=0; d[7][4]=0; d[7][5]=1; d[7][6]=0;
    d[8][0]=1; d[8][1]=1; d[8][2]=1; d[8][3]=1; d[8][4]=1; d[8][5]=1; d[8][6]=1;
    d[9][0]=1; d[9][1]=1; d[9][2]=1; d[9][3]=1; d[9][4]=0; d[9][5]=1; d[9][6]=1;
}
string s[2005];
int n,k,lagbe[2005][15];

void karKotoLagbe()
{
    for(int i=1 ; i<=n ; i++){
        for(int x=0 ; x<=9 ; x++){
            int cnt = 0;
            for(int z=0 ; z<7 ; z++){
                if(s[i][z]=='1' && d[x][z]==0){
                    lagbe[i][x] = infinity;
                    break;
                }
                if(s[i][z]=='0' && d[x][z]==1)
                    cnt++;
            }
            lagbe[i][x] += cnt;
        }
    }
}

bool vis[3005][3005];
int dp[3005][3005];

int FuN(int pos,int usedk)
{
    if(pos>n){
        if(pos==n+1 && usedk==k)
            return dp[pos][usedk] = 1;
        else
            return dp[pos][usedk] = 0;
    }
    if(vis[pos][usedk])
        return dp[pos][usedk];
    int ret1 = 0;
    for(int i=0 ; i<=9 ; i++){
        if(usedk + lagbe[pos][i] <= k)
            ret1 |= FuN(pos+1 , usedk+lagbe[pos][i]);
        else
            ret1 |= 0;
    }
    vis[pos][usedk] = 1;
    return dp[pos][usedk] = ret1;
}

void Print(int pos,int usedk)
{
    if(pos>n){
        if(pos == n+1 && usedk==k){
            pf("\n");
            return;
        }
    }
    int mx = -1;
    for(int i=0 ; i<=9 ; i++){
        if(usedk + lagbe[pos][i] <= k){
            if(dp[pos+1][usedk+lagbe[pos][i]] == 1)
                mx = i;
        }
    }
    if(mx != -1)
        pf("%d",mx);
    Print(pos+1 , usedk+lagbe[pos][mx]);
}

void Solve(int t)
{
    int i,j;
    scin2(n , k);
    for(i=1 ; i<=n ; i++)
        cin>>s[i];
    ajaira();
    karKotoLagbe();
    if(FuN(1 , 0))
        Print(1 , 0);
    else
        pf("-1\n");
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
1 5
0010100

10 0
0111010
1101111
1111011
0111010
1101011
1101011
1110111
1010010
1111111
0010010
ANS: 4694550781
**/

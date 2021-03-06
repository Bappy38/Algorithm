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

///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

/** Suffix Array Template **/
///1.   Longest Common Substring of two string:
        Create a new string str = s1+'@'+s2+'$'; Build its suffix array. len1 = s1.size() ; n = str.size()
        for(i=1 ; i<n ; i++){
            if((arr[i].idx<len1 && arr[i-1].idx>len1) || (arr[i-1].idx<len1 && arr[i].idx>len1))
                ans = max(ans , lcp[i]);
        }
///2.  IF you're given a string with length n(n = length without special character ; but u must have to add a special character that haven't used yet). Then number of unique substring of that string = ((n*(n+1))/2) - Summation of LCP Array ;
///3.  Longest Repeating substring in a string is marked by the maximum value in the LCP array.
///4.  Count the number of distinct substring of a given string s, those length between [p,q]
        tot = (n*(n+1))/2;  /**Total number of substring**/
        for(i=1 ; i<p ; i++)    /**Subtract the number of sub string those length are less than p**/
            tot -= (n-i+1);
        for(i=q+1 ; i<=n ; i++) /**Subtract the number of sub string those length are greater than q**/
            tot -= (n-i+1);
        for(i=1 ; i<=n ; i++){
            if(lcp[i] >= q) /**Subtract duplicate substring of length [p,q]**/
                tot -= (q-p+1);
            else if(lcp[i] >= p)    /**Subtract duplicate substring of length [p,LCP[i]]**/
                tot -= (lcp[i]-p+1);
        }
///Notes are end. Template begins here
#define sz 500005
struct info{
    int tup[2],idx; /// tup[0]-previous rank ; tup[1]-new rank
    bool operator < (const info &p)const{
        return (tup[0] != p.tup[0])? (tup[0] < p.tup[0]) : (tup[1] < p.tup[1]);
    }
}arr[sz];
int step,Rank[20][sz],lcp[sz];
string str;
void BuildSuffixArray(){ /// Complexity: O(n*(log(n))^2)
    int jump , n=(int)str.size();
    for(int j=0 ; j<n ; j++){       ///Give initial rank when suffixes r sorted by their first 2^0=1 character
        Rank[0][j] = str[j];    ///Rank suffixes according to 1st char.
        ms(arr[j].tup , 0);
    }
    for(step=1,jump=1 ; jump<=n ; step++,(jump=jump<<1)){
        for(int j=0 ; j<=n ; j++){
            arr[j].idx = j;
            arr[j].tup[0] = Rank[step-1][j];    ///What j was in previous step
            arr[j].tup[1] = ((j+jump) < n)? Rank[step-1][j+jump] : -1;
        }
        sort(arr , arr+n);
        Rank[step][arr[0].idx] = 0;
        for(int j=1 ; j<n ; j++){
            Rank[step][arr[j].idx] = (arr[j].tup[0] == arr[j-1].tup[0] && arr[j].tup[1] == arr[j-1].tup[1])? Rank[step][arr[j-1].idx] : j;
        }
    }
}
int LCP(int i,int j)    ///returns the length of LCP(Longest Common Prefix) of suffixes starting at index i and j in log(n)
{
    if(i == j)
        return (int)str.size()-i;
    int ans = 0;
    for(int x=step-1 ; x>=0 ; x--){
        if(Rank[x][i] == Rank[x][j]){
            ans += (1<<x);
            i += (1<<x);
            j += (1<<x);
        }
    }
    return ans;
}
void BuildLCP() /// Complexity: O(n log(n)) ; Calculate the LCP of two adjacent suffix from the lexicographically sorted suffix list
{
    lcp[0] = 0;
    int i,j,id1,id2,n=(int)str.size();
    for(i=1 ; i<n ; i++){
        id1 = arr[i-1].idx;
        id2 = arr[i].idx;
        lcp[i] = 0;
        for(j=step-1 ; j>=0 ; j--){
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2]){
                lcp[i] += (1<<j);
                id1 += (1<<j);
                id2 += (1<<j);
            }
        }
    }
}
int main()
{
    int i,j,k,n,x,y;
    cin>>str;
    str += '$';     /// Every time u must have to add an specialist character that haven't use in the string yet
    BuildSuffixArray();
    for(i=0 ; i<(int)str.size() ; i++)
        cout<<arr[i].idx<<endl; ///Sorted suffix index
    cin>>x>>y;
    cout<<LCP(x , y)<<endl; ///LCP of suffix started at index x & y
    BuildLCP();
    for(i=1 ; i<(int)str.size() ; i++)
        cout<<lcp[i]<<endl; ///LCP of (i)th & (i-1)th suffix from the lexicographically sorted suffix list
    return 0;
}

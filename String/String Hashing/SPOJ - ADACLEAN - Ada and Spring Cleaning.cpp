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
#define intlimit                214748369
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
//ll frequency(ll n,ll factor)/** Frequency of a factor in n! **/{ll cnt=0;while(n){cnt += (n/factor);n /= factor;}return cnt;}
//vector<ll>Prime;bool mark[10000009];
//void sieve(ll n){ll i,j;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i*i<=n){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//vector<ll>List;
//void Primefactorize(ll n){for(ll i=0; Prime[i]*Prime[i]<=n; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){List.push_back(Prime[i]);n/=Prime[i];}}}if(n>1){List.push_back(n);}}
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

/** Count the number of k-length unique substring from a given n length String with double Hashing **/
const int m=1e9+7;
const int p1=31;
const int p2=37;
ll pow_p1[100005];
ll pow_p2[100005];
ll hash_sum1[100005];
ll hash_sum2[100005];
vector<pll >st;
char s[100005];
void Power()
{
    pow_p1[0]=1;
    pow_p2[0]=1;
    for(int i=1 ; i<=100002 ; i++)
    {
        pow_p1[i] = (pow_p1[i-1] * p1)%m;
        pow_p2[i] = (pow_p2[i-1] * p2)%m;
    }
}
void compute_hash()
{
    ll hash_value1=0 , hash_value2=0;
    int sz=strlen(s);
    for(int i=0 ; i<sz ; i++)
    {
        hash_value1 = (hash_value1 + (s[i]-'a'+1)*pow_p1[i])%m;
        hash_sum1[i+1] = hash_value1;
        hash_value2 = (hash_value2 + (s[i]-'a'+1)*pow_p2[i])%m;
        hash_sum2[i+1] = hash_value2;
    }
}
int main()
{
    Power();
    int i,j,k,n,len1,t,T,mxpower,addpower;
    ll val1,val2,temp;
    scin(T);
    RUN_CASE(t,T)
    {
        st.clear();
        scin2(n,k);
        sc("%s",s);
        compute_hash();
        mxpower=n-k;
        for(i=0 ; i<=n-k ; i++)
        {
            addpower = mxpower-i;
            val1 = (hash_sum1[i+k] + m - hash_sum1[i])%m;
            val1 = (val1*pow_p1[addpower])%m;

            val2 = (hash_sum2[i+k] + m - hash_sum2[i])%m;
            val2 = (val2*pow_p2[addpower])%m;
            st.push_back({val1 , val2});
        }
        sort(st.begin() , st.end());
        st.erase(unique(st.begin(),st.end()) , st.end());
        pf("%lld\n",st.size());
    }
    return 0;
}


/*
#include<bits/stdc++.h>

using namespace std;

#define nl endl
#define lli long long int
#define vb vector<bool>
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, bool> msb;
typedef map<string, string> mss;
typedef map<string, char> msc;
typedef pair<int, int> pii;
typedef pair<lli, lli> pllilli;
typedef vector<pii> vii;
typedef vector<pllilli> vllilli;
#define FOR(i,a,b) for(int i=a; i<b;i++)
//vector<int>::iterator j;
#define REPV (j, v) for(vector<int>::iterator j = v.begin(); j!=v.end();j++)
#define pb push_back
//#define pf push_front
#define mp make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPR(I, A, B) for (int I = (B); I > (A); I--)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRLLI(X) lli (X); scanf("%lld", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRLLILLI(X, Y) lli X, Y; scanf("%lld%lld", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define DRLLILLILLI(X, Y, Z) lli X, Y, Z; scanf("%lld%lld%lld", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define DRA(a,n) int a[n]; REP(i,n)cin>>a[i]
#define l_b lower_bound
#define u_b upper_bound
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define NL cout<<endl
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define all(ar) ar.begin(), ar.end()
#define pq priority_queue
#define zzz return 0
inline lli Power(int b, int p) { lli ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
const int MOD = 1e9+7;
const int SIZE = 4e6+10;
const int MAX = 1e9+1;

int main(){
  DRI(t);
  while(t--){
    lli n;cin>>n;
    lli sum = 3 * ((n * (n + 1))/2) - n;
    sum = sum% 1000007;
    cout<<sum;NL;
  }
}
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--)
    {
        int n, w, a[n], wt[n];
        cin>>n>>w;
        for(int i=0 ; i<n; i++)
        {
            cin>>a[i];
        }

         for(int i=0 ; i<n; i++)
        {
            cin>>wt[i];
        }
        pair <int ,int> p[n];
            for(int i=0 ; i<n; i++)
        {
        p[i]=make_pair(wt[i], a[i]);
        }
        sort(p, p+n);
        int t[n+1][w+1];

         for(int i=0 ; i<=n; i++)
        {
         for(int j=0 ; j<=w; j++)
        {
          if(i==0&&j==0)
          {t[i][j]=0;
          cout<<"a\n";}
          else if(i==0)
          {t[i][j]=1;cout<<"b\n";}
          else if(j==0)
          {t[i][j]=0;cout<<"c\n";}

         else if(j<p[i-1].first){t[i][j]=t[i-1][j];cout<<"d\n";}
        else {t[i][j]=max(t[i-1][j], p[i].second+t[i-1][j-p[i].first]);cout<<"e\n";}


        }}

         for(int i=0 ; i<n; i++)
        {
         for(int j=0 ; j<=w; j++)
        {
          cout<<t[i][j]<<" ";
        }
        cout<<endl;
      }
        //cout<<t[n-1][w]<<endl;
    }
    return 0;
}

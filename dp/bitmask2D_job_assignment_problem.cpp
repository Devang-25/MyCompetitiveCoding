#include<bits/stdc++.h>

using namespace std;

#define nl endl
#define lli long long int
#define ld long double
#define vb vector<bool>
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef priority_queue<int> pq; //maxHeap
typedef priority_queue <int, vector<int>, greater<int> > pqn; //minHEAP
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
#define zzz return 0
inline lli Power(int b, int p) { lli ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
const int MOD = 1e9+7;
const int SIZE = 4e6+10;
const int MAX = 1e9+1;



//bitmap operations
int Set(int N, int pos) {return N=N | (1<<pos);}//set bit @pos
int unset(int N, int pos) {return N=N & ~(1<<pos);}//unset bit @pos
bool check(int N, int pos) {return (bool)(N & (1<<pos));}//returns true if bit@pos is set
int count_set_bits(int N){if(N==0)return 0;else return ((N+1)+count_set_bits(N>>1));}

//Question link: http://www.sanfoundry.com/dynamic-programming-solutions-assignments-problem/
long long int assign(int n, vector<vector<int> > preference)
{
    int mx=1<<n;
    int i,j;
    int s;

    /*
       student=no. of bits set in integer i
       dp[i] = the number of ways of assigning assignments to students s .. n

       If jth bit of integer i is set, it means that the subject j is  already assigned to students 1 .. s-1 and it cannot be assigned to student s.

    */

    vector<long long int> dp(mx,0);
    dp[mx-1]=1;

    //proceed in bottom up manner
    for(int mask=mx-1;mask>=0;mask--)
    {
        //now find the student
        j=mask;
        s=0;

        //count no. of set bits in mask
        while(j)
        {
            s+=(j&1);
            j/=2;
        }

        //so, this is a state for student s
        for(i=0;i<n;i++)
        {
            if(preference[s][i] && !(mask & (1<<i)))
            {
                dp[mask]+=dp[mask | (1<<i)];
            }
        }
    }

    //this is the result
    return dp[0];
}

int main()
{
    int i,n,j;

    cout<<"How many students are there ? "<<endl;
    cin>>n;

    vector<vector<int> > preference(n+1,vector<int>(n,0));

    cout<<endl<<"Enter the preferences of each of "<<n<<" students for "<<n<<" subjects"<<endl;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>preference[i][j];
        }
    }

    cout<<endl<<"Total number of assignments that can be prepared are "<<endl;
    cout<<assign(n,preference)<<endl;


    return 0;
}

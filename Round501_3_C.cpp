/*** Codeforces Round #501 (Div. 3) ***/
/*** C. Songs Compression ***/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int b, s; };
typedef long long int lli;


bool cmp(P a, P b)
{
    return (a.b-a.s) > (b.b-b.s);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<P> v;
    lli sum=0LL;
    for(int i=0; i<n; i++) {
        int b, s;
        scanf("%d%d", &b, &s);
        v.push_back((P){b, s});
        sum += b;
    }

    sort(v.begin(), v.end(), cmp); 
    
    int ans=0;
    for(int i=0; i<n; i++) {
        if(sum > m) {
            ans++;
            sum = sum - (v[i].b-v[i].s);
        }
        else
            break;
    }
    
    if(ans == n && sum > m) ans = -1;
    printf("%d\n", ans);
    return 0;
}


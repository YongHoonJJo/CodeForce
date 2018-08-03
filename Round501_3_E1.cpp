/*** Codeforces Round #501 (Div. 3) ***/
/*** E1. Stars Drawing (Easy Edition) ***/

#include <cstdio>
#include <vector>
using namespace std;

struct P { int r, c, n; };

int n, m;
char g[1005][1005];
bool check[1005][1005];

int di[]={1, 0, -1, 0};
int dj[]={0, 1, 0, -1};

bool safe(int r, int c)
{
    return (0 < r && r <= n) && (0 < c && c <= m);
}

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; i++)
        scanf("%s", g[i]+1);

    vector<P> ans;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(g[i][j] == '*') {
                int size = 1;
                while(1) {
                    bool ok = 1;
                    for(int k=0; k<4; k++) {
                        int ni = i+di[k]*size;
                        int nj = j+dj[k]*size;
                        if(!safe(ni, nj) || g[ni][nj] != '*') {
                            ok = 0;
                            break;
                        }
                    }
                    if(ok) {
                        for(int k=0; k<4; k++) {
                            int ni = i+di[k]*size;
                            int nj = j+dj[k]*size;
                            check[ni][nj] = 1;
                        }    
                        check[i][j] = 1;
                        size++;
                    }
                    else {
                        if(size > 1) {
                            ans.push_back((P){i, j, size-1});
                        }
                        break;
                    }
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if((check[i][j] == 1 && g[i][j] == '.') || (check[i][j] == 0 && g[i][j] == '*')) {
                puts("-1");
                return 0;
            }
        }
    }

    int sz = ans.size();
    printf("%d\n", sz);
    for(int i=0; i<sz; i++) 
        printf("%d %d %d\n", ans[i].r, ans[i].c, ans[i].n);

    return 0;
}

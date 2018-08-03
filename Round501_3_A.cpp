/*** Codeforces Round #501 (Div. 3) ***/
/*** A. Points in Segments ***/

#include <cstdio>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int seg[101]={0};

    while(n--) {
        int l, r;
        scanf("%d%d", &l, &r);
        
        for(int i=l; i<=r; i++)
            seg[i] = 1;
    }

    int ans=0;
    for(int i=1; i<=m; i++)
        if(!seg[i])
            ans++;
    printf("%d\n", ans);

    for(int i=1; i<=m; i++)
        if(!seg[i])
            printf("%d ", i);
    puts("");
    return 0;
}


/*** Codeforces Round #501 (Div. 3) ***/
/*** B. Obtaining the String ***/

#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    char s[55];
    char t[55];
    scanf("%s%s", s, t);

    int check[30]={0};
    for(int i=0; s[i]; i++) {
        check[s[i]-'a']++;
        check[t[i]-'a']--;
    }

    for(int i=0; i<26; i++) {
        if(check[i]) {
            puts("-1");
            return 0;
        }
    }

    vector<int> ans; 
    
    for(int i=0; i<n; i++) {
        while(s[i] != t[i]) {
            for(int k=i; k<n; k++) {
                if(s[k] == t[i]) {
                    char tmp = s[k-1];
                    s[k-1] = s[k];
                    s[k] = tmp;
                    ans.push_back(k);
                    break;
                }
            }
        }
    }

    int size = ans.size();
    if(size > 10000) puts("-1");
    else {
        printf("%d\n", size);
        for(int i=0; i<size; i++)
            printf("%d ", ans[i]);
        puts("");
    }
        
    return 0;
}


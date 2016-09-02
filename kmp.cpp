#include<stdio.h>
#include<string.h>
void makeNext(const char P[],int next[])
{
    int i,j;
    int m = strlen(P);
    next[0] = 0;
    for (i = 1,j = 0; i < m; ++i)
    {
        while(j > 0 && P[i] != P[j])
            j = next[j-1];
        if (P[i] == P[j])
        {
            j++;
        }
        next[i] = j;
    }
}

int kmp(const char T[],const char P[],int next[])
{
    int n,m;
    int i,q;
    n = strlen(T);
    m = strlen(P);
    makeNext(P,next);
    for (i = 0,q = 0; i < n; ++i)
    {
        while(q > 0 && P[q] != T[i])
            q = next[q-1];
        if (P[q] == T[i])
        {
            q++;
        }
        if (q == m)
        {
            printf("Pattern occurs with shift:%d\n",(i-m+1));
        }
    }    
}

int main()
{
    int i;
    int next[20]={0};
    char T[] = "ababxbababcaabdfdsss";
    char P[] = "abcaabd";
    printf("%s\n",T);
    printf("%s\n",P );
     makeNext(P,next);
    kmp(T,P,next);
    for (i = 0; i < strlen(P); ++i)
    {
        printf("%d ",next[i]);
    }
    printf("\n");

    return 0;
}
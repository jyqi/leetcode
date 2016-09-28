#include <stdio.h>
#include <iostream>
using namespace std;

int n, m;

struct myTree
{
      int next[3];
      int val;
} node[100005];

int pos;

int makend()
{
    int i;
    pos++;
    for(i = 0;i < 2; i++)
        node[pos].next[i] = -1;
    node[pos].val = 0;

    return pos;

}

void add(int x)
{
    int cur = 0,i;

    for(i = 0;i < 30;i++)
    {
        int flag=(x&(1<<i))?1:0;
        if(node[cur].next[flag] == -1)
             node[cur].next[flag] = makend();
        cur = node[cur].next[flag];
    }
    node[cur].val = x;
}

int find(int x)
{
    int cur = 0, i, val;
    int res = 0;
    for(i = 0; i < 30; i++)
    {
        int flag = (x & (1 << i)) ? 1:0;
        if(flag == 1)
        {
	         if(node[cur].next[0] != -1) {
	         	cur = node[cur].next[0];
	         }
	         else {
	         	cur = node[cur].next[1];
	         }
	         val = x ^ node[cur].val;
	         //cout << val << endl;
	         if(node[cur].val != 0 && val > m) res++;
        }
        else if(flag == 0)
        {
		     if(node[cur].next[1] != -1) {		     	
		         cur = node[cur].next[1];
		     }
		     else {
		     	cur = node[cur].next[0];
		     }
		     val = x ^ node[cur].val;
		     //cout << val << endl;
	         if(node[cur].val != 0 && val > m) res++;
        }
    }
    val = x ^ node[cur].val;
    //cout << val << endl;
    if(val > m) res++;
    //cout << res << endl;
    return res;
}

int main()
{
     int i,x;
     cin >> n >> m;
     int mx=0;
     pos=0;
     int res = 0;
     for(i = 0;i < 2; i++) {
     	node[pos].next[i] = -1;
     }
     node[pos].val = 0;
     for(i = 0; i < n; i++)
     {
         cin >> x;
         add(x);
         if(i != 0) {
         	//cout << i << endl;
         	res += find(x);
         	//cout << res << endl;
         }
     }
     cout << res << endl;
	 return 0;
}

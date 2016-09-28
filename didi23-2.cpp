#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

int number;  
int A[1005];
int find(int s[], int sum, int n){
	int i;
	for (i=0; s[i]<=sum && i < n;i++);
	return i-1;
}


void find_factor(int s[],int sum,int n){    
	if(n < 0) return;
	if(sum < s[n]){    
	  n= find(s, sum, n);
	  if(n < 0)
	  return;	
    }
	
	if(sum==s[n]){    
		number++;  
	}	
	find_factor(s, sum-s[n], n-1);
	find_factor(s,sum,n-1); 
}

 
int main(void){
	int n, sum;
    cin >> n >> sum;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
	sort(A, A + n);               
	find_factor(A, sum, n);
	cout << number / 2 << endl;
	return 0;
}

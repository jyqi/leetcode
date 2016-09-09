/*假设一个数组仅仅由1和-1组成，求该数组的和为0的最长子串的长度。

例如：

{1,-1,1,-1,1,1,1}  输出：4.


解法：动态规划，dp0[i]表示以i结尾的加和为0 得到最长子串长度，
dp1[i] 表示以i结尾的加和为1的最长子串长度，
dp2[i]表示以i结尾的加和为-1 的最长子串长度。
于是可以得到下面的递推关系：
*/
#include<iostream>
#include<vector>
using namespace std;
int getLongestLength(int array[],int size){
    if(size<=1) return 0;
    vector<int>dp0(size);
    vector<int>dp1(size);
    vector<int>dp2(size);
    dp0[0]=0;
    if(array[0]==1){
        dp1[0]=1;
        dp2[0]=0;
    }else{
        dp1[0]=0;
        dp2[0]=1;
    }
    int result =0;
    for(int i =1;i<size;i++){
        if(array[i]==1){
            dp0[i]=dp2[i-1]==0?0:dp2[i-1]+1;
            dp1[i]=dp0[i-1]==0?1:dp0[i-1]+1;
            dp2[i]=dp0[i]==0?0:dp2[i-dp0[i]]+dp0[i];
        }else{
            dp0[i]=dp1[i-1]==0?0:dp1[i-1]+ 1;
            dp1[i]=dp0[i]==0?0:dp1[i-dp0[i]]+dp0[0];
            dp2[i]=dp0[i-1]==0?0:dp0[i-1]+1;
        }
        if(result<dp0[i]) result  =dp0[i];
    }

    return result;
}
int main(){
    int nums[]={-1,1,-1,1};
    cout<<getLongestLength(nums,4);
}
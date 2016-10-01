/*求从三角形顶部到底部和最大的路径，即最佳路径（动态规划）
 *   1
 *  3 4
 * 5 7 4
 *5 6 7 8
 */

#include <stdio.h>
#define N 5

int triangle[N][N]={	//三角形
	{1},
	{2,3},
	{4,5,6},
	{10,1,7,8},
	{1,1,4,5,6}
};

int remarkSum[N][N];//记录maxSum(i,j)的值,避免重复计算

//求（i，j）坐标到底部的最佳路径
int minSum(int i,int j)
{
	int sumLeft,sumRight;
	if(i==N-1){
		return triangle[i][j];
	}
	if(remarkSum[i+1][j]==-1)//没计算过，则计算
		remarkSum[i+1][j]=minSum(i+1,j);
    if(remarkSum[i+1][j+1]==-1)
		remarkSum[i+1][j+1]=minSum(i+1,j+1);
	sumLeft=remarkSum[i+1][j];
	sumRight=remarkSum[i+1][j+1];
	return sumLeft<sumRight?sumLeft+triangle[i][j]:sumRight+triangle[i][j];
}

//打印路径
void print(int i,int j)
{
	if(i>=N)
		return;
	printf("%-4d",triangle[i][j]);
	if(remarkSum[i+1][j]>remarkSum[i+1][j+1])
		print(i+1,j);//左边的和比右边的大，则打印左边的数
	else
		print(i+1,j+1);//右边的和比左边的大，则打印右边的数
}

int main()
{
	int i;
	for(i=0;i<N*N;i++)
		*(*remarkSum+i)=-1;
	printf("%d\n",minSum(0,0));
	print(0,0);
	printf("\n");
}
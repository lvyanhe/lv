#include <iostream>
using namespace std;
int maxsum(int a[],int low,int n)
{
    int maxSum = 0;
    int nowSum = 0;
    for (int i = 0; i <= n; i++)
    {
        
    
        nowSum += a[i];
        if (nowSum > maxSum)
            maxSum = nowSum;
        else if (nowSum < 0)
            nowSum = 0;

    }
    return maxSum;
   
}
int main()
{
    int a[100] = {};
	int i;
    int n;
    cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	i--;
	cout << maxsum(a, 0, i); //传入数组及其起始位置下标和终止为止下标，返回最大子数组的值
	
   
    return 0;
}

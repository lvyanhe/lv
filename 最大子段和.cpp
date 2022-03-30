#include<iostream>
#include"test.h"
using namespace std;
int FIND_MAX_CROSSING_SUBARRAY(int a[], int low, int mid, int high)
{

	int sum = 0;
	int left_sum, right_sum;
	int max_left, max_right;
	int i, j;

	left_sum = right_sum = 0;//使左右子数组为0

	for (i = mid; i >= low; i--)
	{
		sum = sum + a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}

	sum = 0;
	for (j = mid + 1; j <= high; j++)
	{
		sum = sum + a[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = j;
		}
	}

	low = max_left;
	high = max_right;
	sum = left_sum + right_sum;

	return sum;
}

//传进去数组，数组的低位序号，高位序号，返回最大子数组
int FIND_MAXIMUM_SUBARRAY(int a[], int low, int high)
{
	int left_sum, right_sum, cross_sum;

	//低位序号和高位序号相同
	if (low == high)
	{
		return a[low];
	}
	else
	{
		int mid;

		mid = (low + high) / 2;

		left_sum = FIND_MAXIMUM_SUBARRAY(a, low, mid);//得到最大左子数组

		right_sum = FIND_MAXIMUM_SUBARRAY(a, mid + 1, high);//得到最大右子数组

		cross_sum = FIND_MAX_CROSSING_SUBARRAY(a, low, mid, high);//得到最大中子数组

		//最大左子数组为最大子数组
		if (left_sum >= right_sum && left_sum >= cross_sum)
		{
			return left_sum;
		}

		//最大右子数组为最大子数组
		else if (right_sum >= left_sum && right_sum >= cross_sum)
		{
			return right_sum;
		}

		//最大中子数组为最大子数组
		else return cross_sum;

	}
}

int main()
{
	int a[6];
	int i;
	cout << "请输入大小为6的数组:" << endl;
	for (i = 0; i < 6; i++)
	{
		cin >> a[i];
	}
	i--;
	cout << FIND_MAXIMUM_SUBARRAY(a, 0, i); //传入数组及其起始位置下标和终止为止下标，返回最大子数组的值

	return 0;
}

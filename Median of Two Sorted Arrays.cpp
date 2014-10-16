//http://blog.csdn.net/yutianzuijin/article/details/11499917


#include <iostream>

using namespace std;

double findkth(int a[],int m,int b[],int n,int k)
{
	if(m > n)
		return findkth(b,n,a,m,k);
	if(m == 0)
		return b[k-1];
	if(k == 1)
		return min(a[0],b[0]);
	int pa = min(k/2,m),pb = k - pa;
	if(a[pa-1] > b[pb-1])
		return findkth(a,m,b+pb,n-pb,k-pb);
	else if (a[pa-1] < b[pb-1])
		return findkth(a+pa,m-pa,b,n,k-pa);
	else 
		return a[pa-1];
}

int main()
{
	class Solution {
	public:
		double findMedianSortedArrays(int A[], int m, int B[], int n) {
			int total = m + n;
			if(total & 0x1)
			{
				return findkth(A,m,B,n,total/2 + 1);
			}
			else
			{
				return (findkth(A,m,B,n,total/2) + findkth(A,m,B,n,total/2 + 1)) / 2;
			}
		}
	};

	Solution s;
	int A[5] = {1,2,3,4,5};
	int B[3] = {2,4,7};
	double result = s.findMedianSortedArrays(A,5,B,3);
	cout << result << endl;
	return 0;
}
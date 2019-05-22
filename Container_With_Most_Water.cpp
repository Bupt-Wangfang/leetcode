#include <iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution{
	public:
		int maxArea(vector<int>& height) {
			//Area = Max(min(height[i], height[j]) * (j-i)) 
			if(height.size()<=1){return -1;}
			int i=0,j=height.size()-1,res=0;
			while(i<j){
				int h=min(height[i],height[j]);
				res=max(res,h*(j-i));
				if(height[i]<height[j]){
					++i;
				}else{
					--j;
				}
			}
			return res;

		}
};

int main()
{
	Solution s1;
	int a[] = {1,8,6,2,5,4,8,3,7};
	vector<int> height;
	//将a的所有元素插入到height中
	height.insert(height.begin(), a, a+9);
    int result=s1.maxArea(height);
	return 0;
}
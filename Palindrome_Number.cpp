#include <iostream>
#include<cmath>
using namespace std;

class Solution{
	public:
		bool isPalindrome(int x) {
			if(x<0){
				return false;
			}
			int numOfFirst=x;
			long numOfLast=0;
			while(x!=0){
				int n=x%10;
				numOfLast=numOfLast*10+n;
				x=x/10;
			}
			if(numOfFirst==numOfLast){
				return true;
			}else{
				return false;
			}
		}
};

int main()
{
	Solution s;
	int x=121;
    bool result=s.isPalindrome(x);
	return 0;
}
#include <iostream>
#include<cmath>
#include<vector>
#include<map>
#include <string>
using namespace std;

class Solution{
	public:
		string intToRoman(int num) {
			string keys[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
			int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
			string res;
			int len=sizeof(keys) / sizeof(keys[0]);
			for(int i=0; i<len; i++)
			{
				while(num>=values[i])
				{
					num -= values[i];
					res += keys[i];
				}
			}
			return res;
		}
};

int main()
{
	Solution s1;
	int s=3;
    string result=s1.intToRoman(s);
	return 0;
}
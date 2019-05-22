#include <iostream>
#include<cmath>
using namespace std;

class Solution{
	public:
		int myAtoi(string str) {
			long long num = 0;
			long long max = 0x100000000;
			bool positive = true;
			const char* digit = str.c_str();
			while(*digit == ' ') {
				digit++;
			}
			if(*digit!='\0'&& *digit == '+') {
				digit++;
			}else if(*digit!='\0'&& *digit == '-') {
				digit++;
				positive=false;
			}
		    while(*digit != '\0'){
				if(*digit <= '9' && *digit >= '0'){
					num = num * 10 + *digit - '0';
					digit ++;
					if(num > INT_MAX){
						num = max;
					}
				}else{
					break;
				}
			}
			if(!positive){
				num=-num;
			}
			if(num > INT_MAX) num = INT_MAX;
			if(num < INT_MIN) num = INT_MIN;
			return num;
		}
};

int main()
{
	Solution s;
	string str="-42";
    int result=s.myAtoi(str);
	return 0;
}
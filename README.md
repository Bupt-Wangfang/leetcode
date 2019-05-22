# leetcode
leetcode 刷题代码
开始刷leetcode，为秋招做准备，因此将自己的代码上传到这里，记录一下，主要用到的语言是C++。

1. Two Sum:
设置一个map容器用来记录元素的索引和值之间的关系，遍历数组nums，设置临时变量来存储目标值与当前值的差值，在map寻找是否有与差值一致的值，如果没有的话，就在map中保存该元素和索引；如果查找成功就返回索引值和当前变量的值i。

2. Add Two Numbers:
建立一个新链表，把输入的链表从头向后同时两两相加，将结果加上进位carried后的值作为一个新节点添加到新链表中。

3. Longest Substring Without Repeating Characters(滑动窗口)
建立一个整型数组freg，用来建立字符和其出现位置之间的映射。
维护一个滑动窗口，窗口内的都是没有重复的字符，去尽可能的扩大窗口的大小，窗口不停的向右滑动。
1) 如果当前遍历到的字符从未出现过，那么直接扩大右边界；
2) 如果当前遍历到的字符出现过，则缩小窗口（左边索引向右移动），然后继续观察当前遍历到的字符；
重复 1)和 2)，直到左边索引无法再移动；
维护一个结果res，每次用出现过的窗口大小来更新结果res，最后返回res获取结果。

4. Median of Two Sorted Arrays
先求有序数组A和B有序合并之后第k小的数。如果A[k/2-1]<B[k/2-1]，那么A[0]~A[k/2-1]一定在第k小的数的序列当中，可以用反证法证明。
假设A[k/2-1]大于合并之后的第k小值，我们不妨假定其为第（k+1）小值。由于A[k/2-1]小于B[k/2-1]，所以B[k/2-1]至少是第（k+2）小值。但实际上，在A中至多存在k/2-1个元素小于A[k/2-1]，B中也至多存在k/2-1个元素小于A[k/2-1]，所以小于A[k/2-1]的元素个数至多有k/2+ k/2-2，小于k，这与A[k/2-1]是第（k+1）的数矛盾。
边界情况：如果A或者B为空，则直接返回B[k-1]或者A[k-1]；
如果k为1，我们只需要返回A[0]和B[0]中的较小值；
如果A[k/2-1]=B[k/2-1]，返回其中一个；

5. 最长回文子串（使用O(n)复杂度的Manacher算法）
将源字符串str的每个字符之间，包括首尾都插入一个特殊字符，新字符串newStr的长度为2* str.length()-1，保证总长度为奇数。
根据newStr求出以每个字符为中心的最长回文子串的最右端字符距离该字符的距离，存入一个数组中，eg. len数组，Len[i]=right-i+1;

6. Z字形变换：将字符串以Z字形排列成给定的行数，然后从左向右，逐行读取字符。
以举例来看，首尾两行中相邻两个元素的index之差跟行数是相关的，为 2 * nRows - 2, 对于其他行的其余元素出现的位置也是有规律的，位置为 j + 2* nRows-2 - 2* i, 其中，j为前一个元素的列数，i为当前行数。 

7. 反转整数
反转之后要考虑整形溢出的问题。由于题目是指32位的数据，因此考虑用long型变量保存结果。之后有其他方法再更新。

8. 字符串转换整数atoi：只能存储32位大小的有符号整数
该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。在任何情况下，若函数不能进行有效的转换时，请返回 0。
思路：
1) 从头遍历串，将i指针定到字符串中数字的最高位：
遇到+或-，则其下一位作为最高位，终止遍历；
遇到数字，则其作为最高位，终止遍历；
遇到空格，跳过考虑下一位；
其它情况，直接返回0。
2) 从最高位索引开始遍历串：当遇到非数字，终止遍历，将j指针定到字符串中数字的最低位的右边。
3) 此时我们已经知道最高位和最低位的索引。只需要累加起来就得到结果，注意：当遇到overflow时，返回边界值。

9. 回文数：判断一个数字是否是回文数。
将数字逆序转换，判断是否与转换前的数字一致。逆序转换使用 % 和 / 操作生成新数。

10. 正则表达式匹配：给定一个字符串 (s) 和一个字符模式 (p)。实现支持 . 和 * 的正则表达式匹配。匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
1) 当模式中的第二个字符不是 * 时，字符串中的第一个字符和模式中的第一个字符相匹配，那么都向后移动一个字符；
2) 当模式中的第二个字符时 * 时， 
  ~ 在模式上向后移动两个字符；
  ~ 如果模式中的第一个字符与字符串中第一个匹配，字符串向后移动一个，模式可以选择向后移动两个字符，也可以选择保持不变。
  
11. 盛最多水的容器：给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
使用动态规划： area = min(height[i], height[j]) * (j - i)
因为面积取决于两个指针的距离与较小值的乘积，如果值大的值向内移动，距离一定减小，要求最大的面积，较大值的指针不动，较值的指针向内移动遍历。

12. 整数转罗马数字：给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
罗马数字包含以下七种字符: I(1)， V(5)， X(10)， L(50)，C(100)，D(500) 和 M(1000)。
1) I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
2) X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
3) C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

13. 罗马数字转整数
如12题，逆过程。

# leetcode
leetcode 刷题代码
开始刷leetcode，为秋招做准备，因此将自己的代码上传到这里，记录一下，主要用到的语言是C++。

1. Two Sum:
设置一个map容器用来记录元素的索引和值之间的关系，遍历数组nums，设置临时变量来存储目标值与当前值的差值，在map寻找是否有与差值一致的值，如果没有的话，就在map中保存该元素和索引；如果查找成功就返回索引值和当前变量的值i。

2. Add Two Numbers:
建立一个新链表，把输入的链表从头向后同时两两相加，将结果加上进位carried后的值作为一个新节点添加到新链表中。

3.Longest Substring Without Repeating Characters(滑动窗口)
建立一个整型数组freg，用来建立字符和其出现位置之间的映射。
维护一个滑动窗口，窗口内的都是没有重复的字符，去尽可能的扩大窗口的大小，窗口不停的向右滑动。
（1）如果当前遍历到的字符从未出现过，那么直接扩大右边界；
（2）如果当前遍历到的字符出现过，则缩小窗口（左边索引向右移动），然后继续观察当前遍历到的字符；
（3）重复（1）（2），直到左边索引无法再移动；
（4）维护一个结果res，每次用出现过的窗口大小来更新结果res，最后返回res获取结果。

4. Median of Two Sorted Arrays
先求有序数组A和B有序合并之后第k小的数。如果A[k/2-1]<B[k/2-1]，那么A[0]~A[k/2-1]一定在第k小的数的序列当中，可以用反证法证明。
假设A[k/2-1]大于合并之后的第k小值，我们不妨假定其为第（k+1）小值。由于A[k/2-1]小于B[k/2-1]，所以B[k/2-1]至少是第（k+2）小值。但实际上，在A中至多存在k/2-1个元素小于A[k/2-1]，B中也至多存在k/2-1个元素小于A[k/2-1]，所以小于A[k/2-1]的元素个数至多有k/2+ k/2-2，小于k，这与A[k/2-1]是第（k+1）的数矛盾。
边界情况：如果A或者B为空，则直接返回B[k-1]或者A[k-1]；
如果k为1，我们只需要返回A[0]和B[0]中的较小值；
如果A[k/2-1]=B[k/2-1]，返回其中一个；

5. 最长回文子串（使用O(n)复杂度的Manacher算法）
将源字符串str的每个字符之间，包括首尾都插入一个特殊字符，新字符串newStr的长度为2*str.length()-1，保证总长度为奇数。
根据newStr求出以每个字符为中心的最长回文子串的最右端字符距离该字符的距离，存入一个数组中，eg. len数组，Len[i]=right-i+1;

7. 反转整数
反转之后要考虑整形溢出的问题。由于题目是指32位的数据，因此考虑用long型变量保存结果。

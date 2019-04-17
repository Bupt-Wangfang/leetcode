class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int total=m+n;
        if(total & 1){
            return findKth(nums1,nums2,m,n, total / 2 + 1);
        }else{
            return (findKth(nums1, nums2,m, n, total / 2)+ findKth(nums1,nums2,m,n, total / 2 + 1)) / 2;
        }
    }
    double findKth(vector<int>& nums1, vector<int>& nums2,int m,int n,int k){
        if(m>n){
            return findKth(nums2,nums1,n,m,k);
        }
        if(m==0){
            return nums2[k-1];
        }
        if(k==1){
            return min(nums1[0],nums2[0]);
        }
        int pa=min(k/2,m),pb=k-pa;
        if(nums1[pa-1]<nums2[pb-1]){
            vector<int>::iterator i1=nums1.begin()+pa;
            vector<int> num1(i1,nums1.end());
            return findKth(num1,nums2,m-pa,n,k-pa);
        }else if (nums1[pa - 1] > nums2[pb - 1]){
            vector<int>::iterator i2=nums2.begin()+pb;
            vector<int> num2(i2,nums2.end());
		    return findKth(nums1,num2, m,n - pb, k - pb);
        }else{
            return nums1[pa-1];
        }
    }
};

### 两个排序数组的中位数
- [leetcode地址](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/)
- 描述
<pre>
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
</pre>
**示例 1:**
```commandline
nums1 = [1, 3]
nums2 = [2]

中位数是 2.0
```

**示例 2:**
```commandline
nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5
```

- 分析
1. 中位数，偶数的时候取中间两个值的平均值，奇数的时候，就直接取中间值。
1. 列举所有case
    * nums1 全部大于 nums2 如：nums1 = [1,2,3], nums2 = [4,5,6]
    * nums1 和 nums2 交错 如：num1 = [1,3,4], nums2 = [2,5,6]
    * 最大最小都属于其中一个序列， 如: nums1 = [1,10], nums2=[3,4,5]
1. 复杂度，也就是log(n+m), 一看见log，我们所能想到的肯定是"二分查找"。
    1. 合起来在重新排序是不可行的，时间复杂度为 O((m + n) * log(m + n))
    1. 先归并排序也是不可行的， 时间复杂度O(m + n)
    1. 用类似桶排的方法时间复杂度也是不行的， 时间复杂度O(m + n) 



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
1. 复杂度，也就是log(n+m), 一看见log，我们所能想到的肯定是"分治法"。
1. 中位数，偶数的时候是中间两个值的平均值，奇数的时候，就直接是中间值。


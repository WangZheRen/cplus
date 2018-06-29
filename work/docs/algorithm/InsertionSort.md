## 插入排序

**问题描述**

![InertionSort](../images/InsertionSort.jpeg "InsertionSort")  

**开始时，我们的左手为空，并且桌子上的牌面向下，然后，每次从桌子上拿走一张牌，并将它插入左手中正确的位置**
![InertionSort2](../images/InsertionSort2.jpeg "InsertionSort2")  

**实现方式(增量方法)**
```
INSERTION-SORT(A)
    for j = 2 to A.length
        key = A[j]
        i = j - 1
        while i > 0 and A[i] > key
            A[i + 1] = A[i]
            i--;
        A[i + 1] = key;

```
_下标_: 从1开始

## 分析算法
* 分析算法的结果意味着预测算法需要的资源（如，内存、通信带宽、计算机硬件资源、_计算时间_)
* 算法需要的时间与输入的规模同步增长，所以通常把一个程序的运行时间描述成其输入规模的函数。
* 一个算法在特定输入上的运行时间是指执行的基本操作数或步数。

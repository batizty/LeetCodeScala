package com.tuoyu.leetcodescala

/**
  * Created by tuoyu on 6/29/16.
  * 寻找两个数组的共同中位数
  */

object FindMedianSortedArrays extends Executor {
  override def runImplement(): Unit = {
    val arr1: Array[Int] = Array(1, 3)
    val arr2: Array[Int] = Array(2)

    val arr3: Array[Int] = Array(1, 2)
    val arr4: Array[Int] = Array(3, 4)

    findMedianSortedArrays(arr3, arr4)
    ()
  }

  /**
    * 思路:
    * 求合体之后的中位数
    * 如果合体之后为奇数,那么中位数是确定的某个
    * 如果合体之后为偶数,中位数为偶数的和/2
    *
    * 可以扩展为求某个两个合体之后的数组的第k个数
    *
    * 求中位数实际上是找第 k = (m+n)/2 的数
    *
    *
    * 求第k小的数的问题:
    * A B 两个数组中,都先寻找第k/2的数字
    * a = A[k/2-1]
    * b = B[k/2-1]
    * (a > b) ==> 说明B数组中,前k/2个元素必然小于第k小的数
    * (a < b) ==> 说明A数组中,前k/2个元素必然小于第k小的数,这些数字可以排除了
    * (a == b) ==> 说明当前数已经找到了,找到A B两个有序数组中的第k小的数了
    * 按照这种思路迭代计算下去,就可以计算出来结果
    *
    * 将A B小于K_2的情况排除掉
    * @param nums1
    * @param nums2
    * @return
    */
  def findMedianSortedArrays(nums1: Array[Int], nums2: Array[Int]): Double = {
    val total = nums1.size + nums2.size

    val ret =
      if ((total % 2) == 0)
        (findKth(nums1, nums2, total / 2) + findKth(nums1, nums2, total / 2 + 1)) / 2
      else
        findKth(nums1, nums2, total / 2 + 1)
    println(s" findMedianSortedArrays ret = $ret ")
    ret
  }

  def findKth(num1: Array[Int], num2: Array[Int], k: Int): Double = {
//    println(s" num1.size = ${num1.size} num2.size = ${num2.size} k = $k")
    if (num1.isEmpty)
      num2(k - 1)
    else if (num2.isEmpty)
      num1(k - 1)
    else if (num1.size < num2.size)
      findKth(num2, num1, k)
    else if (k == 1)
      num1(0).min(num2(0))
    else {
      val k1 = (k / 2).min(num1.size)
      val k2 = k - k1
      if (num1(k1 - 1) > num2(k2 - 1))
        findKth(num1, num2.drop(k2), k - k2)
      else if (num1(k1 - 1) < num2(k2 - 1))
        findKth(num1.drop(k1), num2, k - k1)
      else
        num1(k - 1)
    }
  }
}


package com.tuoyu.leetcodescala

/**
  * Created by tuoyu on 6/27/16.
  * Main会执行所有的LeetCode题目一遍,每个会打印出来执行的平均时间
  */


object Main {
  def main(args: Array[String]): Unit = {
    println(s" Start LeetCodeScala For Scala")
    TwoSum.run()
    AddTwoNumbers.run()
    LengthOfLongestSubstring.run()
    FindMedianSortedArrays.run()
  }
}

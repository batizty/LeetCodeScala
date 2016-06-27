package com.tuoyu.leetcodescala

import scala.language.postfixOps

/**
 * Created by tuoyu on 6/24/16.
 *  一次循环，获得结果
  *
  *
  *  *  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
  *  You may assume that each input would have exactly one solution.
  *  Example:
  *  Given nums = [2, 7, 11, 15], target = 9,
  *  Because nums[0] + nums[1] = 2 + 7 = 9,
  *  return [0, 1].
 */

object TwoSum extends Executor {
  def twoSum(nums: Array[Int], target: Int): Option[(Int, Int)] = {
    val zip_map: Map[Int, Int] = nums.map(target - _).zipWithIndex.toMap
    val targets: Array[(Int, Int)] = nums.zipWithIndex map { case (num, index) =>
      zip_map.get(num).map((index, _)).filter(x => x._1 != x._2)
    } flatten

    targets.headOption
  }

  override def runImplement(): Unit = {
    val array1: Array[Int] = Array(2, 11, 7, 15)
    val array2: Array[Int] = Array(2, 11, 32, 4, 7, 7, 7, 43, 5)
    val target1: Int = 7
    val ret = twoSum(array2, target1)
    ()
  }
}


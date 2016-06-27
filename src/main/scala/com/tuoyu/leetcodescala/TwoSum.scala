package com.tuoyu.leetcodescala

import scala.collection.mutable.Map

/**
 * Created by tuoyu on 6/24/16.
 *  一次循环，获得结果
 */

object TwoSum {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    val table: Map[Int, Int] = Map.empty
    for { i <- 0.to(nums.length) } {
      val tmp = target - nums(i)
      table.get(i) match {
        case Some(x) => return Array(x, i)
        case None => table += i -> nums(i)
      }
    }
    Array.empty
  }
}


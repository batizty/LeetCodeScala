package com.tuoyu.leetcodescala

import org.scalatest.{Matchers, FlatSpec}

/**
  * Created by tuoyu on 6/27/16.
  */

class TwoSumSpec extends FlatSpec with Matchers {
  "TwoSum Spec" should "OK" in {
    val array1: Array[Int] = Array(2, 11, 7, 15)
    val array2: Array[Int] = Array(2, 11, 32, 4, 7, 7, 7, 43, 5)
    val target1: Int = 10

    val result = TwoSum.twoSum(array2, target1)
//    println(s"result = ${result}")
  }
}


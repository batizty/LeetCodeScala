package com.tuoyu.leetcodescala

import scala.collection.mutable.ListBuffer

/**
  * Created by tuoyu on 6/27/16.
  * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
  * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  * Output: 7 -> 0 -> 8
  */

object AddTwoNumbers extends Executor {
  override def runImplement() = {
    val l1 = List(2, 4, 3)
    val l2 = List(5, 6, 4)
    addTwoNumbers(l1, l2)
    ()
  }

  def addTwoNumbers(l1: List[Int], l2: List[Int]): List[Int] = {
    val head: ListBuffer[Int] = new ListBuffer[Int]

    var flag: Int = 0
    var result: List[Int] = l1.zipAll(l2, 0, 0).map { case (a: Int, b: Int) =>
      a + b
    } map { i =>
      val tmp = i + flag
      if (tmp >= 10) {
        flag = 1
        tmp % 10
      }
      else {
        flag = 0
        tmp
      }
    }

    if (flag > 0)
      result = result.:+(flag)

    result
  }
}
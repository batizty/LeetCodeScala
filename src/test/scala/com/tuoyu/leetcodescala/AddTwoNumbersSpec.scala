package com.tuoyu.leetcodescala

import org.scalatest.{Matchers, FlatSpec}

/**
  * Created by tuoyu on 6/27/16.
  */
class AddTwoNumbersSpec extends FlatSpec with Matchers {

  "AddTwoNumbersSpec" should "OK" in {
    val l1 = List(2, 4, 3)
    val l2 = List(5, 6, 4)
    AddTwoNumbers.addTwoNumbers(l1, l2)
  }
}

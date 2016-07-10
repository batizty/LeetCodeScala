package com.tuoyu.leetcodescala

/**
  * Created by tuoyu on 7/1/16.
  *
  * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
  */
object ZigZagConversion extends Executor {
  override def runImplement(): Unit = {
    val s = "PAYPALISHIRING";
    zigZagConvert(s, 3)
    ()
  }

  def zigZagConvert(s: String, row: Int): String = {
    if (s.isEmpty || row <= 0) ""
    else if (row == 1) s
    else {
      val st: StringBuffer = new StringBuffer()
      val sz: Int = row * 2 - 2
      for (i <- 0.until(row) )
        for (j <- i.until(s.length, sz)) {
          st.append(s.charAt(j))
          if (i != 0 && i != row - 1 && (j + sz - 2 * i) < s.length - 1)
            st.append(s.charAt(j + sz - 2 * i))
        }
      st.toString
    }
  }
}

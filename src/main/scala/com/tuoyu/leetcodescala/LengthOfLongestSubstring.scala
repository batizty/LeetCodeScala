package com.tuoyu.leetcodescala

/**
  * Created by tuoyu on 6/27/16.
  * Given a string, find the length of the longest substring without repeating characters.
  * Examples:
  * Given "abcabcbb", the answer is "abc", which the length is 3.
  * Given "bbbbb", the answer is "b", with the length of 1.
  * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
  * Subscribe to see which companies asked this question
  */

import scala.collection.mutable.Map

object LengthOfLongestSubstring extends Executor {
  override def runImplement() = {
    val s1: String = "abcabcbb"
    val s2: String = "bbbb"
    val s3: String = "pwwkew"
    lengthOfLongestSubstring(s3)
    ()
  }

  def lengthOfLongestSubstring(s: String): Int = {
    var char_map: Map[Char, Int] = Map.empty
    var max: Int = 0
    s.zipWithIndex foreach { case (c, idx) =>
      char_map.get(c) foreach { n =>
        max = char_map.size.max(max)
        char_map = char_map.filter(_._2 > n)
      }
      char_map += c -> idx
    }
    max
  }
}

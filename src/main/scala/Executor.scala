package com.tuoyu.leetcodescala

/**
  * Created by tuoyu on 6/27/16.
  */
import org.joda.time.DateTime


trait Executor {
  val runCount: Int = 10000
  def name: String
  def runImplement(): Unit
  def run(): Unit = {
    println(s" Start ${name} Test")
    val start: Long = System.nanoTime()
    (1 to runCount) foreach { i =>
      runImplement()
    }
    val end: Long = System.nanoTime()
    val ns: Long = (end - start) / 1000

    println(s" Run ${name} Test ${runCount} Timers Total Time = ${ns} ms Average Time = ${ns/runCount} ms")
  }
}

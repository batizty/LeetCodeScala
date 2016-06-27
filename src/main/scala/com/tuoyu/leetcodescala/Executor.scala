package com.tuoyu.leetcodescala

/**
  * Created by tuoyu on 6/27/16.
  */


trait Executor {
  val runCount: Int = 10000
  def name: String = getClass.getSimpleName
  def runImplement(): Unit
  def run(): Unit = {
    println(s" Start ${name} Test")
    val start: Long = System.nanoTime()
    (1 to runCount) foreach { i =>
      val x = runImplement()
      x
    }
    val end: Long = System.nanoTime()
    val ns: Long = (end - start) / 1000

    println(s" Run ${name} Test ${runCount} Timers Total Time = ${ns} ms Average Time = ${ns/runCount} ms")
  }
}

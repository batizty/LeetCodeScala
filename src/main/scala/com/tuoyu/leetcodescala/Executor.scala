package com.tuoyu.leetcodescala

/**
  * Created by tuoyu on 6/27/16.
  * Executor是用来做自动执行的trait,每个题目的class继承这个trait
  */


trait Executor {
  val runCount: Int = 10000
  def name: String = getClass.getSimpleName
  def runImplement(): Unit
  def run(): Unit = {
    println(s"  +++++++ Start ${name} Test +++++++")
    val start: Long = System.nanoTime()
    print("\t")
    (1 to runCount) foreach { i =>
      val x = runImplement()
      if (i % (runCount / 10) == 0 )
        print(".")
      x
    }
    print("\n")
    val end: Long = System.nanoTime()
    val ms: Long = (end - start) / 1000
    println(s" \tRun Times   : ${runCount}")
    println(s" \tTotal Time  : ${ms} ms")
    println(s" \tAverage Time: ${ms/runCount} ms\n")
  }
}

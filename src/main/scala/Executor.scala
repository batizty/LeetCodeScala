package com.tuoyu.leetcodescala

/**
  * Created by tuoyu on 6/27/16.
  */
import org.joda.time.DateTime

trait Executor {
  val runCount: Int = 100
  def name: String
  def runImplement(): Unit
  def run(): Unit = {
    println(s" Start ${name} Test")
    val date_start: DateTime = DateTime.now()
    for { i <- 0.to(runCount) } {
      runImplement()
    }
    val date_end: DateTime = DateTime.now()
    val ms: Long = date_end.getMillis() - date_start.getMillis()
    val run_time: Float = ms / runCount

    println(s" Run ${name} Total Time = ${ms} ms Average Time = ${run_time} ms")
  }
}

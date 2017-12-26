/**
 *
 *
 *
 * author: tuoyu.zhang@gmail.com
 */

#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>

/** Time Point **/
#include <chrono>
#include <ctime>

std::chrono::system_clock::time_point currentTimePoint() {
  return std::chrono::system_clock::now();
}

#endif
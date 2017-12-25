/**
 * 
 * 
 * author: tuoyu.zhang@gmail.com
 */


#ifndef _EXECUTOR_H_
#define _EXECUTOR_H_

#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>

class Executor {
	private:
		std::ostream* out;
		int running_count = 1;
		long start = 1L;
	public:
		virtual std::string name(void) = 0;

		virtual void runImpl(void) = 0;

		Executor() {
			setStream(&std::cout);
		}

		void setStream(std::ostream* stream) {
			out = stream;
		}

		std::string header() {
			return "";
		}

		std::string end() {
			return "";
		}

		void summary() {
			long now = 10L;

			if (start <= 0L) {
				throw "Start Time is error " + std::to_string(start);
			}

			long interval = now - start;
			*out << "Running Total Time : " + std::to_string(interval) + "\n";
			*out << "Run Times          : " + std::to_string(running_count) + "\n";
			*out << "Average Run Time   : " + std::to_string(interval / running_count) + "\n";
		}

		void run() {
			*out << " +++ Start " + name() + " Quiz +++\n";
			*out << header();

			if (running_count < 1) {
				throw "This Test Case Running Count" 
					+ std::to_string(running_count) 
					+ " Less than 1";
			}

			for (int i = 0; i < running_count; i++) {
				runImpl();
				if (running_count > 10 && i % (running_count / 10) == 0) {
					*out << '.';
				}
			}

			*out << end();

			summary();
		}
};

#endif
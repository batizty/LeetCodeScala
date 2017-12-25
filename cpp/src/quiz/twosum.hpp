/**
 * 
 * 
 * author: tuouyu.zhang@gmail.com
 */

#ifndef _TWOSUM_H_
#define _TWOSUM_H_

#include <vector>
#include <malloc>
#include <map>

#include "../core/executor.hpp"

using namespace std;

class TwoSum: public Executor {
	public:
		void runImpl() {
			std::cout << "This is TwoSum";
			return;
		}

		std::string name() {
			return "twosum";
		}

		TwoSum() { };
		~TwoSum() { };
		
		vector<int> twoSum(vector<int>& numbers, int target) {
			int l = 0;
			int r = numbers.size() - 1;
			while (l < r) {
				int sum = numbers[l] + numbers[r]; 
				if (sum == target) {
					return vector<int>{l+1, r+1};
				} else if (sum > target) {
					r--;
				} else {
					l++;
				}
			}
    	}
};

#endif
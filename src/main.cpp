#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <string>


std::vector<int> BubbleSort(const std::vector<int>& arr) {
	auto ret = arr;

	if(arr.size() <= 1) {
		return ret;
	}
	else {
		for(size_t i = 0; i < ret.size() - 1; ++i) {
			for(size_t j = 0; j < ret.size() - i - 1; ++j) {
				if(ret[j] > ret[j + 1]) {
					std::swap(ret[j], ret[j + 1]);
				}
			}
		}
		return ret;
	}
}


void PrintArray(const std::string& message, const std::vector<int>& arr) {
	std::cout << message << ": ";
	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;
}


int main() {
	using namespace std;

	cout << "Sorting algorithms" << endl;
	
	mt19937_64 gen{ random_device{}() };
	uniform_int_distribution<> dist(1, 100);

	int length = (dist(gen) - 1) / 10 + 10;
	vector<int> arr(length);
	for(int& x : arr) {
		x = dist(gen);
	}

	PrintArray("Initial array", arr);
	PrintArray("Bubble sort", BubbleSort(arr));
}
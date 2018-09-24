#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <string>
#include <type_traits>



std::vector<int> InsertionSort(const std::vector<int>& arr) {
	std::remove_const<std::remove_reference<decltype(arr)>::type>::type ret;
	ret.push_back(arr[0]);
	for(auto i = arr.begin() + 1; i != arr.end(); ++i) {
		auto p = ret.begin();
		for(; p != ret.end(); ++p) {
			if(*p >= *i) break;
		}
		ret.insert(p, *i);
	}
	return ret;
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
	PrintArray("Insertion sort", InsertionSort(arr));
}
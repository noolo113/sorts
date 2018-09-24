#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <string>


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
}
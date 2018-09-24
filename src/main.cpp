#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>


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

	cout << "Initial array: ";
	copy(arr.begin(), arr.end(), ostream_iterator<int>{cout, " "});
}
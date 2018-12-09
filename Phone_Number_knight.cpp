#include <iostream> 
#include <map> 
#include <iterator> 
#include <algorithm>
using namespace std;

/*
Find total number of phone numbers formed by the movement of Knight and Bishop on keypad
Question:

We have to create phone number of length 7 by the movement of knight and bishop on a keypad. The properties of the phone number:

The phone number cannot start from 1 or 0.
The phone number should not contain special characters.
The length of the phone number should be 7.

the phone should look something like this:
1 2 3
4 5 6
7 8 9
  0
so you can go from 2 to 7 or 9; 3 to 4 or 8; 

*/

int count_paths(std::multimap<int, int> knight, int length) {
	int this_row[10] = { 0,0,1,1,1,1,1,1,1,1 };
	int prev_row[10];
	int clear[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 1; i < 7; i++) {
		memcpy(prev_row, this_row, sizeof(prev_row));
		memcpy(this_row, clear, sizeof(this_row));
		typedef multimap <int, int> ::iterator itr;
		for (int j = 0; j < 10; j++) {
			std::pair<itr, itr> result = knight.equal_range(j);
			for (itr it = result.first; it != result.second; it++) {
				this_row[it->second] += prev_row[it->first];
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum  += this_row[i];
	}
	return sum;
}

int main() {
	std::multimap<int, int> knight;
	knight.insert (pair <int, int>(0, 4));
	knight.insert (pair <int, int>(0, 6));
	knight.insert (pair <int, int>(1, 6));
	knight.insert (pair <int, int>(1, 8));
	knight.insert (pair <int, int>(2, 7));
	knight.insert (pair <int, int>(2, 9));
	knight.insert (pair <int, int>(3, 8));
	knight.insert (pair <int, int>(3, 4));
	knight.insert (pair <int, int>(4, 9));
	knight.insert (pair <int, int>(4, 3));
	knight.insert (pair <int, int>(4, 0));
	knight.insert (pair <int, int>(6, 1));
	knight.insert (pair <int, int>(6, 7));
	knight.insert (pair <int, int>(6, 0));
	knight.insert (pair <int, int>(7, 2));
	knight.insert (pair <int, int>(7, 6));
	knight.insert (pair <int, int>(8, 1));
	knight.insert (pair <int, int>(8, 3));
	knight.insert (pair <int, int>(9, 2));
	knight.insert (pair <int, int>(9, 4));
	typedef multimap <int, int> ::iterator itr;

	cout << count_paths(knight, 7) << endl;
	system("pause");
	return 0;



}


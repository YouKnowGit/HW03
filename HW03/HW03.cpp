#include "SimpleVector.h"
#include <string>

int main() {
    SimpleVector<int> vec;

    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(1);

    cout << "Before sort: ";
    vec.print();

    vec.sortData();
    cout << "After sort: ";
    vec.print();

    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

    vec.pop_back();
    cout << "After pop: ";
    vec.print();
	vec.resize(15);
	cout << "After resize to 15: ";

    return 0;
}

#include <iostream>
#include <vector>


using namespace std;

// vector의 size와 capacity 차이
void SizeAndCapacity()
{
	cout << "Array Created" << endl;

	vector<int> arr;

	arr.reserve(5);

	cout << "Array contains: " << endl;
	for (auto k : arr)
	{
		cout << arr[k] << " ";
	}

	cout << "Array size: " << arr.size() << endl;
	cout << "Array capacity: " << arr.capacity() << endl;
	
	cout << "----------------------------------------------" << endl;

	cout << "Push back 0 1 2 " << endl;
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	//arr.push_back(3);
	//arr.push_back(4);
	//arr.push_back(5);
	//arr.push_back(6);
	//arr.push_back(7);
	//arr.push_back(8);
	//arr.push_back(9);

	cout << "Array contains: " ;
	for (auto k : arr)
	{
		cout << arr[k] << " ";
	}

	cout << endl;
	cout << "Array size: " << arr.size() << endl;
	cout << "Array capacity: " << arr.capacity() << endl;
}

// reserve와 resize 의 차이점을 화인하는 예제
void ReserveAndResize()
{
	cout << "Array reserved to 5" << endl;

	vector<int> arr;

	arr.reserve(5);
	cout << "Array contains: " << endl;
	for (auto k : arr)
	{
		cout << arr[k] << " ";
	}
	cout << "Array size: " << arr.size() << endl; // 유효한 요소들이 할당이 '된' 크기
	cout << "Array capacity: " << arr.capacity() << endl; // 요소들이 할당 '될 수' 있는 크기

	cout << "----------------------------------------------" << endl;

	cout << "Array resized to 5" << endl;
	arr.resize(5);
	cout << "Array contains: " ;
	for (auto k : arr)
	{
		cout << arr[k] << " ";
	}

	cout << endl;
	cout << "Array size: " << arr.size() << endl;
	cout << "Array capacity: " << arr.capacity() << endl;
}

int main()
{
	SizeAndCapacity();

	cout << endl;
	cout << "========================================================"<< endl;
	cout << endl;

	ReserveAndResize();
}

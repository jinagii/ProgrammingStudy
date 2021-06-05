#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>

#pragma warning(disable : 4996)

using namespace std;

/// 삽입 삭제 검색 정렬 사용해보기
// array
// vector
// queue/deque
// list
// set/multiset
// map/multimap
// unordered_map/unordered_multimap

// array 
template<typename T, size_t N> class array;
std::array<int, 5> arr = { 1,2,3,4,5 }; // 왜 std 붙이면 되지?

// vector 
vector<int> vec;

// queue 선입선출
queue<int> que;

// deque
deque<int> deq;

// list 노드기반 컨테이너 
// 이중 연결 리스트 (couble linked list)
// vector deque와는 다르게 멤버함수에서 정렬, 이어붙이기 가능
// 탐색은 at으로 안되고 양방향 반복자 ++ --를 이용
list<int> lis;

// set 노드기반
// 이진 트리 (key 값 중복이 허용안됨)
// multilist는 중복이 허용됨
multiset<int> setNMulset;

// map 노드기반 
// 균형 이진 트리
// multimap은 중복이 가능
multimap<int, char> mapNMulmap;

// unordered_map
// 해시테이블로 구성됨
// 정렬이 안돼있음
// unorderd multimap은 중복이 가능


template <typename T>
void ShowContainer(T container)
{
	 for (auto& it : container)
	 {
		  cout << it << ' ';
	 }
	 cout << endl;
};

template <typename T>
void ShowQueue(T container)
{
	 while (!container.empty())
	 {
		  cout << container.front() << ' ';
		  container.pop();
	 }
	 cout << endl;
}

template<typename T>
void ShowMap(T container)
{
	 for (auto& it : container)
	 {
		  cout << "[" << it.first << "," << it.second << "] ";
	 }
	 cout << endl;
}

int main()
{
	 /////////////////////////////////////////////////////////////array
	 cout << "---array 예제---" << endl;
	 cout << "array : ";
	 ShowContainer(arr);

	 cout << "4번째 value : " << arr.at(3) << endl;
	 // array 삽입삭제 안됨
	 // 2으로 초기화
	 cout << "2로 초기화" << endl;
	 arr.fill(2);

	 // array 출력
	 cout << "array : ";
	 ShowContainer(arr);

	 /////////////////////////////////////////////////////////////vector
	 cout << "---vector 예제---" << endl;

	 vec.push_back(1);
	 vec.push_back(5);
	 vec.push_back(4);
	 vec.push_back(2);
	 vec.push_back(3);

	 cout << " vector : ";
	 ShowContainer(vec);

	 cout << "# 삽입" << endl;
	 vec.push_back(6);
	 cout << " vector : ";
	 ShowContainer(vec);


	 cout << "# 삭제" << endl;
	 cout << " - pop_back" << endl;
	 vec.pop_back();

	 cout << "  vector : ";
	 ShowContainer(vec);


	 cout << " - erase" << endl;
	 vec.erase(vec.begin() + 2);
	 cout << "  vector : ";
	 ShowContainer(vec);

	 cout << "# 검색" << endl;
	 cout << " - 2번째 value : " << vec.at(1) << endl;
	 cout << " - 처음과 끝 value : " << vec.front() << ", " << vec.back() << endl;

	 cout << " - 4의 위치?" << endl;
	 vector<int>::iterator it;
	 it = find(vec.begin(), vec.end(), 4);
	 if (it != vec.end())
	 {
		  cout << "  Index : " << *it << endl;
	 }
	 else
	 {
		  cout << "  없음!" << endl;
	 }

	 cout << " - 7의 위치?" << endl;
	 it = find(vec.begin(), vec.end(), 7);
	 if (it != vec.end())
	 {
		  cout << "  Index : " << *it << endl;
	 }
	 else
	 {
		  cout << "  없음!" << endl;
	 }
	 cout << endl;

	 cout << "# 정렬" << endl;
	 sort(vec.begin(), vec.end(), greater<int>());
	 cout << " - 내림차순 : ";
	 ShowContainer(vec);

	 /////////////////////////////////////////////////////////////queue
	 cout << "---queue 예제---" << endl;

	 que.push(3);
	 que.push(2);
	 que.push(1);
	 que.push(4);
	 que.push(5);

	 ShowQueue(que);

	 cout << "# 삽입" << endl;
	 que.emplace(6);
	 cout << " queue : ";
	 ShowQueue(que);
	 cout << endl;

	 cout << "# 삭제" << endl;
	 que.pop();
	 cout << " queue : ";
	 ShowQueue(que);
	 cout << endl;

	 cout << "# 검색" << endl;
	 cout << " - 처음과 끝 value : " << que.front() << ", " << que.back() << endl;
	 cout << endl;

	 cout << "# 정렬" << endl;
	 priority_queue<int, vector<int>, greater<int>> pque;

	 cout << " - 오름차순 : ";
	 while (!que.empty())
	 {
		  pque.push(que.front());
		  que.pop();
	 }
	 while (!pque.empty())
	 {
		  cout << pque.top() << ' ';
		  pque.pop();
	 }
	 cout << endl;

	 /////////////////////////////////////////////////////////////deque
	 cout << "---deque 예제---" << endl;

	 cout << "# 삽입" << endl;
	 deq.push_back(1);
	 deq.push_front(2);
	 deq.push_back(3);
	 deq.push_front(5);
	 deq.push_back(4);
	 deq.push_front(2);

	 cout << " deque : ";
	 ShowContainer(deq);

	 cout << "# 삭제" << endl;
	 deq.pop_back();
	 deq.pop_front();
	 cout << " deque : ";
	 ShowContainer(deq);

	 cout << "# 검색" << endl;
	 cout << " - 2번째 value : " << deq.at(1) << endl;

	 cout << "# 정렬" << endl;
	 cout << " - 내림차순 : ";
	 sort(deq.begin(), deq.end(), greater<int>());
	 ShowContainer(deq);

	 /////////////////////////////////////////////////////////////list
	 cout << "---list 예제---" << endl;
	 lis.assign(5, 2);
	 cout << " list : ";
	 ShowContainer(lis);

	 list<int>::iterator iter;
	 cout << "# 삽입" << endl;
	 iter = lis.begin();		// iterator로 접근해서 탐색후 삽입
	 iter++;
	 lis.insert(iter, 7);
	 lis.push_back(5);
	 lis.push_front(4);
	 cout << " list : ";
	 ShowContainer(lis);

	 cout << "# 삭제" << endl;
	 lis.pop_back();
	 iter++;
	 lis.erase(iter);
	 cout << " list : ";
	 ShowContainer(lis);

	 cout << "# 검색" << endl;
	 // 기본적으로 iter로 위치를 찾는다
	 lis.remove(7);	// 검색하고 7이있으면 삭제
	 cout << " list : ";
	 ShowContainer(lis);

	 cout << "# 정렬" << endl;
	 cout << " - 내림차순 : ";
	 lis.sort();
	 cout << " list : ";
	 ShowContainer(lis);

	 /////////////////////////////////////////////////////////////set and multiset
	 cout << "---set/multiset 예제---" << endl;
	 setNMulset.insert(4);
	 setNMulset.insert(5);
	 setNMulset.insert(7);
	 setNMulset.insert(9);
	 setNMulset.insert(2);
	 cout << " set : ";
	 ShowContainer(setNMulset);

	 cout << "# 삽입" << endl;
	 setNMulset.insert(6);
	 setNMulset.insert(7);
	 cout << " set : ";
	 ShowContainer(setNMulset);

	 cout << "# 삭제" << endl;
	 setNMulset.erase(setNMulset.find(5));
	 cout << " set : ";
	 ShowContainer(setNMulset);

	 cout << "# 검색" << endl;
	 //multiset<int>::iterator iter = setNMulset.find(9);
	 //auto it = setNMulset.find(9); //왜 안되는지 모르겠다
	 cout << " - 9의 index : " /*<< std::set::setNMulset.end()*/ << endl;

	 /////////////////////////////////////////////////////////////map and multimap
	 cout << "---map/multi_map 예제---" << endl;
	 cout << "# 삽입" << endl;
	 mapNMulmap.insert(pair < int, char>(1, 'a'));
	 mapNMulmap.insert(pair < int, char>(4, 'c'));
	 mapNMulmap.insert(pair < int, char>(3, 'g'));
	 mapNMulmap.insert(pair < int, char>(5, 'b'));
	 mapNMulmap.insert(pair < int, char>(2, 'u'));
	 mapNMulmap.insert(pair < int, char>(2, 'u'));

	 cout << " map : ";
	 ShowMap(mapNMulmap);

	 cout << "# 삭제" << endl;
	 mapNMulmap.erase(2);
	 cout << " map : ";
	 ShowMap(mapNMulmap);

	 cout << "# 검색" << endl;
	 //multimap<int, char>::iterator it;
	 //it = mapNMulmap.find(3);
	 //printf(mapNMulmap.find(3));

	 /////////////////////////////////////////////////////////////unordered map and unordered multimap

	 unordered_multimap<int, char> uMapNMulmap;
	 cout << "---unordered map/unordered multi_map 예제---" << endl;
	 cout << "# 삽입" << endl;
	 uMapNMulmap.insert(pair<int, char>(1, 't'));
	 uMapNMulmap.insert(pair<int, char>(6, 'e'));
	 uMapNMulmap.insert(pair<int, char>(5, 'h'));
	 uMapNMulmap.insert(pair<int, char>(2, 'r'));
	 uMapNMulmap.insert(pair<int, char>(9, 'j'));
	 uMapNMulmap.insert(pair<int, char>(5, 'j'));

	 cout << " unordered_map : ";
	 ShowMap(uMapNMulmap);

	 cout << "# 삭제" << endl;
	 uMapNMulmap.erase(2);
	 cout << " unordered_map : ";
	 ShowMap(uMapNMulmap);

	 cout << "# 검색" << endl;
	 cout << " - index 5만 출력" << endl;
	 for (auto it = uMapNMulmap.lower_bound(5); it != uMapNMulmap.upper_bound(5); it++)
	 {
		  cout << "[" << it->first << "," << it->second << "] ";
	 }
	 cout << endl;
}

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<vector>
#include<string>
#include<random>
using namespace std;

// A~H 중에서 하나를 주어진 확률 테이블을 참조하여 선택하는 코드를 작성해 보세요.
// A~H 중에서 2개를 주어진 확률 테이블을 참조하여 선택하는 코드를 작성해 보세요. (중복 가능)

// Possibility Table
// A:1 / B:3 / C:6 / D:10 / E:10 / F:20 / G:20 / H:30
const int A = 1;
const int B = 3;
const int C = 6;
const int D = 10;
const int E = 10;
const int F = 20;
const int G = 20;
const int H = 30;

int main()
{
	 /// 확률 테이블 생성 - 테이블을 미리 만들어 두는것이 성능상으로 
	 vector<char> Table;
	 Table.reserve(100);
	 for (int i = 0; i < A; i++) { Table.push_back('A'); }
	 for (int i = 0; i < B; i++) { Table.push_back('B'); }
	 for (int i = 0; i < C; i++) { Table.push_back('C'); }
	 for (int i = 0; i < D; i++) { Table.push_back('D'); }
	 for (int i = 0; i < E; i++) { Table.push_back('E'); }
	 for (int i = 0; i < F; i++) { Table.push_back('F'); }
	 for (int i = 0; i < G; i++) { Table.push_back('G'); }
	 for (int i = 0; i < H; i++) { Table.push_back('H'); }

	 // 난수 생성 엔진 초기화
	 random_device rd;
	 mt19937 gen(rd());
	 uniform_int_distribution<int> dis(0, Table.size() - 1); // 0 ~ 100 까지 균등하게 난수열생성 

	 /// 알파벳 카운트 벡터
	 vector<int> LabelCount;
	 LabelCount.resize(8);

	 int CountInput;
	 cout << "Type number to count: ";
	 cin >> CountInput;

	 for (int i = 0; i < CountInput; i++)
	 {
		  int n = dis(gen);

		  int choenAlphabet = Table[n] - 65;

		  LabelCount[choenAlphabet]++;
	 }

	 /// 알파벳 벡터
	 vector<char> Alphabets;
	 Alphabets.reserve(8);
	 for (int i = 0; i < 8; i++)
	 {
		  Alphabets.push_back(65 + i);
	 }

	 // 분포도 프린트
	 for (int i = 0; i < 8; i++)
	 {
		  cout << Alphabets[i] << " : ";
		  cout << LabelCount[i] << endl;
	 }

	 cout << "Pick 1 Alpabet" << endl;

	 cout << Table[dis(gen)] << endl;

	 cout << "Pick 2 Alpabet" << endl;
	 cout << Table[dis(gen)] << endl;
	 cout << Table[dis(gen)] << endl;
}



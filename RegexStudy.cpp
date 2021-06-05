#include <iostream>
#include <string>
#include <regex>

// regex_match 문자열 매칭하기
// regex_search 문자열 검색
// regex_replace 문자열 치환

using namespace std;

int main()
{
	cout << "입력해 주세요. (바보, 멍청이, 빵꾸똥꾸는 *검열*됩니다.)" << endl;

	// 문자열 입력받기
	string sentence;
	getline(cin, sentence);
	
	cout << endl;

	// 필터링할 단어들
	regex re("(바보|멍청이|빵꾸똥꾸)");

	//	smatch match;

	// 필터링 후 대체
	sentence = regex_replace(sentence, re, "*검열*");

	// 출력
	cout << sentence << endl;
}

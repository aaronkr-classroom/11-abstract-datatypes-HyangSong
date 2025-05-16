#include<algorithm>
#include<iomanip>
#include<iostream>
#include<ios>
#include<stdexcept>
#include<string>

#include "Vec.h"
#include "Student_info.h"
#include "median.h"

using namespace std;

int main() {
	Vec<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// 데이터 읽고 저장하기
	while (record.read(cin)) { // Student_info 멤버 함수
		maxlen = max(maxlen, record.get_name().size());
		students.push_back(record);
	}

	// 학생 기록 정렬하기
	sort(students.begin(), students.end(), compare);
	
	// 이름과 점수를 출력하기
	for (Vec<Student_info>::size_type i = 0;
		i != students.size(); i++) {
		cout << students[i].get_name() << string(maxlen + 1 - students[i].get_name().size(), ' ');

		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) <<  final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
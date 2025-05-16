//Student_info.cpp
#include <iostream>

#include "Student_info.h"
#include "grade.h"

using namespace std;

// 생성자
// 빈 생성자
Student_info::Student_info() : midterm(0), final(0) {}

// cin 읽어 Student_info를 초기화
Student_info::Student_info(istream& is) { read(is); }

bool compare(const Student_info& x, const Student_info& y) {
	return x.get_name() < y.get_name(); // A<Z일 때 참 반환, 반대일 때 거짓 반환
}

double Student_info::grade() const {
	return ::grade(midterm, final, homework);
}


istream& read_hw(istream& in, Vec<double>& hw) {
	if (in) {
		// 이전 내용을 제거
		hw.clear();

		// 입력을 위한 변수
		double x; // cin에서 사용하기

		// 입력받은 점수의 합은 sum
		while (in >> x) {
			hw.push_back(x);
		}

		//다음 학생의 점수 입력 작업을 고려해 스트림을 지움
		in.clear();

		
	}
	return in;


}

istream& Student_info::read(istream& is) {
	// 학생의 이름, 중간고사 점수, 기말고사 점수 읽어 저장
	is >> name >> midterm >> final;
	// 과제 점수를 읽음
	read_hw(is, homework);
	return is;
}
#include "decimal.h"
#include<iostream>
#include<string>
std::string decimal::get_num() {
	return num;
}
void decimal::set_num(std::string _num) {
	num = _num;
	if (check_num() == false) {
		std::cout << "Input again";
		std::cin >> num;
	}
}
int decimal::search_point() {
	std::string tmp;
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '.') {
			return i;
		}
	}
}
bool decimal::check_num() {
	for (int i = 0; i < num.length() - 1; i++) {
		if (num[i] == '.' || (num[i] >= 48 && num[i] <= 57)) {}
		else {
			return false;
		}
	}
}
void decimal::cut_div() {
	do {
		if (num[0] == '0') {
			num.erase(0, 1);
		}
		else if (num[0] == '.') {
			num = '0' + num;
			break;
		}

	} while (num[0] == '0' || num[0] == '.');
	do {
		if (num[num.length() - 1] == '0') {
			num.pop_back();
		}
		else if (num[num.length() - 1] == '.') {
			num += '0';
			break;
		}
	} while (num[num.length() - 1] == '0' || num[num.length() - 1] == '.');
}
void decimal::swap(decimal& b) {
	std::swap(this->num, b.num);
}
void decimal::align(decimal& b) {
	int pos_p1 = search_point();
	int pos_p2 = b.search_point();
	int nulltop1 = pos_p1;
	int nulltop2 = pos_p2;
	int nullafterp1 = num.length() - (pos_p1 + 1);
	int nullafterp2 = b.get_num().length() - (pos_p2 + 1);
	if (nullafterp1 < nullafterp2) {
		for (int i = nullafterp1; i < nullafterp2; i++) {
			num += "0";
		}
	}
	else if (nullafterp1 > nullafterp2) {
		for (int i = nullafterp2; i < nullafterp1; i++) {
			b.num += "0";
		}
	}
	if (nulltop1 < nulltop2) {
		b.num = "0" + b.num;
		for (int i = nulltop1; i <= nulltop2; i++) {
			num = "0" + num;
		}
	}
	else if (nulltop1 > nulltop2) {
		num = "0" + num;
		for (int i = nulltop2; i <= nulltop1; i++) {
			b.num = "0" + b.num;
		}
	}
}
decimal decimal::operator+(decimal& b) {
	num = "0" + num;
	b.num = "0" + b.num;
	decimal result(*this);
	result.align(b);
	int transfer = 0;
	for (int i = result.num.length() - 1; i >= 0; i--) {
		if (result.num[i] == '.') {
			continue;
		}
		else {
			if ((int(result.num[i]) + int(b.num[i]) - 48 + transfer) > 57) {
				result.num[i] = (int(result.num[i]) + int(b.num[i]) + transfer) - 57 - 1;
				transfer = 1;
			}
			else {
				result.num[i] = (int(result.num[i]) + int(b.num[i])) - 48 + transfer;
			}
		}
	}
	result.cut_div();
	b.cut_div();
	return result;
}
decimal decimal::operator -(decimal& b) {
	decimal result(*this);
	decimal copy_b(b);
	result.align(copy_b);
	int transfer = 0;
	bool b_bolshe = false;
	for (int i = 0; i < result.num.length(); i++) {
		if (int(result.num[i]) > int(copy_b.num[i])) {
			break;
		}
		else if (int(result.num[i]) < int(copy_b.num[i])) {
			b_bolshe = true;
			break;
		}
	}
	if (b_bolshe == true) {
		result.swap(copy_b);
	}
	for (int i = result.num.length() - 1; i >= 0; i--) {
		if (result.num[i] == '.' || result.num[i] == '-') {
			continue;
		}
		else {
			if ((int(result.num[i]) - int(copy_b.num[i]) - transfer) >= 0) {
				result.num[i] = (int(result.num[i]) - int(copy_b.num[i]) - transfer) + 48;
				transfer = 0;
			}
			else {
				result.num[i] = (int(result.num[i]) - int(copy_b.num[i])) + 58 - transfer;
				transfer = 1;
			}
		}
	}
	result.cut_div();
	if (b_bolshe == true) {
		result.num = "-" + result.num;
	}
	return result;
}
decimal& decimal::operator =(const decimal& d) {
	if (this != &d) {
		decimal tmp(d);
		this->swap(tmp);
	}
	return *this;
}
std::ostream& operator<<(std::ostream& out, const decimal& d) {
	out << d.num;
	return out;
}
std::istream& operator>>(std::istream& in, decimal& d) {
	in >> d.num;
	return in;
}

#include "decimal.h"
#include<iostream>
#include<string>
using namespace std;
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
	int decimal::search_point(){
		std::string tmp;
		int i(num.find("."));
		return i;

	}
	
	/*
	void decimal::align(decimal& b) {
		int num1len = num.length(), num2len = b.num.length();
		int pos_num1(num.find(".")), pos_num2(b.num.find("."));
		int aftrspotnum1 = (num1len - pos_num1) - 1, aftrspotnum2 = (num2len - pos_num2) - 1;//кол-во знаков после запятой
		int num1spot = (num1len - aftrspotnum1) - 1, num2spot = (num2len - aftrspotnum2) - 1;//кол-во знаков до запятой
		num.erase(num.find("."), 1);
		b.num.erase(b.num.find("."), 1);
		if (num1spot > num2spot) {
			int raz = num1spot - num2spot;
			b.num.insert(0, raz, '0');
		}
		else if (num1spot < num2spot) {
			int raz = num2spot - num1spot;
			num.insert(0, raz, '0');
		}
		if (aftrspotnum1 > aftrspotnum2) {
			int raz = aftrspotnum1 - aftrspotnum2;
			b.num.append(raz, '0');
		}
		else if (aftrspotnum1 < aftrspotnum2) {
			int raz = aftrspotnum2- aftrspotnum1;
			num.append(raz, '0');
		}
		int num1len1 = num.length(), num2len1 = b.num.length();//длина строи после преобразований
	}
	bool decimal::check_num() {
		for (int i = 0; i < num.length() - 1; i++) {
			if (num[i] == '.' || (num[i] >= 48 && num[i] <= 57)) {}
			else {
				return false;
			}
		}
	}
	decimal decimal::operator+(decimal& b) {
		num = "0" + num;
		b.num = "0" + b.num;
		decimal result(*this);
		int num1len = num.length(); 
		int num2len = b.num.length();
		int pos_num1(num.find("."));
		int pos_num2(b.num.find("."));
		int aftrspotnum1 = (num1len - pos_num1) - 1; 
		int aftrspotnum2 = (num2len - pos_num2) - 1;//кол-во знаков после запятой
		int num1spot = (num1len - aftrspotnum1) - 1; 
		int num2spot = (num2len - aftrspotnum2) - 1;//кол-во знаков до запятой
		num.erase(num.find("."), 1);
		b.num.erase(b.num.find("."), 1);
		if (num1spot > num2spot) {
			int raz = num1spot - num2spot;
			b.num.insert(0, raz, '0');
		}
		else if (num1spot < num2spot) {
			int raz = num2spot - num1spot;
			num.insert(0, raz, '0');
		}
		if (aftrspotnum1 > aftrspotnum2) {
			int raz = aftrspotnum1 - aftrspotnum2;
			b.num.append(raz, '0');
		}
		else if (aftrspotnum1 < aftrspotnum2) {
			int raz = aftrspotnum2 - aftrspotnum1;
			num.append(raz, '0');
		}
		int num1len1 = num.length(), num2len1 = b.num.length();//длина строи после преобразований
		if (num1len1 > num2len1) {
			result.num.insert(0, num1len1, '0');
		}
		else if (num1len1 < num1len1)
		{
			result.num.insert(0, num2len1, '0');
		}
		else if (num1len1 == num2len1) {
			result.num.insert(0, num1len1, '0');
		}
		int tmp = max(aftrspotnum1, aftrspotnum2);
		int m = result.num.length();
		bool flag = false;
		for (int i = m - 1; i >= 0; i--) {
			result.num[i] = num[i] + b.num[i] - 48;
			if (flag) { result.num[i]++; };
			if (result.num[i] >= 58) {
				result.num[i] -= 10;
				result.num[i - 1] = result.num[i - 1] + 1; flag = true;
			}
			else { flag = false; }
		}
		result.num.insert(tmp + 1, ".");
		if (result.num[0] == '0') {
			result.num.erase(0, 1);
		}
		
		
		
			return result;
		}
	*/
	
	
	/*
	decimal decimal::operator *(decimal& b) {
		num = "0" + num;
		b.num = "0" + b.num;
		decimal result(*this);
		align(b);
		int len1 = num.length(), len2 = b.num.length();
		int h = len1 + len2;
		std::string result(h, '0');

		for (int i = len1 - 1; i >= 0; i--) {
			int carry = 0;
			for (int j = len2 - 1; j >= 0; j--) {
				int temp = (result.num[i + j + 1] - '0') + (num[i] - '0') * (b.num[j] - '0') + carry;
				result.num[i + j + 1] = temp % 10 + '0';
				carry = temp / 10;
			}
			result.num[i] += carry;
		}

		int pos = result.num.find_first_not_of('0');
		if (pos !=string::npos) {
			return result.num.substr(pos);

		}

		return result;;
	}
	*/
void decimal::align(decimal& b) {
	int pos_p1 = search_point();
	int pos_p2 = b.search_point();
	int zn_aft_p1 = num.length() - (pos_p1 + 1);
	int zn_aft_p2 = b.get_num().length() - (pos_p2 + 1);
	int zn_to_p1 = pos_p1;
	int zn_to_p2 = pos_p2;
	if (zn_aft_p1 < zn_aft_p2) {
		for (int i = zn_aft_p1; i < zn_aft_p2; i++) {
			num += "0";
		}
	}
	else if (zn_aft_p1 > zn_aft_p2) {
		for (int i = zn_aft_p2; i < zn_aft_p1; i++) {
			b.num += "0";
		}
	}
	if (zn_to_p1 < zn_to_p2) {
		b.num = "0" + b.num;
		for (int i = zn_to_p1; i <= zn_to_p2; i++) {
			num = "0" + num;
		}
	}
	else if (zn_to_p1 > zn_to_p2) {
		num = "0" + num;
		for (int i = zn_to_p2; i <= zn_to_p1; i++) {
			b.num = "0" + b.num;
		}
	}
}
decimal decimal::operator+(decimal& b) {
	num = "0" + num;
	b.num = "0" + b.num;
	decimal result(*this);
	result.align(b);
	int um = 0;
	for (int i = result.num.length() - 1; i >= 0; i--) {
		if (result.num[i] == '.') {
			continue;
		}
		else {
			if ((int(result.num[i]) + int(b.num[i]) - 48 + um) > 57) {
				result.num[i] = (int(result.num[i]) + int(b.num[i]) + um) - 57 - 1;
				um = 1;
			}
			else {
				result.num[i] = (int(result.num[i]) + int(b.num[i])) - 48 + um;
				um = 0;
			}
		}
	}
	result.cut_div();
	b.cut_div();
	return result;
}
decimal& decimal::operator =(const decimal& d) {
		if (this != &d) {
			decimal tmp(d);
			this->swap(tmp);
		}
		return *this;
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
std::ostream& operator<<(std::ostream& out, const decimal& d) {
		out << d.num;
		return out;
	}
std::istream& operator>>(std::istream& in, decimal& d) {
		in >> d.num;
		return in;
	}
void s_decimal::short_num() {
	cut_div();
	int differ = 0;
	int point_pos = search_point();
	num.erase(point_pos, 1);
	for (int i = 0; i < num.length() - 1; i++) {
		if (num[i] == '-') {
			continue;
		}
		else if (num[i] == '0') {
			continue;
		}
		else {
			num.insert(i + 1, ".");
			differ = i + 1 - point_pos;
			cut_div();
			if (differ != 0) {
				num += "*10^(" + std::to_string(-differ) + ')';
			}
			break;
		}
	}if (num == "00") {
		num = "0.0";
	}
}
s_decimal& s_decimal::operator =(const decimal& a) {
	decimal::operator=(a);
	short_num();
	return *this;
}


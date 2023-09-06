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
	int decimal::search_point(){
		std::string tmp;
		int i(num.find("."));
		return i;

	}
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
			int raz = aftrspotnum2 - aftrspotnum1;
			num.append(raz, '0');
		}
		int num1len1 = num.length(), num2len1 = b.num.length();//длина строи после преобразований
		if (num1len > num2len) {
			result.num.insert(0, num1len1, '0');
		}
		else if (num1len < num1len)
		{
			result.num.insert(0, num2len1, '0');
		}
		else if (num1len == num2len) {
			result.num.insert(0, num1len1, '0');
		}
		int tmp = std::max(aftrspotnum1, aftrspotnum2);
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
	decimal decimal::operator-(decimal& b) {
		num = "0" + num;
		b.num = "0" + b.num;
		decimal result(*this);
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
			int raz = aftrspotnum2 - aftrspotnum1;
			num.append(raz, '0');
		}
		int num1len1 = num.length(), num2len1 = b.num.length();//длина строи после преобразований
		if (num1len > num2len) {
			result.num.insert(0, num1len1, '0');
		}
		else if (num1len < num1len)
		{
			result.num.insert(0, num2len1, '0');
		}
		else if (num1len == num2len) {
			result.num.insert(0, num1len1, '0');
		}
		int tmp = std::max(aftrspotnum1, aftrspotnum2);
		int diflen = result.num.length();
		if (num1len > num2len || num1len == num2len) {
			for (int i = diflen; i >= 0; i--) {
				if (num[i] < b.num[i]) {
					num[i] = num[i] + 10;
					num[i - 1] = num[i - 1] - 1;

				}
				result.num[i] = num[i] - b.num[i] + 48;
			}
			result.num.insert(tmp + 1, ".");
			result.num.erase(0, 1);
			return result;
		}
		else {
			for (int i = diflen; i >= 0; i--) {
				if (b.num[i] < num[i]) {
					b.num[i] = b.num[i] + 10;
					b.num[i - 1] = b.num[i - 1] - 1;
				}
				result.num[i] = b.num[i] - num[i] + 48;
			}
			result.num.insert(tmp + 1, ".");
			result.num.erase(0, 1);
			return result;
		}
	}
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
int main() {
	std::string s_a = "1.1";
	std::string s_b = "1.1";
	decimal a(s_a);
	decimal b(s_b);
	decimal res = a + b;
	std::cout << res  << std::endl;


	return 0;
}

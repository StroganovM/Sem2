#include <iostream>
#include <string>
using namespace std;

string multiply(string num1, string num2, int a, int b) {
	int len1 = num1.length(), len2 = num2.length();

	string result(len1 + len2, '0');

	for (int i = len1 - 1; i >= 0; i--) {
		int carry = 0;
		for (int j = len2 - 1; j >= 0; j--) {
			int temp = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
			result[i + j + 1] = temp % 10 + '0';
			carry = temp / 10;
		}
		result[i] += carry;
	}
	
	int pos = result.find_first_not_of('0');
	if (pos != string::npos) {
	return result.substr(pos);
		
	}
	
	return "0";
}
int main() {
	std::string a,fa, b,fb, sum, dif,incr;
	a = "4.02";
	b = "4.02";
	fa = a; fb = b;
	a.insert(0, 1, '0');
	b.insert(0, 1, '0');
	int alen = a.length(), blen = b.length();
	int pos_a(a.find(".")), pos_b(b.find("."));
	int aspot1 =(alen - pos_a)-1, bspot1 =(blen - pos_b)-1;//кол-во знаков после запятой
	int aspot = (alen - aspot1)-1, bspot = (blen - bspot1)-1;//кол-во знаков до запятой
	a.erase(a.find("."), 1);
	b.erase(b.find("."), 1);
	//приравниваем числа по кол-ву знаков
	if (aspot > bspot) {
		int raz = aspot - bspot;
		b.insert(0, raz, '0');
	}
	else if (aspot < bspot) {
		int raz = bspot - aspot;
		a.insert(0, raz, '0');
	}
	if (aspot1 > bspot1) {
		int raz = aspot1 - bspot1;
		b.append(raz, '0');
	}
	else if (aspot1 < bspot1) {
		int raz = bspot1 -aspot1;
		a.append(raz, '0');
	}
	int alen1 = a.length(), blen1 = b.length();//длина строи после преобразований
	int tmp = std::max(aspot1, bspot1);

	if (alen > blen) {
		sum.insert(0, alen1, '0');
	}
	else if(alen<blen)
	{
		sum.insert(0, blen1, '0');
	}
	else if (alen==blen){
		sum.insert(0, alen1, '0');
	}
	
	int m = sum.length();
	bool flag = false;
	for (int i = m - 1; i >= 0; i--) {
		sum[i] = a[i] + b[i] - 48;
		if (flag) { sum[i]++; };
		if (sum[i] >= 58) {
			sum[i] -= 10;
			sum[i - 1] = sum[i - 1] + 1; flag = true;
		}
		else { flag = false; }
	}
	
	sum.insert(tmp+1, ".");
	if (sum[0] == '0') {
		sum.erase(0, 1);
	}
	cout << fa << " + " <<fb<<" = "<< sum << std::endl;

	if (alen > blen) {
		dif.insert(0, alen1, '0');
	}
	else if (alen < blen)
	{
		dif.insert(0, blen1, '0');
	}
	else if (alen == blen) {
		dif.insert(0, alen1, '0');
	}
	int diflen = dif.length();
	if(alen>blen || alen==blen){
	for (int i = diflen; i >= 0; i--) {
		if (a[i] < b[i]) {
			a[i] = a[i] + 10;
			a[i - 1] = a[i - 1] - 1;
		
		}
		dif[i] = a[i] - b[i] + 48;
	}
	dif.insert(tmp+1, ".");
	dif.erase(0, 1);
	std::cout << fa << " - " << fb << " = " << dif << std::endl;
	} else {
		for (int i = diflen; i >= 0; i--) {
			if (b[i] < a[i]) {
				b[i] = b[i] + 10;
				b[i - 1] = b[i - 1] - 1;
			}
			dif[i] = b[i] - a[i] + 48;
		}
		dif.insert(tmp+1, ".");
		dif.erase(0, 1);
		std::cout << fa << " - " << fb << " = " <<"-"<< dif << std::endl;
	}
	
	
	incr = multiply(a, b, aspot1,bspot1);
	cout << fa << " * " << fb << " = " << incr << std::endl;
	
	return 0;
}
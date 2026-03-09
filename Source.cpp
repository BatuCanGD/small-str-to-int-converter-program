#include <iostream>
#include <string>

class Number {
public:
	long long x = 0;
	
	void add(long long z) { x += z; }
	void subtract(long long z) { x -= z; }
	void multiply(long long z) { x *= z; }
	void divide(long long z) { x /= z; }
	void modulate(long long z) { x %= z; }
};

int main() {
	Number num;
	std::string y;
	std::cout << "--> ";
	while (std::cin >> y) {
		
		bool IsNegative = false;
		bool ToMultiply = false;
		bool ToDivide = false;
		bool ToModulate = false;
		long long number = 0;
		int i = 0;

		std::cout << "=> ";

		if (y[0] == '-') {
			IsNegative = true;
			i = 1;
		}
		else if (y[0] == '*') {
			ToMultiply = true;
			i = 1;
		}
		else if (y[0] == '/') {
			ToDivide = true;
			i = 1;
		}
		else if (y[0] == '%') {
			ToModulate = true;
			i = 1;
		}

		for (; i < y.size(); i++) {
			number = (number * 10) + (y[i] - '0');
		}

		if (IsNegative) {
			num.subtract(number);
		}
		else if(ToMultiply){
			num.multiply(number);
		}
		else if(ToDivide){
			num.divide(number);
		}
		else if(ToModulate){
			num.modulate(number);
		}
		else{
			num.add(number);
		}

		std::string s = std::to_string(num.x);
		int n = s.size();
		for (int j = 0; j < n; j++) {
			std::cout << s[j];
			int digitsleft = n - 1 - j;
			if (digitsleft > 0 && digitsleft % 3 == 0 && s[j] != '-') {
				std::cout << ",";
			}
		}
		std::cout << '\n';
		std::cout << "--> ";
	}
	
	return 0;
}
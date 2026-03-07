#include <iostream>
#include <string>

class Number {
public:
	long long x = 0;
	
	void add(long long z) { x += z; }
	void subtract(long long z) { x -= z; }
};

int main() {
	Number num;
	std::string y;
	std::cout << "--> ";
	while (std::cin >> y) {
		
		bool IsNegative = false;
		long long number = 0;
		int i = 0;

		std::cout << "=> ";

		if (y[0] == '-') {
			IsNegative = true;
			i = 1;
		}

		for (; i < y.size(); i++) {
			number = (number * 10) + (y[i] - '0');
		}

		if (IsNegative) {
			num.subtract(number);
		}
		else {
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
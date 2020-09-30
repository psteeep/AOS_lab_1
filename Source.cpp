#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include<iomanip>

template <typename testype>
double adding(long iter) {
	testype a1 = 9041, a2 = 9349, a3 = 9281, b1 = 9421, b2 = 9133, b3 = 8783, c1 = 8719, c2 = 8669, c3 = 8467;
	double tact(0);
	long double start_time = clock();
	for (long long i=0; i < iter; i++) {
		a1 = b1 + c2; 
		a2 = b1 + c3; 
		a3 = b1 + c3;
		b1 = a1 + c3;
		c3 = a1 + b2;
		b2 = a3 + c1;
		b3 = c2 + a2;
	}
	long double end_time = clock();
	tact = iter / abs((start_time / CLOCKS_PER_SEC) - (end_time / CLOCKS_PER_SEC));
		return tact;
}

template <typename testype>
double subtraction(long iter) {
	testype a1 = 9041, a2 = 9349, a3 = 9281, b1 = 9421, b2 = 9133, b3 = 8783, c1 = 8719, c2 = 8669, c3 = 8467;
	double tact(0);
	long double start_time = clock();
	for (long long i = 0; i < iter; i++) {
		a1 = b1 - c1;
		a2 = b1 - c2;
		a3 = b1 - c3;
		b1 = a1 - c3;
		b2 = a3 - c1;
		b3 = c2 - a2;
	}
	long double end_time = clock();
	tact = iter / abs((start_time / CLOCKS_PER_SEC) - (end_time / CLOCKS_PER_SEC));
	return tact;
}

template <typename testype>
double multiplication(long iter) {
	testype a1 = 9041, a2 = 9349, a3 = 9281, b1 = 9421, b2 = 9133, b3 = 8783, c1 = 8719, c2 = 8669, c3 = 8467;
	double tact(0);
	long double start_time = clock();
	for (long i = 1; i < iter; i++) {
		a1 = b1 * i;
		a2 = b1 * i;
		a3 = b1 * i;
		b1 = a1 * i;
		b2 = a3 * i;
		b3 = c2 * i;
	}
	long double end_time = clock();
	tact = iter / abs((start_time / CLOCKS_PER_SEC) - (end_time / CLOCKS_PER_SEC));
	return tact;
}

template <typename testype>
double division(long iter) {
	testype a1 = 9041, a2 = 9349, a3 = 9281, b1 = 9421, b2 = 9133, b3 = 8783, c1 = 8719, c2 = 8669, c3 = 8467;
	double tact(0);
	long double start_time = clock();
	for (long i = 0; i < iter; i++) {
		a1 = i / c1;
		a2 = i / c2;
		a3 = i / c3;
		b1 = i / c3;
		b2 = i / c1;
	}
	long double end_time = clock();
	tact = iter / abs((start_time / CLOCKS_PER_SEC) - (end_time / CLOCKS_PER_SEC));
	return tact;
}

double max_tact(std::vector<std::vector<double>> tact) {
	double res = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (tact[i][j] > res) {
				res = tact[i][j];
			}
		}
	}
	return res;
}


int main() {

	long iter = 10e6; // iterations

	std::vector<std::vector<double>> tact{ {adding<int>(iter),adding<long>(iter * 10),adding<char>(iter * 10), adding<float>(iter * 10), adding<double>(iter * 10)},
		{subtraction<int>(iter * 10),subtraction<long>(iter * 10),subtraction<char>(iter * 10),subtraction<float>(iter * 10),
								subtraction<double>(iter * 10)},{multiplication<int>(iter),multiplication<long>(iter),multiplication<char>(iter),
								multiplication<float>(iter),multiplication<double>(iter)},{division<int>(iter),
								division<long>(iter),division<char>(iter),division<float>(iter),division<double>(iter)} };

	std::string oper[4] = { "+", "-", "*", "/" };
	std::string types[5] = { "int   ", "long  ", "char  ", "float ", "double" };

	double max_tact1 = max_tact(tact);

	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 4; i++) {
			std::cout << oper[i] << "  " << types[j] << "  " << std::setw(9) << tact[i][j] << " ";
			double frequencies = (tact[i][j] / max_tact1) * 100;
			for (int k = 0; k < int(frequencies); k++) {
				std::cout << 'X';
			}
			for (int k = 0; k < 100 - int(frequencies); k++){
				std::cout << ' ';
		}
			std::cout.setf(std::ios::fixed);
			std::cout.precision(0);
			std::cout << "  " <<frequencies << "%" << std::endl;
		}
	}


	return 0;
}
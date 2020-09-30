#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>


template <typename testype>
double adding(long long iter) {
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
double subtraction(long long iter) {
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
double multiplication(long long iter) {
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
double division(long long iter) {
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

	long long N = 10e6; // iterations

	std::vector<std::vector<double>> tact{ {adding<int>(N),adding<long>(N * 10),adding<char>(N * 10), adding<float>(N * 10), adding<double>(N * 10)},
		{subtraction<int>(N * 10),subtraction<long>(N * 10),subtraction<char>(N * 10),subtraction<float>(N * 10),
								subtraction<double>(N * 10)},{multiplication<int>(N),multiplication<long>(N),multiplication<char>(N),
								multiplication<float>(N),multiplication<double>(N)},{division<int>(N),
								division<long>(N),division<char>(N),division<float>(N),division<double>(N)} };

	std::string oper[4] = { "+", "-", "*", "/" };
	std::string types[5] = { "int   ", "long  ", "char  ", "float ", "double" };

	double max_tact1 = max_tact(tact);

	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < 4; ++i) {
			std::cout << oper[i] << "  " << types[j] << "  " << tact[i][j] << "  ";
			double percent = (tact[i][j] / max_tact1) * 100;
			for (int k = 0; k < int(percent); ++k) std::cout << 'X';
			for (int k = 0; k < 100 - int(percent); ++k) std::cout << ' ';
			std::cout << "  " << percent << "%\n";
		}
		std::cout << '\n';
	}


	
	return 0;
}
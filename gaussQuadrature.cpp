#include <iostream>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


double f1(double x_1){
	return x_1/sqrt(pow(x_1, 2) + 9);
}


double f2(double x_2){
	return pow(x_2, 3)/(pow(x_2, 2) + 1);
}


double f3(double x_3){
	return x_3*exp(x_3);
}


double f4(double x_4){
	return pow(x_4, 2)*log(x_4);
}


void transform(const double a, const double b, double &x){
	double temp = ((b - a)/2)*x + (b + a)/2;
	x = temp;
}


double diffCOV(const double a, const double b){
	return ((b - a) / 2);
}


double gaussQuad3(double f(double), const double a, const double b){
	double x1 = -sqrt(.6);
	double x2 = 0;
	double x3 = sqrt(.6);

	double c1 = .555555555555556;
	double c2 = .888888888888889;
	double c3 = .555555555555556;

	vector<double> x_vals;
	x_vals.push_back(x1);
	x_vals.push_back(x2);
	x_vals.push_back(x3);

	vector<double> coeffs;
	coeffs.push_back(c1);
	coeffs.push_back(c2);
	coeffs.push_back(c3);

	double diffCoeff = 1;

	if (a != -1 || b != 1){
		for (int i = 0; i < 3; i++){
			transform(a, b, x_vals[i]);
		}
		
		diffCoeff = diffCOV(a, b);
	}

	double res;

	for (int i = 0; i < 3; i++){
		res += (f(x_vals[i]) * coeffs[i] * diffCoeff);
	}

	return res;
}


int main(){
	
	vector<double> result;

	result.push_back(gaussQuad3(f1, 0, 4));
	result.push_back(gaussQuad3(f2, 0, 1));
	result.push_back(gaussQuad3(f3, 0, 1));
	result.push_back(gaussQuad3(f4, 1, 3));

	cout << "Results for Sec 5.5 Ex #5:" << endl;
	for (int i = 0; i < 4; i++){
		cout << "Problem " << i + 1 << ": " << result[i] << endl;
	}

	return 1;

}

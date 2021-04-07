#include <iostream>
#include "MyCacheCalculator.h"



int main(){

	MyCacheCalculator myCalculator;
	myCalculator.setCacheSize(3);
	//double num = cache.calculate(7);
	myCalculator.calculate(5);
	myCalculator.calculate(20);
	myCalculator.calculate(10);
	myCalculator.calculate(5);
	myCalculator.calculate(5);
	myCalculator.calculate(5);
	myCalculator.calculate(2);
	myCalculator.calculate(3);
	std::cout << myCalculator << std::endl;
	std::cout << std::endl;
	std:: cout << "cache element = " << myCalculator.getCacheElement(0) << std::endl;
	std:: cout << "cache element = " << myCalculator.getCacheElement(1) << std::endl;
	std:: cout << "cache element = " << myCalculator.getCacheElement(2) << std::endl;
	std:: cout << "cache element = " << myCalculator.getCacheElement(3) << std::endl;

}




#ifndef BASEFUNCTIONCALCULATOR_H_
#define BASEFUNCTIONCALCULATOR_H_





class BaseFunctionCalculator{

public:

	//If the destructor in the abstract class was not pure virtual,
	//the destructor of the base class would be called when destroying objects that created with this class,
	//and the destructor of the derived class object would not be called, which would create a memory leak.
	virtual ~BaseFunctionCalculator(){}
	virtual void setCacheSize(int n) = 0;
	virtual double calculate(int n) = 0;
	virtual int getCacheElement(int index) = 0;

};



#endif /* BASEFUNCTIONCALCULATOR_H_ */

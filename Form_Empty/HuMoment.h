#pragma once
class HuMoment
{

public:

	HuMoment(unsigned char* binaryImage, int width, int height);

	~HuMoment();

	double calcMoment(double p, double q);

	void calcOrgins();

	double calcOrginMoment(double p, double q);

	double calcNormalizedMoment(double p, double q);

	void calcInvariantMoments();

	double* getHuMoments();

	void logTransform();



private:

	int width, height;

	double orginOfX, orginOfY;

	unsigned char* object;

	double huMoments[7];






};



#include <math.h>





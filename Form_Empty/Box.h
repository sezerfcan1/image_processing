#pragma once
class Box
{
private:
	int firstX;
	int firstY;
	int endX;
	int endY;
	int area;
	unsigned char* intensityImage;
	unsigned char* binaryImage;

public:

	void setfirstX(int x);
	void setfirstY(int y);
	int getfirstX();
	int getfirstY();
	void setendX(int x);
	void setendY(int y);
	int getendX();
	int getendY();
	int getArea();
	void setArea(int area);


};


#pragma once
#include <atlstr.h>
#include <Windows.h>
#include"Box.h"

using namespace System::Drawing;

class Images
{
private:
	/// <summary>
	/// Property
	/// </summary>
	unsigned char* Buffer;
	unsigned int width;
	unsigned int height;
	unsigned int numofBox;
	BYTE* LoadBMP(unsigned int* widthh, unsigned int* heightt, long* sizee, LPCTSTR bmpfilee);
	float twoColorKmeans();
	unsigned char* getBinaryImage(float k1);
	void LabelComponent(unsigned char* input, BYTE* output, int labelNo, unsigned int x, unsigned int y);



public:

	void setBuffer(LPCTSTR bmpfilee);
	Bitmap^ ShowBinary();
	Bitmap^ ShowLabelImage();
	unsigned int getWidth();
	unsigned int getHeight();
	unsigned int getnumofBox();
	unsigned char* getRawIntensity();
	static Bitmap^ getRawToImage(unsigned char*, unsigned int w, unsigned int h);
	unsigned char* setMaskImage(double* mask, int kcol, int krow, int padding, int stride);
	unsigned int* getHistogram();
	BYTE* Images::LabelImage();
	Box* getBoxes();




};


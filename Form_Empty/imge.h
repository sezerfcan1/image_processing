#pragma once
#include <Windows.h>
#include <time.h>

using namespace System::Drawing;

BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile);
bool SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile);
BYTE* ConvertToIntensity(BYTE* Buffer, int width, int height);
BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long* newsize);
BYTE* GrayToneMask(BYTE* Buffer, int width, int height, float* mask, int kcol, int krow, int padding, int stride);
int* GrayToneHistogram(BYTE* Buffer, int width, int height);
Bitmap^ ShowIntensity(unsigned char* img, int w, int h);
Bitmap^ ImageMask(Bitmap^ image, int width, int height, float* mask, int kcol, int krow, int padding, int stride);
int** RGBHistogram(Bitmap^ image, int width, int height);
float twoColorKmeans(int width, int height, int* histogram);
float getDistance(float a, float a1, float b, float b1, float c, float c1);
float** MultipleColorKmeans(int numberOfKs, int width, int height, int** histogram);
float** MultipleColorKmeans2(Bitmap^ image, int numberOfKs, int width, int height);
float* GreyToneKmeans(int numberofKs, int width, int height, int* histogram);
BYTE* neighborhood(BYTE* binaryImage, int width, int height);
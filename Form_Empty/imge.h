#pragma once
#include <Windows.h>
BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile);
bool SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile);
BYTE* ConvertToIntensity(BYTE* Buffer, int width, int height);
BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long* newsize);
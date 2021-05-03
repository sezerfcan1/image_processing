#include"imge.h"
#include <cmath>


BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile)
{
	// declare bitmap structures
	BITMAPFILEHEADER bmpheader;
	BITMAPINFOHEADER bmpinfo;
	// value to be used in ReadFile funcs
	DWORD bytesread;
	// open file to read from
	HANDLE file = CreateFile(bmpfile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (NULL == file)
		return NULL; // coudn't open file

	// read file header
	if (ReadFile(file, &bmpheader, sizeof(BITMAPFILEHEADER), &bytesread, NULL) == false) {
		CloseHandle(file);
		return NULL;
	}
	//read bitmap info
	if (ReadFile(file, &bmpinfo, sizeof(BITMAPINFOHEADER), &bytesread, NULL) == false) {
		CloseHandle(file);
		return NULL;
	}
	// check if file is actually a bmp
	if (bmpheader.bfType != 'MB') {
		CloseHandle(file);
		return NULL;
	}
	// get image measurements
	width = bmpinfo.biWidth;
	height = abs(bmpinfo.biHeight);

	// check if bmp is uncompressed
	if (bmpinfo.biCompression != BI_RGB) {
		CloseHandle(file);
		return NULL;
	}
	// check if we have 24 bit bmp
	if (bmpinfo.biBitCount != 24) {
		CloseHandle(file);
		return NULL;
	}

	// create buffer to hold the data
	size = bmpheader.bfSize - bmpheader.bfOffBits;
	BYTE* Buffer = new BYTE[size];
	// move file pointer to start of bitmap data
	SetFilePointer(file, bmpheader.bfOffBits, NULL, FILE_BEGIN);
	// read bmp data
	if (ReadFile(file, Buffer, size, &bytesread, NULL) == false) {
		delete[] Buffer;
		CloseHandle(file);
		return NULL;
	}
	// everything successful here: close file and return buffer
	CloseHandle(file);

	return Buffer;
}//LOADPMB

Bitmap^ ShowIntensity(unsigned char* img, int w, int h) {
	Bitmap^ surface = gcnew Bitmap(w, h);

	Color c;
	int temp;
	for (unsigned int row = 0; row < h; row++)
	{
		for (unsigned int column = 0; column < w; column++)
		{
			temp = row * w + column;
			c = Color::FromArgb(img[temp], img[temp], img[temp]);
			surface->SetPixel(column, row, c);
		}
	}
	return surface;

}

bool SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile)
{
	// declare bmp structures 
	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER info;

	// andinitialize them to zero
	memset(&bmfh, 0, sizeof(BITMAPFILEHEADER));
	memset(&info, 0, sizeof(BITMAPINFOHEADER));

	// fill the fileheader with data
	bmfh.bfType = 0x4d42;       // 0x4d42 = 'BM'
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + paddedsize;
	bmfh.bfOffBits = 0x36;		// number of bytes to start of bitmap bits

	// fill the infoheader

	info.biSize = sizeof(BITMAPINFOHEADER);
	info.biWidth = width;
	info.biHeight = height;
	info.biPlanes = 1;			// we only have one bitplane
	info.biBitCount = 24;		// RGB mode is 24 bits
	info.biCompression = BI_RGB;
	info.biSizeImage = 0;		// can be 0 for 24 bit images
	info.biXPelsPerMeter = 0x0ec4;     // paint and PSP use this values
	info.biYPelsPerMeter = 0x0ec4;
	info.biClrUsed = 0;			// we are in RGB mode and have no palette
	info.biClrImportant = 0;    // all colors are important

	// now we open the file to write to
	HANDLE file = CreateFile(bmpfile, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == NULL) {
		CloseHandle(file);
		return false;
	}
	// write file header
	unsigned long bwritten;
	if (WriteFile(file, &bmfh, sizeof(BITMAPFILEHEADER), &bwritten, NULL) == false) {
		CloseHandle(file);
		return false;
	}
	// write infoheader
	if (WriteFile(file, &info, sizeof(BITMAPINFOHEADER), &bwritten, NULL) == false) {
		CloseHandle(file);
		return false;
	}
	// write image data
	if (WriteFile(file, Buffer, paddedsize, &bwritten, NULL) == false) {
		CloseHandle(file);
		return false;
	}

	// and close file
	CloseHandle(file);

	return true;
} // SaveBMP

BYTE* ConvertToIntensity(BYTE* Buffer, int width, int height)
{
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// find the number of padding bytes

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width * height];

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			newpos = row * width + column;
			bufpos = (height - row - 1) * psw + column * 3;
			newbuf[newpos] = BYTE(0.11 * Buffer[bufpos + 2] + 0.59 * Buffer[bufpos + 1] + 0.3 * Buffer[bufpos]);
		}

	return newbuf;
}//ConvetBMPToIntensity

BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long* newsize)
{
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// now we have to find with how many bytes
	// we have to pad for the next DWORD boundary	

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;
	// we can already store the size of the new padded buffer
	*newsize = height * psw;

	// and create new buffer
	BYTE* newbuf = new BYTE[*newsize];

	// fill the buffer with zero bytes then we dont have to add
	// extra padding zero bytes later on
	memset(newbuf, 0, *newsize);

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			bufpos = row * width + column;     // position in original buffer
			newpos = (height - row - 1) * psw + column * 3;           // position in padded buffer
			newbuf[newpos] = Buffer[bufpos];       //  blue
			newbuf[newpos + 1] = Buffer[bufpos];   //  green
			newbuf[newpos + 2] = Buffer[bufpos];   //  red
		}

	return newbuf;
} //ConvertIntensityToBMP

BYTE* GrayToneMask(BYTE* Buffer, int width, int height, float* mask, int kcol, int krow, int padding, int stride)
{


	int out_col = ((width - kcol + 2 * padding) / stride) + 1;
	int out_row = ((height - krow + 2 * padding) / stride) + 1;

	int sum = 0;
	BYTE* New_Raw = new BYTE[out_col * out_row];


	for (int i = 1; i < out_row; i++)
	{
		for (int j = 1; j < out_col; j++)
		{
			sum = 0;
			for (int k = 0; k < krow; k++)
			{
				for (int l = 0; l < kcol; l++)
				{
					sum += Buffer[(i - 1 + k) * width + (j - 1 + l)] * mask[k * kcol + l];
					//sum += Buffer[(i + k) * Width + (j + l)] * km[k * kcol + l];
				}
			}
			*(New_Raw + (i * out_col + j)) = sum;
		}
	}
	return New_Raw;
}

Bitmap^ ImageMask(Bitmap^ image, int width, int height, float* mask, int kcol, int krow, int padding, int stride) {
	int out_col = ((width - kcol + 2 * padding) / stride) + 1;
	int out_row = ((height - krow + 2 * padding) / stride) + 1;


	Bitmap^ tempimage = gcnew Bitmap(out_col, out_row);;
	Color c;

	for (int i = 1; i < out_row; i++)
	{
		for (int j = 1; j < out_col; j++)
		{
			int sumR = 0;
			int sumG = 0;
			int sumB = 0;
			for (int k = 0; k < krow; k++)
			{
				for (int l = 0; l < kcol; l++)
				{
					c = image->GetPixel(j - 1 + l, i - 1 + k);
					sumR += c.R * mask[k * kcol + l];
					sumG += c.G * mask[k * kcol + l];
					sumB += c.B * mask[k * kcol + l];
				}
			}
			c = Color::FromArgb(sumR, sumG, sumB);
			tempimage->SetPixel(j - 1, i - 1, c);
		}
	}
	return tempimage;
}

int* GrayToneHistogram(BYTE* Buffer, int width, int height) {

	int* histogram = new int[256];

	for (int i = 0; i < 256; i++)
	{
		histogram[i] = 0;
	}


	int temp;
	for (unsigned int row = 0; row < height; row++)
	{
		for (unsigned int column = 0; column < width; column++)
		{
			temp = row * width + column;

			histogram[Buffer[temp]]++;
		}
	}

	return histogram;
}

int** RGBHistogram(Bitmap^ image, int width, int height) {

	int** histogram;
	histogram = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		histogram[i] = new int[256];
	}


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			histogram[i][j] = 0;
		}
	}


	int temp;
	for (unsigned int row = 0; row < height; row++)
	{
		for (unsigned int column = 0; column < width; column++)
		{
			temp = row * width + column;
			Color c = image->GetPixel(column, row);
			histogram[0][c.R]++;
			histogram[1][c.G]++;
			histogram[2][c.B]++;

		}
	}

	return histogram;
}

float twoColorKmeans(int width, int height, int* histogram)
{
	srand(time(NULL));

	float present_k1;
	float next_k1;
	float present_temp1;


	present_k1 = rand() % 256;
	present_temp1 = present_k1;

	while (!(present_temp1 == next_k1))
	{

		float sum1 = 0;

		for (int i = 0; i < 256; i++)
		{

			sum1 += *(histogram + i);
			next_k1 += *(histogram + i) * i;

		}

		next_k1 = next_k1 / sum1;

		present_temp1 = present_k1;

		present_k1 = next_k1;


	}




	return present_k1;
}

float** MultipleColorKmeans(int numberOfKs, int width, int height, int** histogram) {

	srand(time(NULL));





	float** present_ks = new float* [numberOfKs]; // [k sayisi][k'nin degeri] 
	float** next_ks = new float* [numberOfKs];
	float** present_temp1 = new float* [numberOfKs];
	for (int i = 0; i < numberOfKs; i++)
	{
		present_ks[i] = new float[3];
		next_ks[i] = new float[3];
		present_temp1[i] = new float[3];
	}
	for (int i = 0; i < numberOfKs; i++)
	{
		present_ks[i][0] = rand() % ((i + 1) * 25) + 50;
		present_ks[i][1] = rand() % ((i + 1) * 25) + 50;
		present_ks[i][2] = rand() % ((i + 1) * 25) + 50;
		present_temp1[i][0] = present_ks[i][0];
		present_temp1[i][1] = present_ks[i][1];
		present_temp1[i][2] = present_ks[i][2];
		next_ks[i][0] = 0;
		next_ks[i][1] = 0;
		next_ks[i][2] = 0;
	}
	bool test = false;

	int basesayac = 0;

	while (!test)
	{
		basesayac++;
		float** sum = new float* [numberOfKs];

		for (int i = 0; i < numberOfKs; i++)
		{
			sum[i] = new float[3];
		}
		for (int i = 0; i < numberOfKs; i++)
		{
			sum[i][0] = 1;
			sum[i][1] = 1;
			sum[i][2] = 1;
		}

		int minDisIndex = 0;

		for (int i = 0; i < 256; i++)
		{

			float* distance = new float[numberOfKs];

			minDisIndex = 0;


			for (int j = 0; j < numberOfKs; j++)
			{

				distance[j] = getDistance(present_ks[j][0], histogram[0][i], present_ks[j][1], histogram[1][i], present_ks[j][2], histogram[2][i]);

			}

			float mindis = distance[0];

			for (int j = 0; j < numberOfKs; j++)
			{
				if (distance[j] < mindis)
				{
					mindis = distance[j];
					minDisIndex = j;
				}
			}


			sum[minDisIndex][0] += histogram[0][i];
			sum[minDisIndex][1] += histogram[1][i];
			sum[minDisIndex][2] += histogram[2][i];

			next_ks[minDisIndex][0] += histogram[0][i] * i;
			next_ks[minDisIndex][1] += histogram[1][i] * i;
			next_ks[minDisIndex][2] += histogram[2][i] * i;

		}


		for (int k = 0; k < numberOfKs; k++)
		{
			next_ks[k][0] = next_ks[k][0] / sum[k][0];
			next_ks[k][1] = next_ks[k][1] / sum[k][1];
			next_ks[k][2] = next_ks[k][2] / sum[k][2];

			for (int rgb = 0; rgb < 3; rgb++)
			{
				if (next_ks[k][rgb] == 0)
				{
					next_ks[k][rgb] = rand() % 150 + 50;

				}
			}

			present_temp1[k][0] = present_ks[k][0];
			present_temp1[k][1] = present_ks[k][1];
			present_temp1[k][2] = present_ks[k][2];

			present_ks[k][0] = next_ks[k][0];
			present_ks[k][1] = next_ks[k][1];
			present_ks[k][2] = next_ks[k][2];

		}


		int sayac = 0;
		for (int i = 0; i < numberOfKs; i++)
		{
			if (((int)present_temp1[i][0] >= (int)next_ks[i][0] - 2) && ((int)present_temp1[i][0] <= (int)next_ks[i][0] + 2)
				&& ((int)present_temp1[i][1] >= (int)next_ks[i][1] - 2) && ((int)present_temp1[i][1] <= (int)next_ks[i][1] + 2)
				&& ((int)present_temp1[i][2] >= (int)next_ks[i][2] - 2) && ((int)present_temp1[i][2] <= (int)next_ks[i][2] + 2))
			{
				sayac++;
			}

			if (sayac == numberOfKs)
			{
				test = true;
			}
			else
			{
				test = false;
			}

		}



	}

	return present_ks;

}



float** MultipleColorKmeans2(Bitmap^ image, int numberOfKs, int width, int height) {

	srand(time(NULL));



	float** present_ks = new float* [numberOfKs]; // [k sayisi][k'nin degeri]
	float** next_ks = new float* [numberOfKs];
	float** present_temp1 = new float* [numberOfKs];

	for (int i = 0; i < numberOfKs; i++)
	{
		present_ks[i] = new float[3];
		next_ks[i] = new float[3];
		present_temp1[i] = new float[3];
	}
	for (int i = 0; i < numberOfKs; i++)
	{
		present_ks[i][0] = rand() % 256;
		present_ks[i][1] = rand() % 256;
		present_ks[i][2] = rand() % 256;
		present_temp1[i][0] = present_ks[i][0];
		present_temp1[i][1] = present_ks[i][1];
		present_temp1[i][2] = present_ks[i][2];
		next_ks[i][0] = 0;
		next_ks[i][1] = 0;
		next_ks[i][2] = 0;
	}
	bool test = false;


	float* sum = new float[numberOfKs];

	while (!test)
	{





		for (int i = 0; i < numberOfKs; i++)
		{
			sum[i] = 0;

		}

		int minDisIndex = 0;

		for (unsigned int row = 0; row < height; row++)
		{

			for (unsigned int column = 0; column < width; column++)
			{
				float* distance = new float[numberOfKs];

				minDisIndex = 0;

				Color c = image->GetPixel(column, row);
				for (int j = 0; j < numberOfKs; j++)
				{
					Color c = image->GetPixel(column, row);
					distance[j] = getDistance(present_ks[j][0], c.R, present_ks[j][1], c.G, present_ks[j][2], c.B);

				}

				float mindis = distance[0];

				for (int j = 0; j < numberOfKs; j++)
				{
					if (distance[j] < mindis)
					{
						mindis = distance[j];
						minDisIndex = j;
					}
				}


				sum[minDisIndex]++;


				next_ks[minDisIndex][0] += (int)c.R;
				next_ks[minDisIndex][1] += (int)c.G;
				next_ks[minDisIndex][2] += (int)c.B;

			}



		}

		for (int k = 0; k < numberOfKs; k++)
		{
			next_ks[k][0] = next_ks[k][0] / sum[k];
			next_ks[k][1] = next_ks[k][1] / sum[k];
			next_ks[k][2] = next_ks[k][2] / sum[k];


			present_temp1[k][0] = present_ks[k][0];
			present_temp1[k][1] = present_ks[k][1];
			present_temp1[k][2] = present_ks[k][2];

			present_ks[k][0] = next_ks[k][0];
			present_ks[k][1] = next_ks[k][1];
			present_ks[k][2] = next_ks[k][2];

		}



		int sayac = 0;
		for (int i = 0; i < numberOfKs; i++)
		{
			if (((int)present_temp1[i][0] >= (int)next_ks[i][0] - 5) && ((int)present_temp1[i][0] <= (int)next_ks[i][0] + 5)
				&& ((int)present_temp1[i][1] >= (int)next_ks[i][1] - 5) && ((int)present_temp1[i][1] <= (int)next_ks[i][1] + 5)
				&& ((int)present_temp1[i][2] >= (int)next_ks[i][2] - 5) && ((int)present_temp1[i][2] <= (int)next_ks[i][2] + 5))
			{
				sayac++;
			}

			if (sayac == numberOfKs)
			{
				test = true;
			}
			else
			{
				test = false;
			}

		}
	}


	return present_ks;
}



float getDistance(float a, float a1, float b, float b1, float c, float c1) {
	return sqrt(pow(a - a1, 2) + pow(b - b1, 2) + pow(c - c1, 2));
}


float* GreyToneKmeans(int numberofKs, int width, int height, int* histogram)
{
	srand(time(NULL));

	float* present_k1 = new float[numberofKs];
	float* next_k1 = new float[numberofKs];
	float* present_temp1 = new float[numberofKs];

	for (int i = 0; i < numberofKs; i++)
	{
		present_k1[i] = rand() % 256;
		present_temp1[i] = present_k1[i];
		next_k1[i] = 0;
	}

	bool test = false;

	while (!(test))
	{

		float* sum1 = new float[numberofKs];
		for (int i = 0; i < numberofKs; i++)
		{
			sum1[i] = 0;
		}



		for (int j = 0; j < 256; j++)
		{

			float mindistance = present_k1[0];
			int minDisIndex = 0;
			for (int i = 0; i < numberofKs; i++)
			{
				if (mindistance > abs(present_k1[i] - *(histogram + j)))
				{
					mindistance = present_k1[i];
					minDisIndex++;
				}
			}




			sum1[minDisIndex] += *(histogram + j);
			next_k1[minDisIndex] += *(histogram + j) * j;

		}





		for (int i = 0; i < numberofKs; i++)
		{
			next_k1[i] = next_k1[i] / sum1[i];

			present_temp1[i] = present_k1[i];

			present_k1[i] = next_k1[i];
		}



		for (int i = 0; i < numberofKs; i++)
		{
			if (present_temp1[i] == 0) { present_temp1[i] = rand() % 256; }
		}



		int sayac = 0;
		for (int i = 0; i < numberofKs; i++)
		{
			if (((int)present_temp1[i] <= (int)next_k1[i] + 2) && ((int)present_temp1[i] >= (int)next_k1[i] - 2))
			{
				sayac++;
			}

			if (sayac == numberofKs)
			{
				test = true;
			}
			else
			{
				test = false;
			}

		}





	}




	return present_k1;
}


BYTE* neighborhood(BYTE* binaryImage, int width, int height)
{


	BYTE* New_Raw = new BYTE[(width) * (height)];
	BYTE* binaryImagetemp = new BYTE[(width+2) * (height+2)];


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			New_Raw[i * width + j] =0;
		}
	}




	for (int i = 1; i < height+1; i++)
	{
		for (int j = 1; j < width+1; j++)
		{
			binaryImagetemp[(i) * (width+1) + (j)] = binaryImage[(i-1) * (width-1 ) + j-1];
		}
	}


	unsigned int label = 0;

	bool test = true;


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((New_Raw[(i) * (width) + (j)] == 0) && ( 0 != binaryImage[i * width + j]))
			{
				test = true;
				for (int k = -1; k < 2; k++)
				{
					for (int l = -1 ; l < 2; l++)
					{
						if (binaryImagetemp[(i+1+k)*(width+1) + height+1+l] != 0)
						{
							label++;
							binaryImagetemp[(i + 1 + k) * (width + 1) + height + 1 + l] = label;
						}

					}
				}
			}

		}
	}

	for (int i = 1; i < height; i++)
	{
		for (int j = 1; j < width; j++)
		{
			New_Raw[(i-1) * (width-1) + (j-1)] = binaryImagetemp[(i+1)*(width+1)+j+1];
		}
	}




	return New_Raw;
}
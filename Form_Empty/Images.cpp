#include "Images.h"


void Images::setBuffer(LPCTSTR bmpfilee)
{
	long size;

	this->Buffer =  LoadBMP(&width, &height, &size, bmpfilee);

}

unsigned int Images::getWidth()
{
	return this->width;
}

Bitmap^ Images::ShowLabelImage()
{
		int cc[256][3];

		for (int i = 0; i < 256; i++)
		{
			cc[i][0] = rand() % 255;
			cc[i][1] = rand() % 255;
			cc[i][2] = rand() % 255;
		}

		unsigned char* output = LabelImage();

		Bitmap^ outputImage = gcnew Bitmap(width,height);

		for (unsigned int i = 0; i < height; i++)
		{
			for (unsigned int j = 0; j < width; j++)
			{
				if (output[i * width + j] != 0)
				{
					outputImage->SetPixel(j, i, Color::FromArgb(cc[output[i * width + j]][0], cc[output[i * width + j]][1], cc[output[i * width + j]][2]));
				}
				else
				{
					outputImage->SetPixel(j, i, Color::FromArgb(255, 255, 255));

				}
			}
		}

		return outputImage;

}

unsigned int Images::getHeight()
{
	return this->height;
}

unsigned int Images::getnumofBox()
{
	return numofBox;
}

unsigned char* Images::getRawIntensity()
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
	for (unsigned int row = 0; row < height; row++)
		for (unsigned int column = 0; column < width; column++) {
			newpos = row * width + column;
			bufpos = (height - row - 1) * psw + column * 3;
			newbuf[newpos] = BYTE(0.11 * Buffer[bufpos + 2] + 0.59 * Buffer[bufpos + 1] + 0.3 * Buffer[bufpos]);
		}

	return newbuf;
}

Bitmap^ Images::getRawToImage(unsigned char* img, unsigned int w, unsigned int h)
{
	Bitmap^ surface = gcnew Bitmap(w, h);

	Color c;
	int temp;
	for (int row = 0; row < h; row++)
	{
		for (int column = 0; column < w; column++)
		{
			temp = row * w + column;
			c = Color::FromArgb(img[temp], img[temp], img[temp]);
			surface->SetPixel(column, row, c);
		}
	}
	return surface;
}

BYTE* Images::LoadBMP(unsigned int* widthh, unsigned int* heightt, long* sizee, LPCTSTR bmpfilee)
{
	// declare bitmap structures
	BITMAPFILEHEADER bmpheader;
	BITMAPINFOHEADER bmpinfo;
	// value to be used in ReadFile funcs
	DWORD bytesread;
	// open file to read from
	HANDLE file = CreateFile(bmpfilee, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
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
	*widthh = bmpinfo.biWidth;
	*heightt = abs(bmpinfo.biHeight);

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
	*sizee = bmpheader.bfSize - bmpheader.bfOffBits;
	BYTE* Bufferr = new BYTE[*sizee];
	// move file pointer to start of bitmap data
	SetFilePointer(file, bmpheader.bfOffBits, NULL, FILE_BEGIN);
	// read bmp data
	if (ReadFile(file, Bufferr, *sizee, &bytesread, NULL) == false) {
		delete[] Bufferr;
		CloseHandle(file);
		return NULL;
	}
	// everything successful here: close file and return buffer
	CloseHandle(file);

	return Bufferr;
}

unsigned char* Images::setMaskImage(double* mask, int kcol, int krow, int padding, int stride)
{
	int out_col = ((width - kcol + 2 * padding) / stride) + 1;
	int out_row = ((height - krow + 2 * padding) / stride) + 1;

	double sum = 0;
	unsigned char* mask_image = new BYTE[out_col * out_row];
	unsigned char* Raw_Intensity = this->getRawIntensity();
	for (unsigned int i = 1; i < height; i += stride)
	{
		for (unsigned int j = 1; j < width; j += stride)
		{
			sum = 0;
			for (int k = 0; k < krow; k++)
			{
				for (int l = 0; l < kcol; l++)
				{
					sum += Raw_Intensity[(i - 1 + k) * width + (j - 1 + l)] * mask[k * kcol + l];
				}
			}
			mask_image[(((i - 1) / stride) * (out_col)) + ((j - 1) / stride)] = ((unsigned char)(sum));
		}
	}

	return mask_image;
}

unsigned int* Images::getHistogram()
{
	unsigned int* histogram = new unsigned int[256];

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

BYTE* Images::LabelImage()
{
	int labelNo = 0;
	int index = -1;

	unsigned char* output = new unsigned char[width * height];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			output[i * width + j] = 0;
		}
	}

	unsigned char* binary_image = getBinaryImage(twoColorKmeans());


	for (unsigned int y = 0; y < height; y++)
	{
		for (unsigned int x = 0; x < width; x++)
		{
			index++;
			if (binary_image[index] == 0) continue;
			if (output[index] != 0) continue;

			labelNo++;
			LabelComponent(binary_image, output, labelNo, x, y);
		}
	}

	numofBox = labelNo;

	return output;
}

float Images::twoColorKmeans()
{
	float present_k1;
	float next_k1 = 0;
	float present_temp1;
	unsigned int* histogram = new unsigned int[256];
	histogram = getHistogram();
	present_k1 = float(rand() % 255 + 1);
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

void Images::LabelComponent(unsigned char* input, BYTE* output, int labelNo, unsigned int x, unsigned int y)
{
	int index = x + width * y;
	if (input[index] == 0) return;
	if (output[index] != 0) return;
	output[index] = labelNo;

	if (x > 0)        LabelComponent(input, output, labelNo, x - 1, y);   /* left  pixel */
	if (x < width - 1)  LabelComponent(input, output, labelNo, x + 1, y);   /* right pixel */
	if (y > 0)        LabelComponent(input, output, labelNo, x, y - 1);   /* upper pixel */
	if (y < height - 1) LabelComponent(input, output, labelNo, x, y + 1);   /* lower pixel */

}

Bitmap^ Images::ShowBinary()
{
	unsigned char* img = getBinaryImage(twoColorKmeans());
	Bitmap^ surface = gcnew Bitmap(width, height);

	Color c;
	int temp;
	for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width; column++)
		{
			temp = row * width + column;
			if (img[temp] == 1)
			{
				c = Color::FromArgb(0, 0, 0);
				surface->SetPixel(column, row, c);
			}
			else {
				c = Color::FromArgb(255, 255, 255);
				surface->SetPixel(column, row, c);
			}

		}
	}
	return surface;
}

unsigned char* Images::getBinaryImage(float k1)
{
	unsigned char* binary_image = new unsigned char[width * height];
	unsigned char* Raw_Intensity = getRawIntensity();
	for (unsigned int row = 0; row < height; row++)
	{
		for (unsigned int column = 0; column < width; column++)
		{

			if (*(Raw_Intensity + (row * width + column)) < k1)
			{
				*(binary_image + (row * width + column)) = 1;
			}
			else if (*(Raw_Intensity + (row * width + column)) >= k1)
			{
				*(binary_image + (row * width + column)) = 0;
			}

		}
	}

	return binary_image;

}

Box* Images::getBoxes() {

	unsigned char* output = LabelImage();
	Box* Boxes = new Box[numofBox];

	for (unsigned int value = 0; value < numofBox + 1; value++)
	{
		int area = 0;
		int sayac = 0;


		

		for (unsigned int i = 0; i < height; i++)
		{

			for (unsigned int j = 0; j < width; j++)
			{

				if (output[i * width + j] == (value + 1))
				{
					if (sayac == 0)
					{
						Boxes[value].setendX(j);
						Boxes[value].setendY(i);
						Boxes[value].setfirstX(j);
						Boxes[value].setfirstY(i);
						sayac++;
					}

					if (Boxes[value].getfirstX() > j)
					{
						Boxes[value].setfirstX(j);
					}
					if (Boxes[value].getendX() < j)
					{
						Boxes[value].setendX(j);
					}

					if (Boxes[value].getfirstY() > i)
					{
						Boxes[value].setfirstY(i);
					}
					if (Boxes[value].getendY() < i)
					{
						Boxes[value].setendY(i);
					}
					area++;

				}

			}

		}

		Boxes[value].setArea(area);

	}

	return Boxes;


}
#pragma once
#include<Windows.h>
#include<time.h>
#include<iostream>
#include<atlstr.h>
#include"imge.h"
#include "histogram.h"
#include "rgbhistogram.h"
#include "NumericUp.h"

namespace Form_Empty {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readImageToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	public:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int* histogram, ** rgbhistogram;
		int Width, Height;
		long Size;
		BYTE* Buffer, * Raw_Intensity;
		BYTE* New_Raw;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ maskToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ colorsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ multipleColorToolStripMenuItem;



	private: System::Windows::Forms::ToolStripMenuItem^ grayToneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ grayToneToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ rGBToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ rGBToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ histogramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ kMeansToolStripMenuItem;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::ToolStripMenuItem^ grayToneToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ multipleColor2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ neighborhoodToolStripMenuItem;

	public:


	public:



		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->maskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grayToneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rGBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kMeansToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multipleColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grayToneToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multipleColor2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->histogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grayToneToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rGBToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->neighborhoodToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1602, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->readImageToolStripMenuItem,
					this->processToolStripMenuItem, this->showToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// readImageToolStripMenuItem
			// 
			this->readImageToolStripMenuItem->Name = L"readImageToolStripMenuItem";
			this->readImageToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->readImageToolStripMenuItem->Text = L"Read Image";
			this->readImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::readImageToolStripMenuItem_Click);
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->maskToolStripMenuItem,
					this->kMeansToolStripMenuItem, this->neighborhoodToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// maskToolStripMenuItem
			// 
			this->maskToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->grayToneToolStripMenuItem,
					this->rGBToolStripMenuItem
			});
			this->maskToolStripMenuItem->Name = L"maskToolStripMenuItem";
			this->maskToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->maskToolStripMenuItem->Text = L"Mask";
			// 
			// grayToneToolStripMenuItem
			// 
			this->grayToneToolStripMenuItem->Name = L"grayToneToolStripMenuItem";
			this->grayToneToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->grayToneToolStripMenuItem->Text = L"Gray Tone";
			this->grayToneToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::grayToneToolStripMenuItem_Click);
			// 
			// rGBToolStripMenuItem
			// 
			this->rGBToolStripMenuItem->Name = L"rGBToolStripMenuItem";
			this->rGBToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->rGBToolStripMenuItem->Text = L"RGB";
			this->rGBToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rGBToolStripMenuItem_Click);
			// 
			// kMeansToolStripMenuItem
			// 
			this->kMeansToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->colorsToolStripMenuItem,
					this->multipleColorToolStripMenuItem, this->grayToneToolStripMenuItem2, this->multipleColor2ToolStripMenuItem
			});
			this->kMeansToolStripMenuItem->Name = L"kMeansToolStripMenuItem";
			this->kMeansToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->kMeansToolStripMenuItem->Text = L"K-Means";
			// 
			// colorsToolStripMenuItem
			// 
			this->colorsToolStripMenuItem->Name = L"colorsToolStripMenuItem";
			this->colorsToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->colorsToolStripMenuItem->Text = L"2 Colors";
			this->colorsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::colorsToolStripMenuItem_Click);
			// 
			// multipleColorToolStripMenuItem
			// 
			this->multipleColorToolStripMenuItem->Name = L"multipleColorToolStripMenuItem";
			this->multipleColorToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->multipleColorToolStripMenuItem->Text = L"Multiple Color";
			this->multipleColorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::multipleColorToolStripMenuItem_Click);
			// 
			// grayToneToolStripMenuItem2
			// 
			this->grayToneToolStripMenuItem2->Name = L"grayToneToolStripMenuItem2";
			this->grayToneToolStripMenuItem2->Size = System::Drawing::Size(180, 22);
			this->grayToneToolStripMenuItem2->Text = L"Gray Tone";
			this->grayToneToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::grayToneToolStripMenuItem2_Click);
			// 
			// multipleColor2ToolStripMenuItem
			// 
			this->multipleColor2ToolStripMenuItem->Name = L"multipleColor2ToolStripMenuItem";
			this->multipleColor2ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->multipleColor2ToolStripMenuItem->Text = L"Multiple Color 2";
			this->multipleColor2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::multipleColor2ToolStripMenuItem_Click);
			// 
			// showToolStripMenuItem
			// 
			this->showToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->histogramToolStripMenuItem });
			this->showToolStripMenuItem->Name = L"showToolStripMenuItem";
			this->showToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->showToolStripMenuItem->Text = L"View";
			// 
			// histogramToolStripMenuItem
			// 
			this->histogramToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->grayToneToolStripMenuItem1,
					this->rGBToolStripMenuItem1
			});
			this->histogramToolStripMenuItem->Name = L"histogramToolStripMenuItem";
			this->histogramToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->histogramToolStripMenuItem->Text = L"Histogram";
			// 
			// grayToneToolStripMenuItem1
			// 
			this->grayToneToolStripMenuItem1->Name = L"grayToneToolStripMenuItem1";
			this->grayToneToolStripMenuItem1->Size = System::Drawing::Size(126, 22);
			this->grayToneToolStripMenuItem1->Text = L"Gray Tone";
			this->grayToneToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::grayToneToolStripMenuItem1_Click);
			// 
			// rGBToolStripMenuItem1
			// 
			this->rGBToolStripMenuItem1->Name = L"rGBToolStripMenuItem1";
			this->rGBToolStripMenuItem1->Size = System::Drawing::Size(126, 22);
			this->rGBToolStripMenuItem1->Text = L"RGB";
			this->rGBToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::rGBToolStripMenuItem1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(441, 339);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(840, 27);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(441, 339);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->flowLayoutPanel1->Location = System::Drawing::Point(1271, 338);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(319, 181);
			this->flowLayoutPanel1->TabIndex = 3;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->AutoScroll = true;
			this->flowLayoutPanel2->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->flowLayoutPanel2->Location = System::Drawing::Point(1271, 40);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(319, 269);
			this->flowLayoutPanel2->TabIndex = 4;
			// 
			// neighborhoodToolStripMenuItem
			// 
			this->neighborhoodToolStripMenuItem->Name = L"neighborhoodToolStripMenuItem";
			this->neighborhoodToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->neighborhoodToolStripMenuItem->Text = L"Neighborhood";
			this->neighborhoodToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::neighborhoodToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1602, 677);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void readImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		CString str;
		LPCTSTR input;
		delete[] Buffer;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			str = openFileDialog1->FileName;
			input = (LPCTSTR)str;
			Buffer = LoadBMP(Width, Height, Size, input);
			pictureBox1->Width = Width;
			pictureBox1->Height = Height;

			this->pictureBox1->ImageLocation = openFileDialog1->FileName;

			Raw_Intensity = ConvertToIntensity(Buffer, Width, Height);

			Bitmap^ s = ShowIntensity(Raw_Intensity, Width, Height);
			pictureBox2->Location = System::Drawing::Point(pictureBox1->Location.X + pictureBox1->Width + 10, pictureBox1->Location.Y);
			pictureBox2->Width = Width;
			pictureBox2->Height = Height;
			pictureBox2->Image = s;


		}







	}

	private: System::Void colorsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		float k1 = twoColorKmeans(Width, Height, histogram);

		Bitmap^ output = gcnew Bitmap(Width, Height);


		for (unsigned int row = 0; row < Height; row++)
		{
			for (unsigned int column = 0; column < Width; column++)
			{

				if (*(Raw_Intensity + (row * Width + column)) < k1)
				{
					Color c = Color::FromArgb(0, 0, 0);
					output->SetPixel(column, row, c);
					*(Raw_Intensity + (row * Width + column)) = 0;
				}
				else if (*(Raw_Intensity + (row * Width + column)) >= k1)
				{
					Color c = Color::FromArgb(255, 255, 255);
					output->SetPixel(column, row, c);
					*(Raw_Intensity + (row * Width + column)) = 255;
				}

			}
		}

		pictureBox2->Image = output;


	}

	private: System::Void grayToneToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		int kcol = 3;
		int krow = 3;
		int padding = 0;
		int stride = 1;

		int out_col = ((Width - kcol + 2 * padding) / stride) + 1;
		int out_row = ((Height - krow + 2 * padding) / stride) + 1;

		float km[9] = { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0 };

		BYTE* NEW_RAW = GrayToneMask(Raw_Intensity, Width, Height, km, kcol, krow, padding, stride);

		pictureBox2->Width = out_col;
		pictureBox2->Height = out_row;

		Bitmap^ o = ShowIntensity(NEW_RAW, out_col, out_row);

		pictureBox2->Image = nullptr;
		pictureBox2->Image = o;
	}

	private: System::Void grayToneToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {

		histogram = GrayToneHistogram(Raw_Intensity, Width, Height);

		Form_Empty::histogram histogramForm(histogram);

		histogramForm.ShowDialog();
	}

	private: System::Void rGBToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		int kcol = 6;
		int krow = 6;
		int padding = 0;
		int stride = 1;

		Bitmap^ input = (Bitmap^)pictureBox1->Image;

		int out_col = ((Width - kcol + 2 * padding) / stride) + 1;
		int out_row = ((Height - krow + 2 * padding) / stride) + 1;

		float* km = new float[kcol * krow];

		for (int i = 0; i < kcol * krow; i++)
		{
			*(km + i) = 1.0 / (float)(kcol * krow);
		}

		Bitmap^ o = ImageMask(input, Width, Height, km, kcol, krow, padding, stride);

		pictureBox2->Width = out_col;
		pictureBox2->Height = out_row;


		pictureBox2->Image = nullptr;
		pictureBox2->Image = o;

	}

	private: System::Void rGBToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {

		Bitmap^ input = (Bitmap^)pictureBox1->Image;

		rgbhistogram = RGBHistogram(input, Width, Height);

		Form_Empty::rgbhistogram rgbhistogramForm(rgbhistogram);



		rgbhistogramForm.ShowDialog();
	}

	private: System::Void multipleColorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		Form_Empty::NumericUp1 a;
		a.ShowDialog();

		int b = a.a;
		Bitmap^ input = (Bitmap^)pictureBox1->Image;

		float** k1 = MultipleColorKmeans(b, Width, Height, rgbhistogram);




		Bitmap^ output = gcnew Bitmap(Width, Height);


		for (unsigned int row = 0; row < Height; row++)
		{
			for (unsigned int column = 0; column < Width; column++)
			{

				Color inc = input->GetPixel(column, row);
				Color outc;

				float mindis = 100000;
				int sayac = 0;
				mindis = getDistance(k1[0][0], inc.R, k1[0][1], inc.G, k1[0][2], inc.B);
				for (int i = 0; i < b; i++)
				{

					if (mindis > getDistance(k1[i][0], inc.R, k1[i][1], inc.G, k1[i][2], inc.B))
					{
						mindis = getDistance(k1[i][0], inc.R, k1[i][1], inc.G, k1[i][2], inc.B);
						sayac++;
					}
				}

				outc = Color::FromArgb(k1[sayac - 1][0], k1[sayac - 1][1], k1[sayac - 1][2]);


				output->SetPixel(column, row, outc);

			}
		}
		addcontrol(k1, b);
		addcontrol2(rgbhistogram);
		pictureBox2->Image = output;



	}

	void addcontrol(float** a, int k) {


			   flowLayoutPanel1->Controls->Clear();
			   for (int i = 0; i < k; i++)
			   {
				   FlowLayoutPanel^ f = gcnew FlowLayoutPanel();
				   Label^ knumber = gcnew Label();
				   Label^ l1 = gcnew Label();
				   Label^ l2 = gcnew Label();
				   Label^ l3 = gcnew Label();

				   knumber->Text = "k" + i.ToString();
				   l1->Text = a[i][0].ToString();
				   l2->Text = a[i][1].ToString();
				   l3->Text = a[i][2].ToString();

				   f->Controls->Add(knumber);
				   f->Controls->Add(l1);
				   f->Controls->Add(l2);
				   f->Controls->Add(l3);
				   flowLayoutPanel1->Controls->Add(f);

			   }




		   }

	void addcontrol2(int** a) {


			   flowLayoutPanel2->Controls->Clear();
			   for (int i = 0; i < 256; i++)
			   {
				   FlowLayoutPanel^ f = gcnew FlowLayoutPanel();
				   Label^ knumber = gcnew Label();
				   Label^ l1 = gcnew Label();
				   Label^ l2 = gcnew Label();
				   Label^ l3 = gcnew Label();

				   knumber->Text = "h" + i.ToString();
				   l1->Text = "R " + a[0][i].ToString();
				   l2->Text = "G " + a[1][i].ToString();
				   l3->Text = "B " + a[2][i].ToString();

				   f->Controls->Add(knumber);
				   f->Controls->Add(l1);
				   f->Controls->Add(l2);
				   f->Controls->Add(l3);
				   flowLayoutPanel2->Controls->Add(f);

			   }




		   }

	private: System::Void grayToneToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {

		Form_Empty::NumericUp1 a;
		a.ShowDialog();

		int b = a.a;
		Bitmap^ input = (Bitmap^)pictureBox1->Image;

		float* k1 = GreyToneKmeans(b, Width, Height, histogram);




		Bitmap^ output = gcnew Bitmap(Width, Height);


		for (unsigned int row = 0; row < Height; row++)
		{
			for (unsigned int column = 0; column < Width; column++)
			{

				Color inc = input->GetPixel(column, row);
				Color outc;
				float distance;
				float mindis = 100000;
				int sayac = 0;

				for (int i = 0; i < b; i++)
				{
					distance = abs(k1[i] - *(Raw_Intensity + ((row * Width) + column)));
					if (mindis > distance)
					{
						mindis = distance;
						sayac++;
					}
				}

				outc = Color::FromArgb(k1[sayac - 1], k1[sayac - 1], k1[sayac - 1]);


				output->SetPixel(column, row, outc);

			}
		}

		pictureBox2->Image = output;



	}

	private: System::Void multipleColor2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Form_Empty::NumericUp1 a;
		a.ShowDialog();

		int b = a.a;
		Bitmap^ input = (Bitmap^)pictureBox1->Image;

		float** k1 = MultipleColorKmeans2(input, b, Width, Height);




		Bitmap^ output = gcnew Bitmap(Width, Height);


		for (unsigned int row = 0; row < Height; row++)
		{
			for (unsigned int column = 0; column < Width; column++)
			{

				Color inc = input->GetPixel(column, row);
				Color outc;
				float distance;
				float mindis = 100000;
				int sayac = 0;

				for (int i = 0; i < b; i++)
				{
					distance = getDistance(k1[i][0], inc.R, k1[i][1], inc.G, k1[i][2], inc.B);
					if (mindis > distance)
					{
						mindis = distance;
						sayac++;
					}
				}

				outc = Color::FromArgb(k1[sayac - 1][0], k1[sayac - 1][1], k1[sayac - 1][2]);


				output->SetPixel(column, row, outc);

			}
		}
		addcontrol(k1, b);
		addcontrol2(rgbhistogram);
		pictureBox2->Image = output;


	}

	private: System::Void neighborhoodToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {




		unsigned char * outputbinary = neighborhood(Raw_Intensity, Width, Height);

		Bitmap^ output = ShowIntensity(outputbinary, Width, Height);

		pictureBox1->Image = output;


	}
	};
}



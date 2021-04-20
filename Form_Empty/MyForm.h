#pragma once
#include<Windows.h>
#include<iostream>
#include<atlstr.h>
#include"imge.h"
#include "histogram.h"

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
		int Width, Height;
		long Size;
		BYTE *Buffer , *Raw_Intensity;
		BYTE* New_Raw;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ maskToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ histogramToolStripMenuItem;

	public:


	public:



		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		Bitmap^ ShowIntensity(unsigned char* img , int w , int h) {
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
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->maskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->showToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->histogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Size = System::Drawing::Size(1488, 24);
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
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->maskToolStripMenuItem });
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// maskToolStripMenuItem
			// 
			this->maskToolStripMenuItem->Name = L"maskToolStripMenuItem";
			this->maskToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->maskToolStripMenuItem->Text = L"Mask";
			this->maskToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::maskToolStripMenuItem_Click);
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
			// showToolStripMenuItem
			// 
			this->showToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->histogramToolStripMenuItem });
			this->showToolStripMenuItem->Name = L"showToolStripMenuItem";
			this->showToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->showToolStripMenuItem->Text = L"Show";
			// 
			// histogramToolStripMenuItem
			// 
			this->histogramToolStripMenuItem->Name = L"histogramToolStripMenuItem";
			this->histogramToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->histogramToolStripMenuItem->Text = L"Histogram";
			this->histogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::histogramToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1488, 635);
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
			pictureBox2->Location = System::Drawing::Point(pictureBox1->Location.X + pictureBox1->Width +10, pictureBox1->Location.Y );
			pictureBox2->Width = Width;
			pictureBox2->Height = Height;
			pictureBox2->Image = s;

		}


	}

private: System::Void maskToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	int kcol = 3;
	int krow = 3;
	int padding = 0;
	int stride = 1;

	double km[9] = { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0 };

	int out_col = ((Width - kcol + 2 * padding) / stride) + 1;
	int out_row = ((Height - krow + 2 * padding) / stride) + 1;

	int sum = 0;
	New_Raw = new BYTE[out_col * out_row];


	for (int i = 1; i < out_row; i++)
	{
		for (int j = 1; j < out_col; j++)
		{
			sum = 0;
			for (int k = 0; k < krow; k++)
			{
				for (int l = 0; l < kcol; l++)
				{
					sum += Raw_Intensity[(i - 1 + k) * Width + (j - 1 + l)] * km[k * kcol + l];
					//sum += Buffer[(i + k) * Width + (j + l)] * km[k * kcol + l];
				}
			}
			*(New_Raw + (i * out_col + j))=sum  ;
		}
	}

	pictureBox2->Width = out_col;
	pictureBox2->Height = out_row;
	Bitmap^ o = ShowIntensity(New_Raw, out_col, out_row);
	pictureBox2->Image = o;
	
}


private: System::Void histogramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	int b[256];
	for (int i = 0; i < 256; i++)
	{
		b[i] = 0;
	}
	
	int temp;
	for (unsigned int row = 0; row < Height; row++)
	{
		for (unsigned int column = 0; column < Width; column++)
		{
			temp = row * Width + column;
			b[Buffer[temp]]++;
		}
	}

	Form_Empty::histogram histogramForm(b);

	histogramForm.ShowDialog();

}
};
}

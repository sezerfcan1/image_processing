#pragma once
#include <atlstr.h>
#include"Images.h"
#include"histogram.h"
#include <fstream>
#include <string>
#include "HuMoment.h"

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
	private: System::Windows::Forms::ToolStripMenuItem^ ReadImage;
	private: System::Windows::Forms::PictureBox^ pgMiniImage;
	private: System::Windows::Forms::Button^ Verify;
	private: System::Windows::Forms::ComboBox^ objtype;
	private: System::Windows::Forms::Button^ btnGues;
	private: System::Windows::Forms::Label^ lblResult;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::ListBox^ listBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::PictureBox^ pbMainImage;

	private:
		bool getResult(double a, double b) {

			if (abs(a - b) < a / double(5))
			{
				return true;
			}
			else
			{
				return false;
			}

		}

		unsigned int getBox(System::Windows::Forms::MouseEventArgs^ e)
		{
			unsigned int i = 0;

			while (!((e->X < boxes[i].getendX()) && (e->X > boxes[i].getfirstX()) && (e->Y < boxes[i].getendY()) && (e->Y > boxes[i].getfirstY())))
			{
				i++;
			}
			return i;
		}
		int selectedbox;
		Images* image;
		Box* boxes;
	private: System::Windows::Forms::ToolStripMenuItem^ viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ShowIntensityInPb1;
	private: System::Windows::Forms::ToolStripMenuItem^ ShowIntensityMaskInPb1;
	private: System::Windows::Forms::ToolStripMenuItem^ ShowHistogramForm;
	private: System::Windows::Forms::ToolStripMenuItem^ ShowBinaryImage;
	private: System::Windows::Forms::ToolStripMenuItem^ ShowLabelImage;
	private: System::Windows::Forms::ToolStripMenuItem^ ShowBoxes;

		   /// <summary>
		   /// Required designer variable.
		   /// </summary>
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
			   this->ReadImage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ShowIntensityInPb1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ShowIntensityMaskInPb1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ShowHistogramForm = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ShowBinaryImage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ShowLabelImage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ShowBoxes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->pbMainImage = (gcnew System::Windows::Forms::PictureBox());
			   this->pgMiniImage = (gcnew System::Windows::Forms::PictureBox());
			   this->Verify = (gcnew System::Windows::Forms::Button());
			   this->objtype = (gcnew System::Windows::Forms::ComboBox());
			   this->btnGues = (gcnew System::Windows::Forms::Button());
			   this->lblResult = (gcnew System::Windows::Forms::Label());
			   this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->menuStrip1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMainImage))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pgMiniImage))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->fileToolStripMenuItem,
					   this->viewToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1451, 24);
			   this->menuStrip1->TabIndex = 0;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ReadImage });
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // ReadImage
			   // 
			   this->ReadImage->Name = L"ReadImage";
			   this->ReadImage->Size = System::Drawing::Size(136, 22);
			   this->ReadImage->Text = L"Read Image";
			   this->ReadImage->Click += gcnew System::EventHandler(this, &MyForm::ReadImage_Click);
			   // 
			   // viewToolStripMenuItem
			   // 
			   this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				   this->ShowIntensityInPb1,
					   this->ShowIntensityMaskInPb1, this->ShowHistogramForm, this->ShowBinaryImage, this->ShowLabelImage, this->ShowBoxes
			   });
			   this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			   this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			   this->viewToolStripMenuItem->Text = L"View";
			   // 
			   // ShowIntensityInPb1
			   // 
			   this->ShowIntensityInPb1->Name = L"ShowIntensityInPb1";
			   this->ShowIntensityInPb1->Size = System::Drawing::Size(143, 22);
			   this->ShowIntensityInPb1->Text = L"Intensity";
			   this->ShowIntensityInPb1->Click += gcnew System::EventHandler(this, &MyForm::ShowIntensityInPb1_Click);
			   // 
			   // ShowIntensityMaskInPb1
			   // 
			   this->ShowIntensityMaskInPb1->Name = L"ShowIntensityMaskInPb1";
			   this->ShowIntensityMaskInPb1->Size = System::Drawing::Size(143, 22);
			   this->ShowIntensityMaskInPb1->Text = L"Mask";
			   this->ShowIntensityMaskInPb1->Click += gcnew System::EventHandler(this, &MyForm::ShowIntensityMaskInPb1_Click);
			   // 
			   // ShowHistogramForm
			   // 
			   this->ShowHistogramForm->Name = L"ShowHistogramForm";
			   this->ShowHistogramForm->Size = System::Drawing::Size(143, 22);
			   this->ShowHistogramForm->Text = L"Histogram";
			   this->ShowHistogramForm->Click += gcnew System::EventHandler(this, &MyForm::ShowHistogramForm_Click);
			   // 
			   // ShowBinaryImage
			   // 
			   this->ShowBinaryImage->Name = L"ShowBinaryImage";
			   this->ShowBinaryImage->Size = System::Drawing::Size(143, 22);
			   this->ShowBinaryImage->Text = L"Binary Image";
			   this->ShowBinaryImage->Click += gcnew System::EventHandler(this, &MyForm::ShowBinaryImage_Click);
			   // 
			   // ShowLabelImage
			   // 
			   this->ShowLabelImage->Name = L"ShowLabelImage";
			   this->ShowLabelImage->Size = System::Drawing::Size(143, 22);
			   this->ShowLabelImage->Text = L"Label Image";
			   this->ShowLabelImage->Click += gcnew System::EventHandler(this, &MyForm::ShowLabelImage_Click);
			   // 
			   // ShowBoxes
			   // 
			   this->ShowBoxes->Name = L"ShowBoxes";
			   this->ShowBoxes->Size = System::Drawing::Size(143, 22);
			   this->ShowBoxes->Text = L"Boxes";
			   this->ShowBoxes->Click += gcnew System::EventHandler(this, &MyForm::ShowBoxes_Click);
			   // 
			   // pbMainImage
			   // 
			   this->pbMainImage->Location = System::Drawing::Point(13, 28);
			   this->pbMainImage->Name = L"pbMainImage";
			   this->pbMainImage->Size = System::Drawing::Size(663, 497);
			   this->pbMainImage->TabIndex = 1;
			   this->pbMainImage->TabStop = false;
			   this->pbMainImage->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pbMainImage_MouseClick);
			   // 
			   // pgMiniImage
			   // 
			   this->pgMiniImage->Location = System::Drawing::Point(719, 28);
			   this->pgMiniImage->Name = L"pgMiniImage";
			   this->pgMiniImage->Size = System::Drawing::Size(131, 161);
			   this->pgMiniImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			   this->pgMiniImage->TabIndex = 2;
			   this->pgMiniImage->TabStop = false;
			   // 
			   // Verify
			   // 
			   this->Verify->Location = System::Drawing::Point(719, 443);
			   this->Verify->Name = L"Verify";
			   this->Verify->Size = System::Drawing::Size(75, 23);
			   this->Verify->TabIndex = 3;
			   this->Verify->Text = L"Verify";
			   this->Verify->UseVisualStyleBackColor = true;
			   this->Verify->Click += gcnew System::EventHandler(this, &MyForm::Verify_Click);
			   // 
			   // objtype
			   // 
			   this->objtype->FormattingEnabled = true;
			   this->objtype->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Cekirdek", L"Biber", L"Mercimek" });
			   this->objtype->Location = System::Drawing::Point(719, 340);
			   this->objtype->Name = L"objtype";
			   this->objtype->Size = System::Drawing::Size(121, 21);
			   this->objtype->TabIndex = 4;
			   // 
			   // btnGues
			   // 
			   this->btnGues->Location = System::Drawing::Point(870, 443);
			   this->btnGues->Name = L"btnGues";
			   this->btnGues->Size = System::Drawing::Size(75, 23);
			   this->btnGues->TabIndex = 5;
			   this->btnGues->Text = L"btnGues";
			   this->btnGues->UseVisualStyleBackColor = true;
			   this->btnGues->Click += gcnew System::EventHandler(this, &MyForm::btnGues_Click);
			   // 
			   // lblResult
			   // 
			   this->lblResult->AutoSize = true;
			   this->lblResult->Location = System::Drawing::Point(891, 343);
			   this->lblResult->Name = L"lblResult";
			   this->lblResult->Size = System::Drawing::Size(37, 13);
			   this->lblResult->TabIndex = 6;
			   this->lblResult->Text = L"Result";
			   // 
			   // listBox1
			   // 
			   this->listBox1->FormattingEnabled = true;
			   this->listBox1->Location = System::Drawing::Point(870, 53);
			   this->listBox1->Name = L"listBox1";
			   this->listBox1->Size = System::Drawing::Size(120, 186);
			   this->listBox1->TabIndex = 7;
			   // 
			   // listBox2
			   // 
			   this->listBox2->FormattingEnabled = true;
			   this->listBox2->Location = System::Drawing::Point(997, 53);
			   this->listBox2->Name = L"listBox2";
			   this->listBox2->Size = System::Drawing::Size(120, 186);
			   this->listBox2->TabIndex = 8;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(870, 34);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(43, 13);
			   this->label1->TabIndex = 9;
			   this->label1->Text = L"Chosen";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(997, 34);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(49, 13);
			   this->label2->TabIndex = 10;
			   this->label2->Text = L"Cekirdek";
			   // 
			   // listBox3
			   // 
			   this->listBox3->FormattingEnabled = true;
			   this->listBox3->Location = System::Drawing::Point(1124, 53);
			   this->listBox3->Name = L"listBox3";
			   this->listBox3->Size = System::Drawing::Size(120, 186);
			   this->listBox3->TabIndex = 11;
			   // 
			   // listBox4
			   // 
			   this->listBox4->FormattingEnabled = true;
			   this->listBox4->Location = System::Drawing::Point(1251, 53);
			   this->listBox4->Name = L"listBox4";
			   this->listBox4->Size = System::Drawing::Size(120, 186);
			   this->listBox4->TabIndex = 12;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(1124, 34);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(31, 13);
			   this->label3->TabIndex = 13;
			   this->label3->Text = L"Biber";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(1251, 34);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(53, 13);
			   this->label4->TabIndex = 14;
			   this->label4->Text = L"Mercimek";
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1451, 537);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->listBox4);
			   this->Controls->Add(this->listBox3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->listBox2);
			   this->Controls->Add(this->listBox1);
			   this->Controls->Add(this->lblResult);
			   this->Controls->Add(this->btnGues);
			   this->Controls->Add(this->objtype);
			   this->Controls->Add(this->Verify);
			   this->Controls->Add(this->pgMiniImage);
			   this->Controls->Add(this->pbMainImage);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMainImage))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pgMiniImage))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }


#pragma endregion
	private: System::Void ReadImage_Click(System::Object^ sender, System::EventArgs^ e) {

		OpenFileDialog^ fileOpen = gcnew OpenFileDialog();

		fileOpen->ShowDialog();

		CString str;
		LPCTSTR input;

		pbMainImage->ImageLocation = fileOpen->FileName;

		str = fileOpen->FileName;
		input = (LPCTSTR)str;

		image = new Images();

		image->setBuffer(input);

	}
	private: System::Void ShowIntensityInPb1_Click(System::Object^ sender, System::EventArgs^ e) {

		unsigned int w = image->getWidth();
		unsigned int h = image->getHeight();

		pbMainImage->Width = w;
		pbMainImage->Height = h;
		unsigned char* Raw_Intensity = image->getRawIntensity();


		pbMainImage->Image = Images::getRawToImage(Raw_Intensity, w, h);


	}
	private: System::Void ShowIntensityMaskInPb1_Click(System::Object^ sender, System::EventArgs^ e) {

		double km[9] = { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0 };
		unsigned char* Raw_Intensity = image->getRawIntensity();

		int out_col = ((image->getWidth() - 3 + 2 * 0) / 1) + 1;
		int out_row = ((image->getHeight() - 3 + 2 * 0) / 1) + 1;
		pbMainImage->Width = out_col;
		pbMainImage->Height = out_row;

		pbMainImage->Image = Images::getRawToImage(image->setMaskImage(km, 3, 3, 0, 1), out_col, out_row);

	}




	private: System::Void ShowHistogramForm_Click(System::Object^ sender, System::EventArgs^ e) {

		unsigned int* histogramarray = image->getHistogram();

		Form_Empty::histogram histogram(histogramarray);

		histogram.ShowDialog();
	}


	private: System::Void ShowBinaryImage_Click(System::Object^ sender, System::EventArgs^ e) {



		pbMainImage->Image = image->ShowBinary();





	}
	private: System::Void ShowLabelImage_Click(System::Object^ sender, System::EventArgs^ e) {

		pbMainImage->Image = image->ShowLabelImage();



	}
	private: System::Void ShowBoxes_Click(System::Object^ sender, System::EventArgs^ e) {

		Pen^ p = gcnew Pen(Color::Red, 2.0f);

		boxes = image->getBoxes();

		Graphics^ g = Graphics::FromImage(pbMainImage->Image);

		unsigned int numofboxes = image->getnumofBox();

		for (int i = 0; i < numofboxes; i++)
		{

			Box box = *(boxes + i);


			g->DrawRectangle(p, box.getfirstX(), box.getfirstY(), -box.getfirstX() + box.getendX(), -box.getfirstY() + box.getendY());

		}
		pbMainImage->Refresh();
	}
	private: System::Void pbMainImage_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {


		selectedbox = getBox(e);

		Box box = *(boxes + selectedbox);

		unsigned int wid = box.getendX() - box.getfirstX();
		unsigned int hei = box.getendY() - box.getfirstY();
		unsigned int fx = box.getfirstX();
		unsigned int fy = box.getfirstY();
		unsigned int ey = box.getendY();
		unsigned int ex = box.getendX();

		Bitmap^ bmp = gcnew Bitmap(wid, hei);

		Bitmap^ tempbmp = (Bitmap^)pbMainImage->Image;

		for (unsigned int x = fx; x < ex; x++)
		{
			for (unsigned int y = fy; y < ey; y++)
			{
				int xx = x - fx;
				int yy = y - fy;
				Color c = tempbmp->GetPixel(x, y);
				bmp->SetPixel(xx, yy, c);
			}
		}

		pgMiniImage->Image = bmp;


	}
	private: System::Void Verify_Click(System::Object^ sender, System::EventArgs^ e) {

		Bitmap^ miniImage = (Bitmap^)pgMiniImage->Image;

		Box box = *(boxes + selectedbox);

		unsigned int wid = box.getendX() - box.getfirstX();
		unsigned int hei = box.getendY() - box.getfirstY();
		unsigned int fx = box.getfirstX();
		unsigned int fy = box.getfirstY();
		unsigned int ey = box.getendY();
		unsigned int ex = box.getendX();


		unsigned char* minibinaryimage = new unsigned char[wid * hei];

		for (unsigned int x = 0; x < wid; x++)
		{
			for (unsigned int y = 0; y < hei; y++)
			{

				Color c = miniImage->GetPixel(x, y);

				if (c.R == 255 || c.G == 255 || c.B == 255)
				{
					minibinaryimage[x + y * wid] = 0;
				}
				else
				{
					minibinaryimage[x + y * wid] = 1;
				}


			}
		}

		HuMoment hm(minibinaryimage, wid, hei);
		double* huMoment = hm.getHuMoments();


		System::Text::StringBuilder^ builder = gcnew System::Text::StringBuilder();
		for (int i = 0; i < 7; i++)
		{
			builder->AppendLine(huMoment[i].ToString());
		}
		auto text = builder->ToString();

		if (objtype->SelectedIndex == 0)
		{
			Int32 number = Int32::Parse(System::IO::File::ReadAllText("cekirdek\\check.txt"));
			System::IO::File::WriteAllText("cekirdek\\check.txt", (number+1).ToString());
			System::IO::File::WriteAllText("cekirdek\\cekirdek"+number+".txt",text);
			
		}
		if (objtype->SelectedIndex == 1)
		{
			Int32 number = Int32::Parse(System::IO::File::ReadAllText("biber\\check.txt"));
			System::IO::File::WriteAllText("biber\\check.txt", (number + 1).ToString());		
			System::IO::File::WriteAllText("biber\\biber" + number + ".txt", text);
		}
		if (objtype->SelectedIndex == 2)
		{
			Int32 number = Int32::Parse(System::IO::File::ReadAllText("mercimek\\check.txt"));
			System::IO::File::WriteAllText("mercimek\\check.txt", (number + 1).ToString());
			System::IO::File::WriteAllText("mercimek\\mercimek" + number + ".txt", text);
		}
	}
	private: System::Void btnGues_Click(System::Object^ sender, System::EventArgs^ e) {

		Bitmap^ miniImage = (Bitmap^)pgMiniImage->Image;

		Box box = *(boxes + selectedbox);

		unsigned int wid = box.getendX() - box.getfirstX();
		unsigned int hei = box.getendY() - box.getfirstY();
		unsigned int fx = box.getfirstX();
		unsigned int fy = box.getfirstY();
		unsigned int ey = box.getendY();
		unsigned int ex = box.getendX();


		unsigned char* minibinaryimage = new unsigned char[wid * hei];

		for (unsigned int x = 0; x < wid; x++)
		{
			for (unsigned int y = 0; y < hei; y++)
			{

				Color c = miniImage->GetPixel(x, y);

				if (c.R == 255 || c.G == 255 || c.B == 255)
				{
					minibinaryimage[x + y * wid] = 0;
				}
				else
				{
					minibinaryimage[x + y * wid] = 1;
				}


			}
		}

		HuMoment hm(minibinaryimage, wid, hei);
		double* huMoment = hm.getHuMoments();


		double** resultMoment = new double* [3];

		for (int i = 0; i < 3; i++)
		{
			resultMoment[i] = new double[7];
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				resultMoment[i][j] = 0;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				Int32 number = Int32::Parse(System::IO::File::ReadAllText("cekirdek\\check.txt"));

				for (int i = 0; i < number; i++)
				{
					String^ filename = "cekirdek\\cekirdek" + i + ".txt";
					auto Lines = System::IO::File::ReadAllLines(filename);

					for (int j = 0; j < 7; j++)
					{
						double momentvalue = Double::Parse(Lines[j]);
						resultMoment[0][j] += momentvalue;
					}

				}

				for (int j = 0; j < 7; j++)
				{
					resultMoment[0][j] = resultMoment[0][j] / (double)(number);
				}


			}
			if (i == 1)
			{
				Int32 number = Int32::Parse(System::IO::File::ReadAllText("biber\\check.txt"));

				for (int i = 0; i < number; i++)
				{
					String^ filename = "biber\\biber" + i + ".txt";
					auto Lines = System::IO::File::ReadAllLines(filename);

					for (int j = 0; j < 7; j++)
					{
						double momentvalue = Double::Parse(Lines[j]);
						resultMoment[1][j] += momentvalue;
					}

				}
				for (int j = 0; j < 7; j++)
				{
					resultMoment[1][j] = resultMoment[1][j] / (double)(number);
				}


			}
			if (i == 2)
			{
				Int32 number = Int32::Parse(System::IO::File::ReadAllText("mercimek\\check.txt"));

				for (int i = 0; i < number; i++)
				{
					String^ filename = "mercimek\\mercimek" + i + ".txt";
					auto Lines = System::IO::File::ReadAllLines(filename);

					for (int j = 0; j < 7; j++)
					{
						double momentvalue = Double::Parse(Lines[j]);
						resultMoment[2][j] += momentvalue;
					}

				}

				for (int j = 0; j < 7; j++)
				{
					resultMoment[2][j] = resultMoment[2][j] / (double)(number);
					
				}


			}


		}

		int cekirdek = 0, biber = 0, mercimek = 0;



		for (int j = 0; j < 7; j++)
		{

			if (getResult(resultMoment[0][j], huMoment[j]))
			{
				cekirdek++;
			}


		}
		for (int j = 0; j < 7; j++)
		{

			if (getResult(resultMoment[1][j], huMoment[j]))
			{
				biber++;
			}


		}
		for (int j = 0; j < 7; j++)
		{

			if (getResult(resultMoment[2][j], huMoment[j]))
			{
				mercimek++;
			}


		}

		lblResult->Visible = true;

		if (cekirdek > biber && cekirdek > mercimek)
		{
			lblResult->Text = "Cekirdek";
		}
		if (biber > cekirdek && biber > mercimek)
		{
			lblResult->Text = "Biber";
		}
		if (mercimek > biber && mercimek > cekirdek)
		{
			lblResult->Text = "Mercimek";
		}

		listBox1->Items->Clear();
		listBox2->Items->Clear();
		listBox3->Items->Clear();
		listBox4->Items->Clear();

		for (int i = 0; i < 7; i++)
		{
			listBox1->Items->Add(huMoment[i]);
			listBox2->Items->Add(resultMoment[0][i]);
			listBox3->Items->Add(resultMoment[1][i]);
			listBox4->Items->Add(resultMoment[2][i]);

		}



	}
};
}

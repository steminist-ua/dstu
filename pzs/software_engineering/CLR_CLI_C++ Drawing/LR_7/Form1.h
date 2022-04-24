#pragma once
#include "Form2.h"
#include "Form3.h"
#include "Form4.h"
namespace LR_7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;






	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(40, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Сказка";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(40, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 37);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Риссунок";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(40, 174);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(111, 37);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Фигуры";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(191, 242);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
			 {
				///////************Рисует линию*************//////////// 
				 /*Graphics^g=CreateGraphics();
				 Pen ^redPen = gcnew Pen(Color::Red); 
				 g->DrawLine(redPen,Point(k+3,0), Point(100+k, 100+k));

				 Graphics^g1=CreateGraphics();
				 Pen ^redPen1 = gcnew Pen(Color::Green); 
				 g1->DrawLine(redPen1,Point(0, k+3), Point(100+k, 100+k));*/



				 /*this->pictureBox1->Location = System::Drawing::Point(29+k, 28+k);
				 this->pictureBox1->Size = System::Drawing::Size(40+k, 47+k);

				 this->pictureBox2->Location = System::Drawing::Point(-8+k-34, 12+k-34);
				 this->pictureBox2->Size = System::Drawing::Size(31+(k-40), 34+(k-40));
				 

				 if (k==170) this->timer1->Enabled = false;*/
			 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //MessageBox::Show( "The style releated to the 'Form' has been changed" );

			 Form2^ form=gcnew Form2();
			 form->Show();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 Form3^ form=gcnew Form3();
			 form->Show();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 Form4^ form=gcnew Form4();
			 form->Show();
		 }
};
}


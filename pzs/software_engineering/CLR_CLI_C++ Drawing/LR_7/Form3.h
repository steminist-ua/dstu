#pragma once

namespace LR_7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form3
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		Form3(void)
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
		~Form3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 25;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form3::timer1_Tick);
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(273, 218);
			this->Name = L"Form3";
			this->Text = L"Рисунок";
			this->ResumeLayout(false);

		}
#pragma endregion
		int k,k1,k2,k3,k4;
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
			 {
				 Graphics^g=CreateGraphics();
				 Pen ^redPen1 = gcnew Pen(Color::Red);	
				 redPen1->Width = 2.0F;

				if ((k>0)&&(k<=50))
				{
					 g->DrawLine(redPen1,20,20,20+k1,20);
					 g->DrawLine(redPen1,80,20,80+k1,20);
					 g->DrawLine(redPen1,140,20,140+k1,20);
					 g->DrawLine(redPen1,200,20,200+k1,20);

					 g->DrawLine(redPen1,20,80,20+k1,80);
					 g->DrawLine(redPen1,80,80,80+k1,80);
					 g->DrawLine(redPen1,140,80,140+k1,80);
					 g->DrawLine(redPen1,200,80,200+k1,80);

					 g->DrawLine(redPen1,20,140,20+k1,140);
					 g->DrawLine(redPen1,80,140,80+k1,140);
					 g->DrawLine(redPen1,140,140,140+k1,140);
					 g->DrawLine(redPen1,200,140,200+k1,140);

					 g->DrawLine(redPen1,50, 50, 50, 50+k1);
					 g->DrawLine(redPen1,110, 50, 110, 50+k1);
					 g->DrawLine(redPen1,50, 110, 50, 110+k1);
					 g->DrawLine(redPen1,110, 110, 110, 110+k1);
					 g->DrawLine(redPen1,170, 50, 170, 50+k1);	
					 g->DrawLine(redPen1,170, 110, 170, 110+k1);

					 k1++;
				} 
				if ((k>50)&&(k<=100))
				{
					 g->DrawLine(redPen1,20,20,20,20+k2);
					 g->DrawLine(redPen1,80,20,80,20+k2);
					 g->DrawLine(redPen1,140,20,140,20+k2);
					 g->DrawLine(redPen1,200,20,200,20+k2);

					 g->DrawLine(redPen1,20,80,20,80+k2);
					 g->DrawLine(redPen1,80,80,80,80+k2);
					 g->DrawLine(redPen1,140,80,140,80+k2);
					 g->DrawLine(redPen1,200,80,200,80+k2);

					 g->DrawLine(redPen1,20,140,20,140+k2);
					 g->DrawLine(redPen1,80,140,80,140+k2);
					 g->DrawLine(redPen1,140,140,140,140+k2);
					 g->DrawLine(redPen1,200,140,200,140+k2);	

					 g->DrawLine(redPen1,50, 50, 50+k2, 50);
					 g->DrawLine(redPen1,110, 50, 110+k2, 50);
					 g->DrawLine(redPen1,50, 110, 50+k2, 110);
					 g->DrawLine(redPen1,110, 110, 110+k2, 110);
					 g->DrawLine(redPen1,170, 50, 170+k2, 50);	
					 g->DrawLine(redPen1,170, 110, 170+k2, 110);
					 
					 k2++;
				}
				if ((k>100)&&(k<=150))
				{
					 g->DrawLine(redPen1,20+k3,70,20,70);
					 g->DrawLine(redPen1,80+k3,70,80,70);
					 g->DrawLine(redPen1,140+k3,70,140,70);
					 g->DrawLine(redPen1,200+k3,70,200,70);

					 g->DrawLine(redPen1,20+k3,130,20,130);
					 g->DrawLine(redPen1,80+k3,130,80,130);
					 g->DrawLine(redPen1,140+k3,130,140,130);
					 g->DrawLine(redPen1,200+k3,130,200,130);

					 g->DrawLine(redPen1,20+k3,190,20,190);
					 g->DrawLine(redPen1,80+k3,190,80,190);
					 g->DrawLine(redPen1,140+k3,190,140,190);
					 g->DrawLine(redPen1,200+k3,190,200,190);

					 g->DrawLine(redPen1,100, 50, 100, 50+k3);
					 g->DrawLine(redPen1,160, 50, 160, 50+k3);
					 g->DrawLine(redPen1,100, 110, 100, 110+k3);
					 g->DrawLine(redPen1,160, 110, 160, 110+k3);
					 g->DrawLine(redPen1,220, 50, 220, 50+k3);	
					 g->DrawLine(redPen1,220, 110, 220, 110+k3);
					 k3++;
				}
				if ((k>150)&&(k<=200))
				{
					 g->DrawLine(redPen1,70,70,70,70-k4);
					 g->DrawLine(redPen1,130,70,130,70-k4);
					 g->DrawLine(redPen1,190,70,190,70-k4);
					 g->DrawLine(redPen1,250,70,250,70-k4);

					 g->DrawLine(redPen1,70,130,70,130-k4);
					 g->DrawLine(redPen1,130,130,130,130-k4);
					 g->DrawLine(redPen1,190,130,190,130-k4);
					 g->DrawLine(redPen1,250,130,250,130-k4);

					 g->DrawLine(redPen1,70,190,70,190-k4);
					 g->DrawLine(redPen1,130,190,130,190-k4);
					 g->DrawLine(redPen1,190,190,190,190-k4);
					 g->DrawLine(redPen1,250,190,250,190-k4);

					 g->DrawLine(redPen1,100, 100, 100-k4, 100);
					 g->DrawLine(redPen1,160, 100, 160-k4, 100);
					 g->DrawLine(redPen1,100, 160, 100-k4, 160);
					 g->DrawLine(redPen1,160, 160, 160-k4, 160);
					 g->DrawLine(redPen1,220, 100, 220-k4, 100);	
					 g->DrawLine(redPen1,220, 160, 220-k4, 160);

					 k4++;
				}
				 k++;	 
			 }
	};
}

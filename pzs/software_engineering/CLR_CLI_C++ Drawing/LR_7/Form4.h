#pragma once
#include "Figure.h"
namespace LR_7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form4
	/// </summary>
	public ref class Form4 : public System::Windows::Forms::Form
	{
	public:
		Form4(void)
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
		~Form4()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButton1;
	private: System::Windows::Forms::ToolStripMenuItem^  прямоугольникиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  кругиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  треугольникиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel3;
	private: System::Windows::Forms::ToolStripComboBox^  toolStripComboBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  квадратToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  прямоугольникToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  равностороннийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  равнобедренныйToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  прямоугольныйToolStripMenuItem;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStrip^  toolStrip2;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel4;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox1;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel5;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel6;



	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel8;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox4;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
	private: System::Windows::Forms::ToolStrip^  toolStrip3;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel7;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel9;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox3;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel10;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox5;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator8;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel11;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox6;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator9;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel12;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox7;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator10;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator11;
	private: System::Windows::Forms::ToolStrip^  toolStrip4;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel13;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel14;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox8;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel15;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox9;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator12;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel16;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox10;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator13;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton5;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator15;
	private: System::Windows::Forms::ToolStrip^  toolStrip5;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel17;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel18;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox11;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel19;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox12;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator14;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel20;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox13;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator16;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton6;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator18;
	private: System::Windows::Forms::ToolStrip^  toolStrip6;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel21;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel22;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox14;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel23;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox15;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator17;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel24;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox16;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator19;



	private: System::Windows::Forms::ToolStripButton^  toolStripButton7;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator21;
	private: System::Windows::Forms::ToolStrip^  toolStrip7;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel26;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel27;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox18;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel28;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox19;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator22;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel29;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox20;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator23;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel30;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox21;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator24;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton8;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator25;

	protected: 

	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form4::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->прямоугольникиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->квадратToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->прямоугольникToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->кругиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->треугольникиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->равностороннийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->равнобедренныйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->прямоугольныйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel2 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel3 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel4 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel5 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripLabel6 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox2 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel8 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox4 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStrip3 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel7 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel9 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox3 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripLabel10 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox5 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel11 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox6 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator9 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel12 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox7 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator10 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator11 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStrip4 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel13 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel14 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox8 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripLabel15 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox9 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator12 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel16 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox10 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator13 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator15 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStrip5 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel17 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel18 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox11 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripLabel19 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox12 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator14 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel20 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox13 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator16 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator18 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStrip6 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel21 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel22 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox14 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripLabel23 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox15 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator17 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel24 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox16 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator19 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator21 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStrip7 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel26 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel27 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox18 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripLabel28 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox19 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator22 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel29 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox20 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator23 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel30 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripTextBox21 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator24 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton8 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator25 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStrip1->SuspendLayout();
			this->toolStrip2->SuspendLayout();
			this->toolStrip3->SuspendLayout();
			this->toolStrip4->SuspendLayout();
			this->toolStrip5->SuspendLayout();
			this->toolStrip6->SuspendLayout();
			this->toolStrip7->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->toolStripLabel1, 
				this->toolStripDropDownButton1, this->toolStripSeparator1, this->toolStripLabel2, this->toolStripButton1, this->toolStripSeparator3, 
				this->toolStripLabel3, this->toolStripComboBox1, this->toolStripSeparator2, this->toolStripButton2, this->toolStripSeparator4});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->toolStrip1->Size = System::Drawing::Size(585, 25);
			this->toolStrip1->TabIndex = 3;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(104, 22);
			this->toolStripLabel1->Text = L"Выберите фигуру";
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->прямоугольникиToolStripMenuItem, 
				this->кругиToolStripMenuItem, this->треугольникиToolStripMenuItem});
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(29, 22);
			this->toolStripDropDownButton1->Text = L"toolStripDropDownButton1";
			// 
			// прямоугольникиToolStripMenuItem
			// 
			this->прямоугольникиToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->квадратToolStripMenuItem, 
				this->прямоугольникToolStripMenuItem});
			this->прямоугольникиToolStripMenuItem->Name = L"прямоугольникиToolStripMenuItem";
			this->прямоугольникиToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->прямоугольникиToolStripMenuItem->Text = L"Прямоугольники";
			// 
			// квадратToolStripMenuItem
			// 
			this->квадратToolStripMenuItem->Name = L"квадратToolStripMenuItem";
			this->квадратToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->квадратToolStripMenuItem->Text = L"Квадрат";
			this->квадратToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form4::квадратToolStripMenuItem_Click);
			// 
			// прямоугольникToolStripMenuItem
			// 
			this->прямоугольникToolStripMenuItem->Name = L"прямоугольникToolStripMenuItem";
			this->прямоугольникToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->прямоугольникToolStripMenuItem->Text = L"Прямоугольник";
			this->прямоугольникToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form4::прямоугольникToolStripMenuItem_Click);
			// 
			// кругиToolStripMenuItem
			// 
			this->кругиToolStripMenuItem->Name = L"кругиToolStripMenuItem";
			this->кругиToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->кругиToolStripMenuItem->Text = L"Круг";
			this->кругиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form4::кругиToolStripMenuItem_Click);
			// 
			// треугольникиToolStripMenuItem
			// 
			this->треугольникиToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->равностороннийToolStripMenuItem, 
				this->равнобедренныйToolStripMenuItem, this->прямоугольныйToolStripMenuItem});
			this->треугольникиToolStripMenuItem->Name = L"треугольникиToolStripMenuItem";
			this->треугольникиToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->треугольникиToolStripMenuItem->Text = L"Треугольники";
			// 
			// равностороннийToolStripMenuItem
			// 
			this->равностороннийToolStripMenuItem->Name = L"равностороннийToolStripMenuItem";
			this->равностороннийToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->равностороннийToolStripMenuItem->Text = L"Равносторонний";
			this->равностороннийToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form4::равностороннийToolStripMenuItem_Click);
			// 
			// равнобедренныйToolStripMenuItem
			// 
			this->равнобедренныйToolStripMenuItem->Name = L"равнобедренныйToolStripMenuItem";
			this->равнобедренныйToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->равнобедренныйToolStripMenuItem->Text = L"Равнобедренный";
			this->равнобедренныйToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form4::равнобедренныйToolStripMenuItem_Click);
			// 
			// прямоугольныйToolStripMenuItem
			// 
			this->прямоугольныйToolStripMenuItem->Name = L"прямоугольныйToolStripMenuItem";
			this->прямоугольныйToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->прямоугольныйToolStripMenuItem->Text = L"Прямоугольный";
			this->прямоугольныйToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form4::прямоугольныйToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripLabel2
			// 
			this->toolStripLabel2->Name = L"toolStripLabel2";
			this->toolStripLabel2->Size = System::Drawing::Size(62, 22);
			this->toolStripLabel2->Text = L"Цвет пера";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form4::toolStripButton1_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripLabel3
			// 
			this->toolStripLabel3->Name = L"toolStripLabel3";
			this->toolStripLabel3->Size = System::Drawing::Size(88, 22);
			this->toolStripLabel3->Text = L"Толщина пера";
			// 
			// toolStripComboBox1
			// 
			this->toolStripComboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"1", L"3", L"5", L"8"});
			this->toolStripComboBox1->Name = L"toolStripComboBox1";
			this->toolStripComboBox1->Size = System::Drawing::Size(121, 25);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(79, 22);
			this->toolStripButton2->Text = L"Очистить";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form4::toolStripButton2_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(6, 25);
			// 
			// toolStrip2
			// 
			this->toolStrip2->Dock = System::Windows::Forms::DockStyle::Right;
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->toolStripLabel4, 
				this->toolStripLabel5, this->toolStripTextBox1, this->toolStripLabel6, this->toolStripTextBox2, this->toolStripSeparator5, this->toolStripLabel8, 
				this->toolStripTextBox4, this->toolStripSeparator6, this->toolStripButton3, this->toolStripSeparator7});
			this->toolStrip2->Location = System::Drawing::Point(492, 25);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->toolStrip2->Size = System::Drawing::Size(93, 332);
			this->toolStrip2->TabIndex = 4;
			this->toolStrip2->Text = L"toolStrip2";
			this->toolStrip2->Visible = false;
			// 
			// toolStripLabel4
			// 
			this->toolStripLabel4->Name = L"toolStripLabel4";
			this->toolStripLabel4->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel4->Text = L"Координаты: ";
			// 
			// toolStripLabel5
			// 
			this->toolStripLabel5->Name = L"toolStripLabel5";
			this->toolStripLabel5->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel5->Text = L"х";
			// 
			// toolStripTextBox1
			// 
			this->toolStripTextBox1->Name = L"toolStripTextBox1";
			this->toolStripTextBox1->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripLabel6
			// 
			this->toolStripLabel6->Name = L"toolStripLabel6";
			this->toolStripLabel6->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel6->Text = L"у";
			// 
			// toolStripTextBox2
			// 
			this->toolStripTextBox2->Name = L"toolStripTextBox2";
			this->toolStripTextBox2->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripLabel8
			// 
			this->toolStripLabel8->Name = L"toolStripLabel8";
			this->toolStripLabel8->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel8->Text = L"Ширина";
			// 
			// toolStripTextBox4
			// 
			this->toolStripTextBox4->Name = L"toolStripTextBox4";
			this->toolStripTextBox4->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(90, 20);
			this->toolStripButton3->Text = L"Нарисовать";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form4::toolStripButton3_Click);
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(90, 6);
			// 
			// toolStrip3
			// 
			this->toolStrip3->Dock = System::Windows::Forms::DockStyle::Right;
			this->toolStrip3->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(14) {this->toolStripLabel7, 
				this->toolStripLabel9, this->toolStripTextBox3, this->toolStripLabel10, this->toolStripTextBox5, this->toolStripSeparator8, this->toolStripLabel11, 
				this->toolStripTextBox6, this->toolStripSeparator9, this->toolStripLabel12, this->toolStripTextBox7, this->toolStripSeparator10, 
				this->toolStripButton4, this->toolStripSeparator11});
			this->toolStrip3->Location = System::Drawing::Point(492, 25);
			this->toolStrip3->Name = L"toolStrip3";
			this->toolStrip3->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->toolStrip3->Size = System::Drawing::Size(93, 332);
			this->toolStrip3->TabIndex = 5;
			this->toolStrip3->Text = L"toolStrip3";
			this->toolStrip3->Visible = false;
			// 
			// toolStripLabel7
			// 
			this->toolStripLabel7->Name = L"toolStripLabel7";
			this->toolStripLabel7->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel7->Text = L"Координаты: ";
			// 
			// toolStripLabel9
			// 
			this->toolStripLabel9->Name = L"toolStripLabel9";
			this->toolStripLabel9->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel9->Text = L"х";
			// 
			// toolStripTextBox3
			// 
			this->toolStripTextBox3->Name = L"toolStripTextBox3";
			this->toolStripTextBox3->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripLabel10
			// 
			this->toolStripLabel10->Name = L"toolStripLabel10";
			this->toolStripLabel10->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel10->Text = L"у";
			// 
			// toolStripTextBox5
			// 
			this->toolStripTextBox5->Name = L"toolStripTextBox5";
			this->toolStripTextBox5->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator8
			// 
			this->toolStripSeparator8->Name = L"toolStripSeparator8";
			this->toolStripSeparator8->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripLabel11
			// 
			this->toolStripLabel11->Name = L"toolStripLabel11";
			this->toolStripLabel11->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel11->Text = L"Длина ";
			// 
			// toolStripTextBox6
			// 
			this->toolStripTextBox6->Name = L"toolStripTextBox6";
			this->toolStripTextBox6->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator9
			// 
			this->toolStripSeparator9->Name = L"toolStripSeparator9";
			this->toolStripSeparator9->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripLabel12
			// 
			this->toolStripLabel12->Name = L"toolStripLabel12";
			this->toolStripLabel12->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel12->Text = L"Ширина";
			// 
			// toolStripTextBox7
			// 
			this->toolStripTextBox7->Name = L"toolStripTextBox7";
			this->toolStripTextBox7->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator10
			// 
			this->toolStripSeparator10->Name = L"toolStripSeparator10";
			this->toolStripSeparator10->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(90, 20);
			this->toolStripButton4->Text = L"Нарисовать";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Form4::toolStripButton4_Click);
			// 
			// toolStripSeparator11
			// 
			this->toolStripSeparator11->Name = L"toolStripSeparator11";
			this->toolStripSeparator11->Size = System::Drawing::Size(90, 6);
			// 
			// toolStrip4
			// 
			this->toolStrip4->Dock = System::Windows::Forms::DockStyle::Right;
			this->toolStrip4->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->toolStripLabel13, 
				this->toolStripLabel14, this->toolStripTextBox8, this->toolStripLabel15, this->toolStripTextBox9, this->toolStripSeparator12, 
				this->toolStripLabel16, this->toolStripTextBox10, this->toolStripSeparator13, this->toolStripButton5, this->toolStripSeparator15});
			this->toolStrip4->Location = System::Drawing::Point(492, 25);
			this->toolStrip4->Name = L"toolStrip4";
			this->toolStrip4->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->toolStrip4->Size = System::Drawing::Size(93, 332);
			this->toolStrip4->TabIndex = 6;
			this->toolStrip4->Text = L"toolStrip4";
			this->toolStrip4->Visible = false;
			// 
			// toolStripLabel13
			// 
			this->toolStripLabel13->Name = L"toolStripLabel13";
			this->toolStripLabel13->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel13->Text = L"Координаты: ";
			// 
			// toolStripLabel14
			// 
			this->toolStripLabel14->Name = L"toolStripLabel14";
			this->toolStripLabel14->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel14->Text = L"х";
			// 
			// toolStripTextBox8
			// 
			this->toolStripTextBox8->Name = L"toolStripTextBox8";
			this->toolStripTextBox8->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripLabel15
			// 
			this->toolStripLabel15->Name = L"toolStripLabel15";
			this->toolStripLabel15->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel15->Text = L"у";
			// 
			// toolStripTextBox9
			// 
			this->toolStripTextBox9->Name = L"toolStripTextBox9";
			this->toolStripTextBox9->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator12
			// 
			this->toolStripSeparator12->Name = L"toolStripSeparator12";
			this->toolStripSeparator12->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripLabel16
			// 
			this->toolStripLabel16->Name = L"toolStripLabel16";
			this->toolStripLabel16->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel16->Text = L"Радиус";
			// 
			// toolStripTextBox10
			// 
			this->toolStripTextBox10->Name = L"toolStripTextBox10";
			this->toolStripTextBox10->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox10->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator13
			// 
			this->toolStripSeparator13->Name = L"toolStripSeparator13";
			this->toolStripSeparator13->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(90, 20);
			this->toolStripButton5->Text = L"Нарисовать";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &Form4::toolStripButton5_Click);
			// 
			// toolStripSeparator15
			// 
			this->toolStripSeparator15->Name = L"toolStripSeparator15";
			this->toolStripSeparator15->Size = System::Drawing::Size(90, 6);
			// 
			// toolStrip5
			// 
			this->toolStrip5->Dock = System::Windows::Forms::DockStyle::Right;
			this->toolStrip5->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->toolStripLabel17, 
				this->toolStripLabel18, this->toolStripTextBox11, this->toolStripLabel19, this->toolStripTextBox12, this->toolStripSeparator14, 
				this->toolStripLabel20, this->toolStripTextBox13, this->toolStripSeparator16, this->toolStripButton6, this->toolStripSeparator18});
			this->toolStrip5->Location = System::Drawing::Point(492, 25);
			this->toolStrip5->Name = L"toolStrip5";
			this->toolStrip5->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->toolStrip5->Size = System::Drawing::Size(93, 332);
			this->toolStrip5->TabIndex = 7;
			this->toolStrip5->Text = L"toolStrip5";
			this->toolStrip5->Visible = false;
			// 
			// toolStripLabel17
			// 
			this->toolStripLabel17->Name = L"toolStripLabel17";
			this->toolStripLabel17->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel17->Text = L"Координаты: ";
			// 
			// toolStripLabel18
			// 
			this->toolStripLabel18->Name = L"toolStripLabel18";
			this->toolStripLabel18->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel18->Text = L"х";
			// 
			// toolStripTextBox11
			// 
			this->toolStripTextBox11->Name = L"toolStripTextBox11";
			this->toolStripTextBox11->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripLabel19
			// 
			this->toolStripLabel19->Name = L"toolStripLabel19";
			this->toolStripLabel19->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel19->Text = L"у";
			// 
			// toolStripTextBox12
			// 
			this->toolStripTextBox12->Name = L"toolStripTextBox12";
			this->toolStripTextBox12->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox12->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator14
			// 
			this->toolStripSeparator14->Name = L"toolStripSeparator14";
			this->toolStripSeparator14->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripLabel20
			// 
			this->toolStripLabel20->Name = L"toolStripLabel20";
			this->toolStripLabel20->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel20->Text = L"Длина ";
			// 
			// toolStripTextBox13
			// 
			this->toolStripTextBox13->Name = L"toolStripTextBox13";
			this->toolStripTextBox13->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox13->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator16
			// 
			this->toolStripSeparator16->Name = L"toolStripSeparator16";
			this->toolStripSeparator16->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(90, 20);
			this->toolStripButton6->Text = L"Нарисовать";
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &Form4::toolStripButton6_Click);
			// 
			// toolStripSeparator18
			// 
			this->toolStripSeparator18->Name = L"toolStripSeparator18";
			this->toolStripSeparator18->Size = System::Drawing::Size(90, 6);
			// 
			// toolStrip6
			// 
			this->toolStrip6->Dock = System::Windows::Forms::DockStyle::Right;
			this->toolStrip6->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->toolStripLabel21, 
				this->toolStripLabel22, this->toolStripTextBox14, this->toolStripLabel23, this->toolStripTextBox15, this->toolStripSeparator17, 
				this->toolStripLabel24, this->toolStripTextBox16, this->toolStripSeparator19, this->toolStripButton7, this->toolStripSeparator21});
			this->toolStrip6->Location = System::Drawing::Point(399, 25);
			this->toolStrip6->Name = L"toolStrip6";
			this->toolStrip6->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->toolStrip6->Size = System::Drawing::Size(93, 332);
			this->toolStrip6->TabIndex = 8;
			this->toolStrip6->Text = L"toolStrip6";
			this->toolStrip6->Visible = false;
			// 
			// toolStripLabel21
			// 
			this->toolStripLabel21->Name = L"toolStripLabel21";
			this->toolStripLabel21->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel21->Text = L"Координаты: ";
			// 
			// toolStripLabel22
			// 
			this->toolStripLabel22->Name = L"toolStripLabel22";
			this->toolStripLabel22->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel22->Text = L"х";
			// 
			// toolStripTextBox14
			// 
			this->toolStripTextBox14->Name = L"toolStripTextBox14";
			this->toolStripTextBox14->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox14->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripLabel23
			// 
			this->toolStripLabel23->Name = L"toolStripLabel23";
			this->toolStripLabel23->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel23->Text = L"у";
			// 
			// toolStripTextBox15
			// 
			this->toolStripTextBox15->Name = L"toolStripTextBox15";
			this->toolStripTextBox15->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox15->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator17
			// 
			this->toolStripSeparator17->Name = L"toolStripSeparator17";
			this->toolStripSeparator17->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripLabel24
			// 
			this->toolStripLabel24->Name = L"toolStripLabel24";
			this->toolStripLabel24->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel24->Text = L"Длина ";
			// 
			// toolStripTextBox16
			// 
			this->toolStripTextBox16->Name = L"toolStripTextBox16";
			this->toolStripTextBox16->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox16->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator19
			// 
			this->toolStripSeparator19->Name = L"toolStripSeparator19";
			this->toolStripSeparator19->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton7.Image")));
			this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->Size = System::Drawing::Size(90, 20);
			this->toolStripButton7->Text = L"Нарисовать";
			this->toolStripButton7->Click += gcnew System::EventHandler(this, &Form4::toolStripButton7_Click);
			// 
			// toolStripSeparator21
			// 
			this->toolStripSeparator21->Name = L"toolStripSeparator21";
			this->toolStripSeparator21->Size = System::Drawing::Size(90, 6);
			// 
			// toolStrip7
			// 
			this->toolStrip7->Dock = System::Windows::Forms::DockStyle::Right;
			this->toolStrip7->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(14) {this->toolStripLabel26, 
				this->toolStripLabel27, this->toolStripTextBox18, this->toolStripLabel28, this->toolStripTextBox19, this->toolStripSeparator22, 
				this->toolStripLabel29, this->toolStripTextBox20, this->toolStripSeparator23, this->toolStripLabel30, this->toolStripTextBox21, 
				this->toolStripSeparator24, this->toolStripButton8, this->toolStripSeparator25});
			this->toolStrip7->Location = System::Drawing::Point(492, 25);
			this->toolStrip7->Name = L"toolStrip7";
			this->toolStrip7->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->toolStrip7->Size = System::Drawing::Size(93, 332);
			this->toolStrip7->TabIndex = 9;
			this->toolStrip7->Text = L"toolStrip7";
			this->toolStrip7->Visible = false;
			// 
			// toolStripLabel26
			// 
			this->toolStripLabel26->Name = L"toolStripLabel26";
			this->toolStripLabel26->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel26->Text = L"Координаты: ";
			// 
			// toolStripLabel27
			// 
			this->toolStripLabel27->Name = L"toolStripLabel27";
			this->toolStripLabel27->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel27->Text = L"х";
			// 
			// toolStripTextBox18
			// 
			this->toolStripTextBox18->Name = L"toolStripTextBox18";
			this->toolStripTextBox18->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox18->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripLabel28
			// 
			this->toolStripLabel28->Name = L"toolStripLabel28";
			this->toolStripLabel28->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel28->Text = L"у";
			// 
			// toolStripTextBox19
			// 
			this->toolStripTextBox19->Name = L"toolStripTextBox19";
			this->toolStripTextBox19->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox19->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator22
			// 
			this->toolStripSeparator22->Name = L"toolStripSeparator22";
			this->toolStripSeparator22->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripLabel29
			// 
			this->toolStripLabel29->Name = L"toolStripLabel29";
			this->toolStripLabel29->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel29->Text = L"Длина ";
			// 
			// toolStripTextBox20
			// 
			this->toolStripTextBox20->Name = L"toolStripTextBox20";
			this->toolStripTextBox20->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox20->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator23
			// 
			this->toolStripSeparator23->Name = L"toolStripSeparator23";
			this->toolStripSeparator23->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripLabel30
			// 
			this->toolStripLabel30->Name = L"toolStripLabel30";
			this->toolStripLabel30->Size = System::Drawing::Size(90, 15);
			this->toolStripLabel30->Text = L"Ширина";
			// 
			// toolStripTextBox21
			// 
			this->toolStripTextBox21->Name = L"toolStripTextBox21";
			this->toolStripTextBox21->Size = System::Drawing::Size(88, 23);
			this->toolStripTextBox21->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form4::toolStripTextBox1_KeyPress);
			// 
			// toolStripSeparator24
			// 
			this->toolStripSeparator24->Name = L"toolStripSeparator24";
			this->toolStripSeparator24->Size = System::Drawing::Size(90, 6);
			// 
			// toolStripButton8
			// 
			this->toolStripButton8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton8.Image")));
			this->toolStripButton8->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton8->Name = L"toolStripButton8";
			this->toolStripButton8->Size = System::Drawing::Size(90, 20);
			this->toolStripButton8->Text = L"Нарисовать";
			this->toolStripButton8->Click += gcnew System::EventHandler(this, &Form4::toolStripButton8_Click);
			// 
			// toolStripSeparator25
			// 
			this->toolStripSeparator25->Name = L"toolStripSeparator25";
			this->toolStripSeparator25->Size = System::Drawing::Size(90, 6);
			// 
			// Form4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(585, 357);
			this->Controls->Add(this->toolStrip2);
			this->Controls->Add(this->toolStrip3);
			this->Controls->Add(this->toolStrip4);
			this->Controls->Add(this->toolStrip5);
			this->Controls->Add(this->toolStrip6);
			this->Controls->Add(this->toolStrip7);
			this->Controls->Add(this->toolStrip1);
			this->Name = L"Form4";
			this->Text = L" ";
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			this->toolStrip3->ResumeLayout(false);
			this->toolStrip3->PerformLayout();
			this->toolStrip4->ResumeLayout(false);
			this->toolStrip4->PerformLayout();
			this->toolStrip5->ResumeLayout(false);
			this->toolStrip5->PerformLayout();
			this->toolStrip6->ResumeLayout(false);
			this->toolStrip6->PerformLayout();
			this->toolStrip7->ResumeLayout(false);
			this->toolStrip7->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 colorDialog1->ShowDialog();
		 }
private: System::Void квадратToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->toolStrip2->Visible = true;
			 this->toolStrip3->Visible = false;
			 this->toolStrip4->Visible = false;
			 this->toolStrip5->Visible = false;
			 this->toolStrip6->Visible = false;
			 this->toolStrip7->Visible = false;
		 }
private: System::Void прямоугольникToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->toolStrip2->Visible = false;
			 this->toolStrip3->Visible = true;
			 this->toolStrip4->Visible = false;
			 this->toolStrip5->Visible = false;
			 this->toolStrip6->Visible = false;
			 this->toolStrip7->Visible = false;
		 }
private: System::Void кругиToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->toolStrip2->Visible = false;
			 this->toolStrip3->Visible = false;
			 this->toolStrip4->Visible = true;
			 this->toolStrip5->Visible = false;
			 this->toolStrip6->Visible = false;
			 this->toolStrip7->Visible = false;
		 }
private: System::Void равностороннийToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->toolStrip2->Visible = false;
			 this->toolStrip3->Visible = false;
			 this->toolStrip4->Visible = false;
			 this->toolStrip5->Visible = true;
			 this->toolStrip6->Visible = false;
			 this->toolStrip7->Visible = false;
		 }
private: System::Void равнобедренныйToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->toolStrip2->Visible = false;
			 this->toolStrip3->Visible = false;
			 this->toolStrip4->Visible = false;
			 this->toolStrip5->Visible = false;
			 this->toolStrip6->Visible = true;
			 this->toolStrip7->Visible = false;
		 }
private: System::Void прямоугольныйToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->toolStrip2->Visible = false;
			 this->toolStrip3->Visible = false;
			 this->toolStrip4->Visible = false;
			 this->toolStrip5->Visible = false;
			 this->toolStrip6->Visible = false;
			 this->toolStrip7->Visible = true;
		 }
private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //квадрат
			 Square mySquare; 
			 Pen^ myPen;
			 if (toolStripComboBox1->Text!="")
			 {
				 myPen = gcnew Pen( colorDialog1->Color,Convert::ToInt32(toolStripComboBox1->Text));
			 }
			 else 
			 {
				 myPen = gcnew Pen(Color::Black,1);
			 }
			 mySquare.SetLength(Convert::ToInt32(toolStripTextBox4->Text));
			 Graphics^g=CreateGraphics();
			 Color^ h = gcnew Color();
			 g -> Clear(h->Azure);
			 g->DrawRectangle( myPen, Convert::ToInt32(toolStripTextBox1->Text), Convert::ToInt32(toolStripTextBox2->Text), mySquare.GetLength(), mySquare.GetLength() );
			 
		 }
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //ОЧИСТИТЬ
			 Graphics^g=CreateGraphics();
			 Color^ h = gcnew Color();
			 g -> Clear(h->Azure);
			 this->toolStrip2->Visible = false;
			 this->toolStrip3->Visible = false;
			 this->toolStrip4->Visible = false;
			 this->toolStrip5->Visible = false;
			 this->toolStrip6->Visible = false;
			 this->toolStrip7->Visible = false;
			 toolStripComboBox1->Text="";
			 colorDialog1->Color=Color::Black;
		 }
private: System::Void toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //прямоугольник
			 RectangleClass myRectangle; 
			 Pen^ myPen;
			 if (toolStripComboBox1->Text!="")
			 {
				 myPen = gcnew Pen( colorDialog1->Color,Convert::ToInt32(toolStripComboBox1->Text));
			 }
			 else 
			 {
				 myPen = gcnew Pen(Color::Black,1);
			 }
			 myRectangle.SetLength(Convert::ToInt32(toolStripTextBox7->Text));
			 myRectangle.SetWidth(Convert::ToInt32(toolStripTextBox6->Text));
			 Graphics^g=CreateGraphics();
			 Color^ h = gcnew Color();
			 g -> Clear(h->Azure);
			 g->DrawRectangle( myPen, Convert::ToInt32(toolStripTextBox3->Text), Convert::ToInt32(toolStripTextBox5->Text), myRectangle.GetWidth(), myRectangle.GetLength() );
			 
		 }
private: System::Void toolStripButton5_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //КРУГ
			 Circle myCircle; 
			 Pen^ myPen;
			 if (toolStripComboBox1->Text!="")
			 {
				 myPen = gcnew Pen( colorDialog1->Color,Convert::ToInt32(toolStripComboBox1->Text));
			 }
			 else 
			 {
				 myPen = gcnew Pen(Color::Black,1);
			 }
			 myCircle.SetRadius(Convert::ToInt32(toolStripTextBox10->Text));
			 Graphics^g=CreateGraphics();
			 Color^ h = gcnew Color();
			 g -> Clear(h->Azure);
			 g->DrawEllipse( myPen, Convert::ToInt32(toolStripTextBox8->Text), Convert::ToInt32(toolStripTextBox9->Text), 2*myCircle.GetRadius(), 2*myCircle.GetRadius() );

		 }
private: System::Void toolStripButton6_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //РАВНОСТОРОННИЙ
			 Equilateral myEquilateral;
			 Pen^ myPen;
			 if (toolStripComboBox1->Text!="")
			 {
				 myPen = gcnew Pen( colorDialog1->Color,Convert::ToInt32(toolStripComboBox1->Text));
			 }
			 else 
			 {
				 myPen = gcnew Pen(Color::Black,1);
			 }
			 myEquilateral.SetLength(Convert::ToInt32(toolStripTextBox13->Text));
			 Graphics^g=CreateGraphics();
			 Color^ h = gcnew Color();
			 g -> Clear(h->Azure);

			 int k;
			 k = ((Convert::ToInt32(toolStripTextBox12->Text)+myEquilateral.GetLength()) - Convert::ToInt32(toolStripTextBox12->Text)) * 1,7;
			 g -> DrawLine ( myPen, Convert::ToInt32(toolStripTextBox11->Text), Convert::ToInt32(toolStripTextBox12->Text), Convert::ToInt32(toolStripTextBox11->Text) + k, Convert::ToInt32(toolStripTextBox12->Text)+myEquilateral.GetLength() );
			 g -> DrawLine ( myPen, Convert::ToInt32(toolStripTextBox11->Text), Convert::ToInt32(toolStripTextBox12->Text), Convert::ToInt32(toolStripTextBox11->Text) - k, Convert::ToInt32(toolStripTextBox12->Text)+myEquilateral.GetLength() );
			 g -> DrawLine ( myPen, Convert::ToInt32(toolStripTextBox11->Text)-k, Convert::ToInt32(toolStripTextBox12->Text)+myEquilateral.GetLength(), Convert::ToInt32(toolStripTextBox11->Text)+k, Convert::ToInt32(toolStripTextBox12->Text)+myEquilateral.GetLength() );
		 }
private: System::Void toolStripButton7_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //равнобедренный
			 Isosceles myIsosceles;
			 Pen^ myPen;
			 if (toolStripComboBox1->Text!="")
			 {
				 myPen = gcnew Pen( colorDialog1->Color,Convert::ToInt32(toolStripComboBox1->Text));
			 }
			 else 
			 {
				 myPen = gcnew Pen(Color::Black,1);
			 }
			 myIsosceles.SetLength(Convert::ToInt32(toolStripTextBox16->Text));
			 Graphics^g=CreateGraphics();
			 Color^ h = gcnew Color();
			 g -> Clear(h->Azure);

			 int k;
		k = ((Convert::ToInt32(toolStripTextBox14->Text)+myIsosceles.GetLength()) - Convert::ToInt32(toolStripTextBox14->Text) ) / 2;		
		g -> DrawLine ( myPen, Convert::ToInt32(toolStripTextBox14->Text), Convert::ToInt32(toolStripTextBox15->Text)+myIsosceles.GetLength(), Convert::ToInt32(toolStripTextBox14->Text)+myIsosceles.GetLength(), Convert::ToInt32(toolStripTextBox15->Text)+myIsosceles.GetLength() );
		g -> DrawLine ( myPen, Convert::ToInt32(toolStripTextBox14->Text), Convert::ToInt32(toolStripTextBox15->Text)+myIsosceles.GetLength(), Convert::ToInt32(toolStripTextBox14->Text) + k, Convert::ToInt32(toolStripTextBox15->Text) );
		g -> DrawLine ( myPen, Convert::ToInt32(toolStripTextBox14->Text) + k, Convert::ToInt32(toolStripTextBox15->Text), Convert::ToInt32(toolStripTextBox14->Text)+myIsosceles.GetLength(), Convert::ToInt32(toolStripTextBox15->Text)+myIsosceles.GetLength() );
		 }
private: System::Void toolStripButton8_Click(System::Object^  sender, System::EventArgs^  e)
		 {			 
			 Rectangular myRectangular; 
			 myRectangular.SetLength(Convert::ToInt32(toolStripTextBox20->Text));
			 myRectangular.SetWidth(Convert::ToInt32(toolStripTextBox21->Text)); 

			 int x=Convert::ToInt32(toolStripTextBox18->Text);
			 int y=Convert::ToInt32(toolStripTextBox19->Text);
			 int xx=x+myRectangular.GetLength();
			 int yy=y+myRectangular.GetWidth();
			 Pen^ myPen;
			 if (toolStripComboBox1->Text!="")
			 {
				 myPen = gcnew Pen( colorDialog1->Color,Convert::ToInt32(toolStripComboBox1->Text));
			 }
			 else 
			 {
				 myPen = gcnew Pen(Color::Black,1);
			 }
			 Graphics^g=CreateGraphics();
			 Color^ h = gcnew Color();
			 g -> Clear(h->Azure);
			 if ( xx > x )
					{
						if ( yy < y )
						{
							g -> DrawLine ( myPen, x, yy, x, y );
							g -> DrawLine ( myPen, x, yy, xx, y );
							g -> DrawLine ( myPen, x,y, xx, y );
						}
						else
						{

						 g -> DrawLine ( myPen, x, y, x, yy );
						 g -> DrawLine ( myPen, x, yy, xx, yy );
						 g -> DrawLine ( myPen, x,y, xx, yy );
						 }
					}
					else
					{
						if ( xx < x )
						{
							if ( yy < y )
							{
								g -> DrawLine ( myPen, xx, yy, xx, y );
								g -> DrawLine ( myPen,  x, y,xx, yy );
								g -> DrawLine ( myPen, x,y, xx, y );
							}
							else
							{
								g -> DrawLine ( myPen, xx, y, xx, yy );
								g -> DrawLine ( myPen, xx, yy, x, yy );
								g -> DrawLine ( myPen, xx, y, x, yy );
							}
						}
					}
		 }
private: System::Void toolStripTextBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (e->KeyChar>60)
				 e -> Handled = true;
		 }
};
}

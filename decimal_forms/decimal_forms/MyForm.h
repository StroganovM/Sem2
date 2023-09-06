#pragma once
#include <msclr/marshal_cppstd.h> 
#include"decimal.h"
namespace decimalforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxA;
	private: System::Windows::Forms::TextBox^ textBoxB;

	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonDif;
	private: System::Windows::Forms::Label^ label3;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonDif = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ввод a:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(11, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Ввод b:";
			// 
			// textBoxA
			// 
			this->textBoxA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxA->Location = System::Drawing::Point(103, 23);
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(100, 29);
			this->textBoxA->TabIndex = 2;
			// 
			// textBoxB
			// 
			this->textBoxB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxB->Location = System::Drawing::Point(103, 52);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(100, 29);
			this->textBoxB->TabIndex = 3;
			this->textBoxB->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// buttonAdd
			// 
			this->buttonAdd->BackColor = System::Drawing::Color::Transparent;
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAdd->Location = System::Drawing::Point(103, 87);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(110, 34);
			this->buttonAdd->TabIndex = 4;
			this->buttonAdd->Text = L"Сумма";
			this->buttonAdd->UseVisualStyleBackColor = false;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Click);
			// 
			// buttonDif
			// 
			this->buttonDif->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDif->Location = System::Drawing::Point(103, 127);
			this->buttonDif->Name = L"buttonDif";
			this->buttonDif->Size = System::Drawing::Size(110, 34);
			this->buttonDif->TabIndex = 5;
			this->buttonDif->Text = L"Разность";
			this->buttonDif->UseVisualStyleBackColor = true;
			this->buttonDif->Click += gcnew System::EventHandler(this, &MyForm::buttonDif_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(16, 177);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 24);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Ответ:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(265, 223);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->buttonDif);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->textBoxB);
			this->Controls->Add(this->textBoxA);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Calc";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBoxA->Text == "" || textBoxB->Text == "")
		MessageBox::Show(this, "Заполнены не все переменные", "Сообщение",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
	else {
		String^ var_a = textBoxA->Text;
		std::string s_a = msclr::interop::marshal_as<std::string>(var_a);
		String^ var_b = textBoxB->Text;
		std::string s_b = msclr::interop::marshal_as<std::string>(var_b);
		decimal a(s_a);
		decimal b(s_b);
		decimal res = a + b;
		System::String^ sys_res = msclr::interop::marshal_as<System::String^>(res.get_num());
		label3->Text = "Ответ:" + sys_res;
	}
}
private: System::Void buttonDif_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBoxA->Text == "" || textBoxB->Text == "")
		MessageBox::Show(this, "Заполнены не все переменные", "Сообщение",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
	else {
		String^ var_a = textBoxA->Text;
		std::string s_a = msclr::interop::marshal_as<std::string>(var_a);
		String^ var_b = textBoxB->Text;
		std::string s_b = msclr::interop::marshal_as<std::string>(var_b);
		decimal a(s_a);
		decimal b(s_b);
		decimal res = a - b;
		System::String^ sys_res = msclr::interop::marshal_as<System::String^>(res.get_num());
		label3->Text = "Ответ:" + sys_res;
		
	}
}
};
}

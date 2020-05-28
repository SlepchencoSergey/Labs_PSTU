#pragma once

namespace Calculator {

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
	private:
		double first;
		String^ operation = "";
		bool executeOperation = false;

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
	private: System::Windows::Forms::Button^ btnNum1;
	private: System::Windows::Forms::Button^ btnNum2;
	private: System::Windows::Forms::Button^ btnNum3;
	private: System::Windows::Forms::Button^ btnNum6;
	protected:

	protected:



	private: System::Windows::Forms::Button^ btnNum5;

	private: System::Windows::Forms::Button^ btnNum4;
	private: System::Windows::Forms::Button^ btnNum9;


	private: System::Windows::Forms::Button^ btnNum8;

	private: System::Windows::Forms::Button^ btnNum7;
	private: System::Windows::Forms::Button^ btnNum0;
	private: System::Windows::Forms::TextBox^ txtBxMain;




	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ btnEqual;
	private: System::Windows::Forms::Button^ btnDot;


	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ btnRemoveChar;

	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnSqrt;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnNum1 = (gcnew System::Windows::Forms::Button());
			this->btnNum2 = (gcnew System::Windows::Forms::Button());
			this->btnNum3 = (gcnew System::Windows::Forms::Button());
			this->btnNum6 = (gcnew System::Windows::Forms::Button());
			this->btnNum5 = (gcnew System::Windows::Forms::Button());
			this->btnNum4 = (gcnew System::Windows::Forms::Button());
			this->btnNum9 = (gcnew System::Windows::Forms::Button());
			this->btnNum8 = (gcnew System::Windows::Forms::Button());
			this->btnNum7 = (gcnew System::Windows::Forms::Button());
			this->btnNum0 = (gcnew System::Windows::Forms::Button());
			this->txtBxMain = (gcnew System::Windows::Forms::TextBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->btnEqual = (gcnew System::Windows::Forms::Button());
			this->btnDot = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->btnRemoveChar = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnSqrt = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnNum1
			// 
			this->btnNum1->Location = System::Drawing::Point(41, 302);
			this->btnNum1->Margin = System::Windows::Forms::Padding(4);
			this->btnNum1->Name = L"btnNum1";
			this->btnNum1->Size = System::Drawing::Size(59, 56);
			this->btnNum1->TabIndex = 0;
			this->btnNum1->Text = L"1";
			this->btnNum1->UseVisualStyleBackColor = true;
			this->btnNum1->Click += gcnew System::EventHandler(this, &MyForm::btnNum1_Click);
			// 
			// btnNum2
			// 
			this->btnNum2->Location = System::Drawing::Point(108, 302);
			this->btnNum2->Margin = System::Windows::Forms::Padding(4);
			this->btnNum2->Name = L"btnNum2";
			this->btnNum2->Size = System::Drawing::Size(59, 56);
			this->btnNum2->TabIndex = 1;
			this->btnNum2->Text = L"2";
			this->btnNum2->UseVisualStyleBackColor = true;
			this->btnNum2->Click += gcnew System::EventHandler(this, &MyForm::btnNum1_Click);
			// 
			// btnNum3
			// 
			this->btnNum3->Location = System::Drawing::Point(175, 302);
			this->btnNum3->Margin = System::Windows::Forms::Padding(4);
			this->btnNum3->Name = L"btnNum3";
			this->btnNum3->Size = System::Drawing::Size(59, 56);
			this->btnNum3->TabIndex = 2;
			this->btnNum3->Text = L"3";
			this->btnNum3->UseVisualStyleBackColor = true;
			this->btnNum3->Click += gcnew System::EventHandler(this, &MyForm::btnNum1_Click);
			// 
			// btnNum6
			// 
			this->btnNum6->Location = System::Drawing::Point(175, 238);
			this->btnNum6->Margin = System::Windows::Forms::Padding(4);
			this->btnNum6->Name = L"btnNum6";
			this->btnNum6->Size = System::Drawing::Size(59, 56);
			this->btnNum6->TabIndex = 5;
			this->btnNum6->Text = L"6";
			this->btnNum6->UseVisualStyleBackColor = true;
			this->btnNum6->Click += gcnew System::EventHandler(this, &MyForm::btnNum1_Click);
			// 
			// btnNum5
			// 
			this->btnNum5->Location = System::Drawing::Point(108, 238);
			this->btnNum5->Margin = System::Windows::Forms::Padding(4);
			this->btnNum5->Name = L"btnNum5";
			this->btnNum5->Size = System::Drawing::Size(59, 56);
			this->btnNum5->TabIndex = 4;
			this->btnNum5->Text = L"5";
			this->btnNum5->UseVisualStyleBackColor = true;
			this->btnNum5->Click += gcnew System::EventHandler(this, &MyForm::btnNum1_Click);
			// 
			// btnNum4
			// 
			this->btnNum4->Location = System::Drawing::Point(41, 238);
			this->btnNum4->Margin = System::Windows::Forms::Padding(4);
			this->btnNum4->Name = L"btnNum4";
			this->btnNum4->Size = System::Drawing::Size(59, 56);
			this->btnNum4->TabIndex = 3;
			this->btnNum4->Text = L"4";
			this->btnNum4->UseVisualStyleBackColor = true;
			this->btnNum4->Click += gcnew System::EventHandler(this, &MyForm::btnNum1_Click);
			// 
			// btnNum9
			// 
			this->btnNum9->Location = System::Drawing::Point(175, 174);
			this->btnNum9->Margin = System::Windows::Forms::Padding(4);
			this->btnNum9->Name = L"btnNum9";
			this->btnNum9->Size = System::Drawing::Size(59, 56);
			this->btnNum9->TabIndex = 8;
			this->btnNum9->Text = L"9";
			this->btnNum9->UseVisualStyleBackColor = true;
			this->btnNum9->Click += gcnew System::EventHandler(this, &MyForm::btnNum1_Click);
			// 
			// btnNum8
			// 
			this->btnNum8->Location = System::Drawing::Point(108, 174);
			this->btnNum8->Margin = System::Windows::Forms::Padding(4);
			this->btnNum8->Name = L"btnNum8";
			this->btnNum8->Size = System::Drawing::Size(59, 56);
			this->btnNum8->TabIndex = 7;
			this->btnNum8->Text = L"8";
			this->btnNum8->UseVisualStyleBackColor = true;
			this->btnNum8->Click += gcnew System::EventHandler(this, &MyForm::btnNum1_Click);
			// 
			// btnNum7
			// 
			this->btnNum7->Location = System::Drawing::Point(41, 174);
			this->btnNum7->Margin = System::Windows::Forms::Padding(4);
			this->btnNum7->Name = L"btnNum7";
			this->btnNum7->Size = System::Drawing::Size(59, 56);
			this->btnNum7->TabIndex = 6;
			this->btnNum7->Text = L"7";
			this->btnNum7->UseVisualStyleBackColor = true;
			this->btnNum7->Click += gcnew System::EventHandler(this, &MyForm::btnNum1_Click);
			// 
			// btnNum0
			// 
			this->btnNum0->Location = System::Drawing::Point(108, 367);
			this->btnNum0->Margin = System::Windows::Forms::Padding(4);
			this->btnNum0->Name = L"btnNum0";
			this->btnNum0->Size = System::Drawing::Size(59, 56);
			this->btnNum0->TabIndex = 9;
			this->btnNum0->Text = L"0";
			this->btnNum0->UseVisualStyleBackColor = true;
			this->btnNum0->Click += gcnew System::EventHandler(this, &MyForm::btnNum1_Click);
			// 
			// txtBxMain
			// 
			this->txtBxMain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->txtBxMain->Location = System::Drawing::Point(41, 31);
			this->txtBxMain->Name = L"txtBxMain";
			this->txtBxMain->ReadOnly = true;
			this->txtBxMain->Size = System::Drawing::Size(260, 35);
			this->txtBxMain->TabIndex = 10;
			this->txtBxMain->Text = L"0";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(242, 174);
			this->button11->Margin = System::Windows::Forms::Padding(4);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(59, 56);
			this->button11->TabIndex = 11;
			this->button11->Text = L"Х";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::btnOperation_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(242, 238);
			this->button12->Margin = System::Windows::Forms::Padding(4);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(59, 56);
			this->button12->TabIndex = 12;
			this->button12->Text = L"-";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::btnOperation_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(242, 302);
			this->button13->Margin = System::Windows::Forms::Padding(4);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(59, 56);
			this->button13->TabIndex = 13;
			this->button13->Text = L"+";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::btnOperation_Click);
			// 
			// btnEqual
			// 
			this->btnEqual->Location = System::Drawing::Point(242, 367);
			this->btnEqual->Margin = System::Windows::Forms::Padding(4);
			this->btnEqual->Name = L"btnEqual";
			this->btnEqual->Size = System::Drawing::Size(59, 56);
			this->btnEqual->TabIndex = 14;
			this->btnEqual->Text = L"=";
			this->btnEqual->UseVisualStyleBackColor = true;
			this->btnEqual->Click += gcnew System::EventHandler(this, &MyForm::btnEqual_Click);
			// 
			// btnDot
			// 
			this->btnDot->Location = System::Drawing::Point(175, 366);
			this->btnDot->Margin = System::Windows::Forms::Padding(4);
			this->btnDot->Name = L"btnDot";
			this->btnDot->Size = System::Drawing::Size(59, 56);
			this->btnDot->TabIndex = 15;
			this->btnDot->Text = L",";
			this->btnDot->UseVisualStyleBackColor = true;
			this->btnDot->Click += gcnew System::EventHandler(this, &MyForm::btnDot_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(41, 367);
			this->button16->Margin = System::Windows::Forms::Padding(4);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(59, 56);
			this->button16->TabIndex = 16;
			this->button16->Text = L"+/-";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::btnChangeSign_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(242, 110);
			this->button17->Margin = System::Windows::Forms::Padding(4);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(59, 56);
			this->button17->TabIndex = 17;
			this->button17->Text = L"/";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::btnOperation_Click);
			// 
			// btnRemoveChar
			// 
			this->btnRemoveChar->Location = System::Drawing::Point(108, 110);
			this->btnRemoveChar->Margin = System::Windows::Forms::Padding(4);
			this->btnRemoveChar->Name = L"btnRemoveChar";
			this->btnRemoveChar->Size = System::Drawing::Size(59, 56);
			this->btnRemoveChar->TabIndex = 18;
			this->btnRemoveChar->Text = L"<-";
			this->btnRemoveChar->UseVisualStyleBackColor = true;
			this->btnRemoveChar->Click += gcnew System::EventHandler(this, &MyForm::btnRemoveChar_Click);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(41, 110);
			this->btnClear->Margin = System::Windows::Forms::Padding(4);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(59, 56);
			this->btnClear->TabIndex = 19;
			this->btnClear->Text = L"C";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::btnClear_Click);
			// 
			// btnSqrt
			// 
			this->btnSqrt->Location = System::Drawing::Point(175, 110);
			this->btnSqrt->Margin = System::Windows::Forms::Padding(4);
			this->btnSqrt->Name = L"btnSqrt";
			this->btnSqrt->Size = System::Drawing::Size(59, 56);
			this->btnSqrt->TabIndex = 20;
			this->btnSqrt->Text = L"Sqrt";
			this->btnSqrt->UseVisualStyleBackColor = true;
			this->btnSqrt->Click += gcnew System::EventHandler(this, &MyForm::btnSqrt_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(336, 458);
			this->Controls->Add(this->btnSqrt);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnRemoveChar);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->btnDot);
			this->Controls->Add(this->btnEqual);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->txtBxMain);
			this->Controls->Add(this->btnNum0);
			this->Controls->Add(this->btnNum9);
			this->Controls->Add(this->btnNum8);
			this->Controls->Add(this->btnNum7);
			this->Controls->Add(this->btnNum6);
			this->Controls->Add(this->btnNum5);
			this->Controls->Add(this->btnNum4);
			this->Controls->Add(this->btnNum3);
			this->Controls->Add(this->btnNum2);
			this->Controls->Add(this->btnNum1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Калькулятор";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnNum1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtBxMain->Text == "0")
			txtBxMain->Clear();
		if (executeOperation)
		{
			txtBxMain->Clear();
			executeOperation = false;
		}

		Button^ but = (Button^)sender;
		txtBxMain->Text += but->Text;
	}

	private: System::Void EqualExecute()
	{
		if (operation == "")
			return;

		double second = Double::Parse(txtBxMain->Text);

		double res = 0;

		if (operation == "+")
			res = first + second;
		else if (operation == "-")
			res = first - second;
		else if (operation == "Х")
			res = first * second;
		else if (operation == "/")
			res = first / second;

		first = res;
		txtBxMain->Text = res.ToString();
		operation = "";
	}

	private: System::Void btnOperation_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtBxMain->Text != "")
		{
			if (operation == "")
			{
				first = Double::Parse(txtBxMain->Text);
				txtBxMain->Clear();
			}
			else
			{
				executeOperation = true;
				EqualExecute();
			}
			
			Button^ but = (Button^)sender;
			operation = but->Text;
		}
	}
private: System::Void btnEqual_Click(System::Object^ sender, System::EventArgs^ e) {
	EqualExecute();
}

private: System::Void btnChangeSign_Click(System::Object^ sender, System::EventArgs^ e) {
	double num = Double::Parse(txtBxMain->Text);
	num = -num;

	txtBxMain->Text = num.ToString();
}
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
	txtBxMain->Text = "0";
	first = 0;
	operation = "";
}
private: System::Void btnRemoveChar_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ s = txtBxMain->Text;
	if (s->Length > 1)
		s = s->Substring(0, s->Length - 1);
	else
		s = "0";

	txtBxMain->Text = s;
}
private: System::Void btnSqrt_Click(System::Object^ sender, System::EventArgs^ e) {
	double num = Double::Parse(txtBxMain->Text);
	if (num < 0)
	{
		MessageBox::Show("Введены неверные данные‬");
	}
	else
	{
		num = Math::Sqrt(num);
		txtBxMain->Text = num.ToString();
	}
}
private: System::Void btnDot_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!txtBxMain->Text->Contains(","))
	{
		txtBxMain->Text += ",";
	}
}
};
}

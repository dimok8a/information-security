#pragma once
#include "Crypto.h"

namespace lab3UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ messageTextBox;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ keyTextBox;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ encryptedTextBox;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ encryptedMessageTextBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ decryptedMessageTextBox;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ encryptedKeyTextBox;
	private: System::Windows::Forms::Label^ inputCounterLabel2;
	private: System::Windows::Forms::Label^ inputCounterLabel1;






	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->messageTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->keyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->encryptedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->inputCounterLabel2 = (gcnew System::Windows::Forms::Label());
			this->encryptedMessageTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->decryptedMessageTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->encryptedKeyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->inputCounterLabel1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(207, 328);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Закодировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// messageTextBox
			// 
			this->messageTextBox->Location = System::Drawing::Point(181, 63);
			this->messageTextBox->Name = L"messageTextBox";
			this->messageTextBox->Size = System::Drawing::Size(183, 20);
			this->messageTextBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(234, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Сообщение:";
			// 
			// keyTextBox
			// 
			this->keyTextBox->Location = System::Drawing::Point(179, 171);
			this->keyTextBox->Name = L"keyTextBox";
			this->keyTextBox->Size = System::Drawing::Size(183, 20);
			this->keyTextBox->TabIndex = 3;
			this->keyTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::keyTextBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(219, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Ключ (16 символов):";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(192, 225);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(155, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Закодированное сообщение:";
			// 
			// encryptedTextBox
			// 
			this->encryptedTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->encryptedTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->encryptedTextBox->Location = System::Drawing::Point(179, 261);
			this->encryptedTextBox->Name = L"encryptedTextBox";
			this->encryptedTextBox->ReadOnly = true;
			this->encryptedTextBox->Size = System::Drawing::Size(183, 21);
			this->encryptedTextBox->TabIndex = 5;
			this->encryptedTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::encryptedTextBox_KeyDown);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(572, 432);
			this->tabControl1->TabIndex = 7;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->inputCounterLabel1);
			this->tabPage1->Controls->Add(this->messageTextBox);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->encryptedTextBox);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->keyTextBox);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(564, 406);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Закодировать";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->inputCounterLabel2);
			this->tabPage2->Controls->Add(this->encryptedMessageTextBox);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->decryptedMessageTextBox);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->encryptedKeyTextBox);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(564, 406);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Раскодировать";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// inputCounterLabel2
			// 
			this->inputCounterLabel2->AutoSize = true;
			this->inputCounterLabel2->Location = System::Drawing::Point(252, 136);
			this->inputCounterLabel2->Name = L"inputCounterLabel2";
			this->inputCounterLabel2->Size = System::Drawing::Size(62, 13);
			this->inputCounterLabel2->TabIndex = 14;
			this->inputCounterLabel2->Text = L"Введено: 0";
			// 
			// encryptedMessageTextBox
			// 
			this->encryptedMessageTextBox->Location = System::Drawing::Point(190, 67);
			this->encryptedMessageTextBox->Name = L"encryptedMessageTextBox";
			this->encryptedMessageTextBox->Size = System::Drawing::Size(183, 20);
			this->encryptedMessageTextBox->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(203, 226);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(161, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Раскодированное сообщение:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(218, 329);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 32);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Раскодировать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// decryptedMessageTextBox
			// 
			this->decryptedMessageTextBox->HideSelection = false;
			this->decryptedMessageTextBox->Location = System::Drawing::Point(190, 262);
			this->decryptedMessageTextBox->Name = L"decryptedMessageTextBox";
			this->decryptedMessageTextBox->ReadOnly = true;
			this->decryptedMessageTextBox->Size = System::Drawing::Size(183, 20);
			this->decryptedMessageTextBox->TabIndex = 12;
			this->decryptedMessageTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::decryptedMessageTextBox_KeyDown);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(203, 33);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(155, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Закодированное сообщение:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(228, 111);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(110, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Ключ (16 символов):";
			// 
			// encryptedKeyTextBox
			// 
			this->encryptedKeyTextBox->Location = System::Drawing::Point(190, 167);
			this->encryptedKeyTextBox->Name = L"encryptedKeyTextBox";
			this->encryptedKeyTextBox->Size = System::Drawing::Size(183, 20);
			this->encryptedKeyTextBox->TabIndex = 10;
			this->encryptedKeyTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::encryptedKeyTextBox_TextChanged);
			// 
			// inputCounterLabel1
			// 
			this->inputCounterLabel1->AutoSize = true;
			this->inputCounterLabel1->Location = System::Drawing::Point(240, 134);
			this->inputCounterLabel1->Name = L"inputCounterLabel1";
			this->inputCounterLabel1->Size = System::Drawing::Size(62, 13);
			this->inputCounterLabel1->TabIndex = 15;
			this->inputCounterLabel1->Text = L"Введено: 0";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 456);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MainForm";
			this->Text = L"ГОСТ 28147-89";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->keyTextBox->Text->Length == 16)
			this->encryptedTextBox->Text = Crypto::encrypt(this->keyTextBox->Text, this->messageTextBox->Text);
		else
			MessageBox::Show(L"Ключ должен быть длинной 16 символов", L"Ошибка ключа", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->encryptedKeyTextBox->Text->Length == 16)
			this->decryptedMessageTextBox->Text = Crypto::decrypt(this->encryptedKeyTextBox->Text, this->encryptedMessageTextBox->Text);
		else
			MessageBox::Show(L"Ключ должен быть длинной 16 символов", L"Ошибка ключа", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
private: System::Void encryptedTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->Control && e->KeyCode == Keys::A)
	{
		if (sender != NULL)
		{
			this->encryptedTextBox->SelectAll();
			this->encryptedTextBox->Focus();
		}
			
	}
}
private: System::Void decryptedMessageTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->Control && e->KeyCode == Keys::A)
	{
		if (sender != NULL)
		{
			this->decryptedMessageTextBox->SelectAll();
			this->decryptedMessageTextBox->Focus();
		}

	}
}
private: System::Void encryptedKeyTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->inputCounterLabel2->Text = "Введено: " + this->encryptedKeyTextBox->Text->Length;
}
private: System::Void keyTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->inputCounterLabel1->Text = "Введено: " + this->keyTextBox->Text->Length;
}
};
}

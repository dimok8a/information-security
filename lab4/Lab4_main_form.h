#pragma once
#include <math.h>
#include "RSA.h"
#include <msclr\marshal_cppstd.h>

namespace lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for lab4_main_form
	/// </summary>
	public ref class lab4_main_form : public System::Windows::Forms::Form
	{
	public:
		lab4_main_form(void)
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
		~lab4_main_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_enter_p;
	protected:
	private: System::Windows::Forms::Label^ label_enter_q;
	private: System::Windows::Forms::TextBox^ textbox_input_p;
	private: System::Windows::Forms::TextBox^ textbox_input_q;
	private: System::Windows::Forms::Button^ button_code;
	private: System::Windows::Forms::Label^ label_encoded_text;


	private: System::Windows::Forms::TextBox^ textbox_encrypted_text;
	private: System::Windows::Forms::TabControl^ tabControl1;




	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textbox_decrypted_message;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label_decrypt;

	private: System::Windows::Forms::TextBox^ textbox_input_d;
	private: System::Windows::Forms::Button^ button_decrypt;


	private: System::Windows::Forms::TextBox^ textbox_input_n;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textbox_message_to_encrypt;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textbox_message_to_decrypt;
	private: System::Windows::Forms::ComboBox^ combobox_input_e;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ combobox_input_d;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textbox_n;
	private: System::Windows::Forms::ListBox^ listbox_variants;
	private: System::Windows::Forms::Label^ label_variants;
	private: System::Windows::Forms::TextBox^ textbox_unable_decode;
	private: System::Windows::Forms::Label^ label_unable_decode;
	private: System::Windows::Forms::TextBox^ textbox_unable_encode;
	private: System::Windows::Forms::Label^ label_unable_encode;
	private: System::Windows::Forms::RadioButton^ radiobutton_numbers;

	private: System::Windows::Forms::RadioButton^ radiobutton_text;

	private: System::Windows::Forms::Label^ label1;













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
			this->label_enter_p = (gcnew System::Windows::Forms::Label());
			this->label_enter_q = (gcnew System::Windows::Forms::Label());
			this->textbox_input_p = (gcnew System::Windows::Forms::TextBox());
			this->textbox_input_q = (gcnew System::Windows::Forms::TextBox());
			this->button_code = (gcnew System::Windows::Forms::Button());
			this->label_encoded_text = (gcnew System::Windows::Forms::Label());
			this->textbox_encrypted_text = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textbox_unable_encode = (gcnew System::Windows::Forms::TextBox());
			this->label_unable_encode = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textbox_n = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->combobox_input_d = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->combobox_input_e = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textbox_message_to_encrypt = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->radiobutton_numbers = (gcnew System::Windows::Forms::RadioButton());
			this->radiobutton_text = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textbox_unable_decode = (gcnew System::Windows::Forms::TextBox());
			this->label_unable_decode = (gcnew System::Windows::Forms::Label());
			this->label_variants = (gcnew System::Windows::Forms::Label());
			this->listbox_variants = (gcnew System::Windows::Forms::ListBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textbox_message_to_decrypt = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textbox_decrypted_message = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label_decrypt = (gcnew System::Windows::Forms::Label());
			this->textbox_input_d = (gcnew System::Windows::Forms::TextBox());
			this->button_decrypt = (gcnew System::Windows::Forms::Button());
			this->textbox_input_n = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_enter_p
			// 
			this->label_enter_p->AutoSize = true;
			this->label_enter_p->Location = System::Drawing::Point(240, 33);
			this->label_enter_p->Name = L"label_enter_p";
			this->label_enter_p->Size = System::Drawing::Size(61, 13);
			this->label_enter_p->TabIndex = 0;
			this->label_enter_p->Text = L"Введите p:";
			// 
			// label_enter_q
			// 
			this->label_enter_q->AutoSize = true;
			this->label_enter_q->Location = System::Drawing::Point(240, 99);
			this->label_enter_q->Name = L"label_enter_q";
			this->label_enter_q->Size = System::Drawing::Size(61, 13);
			this->label_enter_q->TabIndex = 1;
			this->label_enter_q->Text = L"Введите q:";
			// 
			// textbox_input_p
			// 
			this->textbox_input_p->Location = System::Drawing::Point(224, 63);
			this->textbox_input_p->Name = L"textbox_input_p";
			this->textbox_input_p->Size = System::Drawing::Size(100, 20);
			this->textbox_input_p->TabIndex = 2;
			this->textbox_input_p->Leave += gcnew System::EventHandler(this, &lab4_main_form::textbox_input_q_Leave);
			// 
			// textbox_input_q
			// 
			this->textbox_input_q->Location = System::Drawing::Point(224, 130);
			this->textbox_input_q->Name = L"textbox_input_q";
			this->textbox_input_q->Size = System::Drawing::Size(100, 20);
			this->textbox_input_q->TabIndex = 3;
			this->textbox_input_q->Leave += gcnew System::EventHandler(this, &lab4_main_form::textbox_input_q_Leave);
			// 
			// button_code
			// 
			this->button_code->Location = System::Drawing::Point(224, 446);
			this->button_code->Name = L"button_code";
			this->button_code->Size = System::Drawing::Size(100, 23);
			this->button_code->TabIndex = 4;
			this->button_code->Text = L"Зашифровать";
			this->button_code->UseVisualStyleBackColor = true;
			this->button_code->Click += gcnew System::EventHandler(this, &lab4_main_form::button_code_Click);
			// 
			// label_encoded_text
			// 
			this->label_encoded_text->AutoSize = true;
			this->label_encoded_text->Location = System::Drawing::Point(240, 497);
			this->label_encoded_text->Name = L"label_encoded_text";
			this->label_encoded_text->Size = System::Drawing::Size(62, 13);
			this->label_encoded_text->TabIndex = 5;
			this->label_encoded_text->Text = L"Результат:";
			// 
			// textbox_encrypted_text
			// 
			this->textbox_encrypted_text->Location = System::Drawing::Point(204, 528);
			this->textbox_encrypted_text->Name = L"textbox_encrypted_text";
			this->textbox_encrypted_text->Size = System::Drawing::Size(143, 20);
			this->textbox_encrypted_text->TabIndex = 6;
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
			this->tabControl1->Size = System::Drawing::Size(560, 638);
			this->tabControl1->TabIndex = 7;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->textbox_unable_encode);
			this->tabPage1->Controls->Add(this->label_unable_encode);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->textbox_n);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->combobox_input_d);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->combobox_input_e);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->textbox_message_to_encrypt);
			this->tabPage1->Controls->Add(this->label_enter_p);
			this->tabPage1->Controls->Add(this->textbox_encrypted_text);
			this->tabPage1->Controls->Add(this->label_enter_q);
			this->tabPage1->Controls->Add(this->label_encoded_text);
			this->tabPage1->Controls->Add(this->textbox_input_p);
			this->tabPage1->Controls->Add(this->button_code);
			this->tabPage1->Controls->Add(this->textbox_input_q);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(552, 612);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Зашифровать";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// textbox_unable_encode
			// 
			this->textbox_unable_encode->Location = System::Drawing::Point(6, 528);
			this->textbox_unable_encode->Name = L"textbox_unable_encode";
			this->textbox_unable_encode->Size = System::Drawing::Size(538, 20);
			this->textbox_unable_encode->TabIndex = 20;
			this->textbox_unable_encode->Visible = false;
			// 
			// label_unable_encode
			// 
			this->label_unable_encode->AutoSize = true;
			this->label_unable_encode->Location = System::Drawing::Point(3, 497);
			this->label_unable_encode->Name = L"label_unable_encode";
			this->label_unable_encode->Size = System::Drawing::Size(547, 13);
			this->label_unable_encode->TabIndex = 19;
			this->label_unable_encode->Text = L"Поскольку введенное n > 2^16, то зашифрованный текст может быть не представим в к"
				L"одировке UTF-16";
			this->label_unable_encode->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(263, 163);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(16, 13);
			this->label9->TabIndex = 13;
			this->label9->Text = L"n:";
			// 
			// textbox_n
			// 
			this->textbox_n->Location = System::Drawing::Point(224, 194);
			this->textbox_n->Name = L"textbox_n";
			this->textbox_n->ReadOnly = true;
			this->textbox_n->Size = System::Drawing::Size(100, 20);
			this->textbox_n->TabIndex = 14;
			this->textbox_n->TextChanged += gcnew System::EventHandler(this, &lab4_main_form::textbox_n_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(240, 298);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(69, 13);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Выберите d:";
			// 
			// combobox_input_d
			// 
			this->combobox_input_d->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->combobox_input_d->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->combobox_input_d->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combobox_input_d->FormattingEnabled = true;
			this->combobox_input_d->Location = System::Drawing::Point(212, 331);
			this->combobox_input_d->Name = L"combobox_input_d";
			this->combobox_input_d->Size = System::Drawing::Size(121, 21);
			this->combobox_input_d->TabIndex = 11;
			this->combobox_input_d->SelectedIndexChanged += gcnew System::EventHandler(this, &lab4_main_form::combobox_input_d_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(240, 228);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 13);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Выберите e:";
			// 
			// combobox_input_e
			// 
			this->combobox_input_e->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->combobox_input_e->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->combobox_input_e->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combobox_input_e->FormattingEnabled = true;
			this->combobox_input_e->Location = System::Drawing::Point(212, 255);
			this->combobox_input_e->Name = L"combobox_input_e";
			this->combobox_input_e->Size = System::Drawing::Size(121, 21);
			this->combobox_input_e->TabIndex = 9;
			this->combobox_input_e->DropDownClosed += gcnew System::EventHandler(this, &lab4_main_form::combobox_input_e_DropDownClosed);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(221, 376);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(112, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Введите сообщение:";
			// 
			// textbox_message_to_encrypt
			// 
			this->textbox_message_to_encrypt->Location = System::Drawing::Point(204, 408);
			this->textbox_message_to_encrypt->Name = L"textbox_message_to_encrypt";
			this->textbox_message_to_encrypt->Size = System::Drawing::Size(143, 20);
			this->textbox_message_to_encrypt->TabIndex = 8;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->radiobutton_numbers);
			this->tabPage2->Controls->Add(this->radiobutton_text);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Controls->Add(this->textbox_unable_decode);
			this->tabPage2->Controls->Add(this->label_unable_decode);
			this->tabPage2->Controls->Add(this->label_variants);
			this->tabPage2->Controls->Add(this->listbox_variants);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->textbox_message_to_decrypt);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->textbox_decrypted_message);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->label_decrypt);
			this->tabPage2->Controls->Add(this->textbox_input_d);
			this->tabPage2->Controls->Add(this->button_decrypt);
			this->tabPage2->Controls->Add(this->textbox_input_n);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(552, 612);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Расшифровать";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// radiobutton_numbers
			// 
			this->radiobutton_numbers->AutoSize = true;
			this->radiobutton_numbers->Location = System::Drawing::Point(219, 232);
			this->radiobutton_numbers->Name = L"radiobutton_numbers";
			this->radiobutton_numbers->Size = System::Drawing::Size(89, 17);
			this->radiobutton_numbers->TabIndex = 22;
			this->radiobutton_numbers->Text = L"Набор чисел";
			this->radiobutton_numbers->UseVisualStyleBackColor = true;
			// 
			// radiobutton_text
			// 
			this->radiobutton_text->AutoSize = true;
			this->radiobutton_text->Checked = true;
			this->radiobutton_text->Location = System::Drawing::Point(219, 208);
			this->radiobutton_text->Name = L"radiobutton_text";
			this->radiobutton_text->Size = System::Drawing::Size(55, 17);
			this->radiobutton_text->TabIndex = 21;
			this->radiobutton_text->TabStop = true;
			this->radiobutton_text->Text = L"Текст";
			this->radiobutton_text->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(197, 176);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 13);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Выберите вид сообщения:";
			// 
			// textbox_unable_decode
			// 
			this->textbox_unable_decode->Location = System::Drawing::Point(93, 464);
			this->textbox_unable_decode->Name = L"textbox_unable_decode";
			this->textbox_unable_decode->Size = System::Drawing::Size(365, 20);
			this->textbox_unable_decode->TabIndex = 19;
			this->textbox_unable_decode->Visible = false;
			// 
			// label_unable_decode
			// 
			this->label_unable_decode->AutoSize = true;
			this->label_unable_decode->Location = System::Drawing::Point(90, 405);
			this->label_unable_decode->Name = L"label_unable_decode";
			this->label_unable_decode->Size = System::Drawing::Size(371, 13);
			this->label_unable_decode->TabIndex = 18;
			this->label_unable_decode->Text = L"Зашифрованный текст не может быть представим в кодировке UTF-16";
			this->label_unable_decode->Visible = false;
			// 
			// label_variants
			// 
			this->label_variants->AutoSize = true;
			this->label_variants->Location = System::Drawing::Point(104, 405);
			this->label_variants->Name = L"label_variants";
			this->label_variants->Size = System::Drawing::Size(354, 13);
			this->label_variants->TabIndex = 17;
			this->label_variants->Text = L"Поскольку введенное n < 2^15, то возможны следующие варианты:";
			this->label_variants->Visible = false;
			// 
			// listbox_variants
			// 
			this->listbox_variants->FormattingEnabled = true;
			this->listbox_variants->HorizontalScrollbar = true;
			this->listbox_variants->Location = System::Drawing::Point(93, 438);
			this->listbox_variants->Name = L"listbox_variants";
			this->listbox_variants->Size = System::Drawing::Size(365, 95);
			this->listbox_variants->TabIndex = 16;
			this->listbox_variants->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(216, 266);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(112, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Введите сообщение:";
			// 
			// textbox_message_to_decrypt
			// 
			this->textbox_message_to_decrypt->Location = System::Drawing::Point(200, 296);
			this->textbox_message_to_decrypt->Name = L"textbox_message_to_decrypt";
			this->textbox_message_to_decrypt->Size = System::Drawing::Size(143, 20);
			this->textbox_message_to_decrypt->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(235, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Введите d:";
			// 
			// textbox_decrypted_message
			// 
			this->textbox_decrypted_message->Location = System::Drawing::Point(200, 438);
			this->textbox_decrypted_message->Name = L"textbox_decrypted_message";
			this->textbox_decrypted_message->Size = System::Drawing::Size(143, 20);
			this->textbox_decrypted_message->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(235, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Введите n:";
			// 
			// label_decrypt
			// 
			this->label_decrypt->AutoSize = true;
			this->label_decrypt->Location = System::Drawing::Point(235, 405);
			this->label_decrypt->Name = L"label_decrypt";
			this->label_decrypt->Size = System::Drawing::Size(62, 13);
			this->label_decrypt->TabIndex = 12;
			this->label_decrypt->Text = L"Результат:";
			// 
			// textbox_input_d
			// 
			this->textbox_input_d->Location = System::Drawing::Point(219, 59);
			this->textbox_input_d->Name = L"textbox_input_d";
			this->textbox_input_d->Size = System::Drawing::Size(100, 20);
			this->textbox_input_d->TabIndex = 9;
			// 
			// button_decrypt
			// 
			this->button_decrypt->Location = System::Drawing::Point(219, 346);
			this->button_decrypt->Name = L"button_decrypt";
			this->button_decrypt->Size = System::Drawing::Size(100, 23);
			this->button_decrypt->TabIndex = 11;
			this->button_decrypt->Text = L"Расшифровать";
			this->button_decrypt->UseVisualStyleBackColor = true;
			this->button_decrypt->Click += gcnew System::EventHandler(this, &lab4_main_form::button_decrypt_Click);
			// 
			// textbox_input_n
			// 
			this->textbox_input_n->Location = System::Drawing::Point(219, 128);
			this->textbox_input_n->Name = L"textbox_input_n";
			this->textbox_input_n->Size = System::Drawing::Size(100, 20);
			this->textbox_input_n->TabIndex = 10;
			// 
			// lab4_main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 662);
			this->Controls->Add(this->tabControl1);
			this->MinimumSize = System::Drawing::Size(600, 500);
			this->Name = L"lab4_main_form";
			this->Text = L"Криптосистема RSA";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_code_Click(System::Object^ sender, System::EventArgs^ event) {
		msclr::interop::marshal_context context;
		System::String^ message = textbox_message_to_encrypt->Text;
		System::String^ encryptedMessage = "";
		BigInt e = context.marshal_as<std::string>(combobox_input_e->SelectedItem->ToString());
		BigInt n = context.marshal_as<std::string>(textbox_n->Text);
		// Если n не влазит в рамки uft-16, то сообщаем пользователю и выводим числа в виде чисел
		if (n > RSA::pow(BigInt("2"), BigInt("16")))
		{
			for (int i = 0; i < message->Length; i++)
			{
				BigInt m(message[i]);
				BigInt answer(RSA::getRemainder(m, e, n));
				encryptedMessage += gcnew String(answer.ToString().c_str()) + " ";
			}
			label_unable_encode->Visible = true;
			textbox_unable_encode->Visible = true;

			label_encoded_text->Visible = false;
			textbox_encrypted_text->Visible = false;
			textbox_unable_encode->Text = encryptedMessage;
		}
		else
		{
			// Иначе конвертируем числа в буквы и выводим результат
			for (int i = 0; i < message->Length; i++)
			{
				BigInt m(message[i]);
				BigInt answer(RSA::getRemainder(m, e, n));
				encryptedMessage += (char16_t)std::atoi(answer.ToString().c_str());
			}
			label_unable_encode->Visible = false;
			textbox_unable_encode->Visible = false;

			label_encoded_text->Visible = true;
			textbox_encrypted_text->Visible = true;
			textbox_encrypted_text->Text = encryptedMessage;
		}
		
	}
private: System::Void button_decrypt_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	BigInt d = context.marshal_as<std::string>(textbox_input_d->Text);
	BigInt n = context.marshal_as<std::string>(textbox_input_n->Text);
	System::String^ decryptedMessage = "";
	System::String^ message = textbox_message_to_decrypt->Text;
	listbox_variants->Items->Clear();
	textbox_decrypted_message->Text = "";
	// Получаем все введенные в textbox числа в зависимости от того какой выбран режим (Текст/Числа)
	std::vector<BigInt> allNumbers = BigInt::splitString(message, radiobutton_numbers->Checked);
	// Вариант, где исходное сообщение точно влазит в utf-16
	if (n < RSA::pow(BigInt("2"), BigInt("16")))
	{
		for (int i = 0; i < allNumbers.size(); i++)
		{
			BigInt m = allNumbers[i];
			BigInt answer(RSA::getRemainder(m, d, n));
			decryptedMessage += (char16_t)std::atoi(answer.ToString().c_str());
		}
		// Вариант где есть несколько интерпритаций исходного текста
		if (n < RSA::pow(BigInt("2"), BigInt("15")))
		{
			listbox_variants->Items->Clear();
			listbox_variants->Items->Add(decryptedMessage);
			System::String^ newVariant;
			int newLetter = 0;
			BigInt counter("1");
			bool isInRange = true;
			// Помимо декодированного варианта добавляем варианты с буквами + n, +2n и т.д.
			// Пока не выйдем за пределы utf-16
			while (isInRange)
			{
				newVariant = "";
				for (int i = 0; i < decryptedMessage->Length; i++)
				{
					newLetter = decryptedMessage[i] + std::atoi((n * counter).ToString().c_str());
					if (newLetter > pow(2, 16))
					{
						isInRange = false;
						break;
					}
					newVariant += (char16_t)newLetter;
				}
				if (isInRange)
					listbox_variants->Items->Add(newVariant);
				counter++;
			}
			textbox_decrypted_message->Visible = false;
			label_decrypt->Visible = false;
			label_unable_decode->Visible = false;
			textbox_unable_decode->Visible = false;

			label_variants->Visible = true;
			listbox_variants->Visible = true;
		}
		// Иначе просто выводим ответ
		else
		{
			textbox_decrypted_message->Visible = true;
			label_decrypt->Visible = true;
			label_unable_decode->Visible = false;
			textbox_unable_decode->Visible = false;
			label_variants->Visible = false;
			listbox_variants->Visible = false;
			textbox_decrypted_message->Text = decryptedMessage;
		}
	}
	else
	{
		// Все ли числа декодированного сообщения попали в предел utf-16 
		bool isInRange = true;
		BigInt maxValue = RSA::pow(BigInt("2"), BigInt("16"));
		std::vector<BigInt> decodedNumbers;
		for (int i = 0; i < allNumbers.size(); i++)
		{
			BigInt m = allNumbers[i];
			BigInt answer(RSA::getRemainder(m, d, n));
			if (answer > maxValue)
				isInRange = false;
			decodedNumbers.push_back(answer);
			//decryptedMessage += gcnew String(answer.ToString().c_str()) + " ";
		}
		// Если не все, то выводим числа
		if (!isInRange)
		{
			for (BigInt decodedNumber: decodedNumbers)
				decryptedMessage += gcnew String(decodedNumber.ToString().c_str()) + " ";
			textbox_decrypted_message->Visible = false;
			label_decrypt->Visible = false;
			label_variants->Visible = false;
			listbox_variants->Visible = false;

			label_unable_decode->Visible = true;
			textbox_unable_decode->Visible = true;

			textbox_unable_decode->Text = decryptedMessage;
		}
		// Иначе выводим символы
		else
		{
			for (BigInt decodedNumber : decodedNumbers)
				decryptedMessage += (char16_t)std::atoi(decodedNumber.ToString().c_str());
			textbox_decrypted_message->Visible = true;
			label_decrypt->Visible = true;
			label_unable_decode->Visible = false;
			textbox_unable_decode->Visible = false;
			label_variants->Visible = false;
			listbox_variants->Visible = false;
			textbox_decrypted_message->Text = decryptedMessage;
		}
		
	}
}

// Одинаковый слушатель для p и q при потере фокуса
private: System::Void textbox_input_q_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (textbox_input_p->Text != "" && textbox_input_q->Text != "")
	{
		combobox_input_e->Items->Clear();
		msclr::interop::marshal_context context;
		BigInt p(context.marshal_as<std::string>(textbox_input_p->Text));
		BigInt q(context.marshal_as<std::string>(textbox_input_q->Text));
		if (RSA::isSimple(p) && RSA::isSimple(q) && p != q)
		{
			BigInt fi = (p - 1) * (q - 1);
			textbox_n->Text = gcnew String(BigInt(p * q).ToString().c_str());
			std::vector<BigInt> eNumbers = RSA::generateENumbers(fi);
			for (auto number : eNumbers)
			{
				combobox_input_e->Items->Add(gcnew String(number.ToString().c_str()));
			}
		}
		else
		{
			MessageBox::Show(L"p и q должны быть простыми неравными числами", L"Ошибка ключа", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
	}
}

// Слушатель выбора e для генерации d на его основе
private: System::Void combobox_input_e_DropDownClosed(System::Object^ sender, System::EventArgs^ e) {
	if (combobox_input_e->SelectedIndex != -1)
	{
		msclr::interop::marshal_context context;
		combobox_input_d->Items->Clear();
		BigInt e = context.marshal_as<std::string>(combobox_input_e->SelectedItem->ToString());
		BigInt p(context.marshal_as<std::string>(textbox_input_p->Text));
		BigInt q(context.marshal_as<std::string>(textbox_input_q->Text));
		BigInt fi = (p - 1) * (q - 1);
		std::vector<BigInt> dNumbers = RSA::generateDNumbers(e, fi);
		for (auto number : dNumbers)
		{
			combobox_input_d->Items->Add(gcnew String(number.ToString().c_str()));
		}
	}
}

// Для удобства записываем выбранные значения в значения при декодировании
private: System::Void textbox_n_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textbox_input_n->Text = textbox_n->Text;
}
private: System::Void combobox_input_d_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (combobox_input_d->SelectedIndex != -1)
	{
		textbox_input_d->Text = combobox_input_d->SelectedItem->ToString();
	}
}
};
}

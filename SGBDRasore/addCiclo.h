#ifndef ADDCICLO_H
#define ADDCICLO_H

#include <iostream>
#include <string>
#include "BaseDatos.h"
#include "errorDialog.h"

namespace SGBDRasore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de addCiclo
	/// </summary>
	public ref class addCiclo : public System::Windows::Forms::Form
	{
	public:
		addCiclo(void)
		{
			InitializeComponent();
			bd = NULL;
		}

		addCiclo(BaseDatos &base) {
			InitializeComponent();
			bd = &base;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~addCiclo()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		BaseDatos *bd;
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::TextBox^  NametextBox;
	private: System::Windows::Forms::Label^  label1;
			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(addCiclo::typeid));
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->NametextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(411, 105);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 42;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &addCiclo::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(301, 105);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(92, 32);
			this->SaveButton->TabIndex = 41;
			this->SaveButton->Text = L"Guardar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &addCiclo::SaveButton_Click);
			// 
			// NametextBox
			// 
			this->NametextBox->Location = System::Drawing::Point(29, 58);
			this->NametextBox->Name = L"NametextBox";
			this->NametextBox->Size = System::Drawing::Size(464, 26);
			this->NametextBox->TabIndex = 40;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 20);
			this->label1->TabIndex = 39;
			this->label1->Text = L"Nombre";
			// 
			// addCiclo
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(526, 153);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->NametextBox);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"addCiclo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"A�adir ciclo";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	using namespace Runtime::InteropServices;
	string p = (const char*)(Marshal::StringToHGlobalAnsi(this->NametextBox->Text)).ToPointer();
	try {
		this->bd->insertPeriod(p);
		Close();
	}
	catch (domain_error &e) {
		string mensaje = "El ciclo que se intenta insertar ya existe en la base de datos.";
		SGBDRasore::errorDialog ^dialog = gcnew SGBDRasore::errorDialog(mensaje);
		dialog->ShowDialog();
		delete dialog;
	}
}
};
}
#endif
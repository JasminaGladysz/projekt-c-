#include <FireDAC.Comp.Client.hpp>  //zawiera klasy s³u¿ace do po³¹czeñ z baz¹ danych
#include <FireDAC.Stan.Param.hpp>  //obs³uguje parametry w zapytanaich
#include <FireDAC.Phys.hpp>   //obs³uga baz danych
#include <FireDAC.Phys.SQLite.hpp>  //zawiera sterownik dla bazy w SQLitcie

#pragma hdrstop

#include "LoginForm_G.h"
#include "RegisterForm_G.h"
#include "MenuForm_G.h"
#include "GalleryForm_G.h"
#include "ImageForm_G.h"

String loggedUser = "";
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
TLoginFormG *LoginFormG;
//---------------------------------------------------------------------------

__fastcall TLoginFormG::TLoginFormG(TComponent* Owner)
	: TForm(Owner)
{

	TRectangle *background = new TRectangle(this);
	background->Parent = this;
	background->Align = TAlignLayout::Client;
	TAlphaColor customColor = MakeColor(152, 168, 105);
	background->Fill->Color = customColor;

	this->Width = 640;
	this->Height = 480;

	this->OnResize = FormResize;

	title = new TImage(this);
	title->Parent = this;
	title->Position->X = 170;
	title->Position->Y = 20;
	title->Width = 350;
	title->Height = 140;
	title->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\tytul.png");

 	login = new TEdit(this);
	login->Parent = this;
	login->Position->X = 230;
	login->Position->Y = 160;
	login->Width = 180;
	login->Height = 30;

	login_label = new TLabel(this);
	login_label->Parent = this;
	login_label->Position->X = 150;
	login_label->Position->Y = 160;
	login_label->Width = 130;
	login_label->Height = 40;
	login_label->Text = "USERNAME: ";
	login_label->Font->Size = 14;

	password = new TEdit(this);
	password->Parent = this;
	password->Position->X = 230;
	password->Position->Y = 200;
	password->Width = 180;
	password->Height = 30;
	password->Password = true;

	password_label = new TLabel(this);
	password_label->Parent = this;
	password_label->Position->X = 150;
	password_label->Position->Y = 200;
	password_label->Width = 130;
	password_label->Height = 40;
	password_label->Text = "PASSWORD: ";
    password_label->Font->Size = 14;

	login_button = new TImage(this);
	login_button->Parent = this;
	login_button->Position->X = 270;
	login_button->Position->Y = 250;
	login_button->Width = 100;
	login_button->Height = 50;
	login_button->OnClick = login_buttonClick;
	login_button->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\button1.png");

	account_button = new TImage(this);
	account_button->Parent = this;
	account_button->Position->X = 270;
	account_button->Position->Y = 320;
	account_button->Width = 100;
	account_button->Height = 50;
	account_button->OnClick = account_buttonClick;
	account_button->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\button2.png");

	login_info = new TLabel(this);
	login_info->Parent = this;
	login_info->Position->X = 230;
	login_info->Position->Y = 290;
	login_info->Width = 200;
	login_info->Height = 40;
	login_info->Text = "";

}

void __fastcall TLoginFormG::account_buttonClick(TObject *Sender)
{
	LoginFormG->Hide();
	RegisterFormG->Show();
}

void __fastcall TLoginFormG::login_buttonClick(TObject *Sender)
{
   FDConnection = new TFDConnection(nullptr);
   FDQuery = new TFDQuery(nullptr);

	try {
		FDConnection->DriverName = "SQLite";
		FDConnection->Params->Database = "C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\Projects\\uzytkownicy.db";
		FDConnection->Connected = true;

		FDQuery->Connection = FDConnection;

		AnsiString inputUsername = login->Text;
		AnsiString inputPassword = password->Text;

		if (inputUsername.IsEmpty() || inputPassword.IsEmpty()) {
			login_info->Text = "cannot be empty";
			return;
		}

		FDQuery->SQL->Text = "SELECT Password FROM Users WHERE Username = :Username";
		FDQuery->ParamByName("Username")->AsString = inputUsername;

		FDQuery->Open();

		if (!FDQuery->IsEmpty()) {
			AnsiString storedPassword = FDQuery->FieldByName("Password")->AsString;

			if (storedPassword == inputPassword) {
				loggedUser = inputUsername;
				login_info->Text = "DONE!";
				MenuFormG->user_label->Text = loggedUser;
				GalleryFormG->user_label->Text = loggedUser;
				ImageFormG->user_label->Text = loggedUser;
				this->Hide();
				MenuFormG->Show();
			} else {
				login_info->Text = "WRONG :(";
			}
		} else {
			login_info->Text = "User not found";
		}
	}
	catch (const Exception &e) {
		login_info->Text = "Error: " + e.Message;
	}
	if (FDQuery) delete FDQuery;
	if (FDConnection) delete FDConnection;
}

void __fastcall TLoginFormG::FormResize(TObject *Sender)
{
	title->Position->X = (this->Width - title->Width) / 2;
	login->Position->X = (this->Width - login->Width) / 2;
	login_label->Position->X = login->Position->X - 80;
	password->Position->X = (this->Width - password->Width) / 2;
	password_label->Position->X = password->Position->X - 80;
	login_button->Position->X = (this->Width - login_button->Width) / 2;
	account_button->Position->X = (this->Width - account_button->Width) / 2;
    login_info->Position->X = (this->Width - login_info->Width) / 2;

    title->Position->Y = (this->Height / 8);
    login->Position->Y = (this->Height / 3);
    login_label->Position->Y = login->Position->Y;
    password->Position->Y = login->Position->Y + 40;
    password_label->Position->Y = password->Position->Y;
    login_button->Position->Y = password->Position->Y + 60;
    account_button->Position->Y = login_button->Position->Y + 60;
    login_info->Position->Y = account_button->Position->Y + 40;
}



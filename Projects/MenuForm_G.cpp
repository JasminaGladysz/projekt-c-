#include <fmx.h>
#include <FMX.Dialogs.hpp> //obs�uguje open dialog

#pragma hdrstop

#include "MenuForm_G.h"
#include "ImageForm_G.h"
#include "GalleryForm_G.h"
#include "LoginForm_G.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
TMenuFormG *MenuFormG;
//---------------------------------------------------------------------------

__fastcall TMenuFormG::TMenuFormG(TComponent* Owner)
    : TForm(Owner)
{
	this->Width = 640;
	this->Height = 480;

	this->OnResize = FormResize;

	TRectangle *background = new TRectangle(this);
	background->Parent = this;
	background->Align = TAlignLayout::Client;
	TAlphaColor customColor = MakeColor(152, 168, 105);
	background->Fill->Color = customColor;

	menu_title = new TImage(this);
	menu_title->Parent = this;
	menu_title->Width = 350;
	menu_title->Height = 140;
	menu_title->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\menu_title.png");

	add_button = new TImage(this);
	add_button->Parent = this;
	add_button->Width = 150;
	add_button->Height = 50;
	add_button->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\button_add.png");
	add_button->OnClick = add_buttonClick;

	gallery_button = new TImage(this);
	gallery_button->Parent = this;
	gallery_button->Width = 150;
	gallery_button->Height = 50;
	gallery_button->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\button_galley.png");
	gallery_button->OnClick = gallery_buttonClick;

	user_label = new TLabel(this);
	user_label->Parent = this;
	user_label->Font->Size = 14;
	user_label->Align = TAlignLayout::None;

	FormResize(this);
}

void __fastcall TMenuFormG::FormResize(TObject *Sender)
{
	menu_title->Position->X = (this->Width - menu_title->Width) / 2;
	menu_title->Position->Y = 20;

	add_button->Position->X = (this->Width - add_button->Width) / 2;
	add_button->Position->Y = menu_title->Position->Y + menu_title->Height + 50;

	gallery_button->Position->X = (this->Width - gallery_button->Width) / 2;
	gallery_button->Position->Y = add_button->Position->Y + add_button->Height + 20;

	user_label->Position->X = this->Width - user_label->Width - 20;
	user_label->Position->Y = 10;
}
//---------------------------------------------------------------------------

void __fastcall TMenuFormG::add_buttonClick(TObject *Sender)
{
	OpenDialog = new TOpenDialog(this);
	OpenDialog->Filter = "Obrazy (*.jpg;*.jpeg;*.bmp;*.png)|*.jpg;*.jpeg;*.bmp;*.png";

	if (OpenDialog->Execute()) {
		try {
			ImageFormG->Image->Bitmap->LoadFromFile(OpenDialog->FileName);
			this->Hide();
			ImageFormG->ShowModal();
			this->Show();
		} catch (...) {
			ShowMessage("cannot load image");
		}
	}
	delete OpenDialog;
}
//---------------------------------------------------------------------------

void __fastcall TMenuFormG::gallery_buttonClick(TObject *Sender)
{
	this->Hide();
	GalleryFormG->Show();
}
//---------------------------------------------------------------------------


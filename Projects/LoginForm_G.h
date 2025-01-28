#ifndef LoginForm_GH
#define LoginForm_GH
//---------------------------------------------------------------------------

#include <fmx.h>   //obs�uguje komponenty
extern String loggedUser; //zmienna globalna przechowuj�ca zalogowanego u�ytkownika
//---------------------------------------------------------------------------

class TLoginFormG : public TForm
{
__published:	// IDE-managed Components

private:	// Deklaracje prywatne
	TImage *title;
	TLabel *login_label;
	TLabel *password_label;
	TImage *login_button;           // Przycisk logowania jako obraz
	TImage *account_button;         // Przycisk tworzenia konta jako obraz
	TEdit *login;                   // Pole loginu
	TEdit *password;                // Pole has�a
	TLabel *login_info;
	TFDQuery *FDQuery;             // Zapytanie do bazy danych
	TFDConnection *FDConnection;   // Po��czenie z baz� danych

	void __fastcall account_buttonClick(TObject *Sender);
	void __fastcall login_buttonClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);

public:		// Deklaracje publiczne
	__fastcall TLoginFormG(TComponent* Owner); // Konstruktor
};
//---------------------------------------------------------------------------
extern PACKAGE TLoginFormG *LoginFormG;
//---------------------------------------------------------------------------
#endif


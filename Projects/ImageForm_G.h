#ifndef ImageForm_GH
#define ImageForm_GH
//---------------------------------------------------------------------------

#include <fmx.h>   //obs³uguje komponenty
#include <FireDAC.Comp.Client.hpp> // Dla TFDQuery i TFDConnection
#include <FireDAC.Stan.Param.hpp>
//---------------------------------------------------------------------------

class TImageFormG : public TForm
{
__published:	// IDE-managed Components

private:	// User declarations
	TFDQuery *FDQuery2;           // Zapytanie FDQuery
	TFDConnection *FDConnection2;

	TImage *save_button;         // Przycisk zapisu
	TImage *back_button;
	TComboBox *items_box;         // Lista rozwijana (Rodzaj)

	TCheckBox *spring;            // Sezon Wiosna
    TCheckBox *summer;            // Sezon Lato
    TCheckBox *fall;              // Sezon Jesieñ
	TCheckBox *winter;            // Sezon Zima

    TCheckBox *casual;            // Okazja Casual
    TCheckBox *blacktie;          // Okazja Black Tie
    TCheckBox *sporty;            // Okazja Sportowa
	TCheckBox *party;             // Okazja Party
public:		// User declarations
    TImage *Image;
	__fastcall TImageFormG(TComponent* Owner);
	void __fastcall save_buttonClick(TObject *Sender);
	void __fastcall back_buttonClick(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    TLabel *user_label;
};

//---------------------------------------------------------------------------

extern PACKAGE TImageFormG *ImageFormG;
//---------------------------------------------------------------------------

#endif


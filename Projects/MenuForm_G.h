//---------------------------------------------------------------------------

#ifndef MenuForm_GH
#define MenuForm_GH
//---------------------------------------------------------------------------
#include <fmx.h>   //obs³uguje komponenty
//---------------------------------------------------------------------------
class TMenuFormG : public TForm
{
__published:	// IDE-managed Components

private:	// User declarations
	TImage *add_button;
	TOpenDialog *OpenDialog;
	TImage *gallery_button;
	TImage *menu_title;
public:		// User declarations
	__fastcall TMenuFormG(TComponent* Owner);
	void __fastcall add_buttonClick(TObject *Sender);
	void __fastcall gallery_buttonClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	TLabel *user_label;
};
//---------------------------------------------------------------------------
extern PACKAGE TMenuFormG *MenuFormG;
//---------------------------------------------------------------------------
#endif

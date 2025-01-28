//---------------------------------------------------------------------------
//#define RegisterForm_GH
//---------------------------------------------------------------------------
#include <fmx.h>

//---------------------------------------------------------------------------

class TRegisterFormG : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
    TEdit *r_user_edit;
    TEdit *r_password_edit;
    TLabel *r_password_label;
    TLabel *r_user_label;
    TImage *rregister_button;
    TImage *rback_button;
    TImage *register_title;
    TLabel *r_password_label1;
	TEdit *r_password_edit1;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery1;

public:		// User declarations
	__fastcall TRegisterFormG(TComponent* Owner);
	void __fastcall rregister_buttonClick(TObject *Sender);
	void __fastcall rback_buttonClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
};

//---------------------------------------------------------------------------

extern PACKAGE TRegisterFormG *RegisterFormG;
//---------------------------------------------------------------------------


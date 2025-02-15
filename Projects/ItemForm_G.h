//---------------------------------------------------------------------------

#ifndef ItemForm_GH
#define ItemForm_GH
//---------------------------------------------------------------------------
#include <fmx.h>
//---------------------------------------------------------------------------

class TItemFormG : public TForm
{
__published:

private:
    int dispID;
    // Elementy UI
    TImage *ImageDisplay;
	TImage *editButton;
	TImage *deleteButton;
    TImage *saveButton;
    TCheckBox *SpringBox;
    TCheckBox *SummerBox;
    TCheckBox *FallBox;
    TCheckBox *WinterBox;
    TCheckBox *CasualBox;     // Checkbox dla Casual
    TCheckBox *BlackTieBox;   // Checkbox dla Black Tie
    TCheckBox *PartyBox;      // Checkbox dla Party
    TCheckBox *SportyBox;     // Checkbox dla Sporty
    TComboBox *ComboBox;

    // Po��czenie z baz� danych
    TFDQuery *FDQuery1;

public:
	__fastcall TItemFormG(TComponent* Owner, int id);
	void __fastcall editButtonClick(TObject *Sender);
	void __fastcall saveButtonClick(TObject *Sender);
	void __fastcall deleteButtonClick(TObject *Sender);
	void LoadImage(const String &imagePath);
	void LoadFormData();
    void DataInfo();
};

//---------------------------------------------------------------------------
extern PACKAGE TItemFormG *ItemFormG;
//---------------------------------------------------------------------------
#endif


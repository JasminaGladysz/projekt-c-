#ifndef GalleryForm_GH
#define GalleryForm_GH
//---------------------------------------------------------------------------

#include <fmx.h> //obs³uga komponentóe
#include <map>  //obs³uguje funckjonalnoœæ map/kontenerów

#pragma hdrstop
#include "GalleryForm_G.h"

//---------------------------------------------------------------------------

class TGalleryFormG : public TForm
{
__published:	// IDE-managed Components:
private:	// User declarations
	int dispId;
	int sezonFilter;
	int okazjaFilter;
	std::map<int, String> imageMap;
	TImage *nextButton;
	TImage *prevButton;
	TImage *refreshButton;
	TImage *addButton;
	TImage *menuButton;
	TCheckBox *SummerBox;
	TCheckBox *SpringBox;
	TCheckBox *FallBox;
	TCheckBox *WinterBox;
	TCheckBox *CasualBox;
	TCheckBox *BlackTieBox;
	TCheckBox *SportyBox;
	TCheckBox *PartyBox;
    TImage *SunImage;
    TImage *FlowerImage;
    TImage *LeafImage;
	TImage *FlakeImage;
	TImage *CasualImage;
	TImage *BlackTieImage;
	TImage *SportyImage;
	TImage *PartyImage;
	TImage *icon;
    TOpenDialog *OpenDialog;
public:		// User declarations
    TFDConnection *FDConnection3;
	__fastcall TGalleryFormG(TComponent* Owner);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall PrevButtonClick(TObject *Sender);
	void __fastcall refreshButtonClick(TObject *Sender);
	void __fastcall addButtonClick(TObject *Sender);
	void __fastcall menuButtonClick(TObject *Sender);
	void __fastcall FilterChanged(TObject *Sender);
	void LoadImages(int sezonFilter = 0, int okazjaFilter = 0); // Poprawiona deklaracja
    void AddIcon(int x, int y, String iconPath, TImage *parent, int id);
	void __fastcall ImageClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
    TLabel *user_label;

};
//---------------------------------------------------------------------------

extern PACKAGE TGalleryFormG *GalleryFormG;

//---------------------------------------------------------------------------

#endif


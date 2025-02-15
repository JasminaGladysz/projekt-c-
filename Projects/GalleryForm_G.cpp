#include <fmx.h>    //obs�uga komponent�w
#include <FireDAC.Comp.Client.hpp>  //zawiera komponenty obs�uguj�ce bazy danych
#include <FireDAC.Phys.SQLite.hpp>  //��czenie z baz� w SQLicie
#include <System.IOUtils.hpp>   //zawiera klasy zwi�zane z operacjami na plikach (TPath itp)

#pragma hdrstop
#include "GalleryForm_G.h"
#include "ItemForm_G.h"
#include "ImageForm_G.h"
#include "MenuForm_G.h"

#pragma package(smart_init)
#pragma resource "*.fmx"
TGalleryFormG *GalleryFormG;

__fastcall TGalleryFormG::TGalleryFormG(TComponent* Owner)
	: TForm(Owner)
{
	this->Width = 880;
	this->Height = 620;

	this->OnResize = FormResize;

	TRectangle *background = new TRectangle(this);
	background->Parent = this;
	background->Align = TAlignLayout::Client;
	TAlphaColor customColor = MakeColor(152, 168, 105);
	background->Fill->Color = customColor;

//CHECKBOZY NA PORY ROKU
	const int checkboxY = 40;
	const int checkboxSpacing = 120;
	int checkboxX = (this->Width - 4 * 120) / 2;

	SummerBox = new TCheckBox(this);
	SummerBox->Parent = this;
	SummerBox->Position->X = checkboxX;
	SummerBox->Position->Y = checkboxY;
	SummerBox->OnChange = FilterChanged;

	SunImage = new TImage(this);
	SunImage->Parent = this;
	SunImage->Position->X = checkboxX + 20;
	SunImage->Position->Y = checkboxY;
	SunImage->Width = 30;
	SunImage->Height = 30;
	SunImage->Tag = -1;
	SunImage->WrapMode = TImageWrapMode::Fit;
	SunImage->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\summer.jpg");
    SunImage->BringToFront();

	checkboxX += checkboxSpacing;  //przesuni�cie X dla kolejnego checkboxa

	SpringBox = new TCheckBox(this);
	SpringBox->Parent = this;
	SpringBox->Position->X = checkboxX;
	SpringBox->Position->Y = checkboxY;
	SpringBox->OnChange = FilterChanged;

	FlowerImage = new TImage(this);
	FlowerImage->Parent = this;
	FlowerImage->Position->X = checkboxX + 20;
	FlowerImage->Position->Y = checkboxY;
	FlowerImage->Width = 30;
	FlowerImage->Height = 30;
	FlowerImage->Tag = -1;
	FlowerImage->WrapMode = TImageWrapMode::Fit;
	FlowerImage->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\spring.png");

	checkboxX += checkboxSpacing;

	FallBox = new TCheckBox(this);
	FallBox->Parent = this;
	FallBox->Position->X = checkboxX;
	FallBox->Position->Y = checkboxY;
	FallBox->OnChange = FilterChanged;

	LeafImage = new TImage(this);
	LeafImage->Parent = this;
	LeafImage->Position->X = checkboxX + 20;
	LeafImage->Position->Y = checkboxY;
	LeafImage->Width = 30;
	LeafImage->Height = 30;
	LeafImage->Tag = -1;
	LeafImage->WrapMode = TImageWrapMode::Fit;
	LeafImage->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\fall.jpg");

	checkboxX += checkboxSpacing;

	WinterBox = new TCheckBox(this);
	WinterBox->Parent = this;
	WinterBox->Position->X = checkboxX;
	WinterBox->Position->Y = checkboxY;
	WinterBox->OnChange = FilterChanged;

	FlakeImage = new TImage(this);
	FlakeImage->Parent = this;
	FlakeImage->Position->X = checkboxX + 20;
	FlakeImage->Position->Y = checkboxY;
	FlakeImage->Width = 30;
	FlakeImage->Height = 30;
	FlakeImage->Tag = -1;
	FlakeImage->BringToFront();
	FlakeImage->WrapMode = TImageWrapMode::Fit;
	FlakeImage->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\winter.jpg");


//CHECKBOZY NA OKAZJE
	const int checkboxY1 = 80;
	int checkboxX1 = (this->Width - 4 * 120) / 2;

	CasualBox = new TCheckBox(this);
	CasualBox->Parent = this;
	CasualBox->Position->X = checkboxX1;
	CasualBox->Position->Y = checkboxY1;
	CasualBox->OnChange = FilterChanged;

	CasualImage = new TImage(this);
	CasualImage->Parent = this;
	CasualImage->Position->X = checkboxX1 + 20;
	CasualImage->Position->Y = checkboxY1;
	CasualImage->Width = 30;
	CasualImage->Height = 30;
	CasualImage->Tag = -1;
	CasualImage->WrapMode = TImageWrapMode::Fit;
	CasualImage->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\casual.jpg");
	CasualImage->BringToFront();

	checkboxX1 += checkboxSpacing;  //przesuni�cie X dla kolejnego checkboxa

	BlackTieBox = new TCheckBox(this);
	BlackTieBox->Parent = this;
	BlackTieBox->Position->X = checkboxX1;
	BlackTieBox->Position->Y = checkboxY1;
	BlackTieBox->OnChange = FilterChanged;

	BlackTieImage = new TImage(this);
	BlackTieImage->Parent = this;
	BlackTieImage->Position->X = checkboxX1 + 20;
	BlackTieImage->Position->Y = checkboxY1;
	BlackTieImage->Width = 30;
	BlackTieImage->Height = 30;
	BlackTieImage->Tag = -1;
	BlackTieImage->WrapMode = TImageWrapMode::Fit;
	BlackTieImage->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\blacktie.jpg");

	checkboxX1 += checkboxSpacing;

	SportyBox = new TCheckBox(this);
	SportyBox->Parent = this;
	SportyBox->Position->X = checkboxX1;
	SportyBox->Position->Y = checkboxY1;
	SportyBox->OnChange = FilterChanged;

	SportyImage = new TImage(this);
	SportyImage->Parent = this;
	SportyImage->Position->X = checkboxX1 + 20;
	SportyImage->Position->Y = checkboxY1;
	SportyImage->Width = 30;
	SportyImage->Height = 30;
	SportyImage->Tag = -1;
	SportyImage->WrapMode = TImageWrapMode::Fit;
	SportyImage->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\sporty.jpg");

	checkboxX1 += checkboxSpacing;

	PartyBox = new TCheckBox(this);
	PartyBox->Parent = this;
	PartyBox->Position->X = checkboxX1;
	PartyBox->Position->Y = checkboxY1;
	PartyBox->OnChange = FilterChanged;

	PartyImage = new TImage(this);
	PartyImage->Parent = this;
	PartyImage->Position->X = checkboxX1 + 20;
	PartyImage->Position->Y = checkboxY1;
	PartyImage->Width = 30;
	PartyImage->Height = 30;
	PartyImage->Tag = -1;
	PartyImage->BringToFront();
	PartyImage->WrapMode = TImageWrapMode::Fit;
	PartyImage->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\party.jpg");



	// PRZYCISKI
	nextButton = new TImage(this);
	nextButton->Parent = this;
	nextButton->Width = 100;
	nextButton->Height = 50;
	nextButton->Tag = -1;
	nextButton->OnClick = NextButtonClick;
	nextButton->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\next_button.png");

	prevButton = new TImage(this);
	prevButton->Parent = this;
	prevButton->Width = 100;
	prevButton->Height = 50;
	prevButton->Tag = -1;
	prevButton->OnClick = PrevButtonClick;
	prevButton->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\previous_button.png");

	refreshButton = new TImage(this);
	refreshButton->Parent = this;
	refreshButton->Width = 100;
	refreshButton->Height = 40;
	refreshButton->Tag = -1;
	refreshButton->OnClick = refreshButtonClick;
	refreshButton->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\refresh_button.png");

	addButton = new TImage(this);
	addButton->Parent = this;
	addButton->Width = 100;
	addButton->Height = 40;
	addButton->Tag = -1;
	addButton->OnClick = addButtonClick;
	addButton->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\add_button.png");

	menuButton = new TImage(this);
	menuButton->Parent = this;
	menuButton->Width = 100;
	menuButton->Height = 40;
	menuButton->Tag = -1;
	menuButton->OnClick = menuButtonClick;
	menuButton->Bitmap->LoadFromFile("C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\menu_button.png");

		// Etykieta nazwy u�ytkownika
	user_label = new TLabel(this);
	user_label->Parent = this;
	user_label->Font->Size = 14;
	user_label->Position->X = this->Width - user_label->Width - 10;
	user_label->Position->Y = 10;
	user_label->Align = TAlignLayout::None;

	// W konstruktorze klasy TGalleryFormG
	sezonFilter = 0; // Startowa warto�� filtrowania na 15 (wszystkie sezony)
	okazjaFilter = 0; // Startowa warto�� filtrowania na 15 (wszystkie okazje)

	dispId = 0;


	LoadImages(sezonFilter, okazjaFilter);
}


void __fastcall TGalleryFormG::NextButtonClick(TObject *Sender) {
	dispId += 8;
	LoadImages(sezonFilter, okazjaFilter);
}

void __fastcall TGalleryFormG::PrevButtonClick(TObject *Sender) {
	dispId = (dispId >= 8) ? dispId - 8 : 0;
	LoadImages(sezonFilter, okazjaFilter);
}

void __fastcall TGalleryFormG::FilterChanged(TObject *Sender) {
	 // checkbozy sezon�w
	sezonFilter = 0;
	if (SummerBox->IsChecked) sezonFilter |= 2; // SummerBox (2) bit
	if (SpringBox->IsChecked) sezonFilter |= 1; // SpringBox (1) bit
	if (FallBox->IsChecked) sezonFilter |= 4;   // FallBox (4) bit
	if (WinterBox->IsChecked) sezonFilter |= 8; // WinterBox (8) bit

	// Chekboxy okazji
	okazjaFilter = 0;
	if (CasualBox->IsChecked) okazjaFilter |= 1;  // CasualBox (1) bit
	if (BlackTieBox->IsChecked) okazjaFilter |= 2; // BlackTieBox (2) bit
	if (SportyBox->IsChecked) okazjaFilter |= 8;  // SportyBox (8) bit
	if (PartyBox->IsChecked) okazjaFilter |= 4;   // PartyBox (4) bit
	LoadImages(sezonFilter, okazjaFilter);
	FormResize(this);
}

void TGalleryFormG::LoadImages(int sezonFilter, int okazjaFilter) {

	const int maxImagesPerRow = 4;
	const int imageWidth = 130;
	const int imageHeight = 170;
	const int horizontalSpacing = 20;
	const int verticalSpacing = 20;

	int screenWidth = this->Width;
	int screenHeight = this->Height;
	int galleryStartX = (screenWidth - maxImagesPerRow * (imageWidth + horizontalSpacing) + horizontalSpacing) / 2;
	int galleryStartY = (screenHeight - (imageHeight + verticalSpacing) * 2) / 2; // Mo�na ustawi� r�wnie� odpowiedni� wysoko�� w zale�no�ci od liczby obrazk�w

	const int iconSize = 10;
	const int iconMargin = 3;


	// Ustalanie pocz�tkowej pozycji na podstawie szeroko�ci okna
	int posX = (screenWidth - maxImagesPerRow * (imageWidth + horizontalSpacing) + horizontalSpacing) / 2;

	// Po��czenie z baz� danych
	TFDConnection *FDConnection = new TFDConnection(nullptr);
	TFDQuery *FDQuery = new TFDQuery(nullptr);

	try {
		FDConnection->DriverName = "SQLite";
		FDConnection->Params->Database = "C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\Projects\\szafa.db";
		FDConnection->Connected = true;

		FDQuery->Connection = FDConnection;

		UnicodeString userText = user_label->Text;

		FDQuery->SQL->Text = "SELECT ID, PIC, SEZON, OKAZJA FROM szafa WHERE (sezon & :SezonFilter) != 0 AND (okazja & :OkazjaFilter) != 0 AND USERS = :UserLabel LIMIT 8 OFFSET :Offset";
        FDQuery->ParamByName("SezonFilter")->AsInteger = sezonFilter;
		FDQuery->ParamByName("OkazjaFilter")->AsInteger = okazjaFilter;
		FDQuery->ParamByName("Offset")->AsInteger = dispId;
		FDQuery->ParamByName("UserLabel")->AsString = userText;

		FDQuery->Open();

		//usuwanie
		for (int i = this->Children->Count - 1; i >= 0; i--) {
			TImage *image = dynamic_cast<TImage*>(this->Children->Items[i]);
			if (image && (image->Tag != -1)) {
				delete image; //je�eli Tag jest inny ni� -1 usuwamy obraz /icone
			}
		}

		int index = 0;
		while (!FDQuery->Eof && index < 8) {
            int id = FDQuery->FieldByName("ID")->AsInteger;
			int sezon = FDQuery->FieldByName("SEZON")->AsInteger;
			int okazja = FDQuery->FieldByName("OKAZJA")->AsInteger;
			TBlobField *blobField = dynamic_cast<TBlobField*>(FDQuery->FieldByName("PIC"));

			if (blobField != nullptr) {
				String tempFile = System::Ioutils::TPath::GetTempFileName() + ".jpg";

				TMemoryStream *blobStream = new TMemoryStream();
				try {
					blobField->SaveToStream(blobStream);
					blobStream->SaveToFile(tempFile);
				} __finally {
					delete blobStream;
				}

				int row = index / maxImagesPerRow;
				int col = index % maxImagesPerRow;

				int posX = galleryStartX + col * (imageWidth + horizontalSpacing);
	        	int posY = galleryStartY + row * (imageHeight + verticalSpacing);

				icon = new TImage(this);
				icon->Parent = this;
				icon->Position->X = posX;
				icon->Position->Y = posY;
				icon->Width = imageWidth;
				icon->Height = imageHeight;
				icon->WrapMode = TImageWrapMode::Fit;
				icon->Bitmap->LoadFromFile(tempFile);
				icon->BringToFront();
				icon->Tag = id;
				icon->OnClick = ImageClick;

				//dodawanie obraz do mapy
				imageMap[id] = tempFile;

				//icony dla sezon�w
				int iconPosX = icon->Position->X + iconMargin;
				int iconPosY = icon->Position->Y + iconMargin;

				int iconOffsetY = 0; //przesuni�cie dla ka�dego obrazu resetuj� do 0

				if (sezon & 1) {
				  AddIcon(iconPosX, iconPosY + iconOffsetY, "C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\spring.png", icon, id); // Wiosna
				 iconOffsetY += 24;
				}
				if (sezon & 2) {
				 AddIcon(iconPosX, iconPosY + iconOffsetY, "C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\summer.jpg", icon, id); // Lato
				 iconOffsetY += 24;
				}
				if (sezon & 4) {
				  AddIcon(iconPosX, iconPosY + iconOffsetY, "C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\fall.jpg", icon, id); // Jesie�
				  iconOffsetY += 24;
				}
				if (sezon & 8) {
				  AddIcon(iconPosX, iconPosY + iconOffsetY, "C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\winter.jpg", icon, id); // Zima
				  iconOffsetY += 24;
				}

				//icony dla okazji
				if (okazja & 1) {
				  AddIcon(iconPosX, iconPosY + iconOffsetY, "C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\casual.jpg", icon, id); // Casual
				  iconOffsetY += 24;
				}
				if (okazja & 2) {
				   AddIcon(iconPosX, iconPosY + iconOffsetY, "C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\blacktie.jpg", icon, id); // Black Tie
				  iconOffsetY += 24;
				}
				if (okazja & 4) {
				   AddIcon(iconPosX, iconPosY + iconOffsetY, "C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\party.jpg", icon, id); // Party
				  iconOffsetY += 24;
				}
				if (okazja & 8) {
				   AddIcon(iconPosX, iconPosY + iconOffsetY, "C:\\Users\\Jasmina\\Documents\\Embarcadero\\Studio\\pic\\sporty.jpg", icon, id); // Sporty
				   iconOffsetY += 24;
				}

			} else {
				ShowMessage("Kolumna PIC jest pusta lub niepoprawna dla ID: " + IntToStr(id));
			}

			FDQuery->Next();
			index++;
		}

	} catch (Exception &e) {
		ShowMessage("B��d konfiguracji bazy danych: " + e.Message);
	}

	//zwolniamy pami�c
	delete FDQuery;
	delete FDConnection;
}

  void TGalleryFormG::AddIcon(int x, int y, String iconPath, TImage *parent, int id) {
	icon = new TImage(this);
	icon->Parent = this;
	icon->Position->X = x;
	icon->Position->Y = y;
	icon->Width = 20;
	icon->Height = 20;
	icon->WrapMode = TImageWrapMode::Fit;
	icon->Bitmap->LoadFromFile(iconPath);
	icon->Tag = id;
}


void __fastcall TGalleryFormG::ImageClick(TObject *Sender) {
	TImage *image = dynamic_cast<TImage*>(Sender);
	if (image) {
		int id = image->Tag;
		TItemFormG *form = new TItemFormG(this, id);

		if (imageMap.find(id) != imageMap.end()) {
			String imagePath = imageMap[id];

		  	form->LoadImage(imagePath);
			form->Show();
		}
	}
}

void __fastcall TGalleryFormG::addButtonClick(TObject *Sender)
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
			ShowMessage("Nie uda�o si� za�adowa� obrazu.");
		}
	}
	delete OpenDialog;

}

void __fastcall TGalleryFormG::refreshButtonClick(TObject *Sender) {
    LoadImages(sezonFilter, okazjaFilter);
}

void __fastcall TGalleryFormG::menuButtonClick(TObject *Sender) {
	this->Close();
	MenuFormG->Show();
}
void __fastcall TGalleryFormG::FormResize(TObject *Sender)
{
    int screenWidth = this->Width;
    int screenHeight = this->Height;

	nextButton->Position->X = screenWidth - nextButton->Width - 40;
	nextButton->Position->Y = screenHeight - nextButton->Height - 70;

    prevButton->Position->X = 10;
	prevButton->Position->Y = screenHeight - prevButton->Height - 70;

    refreshButton->Position->X = (screenWidth - refreshButton->Width) / 2;
	refreshButton->Position->Y = screenHeight - refreshButton->Height - 70;

    addButton->Position->X = (screenWidth - addButton->Width) / 2 - 120;
	addButton->Position->Y = screenHeight - addButton->Height - 70;

    menuButton->Position->X = (screenWidth - menuButton->Width) / 2 + 120;
    menuButton->Position->Y = screenHeight - menuButton->Height - 70;

    int checkboxY = 40;
    int checkboxSpacing = 120;
    int checkboxX = (screenWidth - 4 * checkboxSpacing) / 2;

    SummerBox->Position->X = checkboxX;
    SummerBox->Position->Y = checkboxY;

    SunImage->Position->X = checkboxX + 20;
    SunImage->Position->Y = checkboxY;

    checkboxX += checkboxSpacing;

    SpringBox->Position->X = checkboxX;
    SpringBox->Position->Y = checkboxY;

    FlowerImage->Position->X = checkboxX + 20;
    FlowerImage->Position->Y = checkboxY;

    checkboxX += checkboxSpacing;

    FallBox->Position->X = checkboxX;
    FallBox->Position->Y = checkboxY;

    LeafImage->Position->X = checkboxX + 20;
    LeafImage->Position->Y = checkboxY;

    checkboxX += checkboxSpacing;

    WinterBox->Position->X = checkboxX;
    WinterBox->Position->Y = checkboxY;

    FlakeImage->Position->X = checkboxX + 20;
    FlakeImage->Position->Y = checkboxY;

    int checkboxY1 = 80;
    int checkboxX1 = (screenWidth - 4 * checkboxSpacing) / 2;

    CasualBox->Position->X = checkboxX1;
    CasualBox->Position->Y = checkboxY1;

    CasualImage->Position->X = checkboxX1 + 20;
    CasualImage->Position->Y = checkboxY1;

    checkboxX1 += checkboxSpacing;

    BlackTieBox->Position->X = checkboxX1;
    BlackTieBox->Position->Y = checkboxY1;

    BlackTieImage->Position->X = checkboxX1 + 20;
    BlackTieImage->Position->Y = checkboxY1;

    checkboxX1 += checkboxSpacing;

    SportyBox->Position->X = checkboxX1;
    SportyBox->Position->Y = checkboxY1;

    SportyImage->Position->X = checkboxX1 + 20;
    SportyImage->Position->Y = checkboxY1;

    checkboxX1 += checkboxSpacing;

    PartyBox->Position->X = checkboxX1;
	PartyBox->Position->Y = checkboxY1;

    PartyImage->Position->X = checkboxX1 + 20;
    PartyImage->Position->Y = checkboxY1;

    LoadImages(sezonFilter, okazjaFilter);
}





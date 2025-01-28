//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("RegisterForm_G.cpp", RegisterFormG);
USEFORM("MenuForm_G.cpp", MenuFormG);
USEFORM("GalleryForm_G.cpp", GalleryFormG);
USEFORM("ItemForm_G.cpp", ItemFormG);
USEFORM("LoginForm_G.cpp", LoginFormG);
USEFORM("ImageForm_G.cpp", ImageFormG);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TLoginFormG), &LoginFormG);
		Application->CreateForm(__classid(TRegisterFormG), &RegisterFormG);
		Application->CreateForm(__classid(TMenuFormG), &MenuFormG);
		Application->CreateForm(__classid(TGalleryFormG), &GalleryFormG);
		Application->CreateForm(__classid(TItemFormG), &ItemFormG);
		Application->CreateForm(__classid(TImageFormG), &ImageFormG);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

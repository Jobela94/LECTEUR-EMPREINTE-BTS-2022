//---------------------------------------------------------------------------

#ifndef FingerPrintAppH
#define FingerPrintAppH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TLabel *Label1;
	TButton *btnOuvrir;
	TEdit *textResultat;
	TButton *btnRegisterFigner;
	TButton *Button4;
	TLabel *numéro;
	TPanel *Panel1;
	TButton *btnFermer;
	TButton *btnEnvoyer;
	TButton *btnLedOff;
	TButton *btnGetImage;
	TButton *btnCancel;
	TComboBox *btnID;
	TButton *btnTest;
	TButton *Button1;
	void __fastcall btnOuvrirClick(TObject *Sender);
	void __fastcall btnFermerClick(TObject *Sender);
	void __fastcall btnEnvoyerClick(TObject *Sender);
	void __fastcall btnRegisterFignerClick(TObject *Sender);
	void __fastcall btnLedOffClick(TObject *Sender);
	void __fastcall btnGetImageClick(TObject *Sender);
	void __fastcall btnTestClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// Déclarations utilisateur
public:
	// Déclarations utilisateur
    char nomDuPortSerie;
	__fastcall TTForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTForm1 *TForm1;
//---------------------------------------------------------------------------
#endif

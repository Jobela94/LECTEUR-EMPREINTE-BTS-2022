//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "FingerPrintApp.h"
#include "PortComDI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "comportp.lib"
#pragma resource "*.dfm"
TTForm1 *TForm1;
 Rs232 *PortCom;
//---------------------------------------------------------------------------
__fastcall TTForm1::TTForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TTForm1::btnOuvrirClick(TObject *Sender)
{
	PortCom = new Rs232("COM3");
	  PortCom->configurer(CBR_9600,8,NOPARITY,ONESTOPBIT);


  char trameOPEN[] = {0x55,0xaa,0x01,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x02,0x01}; //Initialisation

   for(int i=0; i<12; i++){

		   PortCom->envoyer(trameOPEN[i]);
				textResultat->Text = "PORT OPEN";

  }

		   for(int i=0; i<12; i++){

				PortCom->recevoir(trameOPEN);

		   }

		PortCom->ouvrir();
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::btnFermerClick(TObject *Sender)
{
	char trameCLOSE[] = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x02,0x01}; //Termination

   for(int i=0; i<12; i++){

		PortCom->envoyer(trameCLOSE[i]);

  }

          for(int i=0; i<12; i++){

				PortCom->recevoir(trameCLOSE);

		  }


	PortCom->fermer();
	textResultat->Text = "PORT FERMER";

	delete PortCom;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::btnEnvoyerClick(TObject *Sender)
{
		char trameLedOn[] = {0x55,0xaa,0x01,0x00,0x01,0x00,0x00,0x00,0x12,0x00,0x13,0x01};
	   //	char reponseLedOn[] = {0x55,0xaa,0x01,0x00,0x01,0x00,0x00,0x00,0x12,0x00,0x13,0x01};   //trame pour allumer la LED
		  char reponse[12];

		 for(int i=0; i<12; i++){

			PortCom->envoyer(trameLedOn[i]);

			 textResultat->Text = "LED ALLUMER";

		 }

			 for(int i=0; i<12; i++){

			  PortCom->recevoir(&reponse[i]);

		 }

}

//---------------------------------------------------------------------------

void __fastcall TTForm1::btnRegisterFignerClick(TObject *Sender){

	String ID = btnID->Text;
	char trameLedOn[] = {0x55,0xaa,0x01,0x00,0x01,0x00,0x00,0x00,0x12,0x00,0x13,0x01};
	char trameLedOff[] = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x12,0x00,0x12,0x01};
	char trameEnrollStart[] = {0x55,0xaa,0x01,0x00,0x01,0x00,0x00,0x00,0x22,0x00,0x23,0x01};
	char trameEnroll1[] = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x23,0x00,0x23,0x01};
	char trameEnroll2[] = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x24,0x00,0x24,0x01};
	char trameEnroll3[] = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x25,0x00,0x25,0x01};
	char trameIsPressFinger[] = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x26,0x00,0x26,0x01};
	char trameCaptureFinger[] = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x60,0x01};

	char reponse[12];
	//char reponseEnrollStart[] = {0x55,0xaa,0x01,0x00,0x01,0x00,0x00,0x00,0x22,0x00,0x23,0x01};

	textResultat->Text = "";

	//Allume la led
	do{
		for(int i=0; i<12; i++){
			PortCom->envoyer(trameLedOn[i]);
		}
		for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
		}
		Sleep(1000);
	}while(reponse[8]!=0x30);

	//textResultat->Text = "Poser votre doigt !";

	 // trame pour le début d'enregistrement
	do{
		for(int i=0; i<12; i++){
		PortCom->envoyer(trameEnrollStart[i]);
		}
				for(int i=0; i<12; i++){
					PortCom->recevoir(&reponse[i]);
				}

		 Sleep(1000);


	}
	while(reponse[8]!=0x30);

	//Verifie si un doigt est present sur le lecteur
	do{
		for(int i=0; i<12; i++){
			PortCom->envoyer(trameIsPressFinger[i]);
		}

		for(int i=0; i<12; i++){
		PortCom->recevoir(&reponse[i]);
		}
		Sleep(1000);
	}while(reponse[4]!=0x00);


	// trame pour le 1er enregistrement
	do{
		for(int i=0; i<12; i++){
		PortCom->envoyer(trameEnroll1[i]);
		}
				for(int i=0; i<12; i++){
				PortCom->recevoir(&reponse[i]);
				}

			  Sleep(1000);

	}while(reponse[8]!=0x30);

	 //Eteindre la led
	do{
		for(int i=0; i<12; i++){
			PortCom->envoyer(trameLedOff[i]);
		}
		for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
		}
		Sleep(1000);
	}while(reponse[8]!=0x30);


	//Verifie si un doigt n'est pas present sur le lecteur
	 do{
			for(int i=0; i<12; i++){
		PortCom->envoyer(trameIsPressFinger[i]);
		}

		for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
		}
	  Sleep(1000);
	}while(reponse[4]==0x00);

	// Allumer LED
	do{
		for(int i=0; i<12; i++){
			PortCom->envoyer(trameLedOn[i]);
		}
		for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
		}
		Sleep(1000);
	}while(reponse[8]!=0x30);


    //Verifie si un doigt est present sur le lecteur
	do{
		for(int i=0; i<12; i++){
			PortCom->envoyer(trameIsPressFinger[i]);
		}

		for(int i=0; i<12; i++){
		PortCom->recevoir(&reponse[i]);
		}
		Sleep(1000);
	}while(reponse[4]!=0x00);


	// trame pour enregistrement
	do{
		for(int i=0; i<12; i++){
		PortCom->envoyer(trameEnroll2[i]);
		}
				for(int i=0; i<12; i++){
				PortCom->recevoir(&reponse[i]);
				}

			  Sleep(1000);

	}while(reponse[8]!=0x30);

	 //Eteindre la led
	do{
		for(int i=0; i<12; i++){
			PortCom->envoyer(trameLedOff[i]);
		}
		for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
		}
		Sleep(1000);
	}while(reponse[8]!=0x30);


	//Verifie si un doigt n'est pas present sur le lecteur
	 do{
			for(int i=0; i<12; i++){
		PortCom->envoyer(trameIsPressFinger[i]);
		}

		for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
		}
	  Sleep(1000);
	}while(reponse[4]==0x00);

	// Allumer LED
	do{
		for(int i=0; i<12; i++){
			PortCom->envoyer(trameLedOn[i]);
		}
		for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
		}
		Sleep(1000);
	}while(reponse[8]!=0x30);

    //Verifie si un doigt est present sur le lecteur
	do{
		for(int i=0; i<12; i++){
			PortCom->envoyer(trameIsPressFinger[i]);
		}

		for(int i=0; i<12; i++){
		PortCom->recevoir(&reponse[i]);
		}
		Sleep(1000);
	}while(reponse[4]!=0x00);


	// trame pour enregistrement
	do{
		for(int i=0; i<12; i++){
		PortCom->envoyer(trameEnroll3[i]);
		}
				for(int i=0; i<12; i++){
				PortCom->recevoir(&reponse[i]);
				}

			  Sleep(1000);

	}while(reponse[8]!=0x30);

	 //Eteindre la led
	do{
		for(int i=0; i<12; i++){
			PortCom->envoyer(trameLedOff[i]);
		}
		for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
		}
		Sleep(1000);
	}while(reponse[8]!=0x30);


	//Verifie si un doigt n'est pas present sur le lecteur
	 do{
			for(int i=0; i<12; i++){
		PortCom->envoyer(trameIsPressFinger[i]);
		}

		for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
		}
	  Sleep(1000);
	}while(reponse[4]==0x00);

	// Allumer LED
	do{
		for(int i=0; i<12; i++){
			PortCom->envoyer(trameLedOff[i]);
		}
		for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
		}
		Sleep(1000);
	}while(reponse[8]!=0x30);
}

//---------------------------------------------------------------------------

void __fastcall TTForm1::btnLedOffClick(TObject *Sender)
{
  char trameLedOff[] = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x12,0x00,0x12,0x01};
  char reponse[12];   // trame led off (éteinte)

		for(int i=0; i<12; i++){

		PortCom->envoyer(trameLedOff[i]);
			textResultat->Text = "LED ETEINTE";
		}

			  for(int i=0; i<12; i++){

				PortCom->recevoir(&reponse[i]);

			}




}
//---------------------------------------------------------------------------

//trame delete id =  55 aa 01 00 01 00 00 00 40 00 41 01

void __fastcall TTForm1::btnGetImageClick(TObject *Sender)
{
	char trameLedOn[] 		  = {0x55,0xaa,0x01,0x00,0x01,0x00,0x00,0x00,0x12,0x00,0x13,0x01};
	char trameGetImage[] 	  = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x63,0x00,0x63,0x01};
	char trameIsPressFinger[] = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x26,0x00,0x26,0x01};
	char trameCaptureFinger[] = {0x55,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x60,0x01};
	char reponse[12];

	do{                                                    //Allume la led
		for(int i=0; i<12; i++){

			PortCom->envoyer(trameLedOn[i]);

		}
			for(int i=0; i<12; i++){
			PortCom->recevoir(&reponse[i]);
			}


		Sleep(1000);


	}while(reponse[8]!=0x30);


				do{                                            //Enregistre l'empreinte
				for(int i=0; i<12; i++){
				PortCom->envoyer(trameCaptureFinger[i]);
				}
						for(int i=0; i<12; i++){
						PortCom->recevoir(&reponse[i]);
						}

					  Sleep(1000);

			}while(reponse[8]!=0x30);



                  	do{                                            //Enregistre l'empreinte
				for(int i=0; i<12; i++){
				PortCom->envoyer(trameGetImage[i]);
				}
						for(int i=0; i<12; i++){
						PortCom->recevoir(&reponse[i]);
						}

					  Sleep(1000);

			}while(reponse[8]!=0x3);




}
//---------------------------------------------------------------------------


void __fastcall TTForm1::btnTestClick(TObject *Sender)
{
	textResultat->Text = "0x"+btnID->Text;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::Button1Click(TObject *Sender)
{
		char trameLedOn[] = {0x55,0xaa,0x01,0x00,0x01,0x00,0x00,0x00,0x12,0x00,0x13,0x01};
		String ID = "0x"+btnID->Text;
		  char reponse[12];

		 for(int i=0; i<12; i++){

			PortCom->envoyer(trameLedOn[i]);

			 textResultat->Text = "LED ALLUMER";

		 }

			 for(int i=0; i<12; i++){

			  PortCom->recevoir(&reponse[i]);

		 }
}
//---------------------------------------------------------------------------


#include "globalVar.h"
#include "lineFunction.h"
#include "wifiFunction.h"

void setup()
{
  Serial.begin(115200);

  connectESP();

  // Assegno l'id al macchinario
  idMachinery = generateIDMachinery();
}




void loop()
{
  switch (stateMachine)
  {
      positionP = positions[stateMachine];
      Serial.println("ciclo");

    case 0:
      if (counter >= 120)
      {
        counter = 0;
        idMachinery = generateIDMachinery();
      }
      positionP = positions[stateMachine];
      //Assegno l'id al prodotto
      idProduct = generateIDProduct();
      pass = true;
      stampaMessaggio();
      sendMessage();
      delay(2000);
      stateMachine = 1; //vai alla postazione successiva
      break;

    case 1:
      positionP = positions[stateMachine];
      if ( random(0, 5000) > 800 )
      {
        Serial.println("Lavorazione OK, passaggio a stazione 2");
        pass = true;
        errorCode = 0;
        stampaMessaggio();
        sendMessage();
        delay(2000);
        stateMachine = 2; //passa a postazione 2
        break;
      }
      else
      {
        pass = false;
        errorCode = generateErrorCode();
        stampaMessaggio();
        sendMessage();
        delay(2000);
      }
      break; //stato1

    case 2:
      positionP = positions[stateMachine];
      if ( random(0, 5000) > 800 )
      {
        Serial.println("Lavorazione OK, passaggio a stazione 3");
        pass = true;
        errorCode = 0;
        stampaMessaggio();
        sendMessage();
        delay(2000);
        stateMachine = 3; //passa a postazione 3
        break;
      }
      else
      {
        pass = false;
        errorCode = generateErrorCode();
        stampaMessaggio();
        sendMessage();
        delay(2000);
      }
      break; //stato2


    case 3:
      positionP = positions[stateMachine];
      if ( random(0, 5000) > 900 )
      {
        Serial.println("Lavorazione OK, attesa uscita pezzo");
        pass = true;
        errorCode = 0;
        stampaMessaggio();
        sendMessage();
        delay(2000);
        stateMachine = 4; //passa a stato 4 per attesa prelievo pezzo
        break;
      }
      else
      {
        pass = false;
        errorCode = generateErrorCode();
        stampaMessaggio();
        sendMessage();
        delay(2000);
      }
      break; //stato3


    case 4:
      positionP = positions[stateMachine];
      Serial.println("Pezzo estratto, caricare un nuovo pezzo");
      counter++;
      pass = true;
      errorCode = 0;
      stampaMessaggio();
      sendMessage();
      delay(5000);
      stateMachine = 0;
      break; //stato4

  }//END SWITCH
}

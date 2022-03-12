#include "globalVar.h"
#include "ledFunction.h"
#include "lineFunction.h"
#include "wifiFunction.h"

void setup() 
{
  Serial.begin(115200);

  Serial.println("Led setup");
  pinMode(ledGreenPos1, OUTPUT);
  pinMode(ledRedPos1, OUTPUT);
  pinMode(ledGreenPos2, OUTPUT);
  pinMode(ledRedPos2, OUTPUT);
  pinMode(ledGreenPos3, OUTPUT);
  pinMode(ledRedPos3, OUTPUT);
  ledOff();


  Serial.println("startButton setup");
  pinMode(startButton, INPUT);

  Serial.println("resetButton setup");
  attachInterrupt(resetButton, resetFunction, RISING);    //interrupt che si attiva ogni volta che lo stato passa da basso ad alto

  Serial.println("Proximity setup");
  pinMode(proximity0, INPUT);
  pinMode(proximity1, INPUT);
  pinMode(proximity2, INPUT);
  pinMode(proximity3, INPUT);
  
  connectESP();

  // Assegno l'id al macchinario
  idMachinery = generateIDMachinery();
}




void loop() 
{
  
  /*
   * Ad ogni stato macchina corrisponde l'avanzamento del pezzo nella linea di montaggio
   */

  currentMillis = millis(); //aggiorno tempo
  switch(stateMachine)
  {
    positionP = positions[stateMachine]; //specifico in quale postazione si trova il pezzo
    
    case 0: //accensione impianto ed attesa caricamento pezzo
      while(digitalRead(startButton) == LOW) //finchè il pulsante non è premuto
      {
        currentMillis = millis(); //aggiorno tempo
        idleStartingState();
        if(digitalRead(startButton) == HIGH && digitalRead(proximity0) == HIGH) //se il pulsante viene premuto e il pezzo è sul nastro
        {
          ledOff(); //spegni tutti i led
          
          //Assegno l'id al prodotto
          idProduct = generateIDProduct();     

          delay(50);
          
          motorON(); //accendi nastri linea
          stateMachine = 1; //vai alla postazione successiva 
          break;
        }
      }
      break;
      

    case 1: //pezzo caricato sta viaggiando sui nastri per arrivare alla postazione 1
      Serial.print(" . ");
      idleStartingState();   

      counter = 0;
      while(digitalRead(proximity1) == HIGH) //finchè il pezzo è presente sulla postazione 1
      {
        currentMillis = millis(); //aggiorno tempo
        motorOFF();
        Serial.println("Pezzo in lavorazioni nella postazione 1");

        if(counter > 5000 || resetState == HIGH) //circa 5 secondi di lavorazione o pulsante RESET premuto
        {
          if((random(0, 5000) > 2000 && flagError == LOW) || resetState == HIGH) //PASS/FAIL casuale o pulsante RESET premuto
          {
            Serial.println("Lavorazione OK, passaggio a stazione 2");
            pass = true;
            errorCode = 0;
            motorON();
            resetState = LOW; //riporto lo stato del pulsante di reset basso
            stateMachine = 2; //passa a postazione 2
            flagError = LOW; //Azzero il flag errori
            delay(2000); //Attendi che il pezzo si sposti dal proximity
            break;
          }
          else 
          {
            pass = false;
            flagError = HIGH;
            errorCode = generateErrorCode();
          }
          counter = 0;
        }
        workstationOne(flagError); //lampeggia i led secondo lo stato di flagError
        counter++;
      }//END while
      break; //stato1
    

    case 2: //il pezzo ha terminato la lavorazione 1 ed ora va nella postazione 2
      workstationOne(flagError);

      counter = 0;

      while(digitalRead(proximity2) == HIGH) //finchè il pezzo è presente sulla postazione 2
      {
        currentMillis = millis(); //aggiorno tempo
        motorOFF();
        Serial.println("Pezzo in lavorazione nella postazione 2");

        if(counter > 5000 || resetState == HIGH) //circa 5 secondi di lavorazione
        {
          if((random(0, 5000) > 2000 && flagError == LOW) || resetState == HIGH) //PASS/FAIL casuale o pulsante RESET premuto
          {
            Serial.println("Lavorazione OK, passaggio a stazione 3");
            pass = true;
            errorCode = 0;
            motorON();
            resetState = LOW; //riporto lo stato del pulsante di reset basso
            stateMachine = 3; //passa a postazione 3
            flagError = LOW; //Azzero il flag errori
            delay(2000); //Attendi che il pezzo si sposti dal proximity
            break;
          }
          else 
          {
            flagError = HIGH;
            pass = false;
            errorCode = generateErrorCode();
          }
          counter = 0;
        }
        workstationTwo(flagError); //lampeggia i led secondo lo stato di flagError
        counter++;       
      }
      break; //stato2
      

    case 3: //il pezzo ha terminato la lavorazione 2 ed ora va nella postazione 3
      workstationTwo(flagError);

      counter = 0;

      while(digitalRead(proximity3) == HIGH) //finchè il pezzo è presente sulla postazione 3
      {
        currentMillis = millis(); //aggiorno tempo
        motorOFF();
        Serial.println("Pezzo in lavorazione nella postazione 3");

        if(counter > 5000 || resetState == HIGH) //circa 5 secondi di lavorazione
        {
          if((random(0, 5000) > 2000 && flagError == LOW) || resetState == HIGH) //PASS/FAIL casuale o pulsante RESET premuto
          {
            Serial.println("Lavorazione OK, attesa uscita pezzo");
            pass = true;
            errorCode = 0;
            motorON();
            resetState = LOW; //riporto lo stato del pulsante di reset basso
            stateMachine = 4; //passa a stato 4 per attesa prelievo pezzo
            flagError = LOW; //Azzero il flag errori
            delay(2000); //Attendi che il pezzo si sposti dal proximity
            break;
          }
          else 
          {
            pass = false;
            flagError = HIGH;
            errorCode = generateErrorCode();
          }
          counter = 0;
        }
        workstationThree(flagError); //lampeggia i led secondo lo stato di flagError
        counter++;       
      }
      break; //stato3


      case 4:
        allLedGreenOn();
        counter = 0;

        while(digitalRead(proximity0) == HIGH) //pezzo prodotto, in attesa di estrazione 
        {
          Serial.println("Estrarre pezzo");
          if(digitalRead(proximity0) == LOW)
          {
            Serial.println("Pezzo estratto, caricare un nuovo pezzo");
            pass = true;
            errorCode = 0;
            stateMachine = 0;
          }
        }
        break; //stato4
  }//END SWITCH
}

/*
 * Libreria per la gestione delle funzioni logiche di gestione della 
 * linea di produzione. Ad esempio:
 * - Gestione pulsanti start/reset
 * - Gestione motori nastri trasportatori 
 * - Lettura/generazione codici prodotto e macchinario
 */

// FUNZIONE PER INTERRUPT

  void resetFunction() 
  {
    flagError = LOW;
    resetState = HIGH;
  }

//*************************************************************************************************

  void motorON()
  {
    Serial.println("Motor ON");
    //do something
  }

//*************************************************************************************************

  void motorOFF()
  {
    Serial.println("Motor OFF");
    //do something
  }

//*************************************************************************************************

  String generateIDMachinery()
  {
    String id = "";

    id = random(0, sizeof(machineries) / sizeof(String));
    return id;
  }

//*************************************************************************************************

 String generateIDProduct()
  {
    String id = "";

    id = random(0, sizeof(products) / sizeof(String));
    return id;
  }

//*************************************************************************************************

  int generateErrorCode()
    {
      int code;
  
      code = random(0, sizeof(errorCodes) / sizeof(int));
      return code;
    }

//*************************************************************************************************


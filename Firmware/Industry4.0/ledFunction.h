/*
 * Libreria per la gestione delle funzioni di comando led
 */


  void idleStartingState()
  {
    if(currentMillis > previousMillis + blinkingTime)
    {
      previousMillis = currentMillis; // Aggiorno ultimo lampeggio
      if (ledState == LOW) 
      {
        ledState = HIGH;
      } 
      else 
      {
        ledState = LOW;
      }
      digitalWrite(ledGreenPos1, ledState);
      digitalWrite(ledRedPos1, ledState);
      digitalWrite(ledGreenPos2, ledState);
      digitalWrite(ledRedPos2, ledState);
      digitalWrite(ledGreenPos3, ledState);
      digitalWrite(ledRedPos3, ledState);
    }
  }

//*************************************************************************************************

  void ledOff()
  {
    digitalWrite(ledGreenPos1, LOW);
    digitalWrite(ledGreenPos2, LOW);
    digitalWrite(ledGreenPos3, LOW);
    digitalWrite(ledRedPos1, LOW);
    digitalWrite(ledRedPos2, LOW);
    digitalWrite(ledRedPos3, LOW);
  }

//*************************************************************************************************

  void allLedGreenOn()
  {
    digitalWrite(ledGreenPos1, HIGH);
    digitalWrite(ledGreenPos2, HIGH);
    digitalWrite(ledGreenPos3, HIGH);
    digitalWrite(ledRedPos1, LOW);
    digitalWrite(ledRedPos2, LOW);
    digitalWrite(ledRedPos3, LOW);
  }

//*************************************************************************************************

  void workstationOne(bool flagError)
  {
    if(currentMillis > previousMillis + blinkingTime)
    {
      previousMillis = currentMillis; // Aggiorno ultimo lampeggio
      if (ledState == LOW) 
      {
        ledState = HIGH;
      } 
      else 
      {
        ledState = LOW;
      }

      if(flagError == HIGH)
      {
        digitalWrite(ledGreenPos1, LOW);
        digitalWrite(ledRedPos1, ledState);
        digitalWrite(ledGreenPos2, ledState);
        digitalWrite(ledGreenPos3, ledState);
      }
      else
      {
        digitalWrite(ledGreenPos1, HIGH);
        digitalWrite(ledGreenPos2, ledState);
        digitalWrite(ledGreenPos3, ledState);
      }
      
    }
  }

//*************************************************************************************************

  void workstationTwo(bool flagError)
  {
    if(currentMillis > previousMillis + blinkingTime)
    {
      previousMillis = currentMillis; // Aggiorno ultimo lampeggio
      if (ledState == LOW) 
      {
        ledState = HIGH;
      } 
      else 
      {
        ledState = LOW;
      }

      if(flagError == HIGH)
      {
        digitalWrite(ledGreenPos1, HIGH);
        digitalWrite(ledGreenPos2, LOW);
        digitalWrite(ledRedPos2, ledState);
        digitalWrite(ledGreenPos3, ledState);
      }
      else
      {
        digitalWrite(ledGreenPos1, HIGH);
        digitalWrite(ledGreenPos2, HIGH);
        digitalWrite(ledGreenPos3, ledState);
      }
      
    }
  }

//*************************************************************************************************


  void workstationThree(bool flagError)
  {
    if(currentMillis > previousMillis + blinkingTime)
    {
      previousMillis = currentMillis; // Aggiorno ultimo lampeggio
      if (ledState == LOW) 
      {
        ledState = HIGH;
      } 
      else 
      {
        ledState = LOW;
      }

      if(flagError == HIGH)
      {
        digitalWrite(ledGreenPos1, HIGH);
        digitalWrite(ledGreenPos2, HIGH);
        digitalWrite(ledGreenPos3, LOW);
        digitalWrite(ledRedPos3, ledState);
      }
      else
      {
        digitalWrite(ledGreenPos1, HIGH);
        digitalWrite(ledGreenPos2, HIGH);
        digitalWrite(ledGreenPos3, HIGH);
      }
      
    }
  }
  

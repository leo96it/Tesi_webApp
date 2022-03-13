
/*
   Libreria per la gestione del WiFi a bordo macchina. Tra cui:
   - Connessione al WiFi
   - Invio messaggi HTTP
*/

#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

HTTPClient http;


void connectESP()
{
  Serial.println("WiFi setup");
  WiFi.mode(WIFI_STA); //imposto il wifi

  Serial.println("");
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void sendMessage()
{
  String json;
  if (WiFi.status() == WL_CONNECTED)
  {
    http.begin(serverURL); //apro una conessione di tipo http
    Serial.println("Apro connessione HTTP");

    http.addHeader("Content-Type", "application/json"); //specifico il tipo di file da inviare

    StaticJsonDocument<256> doc;
    doc["idMachinery"] = idMachinery;
    doc["idProduct"] = idProduct;
    doc["position"] = positionP;
    doc["status"] = pass;
    doc["errorCode"] = errorCode;

    // Trasformo i dati in formato JSON
    serializeJson(doc, json);
    
    int httpResponseCode = http.POST(json);
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    Serial.print("HTTP payload: ");
    Serial.println(http.getString());

    Serial.println("Chiudo connessione HTTP");
    Serial.println("-------");
    http.end(); //chiudo la connessione
  }
}




void stampaMessaggio()
{
  Serial.println("---------------------------");
  Serial.print(idMachinery); Serial.print(", ");
  Serial.print(idProduct); Serial.print(", ");
  Serial.print(positionP); Serial.print(", ");
  Serial.print(pass); Serial.print(", ");
  Serial.println(errorCode);
}


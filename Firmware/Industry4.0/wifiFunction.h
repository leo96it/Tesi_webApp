
/*
 * Libreria per la gestione del WiFi a bordo macchina. Tra cui:
 * - Connessione al WiFi 
 * - Invio messaggi HTTP
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
  if(WiFi.status() == WL_CONNECTED)
  {
    //Apro una conessione di tipo HTTP tramite l'url del server
    http.begin(serverURL); 
    Serial.println("Apro connessione HTTP");

    //Specifico il tipo di file da inviare nell'header
    http.addHeader("Content-Type", "application/json"); 

    //Trasformo i dati in formato JSON
    StaticJsonDocument<256> doc;
    doc["idMachinery"] = idMachinery;
    doc["idProduct"] = idProduct;    
    doc["position"] = positionP; 
    doc["status"] = pass;
    doc["errorCode"] = errorCode;
    
    serializeJson(doc, json);

    //Effettuo la chiamata POST al server e stampo la risposta
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


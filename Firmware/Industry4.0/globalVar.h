
/*
 * Dichiarazione delle variabili globali
 */

#define ledGreenPos1    34
#define ledRedPos1      35

#define ledGreenPos2    32
#define ledRedPos2      33

#define ledGreenPos3    25
#define ledRedPos3      26

#define startButton     22
#define resetButton     23

#define proximity0      21
#define proximity1      19
#define proximity2      18
#define proximity3      5

#define motor           13

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
int counter = 0; //contatore per tempo lavorazione pezzo

int blinkingTime = 200;
bool ledState = LOW; //flag per imporre lo stato ai led
bool flagError = LOW; //flag che segnala la presenza di errori lavorazione
bool resetState = LOW; //flag che segnala se il pulsante di reset allarmi è stato premuto

const char* ssid     = "yourSSID";  // -- PUT HERE YOUR WIFI SSID
const char* password = "yourPASSWORD"; // -- PUT HERE YOUR WIFI PASSWORD

int stateMachine = 0; //stato macchina per macchina a stati

/*
 * Indirizzo IP del server, che in questo caso è in locale sul pc, il quale
 * ha indirizzo IP 192.168.1.2, quindi bisogna specificare l'indirizzo IP
 * del pc e la porta sul quale lavora il server (oltre che la route)
 */

const String serverURL = "http://192.168.1.2:3000/produzione/inserisci"; // -- CHANGE IF NECESSARY THE HOST URL

// Dati mockati
String machineries[] = {"#001aude", "#002ufjd", "#003hghj", "#004hkhi", "#005fewe",
                        "#006dewf"};
String products[] = {"#df431", "#kg848", "#dp973", "#qa345", "#lg059",
                     "#ps374", "#oe385"};
String positions[] = {"Station 1: User load / unload",
                      "Station 2: CNC roughing",
                      "Station 3: Protective paint",
                      "Station 4: Laser Labeling"};
int errorCodes[] = {101, 105, 108, 110, 115, 144, 309};

// Variabili per dati da inviare al server
String idMachinery = "";
String idProduct = "";
String positionP = "";
boolean pass = true;
int errorCode = 200;

















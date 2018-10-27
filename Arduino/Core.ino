//#define constantName value
#define lineMenu1 50
#define lineMenu2 84
#define lineMenu3 118
#define lineMenu4 153
#define lineMenu5 186
#define lineMenu6 220
#define lineMenu7 254
#define lineMenu8 288
#define columnMenu1 10
#define columnMenu2 130
#define columnMenu3 250
#define columnMenu4 370
#define columnMenuMiddle 230

//*********** relay *************
#define relay1 1
#define relay2 0
#define relay3 14
#define relay4 15
#define relay5 16
#define relay6 17
#define relay7 18
#define relay8 19
//********************************

//lineMenu8 , columnMenu1
String errorafk;
//********************************
boolean  savedCurrentDayFoodConsumption = true;
boolean gotCurrentDayFoodConsumption = false;
unsigned int CurrentDayFoodConsumption = 0;
String CDFCfiledirectory = "";
boolean  savedCurrentDayWaterConsumption = true;
boolean gotCurrentDayWaterConsumption = false;
unsigned int CurrentDayWaterConsumption = 0;
String CDWCfiledirectory = "";
boolean  savedCurrentDayMortality = true;
boolean gotCurrentDayMortality = false;
unsigned int CurrentDayMortality = 0;
String CDMfiledirectory = "";
//*****************************
//*****************************
boolean fan1state = 0;
boolean fan2state = 0;
boolean fan3state = 0;
boolean fan4state = 0;
boolean fan5state = 0;
byte NumbreOfActiveFans = 0;
byte minimumVentilationcounter = 0;
byte CoolingLevel = 0;
byte controlStage = 0;
float  ApproximativeAirSpeed = 0;
float tempdifference;
byte HeatingLevel = 0;
boolean sendHeatingErrorDone = false;
boolean sendCoolingErrorDone = false;
//*****************************
float averageWeightOfTheDay = 0;

//*****************************
float variation = 0.5;
float Target_HoleTemperature = 0;
float Target_BrooderEdgeTemperature = 0 ;
float Target_BrooderEdgeTemperature2 = 0;
float Target_Humidity ;
int Target_Dark1 = 0 ;
int Target_Dark2 = 0 ;
float Target_AirSpeed = 0;
float Target_VentilationRate = 0;
float Target_AverageWeight = 0;
float Target_CumulativeWeight = 0;
float Target_DailyConsumption = 0;
float Target_CumulativeCosumption = 0;
//*****************************

String getkeypadinputS1 = "";
String getkeypadinputS2 = "";
String getkeypadinputS3 = "";
//****************
boolean newbuildingcreated = false;
boolean   gotbuildingsection = false;
boolean   gotfannumbre = false;
boolean  gotFanCapacity = false;
byte buildingsection = 0;
int   fannumbre = 0;
unsigned int FanCapacity = 0;
//*********************
int   currentBreedAge = 0;
String fileadressMCtD11 = "";
String Menu_ConsultData_Day = "";
boolean newcreated = false;
boolean newdatecreated = false;
boolean newnumbrecreated = false;
boolean createBreedingFileB = false;
unsigned long currentMillis;
unsigned long previousMillis = 0;
unsigned long previousMillisForDataStorage = 0;
unsigned long previousMillisForDataAcquisition = 0;
unsigned long previousMillisForMinimumVentilation = 0;
unsigned long previousMillisForTemperatureAndVentilationControl = 0;
boolean affafk = 0;
boolean firstTimeRun = false;
unsigned int menuIndex = 0;
unsigned int lastmenuIndex = 0;//variable de sélection de menu pour l'interface tactile
unsigned int lastmenuIndexafk = 0;//variable de sélection de menu pour l'interface tactile
char datechar[20] = "0000/00/00 00:00:00";
String settingfiledirectory = "";
String filedirectory = "";
char FolderName[7] = "BCN000";
char filename[10] = "DAY00.TXT";
char filedraw[] = "00000000.TXT";
float CTemp = 0;
float CTemp2 = 0;
float EffTemp = 0;
float CHum = 0;
float CLight = 0;
float CPressure = 1024;
boolean newval = 1;
boolean aff = 0;
char keypressed;
char filex[] = "********";
int filenamepos = 0;
String menu_2param = "";
boolean newinput = 1;
boolean firsttime = true;
float ox , oy ;// graph function
boolean affgraph = 1; // graph function
String currentbreedingnumberstring = "0";
byte currentbreedingnumber = 0;
byte CurrentBreedingDay = 0;
unsigned int currentbreedingnumbre = 0;
String startingday = "0";
String startingnumbre = "0";
unsigned int CurrentNumber = 0;
boolean active = true;
String mode = "";
boolean foodmotorstatus = 0;
boolean lightstatus = 0;
//******************************
#include <MS5611.h>

MS5611 baro;
int32_t MSpressure;
float MSfiltredPressure = 0;
int32_t MStemperature;

/* DEFEINTION BLOCK**************************************************
 *  *****************************************************************
 *  *****************************************************************
 *  *****************************************************************
 *  *****************************************************************/
//defining input const
const int inPinTemperatureHumidity = 12;//digital
const int inPinGass = 0;//
const int inPinLight = A0;//analog
const int inPinFoodAvailability = 0;//
const int inPinFoodLineHeight = 0;//
const int inPinWaterPressure = 0; //
const int inPinWaterLineHeight = 0; //
const int inPinScale = 0; //
//defining output const
const int outPinTemperatureHigh = 0; //
const int outPinTEmperatureLow = 0; //
const int outPinFan1 = relay8; //
const int outPinFan2 = relay7; //
const int outPinFan3 = relay6; //
const int outPinFan4 = 0; //
const int outPinFan5 = 0; //
const int outPinHeatingSystem = 0; //
const int outPinLight = relay4; //
const int outPinFoodMotor = relay5; //
const int outPinFoodHigh = 0; //
const int outPinFoodLow = 0; //
const int outPinWaterPressureHigh = 0; //
const int outPinWaterPressureLow = 0; //
const int outPinWaterLineHeightHigh = 0; //
const int outPinWaterLineHeightLow = 0; //
/* LIBRARIES AND RELATED BLOCK***************************************
 *  *****************************************************************
 *  *****************************************************************
 *  *****************************************************************
 *  *****************************************************************/
#include <Keypad.h>
const byte numRows = 4; //number of rows on the keypad
const byte numCols = 4; //number of columns on the keypad
//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] =  {2, 3, 5, 6}; //Rows 0 to 3
byte colPins[numCols] =  {7, 8, 9, 11}; //Columns 0 to 3
//initializes an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
//************************************************
//tft 3.2---------------------------
#include <TFT_HX8357.h> // Hardware-specific library
TFT_HX8357 tft = TFT_HX8357();       // Invoke custom library
#define TFT_GREY 0x5AEB // New colour
// SD File-------------------
#include <SPI.h>
#include <SD.h>
File myFile;
File webFile;
// Ethernet-------------------
#include <Ethernet.h>
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);
// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);
IPAddress serverweb( 185, 176, 43, 58);
//char serverweb[] = "mmppmmll.getenjoyment.net"; // IMPORTANT: If you are using XAMPP you will have to find out the IP address of your computer and put it here (it is explained in previous article). If you have a web page, enter its address (ie. "www.yourwebpage.com")

// Initialize the Ethernet server library
EthernetClient clientweb;
#define SS_SD_CARD   4
#define SS_ETHERNET 10

// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

byte nextsecond = 0;
DateTime nextday ;
byte nexthour = 0;

// DHT22 temperature and humidity sensor-------------------------------------
// connect dat to digital pin, 5v and ground
#include <DHT.h>;
DHT dht(inPinTemperatureHumidity, 22); //// Initialize DHT sensor for normal 16mhz Arduino
//Variables
// Gass sensor-------------------------------------
// Light sensor-------------------------------------
/*Connect one end of the photocell to 5V, the other end to Analog 0.
  Then connect one end of a 10K resistor from Analog 0 to ground
  Connect LED from pin 11 through a resistor to ground */
int photocellReading;     // the analog reading from the sensor divider


/* FUNCTION BLOCK****************************************************
 *  *****************************************************************
 *  *****************************************************************
 *  *****************************************************************
 *  *****************************************************************/

//**************initialize relays*********************
void stopAllRelays() {
  digitalWrite(relay1, HIGH);
  pinMode(relay1, OUTPUT);
  digitalWrite(relay2, HIGH);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay3, HIGH);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay4, HIGH);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay5, HIGH);
  pinMode(relay5, OUTPUT);
  digitalWrite(relay6, HIGH);
  pinMode(relay6, OUTPUT);
  digitalWrite(relay7, HIGH);
  pinMode(relay7, OUTPUT);
  digitalWrite(relay8, HIGH);
  pinMode(relay8, OUTPUT);
}
//******************************************************

//-----------------------------------
boolean tweeted = true;
#include <Twitter.h>
Twitter twitter("814087408060862464-lH6T08tSeIJEpsIVohD80k7KR8UoCIW");
void tweetsomething(char Tmsg[]) {
  if (!tweeted) {
    //digitalWrite(SS_SD_CARD, HIGH); // SD Card not active
    //digitalWrite(SS_ETHERNET, LOW);  // Ethernet ACTIVE
    if (twitter.post(Tmsg)) {
      // Specify &Serial to output received response to Serial.
      // If no output is required, you can just omit the argument, e.g.
      // int status = twitter.wait();
      int status = twitter.wait(&Serial);
      if (status == 200) {
        Serial.println("OK.");
      } else {
        Serial.print("failed : code ");
        Serial.println(status);
      }
    } else {
      Serial.println("connection failed.");
    }
    //  digitalWrite(SS_ETHERNET, HIGH); // Ethernet not active
    // digitalWrite(SS_SD_CARD, LOW);  // SD Card ACTIVE
    tweeted = true;
  }
}
//-----------------------------------
#define REQ_BUF_SZ   20
char HTTP_req[REQ_BUF_SZ] = {0}; // buffered HTTP request stored as null terminated string
char req_index = 0;

void ethernetCode() {
  // ...
  // digitalWrite(SS_SD_CARD, HIGH); // SD Card not active
  //  digitalWrite(SS_ETHERNET, LOW);  // Ethernet ACTIVE
  // code that sends to the ethernet slave device over SPI
  // using SPI.transfer() etc.


  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (req_index < (REQ_BUF_SZ - 1)) {
          HTTP_req[req_index] = c;          // save HTTP request character
          req_index++;
        }
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          if (StrContains(HTTP_req, "ajax_inputs")) {
            Serial.write("contains ajaxinputs");
            Serial.write(HTTP_req);
            // send rest of HTTP header
            client.println("Content-Type: text/xml");
            client.println("Connection: keep-alive");
            client.println();
            // send XML file containing input states
            XML_response(client);

          } else {  // web page request
            // send rest of HTTP header
            client.println("Content-Type: text/html");
            client.println("Connection: keep-alive");
            client.println();
            webFile = SD.open("ABMS.htm");        // open web page file
            if (webFile) {
              while (webFile.available()) {
                client.write(webFile.read()); // send web page to client
              }
              webFile.close();
            }
            // send web page

          }
          // reset buffer index and all buffer elements to 0
          req_index = 0;
          StrClear(HTTP_req, REQ_BUF_SZ);
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
  //  digitalWrite(SS_ETHERNET, HIGH); // Ethernet not active
  // digitalWrite(SS_SD_CARD, LOW);  // SD Card ACTIVE
  // ...
}
//-----------------------------
void XML_response(EthernetClient cl)
{
  Serial.write("sending xml response");
  cl.print("<?xml version = \"1.0\" ?>");
  cl.print("<inputs>");

  cl.print("<input1>");
  cl.print(CurrentBreedingDay);
  cl.print("</input1>");
  cl.print("<input2>");
  cl.print(CTemp);
  cl.print("</input2>");
  cl.print("<input3>");
  cl.print(CHum);
  cl.print("</input3>");
  cl.print("<input4>");
  cl.print(CPressure);
  cl.print("</input4>");
  cl.print("<input5>");
  cl.print(ApproximativeAirSpeed);
  cl.print("</input5>");
  cl.print("<input6>");
  cl.print(CoolingLevel);
  cl.print("</input6>");
  cl.print("<input7>");
  cl.print(HeatingLevel);
  cl.print("</input7>");
  cl.print("<input8>");
  cl.print(fan1state + fan2state + fan3state + fan4state + fan5state);
  cl.print("</input8>");
  cl.print("<input9>");
  cl.print(CurrentNumber);
  cl.print("</input9>");
  cl.print("<input10>");
  cl.print(Target_AverageWeight);
  cl.print("</input10>");

  cl.print("</inputs>");
}
// sets every element of str to 0 (clears array)
void StrClear(char *str, char length)
{
  for (int i = 0; i < length; i++) {
    str[i] = 0;
  }
}

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind)
{
  char found = 0;
  char index = 0;
  char len;

  len = strlen(str);

  if (strlen(sfind) > len) {
    return 0;
  }
  while (index < len) {
    if (str[index] == sfind[found]) {
      found++;
      if (strlen(sfind) == found) {
        return 1;
      }
    }
    else {
      found = 0;
    }
    index++;
  }

  return 0;
}
//-----------------------------
void getFilename() {

  filename[3] = CurrentBreedingDay / 10 + '0';
  filename[4] = CurrentBreedingDay % 10 + '0';

  return;
}
//-----------------------------------
void getEffectiveTemperature() {
  myFile = SD.open("efftemp.txt");
  if (myFile) {
    while (myFile.available()) {
      myFile.setTimeout(50);
      float ET_fileCTemp = myFile.parseFloat();
      float ET_fileHum = myFile.parseFloat();
      float ET_fileWS = myFile.parseFloat();
      float ET_fileEffTemp = myFile.parseFloat();
      if ((CTemp * 100 >= (ET_fileCTemp - 140)) && (CTemp * 100 <= (ET_fileCTemp + 140)) ) {
        if ((CHum * 100 >= (ET_fileHum - 500)) && (CHum * 100 <= (ET_fileHum + 500))) {
          if ((ApproximativeAirSpeed * 100 >= (ET_fileWS - 25)) && (ApproximativeAirSpeed * 100 <= (ET_fileWS + 25))) {
            EffTemp = ET_fileEffTemp / 100;
            break;
          }
        }
      }
      else {
        EffTemp = CTemp + 1 - 0.5 * ApproximativeAirSpeed;
      }
    }
    myFile.close();
  }
  if (CurrentBreedingDay < 28) {
    EffTemp -= 1.5;
  }
}
//----------------------------------------------
void printTargetParameters() {
  if (!aff) {
    tft.fillRect(0, 36, 480, 320, TFT_BLACK);
    aff = 1;
  }

}
//----------------------------------------------
void SeekParamValue() {
  myFile = SD.open("PARAM.TXT");
  if (myFile) {
    // TFTPrint( "fileparamopeed", 50, 250, 1, 2, TFT_BLACK, TFT_WHITE);
    while (myFile.available()) {
      myFile.setTimeout(10);
      byte SP_Age = myFile.parseInt();
      byte SP_HoleTemperature = myFile.parseInt();
      byte SP_BrooderEdgeTemperature = myFile.parseInt();
      byte SP_BrooderEdgeTemperature2 = myFile.parseInt();
      byte  SP_Humidity = myFile.parseInt();
      byte  SP_Dark1 = myFile.parseInt();
      byte  SP_Dark2 = myFile.parseInt();
      int  SP_AirSpeed = myFile.parseInt();
      int  SP_VentilationRate = myFile.parseInt();
      int  SP_AverageWeight = myFile.parseInt();
      int  SP_CumulativeWeight = myFile.parseInt();
      byte  SP_DailyConsumption = myFile.parseInt();
      int   SP_CumulativeCosumption = myFile.parseInt();
      if (CurrentBreedingDay  == SP_Age ) {
        Target_HoleTemperature = SP_HoleTemperature;
        Target_BrooderEdgeTemperature = SP_BrooderEdgeTemperature ;
        Target_BrooderEdgeTemperature2 = SP_BrooderEdgeTemperature2 ;
        Target_Humidity = SP_Humidity ;
        Target_Dark1 = SP_Dark1 ;
        Target_Dark2 = SP_Dark2 ;
        Target_AirSpeed = SP_AirSpeed ;
        Target_VentilationRate = SP_VentilationRate ;
        Target_AverageWeight = SP_AverageWeight ;
        Target_CumulativeWeight = SP_CumulativeWeight ;
        Target_DailyConsumption = SP_DailyConsumption ;
        Target_CumulativeCosumption = SP_CumulativeCosumption ;
        break;
      }
    }
    myFile.close();
  }


  else {
    // TFTPrint( "fileparamnotttopeed", 50, 250, 1, 2, TFT_BLACK, TFT_WHITE);

  }
}
//----------------------------------------------
float CurrentLightIntensity (int LightSensorPin) {
  return analogRead(LightSensorPin);
}
//----------------------------------------------
float CurrentTemperature (int TemperatureSensorPin) {
  return  (analogRead(TemperatureSensorPin) * 0.48828125);
}
//----------------------------------------------
float CurrentTemperatureDHT22 () {
  return dht.readTemperature();
}
//----------------------------------------------
float CurrentHumidityDHT22 () {
  return dht.readHumidity();
}
//----------------------------------------------
void TFTPrint(String Text, int Txpos, int Typos, byte Font, byte Tsize,  uint16_t BacktxtCol , uint16_t TxtCol) {
  tft.setCursor(Txpos, Typos, Font);
  // Set the font colour to be white with a black background, set text size multiplier to 1
  tft.setTextColor(TxtCol, BacktxtCol);  tft.setTextSize(Tsize);
  // We can now plot text on screen using the "print" class
  int str_len = Text.length() + 1;
  char charBuf[str_len];
  Text.toCharArray(charBuf, 50);
  tft.println(charBuf);
  return;
}
//******************************************************************************************************************************
uint16_t valuePrintColor(float vale, float mini, float maxi) {
  if ((vale <= maxi) && (vale >= mini)) {
    return TFT_GREEN;
  }
  else {
    return TFT_RED;
  }
}
//******************************************************************************************************************************
void drawtime() {
  byte lastsecond = 60;
  DateTime now = rtc.now(); int year = now.year(); int month = now.month(); int day = now.day(); int hour = now.hour(); int minute = now.minute(); int second = now.second();
  if (lastsecond != second)
  {
    datechar[0] = (year / 1000) + '0';
    datechar[1] = (year / 100 ) % 10 + '0';
    datechar[2] = ((year / 10) % 10) + '0';
    datechar[3] = year % 10 + '0';
    datechar[5] = month / 10 + '0';
    datechar[6] = month % 10 + '0';
    datechar[8] = day / 10 + '0';
    datechar[9] = day % 10 + '0';
    datechar[11] = hour / 10 + '0';
    datechar[12] = hour % 10 + '0';
    datechar[14] = minute / 10 + '0';
    datechar[15] = minute % 10 + '0';
    datechar[17] = second / 10 + '0';
    datechar[18] = second % 10 + '0';
    TFTPrint( datechar, 240, 15, 1, 2, TFT_BLACK, TFT_WHITE);
    //TFTPrint(String(FreeRam()), 10, 10, 1, 2, TFT_BLACK, TFT_WHITE);
    lastsecond = second; // Update lastSecond
  }
}
//******************************************************************************************************************************
/*void Menu_index() {

  if (!aff) {
    tft.fillRect(0, 30, 480, 320, TFT_BLACK);
    TFTPrint("Menu Index", 10, 0, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint("Enter choice", 10, 50, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint("Menu 1: Press 1", 10, 100, 2, 2, TFT_BLACK, TFT_RED);
    aff = 1;
  }
  if (keypressed != NO_KEY) {
    if (keypressed == '1') {
      lastmenuIndex = menuIndex;
      menuIndex = 1;
      aff = 0;
    }
    if (keypressed == '2') {
      lastmenuIndex = menuIndex;
      menuIndex = 2;
      aff = 0;
    }
  }
  }*/

//******************************************************************************************************************************
void DrawCurrentParam(float CT, float CH, float CL) {

}
//******************************************************************************************************************************

//******************************************************************************************************************************
void printmenu(byte iback, String stitle, String s1, String s2, String s3, String s4, String s5, String s6, String s7) {
  if (!aff) {
    tft.fillRect(0, 36, 480, 320, TFT_BLACK);
    printtitle(stitle);
    TFTPrint(s1, columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(s2, columnMenu1, lineMenu2, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(s3, columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(s4, columnMenu1, lineMenu4, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(s5, columnMenu1, lineMenu5, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(s6, columnMenu1, lineMenu6, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(s7, columnMenu1, lineMenu7, 2, 2, TFT_BLACK, TFT_RED);
    if ((menuIndex != 777) && (menuIndex != 999)) {
      TFTPrint("0- Back", columnMenu1, 50 + iback * 34, 2, 2, TFT_BLACK, TFT_RED);
    }
    aff = 1;
  }
}


//******************************************************************************************************************************
void Menu_ControlPanel() {// 0

  if (!aff) {
    printmenu(3, "Control Panel", "1- Breeding mode", "2- Breeding cycle", "3- Breeding data", "", "", "", "");
  }

  if (keypressed != NO_KEY) {
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 777;
      aff = 0;
    }
    if (keypressed == '1') {
      lastmenuIndex = menuIndex;
      menuIndex = 1;
      aff = 0;
    }
    if (keypressed == '2') {
      lastmenuIndex = menuIndex;
      menuIndex = 2;
      aff = 0;
    }
    if (keypressed == '3') {
      lastmenuIndex = menuIndex;
      menuIndex = 3;
      aff = 0;
    }
  }
}
//******************************************************************************************************************************
void Menu_SetMode() {//1
  if (!aff) {
    printmenu(2, "Mode", "1- Active", "2- Idle", "", "", "", "", "");
  }
  if (keypressed != NO_KEY) {
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 0;
      aff = 0;
    } if (keypressed == '1') {
      tft.fillRect(0, 150, 480, 220, TFT_BLACK);
      TFTPrint("Active mode selected", columnMenu1, lineMenu5, 2, 2, TFT_BLACK, TFT_RED);
      active = true;
    }
    if (keypressed == '2') {
      tft.fillRect(0, 150, 480, 220, TFT_BLACK);
      TFTPrint("Idle mode selected", columnMenu1, lineMenu5, 2, 2, TFT_BLACK, TFT_RED);
      active = false;
    }
  }
}
//******************************************************************************************************************************

//******************************************************************************************************************************
void Menu_Data() {//3

  printmenu(2, "Data", "1- Store data", "2- Consult data", "", "", "", "", "");

  if (keypressed != NO_KEY) {
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 0;
      aff = 0;
    }
    if (keypressed == '1') {
      lastmenuIndex = menuIndex;
      menuIndex = 31;
      aff = 0;
    }
    if (keypressed == '2') {
      lastmenuIndex = menuIndex;
      menuIndex = 32;
      aff = 0;
    }
  }
}
//******************************************************************************************************************************
void Menu_StoreData() {//31
  printmenu(3, "Store Data", "1- Mortality", "2- Food consumption", "3- Water consumption", "", "", "", "");
  if (keypressed != NO_KEY) {
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 3;
      aff = 0;
    }
    if (keypressed == '1') {
      lastmenuIndex = menuIndex;
      menuIndex = 311;
      aff = 0;
    }
    if (keypressed == '2') {
      lastmenuIndex = menuIndex;
      menuIndex = 312;
      aff = 0;
    }
    if (keypressed == '3') {
      lastmenuIndex = menuIndex;
      menuIndex = 313;
      aff = 0;
    }
  }
}
//*****************************************************************************************************************************
void getCDMfiledirectory() {
  CDMfiledirectory = "";
  CDMfiledirectory += FolderName;
  CDMfiledirectory += '/';
  CDMfiledirectory += "CDM.TXT";
}
//*****************************************************************************************************************************
void saveCDMortality() {
  myFile = SD.open(CDMfiledirectory , FILE_WRITE);
  if (myFile) {

    myFile.print(CurrentBreedingDay);
    Serial.print("Cbd: ");
    Serial.println(CurrentBreedingDay);
    myFile.print(';');
    Serial.print("Cdm: ");
    Serial.println(CurrentDayMortality);
    myFile.print(CurrentDayMortality);
    myFile.println(';');

    myFile.close();
  }

}
//******************************************************************************************************************************
void Menu_StoreData1() {//311

  printmenu(1, "Mortality", "A- Enter current day mortality", "", "", "", "", "", "");
  if (gotCurrentDayMortality) {
    TFTPrint("Mortality : ", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(getkeypadinputS1, columnMenu3, lineMenu3, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("Press 1 to save", columnMenu1, lineMenu4, 2, 2, TFT_BLACK, TFT_RED);
  }

  if (keypressed != NO_KEY) {
    if (keypressed == '0' && !gotCurrentDayMortality) {
      lastmenuIndex = menuIndex;
      menuIndex = 31;
      aff = 0;
    }
    if (keypressed == 'A') {
      if ( !savedCurrentDayMortality) {
        lastmenuIndex = menuIndex;
        menuIndex = 999;
        aff = 0;
      }
      else {
        TFTPrint("Mortality already saved!" + getkeypadinputS1,  columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
      }
    }
    if (keypressed == '1') {
      if (gotCurrentDayMortality) {
        CurrentDayMortality = getkeypadinputS1.toInt();
        getkeypadinputS1 = "";
        saveCDMortality();

        CurrentNumber -= CurrentDayMortality;

        int iiDay = 0;
        int iiHour = 0;
        int iiMinute = 0;
        int iiStartingDay = 0;
        int iiStartingNumbre = 0;
        int iiCurrentNumber = 0;
        myFile = SD.open(settingfiledirectory);
        if (myFile) {
          while (myFile.available()) {
            myFile.setTimeout(50);
            int  iDay = myFile.parseInt();
            int  iHour = myFile.parseInt();
            int  iMinute = myFile.parseInt();
            int  iStartingDay = myFile.parseInt();
            int  iStartingNumbre = myFile.parseInt();
            int  iCurrentNumber = myFile.parseInt();

            if (iCurrentNumber != 0) {
              iiDay = iDay;
              iiHour = iHour;
              iiMinute = iMinute;
              iiStartingDay = iStartingDay;
              iiStartingNumbre = iStartingNumbre;
              iiCurrentNumber = iCurrentNumber;
            }
          }
          myFile.close();
        }
        else {
          TFTPrint("Cannot find ", 10, 200, 2, 2, TFT_BLACK, TFT_RED);
        }
        SD.remove(settingfiledirectory);
        myFile = SD.open(settingfiledirectory, FILE_WRITE);
        if (myFile) {
          // TFTPrint( "file created", 30, 300, 1, 2, TFT_BLACK, TFT_WHITE);
          myFile.print(iiDay);
          myFile.println(';');
          myFile.print(iiHour);
          myFile.println(';');
          myFile.print(iiMinute);
          myFile.println(';');
          myFile.print(iiStartingDay);
          myFile.println(';');
          myFile.print(iiStartingNumbre);
          myFile.println(';');
          myFile.print(CurrentNumber);
          myFile.println(';');
          myFile.close();
          // if the file is available, write to it:
        } else {
          TFTPrint( "error creating file", 250, 150, 1, 2, TFT_BLACK, TFT_WHITE);
        }

        gotCurrentDayMortality = false;
        savedCurrentDayMortality = true;
        TFTPrint("Mortality saved!!!", columnMenu1, lineMenu5, 2, 2, TFT_BLACK, TFT_RED);
      }
    }
    if (keypressed == 'C') {

    }
    if (keypressed == 'D') {

    }
  }
}
//*****************************************************************************************************************************
void getCDFCfiledirectory() {
  CDFCfiledirectory = "";
  CDFCfiledirectory += FolderName;
  CDFCfiledirectory += '/';
  CDFCfiledirectory += "CDFC.TXT";
}
//******************************************************************************************************************************
void saveCDFC() {

  myFile = SD.open(CDFCfiledirectory , FILE_WRITE);
  if (myFile) {
    myFile.print(CurrentBreedingDay);
    myFile.print(';');
    myFile.print(CurrentDayFoodConsumption);
    myFile.println(';');
    myFile.close();
  }
}

//******************************************************************************************************************************
void Menu_StoreData2() {//312

  printmenu(1, "FCons", "A- Enter current day FCons", "", "", "", "", "", "");
  if (gotCurrentDayFoodConsumption) {
    TFTPrint("FCons :", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(getkeypadinputS1, columnMenu3, lineMenu3, 2, 2, TFT_BLACK, TFT_WHITE);

    TFTPrint("Press 1 to save", columnMenu1, lineMenu4, 2, 2, TFT_BLACK, TFT_RED);
  }
  if (keypressed != NO_KEY) {
    if (keypressed == 'A') {
      if (!savedCurrentDayFoodConsumption) {
        lastmenuIndex = menuIndex;
        menuIndex = 999;
        aff = 0;
      }
      else {
        TFTPrint("FCons already saved!" + getkeypadinputS1, columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
      }
    }
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 31;
      aff = 0;
    }
    if (keypressed == '1') {
      if (gotCurrentDayFoodConsumption) {
        CurrentDayFoodConsumption = getkeypadinputS1.toInt();
        getkeypadinputS1 = "";
        saveCDFC();
        gotCurrentDayFoodConsumption = false;
        savedCurrentDayFoodConsumption = true;
        TFTPrint("Food consumption saved!" + getkeypadinputS1,  columnMenu1, lineMenu5, 2, 2, TFT_BLACK, TFT_RED);
      }
    }
  }
}
//*****************************************************************************************************************************
void getCDWCfiledirectory() {
  CDWCfiledirectory = "";
  CDWCfiledirectory += FolderName;
  CDWCfiledirectory += '/';
  CDWCfiledirectory += "CDWC.TXT";
}
//******************************************************************************************************************************
void saveCDWC() {

  myFile = SD.open(CDWCfiledirectory , FILE_WRITE);
  if (myFile) {
    myFile.print(CurrentBreedingDay);
    myFile.print(';');
    myFile.print(CurrentDayWaterConsumption);
    myFile.println(';');
    myFile.close();
  }
}
//******************************************************************************************************************************
void Menu_StoreData3() {//313

  printmenu(1, "WCons", "A- Enter current day WCons", "", "", "", "", "", "");
  if (gotCurrentDayWaterConsumption) {
    TFTPrint("WCons :", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(getkeypadinputS1, columnMenu3, lineMenu3, 2, 2, TFT_BLACK, TFT_WHITE);

    TFTPrint("Press 1 to save", columnMenu1, lineMenu4, 2, 2, TFT_BLACK, TFT_RED);
  }
  if (keypressed != NO_KEY) {
    if (keypressed == 'A') {
      if (!savedCurrentDayWaterConsumption) {
        lastmenuIndex = menuIndex;
        menuIndex = 999;
        aff = 0;
      }
      else {
        TFTPrint("WCons already saved!" + getkeypadinputS1,  columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
      }
    }
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 31;
      aff = 0;
    }
    if (keypressed == '1') {
      if (gotCurrentDayWaterConsumption) {
        CurrentDayWaterConsumption = getkeypadinputS1.toInt();
        getkeypadinputS1 = "";
        saveCDWC();
        gotCurrentDayWaterConsumption = false;
        savedCurrentDayWaterConsumption = true;
        TFTPrint("Water consumption saved!" + getkeypadinputS1, columnMenu1, lineMenu5, 2, 2, TFT_BLACK, TFT_RED);
      }
    }
  }
}
//******************************************************************************************************************************
void Menu_ConsultData() {//32

  printmenu(2, "Consult Data", "1- Consult daily parameters", "2- Consult overall parameters", "", "", "", "", "");

  if (keypressed != NO_KEY) {
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 3;
      aff = 0;
    }
    if (keypressed == '1') {
      lastmenuIndex = menuIndex;
      menuIndex = 321;
      aff = 0;
    }
    if (keypressed == '2') {
      lastmenuIndex = menuIndex;
      menuIndex = 322;
      aff = 0;
    }
  }
}
//******************************************************************************************************************************
void Menu_ConsultData1() {//321

  printmenu(4, "Daily param", "1- Temperature", "2- Relative humidity", "3- Pressure", "4- Air speed", "", "", "");

  if (keypressed != NO_KEY) {
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 32;
      aff = 0;
    }
    if (keypressed == '1') {
      lastmenuIndex = menuIndex;
      menuIndex = 3211;
      aff = 0;
    }
    if (keypressed == '2') {
      lastmenuIndex = menuIndex;
      menuIndex = 3212;
      aff = 0;
    }
    if (keypressed == '3') {
      lastmenuIndex = menuIndex;
      menuIndex = 3213;
      aff = 0;
    }
    if (keypressed == '4') {
      lastmenuIndex = menuIndex;
      menuIndex = 3214;
      aff = 0;
    }
  }
}
//******************************************************************************************************************************
void Menu_ConsultData11() {//3211
  printmenu(1, "Temperature", "A- Day select ", "", "", "", "", "", "");
  if (Menu_ConsultData_Day != "") {

    TFTPrint(Menu_ConsultData_Day, columnMenu1, lineMenu6, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("Press 1 to plot", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);

  }

  if (keypressed != NO_KEY) {
    if (keypressed == '1' && Menu_ConsultData_Day != "") {

      fileadressMCtD11 = "";
      fileadressMCtD11 += FolderName;
      fileadressMCtD11 += "/DAY";
      fileadressMCtD11 += (Menu_ConsultData_Day.toInt() / 10);
      fileadressMCtD11 += (Menu_ConsultData_Day.toInt() % 10);
      fileadressMCtD11 += ".TXT";
      TFTPrint(fileadressMCtD11, 0, 175, 2, 2, TFT_BLACK, TFT_RED);
      drawcurve (1,  fileadressMCtD11, "Temp", "t", "T");
      Menu_ConsultData_Day = "";

    }

    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 321;
      aff = 0;
    }
    if (keypressed == 'A') {
      Menu_ConsultData_Day = "";
      lastmenuIndex = menuIndex;
      menuIndex = 999;
      aff = 0;
    }

  }
}
//******************************************************************************************************************************
void Menu_ConsultData12() {//3212

  printmenu(1, "Humidity", "To choose day, Press A", "", "", "", "", "", "");

  if (Menu_ConsultData_Day != "") {

    TFTPrint(Menu_ConsultData_Day, columnMenu1, lineMenu6, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("Press 1 to plot", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);

  }

  if (keypressed != NO_KEY) {
    if (keypressed == '1' && Menu_ConsultData_Day != "") {

      fileadressMCtD11 = "";
      fileadressMCtD11 += FolderName;
      fileadressMCtD11 += "/DAY";
      fileadressMCtD11 += (Menu_ConsultData_Day.toInt() / 10);
      fileadressMCtD11 += (Menu_ConsultData_Day.toInt() % 10);
      fileadressMCtD11 += ".TXT";
      TFTPrint(fileadressMCtD11, 0, 175, 2, 2, TFT_BLACK, TFT_RED);
      drawcurve (2,  fileadressMCtD11, "Hum", "t", "H");
      Menu_ConsultData_Day = "";

    }

    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 321;
      aff = 0;
    }
    if (keypressed == 'A') {
      Menu_ConsultData_Day = "";
      lastmenuIndex = menuIndex;
      menuIndex = 999;
      aff = 0;
    }

  }
}
//******************************************************************************************************************************
void Menu_ConsultData13() {//3213

  printmenu(1, "Pressure", "To choose day, Press A", "", "", "", "", "", "");

  if (Menu_ConsultData_Day != "") {

    TFTPrint(Menu_ConsultData_Day, columnMenu1, lineMenu6, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("Press 1 to plot", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);

  }

  if (keypressed != NO_KEY) {
    if (keypressed == '1' && Menu_ConsultData_Day != "") {

      fileadressMCtD11 = "";
      fileadressMCtD11 += FolderName;
      fileadressMCtD11 += "/DAY";
      fileadressMCtD11 += (Menu_ConsultData_Day.toInt() / 10);
      fileadressMCtD11 += (Menu_ConsultData_Day.toInt() % 10);
      fileadressMCtD11 += ".TXT";
      TFTPrint(fileadressMCtD11, 0, 175, 2, 2, TFT_BLACK, TFT_RED);
      drawcurve (3,  fileadressMCtD11, "Pressure", "t", "hPa");
      Menu_ConsultData_Day = "";

    }

    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 321;
      aff = 0;
    }
    if (keypressed == 'A') {
      Menu_ConsultData_Day = "";
      lastmenuIndex = menuIndex;
      menuIndex = 999;
      aff = 0;
    }

  }
}
//******************************************************************************************************************************
void Menu_ConsultData14() {//3214

  printmenu(1, "AirSpeed", "To choose day, Press A", "", "", "", "", "", "");

  if (Menu_ConsultData_Day != "") {

    TFTPrint(Menu_ConsultData_Day, columnMenu1, lineMenu6, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("Press 1 to plot", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);

  }

  if (keypressed != NO_KEY) {
    if (keypressed == '1' && Menu_ConsultData_Day != "") {

      fileadressMCtD11 = "";
      fileadressMCtD11 += FolderName;
      fileadressMCtD11 += "/DAY";
      fileadressMCtD11 += (Menu_ConsultData_Day.toInt() / 10);
      fileadressMCtD11 += (Menu_ConsultData_Day.toInt() % 10);
      fileadressMCtD11 += ".TXT";
      TFTPrint(fileadressMCtD11, 0, 175, 2, 2, TFT_BLACK, TFT_RED);
      drawcurve (4,  fileadressMCtD11, "Air.Sp", "t", "m/s");
      Menu_ConsultData_Day = "";

    }

    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 321;
      aff = 0;
    }
    if (keypressed == 'A') {
      Menu_ConsultData_Day = "";
      lastmenuIndex = menuIndex;
      menuIndex = 999;
      aff = 0;
    }

  }
}
//******************************************************************************************************************************

void Menu_ConsultData2() {//322

  printmenu(4, "Overall param", "1- Mortality", "2- Food consumption", "3- Water consumption", "4- Average weight", "", "", "");

  if (keypressed != NO_KEY) {
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 32;
      aff = 0;
    }
    if (keypressed == '1') {
      lastmenuIndex = menuIndex;
      menuIndex = 3221;
      aff = 0;
    }
    if (keypressed == '2') {
      lastmenuIndex = menuIndex;
      menuIndex = 3222;
      aff = 0;
    }
    if (keypressed == '3') {
      lastmenuIndex = menuIndex;
      menuIndex = 3223;
      aff = 0;
    }
    if (keypressed == '4') {
      lastmenuIndex = menuIndex;
      menuIndex = 3224;
      aff = 0;
    }
  }
}
//******************************************************************************************************************************
void Menu_ConsultData21() {//3221

  printmenu(1, "Mortality", "Press 1  to plot", "", "", "", "", "", "");

  if (keypressed != NO_KEY) {
    if (keypressed == '1' ) {
      // TFTPrint(CDMfiledirectory, 0, 175, 2, 2, TFT_BLACK, TFT_RED);
      drawcurveMFCWC (CDMfiledirectory, "Mort.", "t", "n");
    }
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 322;
      aff = 0;
    }
  }
}
//******************************************************************************************************************************
void Menu_ConsultData22() {//3222

  printmenu(1, "Food Cons.", "Press 1  to plot", "", "", "", "", "", "");

  if (keypressed != NO_KEY) {
    if (keypressed == '1' ) {

      // TFTPrint(CDFCfiledirectory, 0, 175, 2, 2, TFT_BLACK, TFT_RED);
      drawcurveMFCWC (CDFCfiledirectory, "FCons.", "t", "Q");
    }


    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 322;
      aff = 0;
    }

  }
}
//******************************************************************************************************************************
void Menu_ConsultData23() {//3223

  printmenu(1, "Water Cons.", "Press 1  to plot", "", "", "", "", "", "");

  if (keypressed != NO_KEY) {
    if (keypressed == '1' ) {

      //  TFTPrint(CDWCfiledirectory, 0, 175, 2, 2, TFT_BLACK, TFT_RED);
      drawcurveMFCWC (CDWCfiledirectory, "WCons.", "t", "Q");
    }


    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 322;
      aff = 0;
    }

  }
}
//******************************************************************************************************************************
void Menu_ConsultData24() {//3224

  printmenu(0, "Av. Weight", "", "", "", "", "", "", "");

  if (keypressed != NO_KEY) {
    if (keypressed == '0') {
      lastmenuIndex = menuIndex;
      menuIndex = 322;
      aff = 0;
    }

  }
}
//******************************************************************************************************************************
void Menu_BuildingSettings() {//666

  printmenu(1, "BuildingSetts", "Enter building parameters", "", "", "", "", "", "");

  if (!gotbuildingsection) {
    TFTPrint("A- Building section", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
  }
  else {
    TFTPrint("Building section : " + String(buildingsection), columnMenu4, lineMenu3, 2, 2, TFT_BLACK, TFT_WHITE);
    if (!gotfannumbre) {
      TFTPrint("A- Fun numbre", columnMenu1, lineMenu4, 2, 2, TFT_BLACK, TFT_RED);
    }
    else {
      TFTPrint("Fan numbre : " + String(fannumbre), columnMenu4, lineMenu4, 2, 2, TFT_BLACK, TFT_WHITE);

      if (!gotFanCapacity) {
        TFTPrint("A- Fun capacity", columnMenu1, lineMenu5, 2, 2, TFT_BLACK, TFT_RED);
      }
      else {
        TFTPrint("Fan capacity : " + String(FanCapacity), columnMenu4, lineMenu5, 2, 2, TFT_BLACK, TFT_WHITE);
      }
    }
  }

  if (gotbuildingsection && gotfannumbre && gotFanCapacity) {
    TFTPrint("Press 1 to save settings", columnMenu1, lineMenu6, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint("", 10, 140, 2, 2, TFT_BLACK, TFT_RED);
    if (keypressed != NO_KEY) {
      if (keypressed = '1') {
        //
        SD.remove("BSETTING.TXT");
        myFile = SD.open("BSETTING.TXT", FILE_WRITE);
        if (myFile) {

          // TFTPrint("BSETTING.TXT created!!", 10, 240, 2, 2, TFT_BLACK, TFT_RED);
          myFile.println(buildingsection);
          myFile.println(fannumbre);
          myFile.println(FanCapacity);


          myFile.close();
        }
        //create building setting file

        gotbuildingsection = false;
        gotfannumbre = false;
        gotFanCapacity = false;
        TFTPrint("Building parameters saved", columnMenu1, lineMenu7, 2, 2, TFT_BLACK, TFT_RED);

        delay(2000);
        aff = 0;
        menuIndex = 2;

      }
    }

  }


  if (keypressed != NO_KEY) {

    if (keypressed == 'A') {

      lastmenuIndex = menuIndex;
      menuIndex = 999;
      aff = 0;


    }
  }
}
//******************************************************************************************************************************
void getkeypadinput() {
  DateTime now = rtc.now(); int year = now.year(); int month = now.month(); int day = now.day(); int hour = now.hour(); int minute = now.minute(); int second = now.second();

  static String keypadinput = "";
  printmenu(4, "Input", "B- Confirm", "C- Backspace", "D- Reset", "A- Back", "", "", "");

  if (newinput) {
    keypadinput = "";
    newinput = 0;
  }
  if (keypressed != NO_KEY) {
    if (keypressed != 'A' && keypressed != 'B' && keypressed != 'C' && keypressed != 'D') {
      keypadinput += keypressed;
    }
    if (keypressed == 'B') {
      switch (lastmenuIndex) {
        case 2:
          if (!newdatecreated) {

            getkeypadinputS1  = keypadinput;
            newdatecreated = true;
          }
          else {
            if (!newnumbrecreated) {
              getkeypadinputS2 = keypadinput;
              newnumbrecreated = true;
            }
          }

          break;
        case 311:
          getkeypadinputS1 = keypadinput;
          gotCurrentDayMortality = true;
          break;
        case 312:
          getkeypadinputS1 = keypadinput;
          gotCurrentDayFoodConsumption = true;
          break;
        case 313:
          getkeypadinputS1 = keypadinput;
          gotCurrentDayWaterConsumption = true;
          break;
        case 3211:
          Menu_ConsultData_Day = keypadinput;
          break;
        case 3212:
          Menu_ConsultData_Day = keypadinput;
          break;
        case 3213:
          Menu_ConsultData_Day = keypadinput;
          break;
        case 3214:
          Menu_ConsultData_Day = keypadinput;
          break;


        case 666:
          if (!gotbuildingsection) {
            buildingsection = keypadinput.toInt();
            gotbuildingsection = true;
          }
          else {
            if (!gotfannumbre) {
              fannumbre = keypadinput.toInt();
              gotfannumbre = true;
            }
            else {
              if (!gotFanCapacity) {
                FanCapacity = keypadinput.toInt();
                gotFanCapacity = true;
              }
            }
          }
          break;
      }
      newinput = 1;
      menuIndex = lastmenuIndex;
      aff = 0;
    }
    if (keypressed == 'C') {//mazeletmatraygletch-tbalbiza  fi blasset padding
      keypadinput.remove(keypadinput.length() - 1);
      tft.fillRect(0, 220, 480, 254, TFT_BLACK);
    }
    if (keypressed == 'D') {//mazeletmatraygletch-tbalbiza  fi blasset padding
      keypadinput = "";
      tft.fillRect(0, 220, 480, 254, TFT_BLACK);
    }
    if (keypressed == 'A') {
      menuIndex = lastmenuIndex;
      aff = 0;
    }
    TFTPrint(keypadinput, columnMenu1, lineMenu6, 2, 2, TFT_BLACK, TFT_WHITE);
  }
}
//******************************************************************************************************************************
void loadlastcycle() {//*************************************************************************************************************************************???w9efthna
  int x = 0;
  myFile = SD.open("LIST.TXT");
  if (myFile) {
    while (myFile.available()) {
      myFile.setTimeout(50);
      int w = myFile.parseInt();
      if (w != 0) {
        x = w;
      }
    }
    myFile.close();
    currentbreedingnumber = x;
    currentbreedingnumberstring = String(x);
  }
  CreateFolder();
  settingfiledirectory = "";
  settingfiledirectory += FolderName;
  settingfiledirectory += '/';
  settingfiledirectory += "SETTING.TXT";
  myFile = SD.open(settingfiledirectory);
  if (myFile) {
    while (myFile.available()) {
      myFile.setTimeout(50);
      int iYear = myFile.parseInt();
      int iMonth = myFile.parseInt();
      int iDay = myFile.parseInt();
      int iStartingDay = myFile.parseInt();
      int iStartingNumbre = myFile.parseInt();
      int iCurrentNumber = myFile.parseInt();

      if (iCurrentNumber != 0) {
        startingday = String(iStartingDay);

        startingnumbre = String(iStartingNumbre);
        CurrentNumber = iCurrentNumber;
        DateTime now = rtc.now(); int year = now.year(); int month = now.month(); int day = now.day(); int hour = now.hour(); int minute = now.minute(); int second = now.second();
        DateTime dt0 (iYear, iMonth, iDay, 0, 0, 0);
        TimeSpan ts = now - dt0;
        CurrentBreedingDay = ts.days() + iStartingDay - 1;
        Serial.println(iStartingDay);
        Serial.println(ts.days());
        Serial.println(CurrentBreedingDay);

        firstTimeRun = true;
      }
    }
    myFile.close();
  }
  else {
    TFTPrint("Cannot find setting.txt", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
  }
  myFile = SD.open("BSETTING.TXT");
  if (myFile) {
    while (myFile.available()) {
      myFile.setTimeout(50);
      int BS_BuildingSection = myFile.parseInt();
      int BS_FanNumbre = myFile.parseInt();
      int BS_FanCapacity = myFile.parseInt();

      if (BS_FanCapacity != 0) {

        buildingsection = BS_BuildingSection;
        fannumbre = BS_FanNumbre;
        FanCapacity = BS_FanCapacity;

      }
    }
    myFile.close();
  }
  else {
    TFTPrint("Cannot find Bsetting.txt", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
  }
  //***********
  getCDMfiledirectory();
  getCDFCfiledirectory();
  getCDWCfiledirectory();
  //*************
}
//******************************************************************************************************************************

void Menu_Cycle() {

  printmenu(1, "Create Menu", "A- Select day", "", "", "", "", "", "");

  if (newdatecreated) {
    TFTPrint("Starting day : ", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(getkeypadinputS1, columnMenu4, lineMenu3, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("A- Select number ", columnMenu1, lineMenu4, 2, 2, TFT_BLACK, TFT_RED);
    //  newdatecreated = false;
  }
  if (newnumbrecreated) {
    TFTPrint("Starting number: ", columnMenu1, lineMenu5, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(getkeypadinputS2, columnMenu4, lineMenu5, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("Press 1 to confirm! ",  columnMenu1, lineMenu6, 2, 2, TFT_BLACK, TFT_RED);
  }
  if (keypressed != NO_KEY) {
    if (!newcreated && newnumbrecreated && newdatecreated) {
      if (keypressed == '1') {
        int x = 0;
        myFile = SD.open("LIST.TXT");
        if (myFile) {
          while (myFile.available()) {
            myFile.setTimeout(50);
            int wwww = myFile.parseInt();
            if (wwww != 0) {
              x = wwww;
            }
          }
          x = x + 1;
          currentbreedingnumber = x;
          currentbreedingnumberstring = String(x);
          myFile.close();
        }
        else {
          TFTPrint("Cannot find LIST.TXT", 10, 200, 2, 2, TFT_BLACK, TFT_RED);
        }
        myFile = SD.open("LIST.TXT", FILE_WRITE);
        if (myFile) {
          // //Serial.println("file oppened to write  ");
          myFile.println(currentbreedingnumberstring + ";");
          myFile.close();
        }
        else {
          TFTPrint("Cannot find LIST.TXT", 10, 200, 2, 2, TFT_BLACK, TFT_RED);
        }
        startingday = getkeypadinputS1;
        startingnumbre = getkeypadinputS2;
        CurrentNumber = startingnumbre.toInt();
        getkeypadinputS1 = "";
        getkeypadinputS2 = "";
        CurrentBreedingDay = startingday.toInt();
        DateTime now = rtc.now(); int year = now.year(); int month = now.month(); int day = now.day(); int hour = now.hour(); int minute = now.minute(); int second = now.second();
        nextday = now ;
        CreateFolder();
        TFTPrint("New breeding cycle created", columnMenu1, lineMenu7, 2, 2, TFT_BLACK, TFT_RED);
        createBreedingFile();
        CurrentBreedingDay -= 1;
        //***********
        savedCurrentDayFoodConsumption = true;
        savedCurrentDayWaterConsumption = true;
        savedCurrentDayMortality = true;
        getCDMfiledirectory();
        getCDFCfiledirectory();
        getCDWCfiledirectory();
        //*************
        newcreated = true;
        newbuildingcreated = true;
      }
    }

    if (keypressed == 'A') {
      lastmenuIndex = menuIndex;
      menuIndex = 999;
      aff = 0;


    }

    if (keypressed == '0') {

      newcreated = false;
      newdatecreated = false;
      newnumbrecreated = false;
      lastmenuIndex = menuIndex;
      menuIndex = 0;
      aff = 0;

    }
  }

}
//******************************************************************************************************************************
void afkmenu() {

  String c1l1 = "Temp.(c):";
  String c1l2 = "Hum.(%) :";
  String c1l3 = "Pr.(hPa) :";
  String c1l4 = "Eff.T(c) :";
  String c1l5 = "B.Day  :";
  String c1l6 = "Heat.lvl:";
  String c1l7 = "Act.fans:";
  String c1l8 = errorafk;
  String c2l1 = String(CTemp);
  String c2l2 = String(CHum);
  String c2l3 = String(CPressure - 3 * NumbreOfActiveFans);
  String c2l4 = String(EffTemp);
  String c2l5 = String(CurrentBreedingDay);
  String c2l6 = String(HeatingLevel);
  String c2l7 = String(NumbreOfActiveFans);
  //String c2l8 =;
  String c3l1 = "T.temp :";
  String c3l2 = "T.hum  :";
  String c3l3 = "T.Pr   :";
  String c3l4 = "MODE   :";
  String c3l5 = "Number:";
  String c3l6 = "Cool.lvl:";
  String c3l7 = "A.Sp(m/s):";
  //String c3l8 =;
  String c4l1 = String(Target_HoleTemperature);
  String c4l2 = String(Target_Humidity);
  String c4l3 = String(CPressure - 0.25 - 3 * NumbreOfActiveFans);
  String c4l4 = mode;
  String c4l5 = String(CurrentNumber);
  String c4l6 = String(CoolingLevel);
  String c4l7 = String(ApproximativeAirSpeed);
  //String c4l8 =;

  if ( active == false ) {
    c2l6 = "-";
    c2l7 = "-";
    c4l6 = "-";

  }


  printmenu(7, "Parameters", "", "", "", "", "", "", "");

  if ( newval == 1) {

    int padding = tft.textWidth("000000", 2);//??????????????
    tft.setTextPadding(padding);

    //col1
    TFTPrint(c1l1 ,    columnMenu1, lineMenu1, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint( c1l2,    columnMenu1, lineMenu2, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c1l3,     columnMenu1, lineMenu3, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c1l4,   columnMenu1, lineMenu4, 1, 2, TFT_BLACK, TFT_WHITE);
    tft.drawLine(10, lineMenu5 - 10, 470, lineMenu5 - 10, TFT_WHITE);
    TFTPrint(c1l5,     columnMenu1, lineMenu5, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c1l6,     columnMenu1, lineMenu6, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c1l7,     columnMenu1, lineMenu7, 1, 2, TFT_BLACK, TFT_WHITE);
    tft.fillRect(0, lineMenu8, 480, lineMenu8, TFT_BLACK);
    TFTPrint(c1l8,     columnMenu1, lineMenu8, 2, 2, TFT_BLACK, TFT_RED);


    //col2
    TFTPrint(c2l1,            columnMenu2, lineMenu1, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint( c2l2,             columnMenu2, lineMenu2, 1, 2, TFT_BLACK, valuePrintColor(CHum, (Target_Humidity - 5), (Target_HoleTemperature + 5)));
    TFTPrint(c2l3,        columnMenu2, lineMenu3, 1, 2, TFT_BLACK, TFT_GREEN);
    TFTPrint( c2l4,        columnMenu2, lineMenu4, 1, 2, TFT_BLACK, valuePrintColor(EffTemp, (Target_HoleTemperature - variation), (Target_HoleTemperature + variation)));
    TFTPrint(c2l5, columnMenu2, lineMenu5, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c2l6,      columnMenu2, lineMenu6, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c2l7, columnMenu2, lineMenu7, 1, 2, TFT_BLACK, TFT_WHITE);

    //col3
    TFTPrint( c3l1,   columnMenu3, lineMenu1, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint( c3l2,   columnMenu3, lineMenu2, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c3l3,    columnMenu3, lineMenu3, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c3l4,    columnMenu3, lineMenu4, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c3l5,    columnMenu3, lineMenu5, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c3l6,   columnMenu3, lineMenu6, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(c3l7,   columnMenu3, lineMenu7, 1, 2, TFT_BLACK, TFT_WHITE);

    //col4
    TFTPrint( c4l1,   columnMenu4, lineMenu1, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint( c4l2,          columnMenu4, lineMenu2, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint(  c4l3,               columnMenu4, lineMenu3, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint( c4l4,            columnMenu4, lineMenu4, 1, 2, TFT_BLACK, TFT_RED);
    TFTPrint( c4l5,            columnMenu4, lineMenu5, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint( c4l6,             columnMenu4, lineMenu6, 1, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint( c4l7,             columnMenu4, lineMenu7, 1, 2, TFT_BLACK, TFT_WHITE);
    newval = 0;
  }
  if (keypressed != NO_KEY) {
    //  affafk = 1;
    newval = 1;
    aff = 0;
    menuIndex = lastmenuIndexafk;
    errorafk = "";

  }
}
//******************************************************************************************************************************
void foodcontroller() {
  boolean tcrt12 = digitalRead(A12);
  boolean tcrt13 = digitalRead(A13);

  if (foodmotorstatus == 0) {
    if (lightstatus == 1) {
      Serial.print("outPinLight: low  ");
      if ((tcrt12 == 1) && ((tcrt13 == 1))) {
        foodmotorstatus = 1;
      }
    }

  } else {
    if (tcrt13 == 0) {
      foodmotorstatus = 0;
    }
  }
  digitalWrite(outPinFoodMotor, !foodmotorstatus);
  Serial.print("12:  ");
  Serial.println( tcrt12);
  Serial.print("13:  ");
  Serial.println( tcrt13);
  Serial.print("motorstats:  ");
  Serial.println( foodmotorstatus);

}
//******************************************************************************************************************************
void  selectMenu2() {
  switch (menuIndex) {
    case 666:
      Menu_BuildingSettings();
      break;
    case 0:
      Menu_ControlPanel(); // 0
      break;
    case 1:
      Menu_SetMode();//1
      break;
    case 2:
      Menu_Cycle(); //2
      break;
    case 3:
      Menu_Data();//3
      break;
    case 31:
      Menu_StoreData();//31
      break;
    case 311:
      Menu_StoreData1();//311
      break;
    case 312:
      Menu_StoreData2();//312
      break;
    case 313:
      Menu_StoreData3();//313
      break;
    case 32:
      Menu_ConsultData();//32
      break;
    case 321:
      Menu_ConsultData1();//321
      break;
    case 3211:
      Menu_ConsultData11();//3211
      break;
    case 3212:
      Menu_ConsultData12();//3212
      break;
    case 3213:
      Menu_ConsultData13();//3213
      break;
    case 3214:
      Menu_ConsultData14();//3214
      break;
    case 322:
      Menu_ConsultData2();//322
      break;
    case 3221:
      Menu_ConsultData21();//3221
      break;
    case 3222:
      Menu_ConsultData22();//3222
      break;
    case 3223:
      Menu_ConsultData23();//3223
      break;
    case 3224:
      Menu_ConsultData24();//3224
      break;
    case 777:
      afkmenu();
      break;
    case 999:
      getkeypadinput();
      break;
    default :
      Menu_ControlPanel();
      break;
  }
}
//******************************************************************************************************************************
void CreateFolder() {
  FolderName[3] = currentbreedingnumber / 100 + '0';
  FolderName[4] = (currentbreedingnumber / 10) % 10 + '0';
  FolderName[5] = currentbreedingnumber % 10 + '0';
  if (!SD.exists(FolderName)) {
    SD.mkdir(FolderName);
  }
}
//******************************************************************************************************************************

void drawcurve (int  prm, String filepx, String  Ctitle, String Xaxis, String Yaxis) {
  tft.fillScreen(TFT_BLACK);
  TFTPrint("Processing data ...", columnMenu2, lineMenu4, 2, 2, TFT_BLACK, TFT_WHITE);
  affgraph = 1;
  int counterdc = 0;
  float valdc = 0;

  float maxv = -32767;//was using integers
  float minv = 32767;
  myFile = SD.open(filepx);
  if (myFile) {
    float zz = 0;
    while (myFile.available()) {
      myFile.setTimeout(10);
      float u1 = myFile.parseFloat();
      float v1 = myFile.parseFloat();
      float x1 = myFile.parseFloat();
      float y1 = myFile.parseFloat();
      float z1 = myFile.parseFloat();
      float w1 = myFile.parseFloat();
      switch (prm) {
        case 1:
          zz = x1; break;
        case 2:
          zz = y1; break;
        case 3:
          zz = z1; break;
        case 4:
          zz = w1; break;
      }
      if (w1 != 0 || x1 != 0 || z1 != 0 || y1 != 0) {
        if ((zz ) > maxv) {
          maxv = (zz );
        }
        if ((zz ) < minv) {
          minv = (zz);
        }
      }

    }
  }
  myFile.close();
  myFile = SD.open(filepx);
  tft.fillScreen(TFT_BLACK);
  if (myFile) {
    float yy = 0;
    while (myFile.available()) {
      myFile.setTimeout(10);
      float u2 = myFile.parseFloat();
      float v2 = myFile.parseFloat();
      float x2 = myFile.parseFloat();
      float y2 = myFile.parseFloat();
      float z2 = myFile.parseFloat();
      float w2 = myFile.parseFloat();
      switch (prm) {
        case 1:
          yy = x2; break;
        case 2:
          yy = y2; break;
        case 3:
          yy = z2; break;
        case 4:
          yy = w2; break;
      }
      float minvm = minv - (maxv - minv) / maxv;
      float maxvm = maxv + (maxv - minv) / maxv;
      float ech = (maxvm - minvm) / 5;
      //(%500
      int itu2 = u2;
      int itv2 = v2;
      valdc += yy;
      if (counterdc % 4 == 0 & (w2 != 0 || x2 != 0 || z2 != 0 || y2 != 0)) {
        valdc /= 4;
        Graph( (itu2 * 60 + itv2) / 4, valdc, 40, 260, 400, 200, 0,  360, 45, minvm, maxvm, ech, Ctitle, Xaxis, Yaxis, TFT_BLUE, TFT_WHITE, TFT_WHITE, TFT_WHITE, TFT_BLACK, affgraph);
        valdc = 0;
      }
      counterdc += 1;
    }
    myFile.close();
  }
  else {
    TFTPrint("can't find " + filepx, columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
  }
}
//******************************************************************************************************************************

void drawcurveMFCWC ( String filepx, String  Ctitle, String Xaxis, String Yaxis) {
  tft.fillScreen(TFT_BLACK);
  affgraph = 1;
  float maxv = -32767;//was using integers
  float minv = 32767;
  myFile = SD.open(filepx);
  if (myFile) {
    int zz = 0;
    while (myFile.available()) {
      myFile.setTimeout(50);
      int w1 = myFile.parseInt();
      int x1 = myFile.parseInt();
      //Serial.print("w1: ");
      //Serial.println(w1);
      //Serial.print("x1: ");
      //Serial.println(x1);
      zz = x1;
      if (!(w1 == 0 && x1 == 0)) {
        if ((zz ) > maxv) {
          maxv = (zz);
        }
        if ((zz ) < minv) {
          minv = (zz );
        }
      }
    }
  }

  myFile.close();
  myFile = SD.open(filepx);
  if (myFile) {
    float yy = 0;
    while (myFile.available()) {
      myFile.setTimeout(50);
      int w2 = myFile.parseInt();
      int x2 = myFile.parseInt();
      //Serial.print("w2: ");
      //Serial.println(w2);
      //Serial.print("x2: ");
      //Serial.println(x2);
      yy = x2;
      int minvm = minv;
      int maxvm = maxv;
      maxvm = maxvm + 1;
      float ech = (maxv + 1 - minv) / 5;
      //  yy=x;
      if (!(w2 == 0 && x2 == 0)) {

        Graph( w2, yy , 40, 260, 400, 200, 0, 60, 10, minvm, maxvm, ech, Ctitle, Xaxis, Yaxis, TFT_BLUE, TFT_WHITE, TFT_WHITE, TFT_WHITE, TFT_BLACK, affgraph);
      }
    }
    myFile.close();
  }
  else {
    TFTPrint("can't find " + filepx, columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
  }
}
//graph fct*****************************************************************************************************************
void Graph( float x, float y, float gx, float gy, float w, float h, float xlo, float xhi, float xinc, float ylo, float yhi, float yinc, String title, String xlabel, String ylabel, uint16_t gcolor, uint16_t acolor, uint16_t pcolor, uint16_t tcolor, uint16_t bcolor, boolean & redraw) {
  float ydiv, xdiv;
  // initialize old x and old y in order to draw the first point of the graph
  // but save the transformed value
  // note my transform funcition is the same as the map function, except the map uses long and we need floats
  //static float ox = (x - xlo) * ( w) / (xhi - xlo) + gx;
  //static float oy = (y - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  float i;
  float temp;
  int rot, newrot;
  if (redraw == true) {
    redraw = false;
    ox = (x - xlo) * ( w) / (xhi - xlo) + gx;
    oy = (y - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
    // draw y scale
    for ( i = ylo; i <= yhi; i += yinc) {
      // compute the transform
      temp =  (i - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
      if (i == 0) {
        tft.drawLine(gx, temp, gx + w, temp, acolor);
      }
      else {
        tft.drawLine(gx, temp, gx + w, temp, gcolor);
      }
      tft.setTextSize(1);
      tft.setTextColor(tcolor, bcolor);
      tft.setCursor(gx - 40, temp);
      // precision is default Arduino--this could really use some format control
      tft.println(i);
    }
    // draw x scale
    float xhi2 = 24;
    float xinc2 = 3;

    if (xhi == 360 && xinc == 45) {
      for (i = xlo; i <= xhi2; i += xinc2) {
        // compute the transform
        temp =  (i - xlo) * ( w) / (xhi2 - xlo) + gx;
        if (i == 0) {
          tft.drawLine(temp, gy, temp, gy - h, acolor);
        }
        else {
          tft.drawLine(temp, gy, temp, gy - h, gcolor);
        }
        tft.setTextSize(1);
        tft.setTextColor(tcolor, bcolor);
        tft.setCursor(temp, gy + 10);
        // precision is default Arduino--this could really use some format control
        tft.println(i);
      }
    }
    else {
      for (i = xlo; i <= xhi; i += xinc) {
        // compute the transform
        temp =  (i - xlo) * ( w) / (xhi - xlo) + gx;
        if (i == 0) {
          tft.drawLine(temp, gy, temp, gy - h, acolor);
        }
        else {
          tft.drawLine(temp, gy, temp, gy - h, gcolor);
        }
        tft.setTextSize(1);
        tft.setTextColor(tcolor, bcolor);
        tft.setCursor(temp, gy + 10);
        // precision is default Arduino--this could really use some format control
        tft.println(i);
      }
    }
    //now draw the labels
    tft.setTextSize(2);
    tft.setTextColor(tcolor, bcolor);
    tft.setCursor(gx , gy - h - 30);
    tft.println(title);
    tft.setTextSize(1);
    tft.setTextColor(acolor, bcolor);
    tft.setCursor(gx , gy + 20);
    tft.println(xlabel);
    tft.setTextSize(1);
    tft.setTextColor(acolor, bcolor);
    tft.setCursor(gx - 30, gy - h - 10);
    tft.println(ylabel);
  }
  //graph drawn now plot the data
  // the entire plotting code are these few lines...
  // recall that ox and oy are initialized as static above
  x =  (x - xlo) * ( w) / (xhi - xlo) + gx;
  y =  (y - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  tft.drawLine(ox, oy, x, y, pcolor);
  tft.drawLine(ox, oy + 1, x, y + 1, pcolor);
  tft.drawLine(ox, oy - 1, x, y - 1, pcolor);
  ox = x;
  oy = y;
}
//*************************************************************************
void sendErrorEmail(String errorText) {
  digitalWrite(SS_SD_CARD, HIGH); // SD Card not active
  digitalWrite(SS_ETHERNET, LOW);  // Ethernet ACTIVE
  clientweb.stop();

  if (clientweb.connect(serverweb, 80)) {

    Serial.print("connected to : ");
    Serial.println(serverweb);
    clientweb.print("GET /error_email.php?"); // This
    clientweb.print("Error="); // This
    clientweb.print(errorText); // And this is what we did in the testing section above. We are making a GET request just like we would from our browser but now with live data from the sensor
    clientweb.println(" HTTP/1.1"); // Part of the GET request
    clientweb.println("Host: mmppmmll.getenjoyment.net"); // IMPORTANT: If you are using XAMPP you will have to find out the IP address of your computer and put it here (it is explained in previous article). If you have a web page, enter its address (ie.Host: "www.yourwebpage.com")
    clientweb.println("Connection: close"); // Part of the GET request telling the server that we are over transmitting the message
    clientweb.println(); // Empty line
    clientweb.println(); // Empty line
    clientweb.stop();    // Closing connection to server
    Serial.println("posted error");

  }

  //digitalWrite(SS_SD_CARD, LOW); // SD Card not active
  // digitalWrite(SS_ETHERNET, HIGH);  // Ethernet ACTIVE
}
//*************************************************************************
void logDataToDB() {
  digitalWrite(SS_SD_CARD, HIGH); // SD Card not active
  digitalWrite(SS_ETHERNET, LOW);  // Ethernet ACTIVE
  clientweb.stop();

  if (clientweb.connect(serverweb, 80)) {

    Serial.print("connected to : ");
    Serial.println(serverweb);
    clientweb.print("GET /store_data.php?"); // This
    clientweb.print("Temperature="); // This
    clientweb.print(CTemp); // And this is what we did in the testing section above. We are making a GET request just like we would from our browser but now with live data from the sensor
    clientweb.print("&Humidity="); // This
    clientweb.print(CHum);
    clientweb.print("&Pressure="); // This
    clientweb.print(CPressure);
    clientweb.print("&AirSpeed="); // This
    clientweb.print(ApproximativeAirSpeed);
    clientweb.print("&CoolingLevel="); // This
    clientweb.print(CoolingLevel);
    clientweb.print("&HeatingLevel="); // This
    clientweb.print(HeatingLevel);
    clientweb.println(" HTTP/1.1"); // Part of the GET request
    clientweb.println("Host: mmppmmll.getenjoyment.net"); // IMPORTANT: If you are using XAMPP you will have to find out the IP address of your computer and put it here (it is explained in previous article). If you have a web page, enter its address (ie.Host: "www.yourwebpage.com")
    clientweb.println("Connection: close"); // Part of the GET request telling the server that we are over transmitting the message
    clientweb.println(); // Empty line
    clientweb.println(); // Empty line
    clientweb.stop();    // Closing connection to server
    Serial.println("postedsomethig");

  }

  //digitalWrite(SS_SD_CARD, LOW); // SD Card not active
  // digitalWrite(SS_ETHERNET, HIGH);  // Ethernet ACTIVE
}
//*************************************************************************
void logDataToSD() {
  DateTime now = rtc.now(); int year = now.year(); int month = now.month(); int day = now.day(); int hour = now.hour(); int minute = now.minute(); int second = now.second();
  File dataFile = SD.open(filedirectory, FILE_WRITE);
  if (dataFile) {
    dataFile.print(hour);
    dataFile.print(';');
    dataFile.print(minute);
    dataFile.print(';');
    dataFile.print(CTemp);
    dataFile.print(';');
    dataFile.print(CHum);
    dataFile.print(';');
    dataFile.print(CPressure);
    dataFile.print(';');
    dataFile.print(ApproximativeAirSpeed);
    dataFile.println(';');
    dataFile.close();
  }
}
//*************************************************************************
void getData() {
  MSpressure = baro.getPressure();
  MStemperature = baro.getTemperature();

  if (MSfiltredPressure != 0) {
    MSfiltredPressure = MSfiltredPressure + 0.1 * (MSpressure - MSfiltredPressure);
  }
  else {
    MSfiltredPressure = MSpressure;          // first reading so enter MSfiltredPressure to reading
  }

  CTemp2 = dht.readTemperature();
  CTemp = MStemperature ;
  CTemp /= 100 ;
  Serial.print("ctemp : ");
  Serial.println(MStemperature);
  Serial.println(CTemp);
  Serial.print("ctemp2 : ");
  Serial.println(CTemp2);


  CHum = dht.readHumidity() - 20;
  CPressure = MSfiltredPressure / 100;
  ApproximativeAirSpeed = (float)((FanCapacity / 3600) * NumbreOfActiveFans) / buildingsection;
  getEffectiveTemperature();
  newval = 1;
}
//*************************************************************************
void createFile() {

  //function call:
  getFilename();
  filedirectory = "";
  filedirectory += FolderName;
  filedirectory += '/';
  filedirectory += filename;
  // TFTPrint( filedirectory, 30, 280, 1, 2, TFT_BLACK, TFT_WHITE);
  File dataFile = SD.open(filedirectory, FILE_WRITE);
  if (dataFile) {
    dataFile.println("Hour;Minute;Temperature;Humidity;Pressure;ApproximativeAirSpeed");
    dataFile.close();
    // if the file is available, write to it:
  } else {
    TFTPrint( "error creating file", columnMenu1, lineMenu1, 1, 2, TFT_BLACK, TFT_WHITE);
  }

}
//*************************************************************************
void SaveUnsavedParams() {
  if (!savedCurrentDayMortality) {
    CurrentDayMortality = 0;
    saveCDMortality();
  }

  if (!savedCurrentDayFoodConsumption) {
    CurrentDayFoodConsumption = 0;
    saveCDFC();
  }


  if (!savedCurrentDayWaterConsumption) {
    CurrentDayWaterConsumption = 0;
    saveCDWC();
  }
}
//*************************************************************************
void createBreedingFile() {
  DateTime now = rtc.now(); int year = now.year(); int month = now.month(); int day = now.day(); int hour = now.hour(); int minute = now.minute(); int second = now.second();

  //function call:
  settingfiledirectory = "";
  settingfiledirectory += FolderName;
  settingfiledirectory += '/';
  settingfiledirectory += "SETTING.TXT";
  //TFTPrint( settingfiledirectory, 30, 280, 1, 2, TFT_BLACK, TFT_WHITE);
  File dataFile = SD.open(settingfiledirectory, FILE_WRITE);
  if (dataFile) {
    // TFTPrint( "file created", 30, 300, 1, 2, TFT_BLACK, TFT_WHITE);
    dataFile.print(year);
    dataFile.println(';');
    dataFile.print(month);
    dataFile.println(';');
    dataFile.print(day);
    dataFile.println(';');
    dataFile.print(startingday);
    dataFile.println(';');
    dataFile.print(startingnumbre);
    dataFile.println(';');
    dataFile.print(startingnumbre);
    dataFile.println(';');
    dataFile.close();
    // if the file is available, write to it:
  } else {
    TFTPrint( "error creating file", columnMenu1, lineMenu1, 1, 2, TFT_BLACK, TFT_WHITE);
  }

}

//*************************************************************************
void printtitle(String title) {
  tft.fillRect(0, 0, 240, 30, TFT_BLACK);
  tft.drawLine(1, 35, 479, 35, TFT_WHITE);
  TFTPrint(title, 10, 1, 2, 2, TFT_BLACK, TFT_RED);
}
//*************************************************************************
void afk() {

  if ((currentMillis - previousMillis) >= 60000 && menuIndex != 777) {
    //    if (affafk) {
    aff = 0;
    // affafk = 0;
    //    }
    lastmenuIndexafk = menuIndex;
    menuIndex = 777;

  }
  if (keypressed != NO_KEY) {
    previousMillis = currentMillis;
  }

}
/* Control BLOCK*****************************************************
 *  *****************************************************************
 *  *****************************************************************
 *  *****************************************************************
 *  *****************************************************************/
void TemperatureAndVentilationController() {

  byte NumbreOfFunToActivateAtFullRateForMinimumVentilation = 0;
  byte NumbreOfFunToActivateAtFullRateForCooling = 0;
  byte NumbreOfFunToActivateAtFullRate = 0;
  int AirNeedPerCycle = 0;
  byte nexttimetocheckcycle = 0;
  int NumbreOfTimeUnitsToActivateLastFan = 0;
  float AirSpeed = 0;
  AirNeedPerCycle = (CurrentNumber * (Target_VentilationRate / 1000) / 12) * 1.1;
  NumbreOfTimeUnitsToActivateLastFan = 1 + (AirNeedPerCycle / (FanCapacity / 12)) % 5; //nb de minute à activer par cycle de 5 min
  NumbreOfFunToActivateAtFullRateForMinimumVentilation = (AirNeedPerCycle / (FanCapacity / 12));
  //TFTPrint("<> "+String(currentMillis - previousMillisForMinimumVentilation), 330, 270, 2, 2, TFT_BLACK, TFT_RED);
  tempdifference = EffTemp - Target_HoleTemperature;

  if ((currentMillis - previousMillisForTemperatureAndVentilationControl) >= 60000) {
    minimumVentilationcounter = (minimumVentilationcounter + 1) % 5;
    if  ( tempdifference > 0.5) {
      if (HeatingLevel > 0) {
        HeatingLevel -= 1;
      }
      else {
        CoolingLevel += 1;
        if (CoolingLevel > 5) {
          if (!sendCoolingErrorDone) {
            sendErrorEmail( "cooling");
            sendCoolingErrorDone = true;
          }
          CoolingLevel = 5;
          errorafk = "Cooling system is unsufficient!";
        }
        else {
          sendCoolingErrorDone = false;
        }
      }
    }

    else {
      if  ( tempdifference < -0.5) {
        if (CoolingLevel > 0) {
          CoolingLevel -= 1;
        }
        else {
          HeatingLevel += 1;
          if (HeatingLevel > 5) {
            if (!sendHeatingErrorDone) {
              sendErrorEmail( "heating");
              sendHeatingErrorDone = true;
            }
            HeatingLevel = 5;
            errorafk = "Heating system is unsufficient!";
          }
          else {
            sendHeatingErrorDone = false;
          }
        }
      }
    }
    previousMillisForTemperatureAndVentilationControl = currentMillis;
  }

  if (NumbreOfFunToActivateAtFullRateForCooling < fannumbre) {
    NumbreOfFunToActivateAtFullRateForCooling = CoolingLevel;
  }


  NumbreOfFunToActivateAtFullRateForMinimumVentilation += NumbreOfTimeUnitsToActivateLastFan > minimumVentilationcounter;
  NumbreOfActiveFans = max(NumbreOfFunToActivateAtFullRateForMinimumVentilation, NumbreOfFunToActivateAtFullRateForCooling);
  switch (NumbreOfActiveFans) {
    default:
      fan1state = 0;
      fan2state = 0;
      fan3state = 0;
      fan4state = 0;
      fan5state = 0;
      break;
    case 0:
      fan1state = 0;
      fan2state = 0;
      fan3state = 0;
      fan4state = 0;
      fan5state = 0;
      break;
    case 1:
      fan1state = 1;
      fan2state = 0;
      fan3state = 0;
      fan4state = 0;
      fan5state = 0;
      break;
    case 2:
      fan1state = 1;
      fan2state = 1;
      fan3state = 0;
      fan4state = 0;
      fan5state = 0;
      break;
    case 3:
      fan1state = 1;
      fan2state = 1;
      fan3state = 1;
      fan4state = 0;
      fan5state = 0;
      break;
    case 4:
      fan1state = 1;
      fan2state = 1;
      fan3state = 1;
      fan4state = 1;
      fan5state = 0;
      break;
    case 5:
      fan1state = 1;
      fan2state = 1;
      fan3state = 1;
      fan4state = 1;
      fan5state = 1;
      break;
  }
  switch (HeatingLevel) {
    case 0 :
      //do something
      break;
    case 1 :
      //do something
      break;
    case 2 :
      //do something
      break;
    case 3 :
      //do something
      break;
    case 4 :
      //do something
      break;
    case 5 :
      //do something
      break;
  }

  digitalWrite(outPinFan1, !fan1state);
  digitalWrite(outPinFan2, !fan2state);
  digitalWrite(outPinFan3, !fan3state);
  /*digitalWrite(outPinFan4, fan4state);
    digitalWrite(outPinFan5, fan5state);///wait for powersupplay for relay

    /* TFTPrint(String(fan1state), 30, 250, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(String(fan2state), 60, 250, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(String(fan3state), 90, 250, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(String(fan4state), 120, 250, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(String(fan5state), 150, 250, 2, 2, TFT_BLACK, TFT_RED);*/



  //  TFTPrint("af " + String(NumbreOfActiveFans), 330, 120, 2, 2, TFT_BLACK, TFT_RED);
  //TFTPrint("fc " + String(FanCapacity), 330, 150, 2, 2, TFT_BLACK, TFT_RED);
  //TFTPrint("bs " + String(buildingsection), 330, 180, 2, 2, TFT_BLACK, TFT_RED);
  //TFTPrint("FR " + String(NumbreOfFunToActivateAtFullRateForMinimumVentilation), 330, 210, 2, 2, TFT_BLACK, TFT_RED);
  //TFTPrint("aas " + String(ApproximativeAirSpeed), 330, 240, 2, 2, TFT_BLACK, TFT_RED);

}
void LightController() {
  DateTime now = rtc.now();  int hour = now.hour();
  if (hour - Target_Dark1  > 0) {
    lightstatus = 1;
  }
  else {
    lightstatus = 0;
  }
  digitalWrite(outPinLight, !lightstatus);
}


/* SETUP BLOCK*******************************************************
*  *****************************************************************
*  *****************************************************************
*  *****************************************************************
*  *****************************************************************/
void setup() {
  stopAllRelays();
  pinMode(A12, INPUT);
  pinMode(A13, INPUT);
  pinMode(SS_SD_CARD, OUTPUT);
  pinMode(SS_ETHERNET, OUTPUT);
  pinMode(53, OUTPUT);
  digitalWrite(SS_SD_CARD, HIGH);  // SD Card not active
  digitalWrite(SS_ETHERNET, LOW); // Ethernet not active
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  //----------------------------------

  boolean keypressedforsetup = false;
  //starting tft----------------------
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  TFTPrint("STARTING...", columnMenu2, lineMenu4, 2, 2, TFT_BLACK, TFT_RED);
  delay(2000);
  tft.fillScreen(TFT_BLACK);
  TFTPrint("AUTOMATIC BROILER MONITORING", columnMenu1, lineMenu2, 2, 2, TFT_BLACK, TFT_RED);

  TFTPrint("SYSTEM", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
  delay(1000);
  TFTPrint("V 0.01.2017", columnMenu1, lineMenu4, 2, 2, TFT_BLACK, TFT_RED);
  delay(1000);
  TFTPrint("by Firas Jribi", columnMenu1, lineMenu5, 2, 2, TFT_BLACK, TFT_RED);
  delay(5000);
  tft.fillScreen(TFT_BLACK);
  //starting ////Serial communication----------------------
  Serial.begin(9600);
  //starting dht--------------
  dht.begin();// DHT22
  //starting rtc--------------
  baro = MS5611();
  baro.begin();

  if (! rtc.begin()) {
    TFTPrint("Couldn't find RTC", columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
    while (1);
  }
  if (! rtc.isrunning()) {
    TFTPrint("RTC is NOT running!", columnMenu1, lineMenu2, 2, 2, TFT_BLACK, TFT_RED);
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  else {
    TFTPrint("RTC is running!", columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
  }

  digitalWrite(SS_ETHERNET, HIGH);
  digitalWrite(SS_SD_CARD, LOW);
  if (!SD.begin(4)) {
    TFTPrint("SD NOT running!", columnMenu1, lineMenu2, 2, 2, TFT_BLACK, TFT_RED);
    return;
  } else {
    TFTPrint("SD is running!", columnMenu1, lineMenu2, 2, 2, TFT_BLACK, TFT_RED);
  }
  tweeted = false;
  //tweetsomething("Starting!!! @fjtheknight_twt");
  delay(2000);
  tft.fillScreen(TFT_BLACK);
  //TFTPrint(String(millis()), columnMenu1, lineMenu6, 2, 2, TFT_BLACK, TFT_RED);
  int setupmillis = millis() + 5000;
  while (millis() < setupmillis) {
    //TFTPrint(String(millis()), 0, 180, 2, 2, TFT_BLACK, TFT_RED);
    if (millis() >= setupmillis - 5000 && millis() < setupmillis - 4000) {
      TFTPrint("SETUP : Press any key before 05 !", columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
    }
    if (millis() >= setupmillis - 4000 && millis() < setupmillis - 3000) {
      TFTPrint("SETUP : Press any key before 04 !", columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
    }
    if (millis() >= setupmillis - 3000 && millis() < setupmillis - 2000) {
      TFTPrint("SETUP : Press any key before 03 !", columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
    }
    if (millis() >= setupmillis - 2000 && millis() < setupmillis - 1000) {
      TFTPrint("SETUP : Press any key before 02 !", columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
    }
    if (millis() >= setupmillis - 1000 && millis() < setupmillis) {
      TFTPrint("SETUP : Press any key before 01 !", columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
    }
    keypressed = myKeypad.getKey();

    if (keypressed != NO_KEY)
    {
      keypressedforsetup = true;
      TFTPrint("Opening SETUP ...", columnMenu1, lineMenu2, 2, 2, TFT_BLACK, TFT_RED);
      delay(2000);
      break;
    }
  }


  if (keypressedforsetup) {
    menuIndex = 666;
    newbuildingcreated = false;
  }
  else {
    loadlastcycle();
    tft.fillScreen(TFT_BLACK);
    TFTPrint("LOADING BUILDING PARAMETERS", columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
    delay(1000);
    TFTPrint("Building section :", columnMenu1, lineMenu2, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(String(buildingsection), columnMenu4, lineMenu2, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("Fan number : ", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(String(fannumbre), columnMenu4, lineMenu3, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("Fan  capacity: ", columnMenu1, lineMenu4, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(String(FanCapacity), columnMenu4, lineMenu4, 2, 2, TFT_BLACK, TFT_WHITE);

    // tweeted = false;
    //tweetsomething("Loading!!! @fjtheknight_twt");
    delay(2000);
    tft.fillScreen(TFT_BLACK);
    TFTPrint("Loading last breeding cycle: ", columnMenu1, lineMenu1, 2, 2, TFT_BLACK, TFT_RED);
    delay(1000);
    TFTPrint("Cycle numbre", columnMenu1, lineMenu2, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(currentbreedingnumberstring, columnMenu4, lineMenu2, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("Starting day : ", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(startingday, columnMenu4, lineMenu3, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("Starting number: ", columnMenu1, lineMenu4, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(startingnumbre, columnMenu4, lineMenu4, 2, 2, TFT_BLACK, TFT_WHITE);
    TFTPrint("current number: ", columnMenu1, lineMenu5, 2, 2, TFT_BLACK, TFT_RED);
    TFTPrint(String(CurrentNumber), columnMenu4, lineMenu5, 2, 2, TFT_BLACK, TFT_WHITE);
    firstTimeRun = true;
    newbuildingcreated = true;
    delay(3000);
    DateTime now = rtc.now(); int year = now.year(); int month = now.month(); int day = now.day(); int hour = now.hour(); int minute = now.minute(); int second = now.second();
    nextday = now ;
  }

  tft.fillScreen(TFT_BLACK);
  previousMillisForDataStorage -= 60000;
  previousMillisForDataAcquisition -= 60000;
  TFTPrint("Starting ETHERNET Connexion...", columnMenu1, lineMenu3, 2, 2, TFT_BLACK, TFT_RED);
  delay(2000);
}
/* LOOP BLOCK********************************************************
 *  *****************************************************************
 *  *****************************************************************
 *  *****************************************************************
 *  *****************************************************************/
void loop() {

  DateTime now = rtc.now();
  keypressed = myKeypad.getKey();

  currentMillis = millis();

  if (newbuildingcreated == true) {
    if (now.day() == nextday.day()) {
      SaveUnsavedParams();
      CurrentBreedingDay++;
      SeekParamValue();
      createFile();

      //********
      savedCurrentDayMortality = false;
      savedCurrentDayFoodConsumption = false;
      savedCurrentDayWaterConsumption = false;
      //***********

      //********
      //tweeted = false;
      /*
        String twt = "";
        twt = "New!!!" + String(CurrentBreedingDay) + " @fjtheknight_twt";
        unsigned int bufSize = twt.length() + 1; //String length + null terminator
        char ret[bufSize];
        twt.toCharArray(ret, bufSize);*/
      //tweetsomething(ret);
      //*******
      nextday = now + TimeSpan(1, 0, 0, 0);
    }
    if ((currentMillis - previousMillisForDataAcquisition) >= 5000) {
      getData();
      previousMillisForDataAcquisition = currentMillis;
    }
    if ((currentMillis - previousMillisForDataStorage) >= 60000) {
      logDataToSD();
      logDataToDB();
      previousMillisForDataStorage = currentMillis;
    }
    if (active == true) {
      mode = "ACTIVE";
      TemperatureAndVentilationController();
      LightController();
      foodcontroller();
    } else {
      mode = "Idle";
      stopAllRelays();

    }

    afk();
    ethernetCode();
  }

  if (menuIndex == 2 || menuIndex == 666) {
    previousMillis = millis();
  }
  if (clientweb.available()) {
    char c = clientweb.read();
    Serial.write(c);
  }
  selectMenu2();
  drawtime();
  delay(50);

}

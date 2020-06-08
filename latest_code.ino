#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
SoftwareSerial mySerial(12, 13);
LiquidCrystal lcd(6,7,8,9,10,11);

#define FAN 5
#define BULB 4
#define DOOR 3
#define WIN 2

boolean fans=false, doors=true, bulbs=false, windows=true, pass=false;
void setup()
{
mySerial.begin(9600); // Setting the baud rate of GSM Module Â 
Serial.begin(9600); // Setting the baud rate of mySerial Monitor (Arduino) //mySerial
delay(100);
pinMode(FAN, OUTPUT);
pinMode(BULB, OUTPUT);
pinMode(DOOR,OUTPUT);
pinMode(WIN,OUTPUT);
  
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("HOME AUTOMATION!");
 delay(1000);
}
void loop() {
  if (Serial.available()>0)
   switch(Serial.read()) 
   {
   case 'x':
   PassCheck();
   break;
   case '1':
   FanOn();
   break;
   case '2':
   FanOff();
   break;
   case '3':
   BulbOn();
   break;
   case '4':
   BulbOff();
   break;
   case '5':
   OpenDoor();
   break;
   case '6':
   CloseDoor();
   break;
   case '7':
   OpenWindow();
   break;
   case '8':
   CloseWindow();
   break;
   case '9':
   DeviceStatus();
   break;
   case '0':
   GetHelp();
   break;
   case 'a':
   TurnAllOn();
   break;
   case 'z':
   TurnAllOff();
   break;
   default:
   mySerial.println("the command you entered is not correct!");
   }
   if (mySerial.available()>0)
   Serial.write(Serial.read()); //mySerial at first
}
 void PassCheck() 
 {
         pass=true;
         mySerial.println("The password you have provided is correct!");
 }
 void FanOn()
{
if (pass==true){
    if (fans==true){
   mySerial.println("The Fan was already On!"); 
  }
  else {  
  digitalWrite(FAN, HIGH);
  fans=true;

  delay(500);
   mySerial.println("Fan turned On!"); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FAN TURNED ON"); 
  delay(500);

    }//every
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
}
void FanOff()

{
if (pass==true){ 
  if (fans==false){
   mySerial.println("The Fan was already Off!"); 
  }
  else {
  digitalWrite(FAN, LOW);
  fans=false;

  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FAN TURNED OFF!"); 
  delay(500);
  mySerial.println("Fan turned off!");
      }
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
}
void TurnAllOn() 

{
if (pass==true){
    if (fans==false && bulbs==false && doors==true && windows==true) {
        OpenDoor(); 
        OpenWindow(); 
        BulbOn();
        FanOn();
        mySerial.println("Everything is done as per you have requested!");
        mySerial.println("please send 0 for help!");  
    }
    else if (fans==false && bulbs==false && doors==true && windows==false) {
        OpenDoor();
        BulbOn();
        FanOff();
        mySerial.println("your window was already unlocked!");
        mySerial.println("please send 0 for help!");
    }
    else if (fans==false && bulbs==false && doors==false && windows==false) {
        BulbOn();
        FanOff();
        mySerial.println("Your door and Window were already unlocked!");
        mySerial.println("please send 0 for help!"); 
    }
    else if (fans==false && bulbs==true && doors==false && windows==false) {
        FanOff();
        mySerial.println("Your door and Window were already unlocked!"); 
        mySerial.println("The light was already On!");
        mySerial.println("please send 0 for help!");
    }
    else if (fans==true && bulbs==true && doors==false && windows==false) {

        mySerial.println("All of your fan and light devices are On!.your Door and Window are also already unlocked!");
        mySerial.println("please send 0 for help!");
    } 
     else {
        OpenDoor();
        BulbOn();
        OpenWindow();
        FanOn();
        mySerial.println("Everything is done as per you have requested!");
        mySerial.println("please send 0 for help!");         
        //i have no idea what to write here let's leave it empty for now ;-)
    }
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }   
}
void TurnAllOff() 

{
if (pass==true){
    if (fans==true && bulbs==true && doors==false && windows==false) {
        CloseDoor();
        CloseWindow();        
        FanOff();
        BulbOff();
        mySerial.println("Everything is done as per you have requested!");
        mySerial.println("please send 0 for help!");          
    }
    else if (fans==true && bulbs==true && doors==false && windows==true) {
        CloseDoor();      
        FanOff();
        BulbOff();
        mySerial.println("your window was already locked!");
        mySerial.println("please send 0 for help!");
    }
    else if (fans==true && bulbs==true && doors==true && windows==true) {
        FanOff();
        BulbOff();
        mySerial.println("Your door and Window were already locked!");
        mySerial.println("please send 0 for help!"); 
    }
    else if (fans==true && bulbs==false && doors==true && windows==true) {
        FanOff();
        mySerial.println("Your door and Window were already locked!"); 
        mySerial.println("The light was already Off!");
        mySerial.println("please send 0 for help!");
    }
    else if (fans==false && bulbs==false && doors==true && windows==true) {
        mySerial.println("All of your fan and light devices are Off!.your Door and Window are also already locked!");
        mySerial.println("please send 0 for help!");
    }
    else {
        CloseDoor();
        CloseWindow();        
        FanOff();
        BulbOff();
        mySerial.println("Everything is done as per you have requested!");
        mySerial.println("please send 0 for help!");
        //i have no idea what to write here let's leave it empty for now ;-)
    }
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
}
void BulbOn()

{
if (pass==true){
    if (bulbs==true){
   mySerial.println("The light was already On!"); 
  }
  else {  
  digitalWrite(BULB, HIGH);
  bulbs=true;

  delay(100);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LIGHT TURNED ON!"); 
  delay(500);
  mySerial.println("Light turned on!");
  }
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
}
void BulbOff()

{
if (pass==true){
  if (bulbs==false){
   mySerial.println("The light was already Off!"); 
  }
  else {  
  digitalWrite(BULB, LOW);
  bulbs=false;

  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LIGHT TURNED OFF"); 
  delay(500);
  mySerial.println("Light turned off!");
  }
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
}

  void OpenDoor()

{
if (pass==true){
    if (doors==false){
  mySerial.println("Your door was already unLocked!");  
  }
  else {
  digitalWrite(DOOR, HIGH);
  doors=false;
  delay(1000);
  digitalWrite(DOOR, LOW);

  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.print("DOOR UNLOCKED!"); 
  delay(500);
  mySerial.println("Your door is unlocked!");
    }
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
}
 
 void CloseDoor()

{
if (pass==true){
  if (doors==true){
  mySerial.println("Your door was already Locked!");   
  }
  else {  
  digitalWrite(DOOR, HIGH);
  doors=true;
  delay(1000);
  digitalWrite(DOOR, LOW);

  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.print("Door Succesfu-");
  delay(500);
  lcd.print("lly LOCKED"); 
  delay(500);
  mySerial.println("Your door is Locked!");
  }
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
}

void OpenWindow()

{
if (pass==true){
    if (windows==false){
   mySerial.println("Your Windodw was already unLocked!"); 
  }
  else {
  digitalWrite(WIN, HIGH);
  windows=false;
  delay(1000);
  digitalWrite(WIN, LOW);
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.print("WINDOW UNLOCKED!"); 
  delay(500);
  mySerial.println("Your window is unlocked!");
  }
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
}

void CloseWindow()

{
if (pass==true){
  if (windows==true){
  mySerial.println("Your window was already Locked!");  
  }
  else {  
  digitalWrite(WIN, HIGH);
  windows=true;
  delay(1000);
  digitalWrite(WIN, LOW);

  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WINDOW LOCKED!");
  delay(500);
  mySerial.println("Your window is locked!");
    }
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
}

void DeviceStatus()

{
if (pass==true){

  delay(500);
  mySerial.print("The fan is ");
  if (fans==true){
    mySerial.println("ON!");
    }
    else if (fans==false){
     mySerial.println("OFF!");
    }
  mySerial.print("The light is ");
  if (bulbs==true){
    mySerial.println("ON!");
    }
    else if (bulbs==false){
     mySerial.println("OFF!");
    }
  mySerial.print("The door is ");
  if (doors==false){
    mySerial.println("OPEN!");
    }
    else if (doors==true){
     mySerial.println("CLOSED!");
    }
  mySerial.print("The windows is ");
  if (windows==false){
    mySerial.println("OPEN!");
    }
    else if (windows==true){
     mySerial.println("CLOSED!");
    }
     //mySerial.println((char)26);
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
}
void GetHelp()

 {
if (pass==true){

  delay(500);
  mySerial.println(" Please use the following command to control your home appliances accordingly.");
  mySerial.println("1) send '1' to turn ON and '2' to turn OFF the fan.");
  mySerial.println("2) send '3' to turn ON and '4' to turn OFF the LIGHT.");
  mySerial.println("3) send '5' to OPEN and '6' to CLOSE the DOOR.");
  mySerial.println("4) send '7' to OPEN and '8' to CLOSE the WINDOW.");
  mySerial.println("5) send '9' to recieve the status of your home appliances.");
  mySerial.println("6) send '0' to recieve help information.");
  mySerial.println("7) send 'a' to turn ON ALL and 'z' to turn OFF ALL of your devices.");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" DEVICE READY ");
  delay(500);
  lcd.print("WAITING FOR CMD!");  
    }
    else {
        mySerial.println("Your password is not correct!");
        mySerial.println("Please fix it or consult your engineer!");
    }
 }

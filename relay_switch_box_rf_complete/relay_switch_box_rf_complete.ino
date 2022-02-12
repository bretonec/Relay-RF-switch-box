#include <RCSwitch.h>

int relay1 = 3;
int relay2 = 4;
int relay3 = 5;
int relay4 = 6;

RCSwitch mySwitch = RCSwitch();

int BUTTON_PIN = A3;
int switchPin1 = A5; 
int BUTTON_PIN2 = A4;
int switchPin3 = 7;
int switchPin4 = 12;

int relay2State = HIGH;   // the current state of relay
int relay4State = HIGH;   // the current state of relay
int lastButtonState;    // the previous state of button
int lastButton2State;    // the previous state of button
int currentButtonState; // the current state of button
int currentButton2State; // the current state of button

void setup(){
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver is on interrupt pin "0" - This is pin 2 on the UNO 
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(switchPin3, INPUT_PULLUP);
  pinMode(switchPin4, INPUT_PULLUP);
  
  
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void loop(){

  
  while(digitalRead(switchPin4) == HIGH){
    lastButtonState    = currentButtonState;      // save the last state
    currentButtonState = digitalRead(BUTTON_PIN); // read new state
    lastButton2State    = currentButton2State;      // save the last state
    currentButton2State = digitalRead(BUTTON_PIN2); // read new state
    
    if (digitalRead(switchPin1) == HIGH){
        digitalWrite(relay1, LOW);
  }
    if (digitalRead(switchPin1) == LOW ){
        digitalWrite(relay1, HIGH);
  }
  if (digitalRead(switchPin3) == HIGH){
        digitalWrite(relay4, LOW);
  }
    if (digitalRead(switchPin3) == LOW){
        digitalWrite(relay4, HIGH);
  }
    if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // toggle state of relay
    relay2State = !relay2State;

    // control relay arccoding to the toggled state
    digitalWrite(relay3, relay2State); 
  }
  if(lastButton2State == HIGH && currentButton2State == LOW) {
    Serial.println("The button is pressed");

    // toggle state of relay
    relay4State = !relay4State;

    // control relay arccoding to the toggled state
    digitalWrite(relay2, relay4State); 
  } 
  
   } 
    


while(digitalRead(switchPin4) == LOW){
  if (mySwitch.available()) // When a code is received...    
{   int value = mySwitch.getReceivedValue(); // Received data is stored under the "value" variable.  
if (value == 0) // If the received data is "0", "Unknown code" is displayed.      
{       
Serial.println("Unbekannter Code");     
}           
else // If the received code is usable, it is sent to the Serial Monitor here.      
  {       
  Serial.print("Processing: ");
  Serial.println( value );
  
  if (value == 5678) //Processing: If the Arduino receives the number "5678", then.. 
    { // Open the program section of the IF command .
    digitalWrite(relay1, LOW); 
    delay (500);  
    } //Close the program section of the IF command.  
  if (value == 5679);
    { 
    digitalWrite(relay1, HIGH); 
    delay (500); //und zwar für 0,5 Sekunden (500 Millisekunden).  
    } 
  } 
  if (value == 5680);
    { 
    digitalWrite(relay2, LOW); 
    delay (500);  
    } 
  if (value == 5681) 
    { 
    digitalWrite(relay2, HIGH); 
    delay (500);
    }        
  if (value == 5682) 
    { 
    digitalWrite(relay3, LOW); 
    delay (500);
    } 
  if (value == 5683) 
    { 
    digitalWrite(relay3, HIGH); 
    delay (500); 
    } 
  if (value == 5684)
    { 
    digitalWrite(relay4, LOW); 
    delay (500); 
    } 
  if (value == 5685) 
    { 
    digitalWrite(relay4, HIGH); 
    delay (500); 
    } //Programmabschnitt des I        
  }   

mySwitch.resetAvailable(); // Hier wird der Empfänger "resettet"   
}
}





  

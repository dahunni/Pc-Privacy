#include <Keyboard.h>
//Reed switch pin
int trigPin = 5;

//LED Pins (change here)
int redLed = 3;
int blueLed = 2;
int greenLed = 4;

//"Button" Pins (change here)
int upBtn = 6;
int dwnBtn = 7;

//parameters

boolean triggered = false;



void setup() {
  pinMode(trigPin, INPUT);
  pinMode(upBtn, INPUT);
  pinMode(dwnBtn, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
   Keyboard.begin();

}

void loop() {

  if(digitalRead(trigPin) == LOW && triggered == false)
  {
    triggered = true;
    keycomb();
 
  }
  if(digitalRead(dwnBtn) == HIGH && digitalRead(trigPin) == HIGH && triggered == true)
  {
    triggered = false;
    undocomb();

  }
  
  if(triggered == true)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  else
  {
    digitalWrite(redLed, LOW);
     digitalWrite(greenLed, HIGH);
  }
  
  
  
}
void keycomb()
{
  
    //Keycomb here!!!:)
    //Example for alt tab +  minimizing all windows (windows key + d) and Teamspeak Muting comb ctrl + alt + m
    
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('d');
    Keyboard.releaseAll();
    delay(100);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('n');
    Keyboard.releaseAll();
  
}
void undocomb()
{
    //INSERT CODE HERE (this code will be executed when you (re)activate the device)
    //reverse the teamspeak mute
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('n');
    Keyboard.releaseAll();
  
}

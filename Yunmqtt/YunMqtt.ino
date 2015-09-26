/*
  YunMQTT Sample 

 This sketch runs a mosquitto engine to evaluate MQTT publisher
 installed on your Yún in folder /usr/bin.
 It publishes the status of Relay switch/LED status to MQTT broker

 It uses Serial to print, so you need to connect your Yún to your
 computer using a USB cable and select the appropriate port from
 the Port menu

 created  25th September 2015
 By Sivakumar 
 */
 
// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int state = HIGH;      // the current state of the output pin
int previous = LOW;    // the previous reading from the input pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flicker

#include <Process.h>

void setup() {
  Serial.begin(9600);  // initialize serial communication
  while (!Serial);     // do nothing until the serial monitor is opened

  Serial.println("Starting bridge...\n");
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();  // make contact with the linux processor
  digitalWrite(13, HIGH);  // Led on pin 13 turns on when the bridge is ready

  delay(2000);  // wait 2 seconds
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  Process mqttPub;  // initialize a new process
  // read the state of the pushbutton value:
  
  buttonState = digitalRead(buttonPin);  
 
    // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH && previous == LOW && millis() - time > debounce) {
       if (state == HIGH)
       {
         state = LOW;
         mqttPub.runShellCommand("/usr/bin/mosquitto_pub -h 192.168.2.5 -t \"spark\" -m \"Light OFF\"");  // command you want to run
       }
          
      else
      {
        state = HIGH;
        mqttPub.runShellCommand("/usr/bin/mosquitto_pub -h 192.168.2.5 -t \"spark\" -m \"Light ON\"");  // command you want to run
      }
      time = millis();
  }
  // turn LED on:
  digitalWrite(ledPin, state);
 
  Serial.println();
  previous = buttonState;
}


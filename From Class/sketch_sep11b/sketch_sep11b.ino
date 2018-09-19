// this is where my variables are
int ledPin = 13;
int knobPin = A0;
int switchPin = 7;

int knobValue = 0;
int knobScaledValue = 0;
int knobMappedValue = 0;

int switchValue = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  // turn on serial communications
  Serial.begin(9600);
}

void loop() {

  switchValue = digitalRead(switchPin);
  Serial.print("Switch: ");
  Serial.println(switchValue);

  knobValue = analogRead(knobPin);
  Serial.print("Knob: ");
  Serial.println(knobValue);

  knobScaledValue = 2*knobValue;
  //Serial.println(knobScaledValue);

  knobMappedValue = map(knobValue, 0, 655, 500, 1500);
  //Serial.println(knobMappedValue);

  if(switchValue == 1) {
    // do something
    Serial.println("switch is on");
    digitalWrite(ledPin, HIGH);
  } else {
    // do the rest 
    if(knobValue > 300) {
      // do this
      Serial.println("above 300");
  
      // put your main code here, to run repeatedly:
      digitalWrite(ledPin, HIGH);
      // send me a message that it's off
      //Serial.println("Turned LED off");
      delay(knobMappedValue); //------------------
    
      knobValue = analogRead(knobPin);
      //Serial.println(knobValue);
    
      knobMappedValue = map(knobValue, 0, 655, 100, 500);
      //Serial.println(knobMappedValue);
    
      digitalWrite(ledPin, LOW); 
      // tell me it turned on the LED
      //Serial.println("Turned LED on");
      delay(knobMappedValue); //------------------
      
    } else {
      // do something else
      Serial.println("below or equal to 300");
    }
    
  }
  
  
}

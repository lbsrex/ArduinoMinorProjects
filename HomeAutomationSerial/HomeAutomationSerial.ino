
 String voice;
int motorPin1 = 4; 	// positve pin on Motor Driver
int motorPin2 = 3; 	// Negative pin on Motor Driver
int enablePin = 5; 	// Enable pin on Motor Driver
int lightPin=6;		//positive pin of LED
int servoPin=7;		
int open=90;
close=0;
Servo Door;

void setup() {
 
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinmode(lightPin,OUTPUT);
    
    digitalWrite(enablePin, HIGH);	// sets enablePin of motor driver to high
    
	Door.attach(servoPin); 		// We need to attach the servo to the used pin number 
    
    Serial.begin(9600);				// initialize serial communication at 9600 bits per second
}

void loop() 
{
  	while (Serial.available())
  	{
  		delay(10);  
  		char c = Serial.read(); 
  		if (c == '#') {break;} 
  		voice += c;
	}  
	if (voice.length() > 0) 
	{
		Serial.println(voice); 
	}
	else if(voice == "*fan on") 
	{
		digitalWrite(motorPin1, HIGH);
		digitalWrite(motorPin2, HIGH);
	} 
	else if(voice == "*fan off") 
	{
		digitalWrite(motorPin2, LOW);
		digitalWrite(motorPin2, LOW);
	}
	else if(voice == "*lights on") 
	{
		digitalWrite(lightPin, HIGH);
	}
	
	else if(voice == "*lights off") 
	{
		digitalWrite(lightPin, LOW);
	}
	voice="";
	
	else if(voice == "*open the door") 
	{
		Door.write(open);
	}
	
	else if(voice == "*close the door") 
	{
		Door.write(close);
	}
}
 

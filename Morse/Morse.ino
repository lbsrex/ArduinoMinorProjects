//Sweeping instaed of staying still


String key[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","1","2","3","4","5","6","7","8","9","0",".",",","?",":",";","-","/","!"};
String Cipher[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----",".-.-.-","--..--","..--..","---...","-.-.-.","-...-","-..-.",".-..-."};


#include <Servo.h>          // Include the Servo library 
int x=0;
int servoPin = 3;           // Declare the Servo pin 
Servo Servo1;               // Create a servo object 

const int motorPin1  = 5;   // Pin 14 of L293
const int motorPin2  = 6;   // Pin 10 of L293

void setup(){
    Servo1.attach(servoPin);//Attach servo object to the pin    //Set Servo to initial position
    Servo1.write(60);
    delay(1000);
    
    pinMode(motorPin1, OUTPUT);//Set pins as outputs
    pinMode(motorPin2, OUTPUT);
    
    //This code  will turn Motor clockwise for 2 sec.
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    
    delay(2000); 
    //This code will turn Motor counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    
    delay(2000);
    
    //And this code will stop motor
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
}
void loop()
{
  x=(x==120)?90:120;
  Servo1.write(x);
  delay(1000);
}

String EnMorse(String Text)
	{
                String Code="";
		int len = Text.length();
		for(int i=0;i<len;i++)
		{
			String ch=(Text.substring(i,i+1));
			System.out.println(ch);
			int index=-1;
			if(!ch.equalsIgnoreCase(" "))
			{
				for(int  j=0;j<key[0].length;j++)
				{
					if(ch.equalsIgnoreCase(key[0][j]))
					{
						index=j;
						break;
					}
				}
				if(index==-1)
				{
					System.out.println("Invalid Input");
					System.exit(0);
				}
				else
				{
					Code=Code+" "+key[1][index];
				}
			}
		}
		return (Code);
	}

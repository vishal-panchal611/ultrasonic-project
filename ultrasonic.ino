/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* This file was made by 
*   Vishal Panchal
*/
const int block1 = 2;
const int block2 = 3;
const int block3 = 4;
const int block4 = 5;
const int sign = 6;

// defines pins numbers
const int trigPin_1 = 9;
const int echoPin_1 = 10;
const int trigPin_2 = 7;
const int echoPin_2 = 8;

// defines variables
long duration1;
int distance1;

long duration2;
int distance2;

void setup() 
{
	pinMode(trigPin_1, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin_1, INPUT); // Sets the echoPin as an Input
	pinMode(trigPin_2, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin_2, INPUT); // Sets the echoPin as an Input

	pinMode(block1, OUTPUT);
    pinMode(block2, OUTPUT);
    pinMode(block3, OUTPUT);
    pinMode(block4, OUTPUT);
    pinMode(sign, OUTPUT);

	Serial.begin(9600); // Starts the serial communication
}
void loop() 
{
// Clears the trigPin
	digitalWrite(trigPin_1, LOW);
	delayMicroseconds(2);
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin_1, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin_1, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration1 = pulseIn(echoPin_1, HIGH);
	// Calculating the distance
	distance1 = duration1*0.034/2;
	// Prints the distance on the Serial Monitor
	Serial.print("Distance1: ");
	Serial.println(distance1);



	digitalWrite(trigPin_2, LOW);
	delayMicroseconds(2);
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin_2, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin_2, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration2 = pulseIn(echoPin_2, HIGH);
	// Calculating the distance
	distance2 = duration2*0.034/2;
	// Prints the distance on the Serial Monitor
	Serial.print("Distance2: ");
	Serial.println(distance2);

    //for ultrasonic 1
	if(distance1 >= 25 && distance1 < 40)
    {
        digitalWrite(sign, HIGH); //sign board
        digitalWrite(block1, HIGH);
        digitalWrite(block3, LOW);
        digitalWrite(block2, LOW);
        digitalWrite(block4, LOW);

    }

    else if(distance1 < 25 && distance1 >= 15)
    {
        digitalWrite(sign, HIGH);
        digitalWrite(block2, HIGH);
        digitalWrite(block1, LOW);
        digitalWrite(block3, LOW);
        digitalWrite(block4, LOW);
    }
    
    else if(distance1 < 15 && distance1 > 0)
    {
        digitalWrite(sign, HIGH);
        digitalWrite(block2, LOW);
        digitalWrite(block1, LOW);
    	digitalWrite(block3, LOW);
        digitalWrite(block4, LOW);
    }

    //for ultrasonic 2

    else if(distance2 >= 25 && distance2 < 40)
    {
        digitalWrite(sign, HIGH); //sign board
        digitalWrite(block4, HIGH);
        digitalWrite(block3, LOW);
        digitalWrite(block2, LOW);
        digitalWrite(block1, LOW);

    }

    else if(distance2 < 25 && distance2 >= 15)
    {
        digitalWrite(sign, HIGH);
        digitalWrite(block3, HIGH);
        digitalWrite(block4, LOW);
        digitalWrite(block2, LOW);
        digitalWrite(block1, LOW);
    }
    
    else if(distance2 < 15 && distance2 > 0)
    {
        digitalWrite(sign, HIGH);
        digitalWrite(block3, LOW);
        digitalWrite(block4, LOW);
        digitalWrite(block2, LOW);
        digitalWrite(block1, LOW);
    }

    else if((distance2) > 60)
    {
    	digitalWrite(sign, LOW);
    	digitalWrite(block4, LOW);
    	digitalWrite(block3, LOW);
    }
    else if(distance1 > 60)
    {
    	digitalWrite(sign, LOW);
    	digitalWrite(block1, LOW);
    	digitalWrite(block2, LOW);

    }

}

int ledPin      =  9;
int buzzerPin   = 10;   // Buzzer   
int trigPin     = 11;   // Trigger
int echoPin     = 12;   // Echo
long duration   =  0;
long cm         =  0;
long inches     =  0;
 
void clearScreen() {

    Serial.write(27);       // ESC command
    Serial.print("[2J");    // clear screen command
    Serial.write(27);
    Serial.print("[H");     // cursor to home command
}

void setupEchoSensor() {

    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
}

void printProximity() {

    Serial.print("Proximity: (");
    Serial.print(inches);
    Serial.print(" in, ");
    Serial.print(cm);
    Serial.print(" cm)");
    Serial.println();
}

void soundBuzzer() {

    Serial.println("Too Close For Comfort!!");
    tone(buzzerPin, 1000);  //Send 1Khz sound signal
    digitalWrite(ledPin, HIGH);
    delay(1000);            //for 1 second            
    noTone(buzzerPin);      //stop sound
    digitalWrite(ledPin, LOW);
}

void setup() {

    //Serial Port begin
    Serial.begin (9600);

    //Define inputs and outputs
    pinMode(buzzerPin, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}
 
void loop() {

    setupEchoSensor();

    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.

    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);

    // Convert the time into a distance
    cm = (duration/2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
    inches = (duration/2) / 74; // Divide by 74 or multiply by 0.0135

    printProximity();

    if (cm <= 25.0) {

        soundBuzzer();
    }

    delay(250);
    clearScreen();
}

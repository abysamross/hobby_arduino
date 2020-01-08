int counter = 10; 

void setup() {

    //set serial baud rate
    Serial.begin(115200);
}

void clearScreen() {

    Serial.write(27);       // ESC command
    Serial.print("[2J");    // clear screen command
    Serial.write(27);
    Serial.print("[H");     // cursor to home command
}

void loop() {

    Serial.println("Simple Serial Printing On Arduino!");
    Serial.println(counter);
    counter = ( counter <= 0 ) ? 10 : (counter - 1);
    delay(1000);
    clearScreen();
}

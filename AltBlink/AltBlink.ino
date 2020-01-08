#define MAX_LED 13
#define LEDS 4

int terminal_led = 13 - LEDS;
int curr_led = MAX_LED;

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize digital pin LED_BUILTIN as an output.
  for (int led_index = MAX_LED; led_index > terminal_led; --led_index) {

      pinMode(led_index, OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {

  // turn the curr LED on
  digitalWrite(curr_led, HIGH);

  // turn the other LEDs off
  for (int led_index = MAX_LED; led_index > terminal_led; --led_index) {

      if (led_index == curr_led)
        continue;
        
      digitalWrite(led_index, LOW);
  }

  // wait for a second
  delay(1000);

  // turn the curr LED off
  digitalWrite(curr_led, LOW);

  // Choose the next curr LED
  curr_led = (curr_led - 1) <= terminal_led ? MAX_LED : curr_led - 1; 
}

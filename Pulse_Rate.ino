// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int beat=0;
int v=0;
float volt=0;
int i;
float peak=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
// set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Please wait 30s");
}
void loop() {
    //for(i=0; i<30;i++)
  while(millis()/1000 <6) // work for 60 secs
   {
    v=analogRead(0); // read analog value from pin 0 
  volt=(v*0.0049)-2; // convert to volts
    
           Serial.print("volt = ");
           Serial.println(volt);
        if(volt<=0.20 && volt>=0.18 ) // check for R waves amplitude
        {
            beat+=1; //increment number of beats
        }
   }
  // set the cursor to column 0, line 1
lcd.clear(); // clear LCD
lcd.print("Your Pulse ="); // Print a message to the LCD.
lcd.setCursor(0, 1); // set the cursor to column 0, line 1
lcd.print(beat);    // print the "beat" value
lcd.setCursor(6, 1);
lcd.print("bpm");
  delay(5000); // delay for 5 secs to read the value
}

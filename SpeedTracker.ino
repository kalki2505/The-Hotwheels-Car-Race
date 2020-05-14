/* Speed Test for Hot Wheels(R) die cast toy cars.

 IR LEDs with 220ohms resistors. IR sensor without any resistor.
 
 This project works ok at the bench when you throw the car smoothly.
 But in the "real world" of a Hot Wheels tracks the sensors are not fast reading enough. Please share your 
 improvements if you find a more precise and fast reading sensors!
 
 Project creator Fabio Coelho - Rio de Janeiro - Brazil Dec2018.
 
 Some improvements were made following inputs from fellow members at Arduino Project hub. Thank You!
 
 
 */

//#include <LiquidCrystal_I2C.h>
//We use a LCD 20x4 with an I2C module. It really keeps wiring simple...
//#include <Wire.h>

//LiquidCrystal_I2C lcd(0x27,12,2);// I2C adress

const int ledPin = 12;
byte irPinA = 4;
byte irPinB = 5;
byte irValA;
byte irValB;
float diff; // store timeScnd minus timeFirst
float vel; // calculated speed
unsigned long timeFirst;// IR sensor at irPinA
unsigned long timeScnd;// IR sensor at irPinB
float speedConst = 414; // ((distance between IR sensors in mm) x 3600)/1000)to convert mm/millis to km/h) 
                          // In This project we have 126mm between IR sensors


byte customChar0[8] = { //some art for the LCD screen
B01000,
B01100,
B01110,
B01111,
B01110,
B01100,
B01000,
B00000
};

void configLCD(){ //function to config the LCD display
 
//lcd.createChar(0, customChar0);
//lcd.setCursor(0,0);
//lcd.write(0);
//lcd.write(0);
//lcd.write(0);
//lcd.write(0);
//lcd.write(0);
//lcd.setCursor(5,0);
//lcd.print("SPEED TEST");
//lcd.setCursor(15,0);
//lcd.write(0);
//lcd.write(0);
//lcd.write(0);
//lcd.write(0);
//lcd.write(0);
//lcd.setCursor(0,1);
//lcd.print("P1:");
//lcd.setCursor(0,2);
///lcd.print("P2:");
//lcd.setCursor(0,3);
//lcd.print("Speed:");

}

void setup()
{
pinMode(irPinA, INPUT);
pinMode(irPinB, INPUT);
pinMode(ledPin, OUTPUT);
//Serial.begin(9600);noneededt 
//lcd.init();
//lcd.backlight();
//configLCD();
digitalWrite(ledPin, HIGH); //Green LED HIGH: ok to next ride.
Serial.begin(9600); // Starts the serial communication
}//end setup


void loop()
{
  irValA = digitalRead(irPinA);
  irValB = digitalRead(irPinB);
 
  if (irValA == LOW){
      timeFirst = millis();
     digitalWrite(ledPin, LOW);
    delay(30);
    }
 
  if (irValB == LOW){
    timeScnd = millis();
    diff = timeScnd - timeFirst; 
    vel = speedConst / diff;//get the Speed converted from mm/millis to km/h.
    /* 
    use only if you want
        Serial.print("T1: ");
    Serial.println(timeFirst);
    Serial.print("T2: ");
    Serial.println(timeScnd);
    Serial.print("Diff: ");
    Serial.println(diff);
    Serial.print("Speed: ");
    Serial.println(vel);
    */
    
    //lcd.setCursor(6, 1);
    //lcd.print(timeFirst);
    //lcd.setCursor(6, 2);
    //lcd.print(timeScnd); 
    //lcd.setCursor(6,3); 
   // lcd.print(vel);
   // lcd.print("km/h");
      // delay(5000); 
      // lcd.clear();
       //configLCD();
       Serial.print("Speed: ");
       Serial.print(vel);
       Serial.println(" km\\hr");
       digitalWrite(ledPin, HIGH);
        }
    
}//end Loop

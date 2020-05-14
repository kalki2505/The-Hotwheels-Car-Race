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

void setup()
{
    pinMode(irPinA, INPUT);
    pinMode(irPinB, INPUT);
    pinMode(ledPin, OUTPUT);
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
        Serial.print("Speed: ");
        Serial.print(vel);
        Serial.println(" km\\hr");
        digitalWrite(ledPin, HIGH);
    }
    
}//end Loop

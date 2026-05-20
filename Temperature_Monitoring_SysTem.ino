

const int sensorPin = A0; // sensor pin
const int Normal_Temp_LED = 8; // Normal Temp LED pin
const int Hot_Temp_LED = 13; // Hot Temp LED pin
int reading;   // ADC reading
float volts;   // voltage
float millivolts;  // voltage in mV
float degreesC;    // temp in deg C



// actual analog reference voltage 
const float aref_voltage = 1.09;
void setup() {  
  // set Normal_Temp_LED pins as outputs
  pinMode(Normal_Temp_LED,OUTPUT);
  pinMode(Hot_Temp_LED,OUTPUT);
    // use internal 1.1V reference voltage
  analogReference(INTERNAL);
  // initialize serial communication
  Serial.begin(9600);
}

void loop() {
  reading = analogRead(A0);  // read analog pin
  volts = reading * aref_voltage / 1023.0; // convert to voltage
  millivolts = 1000 * volts; // convert to millivolts
  degreesC = (millivolts - 500)/10;  // convert to deg C


  // control Normal_Temp_LEDs based on temperature thresholds
  if(degreesC > 30){
    digitalWrite(Hot_Temp_LED,HIGH);
    digitalWrite(Normal_Temp_LED,LOW);
  }
  else{
   digitalWrite(Hot_Temp_LED,LOW);
   digitalWrite(Normal_Temp_LED,HIGH);

  }
  delay(500);
}

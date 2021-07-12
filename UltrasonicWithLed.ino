// C++ code
//

double distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(10, OUTPUT);
}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(6, 5);
  
  // if not in the ultrasonic range
  if (!checkDistance(distance)) {
    digitalWrite(10, LOW);
  }else{ 
  
    // Wait for 3000 millisecond(s) 
    delay(3000);

    // check if still in the range, turn on the led or (send bluetooth signal to open the screen) 
    if (checkDistance(distance)) {
        digitalWrite(10, HIGH);
    }
    
  }
    
}

bool checkDistance(double distance){
  return (distance >= 0 && distance < 336);
}
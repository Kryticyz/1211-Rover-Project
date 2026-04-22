// the pins that I used in the circuit diagram, Tynan feel free to change these
const int leftMotor1 = 8;
const int leftMotor2 = 9;
const int rightMotor1 = 10;
const int rightMotor2 = 11;

void setup() {
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
}

// these are the functions we need for the rectangle I think
// but we should eventually add a backwards function for the maze which would be really simple
// Tynan and Sam if the turns are incorrect feel free to just swap the High and Low values and make adjustments where you reckon its needed
void forward() {
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void stopMotors() {
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}

void turnRight() {
  // left motor moves forward
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  // right motor moves back
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}

void turnLeft() {
  // left motor moves back
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  // right motor move forward
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

// the rectangle bit
void loop() {

  for(int i = 0; i < 4; i++) {
    forward(); 
    delay(4000); // depending on how far we need each side to be adjust this

    stopMotors();
    delay(500); // I think the stops would be good just in case we overshoot the turns

    turnRight(); 
    delay(1000); // we will need to figure out whether this is actually enough for 90'

    stopMotors();
    delay(500);
  }
  stopMotors(); 
}

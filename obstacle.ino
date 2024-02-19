const int trig = 7;
const int echo = 8;
const int leftForward = 5;
const int leftBackward = 6;
const int rightForward = 11;
const int rightBackward = 12;

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  

  if ( distance < 20 )
  {
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
  }
  else
  {digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    delay(100);
    
  }
 
}

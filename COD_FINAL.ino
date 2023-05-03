
long duration; // variable for the duration of sound wave travel
int distance=1111; // distance from sensor to object

void getDistance(){
  // Clears the trigPin condition:
  digitalWrite(3,LOW);
  delayMicroseconds(5);
  digitalWrite(3,HIGH);
  delayMicroseconds(10);
  digitalWrite(3,LOW);
  
  duration = pulseIn(2,HIGH); // calculating the distance
  distance = duration * 0.034 / 2; // speed of sound wave divided by 2 (go and back)
}

void setup()
{  
  pinMode(2, OUTPUT); //echo
  pinMode(3, INPUT); //trig
  pinMode(5,OUTPUT); //ENB
  pinMode(6,OUTPUT); //IN1
  pinMode(7,OUTPUT); //IN2
  pinMode(8,OUTPUT); //IN3
  pinMode(9,OUTPUT); //IN4
  pinMode(10,OUTPUT); //ENA
  Serial.begin(9600); //BlueTooth
}

void loop()
{
  getDistance();
  // Displays the distance on the Serial Monitor:
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  int x=Serial.read();
  
  if(distance<5)
  {
    /*STOP*/analogWrite (10,0);analogWrite(5,0);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);
    x=Serial.read();
  }

  if(x=='1') //1=forward
  {
    getDistance();
    /*FORWARD*/ analogWrite (10,100);analogWrite(5,100);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,HIGH);digitalWrite(9,LOW);
    delay(100);
    if(distance<5)
    {
      /*STOP*/ analogWrite (10,0);analogWrite(5,0);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);
    }
    x=Serial.read();
    if(x!=1||x!=2||x!=3||x!=4||x!=5||x!=6)x=5;
    delay(10);
  }

  if(x=='2') //2=backward
  {
    getDistance();
    /*BACKWARD*/ analogWrite (10,100);analogWrite(5,100);digitalWrite(6,LOW);digitalWrite(7,HIGH);digitalWrite(8,LOW);digitalWrite(9,HIGH);
    delay(100);
    if(distance<5)
    {
      /*STOP*/ analogWrite (10,0);analogWrite(5,0);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);
    }
    x=Serial.read();
    if(x!=1||x!=2||x!=3||x!=4||x!=5||x!=6)x=5;
    delay(10);
  }

  if(x=='3') //3=left
  {
    getDistance();
      /*LEFT*/ analogWrite (10,0);analogWrite(5,255);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,HIGH);digitalWrite(9,LOW);
      delay(50);
      /*FORWARD*/ analogWrite (10,100);analogWrite(5,100);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,HIGH);digitalWrite(9,LOW);
      delay(100);
      /*LEFT*/ analogWrite (10,0);analogWrite(5,255);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,HIGH);digitalWrite(9,LOW);
      delay(50);
    if(distance<5)
    {
      /*STOP*/ analogWrite (10,0);analogWrite(5,0);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);
    }
    x=Serial.read();
    if(x!=1||x!=2||x!=3||x!=4||x!=5||x!=6)x=5;
    delay(10);
  }

  if(x=='4') //4=right
  {
    getDistance();
      /*RIGHT*/ analogWrite (10,255);analogWrite(5,0);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,HIGH);digitalWrite(9,LOW);
      delay(50);
      /*FORWARD*/ analogWrite (10,100);analogWrite(5,100);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,HIGH);digitalWrite(9,LOW);
      delay(100);
      /*RIGHT*/ analogWrite (10,255);analogWrite(5,0);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,HIGH);digitalWrite(9,LOW);
      delay(50);
    if(distance<5)
    {
      /*STOP*/ analogWrite (10,0);analogWrite(5,0);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);
    }
    x=Serial.read();
    if(x!=1||x!=2||x!=3||x!=4||x!=5||x!=6)x=5;
    delay(10);
  }

  if(x=='5') //5=stop
  {
    /*STOP*/ analogWrite (10,0);analogWrite(5,0);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);
  }

  if(x=='6') //6=parkingRight
  {
    getDistance();
      /*FORWARD*/ analogWrite (10,100);analogWrite(5,100);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,HIGH);digitalWrite(9,LOW);
      delay(1000);
      /*STOP*/ analogWrite (10,0);analogWrite(5,0);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);
      delay(3000);
      /*TURN RIGHT*/ analogWrite (10,200);analogWrite(5,200);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,HIGH);
      delay(1500);
      getDistance();
      while(distance>7)
      {
        getDistance();
        /*SLOW FORWARD*/ analogWrite (10,50);analogWrite(5,50);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,HIGH);digitalWrite(9,LOW);
      }
      /*STOP*/ analogWrite (10,0);analogWrite(5,0);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);
      delay(1000);
      /*TURN LEFT*/ analogWrite (10,200);analogWrite(5,200);digitalWrite(6,LOW);digitalWrite(7,HIGH);digitalWrite(8,HIGH);digitalWrite(9,LOW);
      delay(1600);
      /*STOP*/ analogWrite (10,0);analogWrite(5,0);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);
    if(distance<5)
    {
      /*STOP*/ analogWrite (10,0);analogWrite(5,0);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);
    }
    x=Serial.read();
    if(x!=1||x!=2||x!=3||x!=4||x!=5||x!=6)x=5;
    delay(10);
  }
}

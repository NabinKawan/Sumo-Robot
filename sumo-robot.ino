//for front motor 
const int fLin1=2;
const int fLin2=4;
const int fLpwm=3;

const int fRin3=7;
const int fRin4=8;
const int fRpwm=5;
//for back motor 
const int bLin1=1;
const int bLin2=0;
const int bLpwm=6;

const int bRin3=9;
const int bRin4=13;
const int bRpwm=10;

const int ftrigPin=A5;  
const int fechoPin=A4;  
const int btrigPin=12;  
const int bechoPin=11;  

const int br=A1;
const int fr=A0;  
const int bl=A3;  
const int fl=A2;    

float Fdistance=0;
float Bdistance=0; 
float Fduration=0;
float Bduration=0;
int timer=0;
boolean dirn=true; 

void setup() 
{
  pinMode(fRin3,OUTPUT);
  pinMode(fRin4,OUTPUT);
  pinMode(fRpwm,OUTPUT);
    
  pinMode(bRin3,OUTPUT);
  pinMode(bRin4,OUTPUT);
  pinMode(bRpwm,OUTPUT);
    
  pinMode(fLin1,OUTPUT);
  pinMode(fLin2,OUTPUT);
  pinMode(fLpwm,OUTPUT);
    
  pinMode(bLin1,OUTPUT);
  pinMode(bLin2,OUTPUT);
  pinMode(bLpwm,OUTPUT);
  
  pinMode(ftrigPin, OUTPUT);  
  pinMode(fechoPin, INPUT);  
  pinMode(btrigPin, OUTPUT);  
  pinMode(bechoPin, INPUT);  
  
  pinMode(fl, INPUT);  
  pinMode(fr, INPUT);  
  pinMode(bl, INPUT);  
  pinMode(br, INPUT);  
 }
void loop()
{
 
  int flsens=analogRead(fl);
  int frsens=analogRead(fr);
  int blsens=analogRead(bl);
  int brsens=analogRead(br);

//front ultrasonic
 
 digitalWrite(ftrigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(ftrigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(ftrigPin,LOW);
 Fduration=pulseIn(fechoPin,HIGH);
 Fdistance= Fduration*0.034/2;

// back_ultrasonic 
 
 digitalWrite(btrigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(btrigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(btrigPin,LOW);
 Bduration=pulseIn(bechoPin,HIGH);
 Bdistance= Bduration*0.034/2;
 
 if(flsens<=600 && blsens<=600 && frsens<=600 && brsens<=600)
{
 if (Fdistance<=60 && Fdistance>=20)
    {
    forward(150);
   
    }
    else if(Fdistance<20)
    {
     forward(255);
      dirn=!dirn; 
    }  
    else if(Bdistance<=60 && Bdistance>=20)
    {
     backward(150);
    
    }
    else if (Bdistance<20)
    {
  
    backward(255); 
     dirn=!dirn; 
       
    }
  else
        {
         rotate(200,dirn);
         delay(200);
         forward(120);
         delay(300);
         while(timer<30)
         {
          irCheck();
          if(flsens<600 && blsens<600 && frsens<600 && brsens<600)
         {
          forward(120);
          timer++;
         
         }
         else
         {
          break;
         }
         }
         timer=0;
         }  
         
            
        }
         


else if((flsens>600 || frsens>600) && (blsens<600 || brsens<600))
  {
    backward(120);
   delay(800);
   dirn=!dirn;
  }
  else if((flsens<600 || frsens<600) && (blsens>600 || brsens>600))
  {
  forward(120);
delay(800);
dirn=!dirn;
  }
  
  else
  {
    rotate(255,dirn);
   delay(300);
    
  }
  }       
  
void irCheck()
{
  int flsens=analogRead(fl);
  int frsens=analogRead(fr);
  int blsens=analogRead(bl);
  int brsens=analogRead(br);
}
void rotate(int rate,boolean dirn){
  if(dirn == true ){
    // rotate clockwise
digitalWrite(fRin3,HIGH);
  digitalWrite(fRin4,LOW);
  analogWrite(fRpwm,rate);

  digitalWrite(bRin3,HIGH);
  digitalWrite(bRin4,LOW);
  analogWrite(bRpwm,rate);

  digitalWrite(fLin1,LOW);
  digitalWrite(fLin2,HIGH);
  analogWrite(fLpwm,rate);

  digitalWrite(bLin1,LOW);
  digitalWrite(bLin2,HIGH);
  analogWrite(bLpwm,rate);
  }
  else if (dirn == false ){
    // rotate anti clockwise
 digitalWrite(fRin3,LOW);
  digitalWrite(fRin4,HIGH);
  analogWrite(fRpwm,rate);

  digitalWrite(bRin3,LOW);
  digitalWrite(bRin4,HIGH);
  analogWrite(bRpwm,rate);

  digitalWrite(fLin1,HIGH);
  digitalWrite(fLin2,LOW);
  analogWrite(fLpwm,rate);

  digitalWrite(bLin1,HIGH);
  digitalWrite(bLin2,LOW);
  analogWrite(bLpwm,rate);
  }
  }

 void forward(int rate){
  
  digitalWrite(fRin3,HIGH);
  digitalWrite(fRin4,LOW);
  analogWrite(fRpwm,rate);


  digitalWrite(bRin3,HIGH);
  digitalWrite(bRin4,LOW);
  analogWrite(bRpwm,rate);

  digitalWrite(fLin1,HIGH);
  digitalWrite(fLin2,LOW);
  analogWrite(fLpwm,rate);

  digitalWrite(bLin1,HIGH);
  digitalWrite(bLin2,LOW);
  analogWrite(bLpwm,rate);
  }
void backward(int rate){
  digitalWrite(fRin3,LOW);
  digitalWrite(fRin4,HIGH);
  analogWrite(fRpwm,rate);

  digitalWrite(bRin3,LOW);
  digitalWrite(bRin4,HIGH);
  analogWrite(bRpwm,rate);

  digitalWrite(fLin1,LOW);
  digitalWrite(fLin2,HIGH);
  analogWrite(fLpwm,rate);

  digitalWrite(bLin1,LOW);
  digitalWrite(bLin2,HIGH);
  analogWrite(bLpwm,rate);
  }

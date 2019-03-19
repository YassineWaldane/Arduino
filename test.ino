#include<SoftwareSerial.h>

#include <PID_v1.h>
#include <stdint.h>
#include <TouchScreen.h>
#include <Servo.h>

#define YP A1 //0
#define XM A0 //1
#define YM 4  //3
#define XP 3  //4
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300); 
TSPoint p; 
long StartTime = 0;



Servo servoX; 
Servo servoY; 


int Ts = 50; 


double Kpx = 0.2;                                                     
double Kix = 0.03 ;                                                      
double Kdx = 0.12;
                    
double Kpy = 0.2;                                                       
double Kiy = 0;                                                      
double Kdy = 0.08;



double SetpointX, InputX, OutputX; 
double SetpointY, InputY, OutputY; 
PID myPIDX(&InputX, &OutputX, &SetpointX, Kpx, Kix, Kdx, REVERSE);
PID myPIDY(&InputY, &OutputY, &SetpointY, Kpy, Kiy, Kdy, DIRECT);

boolean CheckScreen(){
  TSPoint p = ts.getPoint();
  if (p.z > ts.pressureThreshhold ){
    return true;
  }
  return false;
}

int temps=0;
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
char Data;
int valeur1 ; 
int valeur2 ;
int automatic=1;



void setup()
{ BlueT.begin(9600);
  
  Serial.begin(9600);
  servoX.attach(5);
  servoY.attach(6);

  OutputX=56;
  OutputY=28;
  servoX.write(OutputX); 
  servoY.write(OutputY); 
   p = ts.getPoint();
 
  
  SetpointX = 90.0;
  SetpointY = 70.0;
         

  myPIDX.SetMode(AUTOMATIC);
  myPIDX.SetOutputLimits(10, 80);
  myPIDY.SetMode(AUTOMATIC);
  myPIDY.SetOutputLimits(10, 65);
 
  myPIDX.SetSampleTime(Ts); 
  myPIDY.SetSampleTime(Ts);  
  delay(100);
  StartTime = millis();
}
 
void loop(){ 
     if(automatic==1){
      
      p = ts.getPoint();   
      if (CheckScreen()) 
      {    
          temps=0;
          servoX.attach(5); 
          servoY.attach(6); 
          double valX= p.x;
          double valY = p.y;
          valX=map(valX,66,965,10,172);
          valY=map(valY,102,925,10,130);
      
         Serial.print("x :  ");
         Serial.println(valX);
         Serial.print("y :  ");
         Serial.println(valY);
      
          InputX = valX;  
          InputY = valY;
          
          if(valY >0 && valX >0){

            myPIDX.Compute();  
            myPIDY.Compute(); 
   
              servoX.write(OutputX);
              servoY.write(OutputY);}
              else{Serial.println("erreur");}
      }
  
      else{
        temps+=1;
        delay(1);
        if (temps==3000){
          servoX.write(50);
          servoY.write(30);
        }
        if(temps==10000){
          servoX.detach();
          servoY.detach();
        }
      }
    }
    
if (BlueT.available()){
    Data=BlueT.read();
    
    if (Data=='N'){ automatic=1;}
    if(Data=='O'){ automatic =0;}
    
    if(automatic==0){
      
        if (Data=='A'){ 
            temps=0;
            valeur1 =BlueT.parseInt();
            if(valeur1<70){servoX.write(valeur1);}
        }
        
        if (Data=='B'){
            temps=0;
            valeur2 =BlueT.parseInt(); 
            if(valeur2<70){servoY.write(valeur2);}
        }
        
    }
   
} 
  
}
 

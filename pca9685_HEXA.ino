


#include <Servo.h>              //Servo library
 
//initialize a servo object for the connected servo  
    // attach the signal pin of servo to pin9 of arduino
//#include<elapsedMillis.h>

#include <Adafruit_PWMServoDriver.h>
#include<Servo.h>
#include <Wire.h>
//#include <Adafruit_PWMServoDriver.h>
Servo servo1,servo2;
// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;
int i;
void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");
 servo1.attach(5);   
  servo2.attach(6);
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  delay(10);
}

// you can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  standup();
  delay(5000);
 say_hi();
  delay(100);
  while(1){
  int x = random(0,6);
 Serial.println(x);
 switch(x){

  case 1:
  {
    standup();
    delay(1000);
    for(int i =0;i<4;i++){
      
      backward();
    }
  }break;

  case 2:
  {
    standup();
    delay(1000);
    
    for(int i =0;i<8;i++){
      Turn_left();
    }
    delay(500);1111111111
    for(int i =0;i<8;i++){
      Turn_right();
    }
  }break;

  case 3:
  {
    standup();
    delay(1000);
    
    for(int i =0;i<8;i++){
      Turn_right();
    }
  }break;

  case 4:
  {
    setmovement();
    delay(1500);
    for(int i =0;i<3;i++){
     moveleft();
     delay(200);
     moveleft1();
     delay(200);
    }
  }break;

  case 5:
  {
    standup();
    delay(1000);
    
    for(int i =0;i<2;i++){
      say_hi();
    }
  }break;
  
  case 6:{
    standup();
    delay(1000);
    
  for(int i =0;i<3;i++){
      UP();
    }
  }break;

  
 }

 delay(1000);

}
}

  
void standup(){
//RLEG1
pwm.setPWM(15,0,305);
    servo1.write(90);//110
    servo2.write(105);


///RLEG2

pwm.setPWM(0, 0, 375);
   pwm.setPWM(1, 0, 270);
     pwm.setPWM(2, 0,320 );
//delay(300);



 ///RLEG3
pwm.setPWM(3, 0, 375);
   pwm.setPWM(4, 0, 270);
     pwm.setPWM(5, 0,340 );
//delay(300);
 

///LLEG1
pwm.setPWM(12, 0, 340);
   pwm.setPWM(13, 0, 470);
     pwm.setPWM(14, 0,400);
//delay(300);

//LLEG2
pwm.setPWM(9, 0, 375);
   pwm.setPWM(10, 0, 450);
     pwm.setPWM(11, 0,400);
//delay(300);

//LLEG3
pwm.setPWM(6, 0, 375);
   pwm.setPWM(7, 0, 470);
     pwm.setPWM(8, 0,430);
//delay(300);


}

void left_forward()
{
 pwm.setPWM(12, 0, 340);
pwm.setPWM(6, 0, 375);
pwm.setPWM(0,0,375);

   pwm.setPWM(13, 0, 300);
   pwm.setPWM(7, 0, 320);
  pwm.setPWM(1,0,420);  
   
     pwm.setPWM(14, 0,400);
     pwm.setPWM(8, 0,430);
      pwm.setPWM(2, 0,320 );
      
delay(100);

pwm.setPWM(12, 0, 280);
pwm.setPWM(6, 0, 250);//250
pwm.setPWM(0,0,450);

   pwm.setPWM(13, 0, 300);
  pwm.setPWM(7, 0, 370);
   pwm.setPWM(1,0,420);
   
     pwm.setPWM(14, 0,400);
    pwm.setPWM(8, 0,430);
       pwm.setPWM(2, 0,320);

delay(100);
     
     pwm.setPWM(12, 0, 280);
    pwm.setPWM(6, 0,250);//250
    pwm.setPWM(0,0,420);
     
   pwm.setPWM(13, 0, 450);
   pwm.setPWM(7, 0, 470);
   pwm.setPWM(1, 0, 270);
    
     pwm.setPWM(14, 0,400);
    pwm.setPWM(8, 0,430);
       pwm.setPWM(2, 0,320);

//----BACK

     ////----NEGative

  }

  void right_forward()
  {
    
pwm.setPWM(9, 0, 375);
pwm.setPWM(3, 0, 375);
servo2.write(105);

pwm.setPWM(10, 0, 300);
pwm.setPWM(4, 0, 420);
pwm.setPWM(15,0,510);
delay(200);
//

pwm.setPWM(9, 0, 280);//250
pwm.setPWM(3, 0, 450);//500
servo2.write(130);

pwm.setPWM(10, 0, 300);
pwm.setPWM(4, 0, 420);
pwm.setPWM(15,0,510);
delay(200);
//
pwm.setPWM(9, 0, 280);
pwm.setPWM(3, 0, 500);//500
servo2.write(130);

pwm.setPWM(10, 0, 450);
 pwm.setPWM(4, 0, 270);
pwm.setPWM(15,0,345);
//
}

void backward(){
  
Bleft_forward();

delay(400);
Bright_forward();

pwm.setPWM(12, 0, 375-70);

pwm.setPWM(0, 0, 375+50);

pwm.setPWM(9,0,375-50);
pwm.setPWM(3,0,375+50);
pwm.setPWM(6,0,375-50);
servo2.write(105);
delay(200);
    
    
  
  }
 void Bleft_forward(){
  ///BACK LEFT FORWARD
 pwm.setPWM(12, 0, 375);
pwm.setPWM(6, 0, 375);
pwm.setPWM(0,0,375);

   pwm.setPWM(13, 0, 300);
   pwm.setPWM(7, 0, 320);
  pwm.setPWM(1,0,420);  
   
     pwm.setPWM(14, 0,400);
     pwm.setPWM(8, 0,430);
      pwm.setPWM(2, 0,320);
      
delay(100);

pwm.setPWM(12, 0, 400);
pwm.setPWM(6, 0, 410);//250
pwm.setPWM(0,0,300);

   pwm.setPWM(13, 0, 300);
  pwm.setPWM(7, 0, 370);
   pwm.setPWM(1,0,420);
   
     pwm.setPWM(14, 0,400);
    pwm.setPWM(8, 0,430);
       pwm.setPWM(2, 0,320);

delay(100);
     
     pwm.setPWM(12, 0, 400);
    pwm.setPWM(6, 0,410);//250
    pwm.setPWM(0,0,300);
     
   pwm.setPWM(13, 0, 450);
   pwm.setPWM(7, 0, 470);
   pwm.setPWM(1, 0, 270);
    
     pwm.setPWM(14, 0,400);
    pwm.setPWM(8, 0,430);
       pwm.setPWM(2, 02,320);
       delay(100);
 }

void Bright_forward(){
  ////////////////////////BACK RIGHT FORWARD
pwm.setPWM(9, 0, 375);
pwm.setPWM(3, 0, 375);
servo2.write(105);

pwm.setPWM(10, 0, 300);
pwm.setPWM(4, 0, 420);
pwm.setPWM(15,0,510);
delay(200);
//

pwm.setPWM(9, 0, 500);
pwm.setPWM(3, 0, 250);//500
servo2.write(50);

pwm.setPWM(10, 0, 300);
pwm.setPWM(4, 0, 420);
pwm.setPWM(15,0,510);
delay(200);
//
pwm.setPWM(9, 0, 500);
pwm.setPWM(3, 0, 250);//500
servo2.write(50);

pwm.setPWM(10, 0, 450);
 pwm.setPWM(4, 0, 270);
pwm.setPWM(15,0,345);
//
delay(200);
}



void forward()
{
  
     //delay(400);
left_forward();

delay(400);
right_forward();

pwm.setPWM(12, 0, 340+75);

pwm.setPWM(0, 0, 375-75);

pwm.setPWM(9,0,375+75);
pwm.setPWM(3,0,375-75);
pwm.setPWM(6,0,375+75);
servo2.write(60);
delay(200);
}

void Turn_left_L()
{
  pwm.setPWM(12, 0, 340);
//LEG3
pwm.setPWM(6, 0, 375);
pwm.setPWM(0,0,375);

   pwm.setPWM(13, 0, 300);
   pwm.setPWM(7, 0, 320);
  pwm.setPWM(1,0,420);  
   
     pwm.setPWM(14, 0,400);
     pwm.setPWM(8, 0,430);
      pwm.setPWM(2, 0,320 );
      
delay(100);

pwm.setPWM(12, 0, 250);
pwm.setPWM(6, 0, 20);
pwm.setPWM(0,0,300);

   pwm.setPWM(13, 0, 300);
  pwm.setPWM(7, 0, 370);
   pwm.setPWM(1,0,420);
   
     pwm.setPWM(14, 0,400);
    pwm.setPWM(8, 0,430);
       pwm.setPWM(2, 0,320);

delay(100);
     
     pwm.setPWM(12, 0, 250);
    pwm.setPWM(6, 0,230);//250
    pwm.setPWM(0,0,300);
     
   pwm.setPWM(13, 0, 450);
   pwm.setPWM(7, 0, 470);
   pwm.setPWM(1, 0, 270);
    
     pwm.setPWM(14, 0,400);
    pwm.setPWM(8, 0,430);
    pwm.setPWM(2, 0,320);

}

void Turn_right_R()
{
      
pwm.setPWM(9, 0, 375);
pwm.setPWM(3, 0, 375);
servo2.write(105);

pwm.setPWM(10, 0, 300);
pwm.setPWM(4, 0, 420);
pwm.setPWM(15,0,510);
delay(100);
//

pwm.setPWM(9, 0, 250);
pwm.setPWM(3, 0, 200);
servo2.write(80);

pwm.setPWM(10, 0, 300);
pwm.setPWM(4, 0, 420);
pwm.setPWM(15,0,510);
delay(100);
//
pwm.setPWM(9, 0, 250);
pwm.setPWM(3, 0, 200);
servo2.write(80);

pwm.setPWM(10, 0, 450);
 pwm.setPWM(4, 0, 270);
pwm.setPWM(15,0,345);

}

void Turn_left()
{
  Turn_left_L();
  delay(200);
  Turn_right_R();
  delay(100);
  
pwm.setPWM(12, 0, 340+50);
pwm.setPWM(6, 0, 375+50);
pwm.setPWM(0, 0, 375+50);

pwm.setPWM(9,0,375+50);
pwm.setPWM(3,0,375+50);
servo2.write(140);
delay(200);
}

//////////////////////////////////////////
void moveleft(){
   //UP 
     pwm.setPWM(15,0,400);//345
        pwm.setPWM(4,0,345);//270
delay(100);
 //FORW
        servo1.write(70);//110
        pwm.setPWM(5,0,250);//340
delay(100);
//DOWN
    pwm.setPWM(15,0,300);  
    pwm.setPWM(4,0,210);//270
        pwm.setPWM(1,0,350);//270
 
   
delay(100);
    pwm.setPWM(15,0,345);
    servo1.write(110);


   
   pwm.setPWM(4,0,270);
    pwm.setPWM(5,0,340);

    pwm.setPWM(11,0,510);//400
    pwm.setPWM(10,0,500);//450
    
    delay(100);
    pwm.setPWM(10,0,450);
pwm.setPWM(11,0,400);
  
delay(100);  
  }
  void moveleft1(){

      //  pwm.setPWM(4,0,345);//270
  delay(100);
 //FORW
        //servo1.write(70);//110
        pwm.setPWM(2,0,220);//320
  delay(100);
//DOWN
    pwm.setPWM(1,0,270);  
   // pwm.setPWM(,0,210);//270
 
   
  delay(100);
    pwm.setPWM(2,0,320);
    //servo1.write(110);


   
    pwm.setPWM(15,0,400);//345
    pwm.setPWM(4,0,345);//270
    pwm.setPWM(7,0,550);//470
    pwm.setPWM(8,0,580);//430

    pwm.setPWM(13,0,550);//450
    pwm.setPWM(14,0,550);//400
    
    delay(100);
    pwm.setPWM(7,0,470);//470
    pwm.setPWM(8,0,430);//430

    pwm.setPWM(13,0,450);//450
    pwm.setPWM(14,0,400);//400
delay(100);
}

  void setmovement(){  //RLEG1
pwm.setPWM(15,0,300);
    servo1.write(110);
    servo2.write(80);//60


///RLEG2

pwm.setPWM(0, 0, 375);
   pwm.setPWM(1, 0, 270);
     pwm.setPWM(2, 0,320 );
//delay(1000);



 ///RLEG3
pwm.setPWM(3, 0, 400);//440
   pwm.setPWM(4, 0, 270);
     pwm.setPWM(5, 0,340 );
//delay(1000);
 

///LLEG1
pwm.setPWM(12, 0, 380);//400
   pwm.setPWM(13, 0, 450);
     pwm.setPWM(14, 0,400);
//delay(1000);

//LLEG2
pwm.setPWM(9, 0, 375);
   pwm.setPWM(10, 0, 450);
     pwm.setPWM(11, 0,400);
//delay(1000);

//LLEG3
pwm.setPWM(6, 0, 320);//280
   pwm.setPWM(7, 0, 470);
     pwm.setPWM(8, 0,430);
//delay(1000);
}

void Turn_right_L()
{
 pwm.setPWM(12, 0, 375);
pwm.setPWM(6, 0, 375);
pwm.setPWM(0,0,375);

   pwm.setPWM(13, 0, 300);
   pwm.setPWM(7, 0, 320);
  pwm.setPWM(1,0,420);  
   
     pwm.setPWM(14, 0,400);
     pwm.setPWM(8, 0,430);
      pwm.setPWM(2, 0,320);
      
delay(100);

pwm.setPWM(12, 0, 400);
pwm.setPWM(6, 0, 410);//250
pwm.setPWM(0,0,450);

   pwm.setPWM(13, 0, 300);
  pwm.setPWM(7, 0, 370);
   pwm.setPWM(1,0,420);
   
     pwm.setPWM(14, 0,400);
    pwm.setPWM(8, 0,430);
       pwm.setPWM(2, 0,320);

delay(100);
     
     pwm.setPWM(12, 0, 400);
    pwm.setPWM(6, 0,410);//250
    pwm.setPWM(0,0,450);
     
   pwm.setPWM(13, 0, 450);
   pwm.setPWM(7, 0, 470);
   pwm.setPWM(1, 0, 270);
    
     pwm.setPWM(14, 0,400);
    pwm.setPWM(8, 0,430);
       pwm.setPWM(2, 02,320);
       delay(100);
}
void Turn_left_R()
{
  pwm.setPWM(9, 0, 375);
pwm.setPWM(3, 0, 375);
servo2.write(105);

pwm.setPWM(10, 0, 300);
pwm.setPWM(4, 0, 420);
pwm.setPWM(15,0,510);
delay(200);
//

pwm.setPWM(9, 0, 500);
pwm.setPWM(3, 0, 500);//500
servo2.write(160);

pwm.setPWM(10, 0, 300);
pwm.setPWM(4, 0, 420);
pwm.setPWM(15,0,510);
delay(200);
//
pwm.setPWM(9, 0, 500);
pwm.setPWM(3, 0, 500);//500
servo2.write(160);

pwm.setPWM(10, 0, 450);
 pwm.setPWM(4, 0, 270);
pwm.setPWM(15,0,345);
//
delay(200);

}

void Turn_right()
{
  Turn_right_L();
  delay(400);
  Turn_left_R();
  delay(100);
  
pwm.setPWM(12, 0, 340-75);
pwm.setPWM(6, 0, 375-75);
pwm.setPWM(0, 0, 375-75);

pwm.setPWM(9,0,375+75);
pwm.setPWM(3,0,375+75);
servo2.write(80);
delay(200);
}


void say_hi(){
  standup();
  delay(1000);
         pwm.setPWM(12, 0,300);
         delay(100);
          pwm.setPWM(15,0,500);
          servo1.write(50);
          delay(100);
         for(int i = 0 ; i < 8;i++){
          servo2.write(105);
          delay(100);
          servo2.write(130);
          delay(100);
          }
}

void UP(){
  pwm.setPWM(15,0,150);//305
    servo1.write(20);
    servo2.write(105);


///RLEG2

pwm.setPWM(0, 0, 375);
   pwm.setPWM(1, 0, 10);//270
     pwm.setPWM(2, 0,50 );//320
//delay(300);



 ///RLEG3
pwm.setPWM(3, 0, 375);
   pwm.setPWM(4, 0, 10);//270
     pwm.setPWM(5, 0,70 );//340
//delay(300);
 

///LLEG1
pwm.setPWM(12, 0, 340);
   pwm.setPWM(13, 0, 680);//470
     pwm.setPWM(14, 0,600);//400
//delay(300);

//LLEG2
pwm.setPWM(9, 0, 375);
   pwm.setPWM(10, 0, 600);//450
     pwm.setPWM(11, 0,600);//400
//delay(300);

//LLEG3
pwm.setPWM(6, 0, 375);
   pwm.setPWM(7, 0, 600);//470
     pwm.setPWM(8, 0,600);//430
//delay(300);


}



/*
  KeyboardAndMouseControl
 
 Controls the mouse from five pushbuttons on an Arduino Leonardo or Micro.
 
 Hardware:
 * 5 pushbuttons attached to D2, D3, D4, D5, D6
 
 
 The mouse movement is always relative. This sketch reads 
 four pushbuttons, and uses them to set the movement of the mouse.
 
 WARNING:  When you use the Mouse.move() command, the Arduino takes
 over your mouse!  Make sure you have control before you use the mouse commands.
 
 created 15 Mar 2012
 modified 27 Mar 2012
 by Tom Igoe
 
 this code is in the public domain
 
 */
int MouseX0,MouseX1,MouseY0,MouseY1;
int count=10;
void setup() { 
  // initialize the buttons' inputs:             
  Serial.begin(9600);
  // initialize mouse control:
  Mouse.begin();
  Keyboard.begin();
  while(!Serial);
}

void loop() {
  //read the x and y value then use them
   MouseX0 = analogRead(A0);
   MouseY0 = analogRead(A1);
  //delay(200);
 
  if(MouseY0<=200 && MouseY0>=0)
  {
    Keyboard.write('w');
    while(1){
      MouseY1 = analogRead(A1);
      if(MouseY1>200)
        break;
    }
  }
  else if(MouseX0>=900&&MouseX0<=1030)
  {
    Keyboard.write('d');
    MouseX1 = 500;
    while(1)
    {
      MouseX1 = analogRead(A0);
      if(MouseX1<900)
       break;
    }
  }
  else if(MouseY0>=900&&MouseY0<=1030)
  {
    Keyboard.write('s');
    while(1){
      MouseX1=analogRead(A1);
      if(MouseX1<900)
        break;
    }
  }
  else if(MouseX0>=0&&MouseX0<=200)
  {
    Keyboard.write('a');
    while(1){
      MouseX0=analogRead(A0);
      if(MouseX0>200)
       break;
    }
  }
}


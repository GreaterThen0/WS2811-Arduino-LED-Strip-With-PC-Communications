import controlP5.*;
import processing.serial.*;

Serial port;

ControlP5 cp5;
ControlP5 cp51;
ControlP5 cp52;

void setup()
{
  
  size(300, 400);
  
  
  printArray(Serial.list());
  
  port = new Serial(this, "COM7", 9600);
  
  
  cp5 = new ControlP5(this);
  cp51 = new ControlP5(this);
  cp52 = new ControlP5(this);
  
  cp52.hide();
  
  cp51.addButton("one")
    .setPosition(1,350)
    .setSize(25,25)
  ;
  cp51.addButton("two")
    .setPosition(31,350)
    .setSize(25,25)
  ;
  cp51.addButton("three")
    .setPosition(61,350)
    .setSize(25,25)
  ;
  cp51.addButton("four")
    .setPosition(91,350)
    .setSize(25,25)
  ;
  cp51.addButton("five")
    .setPosition(121,350)
    .setSize(25,25)
  ;
  cp51.addButton("six")
    .setPosition(151,350)
    .setSize(25,25)
  ;
  cp51.addButton("seven")
    .setPosition(181,350)
    .setSize(25,25)
  ;
  cp51.addButton("eight")
    .setPosition(211,350)
    .setSize(25,25)
  ;
  cp51.addButton("nine")
    .setPosition(241,350)
    .setSize(25,25)
  ;
  cp51.addButton("ten")
    .setPosition(271,350)
    .setSize(25,25)
  ;
  
  cp5.addButton("Pride")
    .setPosition(15,50)
    .setSize(100,50)
  ;
  
  cp5.addButton("off")
    .setPosition(175,50)
    .setSize(100,50)
  ;
  
  cp5.addButton("Cylon_RGB")
    .setPosition(175,115)
    .setSize(100,50)
  ;
  
  cp5.addButton("White")
    .setPosition(15,115)
    .setSize(100,50)
  ;
  
  cp5.addButton("RGB")
    .setPosition(175,180)
    .setSize(100,50)
  ;
  
  cp5.addButton("Cylon")
    .setPosition(15,180)
    .setSize(100,50)
  ;
  
  cp5.addButton("Random_Lights")
    .setPosition(15,245)
    .setSize(100,50)
  ;
  
    cp5.addButton("Random_Lights_On")
    .setPosition(175,245)
    .setSize(100,50)
  ;
    
    cp5.addButton("Next")
    .setPosition(128,100)
    .setSize(35,50)
  ;
  
  cp52.addButton("Last")
    .setPosition(128,200)
    .setSize(35,50)
  ;
  
  cp52.addButton("blops")
    .setPosition(15,50)
    .setSize(100,50)
  ;
  
  cp52.addButton("Spotted_Wipe")
    .setPosition(175,50)
    .setSize(100,50)
  ;
  
   cp52.addButton("Color_Wipe")
    .setPosition(175,115)
    .setSize(100,50)
  ;
  
  cp52.addButton("Pretty_Fill")
    .setPosition(15,115)
    .setSize(100,50)
  ;
  
  cp52.addButton("Arcade")
    .setPosition(175,180)
    .setSize(100,50)
  ;
  
  cp52.addButton("RGB_Calibrate")
    .setPosition(15,180)
    .setSize(100,50)
  ;
  
  cp52.addButton("Canada_Flag")
    .setPosition(15,245)
    .setSize(100,50)
  ;
  
    cp52.addButton("4")
    .setPosition(175,245)
    .setSize(100,50)
  ;
  
  
}

void draw(){
 
  background(0,0,0);
  
  text("LED Strip Control", 100, 30);
  
  text("Brightness", 120, 330);
  
}


void Canada_Flag()
{
  port.write('D');
}

void RGB_Calibrate()
{
  port.write('I');
}

void Arcade(){
 
  port.write('Z');
  
}

void Color_Wipe(){
 
  port.write('U');
  
}

void Pretty_Fill(){
 
  port.write('V');
  
}

void Spotted_Wipe(){
 
  port.write('Q');
  
}

void blops(){
 
  port.write('B');
  
}


void ten(){
 
  port.write('9');
  
}

void nine(){
 
  port.write('8');
  
}

void eight(){
 
  port.write('7');
  
}

void seven(){
 
  port.write('6');
  
}

void six(){
 
  port.write('5');
  
}

void five(){
 
  port.write('4');
  
}

void four(){
 
  port.write('3');
  
}

void three(){
 
  port.write('2');
  
}

void two(){
 
  port.write('1');
  
}

void one(){
 
  port.write('0');
  
}


void Last(){
 
  cp52.hide();
  cp5.show();
  
}

void Next(){
 
  cp5.hide();
  cp52.show();
  
}

void Random_Lights_On(){
 
  port.write('A');
  
}

void Random_Lights(){
 
  port.write('R');
  
}

void RGB(){
 
  port.write('G');
  
}

void Cylon(){
 
  port.write('S');
  
}

void Cylon_RGB(){
 
  port.write('C');
  
}

void off(){
 
  port.write('O');
  
}

void Pride()
{
 
  port.write('P');
  
}

void White()
{
 
  port.write('W');
  
}

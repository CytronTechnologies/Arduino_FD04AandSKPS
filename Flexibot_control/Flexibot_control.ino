//skps protocol
#define p_Up	    4
#define p_Right	    5
#define p_Down	    6
#define p_Left	    7
#define	p_L2	    8
#define	p_R2	    9
#define p_L1	    10
#define p_R1	    11
#define p_Triangle  12
#define p_Circle    13
#define p_Cross	    14
#define	p_Square    15

//constant variable
const int rx = 0;
const int tx = 1;

const int mtr2_p1 = 2;
const int mtr2_p2 = 4;
const int mtr2_spd = 3;

const int mtr3_p1 = 7;
const int mtr3_p2 = 8;
const int mtr3_spd = 6;

const int mtr4_p1 = 12;
const int mtr4_p2 = 13;
const int mtr4_spd = 11;

void setup()
{
  Serial.begin(9600);      //Set serial baud rate as 9600
  Serial.flush();          //Waits for the transmission of outgoing serial data to complete.
  
  //Set the mode for each digital pins whether input or output
  pinMode(rx, INPUT);
  pinMode(tx, OUTPUT);
  
  pinMode(mtr2_p1, OUTPUT);
  pinMode(mtr2_p2, OUTPUT);
  pinMode(mtr2_spd, OUTPUT);
  
  pinMode(mtr3_p1, OUTPUT);
  pinMode(mtr3_p2, OUTPUT);
  pinMode(mtr3_spd, OUTPUT);
  
  pinMode(mtr4_p1, OUTPUT);
  pinMode(mtr4_p2, OUTPUT);
  pinMode(mtr4_spd, OUTPUT);
}

void loop()
{ 
   if(skps(p_Up)==0)            //Check whether Up button is pressed
  {
    move_up();                  //Call move_up function, it will move forward
  }
  
  else if(skps(p_Down)==0)	//Check whether Down button is pressed		
  {	
    move_down();		//Call move_down function, it will move backward			
  }
		
  else if(skps(p_Left)==0)	//Check whether Left button is pressed		
  {
    move_left();		//Call move_left function, it will move toward left direction			
  }
		
  else if(skps(p_Right)==0)	//Check whether Right button is pressed		
  {
    move_right();		//Call move_right function, it will move toward right direction				
  }
  
  else if(skps(p_Triangle)==0)	//Check whether Triangle button is pressed		
  {	
    deg_30();			//Call deg_30 function, it will move toward 30 degree direction		
  }
  
  if(skps(p_Circle)==0)        //Check whether Circle button is pressed
  {
    deg_150();                 //Call deg_150 function, it will move toward 150 degree direction
  }
  
  else if(skps(p_Cross)==0)    //Check whether Cross button is pressed		
  {	
    deg_210();		       //Call deg_210 function, it will move toward 210 degree direction		
  }

  if(skps(p_Square)==0)        //Check whether Square button is pressed
  {
    deg_330();                 //Call deg_330 function, it will move toward 330 degree direction
  }
  		
  else if(skps(p_L1)==0)       //Check whether L1 button is pressed		
  {
    anticlockwise();		//Call anticlockwise function, it will rotate counterclockwise at the same position		
  }
		
  else if(skps(p_R1)==0)        //Check whether R1 button is pressed		
  {
    clockwise();		//Call clockwise function, it will rotate clockwise at the same position				
  }
  
  else                          //Check whether no button is pressed
  {
    stop();                     //Call stop function, it will stop all the motors
  }
}

unsigned char receive_data(void)  //Function to wait for a byte receive from UART
{
  unsigned char temp;
  while(!Serial.available());    //Wait until data received
  temp=Serial.read();
  return temp;                    //Return the received data
}

unsigned char skps(unsigned char data)	//Function to send out a byte via UART
{										
  Serial.write(data);             //Send new data
  return receive_data();          //Return received data
}

void anticlockwise()
{
  digitalWrite(mtr2_p1, LOW);
  digitalWrite(mtr2_p2, HIGH);
  analogWrite(mtr2_spd, 200);
  
  digitalWrite(mtr3_p1, LOW);
  digitalWrite(mtr3_p2, HIGH);
  analogWrite(mtr3_spd, 200);
  
  digitalWrite(mtr4_p1, LOW);
  digitalWrite(mtr4_p2, HIGH);
  analogWrite(mtr4_spd, 200);
}

void clockwise()
{
  digitalWrite(mtr2_p1, HIGH);
  digitalWrite(mtr2_p2, LOW);
  analogWrite(mtr2_spd, 200);
  
  digitalWrite(mtr3_p1, HIGH);
  digitalWrite(mtr3_p2, LOW);
  analogWrite(mtr3_spd, 200);
   
  digitalWrite(mtr4_p1, HIGH);
  digitalWrite(mtr4_p2, LOW);
  analogWrite(mtr4_spd, 200);
}

void move_up(void)											
{
  digitalWrite(mtr2_p1, HIGH);
  digitalWrite(mtr2_p2, LOW);
  analogWrite(mtr2_spd, 255);
  
  digitalWrite(mtr3_p1, LOW);
  digitalWrite(mtr3_p2, HIGH);
  analogWrite(mtr3_spd, 255);
  
  digitalWrite(mtr4_p1, LOW);
  digitalWrite(mtr4_p2, LOW);
  analogWrite(mtr4_spd, 0);				    		
}

void move_right(void)											
{
  digitalWrite(mtr2_p1, HIGH);
  digitalWrite(mtr2_p2, LOW);
  analogWrite(mtr2_spd, 190);
  
  digitalWrite(mtr3_p1, HIGH);
  digitalWrite(mtr3_p2, LOW);
  analogWrite(mtr3_spd, 190);
  
  digitalWrite(mtr4_p1, LOW);
  digitalWrite(mtr4_p2, HIGH);
  analogWrite(mtr4_spd, 255);						
}

void move_down(void)											
{
  digitalWrite(mtr2_p1, LOW);
  digitalWrite(mtr2_p2, HIGH);
  analogWrite(mtr2_spd, 255);
  
  digitalWrite(mtr3_p1, HIGH);
  digitalWrite(mtr3_p2, LOW);
  analogWrite(mtr3_spd, 255);
  
  digitalWrite(mtr4_p1, LOW);
  digitalWrite(mtr4_p2, LOW);
  analogWrite(mtr4_spd, 0);
}

void move_left(void)											
{
  digitalWrite(mtr2_p1, LOW);
  digitalWrite(mtr2_p2, HIGH);
  analogWrite(mtr2_spd, 190);
  
  digitalWrite(mtr3_p1, LOW);
  digitalWrite(mtr3_p2, HIGH);
  analogWrite(mtr3_spd, 190);
  
  digitalWrite(mtr4_p1, HIGH);
  digitalWrite(mtr4_p2, LOW);
  analogWrite(mtr4_spd, 255);
}

void deg_30(void)
{
  digitalWrite(mtr2_p1, HIGH);
  digitalWrite(mtr2_p2, LOW);
  analogWrite(mtr2_spd, 255);
  
  digitalWrite(mtr3_p1, LOW);
  digitalWrite(mtr3_p2, LOW);
  analogWrite(mtr3_spd, 0);
  
  digitalWrite(mtr4_p1, LOW);
  digitalWrite(mtr4_p2, HIGH);
  analogWrite(mtr4_spd, 255);
}

void deg_150(void)
{
  digitalWrite(mtr2_p1, LOW);
  digitalWrite(mtr2_p2, LOW);
  analogWrite(mtr2_spd, 0);
  
  digitalWrite(mtr3_p1, HIGH);
  digitalWrite(mtr3_p2, LOW);
  analogWrite(mtr3_spd, 255);
  
  digitalWrite(mtr4_p1, LOW);
  digitalWrite(mtr4_p2, HIGH);
  analogWrite(mtr4_spd, 255);
}

void deg_210(void)
{
  digitalWrite(mtr2_p1, LOW);
  digitalWrite(mtr2_p2, HIGH);
  analogWrite(mtr2_spd, 255);
  
  digitalWrite(mtr3_p1, LOW);
  digitalWrite(mtr3_p2, LOW);
  analogWrite(mtr3_spd, 0);
  
  digitalWrite(mtr4_p1, HIGH);
  digitalWrite(mtr4_p2, LOW);
  analogWrite(mtr4_spd, 255);
}

void deg_330(void)
{
  digitalWrite(mtr2_p1, LOW);
  digitalWrite(mtr2_p2, LOW);
  analogWrite(mtr2_spd, 0);
  
  digitalWrite(mtr3_p1, LOW);
  digitalWrite(mtr3_p2, HIGH);
  analogWrite(mtr3_spd, 255);
  
  digitalWrite(mtr4_p1, HIGH);
  digitalWrite(mtr4_p2, LOW);
  analogWrite(mtr4_spd, 255);
}

void stop()
{ 
  digitalWrite(mtr2_p1, LOW);
  digitalWrite(mtr2_p2, LOW);
  analogWrite(mtr2_spd, 0);
  
  digitalWrite(mtr3_p1, LOW);
  digitalWrite(mtr3_p2, LOW);
  analogWrite(mtr3_spd, 0);
  
  digitalWrite(mtr4_p1, LOW);
  digitalWrite(mtr4_p2, LOW);
  analogWrite(mtr4_spd, 0);
}

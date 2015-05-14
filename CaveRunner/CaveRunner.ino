
#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int arrayone[] = {0,1,0,1,0,1,0,0};      //enemies in array one
int arraytwo[] = {0,0,0,0,0,1,0,0};      //enemies in array two
int arraythree[] = {0,1,0,0,1,0,1,0};    //enemies in array three
int arrayfour[] = {0,0,1,1,0,1,0,0};     //enemies in array four
int arrayfive[] = {0,1,0,0,1,1,0,0};     //enemies in array five
int arraysix[] = {0,1,0,1,0,0,1,0};      //enemies in array six
int rx, ry;
  
void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();         // Required code, line 2 of 2.
  Serial.begin(9600);
}

void loop()                   // run over and over again
{
  drawRunner();
  DrawColumns();
  Drawgoal();
  
  CheckButtonsPress();          // Check to see which buttons are pressed
  
  if(Button_Left)               // Move Left
  {
    rx --;
  }
  if(Button_Right)              // Move Right
  {
    rx ++;
  }
  if(Button_Up)                 // Move Up
  {  
    ry ++;
  }
  if(Button_Down)               // Move Down
  {
    ry --;
  }
    
  
  DisplaySlate();               // Write the drawing to the screen.
  delay(1000);                  // waits for a second
  
  ClearSlate();                 // Erase drawing
  DisplaySlate();                  // Write the (now empty) drawing to the screen.
   
  delay(10);                  // waits for a second
  
  updateRunner();               //Update the Runner
  updateEnemies();              //Update the Enemies
                    
}

void DeathScreen()              //Draw Death Screen
 {
  DrawPx(1,1,White);            
  DrawPx(1,2,White);
  DrawPx(1,3,White);
  DrawPx(1,4,White);
  DrawPx(0,4,White);
  DrawPx(0,5,White);
  DrawPx(0,6,White);
  DrawPx(1,5,Red);
  DrawPx(1,6,White);
  DrawPx(1,7,White);
  DrawPx(2,7,White);
  DrawPx(2,6,White);
  DrawPx(2,5,Red);
  DrawPx(2,4,White);
  DrawPx(2,3,White);
  DrawPx(2,2,White);
  DrawPx(3,1,White);
  DrawPx(3,2,White);
  DrawPx(3,3,White);
  DrawPx(3,4,White);
  DrawPx(3,5,White);
  DrawPx(3,6,White);
  DrawPx(3,7,White);
  DrawPx(4,7,White);
  DrawPx(4,6,White);
  DrawPx(4,5,Red);
  DrawPx(4,4,White);
  DrawPx(4,3,White);
  DrawPx(4,2,White);
  DrawPx(5,1,White);
  DrawPx(5,2,White);
  DrawPx(5,3,White);
  DrawPx(5,4,White);
  DrawPx(5,5,Red);
  DrawPx(5,6,White);
  DrawPx(5,7,White);
  DrawPx(6,6,White);
  DrawPx(6,5,White);
  DrawPx(6,4,White);
 }
 
 void DrawColumns()          //Draw Each Seperate Column
 {
   for(int i=0; i < 8; i++)
   {
     DrawPx(1,i,arrayone[i]);            //Draw column one's array
     DrawPx(3,i,arraythree[i]);          //Draw column two's array
     DrawPx(5,i,arrayfive[i]);           //Draw column three's array
     DrawPx(2,i,arraytwo[i]);            //Draw column four's array
     DrawPx(4,i,arrayfour[i]);           //Draw column five's array
     DrawPx(6,i,arraysix[i]);            //Draw column six's array
   }
 }

void drawRunner()
{
  DrawPx(rx,ry,Blue);                      //Draw Runner at point (x,y) in Blue
}
 

void updateRunner()
{
  CheckButtonsPress();      
    if(Button_Right)           //if button right is pressed move one space to the right
    {
      rx++;
    }
    if(Button_Left)            //if button left is pressed move one space to the left
    {
      rx--;
    }
    if(Button_Up)              //if button up is pressed move one space up
    {
      ry++;
    }
    if(Button_Down)            //if button down is pressed move one space down
    { 
      ry--;
    }
    
}
  
void updateEnemies()
{
  int temp;
   for(int i = 0; i < 7; i++)
   {
     temp = arrayone[i];
     arrayone[i] = arrayone[i+1];        
     arrayone[7] = temp;
     
     temp = arraythree[i];
     arraythree[i] = arraythree[i+1];       
     arraythree[7] = temp;
     
     temp = arrayfive[i];
     arrayfive[i] = arrayfive[i+1];
     arrayfive[7] = temp;                
   }
   
   for(int j = 6; j < 0; j--)
   {
     Serial.println("entered second loop");
     temp = arraytwo[j];
     arraytwo[j] = arraytwo[j-1];
//     arraytwo [0] = temp;     
     
     temp = arrayfour[j];
     arrayfour[j] = arrayfour[j-1];
     arrayfour[0] = temp;

     temp = arraysix[j];              
     arraysix[j] = arraysix[j-1];
     arraysix[0] = temp;     
   }
}
  
void Drawgoal()
{
  DrawPx(7,5,2);
}
 

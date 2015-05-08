
#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int arrayone[] = {0,1,1,0,0,1,1,0}; //enemies in
int arraytwo[] = {0,0,1,0,0,1,0,0};
int arraythree[] = {0,1,1,0,1,0,1,0};
int arrayfour[] = {0,0,1,1,0,1,0,0};
int arrayfive[] = {0,1,0,0,1,1,0,0};
int arraysix[] = {0,1,0,1,0,0,1,0};
  
void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop();                     // run over and over again
{
  drawRunner();
  DrawColumns();
  
  
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
    
  
  DisplaySlate();                  // Write the drawing to the screen.
  delay(1000);                  // waits for a second
  
  ClearSlate();                 // Erase drawing
  DisplaySlate();                  // Write the (now empty) drawing to the screen.
   
  delay(1000);                  // waits for a second
  
  updateRunner();               //Update the Runner
  updateEnemies();              //Update the Enemies
  Score();                      //Score
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
   for(int i=0; i < 8; i++);    
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
  DrawPx(0,3,Blue );       //Draw Runner at point (0,3) in Blue
}
 
void Score()            //Score
{
  if(Score == 1)
  { 
    SetAuxLEDsBinary(B10000000);
  }
if(Score == 2)
{
  SetAuxLEDsBinary(B11000000);
}
if(Score == 3)
{
  SetAuxLEDsBinary(B11100000);
}
if(Score == 4)
{
  SetAuxLEDsBinary(B11110000);
}
if(Score == 5)
{
  SetAuxLEDsBinary(B11111000);
}
if(Score == 6)
{
  SetAuxLEDsBinary(B11111100);
}
if(Score == 7)
{ 
  SetAuxLEDsBinary(B11111110);
}
if(Score == 8)
{
  SetAuxLEDsBinary(B11111111);
}
}
void updateRunner()
{
   for(int i = 0; i < 7; i++);    
   {
     int temp = arrayone[i];
     arrayone[i] = arrayone[i+1];            //Draw column one's array
     arrayone[7] = temp;
     
     int temp = arrayone[i];
     arrayone[i] = arrayone[i+1];            //Draw column one's array
     arrayone[7] = temp;
     
     
     DrawPx(3,i,arraythree[i]);          //Draw column two's array
     DrawPx(5,i,arrayfive[i]);           //Draw column three's array
     DrawPx(2,i,arraytwo[i]);            //Draw column four's array
     DrawPx(4,i,arrayfour[i]);           //Draw column five's array
     DrawPx(6,i,arraysix[i]);            //Draw column six's array
   }
}
  

void updateEnemies()
{
 
}

 

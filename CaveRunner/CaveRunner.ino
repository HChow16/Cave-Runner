
#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int arrayone[] = {0,1,0,1,0,1,0,0};      //enemies in array one
int arraytwo[] = {0,1,0,0,0,1,0,0};      //enemies in array two
int arraythree[] = {0,1,0,0,1,0,1,0};    //enemies in array three
int arrayfour[] = {0,0,1,1,0,1,0,0};     //enemies in array four
int arrayfive[] = {0,1,0,0,1,1,0,0};     //enemies in array five
int arraysix[] = {0,1,0,1,0,0,1,0};      //enemies in array six
int rx;
int ry;
int counter = 0;
int level = 1;


  
void setup()                    // run once when the sketch starts
{
  MeggyJrSimpleSetup();         // Required code, line 2 of 2.
}

void loop()                   // run over and over again
{
  if (counter < 100)
    counter++;
  else counter = 0;
  DrawColumns();
  drawRunner();
  Drawgoal();
 // drawDeathScreen();
  
  
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
  delay(100);                  // waits for a second
  
  ClearSlate();                 // Erase drawing
  DisplaySlate();                  // Write the (now empty) drawing to the screen.
   
//  delay(0);                  // waits for a second
 if (ReadPx(rx,ry) == Red)
   {
    rx=0;
    ry=5;
   } 
  //updateEnemies();
  updateRunner();  //Update the Runner
  if (counter%25 == 0)
    updateEnemies();              //Update the Enemies
                    
}

//void drawDeathScreen()              //Draw Death Screen
 //{
  //DrawPx(1,1,White);            
  //DrawPx(1,2,White);
  //DrawPx(1,3,White);
  //DrawPx(1,4,White);
  //DrawPx(0,4,White);
  //DrawPx(0,5,White);
  //DrawPx(0,6,White);
  //DrawPx(1,5,Red);
  //DrawPx(1,6,White);
  //DrawPx(1,7,White);
  //DrawPx(2,7,White);
  //DrawPx(2,6,White);
  //DrawPx(2,5,Red);
  //DrawPx(2,4,White);
  //DrawPx(2,3,White);
  //DrawPx(2,2,White);
 // DrawPx(3,1,White);
 // DrawPx(3,2,White);
 // DrawPx(3,3,White);
 /// DrawPx(3,4,White);
 // DrawPx(3,5,White);
  //DrawPx(3,6,White);
 // /DrawPx(3,7,White);
  //DrawPx(4,7,White);
 // DrawPx(4,6,White);
  //DrawPx(4,5,Red);
//  DrawPx(4,4,White);
//  DrawPx(4,3,White);
//  DrawPx(4,2,White);
//  DrawPx(5,1,White);
//  DrawPx(5,2,White);
//  DrawPx(5,3,White);
//  DrawPx(5,4,White);
 // DrawPx(5,5,Red);
//  DrawPx(5,6,White);
//  DrawPx(5,7,White);
//  DrawPx(6,6,White);
 // DrawPx(6,5,White);
//  DrawPx(6,4,White);
 //}
 
 void DrawColumns()          //Draw Each Seperate Column
 {
   for(int i=0; i < 8; i++)
   {
     for(int j = 6; j > 0; j--)
     {
       DrawPx(1,i,arrayone[i]);            //Draw column one's array
       DrawPx(3,i,arraythree[i]);          //Draw column two's array
       DrawPx(5,i,arrayfive[i]);           //Draw column three's array
       DrawPx(2,j,arraytwo[j]);            //Draw column four's array
       DrawPx(4,j,arrayfour[j]);           //Draw column five's array
       DrawPx(6,j,arraysix[j]);            //Draw column six's array
     }
   }
 }

void drawRunner()
{
  DrawPx(rx,ry,15);   //Draw Runner at point (x,y) in Blue
  if (ReadPx(rx,ry) == Red)
  {
    rx=0;
    ry=5;
  }
}
 

void updateRunner()
{
  CheckButtonsPress();      
    if(Button_Right)           //if button right is pressed move one space to the right
    {
      rx ++;
    }
    if(Button_Left)            //if button left is pressed move one space to the left
    {
      rx --;
    }
    if(Button_Up)              //if button up is pressed move one space up
    {
      ry ++;
    }
    if(Button_Down)            //if button down is pressed move one space down
    { 
      ry --;
    }
    
    if(ry<0)                   //Boundaries for screen
      ry = 0;
    if(ry>7)
      ry = 7;
    if(rx<0)
      rx = 0;
    if(rx>7)
      rx = 7;
    
    if (ReadPx(rx,ry) == Red)
      {
      rx = 0;
      ry = 5;
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
     temp = arraytwo[j];
     arraytwo[j] = arraytwo[j-1];
     arraytwo[0] = temp;     
     
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
  DrawPx(7,5,2);                    //draw the goal at point x=7 y=5 in orange
  ReadPx(rx,ry) == Orange;
  {
    //Tone_Start(18143, 25);
  }
}
 

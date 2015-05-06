/*
  MeggyJr_Blink.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  
  DrawPx(1,1,White);            // Draw a dot at x=3, y=4, in yellow.
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
 
  
 
  
  DisplaySlate();                  // Write the drawing to the screen.
  delay(1000);                  // waits for a second
  
  ClearSlate();                 // Erase drawing
  DisplaySlate();                  // Write the (now empty) drawing to the screen.
   
  delay(1000);                  // waits for a second
}



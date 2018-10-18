#include <stdio.h>

#define SUCCESS 0
#define ERROR   1

enum Colours{
  Default,
  Red,
  Green,
  Yellow,
  Blue,
  Magenta,
  Cyan,
  Gray
};

void setColour( unsigned int colour )
{
  printf( "\033[0;3%dm", colour );
}

void resetColour( )
{
  printf( "\033[0;0m" );
}

void setColourRGB( unsigned int r, unsigned int g, unsigned int b )
{
  printf( "\033[38;2;%d;%d;%dm", r, g, b );
}

// Part 1 - Drawing a grid
void drawGrid( int xSize, int ySize )
{
  // If less than 1, clamp to 1
  xSize = xSize > 1? xSize : 1;
  ySize = ySize > 1? ySize : 1;

  int currentCol = 100;


  int iWidth = 9 * xSize; // Missing 2 for edges

  // Prints top part
  fputs( "█", stdout );
  for ( int i = 0; i < iWidth; i++ ) fputs( "▀", stdout );
  fputs( "█\n", stdout );

  // Prints squares
  for ( int o = 0; o < ySize; o++ )
  {
    if ( o )
    {
      fputs( "█", stdout );
      for ( int i = 0; i < iWidth; i++ ) fputs( " ", stdout );
      fputs( "█\n", stdout );
    }
    for ( int j = 0; j < 3; j++ )
    {
      fputs( "█", stdout );
      
      for ( int x = 0; x < xSize; x++ )
      {
        fputs( " ", stdout );
        setColourRGB( currentCol, currentCol, currentCol );
        currentCol++;
        for ( int i = 0; i < 7; i++ ) fputs( "█", stdout );
        resetColour(  );
        fputs( " ", stdout );
      }
      fputs( "█\n", stdout );
    }
  }
  
  
  fputs( "█", stdout );
  for ( int i = 0; i < iWidth; i++ ) fputs( "▄", stdout );
  fputs( "█\n", stdout );


}


int main(int argc, char const *argv[])
{

  drawGrid( 5, 5 );
  return SUCCESS;
}
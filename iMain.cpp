/*  Project Name : RongRakkhosh , a color monster!
	Made By : K M Fahim Hossain ( 225090 )
	Supervisor : Mushtari Sadia Ma'am
*/

# include "iGraphics.h"
# include <windows.h>
# include <mmsystem.h>
# include <time.h>
# pragma comment(lib , "winmm.lib")

// creating variables for everything

// window
int screenHeight = 1280;
int screenWidth = 720;

// game states
int gameState = 1;
int previousGameState;
int difficulty = 1 ;
int language = 1;
int music = 1;

// position of the balls
int ball11PositionX , ball12PositionX ,  ball13PositionX;
int ball11PositionY , ball12PositionY ,  ball13PositionY;
int ball21PositionX , ball22PositionX ,  ball23PositionX;
int ball21PositionY , ball22PositionY ,  ball23PositionY;
int ball31PositionX , ball32PositionX ,  ball33PositionX;
int ball31PositionY , ball32PositionY ,  ball33PositionY;
int ball41PositionX , ball42PositionX ,  ball43PositionX;
int ball41PositionY , ball42PositionY ,  ball43PositionY;
int ball51PositionX , ball52PositionX ,  ball53PositionX;
int ball51PositionY , ball52PositionY ,  ball53PositionY;
int bombPositionX;
int bombPositionY;
int clockPositionX;
int clockPositionY;

// ball generate 
int ball11Generate = 1 , ball12Generate = 0 , ball13Generate = 0;
int ball21Generate = 1 , ball22Generate = 0 , ball23Generate = 0;
int ball31Generate = 1 , ball32Generate = 0 , ball33Generate = 0;
int ball41Generate = 1 , ball42Generate = 0 , ball43Generate = 0;
int ball51Generate = 1 , ball52Generate = 0 , ball53Generate = 0;
int bombGenerate = 1;
int clockGenerate = 1;

// ball moving
int ball11Move = 1 , ball12Move = 0 , ball13Move = 0;
int ball21Move = 1 , ball22Move = 0 , ball23Move = 0;
int ball31Move = 1 , ball32Move = 0 , ball33Move = 0;
int ball41Move = 1 , ball42Move = 0 , ball43Move = 0;
int ball51Move = 1 , ball52Move = 0 , ball53Move = 0;
int bombMove = 1;
int clockMove = 1;

// ball position change
int ball11PositionChange , ball12PositionChange , ball13PositionChange;
int ball21PositionChange , ball22PositionChange , ball23PositionChange;
int ball31PositionChange , ball32PositionChange , ball33PositionChange;
int ball41PositionChange , ball42PositionChange , ball43PositionChange;
int ball51PositionChange , ball52PositionChange , ball53PositionChange;
int bombPositionChange;
int clockPositionChange;

// box on or off
int box1 = 1;
int box2 = 1;
int box3 = 1;
int box4 = 1;
int box5 = 1;

// box positions
int box1PositionX = 105;
int box1PositionY = 10;
int box2PositionX = 340;
int box2PositionY = 10;
int box3PositionX = 575;
int box3PositionY = 10;
int box4PositionX = 810;
int box4PositionY = 10;
int box5PositionX = 1045;
int box5PositionY = 10;

// other objects
int explotion1 = 0;
int explotion2 = 0;
int explotion3 = 0;
int explotion4 = 0;
int explotion5 = 0;
int explotion6 = 0;
int explotion7 = 0;
int cross1 = 0;
int cross2 = 0;
int cross3 = 0;
int cross4 = 0;
int cross5 = 0;

// other object's positions
int explosion1PositionX;
int explosion1PositionY;
int explosion2PositionX;
int explosion2PositionY;
int explosion3PositionX;
int explosion3PositionY;
int explosion4PositionX;
int explosion4PositionY;
int explosion5PositionX;
int explosion5PositionY;
int explosion6PositionX;
int explosion6PositionY;
int explosion7PositionX;
int explosion7PositionY;
int cross1PositionX;
int cross1PositionY;
int cross2PositionX;
int cross2PositionY;
int cross3PositionX;
int cross3PositionY;
int cross4PositionX;
int cross4PositionY;
int cross5PositionX;
int cross5PositionY;

// showing timer
int timeCount = 0;

// points and point bar
int points = 0;
char pointString[5];

// monster's hand 
int handPositionX = 640;
int handPositionY = 360;

// leaderboard
FILE *eh;
FILE *mh;
FILE *hh;
int eh1 ,eh2 ,eh3 ,eh4 ,eh5;
int mh1 ,mh2 ,mh3 ,mh4 ,mh5;
int hh1 ,hh2 ,hh3 ,hh4 ,hh5;
char seh1[5] ,seh2[5] ,seh3[5] ,seh4[5] ,seh5[5];
char smh1[5] ,smh2[5] ,smh3[5] ,smh4[5] ,smh5[5];
char shh1[5] ,shh2[5] ,shh3[5] ,shh4[5] ,shh5[5];

// initializing the game
void initializeGame()
{
	// initial time
	timeCount = 0;
	points = 0;

	// Position of the balls
	ball11PositionX = -1000 , ball12PositionX = -1000 ,  ball13PositionX = -1000;
	ball11PositionY = -1000 , ball12PositionY = -1000 ,  ball13PositionY = -1000;
	ball21PositionX = -1000 , ball22PositionX = -1000 ,  ball23PositionX = -1000;
	ball21PositionY = -1000 , ball22PositionY = -1000 ,  ball23PositionY = -1000;
	ball31PositionX = -1000 , ball32PositionX = -1000 ,  ball33PositionX = -1000;
	ball31PositionY = -1000 , ball32PositionY = -1000 ,  ball33PositionY = -1000;
	ball41PositionX = -1000 , ball42PositionX = -1000 ,  ball43PositionX = -1000;
	ball41PositionY = -1000 , ball42PositionY = -1000 ,  ball43PositionY = -1000;
	ball51PositionX = -1000 , ball52PositionX = -1000 ,  ball53PositionX = -1000;
	ball51PositionY = -1000 , ball52PositionY = -1000 ,  ball53PositionY = -1000;
	bombPositionX = -1000;
	bombPositionY = -1000;
	clockPositionX = -1000;
	clockPositionY = -1000;	

	// ball generate 
	ball11Generate = 1 , ball12Generate = 0 , ball13Generate = 0;		
	ball21Generate = 1 , ball22Generate = 0 , ball23Generate = 0;
	ball31Generate = 1 , ball32Generate = 0 , ball33Generate = 0;
	ball41Generate = 1 , ball42Generate = 0 , ball43Generate = 0;
	ball51Generate = 1 , ball52Generate = 0 , ball53Generate = 0;
	bombGenerate = 1;
	clockGenerate = 1;

	// ball moving
	ball11Move = 1 , ball12Move = 0 , ball13Move = 0;
	ball21Move = 1 , ball22Move = 0 , ball23Move = 0;
	ball31Move = 1 , ball32Move = 0 , ball33Move = 0;
	ball41Move = 1 , ball42Move = 0 , ball43Move = 0;
	ball51Move = 1 , ball52Move = 0 , ball53Move = 0;
	bombMove = 1;
	clockMove = 1;

	// box on or off
	box1 = 1;
	box2 = 1;
	box3 = 1;
	box4 = 1;
	box5 = 1;

	// box positions
	box1PositionX = 105;
	box1PositionY = 10;
	box2PositionX = 340;
	box2PositionY = 10;
	box3PositionX = 575;
	box3PositionY = 10;
	box4PositionX = 810;
	box4PositionY = 10;
	box5PositionX = 1045;
	box5PositionY = 10;

	// other objects
	explotion1 = 0;
	explotion2 = 0;
	explotion3 = 0;
	explotion4 = 0;
	explotion5 = 0;
	explotion6 = 0;
	explotion7 = 0;
	cross1 = 0;
	cross2 = 0;
	cross3 = 0;
	cross4 = 0;
	cross5 = 0;

	// monster's hand 
	handPositionX = 640;
	handPositionY = 360;
}

// reading the leaderboard
void leaderboard()
{
	eh = fopen("eh.txt", "r");
	mh = fopen("mh.txt", "r");
	hh = fopen("hh.txt", "r");
	fscanf(eh, "%d\n %d\n %d\n %d\n %d\n", &eh1, &eh2, &eh3, &eh4, &eh5);
	fscanf(mh, "%d\n %d\n %d\n %d\n %d\n", &mh1, &mh2, &mh3, &mh4, &mh5);
	fscanf(hh, "%d\n %d\n %d\n %d\n %d\n", &hh1, &hh2, &hh3, &hh4, &hh5);
	sprintf(seh1, "%d\n", eh1);
	sprintf(seh2, "%d\n", eh2);
	sprintf(seh3, "%d\n", eh3);
	sprintf(seh4, "%d\n", eh4);
	sprintf(seh5, "%d\n", eh5);
	sprintf(smh1, "%d\n", mh1);
	sprintf(smh2, "%d\n", mh2);
	sprintf(smh3, "%d\n", mh3);
	sprintf(smh4, "%d\n", mh4);
	sprintf(smh5, "%d\n", mh5);
	sprintf(shh1, "%d\n", hh1);
	sprintf(shh2, "%d\n", hh2);
	sprintf(shh3, "%d\n", hh3);
	sprintf(shh4, "%d\n", hh4);
	sprintf(shh5, "%d\n", hh5);
	fclose(eh);
	fclose(mh);
	fclose(hh);
}

// writing into the leaderboard
void changeLeaderboardE (int  points)
{
	eh = fopen("eh.txt", "w");
	if (points > eh1) 
	{
        eh5 = eh4;
        eh4 = eh3;
        eh3 = eh2;
        eh2 = eh1;
        eh1 = points;
    } 
	else if (points > eh2) 
	{
        eh5 = eh4;
        eh4 = eh3;
        eh3 = eh2;
        eh2 = points;
    } 
	else if (points > eh3)
	{
        eh5 = eh4;
        eh4 = eh3;
        eh3 = points;
    } 
	else if (points > eh4) 
	{
        eh5 = eh4;
        eh4 = points;
    } 
	else if ( points > eh5 )
	{
        eh5 = points;
    }
	fprintf(eh, "%d\n", eh1);
	fprintf(eh, "%d\n", eh2);
    fprintf(eh, "%d\n", eh3);
	fprintf(eh, "%d\n", eh4);
    fprintf(eh, "%d\n", eh5);
	fclose(eh);
}
void changeLeaderboardM (int  points)
{
	mh = fopen("mh.txt", "w");
	if (points > mh1) 
	{
        mh5 = mh4;
        mh4 = mh3;
        mh3 = mh2;
        mh2 = mh1;
        mh1 = points;
    } 
	else if (points > mh2) 
	{
        mh5 = mh4;
        mh4 = mh3;
        mh3 = mh2;
        mh2 = points;
    } else if (points > mh3) 
	{
        mh5 = mh4;
        mh4 = mh3;
        mh3 = points;
    } 
	else if (points > mh4) 
	{
        mh5 = mh4;
        mh4 = points;
    } 
	else if ( points > mh5 )
	{
        mh5 = points;
    }
	fprintf(mh, "%d\n", mh1);
	fprintf(mh, "%d\n", mh2);
    fprintf(mh, "%d\n", mh3);
	fprintf(mh, "%d\n", mh4);
    fprintf(mh, "%d\n", mh5);
	fclose(mh);
}
void changeLeaderboardH (int  points)
{
	hh = fopen("hh.txt", "w");
	if (points > hh1) 
	{
        hh5 = hh4;
        hh4 = hh3;
        hh3 = hh2;
        hh2 = hh1;
        hh1 = points;
    } 
	else if (points > hh2) 
	{
        hh5 = hh4;
        hh4 = hh3;
        hh3 = hh2;
        hh2 = points;
    } 
	else if (points > hh3) 
	{
        hh5 = hh4;
        hh4 = hh3;
        hh3 = points;
    } 
	else if (points > hh4)
	{
        hh5 = hh4;
        hh4 = points;
    } 
	else if ( points > hh5 )
	{
        hh5 = points;
    }
	fprintf(hh, "%d\n", hh1);
	fprintf(hh, "%d\n", hh2);
    fprintf(hh, "%d\n", hh3);
	fprintf(hh, "%d\n", hh4);
    fprintf(hh, "%d\n", hh5);
	fclose(hh);
}


// iGraphics functions
// iGraphics function

// drawing in the screen
void iDraw() 
{
	// showing pages
	if ( gameState == 1)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\1.bmp");
	}
	else if ( gameState == 2)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\2.bmp");
	}
	else if ( gameState == 3)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\3.bmp");
	}
	else if ( gameState == 4)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\4.bmp");
	}
	else if ( gameState == 5)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\5.bmp");
	}
	else if ( gameState == 6)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\6.bmp");
	}
	else if ( gameState == 7)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\7.bmp");
	}
	else if ( gameState == 8)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\8.bmp");
	}
	else if ( gameState == 9)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\9.bmp");
	}
	else if ( gameState == 10)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\10.bmp");
		iText( 205 , 480 , seh1 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 205 , 450 , seh2 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 205 , 420 , seh3 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 205 , 390 , seh4 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 205 , 360 , seh5 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 575 , 480 ,smh1 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 575 , 450 ,smh2 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 575 , 420 ,smh3 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 575 , 390 ,smh4 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 575 , 360 ,smh5 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 950 , 480 ,shh1 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 950 , 450 ,shh2 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 950 , 420 ,shh3 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 950 , 390 ,shh4 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText( 950 , 360 ,shh5 , GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if ( gameState == 11)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\11.bmp");
	}
	else if ( gameState == 12)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\12.bmp");
	}
	else if ( gameState == 13)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\13.bmp");
	}
	else if ( gameState == 14)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\14.bmp");
	}
	else if ( gameState == 15)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\15.bmp");
	}
	else if ( gameState == 16 )
	{
		iClear();
		iShowBMP( 0 ,0, "files\\16.bmp");
	}
	else if ( gameState == 17)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\17.bmp");
	}
	else if ( gameState == 18 )
	{
		iClear();
		iShowBMP( 0 ,0, "files\\18.bmp");
		iText( 645 , 450 , pointString , GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if ( gameState == 19)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\19.bmp");
	}
	else if ( gameState == 20)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\20.bmp");
	}
	else if ( gameState == 21)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\21.bmp");
	}

	else if ( gameState == 22)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\22.bmp");
		iText( 645 , 450 , pointString , GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if ( gameState == 23)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\23.bmp");
	}

	else if ( gameState == 24)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\24.bmp");
	}

	else if ( gameState == 25)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\25.bmp");
	}

	else if ( gameState == 26)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\26.bmp");
		iText( 645 , 450 , pointString , GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if ( gameState == 27)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\27.bmp");
	}

	else if ( gameState == 28)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\28.bmp");
	}

	else if ( gameState == 29)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\29.bmp");
	}

	// main game
	else if ( gameState == 51)
	{
	// background
	iClear();
	if ( difficulty == 1)
	{	
		iClear();
		iShowBMP( 0 ,0, "files\\15.bmp");
	}
	if ( difficulty == 2)
	{	
		iClear();
		iShowBMP( 0 ,0, "files\\19.bmp");
	}
	if ( difficulty == 3)
	{
		iClear();
		iShowBMP( 0 ,0, "files\\23.bmp");
	}

	// explosion 
	if ( explotion1 == 1)
	{
		iShowBMP2( explosion1PositionX ,explosion1PositionY, "files\\explosion1.bmp" , 0);
	}
	if ( explotion2 == 2)
	{
		iShowBMP2( explosion2PositionX ,explosion2PositionY, "files\\explosion2.bmp" , 0);
	}
	if ( explotion3 == 3)
	{
		iShowBMP2( explosion3PositionX ,explosion3PositionY, "files\\explosion3.bmp" , 0);
	}
	if ( explotion4 == 4)
	{
		iShowBMP2( explosion4PositionX ,explosion4PositionY, "files\\explosion4.bmp" , 0);
	}
	if ( explotion5 == 5)
	{
		iShowBMP2( explosion5PositionX ,explosion5PositionY, "files\\explosion5.bmp" , 0);
	}
	if ( explotion6 == 6)
	{
		iShowBMP2( explosion6PositionX ,explosion6PositionY, "files\\explosion6.bmp" , 0);
	}
	if ( explotion7 == 7)
	{
		iShowBMP2( explosion7PositionX ,explosion7PositionY, "files\\explosion7.bmp" , 0);
	}

	// draw boxes
	iShowBMP2( box1PositionX ,box1PositionY, "files\\box1.bmp" , 0);
	iShowBMP2( box2PositionX ,box2PositionY, "files\\box2.bmp" , 0);
	iShowBMP2( box3PositionX ,box3PositionY, "files\\box3.bmp" , 0);
	iShowBMP2( box4PositionX ,box4PositionY, "files\\box4.bmp" , 0);
	iShowBMP2( box5PositionX ,box5PositionY, "files\\box5.bmp" , 0);

	// draw cross
	if ( cross1 == 1)
	{
		iShowBMP2( box1PositionX - 25 ,box1PositionY, "files\\cross.bmp" , 0);
	}
	if ( cross2 == 1)
	{
		iShowBMP2( box2PositionX - 25 ,box2PositionY, "files\\cross.bmp" , 0);
	}
	if ( cross3 == 1)
	{
		iShowBMP2( box3PositionX - 25 ,box3PositionY, "files\\cross.bmp" , 0);
	}
	if ( cross4 == 1)
	{
		iShowBMP2( box4PositionX - 25 ,box4PositionY, "files\\cross.bmp" , 0);
	}
	if ( cross5 == 1)
	{
		iShowBMP2( box5PositionX - 25 ,box5PositionY, "files\\cross.bmp" , 0);
	}

	// draw scorebar
	iSetColor( 26 , 35, 126);
    iFilledRectangle( 6 , 0 , 9, points*6.5 );

	// draw timer
	if ( difficulty == 1)
	{
		iSetColor( 26 , 35, 126);
    	iFilledRectangle( 1263 , 00, 11.5, 665 - timeCount*0.3694 );
	}
	else if ( difficulty == 2)
	{
		iSetColor( 26 , 35, 126);
    	iFilledRectangle( 1263 , 00, 11.5, 665 - timeCount*.7388 );
	}
	else if ( difficulty == 3)
	{
		iSetColor( 26 , 35, 126);
    	iFilledRectangle( 1263 , 00, 11.5, 665 - timeCount*1.1083 );
	}

	// draw balls
	iSetColor( 0 , 135, 62);
	iFilledCircle(ball11PositionX , ball11PositionY , 20 , 8);
	iSetColor( 234 , 196, 53);
	iFilledCircle(ball21PositionX , ball21PositionY , 20 , 8);
	iSetColor( 52 , 89, 149);
	iFilledCircle(ball31PositionX , ball31PositionY , 20 , 8);
	iSetColor( 3 , 206, 164);
	iFilledCircle(ball41PositionX , ball41PositionY , 20 , 8);
	iSetColor( 202 , 21, 81);
	iFilledCircle(ball51PositionX , ball51PositionY , 20 , 8);
	iSetColor( 0 , 135, 62);
	iFilledCircle(ball12PositionX , ball12PositionY , 20 , 5);
	iSetColor( 234 , 196, 53);
	iFilledCircle(ball22PositionX , ball22PositionY , 20 , 5);
	iSetColor( 52 , 89, 149);
	iFilledCircle(ball32PositionX , ball32PositionY , 20 , 5);
	iSetColor( 3 , 206, 164);
	iFilledCircle(ball42PositionX , ball42PositionY , 20 , 5);
	iSetColor( 202 , 21, 81);
	iFilledCircle(ball52PositionX , ball52PositionY , 20 , 5);
	iSetColor( 0 , 135, 62);
	iFilledCircle(ball13PositionX , ball13PositionY , 20 , 80);
	iSetColor( 234 , 196, 53);
	iFilledCircle(ball23PositionX , ball23PositionY , 20 , 80);
	iSetColor( 52 , 89, 149);
	iFilledCircle(ball33PositionX , ball33PositionY , 20 , 80);
	iSetColor( 3 , 206, 164);
	iFilledCircle(ball43PositionX , ball43PositionY , 20 , 80);
	iSetColor( 202 , 21, 81);
	iFilledCircle(ball53PositionX , ball53PositionY , 20 , 80);

	// draw other objects 
	iShowBMP2( bombPositionX , bombPositionY , "files\\bomb.bmp" , 0);
	iShowBMP2( clockPositionX , clockPositionY , "files\\clock.bmp" , 0);

	// draw hand
	if ( difficulty == 1 || difficulty == 2)
	{
		iShowBMP2( handPositionX , handPositionY , "files\\hand.bmp" , 0);
	}
	else if ( difficulty == 3)
	{
		iShowBMP2( handPositionX , handPositionY , "files\\hand2.bmp" , 0);
	}
	}
}


// taking input of positions for moving the mouse
void iMouseMove(int mx, int my) 
{
	// hand moving
	handPositionX = mx - 32;
	handPositionY = my - 32;

	// ball selecting and moving
	// ball 1
    if ( mx >= (ball11PositionX - 50) && mx <= (ball11PositionX + 50) && 
		 my >= (ball11PositionY - 50) && my <= (ball11PositionY + 50) )
	{
		ball11PositionX = mx;
		ball11PositionY = my;
		ball11Move = 0;
		ball11Generate = 0;
		ball12Generate = 1;
		ball12Move = 1;
	}
	else if ( mx >= (ball12PositionX - 50) && mx <= (ball12PositionX + 50) && 
		      my >= (ball12PositionY - 50) && my <= (ball12PositionY + 50) )
	{
		ball12PositionX = mx;
		ball12PositionY = my;
		ball12Move = 0;
		ball12Generate = 0;
		ball13Generate = 1;
		ball13Move = 1;

	}
	else if ( mx >= (ball13PositionX - 50) && mx <= (ball13PositionX + 50) && 
		  	  my >= (ball13PositionY - 50) && my <= (ball13PositionY + 50) )
	{
		ball13PositionX = mx;
		ball13PositionY = my;
		ball13Move = 0;
		ball13Generate = 0;
		ball11Generate = 1;
		ball11Move = 1;

	}
	// ball 2
	else if ( mx >= (ball21PositionX - 50) && mx <= (ball21PositionX + 50) && 
			  my >= (ball21PositionY - 50) && my <= (ball21PositionY + 50) )
	{
		ball21PositionX = mx;
		ball21PositionY = my;
		ball21Move = 0;
		ball21Generate = 0;
		ball22Generate = 1;
		ball22Move = 1;

	}
	else if ( mx >= (ball22PositionX - 50) && mx <= (ball22PositionX + 50) && 
			  my >= (ball22PositionY - 50) && my <= (ball22PositionY + 50) )
	{
		ball22PositionX = mx;
		ball22PositionY = my;
		ball22Move = 0;
		ball22Generate = 0;
		ball23Generate = 1;
		ball23Move = 1;

	}
	else if ( mx >= (ball23PositionX - 50) && mx <= (ball23PositionX + 50) && 
			  my >= (ball23PositionY - 50) && my <= (ball23PositionY + 50) )
	{
		ball23PositionX = mx;
		ball23PositionY = my;
		ball23Move = 0;
		ball23Generate = 0;
		ball21Generate = 1;
		ball21Move = 1;

	}
	// ball 3
	else if ( mx >= (ball31PositionX - 50) && mx <= (ball31PositionX + 50) && 
			  my >= (ball31PositionY - 50) && my <= (ball31PositionY + 50) )
	{
		ball31PositionX = mx;
		ball31PositionY = my;
		ball31Move = 0;
		ball31Generate = 0;
		ball32Generate = 1;
		ball32Move = 1;

	}
	else if ( mx >= (ball32PositionX - 50) && mx <= (ball32PositionX + 50) && 
			  my >= (ball32PositionY - 50) && my <= (ball32PositionY + 50) )
	{
		ball32PositionX = mx;
		ball32PositionY = my;
		ball32Move = 0;
		ball32Generate = 0;
		ball33Generate = 1;
		ball33Move = 1;

	}
	else if ( mx >= (ball33PositionX - 50) && mx <= (ball33PositionX + 50) && 
			  my >= (ball33PositionY - 50) && my <= (ball33PositionY + 50) )
	{
		ball33PositionX = mx;
		ball33PositionY = my;
		ball33Move = 0;
		ball33Generate = 0;
		ball31Generate = 1;
		ball31Move = 1;

	}
	// ball 4
	else if ( mx >= (ball41PositionX - 50) && mx <= (ball41PositionX + 50) && 
			  my >= (ball41PositionY - 50) && my <= (ball41PositionY + 50) )
	{
		ball41PositionX = mx;
		ball41PositionY = my;
		ball41Move = 0;
		ball41Generate = 0;
		ball42Generate = 1;
		ball42Move = 1;

	}
	else if ( mx >= (ball42PositionX - 50) && mx <= (ball42PositionX + 50) && 
			  my >= (ball42PositionY - 50) && my <= (ball42PositionY + 50) )
	{
		ball42PositionX = mx;
		ball42PositionY = my;
		ball42Move = 0;
		ball42Generate = 0;
		ball43Generate = 1;
		ball43Move = 1;

	}
	else if ( mx >= (ball43PositionX - 50) && mx <= (ball43PositionX + 50) && 
			  my >= (ball43PositionY - 50) && my <= (ball43PositionY + 50) )
	{
		ball43PositionX = mx;
		ball43PositionY = my;
		ball43Move = 0;
		ball43Generate = 0;
		ball41Generate = 1;
		ball41Move = 1;

	}
	// ball 5
	else if ( mx >= (ball51PositionX - 50) && mx <= (ball51PositionX + 50) && 
			  my >= (ball51PositionY - 50) && my <= (ball51PositionY + 50) )
	{
		ball51PositionX = mx;
		ball51PositionY = my;
		ball51Move = 0;
		ball51Generate = 0;
		ball52Generate = 1;
		ball52Move = 1;
		
	}
	else if ( mx >= (ball52PositionX - 50) && mx <= (ball52PositionX + 50) && 
			  my >= (ball52PositionY - 50) && my <= (ball52PositionY + 50) )
	{
		ball52PositionX = mx;
		ball52PositionY = my;
		ball52Move = 0;
		ball52Generate = 0;
		ball53Generate = 1;
		ball53Move = 1;

	}
	else if ( mx >= (ball53PositionX - 50) && mx <= (ball53PositionX + 50) && 
			  my >= (ball53PositionY - 50) && my <= (ball53PositionY + 50) )
	{
		ball53PositionX = mx;
		ball53PositionY = my;
		ball53Move = 0;
		ball53Generate = 0;
		ball51Generate = 1;
		ball51Move = 1;

	}

	// clock selecting and moving
	if ( mx >= (clockPositionX) && mx <= (clockPositionX + 80) && 
	     my >= (clockPositionY) && my <= (clockPositionY + 80) )
	{
		clockPositionX = mx - 40;
		clockPositionY = my - 40;
		clockMove = 0;
		clockGenerate = 0;
	}

	// box selecting and moving 
	if ( box1 == 1 &&
		 mx >= box1PositionX && mx <= box1PositionX + 130 && 
		 my >= box1PositionY && my <= box1PositionY + 130 )
	{
		box1PositionX = mx - 65;
		box1PositionY = my - 65;
	}
	else if ( box2 == 1 &&
		 mx >= box2PositionX && mx <= box2PositionX + 130 && 
		 my >= box2PositionY && my <= box2PositionY + 130 )
	{
		box2PositionX = mx - 65;
		box2PositionY = my - 65;
	}
	else if ( box3 == 1 &&
		 mx >= box3PositionX && mx <= box3PositionX + 130 && 
		 my >= box3PositionY && my <= box3PositionY + 130 )
	{
		box3PositionX = mx - 65;
		box3PositionY = my - 65;
	}
	else if ( box4 == 1 &&
		 mx >= box4PositionX && mx <= box4PositionX + 130 && 
		 my >= box4PositionY && my <= box4PositionY + 130 )
	{
		box4PositionX = mx - 65;
		box4PositionY = my - 65;
	}
	else if ( box5 == 1 &&
		 mx >= box5PositionX && mx <= box5PositionX + 130 && 
		 my >= box5PositionY && my <= box5PositionY + 130 )
	{
		box5PositionX = mx - 65;
		box5PositionY = my - 65;
	}
	
	// ball in correct box or wrong box
	// ball 1
	if ( ball11PositionX == mx && box1 == 1 &&
	     ball11PositionX >= box1PositionX && ball11PositionX <= box1PositionX + 130 &&
		 ball11PositionY >= box1PositionY && ball11PositionY <= box1PositionY + 130 )
	{
		ball11PositionX = -1000;
		ball11PositionY = -1000;
		points = points + 1;
		ball11Move = 1;
		ball11Generate = 1;
	}
	else if ( (ball11PositionX == mx) &&
	   		  ((ball11PositionX >= box2PositionX && ball11PositionX <= box2PositionX + 130 &&
			    ball11PositionY >= box2PositionY && ball11PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball11PositionX >= box3PositionX && ball11PositionX <= box3PositionX + 130 &&
			    ball11PositionY >= box3PositionY && ball11PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball11PositionX >= box4PositionX && ball11PositionX <= box4PositionX + 130 &&
			    ball11PositionY >= box4PositionY && ball11PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball11PositionX >= box5PositionX && ball11PositionX <= box5PositionX + 130 &&
			    ball11PositionY >= box5PositionY && ball11PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball11PositionX = -1000;
		ball11PositionY = -1000;
		ball11Move = 1;
		ball11Generate = 1;
		points = points - 1;
    }
	else if ( ball12PositionX == mx && box1 == 1 &&
	     ball12PositionX >= box1PositionX && ball12PositionX <= box1PositionX + 130 &&
		 ball12PositionY >= box1PositionY && ball12PositionY <= box1PositionY + 130 )
	{
		ball12PositionX = -1000;
		ball12PositionY = -1000;
		points = points + 1;
		ball12Move = 1;
		ball12Generate = 1;
	}
	else if ( (ball12PositionX == mx) && 
	   		  ((ball12PositionX >= box2PositionX && ball12PositionX <= box2PositionX + 130 &&
			    ball12PositionY >= box2PositionY && ball12PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball12PositionX >= box3PositionX && ball12PositionX <= box3PositionX + 130 &&
			    ball12PositionY >= box3PositionY && ball12PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball12PositionX >= box4PositionX && ball12PositionX <= box4PositionX + 130 &&
			    ball12PositionY >= box4PositionY && ball12PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball12PositionX >= box5PositionX && ball12PositionX <= box5PositionX + 130 &&
			    ball12PositionY >= box5PositionY && ball12PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball12PositionX = -1000;
		ball12PositionY = -1000;
		ball12Move = 1;
		ball12Generate = 1;
		points = points - 1;
    }
	else if ( ball13PositionX == mx && box1 == 1 &&
	     ball13PositionX >= box1PositionX && ball13PositionX <= box1PositionX + 130 &&
		 ball13PositionY >= box1PositionY && ball13PositionY <= box1PositionY + 130 )
	{
		ball13PositionX = -1000;
		ball13PositionY = -1000;
		points = points + 1;
		ball13Move = 1;
		ball13Generate = 1;
	}
	else if ( (ball13PositionX == mx) && 
	   		  ((ball13PositionX >= box2PositionX && ball13PositionX <= box2PositionX + 130 &&
			    ball13PositionY >= box2PositionY && ball13PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball13PositionX >= box3PositionX && ball13PositionX <= box3PositionX + 130 &&
			    ball13PositionY >= box3PositionY && ball13PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball13PositionX >= box4PositionX && ball13PositionX <= box4PositionX + 130 &&
			    ball13PositionY >= box4PositionY && ball13PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball13PositionX >= box5PositionX && ball13PositionX <= box5PositionX + 130 &&
			    ball13PositionY >= box5PositionY && ball13PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball13PositionX = -1000;
		ball13PositionY = -1000;
		ball13Move = 1;
		ball13Generate = 1;
		points = points - 1;
    }

	// ball 2
	if ( ball21PositionX == mx && box2 == 1 &&
	     ball21PositionX >= box2PositionX && ball21PositionX <= box2PositionX + 130 &&
		 ball21PositionY >= box2PositionY && ball21PositionY <= box2PositionY + 130 )
	{
		ball21PositionX = -1000;
		ball21PositionY = -1000;
		points = points + 1;
		ball21Move = 1;
		ball21Generate = 1;
	}
	else if ( (ball21PositionX == mx) && 
	   		  ((ball21PositionX >= box1PositionX && ball21PositionX <= box1PositionX + 130 &&
			    ball21PositionY >= box1PositionY && ball21PositionY <= box1PositionY + 130 && box1 == 1) ||
			   (ball21PositionX >= box3PositionX && ball21PositionX <= box3PositionX + 130 &&
			    ball21PositionY >= box3PositionY && ball21PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball21PositionX >= box4PositionX && ball21PositionX <= box4PositionX + 130 &&
			    ball21PositionY >= box4PositionY && ball21PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball21PositionX >= box5PositionX && ball21PositionX <= box5PositionX + 130 &&
			    ball21PositionY >= box5PositionY && ball21PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball21PositionX = -1000;
		ball21PositionY = -1000;
		ball21Move = 1;
		ball21Generate = 1;
		points = points - 1;
    }
	else if ( ball22PositionX == mx && box2 == 1 &&
	     ball22PositionX >= box2PositionX && ball22PositionX <= box2PositionX + 130 &&
		 ball22PositionY >= box2PositionY && ball22PositionY <= box2PositionY + 130 )
	{
		ball22PositionX = -1000;
		ball22PositionY = -1000;
		points = points + 1;
		ball22Move = 1;
		ball22Generate = 1;
	}
	else if ( (ball22PositionX == mx) && 
	   		  ((ball22PositionX >= box1PositionX && ball22PositionX <= box1PositionX + 130 &&
			    ball22PositionY >= box1PositionY && ball22PositionY <= box1PositionY + 130 && box1 == 1) ||
			   (ball22PositionX >= box3PositionX && ball22PositionX <= box3PositionX + 130 &&
			    ball22PositionY >= box3PositionY && ball22PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball22PositionX >= box4PositionX && ball22PositionX <= box4PositionX + 130 &&
			    ball22PositionY >= box4PositionY && ball22PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball22PositionX >= box5PositionX && ball22PositionX <= box5PositionX + 130 &&
			    ball22PositionY >= box5PositionY && ball22PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball22PositionX = -1000;
		ball22PositionY = -1000;
		ball22Move = 1;
		ball22Generate = 1;
		points = points - 1;
    }
	else if ( ball23PositionX == mx && box2 == 1 &&
	     ball23PositionX >= box2PositionX && ball23PositionX <= box2PositionX + 130 &&
		 ball23PositionY >= box2PositionY && ball23PositionY <= box2PositionY + 130 )
	{
		ball23PositionX = -1000;
		ball23PositionY = -1000;
		points = points + 1;
		ball23Move = 1;
		ball23Generate = 1;
	}
	else if ( (ball23PositionX == mx) && box2 == 1 &&
	   		  ((ball23PositionX >= box1PositionX && ball23PositionX <= box1PositionX + 130 &&
			    ball23PositionY >= box1PositionY && ball23PositionY <= box1PositionY + 130 && box1 == 1) ||
			   (ball23PositionX >= box3PositionX && ball23PositionX <= box3PositionX + 130 &&
			    ball23PositionY >= box3PositionY && ball23PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball23PositionX >= box4PositionX && ball23PositionX <= box4PositionX + 130 &&
			    ball23PositionY >= box4PositionY && ball23PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball23PositionX >= box5PositionX && ball23PositionX <= box5PositionX + 130 &&
			    ball23PositionY >= box5PositionY && ball23PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball23PositionX = -1000;
		ball23PositionY = -1000;
		ball23Move = 1;
		ball23Generate = 1;
		points = points - 1;
    }

	// ball 3
	if ( ball31PositionX == mx && box3 == 1 &&
	     ball31PositionX >= box3PositionX && ball31PositionX <= box3PositionX + 130 &&
		 ball31PositionY >= box3PositionY && ball31PositionY <= box3PositionY + 130 )
	{
		ball31PositionX = -1000;
		ball31PositionY = -1000;
		points = points + 1;
		ball31Move = 1;
		ball31Generate = 1;
	}
	else if ( (ball31PositionX == mx) && 
	   		  ((ball31PositionX >= box2PositionX && ball31PositionX <= box2PositionX + 130 &&
			    ball31PositionY >= box2PositionY && ball31PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball31PositionX >= box1PositionX && ball31PositionX <= box1PositionX + 130 &&
			    ball31PositionY >= box1PositionY && ball31PositionY <= box1PositionY + 130 && box1 == 1) ||
			   (ball31PositionX >= box4PositionX && ball31PositionX <= box4PositionX + 130 &&
			    ball31PositionY >= box4PositionY && ball31PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball31PositionX >= box5PositionX && ball31PositionX <= box5PositionX + 130 &&
			    ball31PositionY >= box5PositionY && ball31PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball31PositionX = -1000;
		ball31PositionY = -1000;
		ball31Move = 1;
		ball31Generate = 1;
		points = points - 1;
    }
	else if ( ball32PositionX == mx && box3 == 1 &&
	     ball32PositionX >= box3PositionX && ball32PositionX <= box3PositionX + 130 &&
		 ball32PositionY >= box3PositionY && ball32PositionY <= box3PositionY + 130 )
	{
		ball32PositionX = -1000;
		ball32PositionY = -1000;
		points = points + 1;
		ball32Move = 1;
		ball32Generate = 1;
	}
	else if ( (ball32PositionX == mx) && 
	   		  ((ball32PositionX >= box2PositionX && ball32PositionX <= box2PositionX + 130 &&
			    ball32PositionY >= box2PositionY && ball32PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball32PositionX >= box1PositionX && ball32PositionX <= box1PositionX + 130 &&
			    ball32PositionY >= box1PositionY && ball32PositionY <= box1PositionY + 130 && box1 == 1) ||
			   (ball32PositionX >= box4PositionX && ball32PositionX <= box4PositionX + 130 &&
			    ball32PositionY >= box4PositionY && ball32PositionY <= box4PositionY + 130 && box2 == 1) ||
			   (ball32PositionX >= box5PositionX && ball32PositionX <= box5PositionX + 130 &&
			    ball32PositionY >= box5PositionY && ball32PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball32PositionX = -1000;
		ball32PositionY = -1000;
		ball32Move = 1;
		ball32Generate = 1;
		points = points - 1;
    }
	else if ( ball33PositionX == mx && box3 == 1 &&
	     ball33PositionX >= box3PositionX && ball33PositionX <= box3PositionX + 130 &&
		 ball33PositionY >= box3PositionY && ball33PositionY <= box3PositionY + 130 )
	{
		ball33PositionX = -1000;
		ball33PositionY = -1000;
		points = points + 1;
		ball33Move = 1;
		ball33Generate = 1;
	}
	else if ( (ball33PositionX == mx) && 
	   		  ((ball33PositionX >= box2PositionX && ball33PositionX <= box2PositionX + 130 &&
			    ball33PositionY >= box2PositionY && ball33PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball33PositionX >= box1PositionX && ball33PositionX <= box1PositionX + 130 &&
			    ball33PositionY >= box1PositionY && ball33PositionY <= box1PositionY + 130 && box1 == 1) ||
			   (ball33PositionX >= box4PositionX && ball33PositionX <= box4PositionX + 130 &&
			    ball33PositionY >= box4PositionY && ball33PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball33PositionX >= box5PositionX && ball33PositionX <= box5PositionX + 130 &&
			    ball33PositionY >= box5PositionY && ball33PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball33PositionX = -1000;
		ball33PositionY = -1000;
		ball33Move = 1;
		ball33Generate = 1;
		points = points - 1;
    }

	// ball 4
	if ( ball41PositionX == mx && box4 == 1 &&
	     ball41PositionX >= box4PositionX && ball41PositionX <= box4PositionX + 130 &&
		 ball41PositionY >= box4PositionY && ball41PositionY <= box4PositionY + 130 )
	{
		ball41PositionX = -1000;
		ball41PositionY = -1000;
		points = points + 1;
		ball41Move = 1;
		ball41Generate = 1;
	}
	else if ( (ball41PositionX == mx) && 
	   		  ((ball41PositionX >= box2PositionX && ball41PositionX <= box2PositionX + 130 &&
			    ball41PositionY >= box2PositionY && ball41PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball41PositionX >= box3PositionX && ball41PositionX <= box3PositionX + 130 &&
			    ball41PositionY >= box3PositionY && ball41PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball41PositionX >= box1PositionX && ball41PositionX <= box1PositionX + 130 &&
			    ball41PositionY >= box1PositionY && ball41PositionY <= box1PositionY + 130 && box1 == 1) ||
			   (ball41PositionX >= box5PositionX && ball41PositionX <= box5PositionX + 130 &&
			    ball41PositionY >= box5PositionY && ball41PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball41PositionX = -1000;
		ball41PositionY = -1000;
		ball41Move = 1;
		ball41Generate = 1;
		points = points - 1;
    }
	else if ( ball42PositionX == mx && box4 == 1 &&
	     ball42PositionX >= box4PositionX && ball42PositionX <= box4PositionX + 130 &&
		 ball42PositionY >= box4PositionY && ball42PositionY <= box4PositionY + 130 )
	{
		ball42PositionX = -1000;
		ball42PositionY = -1000;
		points = points + 1;
		ball42Move = 1;
		ball42Generate = 1;
	}
	else if ( (ball42PositionX == mx) && 
	   		  ((ball42PositionX >= box2PositionX && ball42PositionX <= box2PositionX + 130 &&
			    ball42PositionY >= box2PositionY && ball42PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball42PositionX >= box3PositionX && ball42PositionX <= box3PositionX + 130 &&
			    ball42PositionY >= box3PositionY && ball42PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball42PositionX >= box1PositionX && ball42PositionX <= box1PositionX + 130 &&
			    ball42PositionY >= box1PositionY && ball42PositionY <= box1PositionY + 130 && box1 == 1) ||
			   (ball42PositionX >= box5PositionX && ball42PositionX <= box5PositionX + 130 &&
			    ball42PositionY >= box5PositionY && ball42PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball42PositionX = -1000;
		ball42PositionY = -1000;
		ball42Move = 1;
		ball42Generate = 1;
		points = points - 1;
    }
	else if ( ball43PositionX == mx && box4 == 1 &&
	     ball43PositionX >= box4PositionX && ball43PositionX <= box4PositionX + 130 &&
		 ball43PositionY >= box4PositionY && ball43PositionY <= box4PositionY + 130 )
	{
		ball43PositionX = -1000;
		ball43PositionY = -1000;
		points = points + 1;
		ball43Move = 1;
		ball43Generate = 1;
	}
	else if ( (ball43PositionX == mx) && 
	   		  ((ball43PositionX >= box2PositionX && ball43PositionX <= box2PositionX + 130 &&
			    ball43PositionY >= box2PositionY && ball43PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball43PositionX >= box3PositionX && ball43PositionX <= box3PositionX + 130 &&
			    ball43PositionY >= box3PositionY && ball43PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball43PositionX >= box1PositionX && ball43PositionX <= box1PositionX + 130 &&
			    ball43PositionY >= box1PositionY && ball43PositionY <= box1PositionY + 130 && box1 == 1) ||
			   (ball43PositionX >= box5PositionX && ball43PositionX <= box5PositionX + 130 &&
			    ball43PositionY >= box5PositionY && ball43PositionY <= box5PositionY + 130 && box5 == 1)))
	{
		ball43PositionX = -1000;
		ball43PositionY = -1000;
		ball43Move = 1;
		ball43Generate = 1;
		points = points - 1;
    }

	// ball 5
	if ( ball51PositionX == mx && box5 == 1 &&
	     ball51PositionX >= box5PositionX && ball51PositionX <= box5PositionX + 130 &&
		 ball51PositionY >= box5PositionY && ball51PositionY <= box5PositionY + 130 )
	{
		ball51PositionX = -1000;
		ball51PositionY = -1000;
		points = points + 1;
		ball51Move = 1;
		ball51Generate = 1;
	}
	else if ( (ball51PositionX == mx) && 
	   		  ((ball51PositionX >= box2PositionX && ball51PositionX <= box2PositionX + 130 &&
			    ball51PositionY >= box2PositionY && ball51PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball51PositionX >= box3PositionX && ball51PositionX <= box3PositionX + 130 &&
			    ball51PositionY >= box3PositionY && ball51PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball51PositionX >= box4PositionX && ball51PositionX <= box4PositionX + 130 &&
			    ball51PositionY >= box4PositionY && ball51PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball51PositionX >= box1PositionX && ball51PositionX <= box1PositionX + 130 &&
			    ball51PositionY >= box1PositionY && ball51PositionY <= box1PositionY + 130 && box1 == 1)))
	{
		ball51PositionX = -1000;
		ball51PositionY = -1000;
		ball51Move = 1;
		ball51Generate = 1;
		points = points - 1;
    }
	else if ( ball52PositionX == mx && box5 == 1 &&
	     ball52PositionX >= box5PositionX && ball52PositionX <= box5PositionX + 130 &&
		 ball52PositionY >= box5PositionY && ball52PositionY <= box5PositionY + 130 )
	{
		ball52PositionX = -1000;
		ball52PositionY = -1000;
		points = points + 1;
		ball52Move = 1;
		ball52Generate = 1;
	}
	else if ( (ball52PositionX == mx) && 
	   		  ((ball52PositionX >= box2PositionX && ball52PositionX <= box2PositionX + 130 &&
			    ball52PositionY >= box2PositionY && ball52PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball52PositionX >= box3PositionX && ball52PositionX <= box3PositionX + 130 &&
			    ball52PositionY >= box3PositionY && ball52PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball52PositionX >= box4PositionX && ball52PositionX <= box4PositionX + 130 &&
			    ball52PositionY >= box4PositionY && ball52PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball52PositionX >= box1PositionX && ball52PositionX <= box1PositionX + 130 &&
			    ball52PositionY >= box1PositionY && ball52PositionY <= box1PositionY + 130 && box1 == 1)))
	{
		ball52PositionX = -1000;
		ball52PositionY = -1000;
		ball52Move = 1;
		ball52Generate = 1;
		points = points - 1;
    }
	else if ( ball53PositionX == mx && box5 == 1 &&
	     ball53PositionX >= box5PositionX && ball53PositionX <= box5PositionX + 130 &&
		 ball53PositionY >= box5PositionY && ball53PositionY <= box5PositionY + 130 )
	{
		ball53PositionX = -1000;
		ball53PositionY = -1000;
		points = points + 1;
		ball53Move = 1;
		ball53Generate = 1;
	}
	else if ( (ball53PositionX == mx) && 
	   		  ((ball53PositionX >= box2PositionX && ball53PositionX <= box2PositionX + 130 &&
			    ball53PositionY >= box2PositionY && ball53PositionY <= box2PositionY + 130 && box2 == 1) ||
			   (ball53PositionX >= box3PositionX && ball53PositionX <= box3PositionX + 130 &&
			    ball53PositionY >= box3PositionY && ball53PositionY <= box3PositionY + 130 && box3 == 1) ||
			   (ball53PositionX >= box4PositionX && ball53PositionX <= box4PositionX + 130 &&
			    ball53PositionY >= box4PositionY && ball53PositionY <= box4PositionY + 130 && box4 == 1) ||
			   (ball53PositionX >= box1PositionX && ball53PositionX <= box1PositionX + 130 &&
			    ball53PositionY >= box1PositionY && ball53PositionY <= box1PositionY + 130 && box1 == 1)))
	{
		ball53PositionX = -1000;
		ball53PositionY = -1000;
		ball53Move = 1;
		ball53Generate = 1;
		points = points - 1;
    }

	// clock in any box
	if ((clockPositionX >= box1PositionX && clockPositionX <= box1PositionX + 130 &&
		 clockPositionY >= box1PositionY && clockPositionY <= box1PositionY + 130 && box1 == 1 )||
	   	(clockPositionX >= box2PositionX && clockPositionX <= box2PositionX + 130 &&
		 clockPositionY >= box2PositionY && clockPositionY <= box2PositionY + 130 && box2 == 1 )||
		(clockPositionX >= box3PositionX && clockPositionX <= box3PositionX + 130 &&
		 clockPositionY >= box3PositionY && clockPositionY <= box3PositionY + 130 && box3 == 1 )||
		(clockPositionX >= box4PositionX && clockPositionX <= box4PositionX + 130 &&
		 clockPositionY >= box4PositionY && clockPositionY <= box4PositionY + 130 && box4 == 1 )||
		(clockPositionX >= box5PositionX && clockPositionX <= box5PositionX + 130 &&
		 clockPositionY >= box5PositionY && clockPositionY <= box5PositionY + 130 && box5 == 1 ))
	{
		clockPositionX = -1000;
		clockPositionY = -1000;
		clockMove = 1;
		clockGenerate = 1;
		timeCount = timeCount - 100;
    }
}


// things to do when mouse pressed
void iMouse(int button, int state, int mx, int my) 
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// menu page
		if ( gameState == 1 || gameState == 2 || gameState == 3 || gameState == 4 ||gameState == 5 || gameState == 6)
		{
			// start
			if ( mx >= 72 && mx <= 396 && my >= 590 && my <= 650)
			{
				previousGameState = gameState;
				gameState = 51;
				if ( difficulty == 1 && music == 1)
				{
					PlaySound ("Audio Files\\bgm1.wav" , NULL , SND_LOOP | SND_ASYNC);
				}
				if ( difficulty == 2 && music == 1)
				{
					PlaySound ("Audio Files\\bgm2.wav" , NULL , SND_LOOP | SND_ASYNC);
				}
				if ( difficulty == 3 && music == 1)
				{
					PlaySound ("Audio Files\\bgm3.wav" , NULL , SND_LOOP | SND_ASYNC);
				}
			}
			// difficulty
			if ( mx >= 72 && mx <= 396 && my >= 483 && my <= 553)
			{
				if ( difficulty == 1)
				{
					previousGameState = gameState;
					gameState = 7;
				}
				else if ( difficulty == 2)
				{
					previousGameState = gameState;
					gameState = 8;
				}
				else if ( difficulty == 3)
				{
					previousGameState = gameState;
					gameState = 9;
				}
			}
			// leaderboard
			if ( mx >= 72 && mx <= 396 && my >= 384 && my <= 454)
			{
				previousGameState = gameState;
				gameState = 10;
			}
			// story
			if ( mx >= 72 && mx <= 396 && my >= 285 && my <= 355)
			{
				previousGameState = gameState;
				gameState = 11;
			}
			// exit
			if ( mx >= 72 && mx <= 396 && my >= 186 && my <= 255)
			{
				previousGameState = gameState;
				gameState = 13;
			}
		
			// music
			if ( mx >= 40 && mx <= 207 && my >= 24 && my <= 132 )
			{
				if ( gameState == 1 || gameState == 3 || gameState == 5 && music == 1)
				{
					music = 0;
					gameState++;
					PlaySound ( 0 , 0 , 0);
				}
				else if ( gameState == 2 || gameState == 4 || gameState == 6 && music == 0)
				{
					music = 1;
					gameState--;
					PlaySound ("Audio Files\\menubgm.wav" , NULL , SND_LOOP | SND_ASYNC);
				}
			}
			// background change previous
			if ( mx >= 337 && mx <= 396 && my >= 24 && my <= 94 )
			{
				
				if ( gameState == 1)
				{
					gameState = 5;
				}
				else if ( gameState == 3)
				{
					gameState = 1;
				}
				else if ( gameState == 5)
				{
					gameState = 3;
				}
				else if ( gameState == 2)
				{
					gameState = 6;
				}
				else if ( gameState == 4)
				{
					gameState = 2;
				}
				else if ( gameState == 6)
				{
					gameState = 4;
				}
			}
			// background change next
			if ( mx >= 424 && mx <= 483 && my >= 24 && my <= 94 )
			{
				
				if ( gameState == 1)
				{
					gameState = 3;
				}
				else if ( gameState == 3)
				{
					gameState = 5;
				}
				else if ( gameState == 5)
				{
					gameState = 1;
				}
				else if ( gameState == 2)
				{
					gameState = 4;
				}
				else if ( gameState == 4)
				{
					gameState = 6;
				}
				else if ( gameState == 6)
				{
					gameState = 2;
				}
			}
			// others 
			if ( mx >= 944 && mx <= 1057 && my >= 391 && my <= 512)
			{
				if ( language == 1)
				{
					previousGameState = gameState;
					gameState = 27;
				}
				else if ( language == 2)
				{
					previousGameState = gameState;
					gameState = 28;
				}
			}
		}
		// difficulty page
		if ( gameState == 7 || gameState == 8 || gameState == 9 )
		{
			if ( mx >= 224 && mx <= 492 && my >= 405 && my <= 472)
				{
					difficulty = 1;
					if ( gameState == 8)
					{
						gameState = 7;
					}
					else if ( gameState == 9)
					{
						gameState = 7;
					}
				}
			else if ( mx >= 527 && mx <= 771 && my >= 405 && my <= 472)
				{
					difficulty = 2;
					if ( gameState == 7)
					{
						gameState = 8;
					}
					else if ( gameState == 9)
					{
						gameState = 8;
					}
				}

			else if ( mx >= 805 && mx <= 1047 && my >= 405 && my <= 472)
				{
					difficulty = 3;
					if ( gameState == 7)
					{
						gameState = 9;
					}
					else if ( gameState == 8)
					{
						gameState = 9;
					}
				}
			else if ( mx >= 43 && mx <= 101 && my >= 37 && my <= 107)
				{
					gameState = previousGameState;
				}
		}

		// story page
		if ( gameState == 11 )
		{
			if ( mx >= 507 && mx <= 611 && my >= 20 && my <= 145)
			{
				gameState = previousGameState;
			}
			else if ( mx >= 674 && mx <= 777 && my >= 37 && my <= 107 )
			{
				gameState = 12;
			}
		}
		if ( gameState == 12)
		{
			if ( mx >= 588 && mx <= 672 && my >= 20 && my <= 145 )
			{
				gameState = 11;
			}
		}
		// exit
		if ( gameState == 13 )
		{
			if ( mx >= 125 && mx <= 375 && my >= 163 && my <= 224)
			{
				gameState = previousGameState;
			}
			if ( mx >= 390 && mx <= 640 && my >= 163 && my <= 224 )
			{
				gameState = 14;
			}
		}
		if ( gameState == 14)
		{
			if ( mx >= 129 && mx <= 602 && my >= 245 && my <= 475)
			{
				gameState = previousGameState;
			}
			else if ( mx >= 619 && mx <= 702 && my >= 330 && my <= 390)
			{
				exit(0);
			}
		}
		// leaderboard
		if ( gameState == 10)
		{
			if ( mx >= 43 && mx <= 101 && my >= 37 && my <= 107)
			{
				gameState = previousGameState;
			}
		}
		// others page
		if ( gameState == 27 || gameState == 28 || gameState == 29)
		{
			if ( mx >= 72 && mx <= 396 && my >= 594 && my <= 665 && gameState != 29)
			{
				exit(0);
			}
			else if ( mx >= 72 && mx <= 396 && my >= 203 && my <= 284  && gameState != 29)
			{
				gameState = 29;
			}
			else if ( mx >= 489 && mx <= 990 && my >= 486 && my <= 557 && language == 2 && gameState != 29)
			{
				language = 1;
				gameState = 27;
			}
			else if ( mx >= 489 && mx <= 990 && my >= 302 && my <= 384 && language == 1 && gameState != 29)
			{
				language = 2;
				gameState = 28;
			}
			else if (mx >= 43 && mx <= 101 && my >= 37 && my <= 107)
			{
				if ( gameState == 27 || gameState == 28)
				{
					gameState = previousGameState;
				}
				else if ( gameState == 29)
				{
					if ( language == 1)
					{
						gameState = 27;
					}
				else if ( language == 2)
					{
						gameState = 28;
					}
				}
			}
		}

		// inside the game
		if (gameState == 51)
		{
			// explotion
			if ( mx >= bombPositionX - 20 && mx <= bombPositionX + 100 && 
				 my >= bombPositionY - 20 && my <= bombPositionY + 100 )
			{
				if ( explotion1 == 0)
				{
					explotion1 = 1;
					explosion1PositionX = bombPositionX - 60;
					explosion1PositionY = bombPositionY - 60;
					bombPositionX = - 1000;
					bombPositionY = - 1000;
					explotion2 = 1;
				}
				else if ( explotion2 == 1)
				{
					explotion2 = 2;
					explosion2PositionX = bombPositionX - 60;
					explosion2PositionY = bombPositionY - 60;
					bombPositionX = - 1000;
					bombPositionY = - 1000;
					explotion3 = 1;
				}
				else if ( explotion3 == 1)
				{
					explotion3 = 3;
					explosion3PositionX = bombPositionX - 60;
					explosion3PositionY = bombPositionY - 60;
					bombPositionX = - 1000;
					bombPositionY = - 1000;
					explotion4 = 1;
				}
				else if ( explotion4 == 1)
				{
					explotion4 = 4;
					explosion4PositionX = bombPositionX - 60;
					explosion4PositionY = bombPositionY - 60;
					bombPositionX = - 1000;
					bombPositionY = - 1000;
					explotion5 = 1;
				}
				else if ( explotion5 == 1)
				{
					explotion5 = 5;
					explosion5PositionX = bombPositionX - 60;
					explosion5PositionY = bombPositionY - 60;
					bombPositionX = - 1000;
					bombPositionY = - 1000;
					explotion6 = 1;
				}
				else if ( explotion6 == 1)
				{
					explotion6 = 6;
					explosion6PositionX = bombPositionX - 60;
					explosion6PositionY = bombPositionY - 60;
					bombPositionX = - 1000;
					bombPositionY = - 1000;
					explotion7 = 1;
				}
				else if ( explotion7 == 1)
				{
					explotion7 = 7;
					explosion7PositionX = bombPositionX - 60;
					explosion7PositionY = bombPositionY - 60;
					bombPositionX = - 1000;
					bombPositionY = - 1000;
					explotion1 = 0;
				}
			}

			// pause button
			if ( mx >= 58 && mx <= 158 && my >= 583 && my <= 682)
			{
				PlaySound ("Audio Files\\pause.wav" , NULL , SND_ASYNC);
				if ( difficulty == 1)
				{
					if ( language == 1)
					{
						gameState = 16;
					}
					else if ( language == 2)
					{
						gameState = 17;
					}					
				}
				else if ( difficulty == 2)
				{
					if ( language == 1)
					{
						gameState = 20;
					}
					else if ( language == 2)
					{
						gameState = 21;
					}					
				}
				else if ( difficulty == 3)
				{
					if ( language == 1)
					{
						gameState = 24;
					}
					else if ( language == 2)
					{
						gameState = 25;
					}	
				}				
			}
		}

		
		if ( gameState == 16 || gameState == 17 || gameState == 20 ||  gameState == 21 || gameState == 24 || gameState == 25 )
		{
			// resume button
			if ( mx >= 515 && mx <= 765 && my >= 270 && my <= 504 )
			{
				gameState = 51;
				if ( music == 1 && difficulty == 1)
				{
					PlaySound ("Audio Files\\bgm1.wav" , NULL , SND_ASYNC);		
				}
				else if ( music == 1 && difficulty == 2)
				{
					PlaySound ("Audio Files\\bgm2.wav" , NULL , SND_ASYNC);		
				}
				else if ( music == 1 && difficulty == 3)
				{
					PlaySound ("Audio Files\\bgm3.wav" , NULL , SND_ASYNC);		
				}
			}

			//exit button
			else if ( mx >= 1094 && mx <= 1200 && my >= 584 && my <= 665 )
			{
				sprintf(pointString, "%d\n", points);
				if ( difficulty == 1)
				{
					changeLeaderboardE(points);
				}
				if ( difficulty == 2)
				{
					changeLeaderboardM(points);
				}
				if ( difficulty == 3)
				{
					changeLeaderboardH(points);
				}
				leaderboard();
				initializeGame();
				if ( difficulty == 1)
				{
					gameState = 18;
				}
				else if ( difficulty == 2)
				{
					gameState = 22;
				}
				else if ( difficulty == 3)
				{
					gameState = 26;
				}
				if ( music == 1)
				{
					PlaySound ("Audio Files\\menubgm.wav" , NULL , SND_LOOP | SND_ASYNC);
				}
			}
		}

		// exit to home
		if ( gameState == 18 || gameState == 22 || gameState == 26)
		{
			if (  mx >= 578 && mx <= 768 && my >=0 && my <= 130)
			{
				gameState = previousGameState;
			}
		}
	}
}

void iKeyboard(unsigned char key) 
{
	if (key == 'q') 
	{
		exit(0);
	}
	if ( key == 'm')
	{
		if ( music == 1)
		{
			PlaySound ( 0 , 0, 0);
			music = 0;
		}
		if ( music == 0)
		{
			PlaySound ("Audio Files\\menubgm.wav" , NULL , SND_LOOP | SND_ASYNC);
			music = 1;
		}
	}
	if ( gameState == 29 )
	{
		if ( key == 'i')
		{
			
			PlaySound("Audio Files\\hiddenmusic.wav" , NULL , SND_LOOP | SND_ASYNC);
		}
	}
}

void iSpecialKeyboard(unsigned char key) {}

// Custom Functions
// Custom Functions

void ballMovingDown()
{
	if ( gameState == 51 )
	{
		if ( ball11Move == 1 )
		{
			ball11PositionY = ball11PositionY - 3*difficulty; 
			ball11PositionX = ball11PositionX - 5 + ball11PositionChange;
		}
		if ( ball12Move == 1 )
		{
			ball12PositionY = ball12PositionY - 3*difficulty; 
			ball12PositionX = ball12PositionX - 5 + ball12PositionChange;
		}
		if ( ball13Move == 1 )
		{
			ball13PositionY = ball13PositionY - 3*difficulty; 
			ball13PositionX = ball13PositionX - 5 + ball13PositionChange;
		}

		if ( ball21Move == 1 )
		{
			ball21PositionY = ball21PositionY - 3*difficulty; 
			ball21PositionX = ball21PositionX - 5 + ball21PositionChange;
		}
		if ( ball22Move == 1 )
		{
			ball22PositionY = ball22PositionY - 3*difficulty; 
			ball22PositionX = ball22PositionX - 5 + ball22PositionChange;
		}
		if ( ball23Move == 1 )
		{
			ball23PositionY = ball23PositionY - 3*difficulty; 
			ball23PositionX = ball23PositionX - 5 + ball23PositionChange;
		}

		if ( ball31Move == 1 )
		{
			ball31PositionY = ball31PositionY - 3*difficulty; 
			ball31PositionX = ball31PositionX - 5 + ball31PositionChange;
		}
		if ( ball32Move == 1 )
		{
			ball32PositionY = ball32PositionY - 3*difficulty; 
			ball32PositionX = ball32PositionX - 5 + ball32PositionChange;
		}
		if ( ball33Move == 1 )
		{
			ball33PositionY = ball33PositionY - 3*difficulty; 
			ball33PositionX = ball33PositionX - 5 + ball33PositionChange;
		}

		if ( ball41Move == 1 )
		{
			ball41PositionY = ball41PositionY - 3*difficulty; 
			ball41PositionX = ball41PositionX - 5 + ball41PositionChange;
		}
		if ( ball42Move == 1 )
		{
			ball42PositionY = ball42PositionY - 3*difficulty; 
			ball42PositionX = ball42PositionX - 5 + ball42PositionChange;
		}
		if ( ball43Move == 1 )
		{
			ball43PositionY = ball43PositionY - 3*difficulty; 
			ball43PositionX = ball43PositionX - 5 + ball43PositionChange;
		}

		if ( ball51Move == 1 )
		{
			ball51PositionY = ball51PositionY - 3*difficulty; 
			ball51PositionX = ball51PositionX - 5 + ball51PositionChange;
		}
		if ( ball52Move == 1 )
		{
			ball52PositionY = ball52PositionY - 3*difficulty; 
			ball52PositionX = ball52PositionX - 5 + ball52PositionChange;
		}
		if ( ball53Move == 1 )
		{
			ball53PositionY = ball53PositionY - 3*difficulty; 
			ball53PositionX = ball53PositionX - 5 + ball53PositionChange;
		}

		// clock moving down
		if ( clockMove == 1 )
		{
			clockPositionY = clockPositionY - 5; 
			clockPositionX = clockPositionX - 5 + clockPositionChange;
		}

		// bomb moving down
		if ( bombMove == 1 )
		{
			bombPositionY = bombPositionY - 4; 
			bombPositionX = bombPositionX - 4 + bombPositionChange;

			// bomb collison with box
			if ( bombPositionX >= box1PositionX && bombPositionX <=  box1PositionX + 100 &&
				 bombPositionY >= box1PositionY && bombPositionY <=  box1PositionY + 100 && box1 == 1)
				 {
					bombPositionX = -1000;
					bombPositionY = -1000;
					cross1 = 1;
					box1 = 0;
				 }
			else if ( bombPositionX >= box2PositionX && bombPositionX <=  box2PositionX + 100 &&
				      bombPositionY >= box2PositionY && bombPositionY <=  box2PositionY + 100 && box2 == 1)
					{
						bombPositionX = -1000;
						bombPositionY = -1000;
						cross2 = 1;
						box2 = 0;
    				}
			else if ( bombPositionX >= box3PositionX && bombPositionX <=  box3PositionX + 100 &&
				      bombPositionY >= box3PositionY && bombPositionY <=  box3PositionY + 100 && box3 == 1 )
					{
						bombPositionX = -1000;
						bombPositionY = -1000;
						cross3 = 1;
						box3 = 0;
    				}
			else if ( bombPositionX >= box4PositionX && bombPositionX <=  box4PositionX + 100 &&
				      bombPositionY >= box4PositionY && bombPositionY <=  box4PositionY + 100 && box4 == 1 )
					{
						bombPositionX = -1000;
						bombPositionY = -1000;
						cross4 = 1;
						box4 = 0;
    				}	
			else if ( bombPositionX >= box5PositionX && bombPositionX <=  box5PositionX + 100 &&
				      bombPositionY >= box5PositionY && bombPositionY <=  box5PositionY + 100 && box5 == 1 )
					{
						bombPositionX = -1000;
						bombPositionY = -1000;
						cross5 = 1;
						box5 = 0;
    				}					
		}
	}
}

void timerBar()
{
	if ( gameState == 51 )
	{
		timeCount = timeCount + 1;
		if ((difficulty == 1 && timeCount == 1800)||
			(difficulty == 2 && timeCount == 900)||
			(difficulty == 3 && timeCount == 600))
		{
			sprintf(pointString, "%d\n", points);
			if ( difficulty == 1)
			{
				changeLeaderboardE(points);
			}
			if ( difficulty == 2)
			{
				changeLeaderboardM(points);
			}
			if ( difficulty == 3)
			{
				changeLeaderboardH(points);
			}
			leaderboard();
			initializeGame();
			if ( difficulty == 1)
			{
				gameState = 18;
			}
			else if ( difficulty == 2)
			{
				gameState = 22;
			}
			else if ( difficulty == 3)
			{
				gameState = 26;
			}
			if ( music == 1)
			{
				PlaySound ("Audio Files\\menubgm.wav" , NULL , SND_LOOP | SND_ASYNC);
			}
		}
	}
}

void generateBall1()
{
	if ( gameState == 51 )
	{
		srand(time(NULL));
		ball11PositionChange = rand()%10 + 1;
		ball12PositionChange = rand()%10 + 1;
		ball13PositionChange = rand()%10 + 1;

		if ( ball11Generate == 1)
		{
			ball11PositionX = 320 + rand() % 640 + 1;
			ball11PositionY = 700;
		}
		if ( ball12Generate == 1)
		{
			ball12PositionX = 320 + rand() % 640 + 1;
			ball12PositionY = 700;
		}
		if ( ball13Generate == 1)
		{
			ball13PositionX = 320 + rand() % 640 + 1;
			ball13PositionY = 700;
		}
	}
}

void generateBall2()
{
	if ( gameState == 51 )
	{
	srand(time(NULL));
	ball21PositionChange = rand()%10 + 1;
	ball22PositionChange = rand()%10 + 1;
	ball23PositionChange = rand()%10 + 1;
	
	if ( ball21Generate == 1)
	{
		ball21PositionX = 320 + rand() % 640 + 1;
		ball21PositionY = 700;
	}
	if ( ball22Generate == 1)
	{
		ball22PositionX = 320 + rand() % 640 + 1;
		ball22PositionY = 700;
	}
	if ( ball23Generate == 1)
	{
		ball23PositionX = 320 + rand() % 640 + 1;
		ball23PositionY = 700;
	}
	}
}

void generateBall3()
{
	if ( gameState == 51 )
	{
		srand(time(NULL));
		ball31PositionChange = rand()%10 + 1;
		ball32PositionChange = rand()%10 + 1;
		ball33PositionChange = rand()%10 + 1;
	
	if ( ball31Generate == 1)
	{
		ball31PositionX = 320 + rand() % 640 + 1;
		ball31PositionY = 700;
	}
	if ( ball32Generate == 1)
	{
		ball32PositionX = 320 + rand() % 640 + 1;
		ball32PositionY = 700;
	}
	if ( ball33Generate == 1)
	{
		ball33PositionX = 320 + rand() % 640 + 1;
		ball33PositionY = 700;
	}
	}
}

void generateBall4()
{
	if ( gameState == 51 )
	{
		srand(time(NULL));
		ball41PositionChange = rand()%10 + 1;
		ball42PositionChange = rand()%10 + 1;
		ball43PositionChange = rand()%10 + 1;
	
	if ( ball41Generate == 1)
	{
		ball41PositionX = 420 + rand() % 640 + 1;
		ball41PositionY = 700;
	}
	if ( ball42Generate == 1)
	{
		ball42PositionX = 420 + rand() % 640 + 1;
		ball42PositionY = 700;
	}
	if ( ball43Generate == 1)
	{
		ball43PositionX = 420 + rand() % 640 + 1;
		ball43PositionY = 700;
	}
	}
}

void generateBall5()
{
	if ( gameState == 51 )
	{
		srand(time(NULL));
		ball51PositionChange = rand()%10 + 1;
		ball52PositionChange = rand()%10 + 1;
		ball53PositionChange = rand()%10 + 1;
		
	if ( ball51Generate == 1)
	{
		ball51PositionX = 520 + rand() % 640 + 1;
		ball51PositionY = 700;
	}
	if ( ball52Generate == 1)
	{
		ball52PositionX = 520 + rand() % 640 + 1;
		ball52PositionY = 700;
	}
	if ( ball53Generate == 1)
	{
		ball53PositionX = 520 + rand() % 640 + 1;
		ball53PositionY = 700;
	}
	}
}

void generateBomb()
{
	srand(time(NULL));
	bombPositionChange = rand()%5 + 1;
	if ( gameState == 51 )
	{
		bombPositionX = 520 + rand() % 640 + 1;
		bombPositionY = 700;
	}
}

void generateClock()
{
	srand(time(NULL));
	clockPositionChange = rand()%5 + 1;
	if ( gameState == 51 )
	{
		if ( clockGenerate == 1)
		{
			clockPositionX = 520 + rand() % 640 + 1;
			clockPositionY = 700;
		}
	}
}


// main function
// main function
int main() 
{
	initializeGame();
	leaderboard();
	iSetTimer ( 3500 , generateBall1);
	iSetTimer ( 3700 , generateBall2);
	iSetTimer ( 3950 , generateBall3);
	iSetTimer ( 4400 , generateBall4);
	iSetTimer ( 4600 , generateBall5);
	iSetTimer ( 15000 , generateBomb);
	iSetTimer ( 20000 , generateClock);
	iSetTimer ( 15 , ballMovingDown );
	iSetTimer ( 100 , timerBar);
	if ( music == 1)
	{
		PlaySound ("Audio Files\\menubgm.wav" , NULL , SND_ASYNC);		
	}
	iInitialize(screenHeight ,screenWidth , "Color Monster");
	return 0;
}
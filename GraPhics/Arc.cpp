#include<graphics.h>
#include<conio.h>

main()
{
   int gd = DETECT, gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   setfillstyle( WIDE_DOT_FILL, RED);
   circle(100, 100, 50);
   floodfill(100, 100, WHITE);

   getch();
   closegraph();
   return 0;
}

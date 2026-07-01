#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 30
#define COLS 60

char canvas[ROWS][COLS];

/*-----------------------------------------
    CANVAS FUNCTIONS
------------------------------------------*/

void initializeCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c ", canvas[i][j]);
        }

        printf("\n");
    }
}

int isValid(int x, int y)
{
    if(x >= 0 && x < COLS && y >= 0 && y < ROWS)
        return 1;

    return 0;
}

void plot(int x, int y)
{
    if(isValid(x, y))
        canvas[y][x] = '*';
}

void erasePoint(int x, int y)
{
    if(isValid(x, y))
        canvas[y][x] = '_';
}

/*-----------------------------------------
    RECTANGLE
------------------------------------------*/

void drawRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height; i++)
    {
        for(j = x; j < x + width; j++)
        {
            plot(j, i);
        }
    }
}

/*-----------------------------------------
    BRESENHAM LINE ALGORITHM
------------------------------------------*/

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while(1)
    {
        plot(x1, y1);

        if(x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if(e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if(e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

/*-----------------------------------------
    TRIANGLE
------------------------------------------*/

void drawTriangle(int x, int y, int height)
{
    drawLine(x, y, x - height, y + height);

    drawLine(x, y, x + height, y + height);

    drawLine(x - height,
             y + height,
             x + height,
             y + height);
}

/*-----------------------------------------
    MIDPOINT CIRCLE
------------------------------------------*/

void drawCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;

    int d = 1 - r;

    while(x <= y)
    {
        plot(xc + x, yc + y);
        plot(xc - x, yc + y);
        plot(xc + x, yc - y);
        plot(xc - x, yc - y);

        plot(xc + y, yc + x);
        plot(xc - y, yc + x);
        plot(xc + y, yc - x);
        plot(xc - y, yc - x);

        if(d < 0)
        {
            d += 2 * x + 3;
        }
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }

        x++;
    }
}

/*-----------------------------------------
    DELETE AREA
------------------------------------------*/

void deleteArea(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height; i++)
    {
        for(j = x; j < x + width; j++)
        {
            erasePoint(j, i);
        }
    }
}

/*-----------------------------------------
    CLEAR CANVAS
------------------------------------------*/

void clearCanvas()
{
    initializeCanvas();
}
/*-----------------------------------------
    MENU
------------------------------------------*/

void menu()
{
    printf("\n=====================================\n");
    printf("         2D GRAPHICS EDITOR\n");
    printf("=====================================\n");

    printf("1. Draw Rectangle\n");
    printf("2. Draw Line\n");
    printf("3. Draw Triangle\n");
    printf("4. Draw Circle\n");
    printf("5. Delete Area\n");
    printf("6. Modify Rectangle\n");
    printf("7. Clear Canvas\n");
    printf("8. Display Picture\n");
    printf("9. Exit\n");

    printf("-------------------------------------\n");
}

/*-----------------------------------------
    MAIN FUNCTION
------------------------------------------*/

int main()
{
    int choice;

    initializeCanvas();

    while(1)
    {
        menu();

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int x, y, w, h;

                printf("\nEnter X Y Width Height : ");
                scanf("%d %d %d %d", &x, &y, &w, &h);

                drawRectangle(x, y, w, h);

                printf("Rectangle Added Successfully!\n");
                break;
            }

            case 2:
            {
                int x1, y1, x2, y2;

                printf("\nEnter X1 Y1 X2 Y2 : ");
                scanf("%d %d %d %d",
                      &x1,
                      &y1,
                      &x2,
                      &y2);

                drawLine(x1, y1, x2, y2);

                printf("Line Added Successfully!\n");
                break;
            }

            case 3:
            {
                int x, y, h;

                printf("\nEnter Top Vertex X Y Height : ");
                scanf("%d %d %d",
                      &x,
                      &y,
                      &h);

                drawTriangle(x, y, h);

                printf("Triangle Added Successfully!\n");
                break;
            }

            case 4:
            {
                int x, y, r;

                printf("\nEnter Center X Center Y Radius : ");
                scanf("%d %d %d",
                      &x,
                      &y,
                      &r);

                drawCircle(x, y, r);

                printf("Circle Added Successfully!\n");
                break;
            }

            case 5:
            {
                int x, y, w, h;

                printf("\nEnter X Y Width Height to Delete : ");

                scanf("%d %d %d %d",
                      &x,
                      &y,
                      &w,
                      &h);

                deleteArea(x, y, w, h);

                printf("Area Deleted Successfully!\n");

                break;
            }

            case 6:
            {
                int oldx, oldy, w, h;
                int newx, newy;

                printf("\nOld Rectangle X Y Width Height : ");

                scanf("%d %d %d %d",
                      &oldx,
                      &oldy,
                      &w,
                      &h);

                deleteArea(oldx, oldy, w, h);

                printf("New X Y : ");

                scanf("%d %d",
                      &newx,
                      &newy);

                drawRectangle(newx, newy, w, h);

                printf("Rectangle Modified Successfully!\n");

                break;
            }

            case 7:
            {
                clearCanvas();

                printf("Canvas Cleared!\n");

                break;
            }

            case 8:
            {
                displayCanvas();

                break;
            }

            case 9:
            {
                printf("\nThank you for using 2D Graphics Editor.\n");

                return 0;
            }

            default:
            {
                printf("\nInvalid Choice!\n");
            }
        }
    }

    return 0;
}

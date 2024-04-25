#include <stdio.h>

typedef struct {
    int x;
    int y;
} point; 

typedef struct {
    point pt1;
    point pt2;
} rect;

point make_point(int, int);
point add_point(point, point);
int test_point_inside_rect(point, rect);

int main()
{
    rect screen;
    int pixels;

    screen.pt1 = make_point(0, 0);
    screen.pt2 = make_point(1920, 1080);
    point middlepoint;
    middlepoint.x = screen.pt2.x/2;
    middlepoint.y = screen.pt2.y/2;

    pixels = (screen.pt2.x - screen.pt1.x) * (screen.pt2.y - screen.pt1.y);
    
    printf("testing if point inside rect...\n\n");
    int inside = test_point_inside_rect(middlepoint, screen);
    if (inside == 0) {
        printf("point inside!\n");
    } else if (inside == 1) {
        printf("point not inside!\n");
    } else {
        printf("ERROR: unexpected return value!\n");
        return 1;
    }

    printf("screen pixels: %d\n", pixels);
    return 0;
}

point make_point(int x, int y)
{
    point p;
    p.x = x;
    p.y = y;
    return p; 
}

point add_point(point p1, point p2)
{
    point p;
    p.x = p1.x + p2.x;
    p.y = p1.y + p2.y;
    return p;
}

int test_point_inside_rect(point p, rect r)
{
    // returns 0 for success, 1 for failure
    return !(p.x >= r.pt1.x && p.x <= r.pt2.x
        && p.y >= r.pt1.y && p.y <= r.pt2.y);
}

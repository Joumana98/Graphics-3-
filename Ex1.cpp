#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

class Smiley: public Circle
{
public:
    Smiley(Point c, int r);

    void draw_lines() const;


private:
    Arc mouth;
    Marks eyes;
};

class Frowny: public Circle
{
public:
    Frowny(Point c, int r);

    void draw_lines() const;


private:
    Arc mouth;
    Marks eyes;
};

class Smiley_hat: public Smiley
{

public:
    Smiley(Pint c, int r);
    void draw_lines const();

private:
    Open_polyline hat;
};

//-------------------------------------------------------------------------------------------------------------------------------------

int main()
{
 using namespace Graph_lib;

    Simple_window win{Point{20,100},800,600,"My canvas"};
    Smiley face1{Point{200,200},100};
    Frowny face2 {Point{500,100},100};
    Smiley_hat face3 {Point{200,400},100};

    win.attach(face1);
    win.attach(face2);
    win.attach(face3);
    win.wait_for_button();

    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------

 Smiley::Smiley(Point c, int r): Circle{c,r}
 {
    add(Point{center().x+radius()/2,center()).y-radius()/2});
    add(Point{center().x-radius()/2,center().y-radius()/2});

    eyes{"*",{point(1),point(2)}};
    mouth{c,r/2,225,315};

 }

void Smiley::draw_lines() const
{
     Circle::draw_lines();
     eyes.draw_lines();
     mouth.draw_lines();

}

 Frowny::Frowny(Point c, int r): Circle{c,r}
 {
    add(Point{center().x+radius()/2,center()).y-radius()/2});
    add(Point{center().x-radius()/2,center().y-radius()/2});

    eyes{"*",{point(1),point(2)}};
    mouth{Point{center().x,center().y+r},r/2,45,135};

 }

void Frowny::draw_lines() const
{
     Circle::draw_lines();
     eyes.draw_lines();
     mouth.draw_lines();

}

//---------------------------------------------------------------------------------------------------------------------------------------

 Smiley_hat::Smiley_hat(Point c, int r):Smiley{c,r}
 {
    double d=r*sqrt(2)/2;
    add(Point{center().x+d,center().y-d});
    add(Point{center().x-d,center().y-d});

    hat{point(3),Point{center().x,center().y-2*r},point(4)};


 }


void Smiley_hat::draw_lines const()
{
        Smiley::draw_lines();
        hat.draw_lines();
}

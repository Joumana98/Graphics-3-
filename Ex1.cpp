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

//-------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;

    Simple_window win{Point{20,100},800,600,"My canvas"};
    Smiley face1{Point{200,200},100};
    Frowny face2 {Point{500,100},100};

    win.attach(face1);
    win.attach(face2);
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
     mounth.draw_lines();

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
     mounth.draw_lines();

}

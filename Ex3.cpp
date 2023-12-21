#include "Simple_window.h"
#include "Graph.h"

class Striped_cirlce: public Cirlce
{

public:
    Striped_circle(Point c, int rad, int s);
    void draw_lines();

private:
    int sw;
};

int main()
{
    using namepsace Graph_lib;

    Simple_window win{Point{20,100},800,600,"My canvas"};
    Striped_circle c{Point{300,300},200,5};

    win.attach(c);

    win.wait_for_button();
    return 0;
}


Striped_circle::Striped_circle(Point c, int rad,int s): Circle{c,rad}
{
    if (s<0 || s>rad)
       error("Invalid strips width");
    else
       sw=s;

}

void Striped_circle::draw_lines()
{
    Circle::draw_lines();

    int strips_nb=int(radius()/sw);
    for (int i=1;i<strips_nb;i+=2)
    {
       Circle c{Circle::center(),i*sw}
       c.draw_lines();
       c.set_style(Line_style{Line_style::solid,sw});
    }

}

#include "Simple_window.h"
#include "Graph.h"

class Striped_rectangle: public Rectangle
{

public:
    Striped_rectangle(int w, int l, int s);
    void draw_lines();

private:
    int sw;
    Lines strips;
};

int main()
{
    using namepsace Graph_lib;

    Simple_window win{Point{20,100},800,600,"My canvas"};

    Striped_rectangle rec{Point{100,100},400,200,5};
    win.attach(rec);

    win.wait_for_button();
    return 0;
}


Striped_rectangle::Striped_rectangle(int w, int l,int s): Rectangle{w,l}
{
    if (s<0 || s>l)
       error("Invalid strips width");
    else
       sw=s;

    int strips_nb=int(l/s);
    for (int i=1;i<strips_nb;i+=2)
    {
        int yy=Striped_rectangle::point(0).y+i*s;
        strips.add(Point{Rectangle::point(0).x,yy},Point{Rectangle::point(0).x+w,yy});
    }


}

void Striped_rectangle::draw_lines()
{
    Rectangle::draw_lines();
    stripd.draw_lines();
    strips.set_style(Line_style{Line_style::solid,sw});

}

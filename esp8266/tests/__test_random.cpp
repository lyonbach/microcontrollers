#include <iostream>

struct RGBColor 
{
    int red, green, blue;

    RGBColor(int r, int g, int b)
    {
        this->red = r;
        this->green = g;
        this->blue = b;
    }
};

int main()
{
    // std::cout << RAND_MAX << std::endl;
    // for(int i = 0; i < 100; i++)
    //     std::cout << (float)std::rand()/RAND_MAX << std::endl;
    // return 0;
    RGBColor color = RGBColor(15, 20, 30);
    std::cout << color.red << ", " << color.green << ", " << color.blue << std::endl;
}
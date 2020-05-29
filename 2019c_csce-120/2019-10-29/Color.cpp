#include "Color.h"
#include <stdexcept>
#include <iostream>
#include <sstream>

Color::Color() : r(0), g(0), b(0)
{

}

Color::Color(int rr, int gg, int bb) : r(rr), g(gg), b(bb)
{
    if (r > 255 || r < 0)
        throw std::runtime_error("Invalid color value for r");
    if (g > 255 || g < 0)
        throw std::runtime_error("Invalid color value for g");
    if (b > 255 || b < 0)
        throw std::runtime_error("Invalid color value for b");

}

Color::~Color()
{
    std::cout << "bye bye color" << std::endl;
}

std::string to_str(const Color& c)
{
    std::stringstream ss;
    ss << c.get_r() << '\t' << c.get_g() << '\t' << c.get_b() << '\n';
    return ss.str();
}

void Color::set_r(int val)
{
    if (val > 255 || val < 0)
        throw std::runtime_error("Invalid color value");

    this->r = val; // (*this).r
}

void Color::set_g(int val)
{
    if (val > 255 || val < 0)
        throw std::runtime_error("Invalid color value");

    this->g = val; // (*this).r
}

void Color::set_b(int val)
{
    if (val > 255 || val < 0)
        throw std::runtime_error("Invalid color value");

    this->b = val; // (*this).r
}

int Color::get_r() const
{
    return r;
}

int Color::get_g() const
{
    return g;
}

int Color::get_b() const
{
    return b;
}
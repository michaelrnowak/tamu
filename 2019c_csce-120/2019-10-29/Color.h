#ifndef COLOR_H
#define COLOR_H
#include<string>

class Color {
public:
    Color();
    Color(int, int, int);
    ~Color();

    void set_r(int);
    void set_g(int);
    void set_b(int);
    int get_r() const;
    int get_g() const;
    int get_b() const;

private:
    int r, g, b;

};

std::string to_str(const Color&);

#endif
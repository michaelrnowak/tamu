//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                           PRINTVISUALV2.H                                //
//                                                                          //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/08/12              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#ifndef PRINTVISUALV2_H
#define PRINTVISUALV2_H

//////////////////////////////////////////////////////////////////////////////
// Includes                                                                 //
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// Begin namespace vis                                                       //
//////////////////////////////////////////////////////////////////////////////
namespace vis {

//////////////////////////////////////////////////////////////////////////////
// Declarations                                                             //
//////////////////////////////////////////////////////////////////////////////
// including vis::center definition so that entire library can be used by #include(ing) this header file
std::string center (const std::string &str, const int col_width)
{
    // quick and easy (but error-prone) implementation
    int padl = (col_width - str.length()) / 2;
    int padr = (col_width - str.length()) - padl;
    std::string strf = std::string(padl, ' ') + str + std::string(padr, ' ');
    return strf;
}
void return_to_continue()
{
    std::cout << "Press [Return] to continue..." << std::endl;
    std::string str; getline (std::cin, str);
}

//////////////////////////////////////////////////////////////////////////////
// Templated Fuctions Definitions                                           //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//     template<typename T> std::ostream& print_obj(T*& ptr, const          //
//         std::string &name = "", std::ostream& os = std::cout)            //
//                                                                          //
//       Input : Object of type T passed-by-reference, optional const       //
//               std::string passed by reference containing name its        //
//               identifier (for diagram labeling), and std::ostream        //
//               passed-by-reference in which the diagram will be output    //
//                                                                          //
//      Output :             i                                              //
//                   .---------------.                                      //
//                   |       7       |                                      //
//                   '---------------'                                      //
//                   ( 0x7fff54abd2ac)                                      //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& print_obj(T& obj, const std::string &name = "", std::ostream& os = std::cout, int address_size = 16)
{
    // names
    os << ' ' << center(name, address_size - 1) << ' ' << std::endl;
    // box tops
    os << '.' << std::setw(address_size) << std::setfill('-') << '.' << std::endl;
    // box middles (includes object values)
    std::ostringstream oss; oss << obj; std::string val = oss.str(); oss.str("");
    os << '|' << std::setw(address_size - 1) << std::setfill(' ') << center(val, address_size - 1) << '|' << std::endl;
    // box bottoms
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'' << std::endl;
    // addresses
    os << '(' << "\e[31m" << std::setw(address_size - 1) << std::setfill(' ') << &obj << "\x1b[0m" << ')' << std::endl;
    return os;
}

//////////////////////////////////////////////////////////////////////////////
//     template<typename T> std::ostream& print_ref(T*& ptr, const          //
//         std::string &name = "", std::ostream& os = std::cout)            //
//                                                                          //
//       Input : Object of type T passed-by-reference, optional const       //
//               std::string passed by reference containing name its        //
//               identifier (for diagram labeling), and std::ostream        //
//               passed-by-reference in which the diagram will be output    //
//                                                                          //
//      Output :                                                            //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& print_ref(T& obj, const std::string &name = "", const std::string &ref = "", std::ostream& os = std::cout, int address_size = 16)
{
    // names
    os << std::setfill(' ') << std::setw(address_size) << ' ' << ' ' << center(name, address_size - 1) << ' ' << std::endl;
    // box tops
    os << std::setfill(' ') << std::setw(address_size) << ' ' << '.' << std::setw(address_size) << std::setfill('-') << '.' << std::endl;
    // box middles (includes object values)
    std::ostringstream oss; oss << obj; std::string val = oss.str(); oss.str("");
    os << std::setfill(' ') << std::setw(address_size - 3) << ref << std::setw(3) << ": " << '|' << std::setw(address_size - 1) << std::setfill(' ') << center(val, address_size - 1) << '|' << std::endl;
    // box bottoms
    os << std::setfill(' ') << std::setw(address_size) << ' ' << '\'' << std::setw(address_size) << std::setfill('-') << '\'' << std::endl;
    // addresses
    os << std::setfill(' ') << std::setw(address_size) << ' ' << '(' << "\e[31m" << std::setw(address_size - 1) << std::setfill(' ') << &obj << "\x1b[0m" << ')' << std::endl;
    return os;
}
//////////////////////////////////////////////////////////////////////////////
//     template<typename T> std::ostream& print(T*& ptr, const std::string  //
//         &name = "", std::ostream& os = std::cout)                        //
//                                                                          //
//       Input : Pointer of type T passed-by-reference, optional const      //
//               std::string passed by reference containing name its        //
//               identifier (for diagram labeling), and std::ostream        //
//               passed-by-reference in which the diagram will be output    //
//                                                                          //
//      Output : Provided an int* i initialized as int* i = new int{1},     //
//               and std::string "i", the following output will drawn to    //
//               the ostream& os.                                           //
//                        i                      *i                         //
//                 .---------------.       .---------------.                //
//                 | 0x7fbbb9c04c50|------>|       1       |                //
//                 '---------------'       '---------------'                //
//                 ( 0x7fff52a9b3b8)       ( 0x7fbbb9c04c50)                //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
std::ostream& print(T*& ptr, const std::string &name = "", std::ostream& os = std::cout, int address_size = 16)
{
    // names
    os << ' ' << center(name, address_size - 1) << ' ';
    os << std::setw(address_size / 2) << std::setfill(' ') << ' ';
    os << center("*" + name, address_size - 1) << std::endl;
    // box tops
    os << '.' << std::setw(address_size) << std::setfill('-') << '.';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '.' << std::setw(address_size) << std::setfill('-') << '.' << std::endl;
    // box middles (includes object values)
    os << '|' << "\e[31m" << std::setw(address_size - 1) << std::setfill(' ') << ptr << "\x1b[0m" << '|';
    os << std::setw(address_size / 2 - 1) << std::setfill('-') << '>';
    os << '|' << center(std::to_string(*ptr), address_size - 1) << '|' << std:: endl;
    // box bottoms
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'' << std::endl;
    // addresses
    os << '(' << std::setw(address_size - 1) << std::setfill(' ') << &ptr << ')';
    os << std::setw(address_size / 2 - 1) << std::setfill(' ') << ' ';
    os << '(' << "\e[31m" << std::setw(address_size - 1) << ptr << std::setfill(' ') << "\x1b[0m" << ')' << std::endl;
    return os;
}
//////////////////////////////////////////////////////////////////////////////
//    template<typename T> std::ostream& print(T**& ptr, const std::string  //
//         &name = "", std::ostream& os = std::cout)                        //
//                                                                          //
//       Input : T**& ptr, optional const std::string passed by reference   //
//               containing name of its identifier (for diagram labeling),  //
//               and std::ostream&os in which the diagram will be output    //
//                                                                          //
//      Output : Provided an int** ii is initialized int** ii = &i where    //
//               i is initialized as int* i = new int{1} and an             //
//               std::string "ii", the following output will drawn to the   //
//               ostream& os.                                               //
//           ii                      *ii                    **ii            //
//    .---------------.       .---------------.       .---------------.     //
//    | 0x7fff5a7593b8|------>| 0x7faa5a500000|------>|       1       |     //
//    '---------------'       '---------------'       '---------------'     //
//    ( 0x7fff5a7593b0)       ( 0x7fff5a7593b8)       ( 0x7faa5a500000)     //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& print(T**& ptr, const std::string &name = "", std::ostream& os = std::cout, int address_size = 16)
{
    // names
    os << ' ' << center(name, address_size - 1) << ' ';
    os << std::setw(address_size / 2) << std::setfill(' ') << ' ';
    os << center("*" + name, address_size - 1) << ' ';
    os << std::setw(address_size / 2) << std::setfill(' ') << ' ';
    os << center("**" + name, address_size - 1) << ' ' << std::endl;
    // box tops
    os << '.' << std::setw(address_size) << std::setfill('-') << '.';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '.' << std::setw(address_size) << std::setfill('-') << '.';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '.' << std::setw(address_size) << std::setfill('-') << '.' << std::endl;
    // box middles (includes object values)
    os << '|' << "\e[34m" << std::setw(address_size - 1) << std::setfill(' ') << ptr << "\x1b[0m" << '|';
    os << std::setw(address_size / 2 - 1) << std::setfill('-') << '>';
    os << '|' << "\e[31m" <<  std::setfill(' ') << std::setw(address_size - 1) << *ptr << "\x1b[0m" <<  '|';
    os << std::setw(address_size / 2 - 1) << std::setfill('-') << '>';
    os << '|' << center(std::to_string(**ptr), address_size - 1) << '|' << std:: endl;
    // box bottoms
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'' << std::endl;
    // addresses
    os << '(' << std::setw(address_size - 1) << std::setfill(' ') << &ptr << ')';
    os << std::setw(address_size / 2 - 1) << std::setfill(' ') << ' ';
    os << '(' << "\e[34m" << std::setw(address_size - 1) << ptr << std::setfill(' ') << "\x1b[0m" << ')';
    os << std::setw(address_size / 2 - 1) << std::setfill(' ') << ' ';
    os << '(' << "\e[31m" << std::setw(address_size - 1) << *ptr << std::setfill(' ') << "\x1b[0m" << ')' << std:: endl;
    return os;
}
//////////////////////////////////////////////////////////////////////////////
//    template<typename T> std::ostream& print(const T(&arr)[N],            //
//        const std::string &name = "", std::ostream& os = std::cout, int   //
//        field_size = 20)                                                  //
//                                                                          //
//       Input :                                                            //
//                                                                          //
//      Output :                                                            //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/10/12              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
template <typename T, size_t N>
std::ostream& print(const T(&arr)[N], const std::string &name = "", std::ostream& os = std::cout, int field_size = 20)
{
    if (N == 0) {
        os << "The array is empty" << std::endl;
        return os;
    }
    os << ' ' << center(name.substr(0, field_size), field_size) << ' ' << std::endl;
    if (N == 0)
        os << ' ' << std::setw(field_size) << center("--", field_size - 1) << ' ' << std::setfill(' ') << std::endl;

    for (int i = N - 1 ; i >= 0  ; --i) {
        // top dash
        if (i == N - 1)
            os << '.' << std::setw(field_size) << std::setfill('-') << '.' << std::setfill(' ') << std::endl;
        else
            os << '+' << std::setw(field_size) << std::setfill('-') << '+' << std::setfill(' ') << std::endl;
        // middle
        std::ostringstream oss; oss << (arr[i]); std::string val = oss.str(); oss.str("");
        os << '|' << std::setw(field_size / 4) << center("[" + std::to_string(i) + "]", field_size / 4 - 1) << center(val, field_size * 3 / 4 - 1) << '|' << std::endl;
        // middle dash
        os << '+' << "\e[37m" << std::setw(field_size - 1) << std::setfill('-') << '-' << "\x1b[0m" << '+' << std::setfill(' ') << std::endl;
        // address
        oss << (void*) &(arr[i]); std::string address = oss.str(); oss.str("");
        os << '|' << "\e[30;3m" << center(address, field_size - 1) << "\x1b[0m" << '|' << std::endl;
        // bottom bash
        if (i == 0)
            os << '\'' << std::setw(field_size) << std::setfill('-') << '\'' << std::setfill(' ') << std::endl;
    }
    os << "    Size : " << N << std::endl;
    return os;
}
//////////////////////////////////////////////////////////////////////////////
//    template<typename T> std::ostream& print(const std::vector<T>& vect,  //
//        const std::string &name = "", std::ostream& os = std::cout, int   //
//        field_size = 20)                                                  //
//                                                                          //
//       Input :                                                            //
//                                                                          //
//      Output :                                                            //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/10/12              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& print(const std::vector<T>& vect, const std::string &name = "", std::ostream& os = std::cout, int field_size = 20)
{
    if (vect.size() == 0) {
        os << "The vector " << (name != "" ? (name + " ") : "") << "is empty" << std::endl;
        return os;
    }
    os << ' ' << center(name.substr(0, field_size), field_size) << ' ' << std::endl;
    if (vect.size() == 0)
        os << ' ' << std::setw(field_size) << center("--", field_size - 1) << ' ' << std::setfill(' ') << std::endl;

    for (int i = vect.size() - 1; i >= 0 ; --i) {
        if (i == vect.size() - 1)
            os << '.' << std::setw(field_size) << std::setfill('-') << '.' << std::setfill(' ') << std::endl;
        else
            os << '+' << std::setw(field_size) << std::setfill('-') << '+' << std::setfill(' ') << std::endl;
        // middle
        std::ostringstream oss; oss << vect.at(i); std::string val = oss.str(); oss.str("");
        os << '|' << std::setw(field_size / 4) << center("[" + std::to_string(i) + "]", field_size / 4 - 1) << center(val, field_size * 3 / 4 - 1) << '|' << std::endl;
        // middle dash
        os << '+' << "\e[37m" << std::setw(field_size - 1) << std::setfill('-') << '-' << "\x1b[0m" << '+' << std::setfill(' ') << std::endl;
        // address
        oss << &(vect.at(i)); std::string address = oss.str(); oss.str("");
        os << '|' << "\e[30;3m" << center(address, field_size - 1) << "\x1b[0m" << '|' << std::endl;
        // bottom bash
        if (i == 0)
            os << '\'' << std::setw(field_size) << std::setfill('-') << '\'' << std::setfill(' ') << std::endl;
    }
    os << "    Size : " << vect.size() << std::endl;
    os << "Capacity : " << vect.capacity() << std::endl;
    return os;
}
//////////////////////////////////////////////////////////////////////////////
//    template<typename T> std::ostream& print(const T(&arr)[N],int array_sz//
//        const std::string &name = "", std::ostream& os = std::cout, int   //
//        field_size = 20)                                                  //
//                                                                          //
//       Input :                                                            //
//                                                                          //
//      Output :                                                            //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/10/12              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
template <typename T>
std::ostream& print_arr(const T& arr, int array_sz, const std::string &name = "", std::ostream& os = std::cout, int field_size = 20)
{
    if (array_sz == 0) {
        os << "The array " << (name != "" ? (name + " ") : "") << "is empty" << std::endl;
        return os;
    }
    os << ' ' << center(name.substr(0, field_size), field_size) << ' ' << std::endl;
    if (array_sz == 0)
        os << ' ' << std::setw(field_size) << center("--", field_size - 1) << ' ' << std::setfill(' ') << std::endl;

    for (int i = array_sz - 1 ; i >= 0  ; --i) {
        // top dash
        if (i == array_sz - 1)
            os << '.' << std::setw(field_size) << std::setfill('-') << '.' << std::setfill(' ') << std::endl;
        else
            os << '+' << std::setw(field_size) << std::setfill('-') << '+' << std::setfill(' ') << std::endl;
        // middle
        std::ostringstream oss; oss << (arr[i]); std::string val = oss.str(); oss.str("");
        os << '|' << std::setw(field_size / 4) << center("[" + std::to_string(i) + "]", field_size / 4 - 1) << center(val, field_size * 3 / 4 - 1) << '|' << std::endl;
        // middle dash
        os << '+' << "\e[37m" << std::setw(field_size - 1) << std::setfill('-') << '-' << "\x1b[0m" << '+' << std::setfill(' ') << std::endl;
        // address
        oss << &(arr[i]); std::string address = oss.str(); oss.str("");
        if (i != 0)
            os << '|' << "\e[30;3m" << center(address, field_size - 1) << "\x1b[0m" << '|' << std::endl;
        else
            os << '|' << "\e[31m" << center(address, field_size - 1) << "\x1b[0m" << '|' << std::endl;
        // bottom bash
        if (i == 0)
            os << '\'' << std::setw(field_size) << std::setfill('-') << '\'' << std::setfill(' ') << std::endl;
    }
    os << "    Size : " << array_sz << std::endl;
    return os;
}

//////////////////////////////////////////////////////////////////////////////
//        std::ostream& print_ptr_info(T*& ptr,const std::string &name = "",//
//                      bool deref_ptr = true, std::ostream& os = std::cin  //
//                                                                          //
//       Input :                                                            //
//                                                                          //
//      Output :                                                            //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& print_ptr_info(T*& ptr, const std::string &name = "", bool deref_ptr = true, std::ostream& os = std::cout)
{
    int field_size = 48;
    int address_size = 16;
    os << '.' << std::setw(field_size) << std::setfill('-') << '.' << std::setfill(' ') << std::endl;
    os << '|' << center("Pointer Name", (field_size - address_size) - 1) << '|';
    os << center(name, (address_size) - 1) << '|' << std::endl;
    os << '+' << std::setw(field_size) << std::setfill('-') << '+' << std::setfill(' ') << std::endl;
    os << '|' << center("Pointer Address", (field_size - address_size) - 1) << '|';
    os << std::setw(address_size - 1) << std::setfill(' ') << &ptr << '|' << std::endl;
    os << '+' << std::setw(field_size) << std::setfill('-') << '+' << std::setfill(' ') << std::endl;
    os << '|' << center("Pointer Value", (field_size - address_size) - 1) << '|';
    os << std::setw(address_size - 1) << std::setfill(' ') << ptr << '|' << std::endl;
    if (deref_ptr) {
        os << '+' << std::setw(field_size) << std::setfill('-') << '+' << std::setfill(' ') << std::endl;
        os << '|' << center("Value Pointed To", (field_size - address_size) - 1) << '|';
        os << std::setw(address_size - 1) << std::setfill(' ') << *ptr << '|' << std::endl;
    }
    os << '\'' << std::setw(field_size) << std::setfill('-') << '\'' << std::setfill(' ') << std::endl;
    return os;
}

//////////////////////////////////////////////////////////////////////////////
//                    std::uintptr_t asmaskedint(void *p)                   //
//                                                                          //
//       Input : address                                                    //
//                                                                          //
//      Output : address as integer with upper-order bits masked out        //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.14.6     //
//  Date ......: 2019/09/23              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
std::uintptr_t asmaskedint(void *p)
{
    return (std::uintptr_t) 0xff & (std::uintptr_t)p;
}

//////////////////////////////////////////////////////////////////////////////
// std::ostream& print2DarrayAddresses(const int *arr, const int noRows,    //
//                          const int noCols, std::ostream &os = std::cout) //
//                                                                          //
//       Description : prints 2d array addresses to std::out (by default)   //
//                     as integer values with high-order bits masked out    //
//     Dependencies : asmaskedint()                                         //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.14.6     //
//  Date ......: 2019/09/23              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
std::ostream& print2DarrayAddresses(const int *arr, const int noRows, const int noCols, std::ostream &os = std::cout)
{
    for (int row = 0; row < noRows; ++row) {
        for (int col = 0; col < noCols; ++col) {
            void *p = (void*)((arr + row * noCols) + col);
            std::uintptr_t mask = asmaskedint(p);
            os << mask << '\t';
        }
        os << std::endl;
    }
}


//////////////////////////////////////////////////////////////////////////////
// close namespace vis                                                      //
//////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
#endif
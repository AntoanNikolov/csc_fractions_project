#include <string>
struct Time
{
    int hours, minutes, seconds;

    Clock(); // constructor
    std::string to_string();
};
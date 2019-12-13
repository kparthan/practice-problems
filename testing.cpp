// stringstream::str
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf

using namespace std;

int main () {

/*
    std::stringstream ss;
    ss.str ("Example string");
    std::string s = ss.str();
    std::cout << s << '\n';
*/
    std::stringstream ss;
    ss << "100" << "\n" << 200;
    cout << ss.str() << endl;

    int foo,bar;
    ss >> foo >> bar;

    std::cout << "foo: " << foo << '\n';
    std::cout << "bar: " << bar << '\n';

    string line;
    cout << "Enter line: ";
    getline(cin, line);
    cout << line << line.length() << endl;

    return 0;
}


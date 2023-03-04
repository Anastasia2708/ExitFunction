#include <iostream>
#include <stdexcept>
#include <string>
#include <stdlib.h>
class MyException : public std::runtime_error
{
public:
    MyException(std::string err) :std::runtime_error(err)
    {
        this->err = err;
    }
    std::string GetMsg()
    {
        return "[ERROR]: " + err;
    }
private:
    std::string err;
};

void Foo(int value)
{
    if (value < 0)
    {
        throw std::runtime_error("Ошибка! Число < 0");
    }
    if (value == 1)
    {
        std::string s;
        std::cin >> s;
        throw MyException(s);
    }
    std::cout << "Переменная = " << value << std::endl;
}

int main() {
    try {
        Foo(-1);
    }
    catch (MyException& err) {
        std::cout << err.GetMsg() << std::endl;
        exit(0);
    }
    catch (std::runtime_error& err){
        std::cout << err.what() << std::endl;
        exit(0);
    }
    catch (MyException& err) {
        std::cout << err.GetMsg() << std::endl;
    }
    return 0;
}

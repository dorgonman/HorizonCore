

#include <stdlib.h>
#include <iostream>
#include <memory>
#include <chrono>

class Timer
{
public:
    Timer() : beg_(clock_::now()) {}
    void reset() { beg_ = clock_::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<second_>
            (clock_::now() - beg_).count();
    }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
};
int main(){

    {
        Timer t;
        for (int i = 0; i < 10000000; i++){
            char s[] = "small_string";
            char t[10];

            memcpy(&t, &s, 10);
        }

        std::cout << "test, memcpy: " << t.elapsed() << " second" << std::endl;
    }


    {
        Timer t;
        for (int i = 0; i < 10000000; i++){
            char s[] = "small_string";
            char t[10];
            memmove(&t, &s, 10);
            //std::clog << t << std::endl;
        }

        std::cout << "test, memmove: " << t.elapsed() << " second" << std::endl;
    }


    {
        Timer t;
        for (int i = 0; i < 10000000; i++){

            std::string test = "small_string";
            std::string test2_1 = test;   // line 1
            // std::clog << test2_1.c_str() << std::endl;
        }

        std::cout << "test, str copy: " << t.elapsed() << " second" << std::endl;
    }


    {
        Timer t;
        for (int i = 0; i < 10000000; i++){

            std::string test = "small_string";
            std::string test2_2 = std::move(test); // line 2

            // std::clog << test2_2.c_str() << std::endl;
        }
        std::cout << "test, str move: " << t.elapsed() << " second" << std::endl;
    }
}
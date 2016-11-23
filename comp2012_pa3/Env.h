/*This is the header containing implementation of
each provided PVE_ENV and PVP_ENV used as template in Map.
Please implement those provided class according to the requierment and
the codes in Maps.tpp and heros.h to ensure the program should be compiled.
You cannot modify any provided codes.
When grading, we will provide more PVE_ENV and PVP_ENV implementation*/

#ifndef ENV_H
#define ENV_H
#include "Heroes.h"
#include <vector>
using namespace std;

class Fire_PVP_ENV
{
public:
    void operator()(Hero*& hero) const
    {
	    //TODO::implement this function to 
		//let the hero's hp decrease by 1 and atk improve 2
		//and the hero will obtain 16 experiance.
		//If the hero can evolve, please let him evolve.
    }
};

class Complex_PVP_ENV
{
public:
    vector<int> exp_vec, dspd_vec, ddef_vec;
    Complex_PVP_ENV()
    {
        dspd_vec.resize(100);
        exp_vec.resize(100);
        ddef_vec.resize(100);
        for (int i = 0; i < 100; i++)
        {
            if (i % 2)
            {
                dspd_vec[i] = 1;
                exp_vec[i] = 10;
            }
            else
            {
                if (i != 52)
                    ddef_vec[i] = 1;
                exp_vec[i] = 20;
            }
        }
    }
    // TODO:: defined and implement operator overloading ().
    // In this function, hero's spd and def will change according to
    // his location, the changing of location i is stored in dspd_vec[i]
    // and ddef_vec[i]. After that, the hero will obtain exp in his location with
    // value exp_vec[i]. If the hero can evolve, evolve him.
};

class Simple_PVE_ENV
{
public:
    // TODO:: implement member function update to improve the hero's ability:
    // if hero's location < 50, hero's hp plus 1, else hero's mp plus 1
    // hero will get 50 exp, if  hero's remaining exp is 0, he will evolve.
};

class General_PVE_ENV
{
public:
    // TODO:: implement member function update and constructor. In member function update,
    // hero will improve the corresponding ability stored in the class
    General_PVE_ENV(int dhp_, int dmp_, int datk_, int ddef_, int dspd_, int dexp_)
private:
    // TODO:: define variables to store the changing of each ability of hero,
    // those ability will be initialized by constructor.
};

#endif // ENV_IF
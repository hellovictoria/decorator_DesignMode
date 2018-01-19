#ifndef _BEVERAGE_H_
#define _BEVERAGE_H_
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

#define TALL    1
#define GRANDE  2
#define VENTI   3

class Beverage
{
    public:
        Beverage() {description = "Unknown Beverage";isize=0;}
        virtual string getDescription() {return description;}
        virtual int getSize() {return isize;}
        virtual double cost(){}
    protected:
        string  description;
        int     isize;
};


class Condiment : public Beverage
{
    public:
        virtual string getDescription(){}  // all children should add its description
};


class Espresso : public Beverage
{
    public:
        Espresso(int isz) {description = "Espresso";isize=isz;}
        double cost()
        {
            switch(getSize())
            {
                case TALL: return 1;break;
                case GRANDE: return 1.5;break;
                case VENTI: return 2;break;
                default: return 1;break;
            }
        }
};

class HouseBlend : public Beverage
{
    public:
        HouseBlend(int isz) {description = "HouseBlend";isize=isz;}
        double cost()
        {
            switch(getSize())
            {
                case TALL: return 0.8;break;
                case GRANDE: return 1.2;break;
                case VENTI: return 1.6;break;
                default: return 0.8;break;
            }
        }
};

class Mocha : public Condiment
{
    public:
        Mocha(Beverage *beverage) {this->beverage=beverage;}
        string getDescription()
        {
            return beverage->getDescription() + ", Mocha";
        }
        int getSize() {return beverage->getSize();}
        double cost()
        {
            double cost = beverage->cost();
            cout << "Mocha size: " << beverage->getSize() << " " << getSize()  << endl;
            switch(beverage->getSize())
            {
                case TALL: cost+=0.2;break;
                case GRANDE: cost+=0.3;break;
                case VENTI: cost+=0.4;break;
                default: cost+=0.2;break;
            }
            return cost;
        }
    protected:
        Beverage *beverage; // decorate to which
};

class Soy : public Condiment
{
    public:
        Soy(Beverage *beverage) {this->beverage=beverage;}
        string getDescription()
        {
            return beverage->getDescription() + ",Soy";
        }
        int getSize() {return beverage->getSize();}
        double cost()
        {
            double cost = beverage->cost();
            cout << "Soy size: "<< beverage->getSize() << " " << getSize() << endl;
            switch(beverage->getSize())
            {
                case TALL: cost+=0.1;break;
                case GRANDE: cost+=0.15;break;
                case VENTI: cost+=0.2;break;
                default: cost+=0.1;break;
            }
            return cost;
        }
    protected:
        Beverage *beverage; // decorate to which
};

#endif

/*This is the header to define all hero class.
Please define all the required virtual member functions except the ones
in base class Hero and implement the reuqired member functions
You cannot modify the any provided codes or add any new member variables
or modify the accessors of provided member variables and function
or add any new friend class.
In particular, you cannot modify or add any member variables and member
function in base class Hero.*/

#ifndef HEROES_H
#define HEROES_H
class Hero
{
public:
    friend class Berserker;
    friend class Warrior;
    friend class Knight;
    friend class Mage;
    friend class Magician;
    friend class Healer;
    Hero(int location_, int direction_);
	virtual ~Hero(){}
    bool is_dead();
    int get_location() const;
    void action(Hero* hero);
    virtual void print();


    // Please implement the following member function in Heros.cpp1

    // If hero's current hp>mp, it will evolve to Warrior, otherwise Mage
    virtual Hero* evolve();

    // Update function of each ability by the input value
    // hp, mp, atk, def cannot less than 0 and spd cannot less than 1
    void update_hp(int dhp);
    void update_mp(int dmp);
    void update_atk(int datk);
    void update_def(int ddef);
    void update_spd(int dspd);

    // Update remain_exp.remain_exp cannot less than 0.
    // if remain_exp is 0, return true, meaning the hero can evolve
    // otherwise return false
    bool gain_exp(int exp);

    virtual void attack(Hero* enemy);
    virtual void attacked(int dhp);
    virtual void move(const Hero* enemy);

protected:
    int hp, mp, atk, def, spd, remain_exp;
    int location;
    int direction;
    Hero(const Hero& hero);

    // Implement the following member function. In this function,
    // the hero will move direction*spd. If the hero meet the opposite hero, stop.
    void just_move(const Hero* enemy);

    // Define all the virtual member functions in public domain
    // you think need to be overloaded according to the description in website
};


class Warrior : public Hero
{
public:
    friend class Hero;
	virtual ~Warrior(){}
    virtual void print();

    // Define all the virtual member functions in public domain
    // you think need to be overloaded according to the description in website
protected:
    int armor;
    Warrior(const Warrior& hero);
	
    // Define all the virtual member functions in protected domain
    // you think need to be overloaded according to the description in website
    void attacked(int dhp);
    Hero* evolve();
private:
    Warrior(const Hero& hero);
};


class Knight : public Warrior
{
public:
    friend class Warrior;
	virtual ~Knight(){}
    virtual void print();
	
    // Define all the virtual member functions in public domain
    // you think need to be overloaded according to the description in website

protected:
    // Define all the virtual member function in protected domain
    // you think need to be overloaded according to the description in website
    void move(const Hero* enemy);
    Hero* evolve();
private:
    Knight(const Warrior& hero);
};


class Berserker : public Warrior
{
public:
    friend class Warrior;
	virtual ~Berserker(){}
    virtual void print();
	
    // Define all the virtual member functions in public domain
    // you think need to be overloaded according to the description in website

protected:
    // Define all the virtual member function in protected domain
    // you think need to be overloaded according to the description in website
    void attack(Hero* enemy);
    Hero* evolve();
private:
    Berserker(const Warrior& hero);
};


class Mage : public Hero
{
public:
    friend class Hero;
	virtual ~Mage(){}
    virtual void print();
	
    // Define all the virtual member functions in public domain
    // you think need to be overloaded according to the description in website

protected:
    int wand;
    Mage(const Mage& hero);
	
    // Define all the virtual member functions in protected domain
    // you think need to be overloaded according to the description in website
    void attack(Hero* enemy);
    void attacked(int dhp);
    Hero* evolve();
private:
    Mage(const Hero& hero);
};


class Magician : public Mage
{
public:
    friend class Mage;
	virtual ~Magician(){}
    virtual void print();
    // Define all the virtual member functions in public domain
    // you think need to be overloaded according to the description in website

protected:
    // Define all the virtual member functions in protected domain
    // you think need to be overloaded according to the description in website
	void attack(Hero* enemy);
	Hero* evolve();
private:
    Magician(const Mage& hero);
};


class Healer : public Mage
{
public:
    friend class Mage;
	virtual ~Healer(){}
    virtual void print();
    // Define all the virtual member functions in public domain
    // you think need to be overloaded according to the description in website

protected:
    // Define all the virtual member functions in protected domain
    // you think need to be overloaded according to the description in website
	void move(const Hero* enemy);
	Hero* evolve();
private:
    Healer(const Mage& hero);
};

#endif // HEROES_H

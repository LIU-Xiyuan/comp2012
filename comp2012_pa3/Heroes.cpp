#include "Heroes.h"
#include <math.h>

// TODO:: implement all the required member function in Heroes.h

Hero* Hero::evolve()
{
	if(hp>mp)
	{
		Hero* w = new Warrior(*this);
		return w;
	}
	else
	{
		Hero* m = new Mage(*this);
		return m;
	}
}

void Hero::update_hp(int dhp){hp+=dhp;if(hp<0)hp=0;}

void Hero::update_mp(int dmp){mp+=dmp;if(mp<0)mp=0;}

void Hero::update_atk(int datk){atk+=(int)datk;if(atk<0)atk=0;}

void Hero::update_def(int ddef){def+=ddef;if(def<0)def=0;}

void Hero::update_spd(int dspd){spd+=dspd;if(spd<1)spd=1;}

bool Hero::gain_exp(int exp)
{
	if(exp>0)
	{
		remain_exp-=exp;
		if(remain_exp<0)
			remain_exp=0;
		return (!(remain_exp>0));
	}
	return -1;
}

void Hero::just_move(const Hero* enemy)
{
	location += spd*direction;
	if(location>=enemy->location && (location-spd*direction)<=enemy->location)
		location=enemy->location;
	else if(location<=enemy->location && (location-spd*direction)>=enemy->location)
		location=enemy->location;
}

void Hero::move(const Hero* enemy){just_move(enemy);}

void Hero::attack(Hero* enemy)
{
	if(location==enemy->location)
		enemy->attacked(atk-enemy->def);
}

void Hero::attacked(int dhp)
{
	if(dhp>0)
		update_hp(-dhp);
}

Hero* Warrior::evolve()
{
	if(atk<spd+15)
	{
		Hero* k = new Knight(*this);
		return k;
	}
	else
	{
		Hero* b = new Berserker(*this);
		return b;
	}
}

void Warrior::attacked(int dhp)
{
	if(dhp>0)
	{
		if(armor-dhp>=0)
			armor-=dhp;
		else
			{
				update_hp(-(dhp-armor));
				armor =0;
			}
	}
}

void Knight::move(const Hero* enemy)
{
	if(mp-5>=0)
		{
			location+=direction*(spd+2);
			if(location>enemy->location)
				location=enemy->location;
			update_mp(-5);
		}
	else
		{
			location+=direction*spd;
			if(location>enemy->location)
				location=enemy->location;
		}
}

Hero* Knight::evolve(){return this;}

void Berserker::attack(Hero* enemy)
{
	if(location==enemy->location)
	{
		if(mp-5>=0)
		{
			update_mp(-5);
			enemy->attacked(atk*2-enemy->def);
		}
		else
			enemy->attacked(atk-enemy->def);
	}
}

Hero* Berserker::evolve(){return this;}

void Mage::attack(Hero* enemy)
{
	if(location-enemy->location<4 && enemy->location-location<4)
		{
			if(wand-10>=0)
			{
				wand-=10;
				enemy->attacked(atk*1.5-enemy->def);
			}
			else
			{
				enemy->attacked(atk-enemy->def);
			}
		}
}

void Mage::attacked(int dhp)
{
	if(dhp>0)
	{
		if(mp-5>=0)
		{
			if(dhp>5)
			{
				update_hp(-(dhp-5));
				update_mp(-5);
			}
			else
				update_mp(-5);
		}
		else
			update_hp(-dhp);
	}
}

Hero* Mage::evolve()
{
	if(atk<def+20)
	{
		Hero* h = new Healer(*this);
		return h;
	}
	else
	{
		Hero* m = new Magician(*this);
		return m;
	}
}

void Magician::attack(Hero* enemy)
{
	if(location-enemy->location<5 && enemy->location-location<5)
		{
			if(wand-10>=0 && mp-5>=0)
			{
				wand-=10;
				update_mp(-5);
				enemy->attacked(atk*2-enemy->def);
			}
			else if(mp-5>=0)
			{
				update_mp(-5);
				enemy->attacked(atk*1.5-enemy->def);
			}
		}
}

Hero* Magician::evolve(){return this;}

void Healer::move(const Hero* enemy)
{
	just_move(enemy);
	if(mp-5>=0)
	{
		update_hp(5);
		update_mp(-5);
	}
}

Hero* Healer::evolve(){return this;}

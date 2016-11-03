//SUBMIT THIS
//MAKE SURE THE SPELLING OF THE FILENAME IS EXACTLY Multiset.cpp

#include "Multiset.h"

Multiset::Multiset()
{
	head = NULL;
}

Multiset::Multiset(const Multiset& another)
{
	if(another.head == NULL)
		head = NULL;
	else
	{
		head = new Node(*another.head);
		Node* cur = head;
		Node* nex = another.head->getNext();

		while(nex != NULL)
		{
			Node* n = new Node(*nex);
			cur->setNext(n);
			nex = nex->getNext();
			cur = cur->getNext();
		}
	}
}

Multiset::~Multiset()
{
	Node* cur = head;
	while(cur != NULL)
	{
		head = head->getNext();
		delete cur;
		cur = head;
	}
	head = NULL;
}

int Multiset::cardinality() const
{
	int ans = 0;
	if(head != NULL)
	{
		Node* cur = head;
		Node* nex = head->getNext();
		while(nex != NULL)
		{
			ans += cur->getCount();
			cur = nex;
			nex = nex->getNext();
		}
		ans += cur->getCount();
	}
	return ans;
}

int Multiset::uniqueElementsCount() const
{
	int ans = 0;
	if(head != NULL)
	{
		Node* cur = head;
		while(cur->getNext() != NULL)
		{
			ans += 1;
			cur = cur->getNext();
		}
		ans += 1;
	}
	return ans;
}

int Multiset::itemCount(int item) const
{
	int ans = 0;
	if(head != NULL)
	{
		Node* cur = head;
		for(; cur->getNext() != NULL; cur = cur->getNext())
			if(cur->getValue() == item)
				ans = cur->getCount();
		if(cur->getValue() == item)
			ans = cur->getCount();
	}
	return ans;
}

Multiset& Multiset::operator+=(const int& item)
{
	if(head != NULL)
	{
		bool in = false;
		Node* cur = head;

		if(item < head->getValue())
		{
			Node* n = new Node(item,1,head);
			head = n;
		}
		else if(item == head->getValue())
		{
			head->incrementCount();
		}
		else
		{
			for(;cur->getNext() != NULL && in != true; cur = cur->getNext())
			{
				if(item < cur->getNext()->getValue())
				{
					Node* n = new Node(item, 1, cur->getNext());
					cur->setNext(n);
					in = true;
				}
				else if(item == cur->getNext()->getValue())
				{
					cur->getNext()->incrementCount();
					in = true;
				}
			}
			if(in == false)
			{
				Node* n = new Node(item, 1, NULL);
				cur->setNext(n);
			}
		}
	}
	else
	{
		head = new Node(item, 1, NULL);
	}

	return *this;
}

Multiset& Multiset::operator-=(const int& item)
{
	Node* n = head;
	for(;n != NULL; n = n->getNext())
	{
		if(n->getValue() == item)
			n->decrementCount();
	}
	return *this;
}

Multiset Multiset::operator+(const Multiset& another) const
{
	Multiset m(*this);
	Node* n = another.head;
	for(;n != NULL; n = n->getNext())
		for(int i = 0; i < n->getCount(); i++)
			m.operator +=(n->getValue());
	return m;
}

Multiset Multiset::operator-(const Multiset& another) const
{
	Multiset m(*this);
	Multiset l(another);
	Node* n = m.head;
	Node* o = l.head;
	for(; n != NULL; n = n->getNext())
	{
		for(o = l.head; o != NULL; o = o->getNext())
			if(n->getValue() == o->getValue())
				while(n->getCount() > 0 && o->getCount() > 0)
					{
						n->decrementCount();
						o->decrementCount();
					}
	}
	Multiset a;
	for(n = m.head; n != NULL; n = n->getNext())
		if(n->getCount() != 0)
			for(int i = 0; i < n->getCount(); i++)
				a.operator +=(n->getValue());
	return a;
}

Multiset Multiset::operator|(const Multiset& another) const
{
	Multiset m(*this);
	Multiset l(another);
	Node* n = head;
	Node* h = another.head;
	for(; h != NULL; h = h->getNext())
		{
			bool appear = false;
			for(n = head; n != NULL; n = n->getNext())
			{
				if(n->getValue() == h->getValue())
					{
						if(h->getCount() > n->getCount())
							for(int i = 0; i< h->getCount() - n->getCount(); i++)
								m.operator +=(h->getValue());
						appear = true;
					}
			}
			if(!appear)
				for(int i = 0; i < h->getCount(); i++)
					m.operator +=(h->getValue());
		}
	return m;
}

Multiset Multiset::operator&(const Multiset& another) const
{
	Multiset m(*this);
	Multiset l(another);
	Multiset a;
	Node* n = m.head;
	Node* o = l.head;
	for(; n != NULL; n = n->getNext())
	{
		for(o = l.head; o != NULL; o = o->getNext())
			if(n->getValue() == o->getValue())
				while(n->getCount() > 0 && o->getCount() > 0)
					{
						a.operator+=(n->getValue());
						n->decrementCount();
						o->decrementCount();
					}
	}
	return a;
}

Multiset& Multiset::operator=(const Multiset& another)
{
	if(head != NULL)
	{
		Node* cur = head;
		Node* nex = head->getNext();
		while(nex != NULL)
		{
			delete cur;
			cur = NULL;
			cur = nex;
			nex = nex->getNext();
		}
		delete cur;
		cur = NULL;
	}

	if(another.head == NULL)
		head = NULL;
	else
	{
		head = new Node(*another.head);
		Node* cur = head;
		Node* nex = another.head->getNext();

		while(nex != NULL)
		{
			Node* n = new Node(*nex);
			cur->setNext(n);
			nex = nex->getNext();
			cur = cur->getNext();
		}
	}
	return *this;
}

bool Multiset::operator==(const Multiset& another) const
{
	Node* n = head;
	Node* h = another.head;
	bool equal = true;
	if((n != NULL && h != NULL) || (n == NULL && h == NULL))
	{
		for(; n != NULL; n = n->getNext())
		{
			bool appear = false;
			for(h = another.head; h != NULL; h = h->getNext())
				if(n->getValue() == h->getValue())
				{
					if(n->getCount() != h->getCount())
						return false;
					else if(n->getCount() == h->getCount())
						appear = true;
				}
			if(!appear)
				return false;
		}
	}
	else
		return false;
	return equal;
}

bool Multiset::isSupersetOf(const Multiset& another) const
{
	Node* n = head;
	Node* h = another.head;

	for(; h != NULL; h = h->getNext())
		{
			bool appear = false;
			for(n = head; n != NULL; n = n->getNext())
				if(h->getValue() == n->getValue())
				{
					if(h->getCount() > n->getCount())
						return false;
					else if(h->getCount() <= n->getCount())
						appear = true;
				}
			if(!appear)
				return false;
		}
	return true;
}

bool Multiset::isSubsetOf(const Multiset& another) const
{
	return another.isSupersetOf(*this);
}

bool Multiset::isUniqueSet() const
{
	if(head != NULL)
	{
		Node* cur = head;
		for(; cur != NULL; cur = cur->getNext())
			if(cur->getCount() != 1)
				return false;
	}
	return true;
}

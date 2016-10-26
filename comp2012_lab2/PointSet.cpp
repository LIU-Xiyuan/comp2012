#include "PointSet.h"
#include <iostream>
using namespace std;


PointSet::PointSet()
{
   // This function is already completed.

   cout << "Initialized by PointSet's default constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   numPoints = 0;
}

PointSet::PointSet(const Point3D points_in[], int num_in)
{
   cout << "Initialized by PointSet's parameterized constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here
   numPoints = num_in;
   for (int i=0;i<num_in;i++)
   {
	   points[i] = points_in[i];
   }
}

PointSet::PointSet(const PointSet & s)
{
   cout << "Initialized by PointSet's copy constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here
   numPoints = s.numPoints;
   for (int i=0;i<s.numPoints;i++)
   {
	   points[i] = s.points[i];
   }
}


void PointSet::addPoint(const Point3D& p)
{
   // TODO: add your code here
	if(this->numPoints<MAX_NUM_POINTS)
	{
		//this->points[numPoints].x=p.x;
		//this->points[numPoints].y=p.y;
		//this->points[numPoints].z=p.z;
		this->points[numPoints]=p;
		this->numPoints+=1;
	}
	else
	{
		cout<<"Insufficient array space"<<endl;
		cout<<endl;
	}
}

void PointSet::removeLastPoint()
{
	// TODO: add your code here
	if(this->numPoints<=0)
	{
		cout<<"No points"<<endl;
		cout<<endl;
	}
	else
	{
		this->numPoints-=1;
	}

}

bool PointSet::contains(const Point3D& p) const
{
	// TODO: add your code here
	if(this->numPoints>0)
	{
		for (int i=0;i<this->numPoints;i++)
		{
			if(this->points[i].equal(p))
				return true;
		}
	}
	return false;
}

void PointSet::print() const
{
	// This function is already completed.
   if (numPoints == 0) {
      cout << "The PointSet is empty!" << endl;
      return;
   }
   cout << "Number of points: " << numPoints << endl;;
   cout << "points: " << endl;
   for (int i = 0; i < numPoints; i++)
   {
      points[i].print();
      cout << endl;
   }
}

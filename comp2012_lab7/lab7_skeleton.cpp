#include <set>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <map>
using namespace std;

void printSetUsingIterator(const set<string>& s) {
   // TODO: Print a set of string using iterator
	set<string>::const_iterator p=s.begin();
	cout<<"{"<<*p;
	++p;
	for(;p!=s.end();p++)
		cout<<", "<<*p;
	cout<<"}"<<endl;
}

void printListUsingIterator(const list<string>& s) {
   // TODO: Print a list of string using iterator
	list<string>::const_iterator p=s.begin();
	cout<<"{"<<*p;
	++p;
	for(;p!=s.end();p++)
		cout<<", "<<*p;
	cout<<"}"<<endl;
}

void printMapUsingIterator(const map<string,int>& s) {
   // TODO: Print a map using iterator
	map<string,int>::const_iterator p=s.begin();
	for(;p!=s.end();p++)
		cout<<"key: "<<p->first<<" Value: "<<p->second<<endl;
}

int main()
{
    cout << endl;
    cout << "************************** Part1: set **************************";
    cout << endl;

    set<string> Fictions, Movies;
    Fictions.insert("The Time Machine");
    Fictions.insert("The Catcher in the Rye");
    Fictions.insert("The Lord of the Rings");

    Movies.insert("The Shawshank Redemption");
    Movies.insert("City of God");
    Movies.insert("The Lord of the Rings");
    Movies.insert("Star Wars");

    cout << "Set Fictions Content =" ;
    printSetUsingIterator(Fictions);
    cout << "Set Movies Content =" ;
    printSetUsingIterator(Movies);


    // Part 1 TODO: Complete the set operations: union, intersection and difference.
    set<string> unionSet, interSet, diffSet;

    // ADD YOUR CODE HERE
    for(set<string>::iterator p=Fictions.begin();p!=Fictions.end();p++)
    	unionSet.insert(*p);
    for(set<string>::iterator p=Movies.begin();p!=Movies.end();p++)
        unionSet.insert(*p);
    cout << "Fictions union Movies Content = ";
    printSetUsingIterator(unionSet);

    // ADD YOUR CODE HERE
    for(set<string>::iterator p=Fictions.begin();p!=Fictions.end();p++)
    	for(set<string>::iterator m=Movies.begin();m!=Movies.end();m++)
    		if(*p==*m)
    			interSet.insert(*p);
    cout << "Fictions intersect Movies Content = ";
    printSetUsingIterator(interSet);

    // ADD YOUR CODE HERE
    for(set<string>::iterator p=Fictions.begin();p!=Fictions.end();p++)
		for(set<string>::iterator m=interSet.begin();m!=interSet.end();m++)
			if(*p!=*m)
				diffSet.insert(*p);
    cout << "Fictions difference Movies Content = ";
    printSetUsingIterator(diffSet);


    cout << endl;
    cout << "************************** Part2: list **************************";
    cout << endl;

//    cout << "ok" << endl;
    list<string> listR ;
    // Part 2 TODO: Merge Fictions and Movies to listR
    // ADD YOUR CODE HERE
    for(set<string>::iterator p=Fictions.begin();p!=Fictions.end();p++)
        listR.push_back(*p);
//    cout << "ok" << endl;
    for(set<string>::iterator p=Movies.begin();p!=Movies.end();p++)
        listR.push_back(*p);
//    cout << "ok" << endl;
    cout << "listR Content = ";
    printListUsingIterator(listR);

    // Part 2 TODO:
    //Add a new string "Forest Gump" at the end of the list
    //Add a new string "The Dark Knight" at the head of the list
    // ADD YOUR CODE HERE
    listR.push_back("Forest Gump");
    listR.push_front("The Dark Knight");
    cout << "New R Content = ";
    printListUsingIterator(listR);

    // Part 2 TODO: Compelete sort and unique of list here
    // reverse listR
    // ADD YOUR CODE HERE
    listR.reverse();
    cout << "Reversed R Content = ";
    printListUsingIterator(listR);

    // Sort listR
    // ADD YOUR CODE HERE
    listR.sort();
    cout << "Sorted R Content = ";
    printListUsingIterator(listR);




    cout << endl;
    cout << "************************** Part3: map **************************";
    cout << endl;

    map<string,int> mapMovie;
    mapMovie.insert(make_pair("The Shawshank Redemption", 1994));
    mapMovie.insert(make_pair("City of God", 2002));
    mapMovie.insert(make_pair("The Lord of the Rings", 2002));
    mapMovie.insert(make_pair("Star Wars", 1977));
    mapMovie.insert(make_pair("Forest Gump", 1994));
    cout << "mapMovie Content: "<<endl;
    printMapUsingIterator(mapMovie);

    //Part3 TODO : Compelete element search and deletion in mapMovie here
    // search "Star Wars" in map
    // ADD YOUR CODE HERE
    map<string,int>::iterator p = mapMovie.find("Star Wars");
    if(p!=mapMovie.end())
    	cout<<"Key found, the value is "<<mapMovie.at("Star Wars")<<endl;
    // delete "City of God" in map
    // ADD YOUR CODE HERE
    p = mapMovie.find("City of God");
    	if(p!=mapMovie.end())
    		mapMovie.erase(p);

    printMapUsingIterator(mapMovie);
    return 0;
}

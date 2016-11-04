//DO NOT SUBMIT

#include <iostream>
#include "Multiset.h"

using namespace std;

int main()
{
    Multiset* set3;

	cout << endl << "=== set1 ===" << endl;
	cout << "add 11, 22, 33 ..." << endl;
	Multiset set1;

	cout << set1 << endl;
	set1 += 11;
	cout << set1 << endl;
	set1 += 22;
	cout << set1 << endl;
	set1 += 33;
	cout << set1 << endl;

    cout << "set1's cardinality = " << set1.cardinality() << endl;
    cout << "set1's uniqueElementsCount = " << set1.uniqueElementsCount() << endl;
    cout << "set1's isUniqueSet = " << set1.isUniqueSet() << endl;

    cout << endl << "=== set2 ===" << endl;
	cout << "add 33, 11, 1, 100, 1, 11, 11, 100 ... remove 11 ..." << endl;
    Multiset set2;
	cout << set2 << endl;
    set2 += 33;
    cout << set2 << endl;
    set2 += 11;
    cout << set2 << endl;
    set2 += 1;
    cout << set2 << endl;
    set2 += 100;
    cout << set2 << endl;
    set2 += 1;
    cout << set2 << endl;
    set2 += 11;
    cout << set2 << endl;
    set2 += 11;
    cout << set2 << endl;
    set2 += 100;
    cout << set2 << endl;
    set2 -= 11;
    cout << set2 << endl;

    cout << "set2's cardinality = " << set2.cardinality() << endl;
    cout << "set2's uniqueElementsCount = " << set2.uniqueElementsCount() << endl;
    cout << "set2's isUniqueSet = " << set2.isUniqueSet() << endl;
    cout << "set2's itemCount(11) = " << set2.itemCount(11) << endl;
    cout << "set2's itemCount(22) = " << set2.itemCount(22) << endl;
    cout << "set2's itemCount(33) = " << set2.itemCount(33) << endl;

    cout << endl << "=== set3 (copied from set1) ===" << endl;
	set3 = new Multiset(set1);
    cout << *set3 << endl;

    cout << endl << "=== updated set2 (=set3) ===" << endl;
    set2 = *set3;
    cout << set2 << endl;

    cout << endl << "=== set4 ===" << endl;
    Multiset set4a;
    Multiset set4b;
    set4a +=  2;
    set4a +=  4;
    set4a +=  4;
    set4a +=  6;
    set4b += 4;
    set4b += 6;
    set4b += 6;
    set4b += 6;
    set4b += 8;
    set4b += 10;
    set4b += 10;
    Multiset set4 = set4a | set4b;
    cout << set4a << " | " << set4b << " = " << set4 << endl;
    cout << set4 << " & " << set4a << " = " << (set4 & set4a) << endl;
    cout << set4 << " & " << set4b << " = " << (set4 & set4b) << endl;
    cout << set4 << " - " << set4a << " = " <<  set4 - set4a << endl;
    cout << set4a << " - " << set4b << " = " << set4a - set4b << endl;
    cout << set4a << " + " << set4b << " = " << set4a + set4b << endl;
    cout << set4 << " + " << set4b << " = " << set4 + set4b << endl;

    cout << "Testing == ..." << endl;
    cout << (set4 == set4) << " ";
    cout<< (set4 == set4a) << " " << (set4 == set4b) << " ";
	cout<< (set4 == (set4b | set4a)) << endl;

    cout << "Testing isSupersetOf ..." << endl;
    cout << set4.isSupersetOf(set4) << " " << set4.isSupersetOf(set4a) << " " << set4.isSupersetOf(set4b) << endl;
    cout << set4a.isSupersetOf(set4) << " " << set4a.isSupersetOf(set4a) << " " << set4a.isSupersetOf(set4b) << endl;
    cout << set4b.isSupersetOf(set4) << " " << set4b.isSupersetOf(set4a) << " " << set4b.isSupersetOf(set4b) << endl;

    cout << "Testing isSubsetOf ..." << endl;
    cout << set4.isSubsetOf(set4) << " " << set4.isSubsetOf(set4a) << " " << set4.isSubsetOf(set4b) << endl;
    cout << set4a.isSubsetOf(set4) << " " << set4a.isSubsetOf(set4a) << " " << set4a.isSubsetOf(set4b) << endl;
    cout << set4b.isSubsetOf(set4) << " " << set4b.isSubsetOf(set4a) << " " << set4b.isSubsetOf(set4b) << endl;

    delete set3;

    return 0;
}

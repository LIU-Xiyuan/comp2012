#include "mat.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Empty matrix m1: " << endl;
    Mat m1;
    m1.printMat();
    cout << endl;

    cout << "2 * 3 matrix m2: " << endl;
    Mat m2(2, 3);
    for (size_t i = 0; i < m2.rowNum(); i++)
    {
        for (size_t j = 0; j < m2.colNum(); j++)
        {
            m2(i, j) = 1 + i + j;
        }
    }
    m2.printMat();
    cout << endl;

    cout << "Copy constructor m3(m2), print m3: " << endl;
    Mat m3(m2);
    m3.printMat();
    cout << endl;

    Mat m4;
    cout << "Assign m3 to m4, print m4: " << endl;
    m4.assign(m3);
    m4.printMat();
    cout << endl;

    cout << "m4 = m4 + m3, print m4: " << endl;
    m4.plusEqual(m3);
    m4.printMat();
    cout << endl;

    cout << "m4 = m4 - m3, print m4: " << endl;
    m4.minusEqual(m3);
    m4.printMat();
    cout << endl;

    cout << "m4 = m4 * m3, print m4 (m3 is reshaped to dimension (3, 2)): " << endl;
    m3.reshape(3, 2);
    m4.multiplyEqual(m3);
    m3.reshape(2, 3);
    m4.printMat();
    cout << endl;

    cout << "m4 = m4 / m3, print m4: " << endl;
    m4.assign(m3);
    m4.divideEqual(m3);
    m4.printMat();
    cout << endl;

    cout << "Assign 22 to All elements of m4, print m4: " << endl;
    m4.assign(22);
    m4.printMat();
    cout << endl;

    cout << "Add 22 to all elements of m4, print m4: " << endl;
    m4.plusEqual(22);
    m4.printMat();
    cout << endl;

    cout << "Subtracted 22 from all elements of m4, print m4: " << endl;
    m4.minusEqual(22);
    m4.printMat();
    cout << endl;

    cout << "Multiplied 22 to All elements of m4, print m4: " << endl;
    m4.multiplyEqual(22);
    m4.printMat();
    cout << endl;

    cout << "All elements of m4 be divided by 22, print m4: " << endl;
    m4.divideEqual(22);
    m4.printMat();
    cout << endl;

    cout << "m4 = m2 + m3, print m4: " << endl;
    m4.assign(m2.plus(m3));
    m4.printMat();
    cout << endl;

    cout << "m4 = m2 - m3, print m4: " << endl;
    m4.assign(m2.minus(m3));
    m4.printMat();
    cout << endl;

    cout << "m4 = m2 * m3, print m4 (m3 is reshaped to dimension (3, 2)): " << endl;
    m3.reshape(3, 2);
    m4.assign(m2.multiply(m3));
    m3.reshape(2, 3);
    m4.printMat();
    cout << endl;

    cout << "m4 = m2 / m3, print m4: " << endl;
    m4.assign(m2.divide(m3));
    m4.printMat();
    cout << endl;

    cout << "Transpose m4: print m4: " << endl;
    m4 = m4.transpose();
    m4.printMat();
    cout << endl;

    cout << "Transpose m2 to m4, print m4: " << endl;
    m2.transposeTo(m4);
    m4.printMat();
    cout << endl;

    cout << "L1, L2 norm of m4: " << endl;
    cout << "L1 norml = " << m4.norml1() << ", L2 norml = " << m4.norml2() << endl << endl;

    cout << "Normalizing m4, print m4: " << endl;
    m4.normalize().printMat();
    cout << endl;

    cout << "Fill m4 with 0.3: " << endl;
    m4.fill(0.3).printMat();
    cout << endl;

    cout << "Resize m4 to 3 * 4 and then assign new values, print m4: " << endl;
    m4.resize(3, 4);
    for (size_t i = 0; i < m4.rowNum(); i++)
    {
        for (size_t j = 0; j < m4.colNum(); j++)
        {
        	m4(i, j) = 2 * i + 3 * j;
        }
    }
    m4.printMat();
    cout << endl;

    cout << "Fill m4 with an array, print m4: " << endl;
    double *data1 = new double[6];
    for (int i = 0; i < 6; i++) data1[i] = i + 1;
    m4.fillMemory(data1, 2, 3);
    delete[] data1;
    m4.printMat();
    cout << endl;

    return 0;
}

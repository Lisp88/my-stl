
#include "vector/my_vector.h"
#include <iostream>
#include <vector>
using namespace my_stl;
#include "vector/my_vector.h"

int main() {
    Vector<int> v;
    for(int i=0; i<10; i++) {v.push_back(i);}
    for(Vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    return 0;
}

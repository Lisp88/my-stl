
#include "vector/my_vector.h"
using namespace my_stl;
int main() {
    Vector<int> v;
    for (int i = 0; i < 6; ++i) {
        v.push_back(i);
    }
    v.reserve(9);
    v.print();
    cout << "capacity: " << v.capacity() << endl;
    return 0;
}

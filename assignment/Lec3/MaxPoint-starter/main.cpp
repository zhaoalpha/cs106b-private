/**
 * Find the max point in the given Vector.
 */
#include "random.h"
#include "testing/SimpleTest.h"
#include "vector.h"

int maxOf(Vector<int> elems) {
    // edge case
    if(elems.size() == 1){
      return elems[0];
    }
    // pick the first point
    int first = elems[0];
    // get the max point in the rest (someone do it for you)
    int theRestMax = maxOf(elems.subList(1,elems.size()-1));
    // compare your point with the max point in the rest
    return first > theRestMax ? first: theRestMax;
}

int maxOfDevide(Vector<int> elems) {
    // edge case
    if(elems.size() == 1){
        return elems[0];
    }
    // divide the task into two parts
    int mid = elems.size() / 2;
    // get the max point in the first part
    Vector<int> left= elems.subList(0,mid);
    int left_max = maxOfDevide(left);
    // get the max point in the second part
    Vector<int> right = elems.subList(mid);
    int right_max = maxOfDevide(right);
    // compare the two max points
    return left_max > right_max ? left_max : right_max;
}

int maxOfRef(Vector<int> &elems, int start, int end) {
    (void)elems;
    (void)start;
    (void)end;
    // edge case

    // divide the task into two parts

    // get the max point in the first part

    // get the max point in the second part

    // compare the two max points
    return 0;
}

int main() {
    if (runSimpleTests(SELECTED_TESTS))
        return 0;

    return 0;
}

// *********************** Testing Case ****************************

STUDENT_TEST("Test for the edge test"){
    Vector<int> v = {9};
    EXPECT_EQUAL(maxOf(v),9);
}

STUDENT_TEST("Test for the maxOf"){
    Vector<int> v= {1,3,5,8};
    EXPECT_EQUAL(maxOfDevide(v),8);
}

STUDENT_TEST("Scale Test for the maxOf"){
    Vector<int> v;
    for(int i = 0; i < 500; i++){
        v.add(randomInteger(0,100));
    }
    // double the vector
    for (int i = 0; i < 5; ++i) {
        int size = v.size();
        for(int i = 0; i < size ; i++){
            v.add(randomInteger(0,100));
        }
       TIME_OPERATION(v.size(),maxOf(v));
    }
}


STUDENT_TEST("Scale Test for the maxOfDivide"){
    Vector<int> v;
    for(int i = 0; i < 500; i++){
        v.add(randomInteger(0,100));
    }
    // double the vector
    for (int i = 0; i < 5; ++i) {
        int size = v.size();
        for(int i = 0; i < size ; i++){
            v.add(randomInteger(0,100));
        }
       TIME_OPERATION(v.size(),maxOfDevide(v));
    }
}

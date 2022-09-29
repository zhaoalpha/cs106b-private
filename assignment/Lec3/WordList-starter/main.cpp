#include "console.h"
#include "map.h"
#include "set.h"
#include "simpio.h"
#include "vector.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Vector<string> wordlist;

    while (true) {
        string word = getLine("Enter your word: ");
        if (word == "")
            break;
        wordlist.add(word);
    }

    cout << wordlist << endl;

    return 0;
}

/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include "testing/SimpleTest.h"
#include "strlib.h"
#include "filelib.h"
#include "simpio.h"
#include <fstream>
#include <cctype>
#include <string>
#include "vector.h"
using namespace std;

/* This function is intended to return a string which
 * contains only the letter characters from the original
 * (all non-letter characters are removed)
 *
 * WARNING: The provided code is buggy!
 *
 * Use unit tests to identify which inputs to this function
 * are incorrectly handled. Then, remove this comment and
 * replace it with a description of the bug you fixed.
 */
string removeNonLetters(string s) {
    string result;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            result += s[i];
        }
    }
    return result;
}

/**
 * accorading to the code table to encode the input s
 * @brief encode
 * @param s
 * @return
 */
string encode(string s){
    if(s.empty()){
        return "";
    }
    string result;
    vector<string> codeTable = {"AEIOUHWY","BFPV","CGJKQSXZ","DT","L","MN","R"};
    for(int i = 0; i < s.length(); ++i){
        char uppeCaseLetter = toupper(s[i]);
       for(int j= 0; j < codeTable.size(); j++){
          if(codeTable[j].find(uppeCaseLetter) != std::string::npos){
              result+=to_string(j);
          }
       }
    }
    return result;
}

string removeAdjacentDuplicate(string s){
    if(s.empty() || s.size() == 1){
        return s;
    }
    int slow = 0;
    int fast = 1;
    while(fast < s.length()){
       if(s[slow] != s[fast]){
            slow++;
            s[slow] = s[fast];
       }
       fast++;
    }
    s.resize(slow+1);
    return s;
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
string soundex(string s) {
    /* TODO: Fill in this function. */
    return "";
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
void soundexSearch(string filepath) {
    // The proivded code opens the file with the given name
    // and then reads the lines of that file into a vector.
    ifstream in;
    Vector<string> databaseNames;

    if (openFile(in, filepath)) {
        readEntireFile(in, databaseNames);
    }
    cout << "Read file " << filepath << ", "
         << databaseNames.size() << " names found." << endl;

    // The names in the database are now stored in the provided
    // vector named databaseNames

    /* TODO: Fill in the remainder of this function. */
}


/* * * * * * Test Cases * * * * * */


PROVIDED_TEST("Test removing puntuation, digits, and spaces") {
    string s = "O'Hara";
    string result = removeNonLetters(s);
    EXPECT_EQUAL(result, "OHara");
    s = "Planet9";
    result = removeNonLetters(s);
    EXPECT_EQUAL(result, "Planet");
    s = "tl dr";
    result = removeNonLetters(s);
    EXPECT_EQUAL(result, "tldr");
}


PROVIDED_TEST("Sample inputs from handout") {
    EXPECT_EQUAL(soundex("Curie"), "C600");
    EXPECT_EQUAL(soundex("O'Conner"), "O256");
}

PROVIDED_TEST("hanrahan is in lowercase") {
    EXPECT_EQUAL(soundex("hanrahan"), "H565");
}

PROVIDED_TEST("DRELL is in uppercase") {
    EXPECT_EQUAL(soundex("DRELL"), "D640");
}

PROVIDED_TEST("Liu has to be padded with zeros") {
    EXPECT_EQUAL(soundex("Liu"), "L000");
}

PROVIDED_TEST("Tessier-Lavigne has a hyphen") {
    EXPECT_EQUAL(soundex("Tessier-Lavigne"), "T264");
}

PROVIDED_TEST("Au consists of only vowels") {
    EXPECT_EQUAL(soundex("Au"), "A000");
}

PROVIDED_TEST("Egilsdottir is long and starts with a vowel") {
    EXPECT_EQUAL(soundex("Egilsdottir"), "E242");
}

PROVIDED_TEST("Jackson has three adjcaent duplicate codes") {
    EXPECT_EQUAL(soundex("Jackson"), "J250");
}

PROVIDED_TEST("Schwarz begins with a pair of duplicate codes") {
    EXPECT_EQUAL(soundex("Schwarz"), "S620");
}

PROVIDED_TEST("Van Niekerk has a space between repeated n's") {
    EXPECT_EQUAL(soundex("Van Niekerk"), "V526");
}

PROVIDED_TEST("Wharton begins with Wh") {
    EXPECT_EQUAL(soundex("Wharton"), "W635");
}

PROVIDED_TEST("Ashcraft is not a special case") {
    // Some versions of Soundex make special case for consecutive codes split by hw
    // We do not make this special case, just treat same as codes split by vowel
    EXPECT_EQUAL(soundex("Ashcraft"), "A226");
}

// TODO: add your test cases here

STUDENT_TEST("Test removeNonLetters with empty string "){
    string s = "";
    string expected = "";
    EXPECT_EQUAL(removeNonLetters(s),expected);
}

STUDENT_TEST("Test removeNonLetters with none letters"){
    string s = "12,!5678";
    string expected = "";
    EXPECT_EQUAL(removeNonLetters(s),expected);
}

STUDENT_TEST("Test encode"){
    string s = "";
    string expected = "";
    EXPECT_EQUAL(encode(s),expected);

    s= "Curie";
    expected = "20600";
    EXPECT_EQUAL(encode(s),expected);

    s= "Angelou";
    expected = "0520400";
    EXPECT_EQUAL(encode(s),expected);
}

STUDENT_TEST("Test removeAjacentDuplicate"){
    string s = "";
    string expected = "";
    EXPECT_EQUAL(removeAdjacentDuplicate(s),expected);

    s= "20600";
    expected = "2060";
    EXPECT_EQUAL(removeAdjacentDuplicate(s),expected);

    s= "222222";
    expected = "2";
    EXPECT_EQUAL(removeAdjacentDuplicate(s),expected);

    s= "1";
    expected = "1";
    EXPECT_EQUAL(removeAdjacentDuplicate(s),expected);
}




///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <iostream>
#include <exception>
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"
#include "Cats.h"
#include "config.h"
#define DEBUG
#define MAX_NAME "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx"
#define ILLEGAL_NAME "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy"
//#define BIRTHDAY
//#define OLD

using namespace std ;


int main() {

    cout << "Starting Animal Farm 2" << endl;

    addCats(new Cats("Loki", MALE, PERSIAN, 1.0));
    addCats(new Cats("Milo", MALE, MANX, 1.1));
    addCats(new Cats("Bella", FEMALE, MAINE_COON, 1.2));
    addCats(new Cats("Kali", FEMALE, SHORTHAIR, 1.3));
    addCats(new Cats("Trin", FEMALE, MANX, 1.4));
    addCats(new Cats("Chili", MALE, SHORTHAIR, 1.5));

    printAllCats();
    deleteAllCats();
    printAllCats();
    cout << "Done with Animal Farm 2" << endl;


#ifdef DEBUG

    //test default values
    Cats testCat = Cats();

    Cats testCat2 = Cats("test", MALE, PERSIAN, 1.0);

    testCat.print();

    testCat2.print();

    //test validate name
    testCat.validateName("");

    //test validate gender
    testCat.validateGender(UNKNOWN_GENDER);

    //test validate breed
    testCat.validateBreed(UNKNOWN_BREED);

    //test validate weight
    testCat.validateWeight(-1);

    //test validate cat
    testCat2.validate();
    printf("this one should have an error: \n");
    testCat.validate();

    //test validation in addCat
    try {
        printf("addCats validation failure Name: \n");
        addCats(new Cats("", MALE, PERSIAN, 1.0));
        assert(false);
    } catch (exception const &e) {}
    try {
        printf("addCats validation failure Gender: \n");
        addCats(new Cats("test", UNKNOWN_GENDER, PERSIAN, 1.0));
        assert(false);
    } catch (exception const &e) {}
    try {
        printf("addCats validation failure Breed: \n");
        addCats(new Cats("test", MALE, UNKNOWN_BREED, 1.0));
        assert(false);
    } catch (exception const &e) {}
    try {
        printf("addCats validation failure Weight: \n");
        addCats(new Cats("test", MALE, PERSIAN, -1.0));
        assert(false);
    } catch (exception const &e) {}

    //test addCats
    printf("adding three test cats to linked list using addCats\n");
    addCats(new Cats("test", MALE, PERSIAN, 1.0));
    addCats(new Cats("Milo", MALE, MANX , 1.1));
    addCats(new Cats("Bella", FEMALE, MAINE_COON, 1.2));

    //test printallcats
    printAllCats();

    //test findCatbyName
    //no match
    printf("testing findCat with no match:\n");
    try {
        findCatByName("no match");
        assert(false);
    } catch (exception const &e) {}
    printf("testing findCat with match Milo (address and printCat):\n");
    //match (used print method to print match)
    cout << findCatByName( "Milo" ) << endl;
    findCatByName("Milo")->print();


    //test delete cat
    //case: first in list
    printf("testing delete cat:\n");
    deleteCat(findCatByName("Bella"));
    try {
        findCatByName("Bella")->print();
        assert(false);
    } catch (exception const &e) {}
    //case: not first
    deleteCat(findCatByName("test"));
    try {
        findCatByName("test")->print();
        assert(false);
    } catch (exception const &e) {}


    std:: cerr  << PROGRAM_NAME << " is the name of the program"  << std:: endl;

    //addCats(new Cats("test", UNKNOWN_GENDER, PERSIAN, 1.0));
#endif
    return 0;
}



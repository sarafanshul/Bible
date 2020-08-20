
/*
                                emplace_back vs push_back

The real primary difference has to do with implicit vs. explicit constructors

REFER -> https://stackoverflow.com/a/36919571

SUMMARY 

After your optimizing compiler gets its hands on this, 
there is no difference between these two statements in terms of generated code. 
    -> The traditional wisdom is that push_back will construct a temporary object, 
        which will then get moved into v whereas emplace_back will forward the 
        argument along and construct it directly in place with no copies or moves. 
        This may be true based on the code as written in standard libraries, 
        but it makes the mistaken assumption that the optimizing compiler's job 
        is to generate the code you wrote. 
    -> The optimizing compiler's job is actually to generate the 
        code you WOULD HAVE WRITTEN if you were an expert on platform-specific 
        optimizations and did not care about maintainability, just performance.

The actual difference between these two statements is that 
the more powerful emplace_back will call -ANY- type of constructor out there, 
whereas the more cautious push_back will call -ONLY- constructors that are implicit. 
Implicit constructors are supposed to be -SAFE-.

If you can implicitly construct a U from a T, 
you are saying that U can hold all of the information in T with no loss. 

It is safe in pretty much any situation to pass a T and no one will mind 
if you make it a U instead. 
 -> A good example of an implicit constructor is the conversion 
    from std::uint32_t to std::uint64_t. 
 -> A bad example of an implicit conversion is double to std::uint8_t.

We want to be cautious in our programming. 
We do not want to use powerful features because 
    the more powerful the feature, the easier it is to accidentally 
    do something incorrect or unexpected. 

If you intend to call explicit constructors, then you need the power of emplace_back. 

If you want to call only implicit constructors, stick with the safety of push_back.

Specific use case for emplace_back: 
    If you need to create a temporary object which will then be 
    pushed into a container, use emplace_back instead of push_back. 
    It will create the object in-place within the container.

Notes:

 1 -> push_back in the above case will create a temporary 
        object and move it into the container. 
        However, in-place construction used for emplace_back would 
        be more performant than constructing and then moving the 
        object (which generally involves some copying).

 2 -> In general, you can use emplace_back instead of 
        push_back in all the cases without much issue.

*/


// ------ EXAMPLE - 1 --------

#include <bits/stdc++.h>

#define PB push_back
#define EB emplace_back

using namespace std;

class A{
public:
    A(int x) { cout<<"A constructor called!!\n"; }
    ~A() { cout<<"A destructor called!!\n"; }
};
 
int32_t main(){
    vector<A> a;
    a.reserve(100);
    cout << "\nPB\n";
    a.PB(A(10));
    cout << "\nEB\n";
    a.EB(2);
    cout << "\n-END-\n";
    return 0;
}


/* OUTPUT

PB
A constructor called!!
A destructor called!!

EB
A constructor called!!

-END-
A destructor called!!
A destructor called!!

=====
Used: 0 ms, 256 KB

*/


// ------ EXAMPLE 2 -------

#include <vector>
#include <string>
#include <iostream>
 
struct President {
    std::string name;
    std::string country;
    int year;
 
    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year){
        std::cout << "I am being constructed.\n";
    }
    
    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year){
        std::cout << "I am being moved.\n";
    }
    
    President& operator=(const President& other) = default;
};
 
int main(){
    std::vector<President> elections;
    std::cout << "emplace_back:\n";
    elections.emplace_back("Nelson Mandela", "South Africa", 1994);
 
    std::vector<President> reElections;
    reElections.reserve(10);
    std::cout << "\npush_back:\n";
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));

// -> for push_back 1) we need to create a object  ,which is not needed in emplace_back
    
    // std::cout << "\npush_back:\n";
    // reElections.push_back("Franklin Delano Roosevelt", "the USA", 1936);
    
// -> above will give compilation error  ,bellow will not;
    
    // EXPLICIT CREATION OF OBJECT WORKS SAME AS PUSH_BACK
    std::cout << "\nemplace_back(EXPLICIT):\n";
    reElections.emplace_back(President("Franklin Delano Roosevelt", "the USA", 1936));
 
    std::cout << "\nContents:\n";
    for (President const& president: elections) {
        std::cout << president.name << " was elected president of "
                  << president.country << " in " << president.year << ".\n";
    }
    for (President const& president: reElections) {
        std::cout << president.name << " was re-elected president of "
                  << president.country << " in " << president.year << ".\n";
    }
}

/*OUTPUT

emplace_back:
I am being constructed.

push_back:
I am being constructed.
I am being moved.

emplace_back(EXPLICIT):
I am being constructed.
I am being moved.

Contents:
Nelson Mandela was elected president of South Africa in 1994.
Franklin D...
=====
Used: 15 ms, 4 KB
*/
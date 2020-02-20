#include "Movie.h"
#include <iostream>
using std::cout;
using std::endl;
Movie::Movie(std::string name_val, std::string rating_val, int times_watched_val)
    : name{name_val}, rating{rating_val}, times_watched{times_watched_val}
{
}

Movie::~Movie()
{
}

std::string Movie::get_name(){
    return name;
}
std::string Movie::get_rating(){
    return rating;
}
int Movie::get_times_watched(){
    return times_watched;
}
void Movie::increment_times_watched(){
    times_watched++;
}
void Movie::decrement_times_watched(){
    if(times_watched>0){
        times_watched--;
    } else{
        std::cout<<"Watch the movie at least once before decrementing!"<<std::endl;
    }
}
void Movie::display_movie(){
    cout<<"Title: " << name <<endl;
    cout<< "Rating: " << rating <<endl;
    cout<< "Times watched: " << times_watched <<endl;
    cout<< "-------------------------------------------------------------------------"<<endl;
}


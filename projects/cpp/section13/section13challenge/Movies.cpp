#include "Movies.h"
#include "Movie.h"
#include <iostream>
using std::cout;
using std::endl;
Movies::Movies()
{
}

Movies::~Movies()
{
}

int Movies::get_size(){
    return movie_vec.size();
}
void Movies::display_movies(){
    for(size_t i{0}; i<movie_vec.size(); i++){
        movie_vec[i].display_movie();
    }
}
void Movies::add_movie(std::string name_val, std::string rating_val, int times_watched_val){
    if(movie_vec.size()==0){
        Movie temp(name_val, rating_val, times_watched_val);
        movie_vec.push_back(temp);
    } else{
        for(size_t i{0}; i<movie_vec.size(); i++){
            if(movie_vec[i].get_name() == name_val){
                cout << "That movie is already in the vector"<<endl;
                break;
            } else if(i==movie_vec.size()-1){
                Movie temp(name_val, rating_val, times_watched_val);
                movie_vec.push_back(temp);
            } 
        }   
    }
}
void Movies::increment_watch_count(std::string movie_name){
    for(size_t i{0}; i<movie_vec.size(); i++){
        if(movie_vec[i].get_name() == movie_name){
            movie_vec[i].increment_times_watched();
        } else{
            cout<<"That movie isn't in the vector"<<endl;
        }
    }
}
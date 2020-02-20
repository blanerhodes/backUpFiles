#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <vector>
#include <string>
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> movie_vec;
    
public:
    void add_movie(std::string name_val, std::string rating_val, int times_watched_val);
    void increment_watch_count(std::string movie_name);
    void display_movies();
    int get_size();
    Movies();
    ~Movies();

};

#endif // _MOVIES_H_

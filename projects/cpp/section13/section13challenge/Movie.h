#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>
class Movie
{
private:
    std::string name;
    std::string rating;
    int times_watched;

public:
    std::string get_name();
    std::string get_rating();
    int get_times_watched();
    void increment_times_watched();
    void decrement_times_watched();
    void display_movie();
    Movie(std::string name_val = "None", std::string rating_val = "G", int times_watched_val = 0);
    ~Movie();

};

#endif // _MOVIE_H_

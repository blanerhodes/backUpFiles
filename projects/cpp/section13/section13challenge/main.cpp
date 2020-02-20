#include <iostream>
#include <vector>\
#include "Movie.h"
#include "Movies.h"
using std::cout;
using std::endl;
void display_menu();
char get_selection();
void handle_add();


int main(){
    char selection{};
    Movies movies_vector;
    do{
        display_menu();
        selection = get_selection();
        switch(selection){
            case 'D':
                movies_vector.display_movies();
                break;
            case 'A': {
                std::string title;
                std::string age_rating;
                int amount_watched;
                cout<<"Input the movie title: ";
                std::cin>> title;
                
                cout<< "Input the age group rating: ";
                std::cin>> age_rating;
               
                cout<<"Input how many times you've seen the movie: ";
                std::cin>>amount_watched;
               
                movies_vector.add_movie(title, age_rating, amount_watched);
            }
                break;
            case 'W':{
                std::string title;
                cout<<"Input what movie you want to increment: ";
               std::cin>>title;
                movies_vector.increment_watch_count(title);
                
            }
                break;
            case 'Q':
                cout<<"Goodbye!"<<endl;
                break;
        }
        
        
    } while(selection != 'Q');
    
    return 0;
}

void display_menu(){
    cout<<"D - Display all movies"<<endl;
    cout<<"A - Add movie to vector"<<endl;
    cout<<"W - Increment times_watched for given movie"<<endl;
    cout<< "Q - Quit program"<<endl;
    cout<<"Input selection: ";
}
char get_selection(){
    char selection{};
    std::cin>>selection;
    return toupper(selection);
}

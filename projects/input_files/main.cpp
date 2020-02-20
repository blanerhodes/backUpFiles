#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Movie{
    string id; //string variable for a movie's ID
    string title; //string variable for a movie's title
    string actor1; //string variable for a movie's first actor
    string actor2; //string variable for a movie's second actor
    int released; //integer variable for a movie's release year
    double rating; //double variable for a movie's rating 0-10
};

int getMovieData(Movie[], int SIZE);
int displayMenu();
void displayArrayKeyValues(Movie[], int);
void displayByTitle(Movie[], int);
void displayByRating(Movie[], int);
void getActorsAndTitleById(Movie[], int);
void getIdByActorsAndTitle(Movie[], int);
void titleSort(Movie[], int);
void idSort(Movie[], int);
void ratingSort(Movie[], int);


int main() {
    Movie moviesData[100]; // array of Movie structs to store up to 100 movies read from the input file
    int numberOfMovies = getMovieData(moviesData, 100); // integer variable to hold the true number of movies that are read in
    Movie presentMovies[numberOfMovies]; // array of Movie structs to store the actual movies read in, reduces array size of movies Data
    for(int i=0; i<numberOfMovies; i++){
        presentMovies[i] = moviesData[i];
    }

    int userChoice = 0; // integer value to accept a user's menu choice
    do{
        userChoice = displayMenu();
        switch(userChoice){
            case 1: displayByTitle(presentMovies, numberOfMovies); break;
            case 2: displayByRating(presentMovies, numberOfMovies); break;
            case 3: getActorsAndTitleById(presentMovies, numberOfMovies); break;
            case 4: getIdByActorsAndTitle(presentMovies, numberOfMovies); break;
            case 5: cout<<"Thank you for using the imdb.com app"<<endl; exit(0);
            default: cout<<"That is an illegal input. Please try again."<<endl;
        }
    }while(userChoice != 5);
}

//***********************************************************
// getMovieData: creates an input file stream, reads in movie data, populates moviesData array with data
//
// moviesData: the array to be populated with data
// SIZE: size of array being passed
// returns: movieCount applied to numberOfMovies for making the smaller working array
//***********************************************************
int getMovieData(Movie moviesData[], int SIZE){
    ifstream data; // input stream to read in movie data from input file
    data.open("./library.txt");
    if(!data){
        cout<<"Error: The file cannot be accessed."<<endl;
        return 1;
    }
    int movieCount = 0; // integer count of how many movies are read into the moviesData array
    while(data>>moviesData[movieCount].id){ //THIS WORKS BUT SEE ABOUT CHANGING IT TO CHECK FOR EOF
        data>>ws;
        getline(data, moviesData[movieCount].title);
        data>>ws;
        getline(data, moviesData[movieCount].actor1);
        data>>ws;
        getline(data, moviesData[movieCount].actor2);
        data>>ws;
        data>>moviesData[movieCount].released;
        data>>moviesData[movieCount].rating;
        movieCount++;
    }
    data.close();
    return movieCount;
};

//***********************************************************
// displayMenu: displays possible user choices
//
// returns: userInput to be applied to userChoice for while loop in main
//***********************************************************
int displayMenu(){
    int userInput; // integer value to accept a user's choice, passed to userChoice in main
    cout<<endl;
    cout<<"Menu"<<endl;
    cout<<endl;
    cout<<"1. Display movies sorted by title"<<endl;
    cout<<"2. Display movies sorted by rating"<<endl;
    cout<<"3. Lookup title and actors by id"<<endl;
    cout<<"4. Lookup id by title and either actor"<<endl;
    cout<<"5. Quit the Program"<<endl;
    cout<<endl;
    cout<<"Enter your choice: ";
    cin>>userInput;
    cout<<endl;
    return userInput;
}

//***********************************************************
// displayArrayKeyValues: displays movie information for each movie from the working array
//
// presentMovies: working array of movies
// SIZE: size of the passed array
//***********************************************************
void displayArrayKeyValues(Movie presentMovies[], int SIZE){
    for(int i=0; i<SIZE; i++){
        cout<<left<<setw(21)<<presentMovies[i].title;
        cout<<left<<setw(21)<<presentMovies[i].actor1;
        cout<<left<<setw(15)<<presentMovies[i].actor2;
        cout<<left<<setw(6)<<presentMovies[i].released;
        cout<<presentMovies[i].rating;
        cout<<endl;
    }
}

//***********************************************************
// displayByTitle: displays movies sorted by title
//
// presentMovies: working array of movies
// SIZE: size of the passed array
//***********************************************************
void displayByTitle(Movie presentMovies[], int SIZE){
    titleSort(presentMovies, SIZE);
    displayArrayKeyValues(presentMovies, SIZE);
}

//***********************************************************
// displayByRating: displays movies sorted by rating
//
// presentMovies: working array of movies
// SIZE: size of the passed array
//***********************************************************
void displayByRating(Movie presentMovies[], int SIZE){
    ratingSort(presentMovies, SIZE);
    displayArrayKeyValues(presentMovies, SIZE);
}

//***********************************************************
// getActorsAndTitleById: gets actor and title data based on user input of movie ID and displays this data
//
// presentMovies: working array of movies
// SIZE: size of the passed array
//***********************************************************
void getActorsAndTitleById(Movie presentMovies[], int SIZE){
    string movieID; // string variable to accept what ID the user is looking for
    cout<<"Enter the id of the movie: ";
    cin>>movieID;
    cout<<endl;
    idSort(presentMovies, SIZE);
    int firstIndex = 0; // first position of binary search comparison
    int lastIndex = SIZE-1; // final position of binary search comparison
    bool foundMovie = false; // state variable to signal loop exit (whether a movie is found or not)
    while(!foundMovie){
        int middleIndex = (lastIndex + firstIndex) / 2; // target index the binary search will collapse upon when updated
        if(presentMovies[middleIndex].id == movieID){
            cout<<"The movie with id "<<movieID<<" is:"<<endl;
            cout<<presentMovies[middleIndex].title<<endl;
            cout<<"Actors:"<<endl;
            cout<<presentMovies[middleIndex].actor1<<endl;
            cout<<presentMovies[middleIndex].actor2<<endl;
            foundMovie = true;
        }else if(firstIndex >= lastIndex){
            cout<<"No movie found with that id."<<endl;
            foundMovie = true;
        }else{
            if(movieID>presentMovies[middleIndex].id){
                firstIndex = middleIndex + 1;
            } else{
                lastIndex = middleIndex - 1;
            }
        }
    }
}

//***********************************************************
// getIdByActorsAndTitle: gets movie ID based on user input of movie title and a movie actor and displays this data
//
// presentMovies: working array of movies
// SIZE: size of the passed array
//***********************************************************
void getIdByActorsAndTitle(Movie presentMovies[], int SIZE){
    string movieTitle; // string variable to accept the title the user is looking for
    string actor; // string variable to accept either actor of the movie the user is looking for
    cout<<"Enter the title: ";
    cin>>ws;
    getline(cin, movieTitle);
    cout<<"Enter either actor: ";
    cin>>ws;
    getline(cin, actor);
    cout<<endl;
    bool foundMovie = false; // state variable to track if a move was found based on user input for error message use
    for(int i=0; i<SIZE; i++){
        if(presentMovies[i].title==movieTitle && (presentMovies[i].actor1==actor || presentMovies[i].actor2==actor)){
            cout<<"The id of "<<presentMovies[i].title;
            cout<<" with "<<presentMovies[i].actor1<<" and "<<presentMovies[i].actor2;
            cout<<" is "<<presentMovies[i].id<<endl;
            foundMovie = true;
            break;
        }
    }
    if(!foundMovie){
        cout<<"A movie with the given title and actor combination was not found. Please try another search."<<endl;
    }
}

//***********************************************************
// titleSort: sorts working array by movie title via bubble sort (ascending)
//
// presentMovies: working array of movies
// SIZE: size of the passed array
//***********************************************************
void titleSort(Movie presentMovies[], int SIZE){
    Movie tempPosition; // struct variable to temporarily store an array's value during bubble sort swapping
    bool swapOccurred = true; // state variable to flag if the bubble sort should continue
    while(swapOccurred){
        swapOccurred = false;
        for(int i=0; i<(SIZE-1); i++){
            if(presentMovies[i+1].title < presentMovies[i].title){
                tempPosition = presentMovies[i];
                presentMovies[i] = presentMovies[i+1];
                presentMovies[i+1]= tempPosition;
                swapOccurred = true;
            }
        }
    }
}

//***********************************************************
// idSort: sorts working array by movie id via bubble sort (ascending)
//
// presentMovies: working array of movies
// SIZE: size of the passed array
//***********************************************************
void idSort(Movie presentMovies[], int SIZE){
    Movie tempPosition; // struct variable to temporarily store an array's value during bubble sort swapping
    bool swapOccurred = true; // state variable to flag if the bubble sort should continue
    while(swapOccurred){
        swapOccurred = false;
        for(int i=0; i<(SIZE-1); i++){
            if(presentMovies[i+1].id < presentMovies[i].id){
                tempPosition = presentMovies[i];
                presentMovies[i] = presentMovies[i+1];
                presentMovies[i+1]= tempPosition;
                swapOccurred = true;
            }
        }
    }
}

//***********************************************************
// ratingSort: sorts working array by movie rating via bubble sort (descending)
//
// presentMovies: working array of movies
// SIZE: size of the passed array
//***********************************************************
void ratingSort(Movie presentMovies[], int SIZE) {
    Movie tempPosition; // struct variable to temporarily store an array's value during bubble sort swapping
    bool swapOccurred = true; // state variable to flag if the bubble sort should continue
    while (swapOccurred) {
        swapOccurred = false;
        for (int i = 0; i < (SIZE - 1); i++) {
            if (presentMovies[i + 1].rating > presentMovies[i].rating) {
                tempPosition = presentMovies[i];
                presentMovies[i] = presentMovies[i + 1];
                presentMovies[i + 1] = tempPosition;
                swapOccurred = true;
            }
        }
    }
}

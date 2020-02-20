#include <iostream>
#include <fstream>
#include <sstream>
#include "Document.h"


int main() {
    std::vector<std::string> someTags {"Character", "Main Story", "Good"};
    std::string testTitle = "Blane";
    std::string testContent = "Blane is a main story character on the good side.";
    Document *testDoc = new Document(someTags, testTitle, testContent);

    std::ofstream fileOut ("/home/blane/IdeaProjects/test.txt", std::ios::out | std::ios::trunc);
    std::vector<std::string> emptyVec;
    std::vector<std::string> tagVec = testDoc->getTags(emptyVec);
    for(int i=0; i<tagVec.size(); i++){
        if(i == tagVec.size()-1){
            fileOut<<tagVec.at(i)<<"|";
        } else{
            fileOut<<tagVec.at(i)<<",";
        }
    }
    fileOut<<testDoc->getTitle()<<"|";
    fileOut<<testDoc->getContent()<<"\n";
    fileOut.close();
    delete testDoc;

    std::ifstream fileIn ("/home/blane/IdeaProjects/test.txt", std::ios::in);
    Document *pullTestDoc = new Document();
    std::vector<std::string> row;
    std::string line, word, temp;
    //get all tags
    row.clear();
    getline(fileIn, line, '|');
    std::stringstream s(line); //figure out what this does
    while(getline(s, word, ',')){
        row.push_back(word);
    }
    //idk if creating a new document object is a good idea or if we should just read straight from the filetio
    int x =5;
    std::cout<<declval((x));

    return 0;
}
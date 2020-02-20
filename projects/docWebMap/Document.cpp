//
// Created by blane on 1/17/20.
//
#include "Document.h"
#include <iostream>
#include <algorithm>

//need to decide if we want to put the searching debt on search functions or sort tags when its updated and use binary search
//for now im keeping the vector unsorted
//should this handle multiple tags

Document::Document(std::vector<std::string> startingTags, std::string startTitle, std::string startContent){
    tags = startingTags;
    title = startTitle;
    content = startContent;
}

Document::Document(){
    title = "No Title";
    content = "No Content";
}

void Document::removeTag(std::string toRemove) {
    for(int i{0}; i<tags.size(); i++){
        if(tags.at(i) == toRemove){
            tags.erase(tags.begin()+i);
            break;
        } else if(i == tags.size()-1){
            std::cout<<"Tag not found\n";
        }
    }
}

//again could change depending on sorting data structure
void Document::addTag(std::string toAdd) {
    tags.push_back(toAdd);
}

//this does a full rewrite of the files content, look into making this more efficient
void Document::setContent(std::string newContent) {
    content = newContent;
}

//this does a full rewrite of the title but that shouldnt matter since it's small
void Document::editTitle(std::string newTitle) {
    title = newTitle;
}

std::string Document::getContent() {
    return content;
}

std::string Document::getTitle() {
    return title;
}

//this prints all tags if an empty vector is given and prints whether or not a tag is there if a vector of tags is provided
//idk if this should be two functions or not
std::vector<std::string> Document::getTags(std::vector<std::string> tagSearch) {
    std::vector<std::string>::iterator it;
    if(tagSearch.empty()){
        return tags;
    } else{
        std::vector<std::string> tagsFound;
        for(int i=0; i<tagSearch.size(); i++){
            it = find(tags.begin(), tags.end(), tagSearch.at(i));
            if(it == tags.end()){
                std::cout<<tagSearch.at(i)<<" is not a tag of this document.\n";
            } else{
                tagsFound.push_back(tagSearch.at(i));
            }
        }
        return tagsFound;
    }
}
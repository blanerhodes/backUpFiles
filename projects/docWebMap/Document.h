//
// Created by blane on 1/17/20.
//

#ifndef PROJECTBACKEND_DOCUMENT_H
#define PROJECTBACKEND_DOCUMENT_H
#include <vector>
#include <string>

class Document {
private:
    std::vector<std::string> tags;
    std::string content;
    std::string title;
public:
    Document(std::vector<std::string>, std::string, std::string);
    Document();
    void addTag(std::string);
    void removeTag(std::string);
    void editTitle(std::string);
    void setContent(std::string);
    std::vector<std::string> getTags(std::vector<std::string>);
    std::string getContent();
    std::string getTitle();
};


#endif //PROJECTBACKEND_DOCUMENT_H

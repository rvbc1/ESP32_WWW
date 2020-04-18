#ifndef HTML_ELEMENT_H
#define HTML_ELEMENT_H

#include <string>

class HTML_Element{
public:
    HTML_Element(std::string name);
    std::string name;
    std::string value;
    std::string getString();
    HTML_Element *child = 0;
    void addChild(HTML_Element *child);
};

#endif
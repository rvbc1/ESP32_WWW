#ifndef HTML_ELEMENT_H
#define HTML_ELEMENT_H

#include <string>
#include "html_element_list.h"

#define NULL 0

class HTML_Element{
public:
    HTML_Element(std::string name);
    std::string name;
    std::string value;
    std::string getString();
    HTML_Element *child = NULL;
    HTML_Element_List list;
    void addChild(HTML_Element *child);
};

#endif
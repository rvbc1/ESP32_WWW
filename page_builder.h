#ifndef PAGE_BUILDER_H
#define PAGE_BUILDER_H

#include <string>
#include "html_element.h"

class Page_Builder{
public:
    Page_Builder();
    std::string getPageSource();
    HTML_Element *head;
    HTML_Element *body;
};

#endif
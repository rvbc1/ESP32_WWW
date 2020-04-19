#ifndef PAGE_BUILDER_H
#define PAGE_BUILDER_H

#include <string>
#include "html_tag.h"

class Page_Builder{
public:
    Page_Builder();
    std::string getPageSource();
    HTML_Tag *docktype;
    HTML_Tag *html;
    HTML_Tag *head;
    HTML_Tag *body;
};

#endif
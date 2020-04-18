#ifndef HTML_ELEMENT_LIST_H
#define HTML_ELEMENT_LIST_H


#include "html_element_list_item.h"

class HTML_Element;

class HTML_Element_List{
private:
    unsigned int size = 0;
    HTML_Element_List_Item *first = 0;
public:
    HTML_Element_List();
    void addElement(HTML_Element *element);
    HTML_Element *getElement(int index);
};

#endif
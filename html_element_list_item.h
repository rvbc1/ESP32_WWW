#ifndef HTML_ELEMENT_LIST_ITEM_H
#define HTML_ELEMENT_LIST_ITEM_H


//#include "html_element.h"
class HTML_Element;

class HTML_Element_List_Item{
private:
    HTML_Element_List_Item *next = 0;
    HTML_Element *element;
public:
    HTML_Element_List_Item(HTML_Element *element);
    HTML_Element *getElement();
    void setNext(HTML_Element_List_Item* item);
};

#endif
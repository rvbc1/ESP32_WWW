#ifndef HTML_ELEMENT_LIST_ITEM_H
#define HTML_ELEMENT_LIST_ITEM_H


//#include "html_element.h"
class HTML_Tag;

class HTML_Tag_List_Item{
private:
 //   HTML_Element_List_Item *next = 0;
    HTML_Tag *element;
public:
    HTML_Tag_List_Item *next = 0;

    HTML_Tag_List_Item(HTML_Tag *element);
    HTML_Tag *getElement();
    void setNext(HTML_Tag_List_Item* item);
};

#endif
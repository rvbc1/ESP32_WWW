#ifndef HTML_ELEMENT_LIST_H
#define HTML_ELEMENT_LIST_H

#include "html_tag_list_item.h"

class HTML_Tag;

class HTML_Tag_List {
   private:
    unsigned int size = 0;
    HTML_Tag_List_Item *first = 0;
    HTML_Tag_List_Item *last = 0;

   public:
    HTML_Tag_List();
    void addElement(HTML_Tag *element);
    HTML_Tag *getElement(int index);
    HTML_Tag_List_Item *getLast();
    unsigned int getSize();
};

#endif
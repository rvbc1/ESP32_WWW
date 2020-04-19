#ifndef HTML_ELEMENT_H
#define HTML_ELEMENT_H

#include <string>

#include "html_tag_list.h"

#define NULL 0

class HTML_Tag {
   public:
    static const int SINGLE_TAG = 1;
    static const int DOUBLE_TAG = 2;

    HTML_Tag(std::string name, int type = DOUBLE_TAG, std::string value = "");

    std::string getString();

    void addChild(HTML_Tag *child);
    void setValue(std::string value);

   private:
    int tag_type = -1;

    std::string name;
    std::string value;

    HTML_Tag_List list;
};

#endif
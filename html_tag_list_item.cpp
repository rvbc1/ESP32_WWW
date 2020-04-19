#include "html_tag_list_item.h"

HTML_Tag_List_Item::HTML_Tag_List_Item(HTML_Tag *element) {
    this->element = element;
}

HTML_Tag *HTML_Tag_List_Item::getElement() {
    return element;
}

void HTML_Tag_List_Item::setNext(HTML_Tag_List_Item *item) {
    next = item;
}
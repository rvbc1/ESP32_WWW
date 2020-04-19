#include "html_tag_list.h"

HTML_Tag_List::HTML_Tag_List() {
}

void HTML_Tag_List::addElement(HTML_Tag *element) {
    if (size == 0) {
        first = new HTML_Tag_List_Item(element);
        last = first;
    } else {
        HTML_Tag_List_Item *new_last = new HTML_Tag_List_Item(element);
        last->setNext(new_last);
        last = new_last;
    }
    size++;
}

HTML_Tag_List_Item *HTML_Tag_List::getLast() {
}

HTML_Tag *HTML_Tag_List::getElement(int index) {
    HTML_Tag_List_Item *item = first;
    if (index < size) {
        for (int i = 0; i < index; i++) {
            item = item->next;
        }
    }
    return item->getElement();
}

unsigned int HTML_Tag_List::getSize() {
    return size;
}
#include "html_element_list_item.h"

HTML_Element_List_Item::HTML_Element_List_Item(HTML_Element *element){
    this->element = element;
}


HTML_Element *HTML_Element_List_Item::getElement(){
    return element;
}

void HTML_Element_List_Item::setNext(HTML_Element_List_Item* item){
    next = item;
}
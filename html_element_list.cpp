#include "html_element_list.h"

HTML_Element_List::HTML_Element_List(){

}

void HTML_Element_List::addElement(HTML_Element *element){
    if(size == 0){
        first = new HTML_Element_List_Item(element);
    } else {
        first->setNext(new HTML_Element_List_Item(element));
    }
    size++;
}

HTML_Element *getElement(int index){
    //for()
}
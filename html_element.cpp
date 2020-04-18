#include "html_element.h"

HTML_Element::HTML_Element(std::string name){
    this->name = name;
}

std::string HTML_Element::getString(){
    std::string child;
    if(this->child != 0){
        child = this->child->getString();
    }
    return ("<" + name + ">" + child + value + "</" + name + ">");
    //return 3;
}

void HTML_Element::addChild(HTML_Element *child){
    this->child = child;
}
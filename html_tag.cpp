#include "html_tag.h"

#include <sstream>
#include <string>

namespace patch {
template <typename T>
std::string to_string(const T& n) {
    std::ostringstream stm;
    stm << n;
    return stm.str();
}
}  // namespace patch

HTML_Tag::HTML_Tag(std::string name, int tag_type, std::string value) {
    this->name = name;
    this->tag_type = tag_type;
    this->value = value;
}

std::string HTML_Tag::getString() {
    std::string return_string = "";
    if (tag_type == SINGLE_TAG) {
        return_string = "<" + name + " " + value + ">";
    } else if (tag_type == DOUBLE_TAG) {
        std::string child_string = "";

        for (int i = 0; i < list.getSize(); i++) {
            child_string += list.getElement(i)->getString();
        }

        return_string = "<" + name + ">" + child_string + value + "</" + name + ">";
    }
    return return_string;
}

void HTML_Tag::addChild(HTML_Tag* child) {
    //this->child = child;
    list.addElement(child);
}

 void HTML_Tag::setValue(std::string value){
     this->value = value;
 }
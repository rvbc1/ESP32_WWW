#include "page_builder.h"

Page_Builder::Page_Builder() {
    docktype = new HTML_Tag("!DOCTYPE", HTML_Tag::SINGLE_TAG, "html");
    html = new HTML_Tag("html");
    head = new HTML_Tag("head");


    head->addChild(new HTML_Tag("meta", HTML_Tag::SINGLE_TAG, "name=\"viewport\" content=\"width=device-width, initial-scale=1\""));
    head->addChild(new HTML_Tag("meta", HTML_Tag::SINGLE_TAG, "http-equiv=\"refresh\" content=\"1\"><link rel=\"icon\" href=\"data:,\""));

    HTML_Tag *css = new HTML_Tag("style");
    css->setValue("html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\nbody {background-color:gray;}\n.button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;\ntext-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}\n.button2 {background-color: #555555;}");

    head->addChild(css);

    body = new HTML_Tag("body");
    HTML_Tag *title = new HTML_Tag("h1");
    title->setValue("ESP32 Web Server1");


    body->addChild(title);
    body->addChild(title);


    html->addChild(head);
    html->addChild(body);
}

std::string Page_Builder::getPageSource() {
    return docktype->getString() + html->getString();
}
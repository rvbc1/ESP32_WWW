#include "page_builder.h"

Page_Builder::Page_Builder()
{
    //client.println("<!DOCTYPE html><html>");
    head = new HTML_Element("head");
    head->value = "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><meta http-equiv=\"refresh\" content=\"1\"><link rel=\"icon\" href=\"data:,\">";

    HTML_Element *css = new HTML_Element("style");
    css->value = "html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n.button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;\ntext-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}\n.button2 {background-color: #555555;}";

    head->addChild(css);

    body = new HTML_Element("body");
    HTML_Element *title = new HTML_Element("h1");
    title->value = "ESP32 Web Server";
    body->addChild(title);
}

std::string Page_Builder::getPageSource()
{
  //  std::string page = ""
    return "<!DOCTYPE html><html>" + head->getString() + body->getString() + "</html>";
}
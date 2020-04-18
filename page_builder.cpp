#include "page_builder.h"

Page_Builder::Page_Builder()
{
    //client.println("<!DOCTYPE html><html>");
    head = new HTML_Element("head");
    head->value = "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><meta http-equiv=\"refresh\" content=\"1\"><link rel=\"icon\" href=\"data:,\">";
    // client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    // client.println("<meta http-equiv=\"refresh\" content=\"1\">");
    // client.println("<link rel=\"icon\" href=\"data:,\">");
    // CSS to style the on/off buttons
    // Feel free to change the background-color and font-size attributes to fit your preferences
    
    HTML_Element *css = new HTML_Element("style");
    css->value = "html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n.button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;\ntext-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}\n.button2 {background-color: #555555;}";
    // client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    // client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
    // client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
    // client.println(".button2 {background-color: #555555;}</style></head>");
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
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "rapidxml/rapidxml.hpp"


rapidxml::xml_document<> doc;
rapidxml::xml_node<> *root_node = NULL;

struct action {
    action(): name(NULL), con_id(NULL) {}
    const char* name; 
    const char* con_id;
};

struct response {
    const char* summary;
    const char* response;
    const char* condition;
    const char* condition_level;
    struct action *act;
};

class conversationnode {
    public:
        unsigned int _id;
        const char * _root;
        unsigned int number_of_responses;
        struct response** responses;

    
        conversationnode(unsigned int id, std::string root) {
            _id = id;
            _root = root.c_str();
            number_of_responses = 0;
            responses = (struct response **) malloc(sizeof(struct response *));
        };

        void add_option(std::string _summary, std::string _response, struct action *_act, std::string condition = "", std::string condition_level = "" ) {
            struct response res = {_summary.c_str(), _response.c_str(), condition.c_str(), condition_level.c_str(),  _act};
            responses[number_of_responses] = (struct response *) malloc(sizeof(struct response));
            responses[number_of_responses++] = &res;
        }
};


conversationnode &implement_conversation() {

    std::ifstream ideas_file("ideas.xml");
    std::vector<char> buffer((std::istreambuf_iterator<char>(ideas_file)), std::istreambuf_iterator<char>());

    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);

    root_node = doc.first_node("dialogue");


    try {
        for(rapidxml::xml_node<> * conversation_node = root_node ->first_node("conversation"); conversation_node; conversation_node = conversation_node -> next_sibling()) {

            unsigned int id = std::atoi(conversation_node -> first_attribute("id") -> value());
            std::string root(conversation_node -> first_attribute("root") -> value());

            conversationnode con_node(id, root);

            for(rapidxml::xml_node<> * option_node = conversation_node -> first_node("option"); option_node; option_node = option_node -> next_sibling()) {
                std::string summary = option_node -> first_attribute("summary")->value();
                std::string response = option_node -> first_attribute("response")->value();
                std::string condition = "";
                std::string con_level = "";
                if(option_node -> first_attribute("condition") != NULL) {
                    condition = option_node -> first_attribute("condition") -> value();
                    con_level = option_node -> first_attribute("lvl") -> value();
                }
    

                if(option_node -> first_node("action") != NULL) {
                    for(rapidxml::xml_node<> * action_node = option_node -> first_node("action"); action_node; action_node = action_node -> next_sibling()) {

                        std::string action_name = action_node -> first_attribute("name") -> value();
                        std::string action_id = "";

                        if(action_node -> first_attribute("id") != NULL) {
                            action_id = action_node -> first_attribute("id") -> value();
                        }

                        struct action a = action();
                        a.con_id = con_level.c_str();
                        a.name = condition.c_str();

                        struct response res = {summary.c_str(), response.c_str(), condition.c_str(), con_level.c_str(), &a };

                        con_node.add_option(summary, response, &a);

                    }
                }
            }
        }

        
    } catch(std::exception& ex) {
        std::cout << ex.what() << std::endl;
        std::cout << "yas" << std::endl;
    }

    return 
}


int main(void) {
    
    

    


    return 0;
}
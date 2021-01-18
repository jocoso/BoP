#include <string>
#include <iostream>
#include <cstring>

#ifndef DIALOGUE_TREE_H
#define DIALOGUE_TREE_H


struct DialogueNode {
    const char* root_response;
    const char* choice;
    const char* char_response;
    unsigned int completed_choices;

    DialogueNode* branches[];
};

class ConversationTree {

    DialogueNode *root;

    public:
    // Root
    ConversationTree(const char*);
    ConversationTree(DialogueNode&);
    ConversationTree& add_choice(std::string, std::string, std::string);
    void play();
    void wipe_out(DialogueNode*);
    void destroy();
};



#endif
#include "conversationTree.h"

ConversationTree::ConversationTree(const char* root_response) {
    root = new DialogueNode;
    *root = {.root_response = root_response};
    *root -> branches = new DialogueNode;
    root -> completed_choices = 0;
}

ConversationTree::ConversationTree(DialogueNode &_root) {
    root = &_root;
    *root -> branches = new DialogueNode;
    root -> completed_choices = 0;
}

ConversationTree&  ConversationTree::add_choice(std::string choice, std::string char_response, std::string root_response) {
    root -> branches[root -> completed_choices] = new DialogueNode;
    // *root -> branches[root -> completed_choices] = { .choice = choice, .char_response = char_response, .root_response = root_response};

    // std::string choi(choice);
    root -> branches[root -> completed_choices]->choice = choice.c_str();
    root -> branches[root -> completed_choices] ->char_response = char_response.c_str();
    root -> branches[root -> completed_choices]->root_response = root_response.c_str();
    
    ConversationTree a(*root -> branches[root -> completed_choices++]);

    return a;
}


void ConversationTree::play() {
    do {
        if(root -> completed_choices > 0) {

            std::cout << root -> root_response << std::endl;


            for(int i = 0; i < root -> completed_choices; i++) {
                std::cout << i<< ") "<< root->branches[i]->choice << std::endl;
            }

            int a;
            std::cout << ">";
            std::cin >> a;

            std::cout << root -> branches[a] -> char_response << std::endl;

            root = root -> branches[a];

        }

    } while (root -> completed_choices > 0);

    std::cout << root -> root_response << std::endl;
    std::cout << std::flush;
}


void ConversationTree::wipe_out(DialogueNode *node) {
    if(node->completed_choices > 0) {
        for(int i = 0; i < node -> completed_choices; i++) {
            wipe_out(node->branches[i]);
        }
    }

    free(root);
}

// Only use this with the root answer you want to eliminate
void ConversationTree::destroy() {
    wipe_out(root);
}
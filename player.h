
#ifndef PLAYER_H_
#define PLAYER_H_


class Player {
    private:
        static int health;
        static int stamina;
        int perk[20];
        static int build[2];
        static int dexterity[2];
        static int people[2];
        static int intelligence[2];
        const unsigned int MAX_LEVEL_OF_UPDATES = 4;

    public:
        char private_name[50];
        char private_passwd[50];

        // MANAGEMENT
        int get_health();
        void change_health_by(double hp);
        int get_stamina();
        void change_stamina_by(double st);

        // BUILD
        // -------------------------------------------------
        // HEALTH
        int get_build_health();
        int increase_build_health_by_one();
        bool has_build_health_reached_max_value();

        // STRENGTH
        int get_build_strength();
        int increase_build_strength_by_one();
        bool has_build_strength_reached_max_value();

        // -------------------------------------------------

        // DEXTERITY
        // -------------------------------------------------

        // PRECISION
        int get_dexterity_perception();
        int increase_dexterity_perception_by_one();
        bool has_dexterity_perception_reached_max_value();

        // AGILITY
        int get_dexterity_agility();
        int increase_dexterity_agility_by_one();
        bool has_dexterity_agility_reached_max_value();
    
        // -------------------------------------------------


        // PEOPLE
        // -------------------------------------------------
        // COOL
        int get_people_cool();
        int increase_people_cool_by_one();
        bool has_people_cool_reached_max_value();

        // BARTER
        int get_people_barter();
        int increase_people_barter_by_one();
        bool has_people_barter_reached_max_value();
        // -------------------------------------------------


        // INTELLIGENCE
        // -------------------------------------------------
        // SCIENCE
        int get_intelligence_science();
        int increase_intelligence_science_by_one();
        bool has_intelligence_science_reached_max_value();

        // ENGINEERING
        int get_intelligence_engineering();
        int increase_intelligence_engineering_by_one();
        bool has_intelligence_engineering_reached_max_value();

        // -------------------------------------------------


};



#endif
  

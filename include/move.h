
#ifndef GENONESIMULATION_INCLUDE_MOVE
#define GENONESIMULATION_INCLUDE_MOVE

#include<string>
#include<cstring>
#include<sstream>
#include<cstdlib>
#include<iostream>
#include "pokedata.h"

struct Move {

    /**
     * name, accuracy, base_power, category(attach move, status, special), pp,
     * self_inflected_status, volatile_status(frz, brn, confusion), 
     * volatile_status_chance, boosts, healing, type
     * multiple paramaters are split with | operators.
     *
     **/

   
    private: 
        std::string name;
        int accuracy;
        int base_power;
        std::string category;
        int pp;
        std::string self_inflected_status;
        std::string volatile_status;
        std::string volatile_status_chance;
        std::string boosts;
        std::string heal;
        Type type;
    public:
        Move();
        Move(std::string data);
        ~Move();

        std::string get_name();
        void set_name(std::string name);

        int get_accuracy();
        void set_accuracy(int accuracy);

        int get_base_power();
        void set_base_power(int base_power);
        
        std::string get_category();
        void set_category(std::string category);

        int get_pp();
        void set_pp(int pp);
    
        std::string get_self_inflected_status();
        void set_self_inflected_status(std::string self_inflected_status);

        std::string get_volatile_status();
        void set_volatile_status(std::string volatile_status);

        std::string get_volatile_status_chance();
        void set_volatile_status_chance(std::string volatile_status_chance);

        std::string get_boosts();
        void set_boosts(std::string boosts);

        std::string get_heal();
        void set_heal(std::string heal);

        Type get_type();
        void set_type(Type type);

};

#endif

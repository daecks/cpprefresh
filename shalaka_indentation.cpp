#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

class Indenter{

    public:
        Indenter(){};
        void add(string name, string time, string action){
            function_actions.push_back({ name, time, action });
        }

        string format(){
            // The idea: find an enter action. find the exit action for that 
            // function. Create the formatted string. Move to next enter action
            // while they still exist.
            string retval;
            string indent_amount = "";

            auto is_enter_action = [](auto& elem){return get<ACTION>(elem) == "enter";};

            auto enter_action = find_if(begin(function_actions), end(function_actions), is_enter_action);
            auto exit_action = begin(function_actions);

            while(enter_action != function_actions.end()){
                exit_action = find_if(enter_action, 
                    end(function_actions),
                    [&](auto& elem){return get<ACTION>(elem) == "exit" && get<FUNCTION>(elem) == get<FUNCTION>(*enter_action);} );

                retval += indent_amount + get<FUNCTION>(*enter_action) + " " + get<TIME>(*enter_action) + "-" + get<TIME>(*exit_action) + '\n';

                enter_action = find_if(++enter_action, end(function_actions), is_enter_action);

                indent_amount += " ";
            }

            return retval;
        }


    private:
        vector<tuple <string, string, string >> function_actions;
        string retval;
        static const int FUNCTION = 0;
        static const int TIME = 1;
        static const int ACTION = 2;

};

int main(){

    Indenter indenter;
    indenter.add("main", "t1", "enter");
    indenter.add("foo", "t2", "enter");
    indenter.add("bar", "t3", "enter");
    indenter.add("bar", "t4", "exit");
    indenter.add("foo", "t5", "exit");
    indenter.add("foo", "t6", "enter");
    indenter.add("foo", "t7", "exit");
    indenter.add("main", "t8", "exit");

    cout << indenter.format() << endl;

    return 0;
}
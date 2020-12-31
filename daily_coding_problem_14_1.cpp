#include <iostream>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

stack<string> get_itinerary(list<pair<string, string>> &flights, stack<string> &itinerary){

    // We're done if there are no more flights
    if(flights.size() == 0) return itinerary;

    // Find a flight from the current airport and add it to our itinerary.
    auto found_flight = find_if(begin(flights), end(flights), [&](auto flight){return itinerary.top() == flight.first;});

    if(found_flight != flights.end()){
        // We found a flight! 
        // Add the destination airport to the itinerary
        // Remove the flight from the list and try the next entry
        itinerary.push(found_flight->second);
        flights.remove(*found_flight);
    }else{
        // No match was found. Pop the last addition to the itinerary and try again.
        itinerary.pop();
    }
    get_itinerary(flights, itinerary);

    return itinerary;
}

int main(){

    // A list of the possible flights that can be taken
    list<pair<string, string>> flights;
    flights.push_back(make_pair("SFO", "HKO"));
    flights.push_back(make_pair("YYZ", "SFO"));
    flights.push_back(make_pair("YUL", "YYZ"));
    flights.push_back(make_pair("HKO", "ORD"));
    flights.push_back(make_pair("SFO", "ADL"));

    // An itinerary with the starting airport
    stack<string> itinerary;
    itinerary.push("YUL");

    stack<string> calculated_itinerary = get_itinerary(flights, itinerary);

    while(!calculated_itinerary.empty()){
        cout << calculated_itinerary.top() << " <- ";
        calculated_itinerary.pop();
    }
    cout << "BEGIN" << endl;

}
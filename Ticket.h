//ticket.h
//niaz hussain
//ticket queue manager
//cst 202 – data structures

#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <chrono>

struct Ticket {
    int id;    // unique ticket number
    std::string description; // user’s issue
    std::chrono::time_point<std::chrono::steady_clock> timestamp; // creation time
};

#endif

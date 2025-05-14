//ticketqueue.h
//niaz hussain
//ticket queue manager
//cst 202 – data structures

#ifndef TICKETQUEUE_H
#define TICKETQUEUE_H

#include "Ticket.h"
#include <iostream>

// node for our queue
struct NodeTicket {
    Ticket data;
    NodeTicket* next;
    NodeTicket(const Ticket& t) : data(t), next(nullptr) {}
};

class TicketQueue {
private:
    NodeTicket* head;
    NodeTicket* tail;
    int nextId; // for assigning new ticket IDs

public:
    TicketQueue();
    ~TicketQueue();

    bool isEmpty() const;
    void addTicket(const std::string& desc);        // insert a new ticket
    const Ticket& viewNext() const;                 // peek at front
    Ticket resolveNext();                            // dequeue & return front
    void escalate(int thresholdMinutes);            // move tickets older than threshold to front
    void printAll() const;                          // list all tickets
};

#endif

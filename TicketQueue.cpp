//ticketqueue.cpp

#include "TicketQueue.h"
#include <chrono>
#include <stdexcept>

// constructor
TicketQueue::TicketQueue()
    : head(nullptr), tail(nullptr), nextId(1) {
}

// destructor cleans up remaining nodes
TicketQueue::~TicketQueue() {
    while (!isEmpty()) {
        resolveNext();
    }
}

bool TicketQueue::isEmpty() const {
    return head == nullptr;
}

// add a new ticket with unique id and timestamp
void TicketQueue::addTicket(const std::string& desc) {
    Ticket t{ nextId++, desc, std::chrono::steady_clock::now() };
    NodeTicket* n = new NodeTicket(t);
    if (isEmpty()) head = tail = n;
    else { tail->next = n; tail = n; }
}

// view the ticket at the front
const Ticket& TicketQueue::viewNext() const {
    if (isEmpty()) throw std::runtime_error("no tickets");
    return head->data;
}

// remove and return the front ticket
Ticket TicketQueue::resolveNext() {
    if (isEmpty()) throw std::runtime_error("no tickets to resolve");
    NodeTicket* n = head;
    Ticket t = head->data;
    head = head->next;
    if (!head) tail = nullptr;
    delete n;
    return t;
}

// move any ticket older than thresholdMinutes to the front
void TicketQueue::escalate(int thresholdMinutes) {
    using namespace std::chrono;
    auto now = steady_clock::now();
    NodeTicket* prev = nullptr;
    NodeTicket* curr = head;

    while (curr) {
        // compute age in minutes
        auto ageMin = duration_cast<minutes>(now - curr->data.timestamp).count();
        NodeTicket* nxt = curr->next;

        if (ageMin >= thresholdMinutes) {
            // detach curr
            if (prev) prev->next = nxt;
            else head = nxt;
            if (curr == tail) tail = prev;
            // move curr to front
            curr->next = head;
            head = curr;
            if (!tail) tail = head;
        }
        else {
            prev = curr;
        }
        curr = nxt;
    }
}

// print all tickets in queue order
void TicketQueue::printAll() const {
    using namespace std::chrono;
    auto now = steady_clock::now();
    NodeTicket* curr = head;
    std::cout << "tickets in queue:\n";
    while (curr) {
        auto ageMin = duration_cast<minutes>(now - curr->data.timestamp).count();
        std::cout << "[" << curr->data.id << "] "
            << curr->data.description
            << " (" << ageMin << " min old)\n";
        curr = curr->next;
    }
}

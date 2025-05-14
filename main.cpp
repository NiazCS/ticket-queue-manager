//main.cpp
//niaz hussain
//ticket queue manager
//cst 202 – data structures

#include <iostream>
#include <string>
#include "TicketQueue.h"

int main() {
    TicketQueue tq;
    while (true) {
        std::cout << "\nmenu:\n"
            << "1) add ticket\n"
            << "2) view next ticket\n"
            << "3) escalate tickets\n"
            << "4) resolve next ticket\n"
            << "5) print all tickets\n"
            << "6) quit\n"
            << "choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try {
            if (choice == 1) {
                std::cout << "ticket description: ";
                std::string desc;
                std::getline(std::cin, desc);
                tq.addTicket(desc);
                std::cout << "ticket added\n";
            }
            else if (choice == 2) {
                const Ticket& t = tq.viewNext();
                std::cout << "next ticket: [" << t.id << "] "
                    << t.description << "\n";
            }
            else if (choice == 3) {
                std::cout << "escalate tickets older than (minutes): ";
                int mins;
                std::cin >> mins;
                tq.escalate(mins);
                std::cout << "tickets escalated\n";
            }
            else if (choice == 4) {
                Ticket t = tq.resolveNext();
                std::cout << "resolved ticket: [" << t.id << "] "
                    << t.description << "\n";
            }
            else if (choice == 5) {
                tq.printAll();
            }
            else if (choice == 6) {
                std::cout << "goodbye\n";
                break;
            }
            else {
                std::cout << "invalid choice\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "error: " << e.what() << "\n";
        }
    }
    return 0;
}

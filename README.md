ticket queue manager
manages a simple help‑desk queue: add tickets, view next, escalate by age, resolve, and list all.

test run:
menu:

add ticket

view next ticket

escalate tickets

resolve next ticket

print all tickets

quit
choice: 1
ticket description: printer down
ticket added

menu:

add ticket

view next ticket

escalate tickets

resolve next ticket

print all tickets

quit
choice: 1
ticket description: network issue
ticket added

menu:

add ticket

view next ticket

escalate tickets

resolve next ticket

print all tickets

quit
choice: 5
tickets in queue:
[1] printer down (0 min old)
[2] network issue (0 min old)

menu:
choice: 3
escalate tickets older than (minutes): 0
tickets escalated

menu:
choice: 5
tickets in queue:
[2] network issue (0 min old)
[1] printer down (0 min old)

menu:
choice: 4
resolved ticket: [2] network issue

menu:
choice: 6
goodbye

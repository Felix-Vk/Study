# Kernel Simulation (Starter)

Purpose:
- Practice kernel concepts (IDT, GDT, interrupts, context switching) via C++ simulations.

Suggested exercises:
1. Implement an "IDT" as an array of std::function<void()> and simulate an interrupt dispatcher.
2. Create a RegisterSet struct that holds fake register values; write save/restore functions to simulate a context switch.
3. Simulate a timer interrupt that triggers a scheduling function.

Tools:
- Study OSDev articles: https://wiki.osdev.org/
- Use OS Virtual Labs or plain C++ in Codespaces to run simulations.

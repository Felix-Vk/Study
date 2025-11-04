# Global Systems Engineer Bootcamp — 3 Month Detailed Guide (with inline learning links)

**Goal:** Become a systems / OS / low-level engineer capable of building kernels, low-latency systems and high-performance C++ code.  
**No installs required** — everything in this guide uses browser-based tools (Replit, Codespaces, copy.sh/v86, OnlineGDB, OS Virtual Labs) or pure reading resources.

---

## Quick index
- Month 1 — C++ fundamentals & OS basics (Weeks 1–4)  
- Month 2 — Bootloader, kernel concepts & virtual FS (Weeks 5–8)  
- Month 3 — Performance, networking & final project (Weeks 9–12)  
- Resources & checklist

---

# Month 1 — Modern C++ & OS Fundamentals (Weeks 1–4)

> **Primary free sources used inline:**  
> • LearnCpp — https://www.learncpp.com/  
> • cppreference (reference) — https://en.cppreference.com/  
> • OSTEP (Operating Systems: Three Easy Pieces) — https://pages.cs.wisc.edu/~remzi/OSTEP/  
> • GeeksforGeeks (practical examples) — https://www.geeksforgeeks.org/  
> • C++ docs (cplusplus.com) — https://cplusplus.com/doc/tutorial/

---

## Week 1 — C++ core: memory, RAII, smart pointers

**💻 Learn**
- Stack vs Heap, Pointers & References → [LearnCpp: Pointers & References](https://www.learncpp.com/cpp-tutorial/pointers-and-references/)  
- RAII, Constructors/Destructors → [cppreference: constructors](https://en.cppreference.com/w/cpp/language/constructor)  
- Smart pointers: `unique_ptr`, `shared_ptr`, `weak_ptr` → [LearnCpp: Smart Pointers](https://www.learncpp.com/cpp-tutorial/smart-pointers-stdunique_ptr-stdshared_ptr-stdweak_ptr/)  
- Move semantics & rvalue refs → [cppreference: Move constructors](https://en.cppreference.com/w/cpp/language/move_constructor)

**🧠 Do (daily)**
- Day 1: Read pointers & stack/heap; run small pointer examples in Replit.  
- Day 2: Implement a class with RAII (resource open/close) and test.  
- Day 3: Implement `UniquePtr` in `Month1/Smart_Pointer/unique_ptr.hpp` and test `main.cpp`.  
- Day 4: Implement `SharedPtr` (optional) or read implementation notes online.  
- Day 5: Write small move/copy tests (move constructor, copy deleted).  
- Day 6: Refactor and add comments; push to GitHub.  
- Day 7: Write a 200-word README describing your pointer design.

**📁 Project:** `Month1/Smart_Pointer`

---

## Week 2 — STL internals & multithreading

**💻 Learn**
- STL containers overview (`vector`, `map`, `unordered_map`) → [GeeksforGeeks: STL overview](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)  
- `std::vector` internals & growth strategy → [cppreference: vector](https://en.cppreference.com/w/cpp/container/vector)  
- Threads, mutexes, condition variables → [LearnCpp: Threads & synchronization](https://www.learncpp.com/cpp-tutorial/threads-and-thread-synchronization/)  
- Practical concurrency patterns → [cppreference: thread](https://en.cppreference.com/w/cpp/thread)

**🧠 Do (daily)**
- Day 1–2: Implement a tiny `vector` clone with `push_back` & dynamic resize.  
- Day 3: Create a multi-threaded producer/consumer skeleton using `std::condition_variable`.  
- Day 4: Implement a thread-safe logger using `std::mutex`.  
- Day 5: Stress test logger with many threads in Replit/Codespaces.  
- Day 6: Profile slow points (use simple timing `chrono`).  
- Day 7: Push code and write a short note on synchronization pitfalls.

**📁 Project:** `Month1/Multithreaded_Logger`

---

## Week 3 — OS basics: processes & system calls

**💻 Learn**
- Process & thread fundamentals → [OSTEP: Processes](https://pages.cs.wisc.edu/~remzi/OSTEP/processes.pdf)  
- Linux system calls `fork()`, `execve()`, `waitpid()` → [GeeksforGeeks: fork() overview](https://www.geeksforgeeks.org/fork-system-call/)  
- `/proc` filesystem exploration → [procfs overview (tutorial)](https://tldp.org/LDP/lpg/node11.html) (use Codespaces terminal)

**🧠 Do (daily)**
- Day 1: Read OSTEP chapter on processes.  
- Day 2: Write a small C++ program that `fork()`s and prints `pid`/`ppid`. Run in Codespaces.  
- Day 3: Use `execvp()` to run `/bin/ls` from your process, handle errors.  
- Day 4: Explore `/proc/self/maps` and `/proc` entries (inspect memory maps).  
- Day 5–6: Build the mini shell skeleton (`fork`+`execvp`) in `Month1/Mini_Shell/shell.cpp`.  
- Day 7: Test shell (OnlineGDB or Codespaces), add `cd` builtin and `exit`.

**📁 Project:** `Month1/Mini_Shell` (use OnlineGDB or Codespaces)

---

## Week 4 — CPU scheduling & simulation

**💻 Learn**
- Scheduling concepts: FCFS, SJF, Round Robin, priority scheduling → [GeeksforGeeks: CPU Scheduling](https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/)  
- Further reading: OSTEP chapters on scheduling → [OSTEP: Scheduling](https://pages.cs.wisc.edu/~remzi/OSTEP/scheduling.pdf)

**🧠 Do (daily)**
- Day 1: Implement FCFS scheduler simulator in C++ (read tasks from a simple input).  
- Day 2: Implement Round Robin with configurable quantum.  
- Day 3: Implement SJF (non-preemptive, then preemptive if time permits).  
- Day 4: Add CLI for job submission (arrival, burst).  
- Day 5: Compute waiting & turnaround times; print table.  
- Day 6: Add unit tests or sample runs & push.  
- Day 7: Write a README showing sample input/output.

**📁 Project:** `Month1/CPU_Scheduler_Simulation`

---

# Month 2 — Bootloader, Kernel Concepts & Virtual File System (Weeks 5–8)

> **Primary free sources used inline:**  
> • OSDev wiki — https://wiki.osdev.org/  
> • copy.sh/v86 emulator — https://copy.sh/v86/  
> • OSTEP (virtual memory/interrupts) — https://pages.cs.wisc.edu/~remzi/OSTEP/  
> • Tutorialspoint (assembly basics) — https://www.tutorialspoint.com/assembly_programming/index.htm

---

## Week 5 — Assembly basics & bootloader

**💻 Learn**
- x86 assembly basics (MOV, CALL, INT, registers) → [Tutorialspoint: Assembly Programming](https://www.tutorialspoint.com/assembly_programming/index.htm)  
- BIOS boot process & boot sector structure → [OSDev: Boot Sequence](https://wiki.osdev.org/Boot_Sequence)  
- Barebones bootloader examples → [OSDev: Bare Bones](https://wiki.osdev.org/Bare_Bones)  
- Emulator: copy.sh/v86 → [copy.sh/v86](https://copy.sh/v86/)

**🧠 Do (daily)**
- Day 1: Learn NASM/GAS syntax via online assembler examples.  
- Day 2: Write a 512-byte boot sector that prints characters via BIOS INT 0x10. See `Month2/Bootloader_Assembly/boot.asm`.  
- Day 3: Test `boot.asm` in `copy.sh/v86` by loading a floppy image (assemble with NASM if available or use an online assembler).  
- Day 4: Modify printed text and re-test.  
- Day 5–7: Document the boot steps in Bootloader README.

**📁 Project:** `Month2/Bootloader_Assembly/boot.asm`

---

## Week 6 — Protected mode, GDT & IDT (concepts)

**💻 Learn**
- Protected mode concepts & GDT → [OSDev: Protected Mode](https://wiki.osdev.org/Protected_Mode)  
- Interrupt Descriptor Table (IDT) → [OSDev: Interrupt Descriptor Table](https://wiki.osdev.org/Interrupt_Descriptor_Table)  
- Context switching basics (theory) → [OSTEP: Virtual Memory & Context Switching](https://pages.cs.wisc.edu/~remzi/OSTEP/)

**🧠 Do (daily)**
- Day 1: Read OSDev articles on GDT/IDT and study examples.  
- Day 2: Create a C++ simulation: represent IDT as an array of `std::function<void()>`, dispatch interrupts by index.  
- Day 3: Implement a `RegisterSet` struct and `save()`/`restore()` functions to simulate context switch.  
- Day 4–6: Simulate keyboard interrupt handler logic (no hardware — pure simulation).  
- Day 7: Document diagrams & notes in `Month2/Kernel_Simulation/README.md`.

**📁 Project:** `Month2/Kernel_Simulation` (README + simulation stubs)

---

## Week 7 — Interrupts, timers & simple kernel logic

**💻 Learn**
- PIC/APIC basics (high-level) → [OSDev: Programmable Interrupt Controller](https://wiki.osdev.org/PIC)  
- Timer interrupts & preemption (conceptual) → [OSTEP: Preemption & Scheduling](https://pages.cs.wisc.edu/~remzi/OSTEP/scheduling.pdf)

**🧠 Do (daily)**
- Day 1: Create a timer tick simulator (C++ function invoked every X ms).  
- Day 2: Integrate timer into your scheduler simulation to support preemption.  
- Day 3–5: Implement a simple kernel loop that runs processes and responds to timer interrupts (all simulated).  
- Day 6: Add logging for context switches & tick counts.  
- Day 7: Push code and capture sample outputs.

**📁 Project:** extend `Month2/Kernel_Simulation`

---

## Week 8 — Virtual File System (in-memory)

**💻 Learn**
- File system basics, directory entries, FAT12 overview → [OSDev: FAT12](https://wiki.osdev.org/FAT12)  
- Virtual File System concepts (VFS) → [Wikipedia: Virtual File System](https://en.wikipedia.org/wiki/Virtual_file_system)

**🧠 Do (daily)**
- Day 1: Design in-memory file structures (file metadata + content).  
- Day 2: Implement create/read/write APIs in `Month2/Virtual_File_System/vfs.cpp`.  
- Day 3: Add directory listing & simple permissions simulation.  
- Day 4: Add file deletion & error handling.  
- Day 5–6: Build test harness: create, read, write, delete files and display results.  
- Day 7: Document usage and example runs in README.

**📁 Project:** `Month2/Virtual_File_System`

---

# Month 3 — Performance Engineering, Networking & Final Project (Weeks 9–12)

> **Primary free sources used inline:**  
> • Brendan Gregg Systems Performance (online resources & blog) — https://www.brendangregg.com/  
> • LearnCpp timing & chrono — https://www.learncpp.com/cpp-tutorial/timing-your-code/  
> • Beej's Guide to Network Programming — https://beej.us/guide/bgnet/

---

## Week 9 — Profiling & CPU microarchitecture basics

**💻 Learn**
- CPU caches, false sharing, memory alignment → [Brendan Gregg (articles) — CPU caches](http://www.brendangregg.com/Perf.html)  
- Timing in C++ using `chrono` → [LearnCpp: Timing your code](https://www.learncpp.com/cpp-tutorial/timing-your-code/)  
- Simple profiling concepts (hotspots, sampling vs instrumentation) → [Brendan Gregg: Flame Graphs intro](http://www.brendangregg.com/flamegraphs.html)

**🧠 Do (daily)**
- Day 1: Read about CPU caches & false sharing; run simple microbenchmarks.  
- Day 2: Implement microbenchmarks in `Month3/Function_Profiler/profiler.cpp` (use `chrono`).  
- Day 3: Experiment with alignment & padding to observe performance differences.  
- Day 4: Document results and save sample outputs.  
- Day 5–7: Polish profiler and add README with run instructions.

**📁 Project:** `Month3/Function_Profiler`

---

## Week 10 — Networking: sockets & non-blocking IO

**💻 Learn**
- Beej's Guide to Network Programming (sockets) → [Beej's Guide](https://beej.us/guide/bgnet/)  
- `select` / `poll` / `epoll` overview (Linux) → [GeeksforGeeks: epoll tutorial](https://www.geeksforgeeks.org/epoll-in-linux/)  
- Blocking vs non-blocking sockets → [Beej / manpages]

**🧠 Do (daily)**
- Day 1: Implement a blocking TCP echo server (`Month3/TCP_Echo_Server/echo_server.cpp`).  
- Day 2: Implement a client that connects and tests echo.  
- Day 3: Convert server to non-blocking with `select` and handle multiple clients.  
- Day 4: Measure round-trip latency using `nc` or a small client script.  
- Day 5–7: Add logging & push code; note limitations when running inside Codespaces.

**📁 Project:** `Month3/TCP_Echo_Server`

---

## Week 11 — Trading Engine design & matching basics

**💻 Learn**
- Order book basics, price-time priority (read short overviews) → [Wikipedia: Order book](https://en.wikipedia.org/wiki/Order_book)  
- Simple matching algorithms (price-time priority) → [Quant concepts intro (free articles online)]

**🧠 Do (daily)**
- Day 1–2: Design data structures: `Order`, `OrderBook`, `Trade`.  
- Day 3–5: Implement a single-threaded matching engine (simple price-time matching).  
- Day 6: Add logging of matched trades.  
- Day 7: Test with synthetic order streams & record latencies.

**📁 Project:** `Month3/Trading_Engine_Simulator` (server.cpp, client.cpp)

---

## Week 12 — Final integration: multi-threaded & networked engine

**💻 Learn**
- Concurrency patterns for low-latency systems → [LearnCpp / cppreference concurrency pages]  
- Practical techniques for low-latency networking (batching, pinned threads) → [free articles & blog posts; start with Brendan Gregg notes]

**�� Do (daily)**
- Day 1–3: Extend matching engine to handle concurrent order ingestion (thread pool + queue).  
- Day 4–5: Add a TCP layer so clients can submit orders remotely (or simulate via threads).  
- Day 6: Add basic latency logging (timestamps at ingestion and match).  
- Day 7: Final polish — write README with architecture, how to run, sample outputs, and performance numbers.

**📁 Final project:** polished `Month3/Trading_Engine_Simulator`

---

# How to run & test (no local install required)

**Codespaces (recommended)**  
- Use integrated terminal to compile & run: `g++ -std=c++17 file.cpp -o exe && ./exe`  
- For multi-file projects, use Makefiles or `g++` with multiple sources.  
- Bootloader testing: assemble with `nasm` (if available) and load `boot.bin` into copy.sh/v86.

**Replit / OnlineGDB**  
- Use for quick experiments on single-file projects (shell, profiler, small C++ programs).  
- For `fork`/`exec` examples, Codespaces is more reliable than Replit.

**Bootloader (emulator)**  
- use https://copy.sh/v86/ to load a 512-byte floppy image and see BIOS text output.

---

# Checklist (end of 3 months)
- [ ] Smart Pointer project  
- [ ] Multithreaded Logger  
- [ ] Mini Shell  
- [ ] CPU Scheduler Simulation  
- [ ] Bootloader (Hello on boot)  
- [ ] Kernel Simulation (context switching)  
- [ ] Virtual File System  
- [ ] Function Profiler  
- [ ] TCP Echo Server  
- [ ] Trading Engine Simulator  
- [ ] GitHub repo with READMEs & sample outputs

---

# Final notes & tips
- Push each completed week to GitHub as a separate commit; this becomes your portfolio timeline.  
- Keep READMEs short and include **how to build** and **run** commands.  
- Aim for **small demos** (screenshots, short terminal recordings) for each project; they impress recruiters.

Good luck — follow this plan week-by-week. When you're ready I can also:
- generate README templates per folder,  
- produce test harnesses for the trading engine, or  
- create `Bootcamp_Guide.pdf` and commit it.


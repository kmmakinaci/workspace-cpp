// The std::thread is the C++ handle for a thread of execution. Multiple threads can be potentially executed concurrently.
// A std::thread with an associated state must be joined, detached, or moved-from before it can be destroyed.
// Joining a thread will block the caller until the thread finishes running. 
// Detaching a thread will dissociate the thread from the std::thread handle, allowing it to run independently.
// If a detached thread outlives main, the result is undefined. Typical implementations will terminate all remaining
// threads as part of exit() after returning from the main function.
// If you are using C++20, prefer std::jthread, which offers better ergonomy and additional features.

#include <thread>
#include <latch>
#include <print>

std::atomic<int> total{};

int main() {
    // start a thread
    auto t1 = std::thread([]{ ++total; });
    // block until the thread finishes running
    t1.join();
    // total == 1

    std::println("total == {}", total.load());

    auto fn = [](int arg1, double arg2) {
        total += arg1 + arg2;
    };
    // start fn in a new thread with the arguments (42, 3.14)
    auto t2 = std::thread(fn, 42, 3.14);
    // block until the thread finishes running
    t2.join();
    // total == 46

    std::println("total == {}", total.load());

    size_t t_count = 4;
    std::latch work_done(t_count);
    auto work_fn = [&work_done]{
        // do work
        ++total;
        // mark that we are done
        work_done.count_down();
    };

    // Start four detached threads
    for (size_t i = 0; i < t_count; ++i)
        std::thread(work_fn).detach();

    work_done.wait(); // Wait until all threads finish
    // total == 50

    std::println("total == {}", total.load());
}


The std::thread is the C++ handle for a thread of execution. Multiple threads can be potentially executed concurrently.

A std::thread with an associated state must be joined, detached, or moved-from before it can be destroyed.

Joining a thread will block the caller until the thread finishes running. Detaching a thread will dissociate the thread from the std::thread handle, allowing it to run independently.

If a detached thread outlives main, the result is undefined. Typical implementations will terminate all remaining threads as part of exit() after returning from the main function.

If you are using C++20, prefer std::jthread, which offers better ergonomy and additional features.




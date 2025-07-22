#pragma once

#include <iostream>
#include <thread>
#include <mutex>

class TestThread
{
    private:
        inline static std::mutex gs_mtx;  // Use inline for header-only definition
        static void sayHello(int i, int j) {
            std::lock_guard<std::mutex> lock(gs_mtx); // Lock the mutex to ensure thread safety
            std::cout << "Hello from thread in function i:" << i << " j:" << j << std::endl;
        }
    public:
        static void runThreadsWithFunction() {
            std::thread t1(sayHello, 1, 1234);
            std::thread t2(sayHello, 2, 1235);

            // Wait for threads to finish
            t1.join();
            t2.join();
        }

        static void runThreadsWithLambda() {
            std::mutex mtx;
            auto sayHello = [&](int i, int j) {
                std::lock_guard<std::mutex> lock(mtx); // Lock the mutex to ensure thread safety
                std::cout << "Hello from thread in lambda i:" << i << " j:" << j << std::endl;
            };
        
            std::thread t1(sayHello, 1, 1234);
            std::thread t2(sayHello, 2, 1235);

            // Wait for threads to finish
            t1.join();
            t2.join();
        }

        static void runMultipleThreadsInLoop(int count) {
            std::vector<std::thread> threads;
            for (int i = 0; i < count; i++) {
                //threads.emplace_back(sayHello, i, i + 1000);
                threads.emplace_back(std::thread(sayHello, i, i + 1000));
                //threads.push_back(std::thread(sayHello, i, i + 1000));
                //threads[i] = std::thread(sayHello, i, i + 1000);
                /* Alternatively, you can use std::move to transfer ownership
                std::thread t(sayHello, i, i + 1000);
                threads.push_back(std::move(t));  // move t into the vector
                */
            }
            //for (std::thread& t : threads) {
            for (auto& t : threads) {
                t.join(); // Wait for all threads to finish
            }
        }
};
